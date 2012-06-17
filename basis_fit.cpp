#include "header_fit.h"

void basis_fit(double t,int ith)
{
	int i,k;
	double a,b;
	for(i=0;i<n+c;i++){
		if(t>=u[i] && t<u[i+1])
			basis[i]=1;
		else
			basis[i]=0;
	}
	for(k=1;k<c;k++){
		for(i=0;i<n+c-k;i++){
			if(basis[i]!=0)
				a=(t-u[i])*basis[i]/(u[i+k]-u[i]);
			else
				a=0;
			if(basis[i+1]!=0)
				b=(u[i+k+1]-t)*basis[i+1]/(u[i+k+1]-u[i+1]);
			else
				b=0;
			basis[i]=a+b;
		}
	}
	if(u[n+c]-t<1e-5 || t==u[n+c])
		basis[n]=1;
	for(i=0;i<n+1;i++){
	N[i][ith]=basis[i];
		opf<<N[i][ith]<<"\t";
	}
	opf<<endl;
}
