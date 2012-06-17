/*---------------------------------------------------------------------------
Convention followed:-
dpt:Number of data points
n+1:number of control points
U[n+p+1]:knot vector
c:order of the curve
t[dpt]:parameters
---------------------------------------------------------------------------*/
#include "header_fit.h"

void knotcal(void)
{
	int cpt,i,j;
	double I,R;
	ifstream ipf("out_para.dat",ios::in);
	ofstream opf("out_knot.dat",ios::out);
	ofstream opf1("gnu_knot.dat",ios::out);
	u=new double[n+c+1];
	for(i=0;i<c;i++){
		u[i]=0;
		u[n+1+i]=1;
	}
	I=(dpt-1)*1.00/(n+1-c+1);
	cout<<"I="<<I<<endl;
	for(i=1;i<=n+1-c;i++){
		j=I*i+1;
		cout<<"j="<<j<<"\t";
		R=I*i+1-j;
		cout<<"R="<<R<<"\t";
		u[c+i-1]=(1-R)*t[j]+R*t[j+1];
		cout<<"u["<<c+i-1<<"]="<<u[c+i-1]<<endl;
	}		
	for(i=0;i<n+1+c;i++){
		opf<<u[i]<<endl;
		opf1<<u[i]<<"\t"<<"0"<<endl;
		cout<<u[i]<<"\t";
	}
	cout<<endl;
}
