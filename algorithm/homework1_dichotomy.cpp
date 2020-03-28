#include <stdio.h>
#include <math.h>
#define e 2.71828
double fuc(double x);
int main(){
	double cu,a,b,mid,res;
	printf("\n请输入精度");
	scanf("%lf",&cu);
	printf("\n请输入上下限a,b");
	scanf("%lf,%lf",&a,&b);
	if(fuc(a)==0){
		res = a;
	}else if(fuc(b)==0){
		res = b;
	}else{
		while((a-b)/2>cu){
			mid = (a+b)/2;
			if(fuc(mid)==0){
				break;
			}else if(fuc(a)*fuc(mid)>0){
				a = mid;
			}else{
				b = mid;
			}
			printf("\n%lf,%lf",a,b);
		}
		res = (a+b)/2;
	}
	printf("\n方程的根为：x = %lf",res);
	return 0;
} 

double fuc(double x){
//	printf("%lf",-2+10*x+pow(e,x));
	return -2+10*x+pow(e,x);
}
