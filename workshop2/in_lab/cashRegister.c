#include <stdio.h>
int main(void){
	double amount=0.0;
	int loonies_no=0;
	int quarters_no=0;
	double BalOw=0.0;
		printf("Please enter the amount to be paid: $");
		scanf("%lf",&amount);
	loonies_no = amount/1;
	BalOw = amount-loonies_no;
		printf("Loonies required: %d, ",loonies_no);
		printf("balance owing $%.2lf\n",BalOw);
	quarters_no = BalOw/0.25;
	amount = BalOw;
	BalOw = amount - quarters_no*0.25;
		printf("Quarters required: %d, ",quarters_no);
		printf("balance owing $%.2lf\n",BalOw);
return 0;
}
	
