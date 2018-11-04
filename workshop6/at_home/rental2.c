#include <stdio.h>
struct Rental{
	int id;
	double baseDay;
	double earnings;
};
double addPositive(double newAmount,double amount);
void RentalInfoDisplay();
double ApplyRentalCharges();
struct Rental vRent[3]={{123,9.95,0},{124,19.95,0},{125,29.95,0}};
double taxCalc(double price, double rate);
double subtractPositive(double amount, double newAmount);
void giftcard(void);
int main(void){
	int option;
	double taxRate = 0.14;
	printf("***** Rental Vehicle Management App *****\n\n");
	do{
		printf("1.) Rental Status\n2.) Apply Charges\n3.) Apply Taxes to All Rentals\n4.) Apply Gift Card\n0.) Log out\n");
		printf("\nPlease enter an option to continue: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("\n-- Rental Vehicle Status --\n");
				RentalInfoDisplay();
				break;
			case 2:
				printf("\n-- Rental Charges --\n");
				ApplyRentalCharges();
				break;
			case 3:
				printf("\n-- Apply Taxes To all Accounts--\n");
				taxCalc(0,taxRate);
				break;
			case 4:
				printf("\n-- Apply Gift Card --\n\n");
				giftcard();
				break;
			case 0:
				return 0;
			default:
				printf("ERROR!!! Wrong option. Please enter again.\n");
		}
	}while(option >= 0);
return 0;
}
void RentalInfoDisplay(){
	int i;
	printf("\nID#      Earnings\n-------- ----------\n");
	for(i=0;i<3;i++){        
		printf("%8d %10.2lf\n",vRent[i].id,vRent[i].earnings);
	}
	printf("\n");
	return;
} 
double ApplyRentalCharges(){
	int i,id;
	int flag=-1;
	int km,day;
	double disRate1 = 0.69, disRate2 = 0.49;
	double discount=5.0,amount=0.0,kmcost,charge,baseprice;
	char disc,c;
	printf("\nEnter vehicle ID: ");
	scanf("%d",&id);
	for(i=0;i<3;i++){
		if(vRent[i].id == id)
			flag=i;
	}
	if(flag != -1){
		printf("Enter Rental Period (in Days): ");
		scanf("%d",&day);
		printf("Enter kilometers driven: ");
		scanf("%d",&km);
		if(km > 100){
			kmcost = (km-100) * disRate2 + 69;
		}else{
			kmcost = km * disRate1;
		}
		baseprice = vRent[flag].baseDay * day;
		charge = baseprice + kmcost;
		vRent[flag].earnings = addPositive(charge,amount);
		printf("Apply Discount: ");
		do{
			scanf("%c",&c);
		}while(c != '\n');
		
		scanf("%c",&disc);
		if(disc == 'Y' || disc == 'y'){
			charge = subtractPositive(vRent[flag].earnings,discount);
			vRent[flag].earnings = charge;
		}
		printf("\nBase   kmCost DiscStatus Total\n====== ====== ========== ======\n");
		printf("%6.2lf %6.2lf %10c %6.2lf\n\n",baseprice,kmcost,disc,charge);
	}else{
		printf("ERROR: Vehicle ID does not exist.\n\n");
	}

	return charge;
}
double addPositive(double newAmount,double amount){
	if (newAmount>0){
		amount=amount + newAmount;
	}
	return amount;
}
double subtractPositive(double amount, double newAmount){
	double sub=0.0;
	if(newAmount>0){
		sub=amount -  newAmount;
	}
	return sub;
}
double taxCalc(double price, double rate){
	int i;
	printf("\nID#      Earnings   Taxes\n-------- ---------- ------\n");
	for(i=0;i<3;i++){
		price = vRent[i].earnings * rate;
		vRent[i].earnings = addPositive(vRent[i].earnings,price); 
		printf("%8d %10.2lf %6.2lf\n",vRent[i].id,vRent[i].earnings,price);
	}
	printf("\n");
	return price;
}
void giftcard(void){
	int id;
	double amt;
	int i, flag =-1;
	printf("Enter vehicle ID: ");
	scanf("%d",&id);
	for(i=0;i<3;i++){
		if(vRent[i].id == id)
			flag = i;
	}
	if(flag != -1){
		printf("Enter Gift Card Amount: ");
		scanf("%lf",&amt);
		printf("Discount Applied\n\n");
		vRent[flag].earnings = subtractPositive(vRent[flag].earnings,amt);
	}else{
		printf("ERROR!!! Wrong ID.\n");
	}
	return;
}
