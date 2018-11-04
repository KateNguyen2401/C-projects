#include <stdio.h>
#define MAX 10
int main(void){
	int n=0,i=0;
	int htemp[MAX],ltemp[MAX];
	int highest=0, lowest=0;
	int highday=0,lowday=0,avgday=0,totalhigh=0,totallow=0,total=0;
	float avg=0.0;
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d",&n);
	printf("\n");
	while(n>10||n<3){
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d",&n);
		printf("\n");
	}
	for(i=0;i<n;i++){
		printf("Day %d - High: ",i+1);
		scanf("%d",&htemp[i]);
		printf("Day %d - Low: ",i+1);
		scanf("%d",&ltemp[i]);
		if(htemp[i]>highest){
			highest=htemp[i];
			highday=i+1;
		}
		if(ltemp[i]<lowest){
			lowest=ltemp[i];
			lowday=i+1;
		}
	}
	printf("\nDay  Hi  Low\n");
	for(i=0;i<n;i++){
		printf("%d    %d    %d\n",i+1,htemp[i],ltemp[i]);
	}
	printf("\nThe highest temperature was %d, on day %d\n",highest,highday);
	printf("The lowest temperature was %d, on day %d\n",lowest,lowday);
	printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ",n);
	scanf("%d",&avgday);
	while(avgday>0){
		if(avgday>n){
			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ",n);
			scanf("%d",&avgday);
		}
		for(i=0;i<avgday;i++){
			totalhigh=totalhigh+htemp[i];
			totallow=totallow+ltemp[i];
		}
		total=totalhigh+totallow;
		avg=(float)total/(avgday*2);
		printf("\nThe average temperature up to day %d is: %.2f\n",avgday,avg);
		totalhigh=0,totallow=0;
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ",n);         
		scanf("%d",&avgday);
	}        
	if(avgday<0){
		printf("\nGoodbye!\n");
	}
return 0;
}
	
