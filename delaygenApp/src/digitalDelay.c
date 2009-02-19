/******

digital delay

Given a table of delay values (in ps) corresponding to each of twelve delay lines, calculate
the delay values of all possible combinations of those delay lines. When user requests a delay
value, find the closest achievable delay, and output the bit pattern that achieves it.

aSub fields:
  A - the desired delay
  VALA - the closest achievable delay
  VALB - the bit pattern that will produce VALA
  VALC - actual delay - desired delay
  C - delays corresponding to each bit of pattern (array)
  I - index array, used to sort VALA
  D - achievable delays (array)
  B - bit patterns corresponding to D delays (array)

******/



#include <stddef.h>
#include <stdlib.h>
/* #include <ctype.h> */
#include <math.h>
#include <stdio.h>

/* #include <dbEvent.h> */
#include <dbDefs.h>
#include <dbCommon.h>
#include <recSup.h>
#include <epicsVersion.h>       /* for LT_EPICSBASE macro */
#include <aSubRecord.h>

#define GE_EPICSBASE(v,r,l) ((EPICS_VERSION>=(v)) && (EPICS_REVISION>=(r)) && (EPICS_MODIFICATION>=(l)))

void indexx(long n, double *arrin, long *indx);

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) > (b) ? (b) : (a))
#define NINT(f)  (int)((f)>0 ? (f)+0.5 : (f)-0.5)

volatile int digitalDelayDebug = 0;

static double delayValue(int pattern, int nbits, double *delay_line_values)
{
	int i;
	double value = 0.;
	for (i=0; i<nbits; i++) {
		if (pattern & (1<<i)) value += delay_line_values[i];
	}
	return (value);
}

static void do_init(aSubRecord *psub)
{
	long pattern;
	double *delay_line_values = (double *)psub->c;
	double *delay_ps = (double *)psub->d;
	long *bitPattern = (long *)psub->b;
	long *index = (long *)psub->i;
	long npatterns = psub->nod;
	long nbits = psub->noc;
	long *reinit = (long *)psub->e;

	for (pattern=0; pattern<npatterns; pattern++) {
		delay_ps[pattern] = delayValue(pattern, nbits, delay_line_values);
		bitPattern[pattern] = pattern;
		if (digitalDelayDebug) printf("0x%lx %f\n", pattern, delay_ps[pattern]);
	}
	/* sort delayTable so that delay values increase */
	indexx(npatterns, delay_ps, index);
	if (digitalDelayDebug) {
		for (pattern=0; pattern<npatterns; pattern++) {
			printf("%ld, 0x%lx %f\n", index[pattern], pattern, delay_ps[index[pattern]]);
		}
	}
	*reinit = 0;
	return;
}

static long digitalDelay_init(aSubRecord *psub)
{
	double *delay_line_values = (double *)psub->c;
	long nbits = psub->noc;

	/* Initialize delay values.  User can write their own values to the C array before or after iocInit.
	 * If C is written after iocInit, user must set E and wait for it to be reset to 0.
	 */
	if (nbits>0)  delay_line_values[0]  = 5.;
	if (nbits>1)  delay_line_values[1]  = 14.5;
	if (nbits>2)  delay_line_values[2]  = 25.;
	if (nbits>3)  delay_line_values[3]  = 81.6;
	if (nbits>4)  delay_line_values[4]  = 101.5;
	if (nbits>5)  delay_line_values[5]  = 176.4;
	if (nbits>6)  delay_line_values[6]  = 352.7;
	if (nbits>7)  delay_line_values[7]  = 672.7;
	if (nbits>8)  delay_line_values[8]  = 1298.2;
	if (nbits>9)  delay_line_values[9]  = 2545.5;
	if (nbits>10) delay_line_values[10] = 5047.4;
	if (nbits>11) delay_line_values[11] = 10088.;

	do_init(psub);
	return(0);
}

static long digitalDelay_do(aSubRecord *psub)
{
	double *a = (double *)psub->a;
	double *vala = (double *)psub->vala;
	long *valb = (long *)psub->valb;
	double *valc = (double *)psub->valc;
	double *vald = (double *)psub->vald;
	double *vale = (double *)psub->vale;
	double *delay_ps = (double *)psub->d;
	long *bitPattern = (long *)psub->b;
	long *index = (long *)psub->i;
	long *reinit = (long *)psub->e;
	long npatterns = psub->nod;
	double diff;
	long bestIx;
	int i, ix;


	if (digitalDelayDebug) printf("digitalDelay_do: a=%f\n", *a);

	if (*reinit) do_init(psub);

	diff = 1000.;
	bestIx = 0;
	for (i=0; i<npatterns; i++) {
		ix = index[i];
		if (fabs(*a-delay_ps[ix]) < diff) {
			diff = fabs(*a-delay_ps[ix]);
			bestIx = ix;
		}
	}
	*vala = delay_ps[bestIx];
	*valb = bitPattern[bestIx];
	*valc = *vala - *a;
	*vald = delay_ps[MAX(0,bestIx-1)];
	*vale = delay_ps[MIN(npatterns-1,bestIx+1)];
	if (digitalDelayDebug) {
		printf("digitalDelay_do: bestIx=%ld, vala=%f, valb=0x%lx\n", bestIx, *vala, *valb);
		printf("digitalDelay_do: bestIx=0x%lx, nextH=0x%lx, nextL=0x%lx\n", bestIx, MAX(0,bestIx-1), MIN(npatterns-1,bestIx+1));
	}
	return(0);
}

/* Fill the index array, indx, so that arrin[indx[i]] increases monotonically
 * with i.
 */
void indexx(long n, double *arrin, long *indx)
{
	long l,j,ir,indxt,i;
	double q;

	/* This code thinks array indices start at 1.  Fix for arrays that start at 0 */
	arrin--;
	indx--;

	for (j=1;j<=n;j++) indx[j]=j;
	l=(n >> 1) + 1;
	ir=n;
	for (;;) {
		if (l > 1)
			q=arrin[(indxt=indx[--l])];
		else {
			q=arrin[(indxt=indx[ir])];
			indx[ir]=indx[1];
			if (--ir == 1) {
				indx[1]=indxt;
				/* This code thinks array indices start at 1.  Fix for arrays that start at 0 */
				for (j=1;j<=n;j++) --(indx[j]);
				return;
			}
		}
		i=l;
		j=l << 1;
		while (j <= ir) {
			if (j < ir && arrin[indx[j]] < arrin[indx[j+1]]) j++;
			if (q < arrin[indx[j]]) {
				indx[i]=indx[j];
				j += (i=j);
			}
			else j=ir+1;
		}
		indx[i]=indxt;
	}
}
#if GE_EPICSBASE(3,14,0)
#include <registryFunction.h>
#include <epicsExport.h>

epicsExportAddress(int, digitalDelayDebug);

static registryFunctionRef digitalDelayRef[] = {
	{"digitalDelay_init", (REGISTRYFUNCTION)digitalDelay_init},
	{"digitalDelay_do", (REGISTRYFUNCTION)digitalDelay_do}
};

static void digitalDelayRegister(void) {
	registryFunctionRefAdd(digitalDelayRef, NELEMENTS(digitalDelayRef));
}

epicsExportRegistrar(digitalDelayRegister);

#endif
