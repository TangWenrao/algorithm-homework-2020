#include <stdio.h>
#include <math.h>
int main(){
	double cdn[2][5]={{9,11,13,15,17},{37289,42747,59885,66581,70644}};
	double x[4]={10,12,14,16};
	double y[4]={0};
	int i,j,k;
	double t;
	for(k=0;k<4;k++){
		for(i=0;i<5;i++){
			t=1;
			for(j=0;j<5;j++){
				if(j!=i){
					t*=(x[k]-cdn[0][j])/(cdn[0][i]-cdn[0][j]);				
				}
			}
			y[k]+=t*cdn[1][i];
		}
		printf("\n%lf",y[k]);
	}

}
