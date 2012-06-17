#include "header_fit.h"
void decompose(void);
void substitute(void);
void input_lu_inverse(void);
void lu_inverse(void)
{	
	int i,j,k;
	ofstream inv("inverse.dat",ios::out);
	input_lu_inverse();
	decompose();
	for(i=0;i<n+1;i++){
		cout<<"B="<<endl;
		for(j=0;j<n+1;j++){
			if(i!=j)
				B[j]=0;
			else
				B[j]=1;
			cout<<B[j]<<endl;
		}
		substitute();
		for(k=0;k<n+1;k++){
			Ainv[k][i]=x[k];
		}
	}
	for(i=0;i<n+1;i++){
		for(j=0;j<n+1;j++){
			inv<<Ainv[i][j]<<"\t";
		}
		inv<<endl;
	}
}

void input_lu_inverse(void)
{	
	int i,j;
	Ainv= new double*[n+1];
	for(i=0;i<n+1;i++){
		Ainv[i]=new double[n+1];
	}
	B=new double[n+1];
	D=new double[n+1];
	x=new double[n+1];
}
void decompose(void)
{
	int i,j,k;
	double factor;
	ofstream matout("out_mat.dat",ios::out);
	for(k=0;k<(n);k++){
		for(i=k+1;i<n+1;i++){
			factor=A[i][k]/A[k][k];
			A[i][k]=factor;
			for(j=k+1;j<n+1;j++){
				A[i][j]=A[i][j]-factor*A[k][j];
			}
		}
	}
	for(i=0;i<n+1;i++){
		for(j=0;j<n+1;j++){
			matout<<A[i][j]<<"\t";
		}
		matout<<endl;
	}
}

void substitute(void)
{
	int i,j;
	double sumfwd,sumbwd;
	ofstream subout("out_substitute.dat",ios::out);
	//Forward subtitution for LD=B
	for(i=0;i<n+1;i++){
		sumfwd=B[i];
		for(j=0;j<i;j++){
			sumfwd=sumfwd-D[j]*A[i][j];
		}
		D[i]=sumfwd;
	}
	//Backward substitution for UX=D
//	x[r-1]=D[r-1]/A[r-1][r-1];
	for(i=(n);i>=0;i--){
		sumbwd=0.00;
		for(j=i+1;j<n+1;j++){
			sumbwd=sumbwd+x[j]*A[i][j];
		}
		cout<<"sumbwd="<<sumbwd<<endl;
		x[i]=(D[i]-sumbwd)/A[i][i];
	}
	cout<<"D="<<"\t"<<"X="<<endl;
	for(i=0;i<n+1;i++){
		cout<<D[i]<<"\t"<<x[i]<<endl;
	}
}
