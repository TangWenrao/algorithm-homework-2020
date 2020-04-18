#include <stdio.h>
#include <math.h>
int main(){
	double cdn[2][5]={{9,11,13,15,17},{37289,42747,59885,66581,70644}};
	double x[4]={10,12,14,16};
	double y[4]={0};
	int i,j,k;
	double f[5][5];
	for(i=0;i<5;i++){
		f[i][0]=cdn[1][i];
	}
	for(j=1;j<5;j++){
		for(i=j;i<5;i++){
			f[i][j]=(f[i][j-1]-f[i-1][j-1])/(cdn[0][i]-cdn[0][i-j]);
		}
	}
	for(k=0;k<4;k++){
		y[k]=f[4][4];
		for (j = 3; j >= 0; j--) {
	        y[k] = f[j][j] + (x[k] - cdn[0][j])*y[k];
	    }
		
		printf("\n%lf",y[k]);
	}

}
