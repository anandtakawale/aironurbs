#include "header_fit.h"

int clamp()
{
	int i;
	double *knot;
	ofstream out("main_out.nurbs",ios::out);
	knot = new double[2*n+c];
	out<<2*n<<endl<<c<<endl<<2*dpt<<endl;
	for(i=0;i<c;i++){
		knot[i]=0;
		knot[2*n+1+i]=1;
	}
	for(i=c;i<=n;i++){
		knot[i]=0.5*u[i];
	}
	for(i=1;i<c;i++){
		knot[n+i]=0.5;
	}
	for(i=0;i<n+1-c;i++){
		knot[n+c+i]=1-knot[n-i];
	}
	for(i=0;i<=2*n+c;i++){
		cout<<knot[i]<<"\t";
		out<<knot[i]<<"\t";
	}
	cout<<endl;
	out<<endl;
	for(i=0;i<=2*n;i++){
		out<<"1"<<"\t";
	}
	out<<endl;
	for(i=0;i<n;i++){
		out<<P[i][0]<<"\t"<<P[i][1]<<endl;
	}
	out<<"0.00\t0.00"<<endl;
	for(i=n-1;i>0;i--){
		out<<P[i][0]<<"\t"<<-1*P[i][1]<<endl;
	}
	out<<"1.00\t0.00"<<endl;
}

