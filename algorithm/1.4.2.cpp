#include <stdio.h>
#include <math.h> 
double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);
double cycle(double(*f)(double));
int main(){
	double x=2;
	cycle(f1);
	cycle(f2);
	cycle(f3);
	cycle(f4);
}
double f1(double x){
	return pow(2*x+5,1.000/3);
}
double f2(double x){
	return sqrt(2+5/x);
}
double f3(double x){
	return pow(x,3)-x-5;
}
double f4(double x){
	return (2*pow(x,3)+5)/(3*pow(x,2)-2);
}
double cycle(double(*f)(double)){
	double x0 = 2;
	double x = 2;
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
