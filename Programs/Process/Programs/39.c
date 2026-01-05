#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
	int low_limit = 22 ,high_limit = 33;
	float f_low=0.5,f_high=0.8,range;
	srand(getpid());
	printf("0 to 10:%d\n",rand()%10 + 1);//0 to 10
	printf("0 to 100:%d\n",rand()%100);//0 to 100
	printf("0 to 1000:%d\n",rand()%1000);//0 to 1000
	printf("0  to 22: %d\n",rand()%(22+1));//0 to 22
	printf("%d to %d: %d\n",low_limit,high_limit,(rand()%(high_limit - low_limit + 1))+low_limit);
	range = f_high-f_low; 
	printf("%.2lf to %.2lf: %.2lf\n",f_low,f_high,(((float)rand())/RAND_MAX)*range+f_low);


}
