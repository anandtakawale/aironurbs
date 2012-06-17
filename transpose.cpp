/*---------------------------------------------------------
N[dpt][n+1]:Matrix of basis functions
Nt[n+1][dpt]:transpose of N
(n+1):number of control points
dpt:Number of data points
A[n+1][n+1]=Nt[n+1][dpt]*N[dpt][n+1] (A is matrix to be inverted)
X[dpt][2]:matrix of data points
---------------------------------------------------------*/
#include "header_fit.h"

void transpose(void)
{	
	int i,j,k;
	double sum;
	ifstream N_in("out_basis.dat",ios::in);
	ofstream mult("A_mat.dat",ios::out);
	ofstream ntrans("Nt_mat.dat",ios::out);
	Nt=new double*[n+1];
	for(i=0;i<n+1;i++){
		Nt[i]=new double[dpt];
	}
	for(i=0;i<dpt;i++){
		for(j=0;j<n+1;j++){
			N_in>>N[i][j];
			//transposing
			Nt[j][i]=N[i][j];
		}
	}
	//writing transpose to a file
	for(i=0;i<n+1;i++){
		for(j=0;j<dpt;j++){
			ntrans<<Nt[i][j]<<"\t";
		}
		ntrans<<endl;
	}
	A=new double*[n+1];
	for(i=0;i<n+1;i++){
		A[i]=new double[n+1];
	}
	for(i=0;i<n+1;i++){
		for(j=0;j<n+1;j++){
			sum=0.00;
			for(k=0;k<dpt;k++){
				sum+=Nt[i][k]*N[k][j];
			}
			A[i][j]=sum;
			mult<<A[i][j]<<"\t";
		}
		mult<<endl;
	}
	
}
