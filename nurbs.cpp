#include "header.h"

int main()
{
	int i,j;
	double x,y,h;
	ofstream opf("out.dat",ios::out);
	t = 0.000;
	input();
	h=1.00*U[n+c]/(dpt-1);
	cout<<"h="<<h<<endl;
	for(j=0;j<dpt;j++){
		cout<<"t="<<t<<endl;
		basis();
		x=y=0.00;
		for(i=0;i<n+1;i++){
			x+=N[i]*P[i][0];
			y+=N[i]*P[i][1];
		}
		cout<<"x="<<x<<"\t"<<"y="<<y<<endl<<endl;
		output(x,y);
		opf<<t/U[n+c]<<endl;
		t=t+h;
	}
	dpts.close();
	return 0;
}
