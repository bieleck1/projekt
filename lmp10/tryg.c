#include <stdio.h> 
#include <stdlib.h>

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


void make_spl(points_t * pts, spline_t * spl)
{
 double a0;
 int stopien, i;

 if (STOPIEN > (pts->n - 1) / 2)
 	stopien = (pts->n - 1) / 2;
 else 
 	stopien = STOPIEN;
 
 
 for (i = 0; i < spl->n; i++)
 	spl->f[i] = a0;
}
