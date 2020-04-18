#include <stdio.h>
#include <math.h> 
double f1(double x);
double cycle(double(*f)(double));
int main(){
	cycle(f1);
}
double f1(double x){
	return 2/pow(x,4)-5;
}
double cycle(double(*f)(double)){
	double x0 = -5;
	double x = -5;
	int k=1;
	do{
		x0 = x;
		x=f(x0);
		printf("%d,%lf\n",k,x0);
		k=k+1;
	}
	while(fabs(x-x0)>0.00001||k<20);
	return x; 
}
