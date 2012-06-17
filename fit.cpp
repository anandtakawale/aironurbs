/*---------------------------------------------------------------------
Program to obtain parameter values for given data points
Nomenclature used:-
X[n][2]:data points matrix
n:Number of data points
e:factor which decides type of parameter selection methods
	when 	e=0 >> uniformlyspaced method
		e=0.5 >> centripetal method
		e=1 >> chord length method
--------------------------------------------------------------------*/
#include "header_fit.h"
double norm(int,double);
void fit(void)
{
	int i,j;
	double numer,denom=0.00,e;
	ifstream ipf("naca4415.dat",ios::in);
	ofstream opf("out_para.dat",ios::out);
	ofstream opf1("gnu_para.dat",ios::out);
	cout<<"Enter the value of e:";
	cin>>e;
	X= new double*[dpt];
	for(i=0;i<dpt;i++){
		X[i]=new double[2];
	}
	for(i=0;i<dpt;i++){
		ipf>>X[i][0]>>X[i][1];
		cout<<X[i][0]<<"\t"<<X[i][1]<<endl;
	}
	t= new double[dpt];
	t[0]=0;
	opf<<t[0]<<endl;
	opf1<<t[0]<<"\t"<<"0"<<endl;
	//Determining denominator i.e total length of curve if e==0
	for(j=0;j<(dpt-1);j++){
		denom+=norm(j,e);
	}
	//Determining numerator i.e length of curve from first point to i th point
	for(i=1;i<dpt;i++){
		numer=0.00;
		for(j=0;j<i;j++){
			numer+=norm(j,e);	
		}
		cout<<i<<")";
		cout<<"numer="<<numer<<"\t"<<"denom="<<denom<<endl;
		t[i]=numer/denom;
		//output the value to the output.dat
		opf<<t[i]<<endl;
		opf1<<t[i]<<"\t0"<<endl;
	}
}

//A function to calculate the norm of the matrix
double norm(int j,double e)
{
	double N[2],ans;
	N[0]=X[j+1][0]-X[j][0];
	N[1]=X[j+1][1]-X[j][1];
	ans=pow(N[0],2)+pow(N[1],2);
	ans=pow(ans,0.5);
	return(pow(ans,e));	
}
