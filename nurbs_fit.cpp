#include "header_fit.h"

int main()
{
	int i,cpt;
	ifstream in("input.dat",ios::in);
	in>>cpt>>c>>dpt;
	n=cpt-1;
	cout<<"n="<<n<<endl<<"c="<<c<<endl<<"dpt="<<dpt<<endl;
	basis=new double[n+c+1];
	N= new double*[dpt];
	for(i=0;i<dpt;i++){
		N[i]=new double[n+1];
	}
	fit();
	knotcal();
	for(i=0;i<dpt;i++){
		basis_fit(t[i],i);
	}
	cout<<"Working"<<endl;
	transpose();
	lu_inverse();
	solve();
	generate_cpts();
	return 0;
}
