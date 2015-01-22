#ifndef SPLINES_H
#define SPLINES_H

#include <stdio.h>

#include "points.h"

typedef struct {
		int n;
		double *x;
		double *f;
		double *a;
		double *b;
} spline_t;

int alloc_spl( spline_t *spl, int n );

int  read_spl ( FILE *inf,  spline_t *spl );

void  write_spl ( spline_t *spl, points_t * pts, FILE * ouf );

double value_spl( spline_t *spl, points_t * pts, double x);

#endif
