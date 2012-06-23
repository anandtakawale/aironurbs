#include "header_fit.h"

void generate_cpts(void)
{	
	int i;
	ofstream cpts_fit("cpts.nurbs",ios::out);
	ofstream cpts_dat("cpts.dat",ios::out);
	cpts_fit<<n<<endl<<c<<endl<<dpt<<endl;
	for(i=0;i<n+c+1;i++){
		cpts_fit<<u[i]<<"\t";
	}
	cpts_fit<<endl;
	for(i=0;i<n+1;i++){
		cpts_fit<<"1"<<"\t";
	}
	cpts_fit<<endl;
	for(i=0;i<n;i++){
		cpts_fit<<P[i][0]<<"\t"<<P[i][1]<<endl;
		cpts_dat<<P[i][0]<<"\t"<<P[i][1]<<endl;
	}
	cpts_dat<<"0.00\t0.00"<<endl;
	for(i=n;i>0;i--){
		cpts_dat<<P[i][0]<<"\t"<<P[i][1]*-1<<endl;
	}
}
