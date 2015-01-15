#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

#include "makespl.h"

#define STOPIEN 10 /* Stopien wielomianu trygonometrycznego */

/* Wspolczynnik a0 */
double a_0(points_t * pts, double a0)
{
 int i;
 a0 = 0.0;

 for (i = 0; i < pts->n; i++)
	a0 = a0 + pts->y[i];

 a0 = a0 / (double) pts->n;
 
 return a0;
}


/* Wspolczynniki ai oraz bi */
void a_and_b(points_t * pts, spline_t * spl, double * a, double * b, int stopien)
{
 int i, j;
 
 for (i = 0; i < stopien; i++)
	{
	 a[i] = 0;
	 b[i] = 0;
	 
	 for (j = 0; j < pts->n; j++)
		{
		 a[i] = a[i] + (pts->y[i] * cos(2.0 * M_PI * i * j / pts->n));
		 b[i] = b[i] + (pts->y[i] * sin(2.0 * M_PI * i * j / pts->n));
		}

	 a[i] = a[i] * 2.0 / pts->n;
	 b[i] = b[i] * 2.0 / pts->n;

	}
}



void make_spl(points_t * pts, spline_t * spl)
{
 double a0;
 int stopien, i;
 double *a = NULL;
 double *b = NULL;

 if (STOPIEN > (pts->n - 1) / 2)
 	stopien = (pts->n - 1) / 2;
 else 
 	stopien = STOPIEN;
 
 a = malloc(stopien * sizeof (double));
 b = malloc(stopien * sizeof (double));
 
 if (a == NULL || b == NULL)
	printf("Brak miejsca w pamieci.");
 
 a0 = a_0(pts, a0);

 alloc_spl(spl, pts->n); /* Ilosc splinesow */
 
 for (i = 0; i < spl->n; i++)
 	spl->f[i] = a0;
 
 a_and_b(pts, spl, a, b, stopien);
 
 

 free(a);
 free(b); 
}
