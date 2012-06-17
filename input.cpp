#include "header.h"
void input()
{
	int i;
	if(cpts.is_open()){
		cpts>>n>>c>>dpt;
		cout<<"n="<<n<<endl;
		cout<<"c="<<c<<endl;
		N= new double[n+c];
		w= new double[n+1];
		U= new double[n+c+1];
		P= new double*[n+1];
		for(i=0;i<n+1;i++){
			P[i]=new double[2];
		}
		for(i=0;i<(n+c+1);i++){
			cpts>>U[i];
			cout<<U[i]<<" ";
		}
		cout<<endl;
		for(i=0;i<(n+1);i++){
			cpts>>w[i];
			cout<<w[i]<<" ";
		}
		cout<<endl;
		for(i=0;i<(n+1);i++){
			cpts>>P[i][0]>>P[i][1];
			cout<<P[i][0]<<"\t"<<P[i][1]<<endl;
		}
		cpts.close();
	}
	else{
		cout<<"Can't open file";
	}
}
