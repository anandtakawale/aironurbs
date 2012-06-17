#include "header_fit.h"

int n,c,dpt;
double **X,*t,*u,*basis,**N,**Nt,**A,*B,*D,*x,**Ainv,**P;
ofstream opf("out_basis.dat",ios::out);
