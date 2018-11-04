#include <stdio.h>
#define MAX 10
int main(void){
	int n=0,i=0;
	int htemp[MAX],ltemp[MAX];
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
	}
	printf("\nDay  Hi  Low\n");
	for(i=0;i<n;i++){
		printf("%d    %d    %d\n",i+1,htemp[i],ltemp[i]);
	}
     
return 0;
}
	
