#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#include "makespl.h"


void make_spl (points_t * pts, spline_t * spl)
{
 int i, j;
 int n = pts->n;

 
 if (pts->l > ((pts->n - 1) / 2))
	{
	 pts->l = ((pts->n - 1) / 2);
	}

 if (alloc_spl(spl, n) == 0)
	{
	 spl->x = pts->x;
	 spl->f = pts->y;

	 spl->a[0] = 0.0;
	 for (i = 0; i <= pts->l; i++)
		spl->a[0] += spl->f[i];
	 spl->a[0] /= n;

	 for (i = 1; i <= pts->l; i++)
		{
		 spl->a[i] = 0.0;
		 spl->b[i] = 0.0;
		 for(j = 1; j < n; j++)
			{
			 spl->a[i] += 2.0 / n * spl->f[j] * cos(2.0 * M_PI * i * j / n);
			 spl->b[i] += 2.0 / n * spl->f[j] * sin(2.0 * M_PI * i * j / n);
			}
		}
	}
}
