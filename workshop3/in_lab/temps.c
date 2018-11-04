#include <stdio.h>
#define NUMS 3
int main(void){
	printf("---=== IPC Temperature Analyzer ===---\n");
	int i=0,ltemp[3], htemp[3],totalhigh=0,totallow=0,total=0;
	float avg=0.0;
	for (i=0;i<NUMS; i++){
	printf("Enter the high value for day %d: ",i+1);
	scanf("%d",&htemp[i]);
	printf("\n");
	printf("Enter the low value for day %d: ",i+1);
	scanf("%d",&ltemp[i]);
	printf("\n");
	
	while(htemp[i]<ltemp[i]||htemp[i]>40||htemp[i]<-40||ltemp[i]<-40){
	printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
	printf("\n");
	printf("Enter the high value for day %d: ",i+1);
	scanf("%d",&htemp[i]);
	printf("\n");
	printf("Enter the low value for day %d: ",i+1);
	scanf("%d",&ltemp[i]);
	printf("\n");
	}
	totalhigh=totalhigh+htemp[i];
	totallow=totallow+ltemp[i];
	total=totalhigh+totallow;
	avg=(float)total/6;
	}
	printf("The average (mean) temperature was: %.2f\n",avg);
	
return 0;
}
      
