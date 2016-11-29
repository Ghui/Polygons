#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main() {
  //double * norm =(double *)malloc(3 * sizeof(double));
  //double dot;
  screen s;
  struct matrix *edges;
  struct matrix *transform;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  
  
  //print_matrix(edges);
  
  parse_file( "script_c", transform, edges, s );
  /*add_point(edges,1,2,3);
  add_point(edges,11,12,13);
  add_point(edges,21,22,23);
  add_point(edges,31,32,33);
  print_matrix(edges);
  norm = calculate_normal(4.0,2.0,3.0,1.0,2.0,3.0);
  dot = calculate_dot(edges,1);
  printf("%f %f %f %f\n", norm[1],norm[2],norm[0],dot);*/
  
  free_matrix( transform );
  free_matrix( edges );
  //free(norm);
}  
