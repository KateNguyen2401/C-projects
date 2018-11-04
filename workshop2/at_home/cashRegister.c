#include <stdio.h>
int main(void){
	double amount=0.0;
	int loonies_no=0;
	int a=0,b=0;
	double BalOw=0.0;
	double GST=0.0;
	printf("Please enter the amount to be paid: $");
	scanf("%lf",&amount);
	GST = amount*.13 + 0.005;
	printf("GST: %.2lf\n",GST);
	BalOw = amount + GST;
	printf("Balance owing: $%.2lf\n",BalOw);
	loonies_no = BalOw/1;
	BalOw= BalOw - loonies_no;
	printf("Loonies required: %d, ",loonies_no);
	printf("balance owing $%.2lf\n",BalOw);
	a=BalOw*100;
	b = a%25;
	int quarters_no=(a-b)/25;
	a=b;
	printf("Quarters required: %d, ",quarters_no);
	printf("balance owing $%1.2lf\n",(float)b/100);
	b=a%10;
	int dimes=(a-b)/10;
	a=b;
	printf("Dimes required: %d, ",dimes);
	printf("balance owing $%1.2lf\n",(float)b/100);
	b=a%5;
	int nickels=(a-b)/5;
	printf("Nickels required: %d, ",nickels);
	printf("balance owing $%1.2lf\n",(float)b/100);
	int pennies=b;
	printf("Pennies required: %d, ",pennies);
	printf("balance owing $0.00\n");

return 0;
}
	
