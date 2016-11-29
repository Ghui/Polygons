#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"
#include "gmath.h"



/*======== double * calculate_normal() ==========
  Inputs:   double ax
            double ay
	    double az
	    double bx
	    double by
	    double bz  
  Returns: A double arry of size 3 representing the 
           cross product of <ax, ay, az> and <bx, by, bz>

  04/17/12 16:46:30
  jonalf
  ====================*/
double * calculate_normal( double ax, double ay, double az,	
			   double bx, double by, double bz ) {
  
  double *normal,mag;
  normal = (double *)malloc(3 * sizeof(double));
  normal[0] = (ax * bz) - (az * by);
  normal[1] = (az * bx) - (ax * bz);
  normal[2] = (ax * by) - (ay * bx);
  mag = sqrt(normal[0] * normal[0] +
	     normal[1] * normal[1] +
	     normal[2] * normal[2]);
  normal[0] = normal[0] / mag;
  normal[1] = normal[1] / mag;
  normal[2] = normal[2] / mag;
  return normal;
}

/*======== double calculate_dot() ==========
  Inputs:   struct matrix *points
            int i  
  Returns: The dot product of a surface normal and
           a view vector
  
  calculates the dot product of the surface normal to
  triangle points[i], points[i+1], points[i+2] and a 
  view vector (use <0, 0, -1> to start.

  04/17/12 16:38:34
  jonalf
  ====================*/
double calculate_dot( struct matrix *points, int i ) {
  double dot,ax,ay,az,bx,by,bz;
  double *normal;
  normal = (double *) malloc(3 * sizeof(double));
  ax = points -> m [0][i+1] - points -> m[0][i];
  ay = points -> m [1][i+1] - points -> m[1][i];
  az = points -> m [2][i+1] - points -> m[2][i];
  bx = points -> m [0][i+2] - points -> m[0][i];
  by = points -> m [1][i+2] - points -> m[1][i];
  bz = points -> m [2][i+2] - points -> m[2][i];
  normal = calculate_normal(ax,ay,az,bx,by,bz);
  dot = normal[2] * -1;
  return dot;
}
