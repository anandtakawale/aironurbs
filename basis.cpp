#include "header.h"

void basis()
{
	int i,k;
	double a,b,sum=0,sumN=0;
	//Assigns the value to basis functions at like N(1,1),N(2,1),...,N(n+c,1)
	for(i=0;i<(n+c);i++){
		if((t>= U[i]) && (t<U[i+1]))
			N[i]=1;
		else
			N[i]=0;
		cout<<N[i]<<"\t";
	}
	cout<<endl;
	//Assigns value to all other dependent basis fuctions
	for(k=2;k<=c;k++){
		for(i=0;i<(n+c+1-k);i++){
			if(N[i]!=0)
				a=((t-U[i])*N[i])/(U[i+k-1]-U[i]);
			else
				a=0;
			if(N[i+1]!=0)
				b=((U[i+k]-t)*N[i+1])/(U[i+k]-U[i+1]);
			else
				b=0;
			N[i]=a+b;
			cout<<N[i]<<"\t";
		}
		cout<<endl;
	}
	//for last point
	if((U[n+c]-t)<1e-7)
		N[n]=1;
	for(i=0;i<n+1;i++){
		sum=sum+N[i]*w[i];
	}
	cout<<"Final=";
	for(i=0;i<n+1;i++){
		if(sum!=0)
			N[i]=N[i]*w[i]/sum;
		else
			N[i]=0;
		cout<<N[i]<<" ";
		sumN=sumN+N[i];
	}
	cout<<"sumN="<<sumN<<endl;
}
