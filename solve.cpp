#include "header_fit.h"

void solve(void)
{	
	int i,j,k;
	double sum=0.00,**Y;
	ofstream final("final.dat",ios::out);
	P=new double*[n+1];
	for(i=0;i<n+1;i++){
		P[i]=new double[2];
	}
	Y=new double*[n+1];
	for(i=0;i<n+1;i++){
		Y[i]=new double[2];
	}
	//Multiplying Nt and X  Y[n+1][2]=Nt[n+1][dpt]*X[dpt][2]
	for(i=0;i<n+1;i++){
		for(j=0;j<2;j++){
			sum=0.00;
			for(k=0;k<dpt;k++){
				sum+=Nt[i][k]*X[k][j];
			}
			Y[i][j]=sum;
		}
	}
	//Multiplying Ainv and Y to get P[n+1][2]=Ainv[n+1][n+1]*Y[n+1][2]
	for(i=0;i<n+1;i++){
		for(j=0;j<2;j++){
			sum=0.00;
			for(k=0;k<n+1;k++){
				sum+=Ainv[i][k]*Y[k][j];
			}
			P[i][j]=sum;
			//Output control points to a file
			final<<P[i][j]<<"\t";
		}
		final<<endl;
	}
}
