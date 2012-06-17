#include<iostream>
#include<fstream>
#include<new>
using namespace std;

int main()
{	
	int i,n,c,cpt,dpt;
	double *U,*x,*y,*w;
	ofstream cpts("cpts.nurbs",ios::out);
	cout<<"Enter the number of control points:";
	cin>>cpt;
	cpts<<cpt<<endl;
	n=cpt-1;
	x= new double [n+1];
	y= new double [n+1];
	w = new double[n+1];
	cout<<"Enter the order of the curve(<number of data points):";
	cin>>c;
	U=new double [n+c+1];
	cpts<<c<<endl;
	cout<<"Enter the number of data points required:";
	cin>>dpt;
	cpts<<dpt<<endl;
	cout<<"Enter the knot values or knot vector:";
	for(i=0;i<n+c+1;i++){
		cin>>U[i];
		cpts<<U[i]<<"\t";
	}
	cpts<<endl;
	cout<<"Enter the weight for each control point:";
	for(i=0;i<n+1;i++){
		cin>>w[i];
		cpts<<w[i]<<"\t";
	}
	cpts<<endl;
	cout<<"Enter the co-ordinates for control points:";
	for(i=0;i<n+1;i++){
		cout<<"x["<<i<<"]=";
		cin>>x[i];
		cpts<<x[i]<<"\t";
		cout<<"y["<<i<<"]=";
		cin>>y[i];
		cpts<<y[i]<<endl;
	}
	return 0;
}

