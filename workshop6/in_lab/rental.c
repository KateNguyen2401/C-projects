#include <stdio.h>
struct Rental{
	int id;
	double baseDay;
	double earnings;
};
double addPositive(double newAmount,double amount);
void RentalInfoDisplay();
double ApplyRentalCharges();
struct Rental vRent[2]={{123,9.95,0},{124,19.95,0}};

int main(void){
	int option;
	printf("***** Rental Vehicle Management App *****\n\n");
	do{
		printf("1.) Rental Status\n2.) Apply Charges\n0.) Log out\n");
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
	for(i=0;i<2;i++){        
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
	double kmcost,newAmount,amount=0.0,charge,baseprice;
	printf("\nEnter vehicle ID: ");
	scanf("%d",&id);
	for(i=0;i<2;i++){
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
		newAmount = charge;
		addPositive(newAmount,amount);
		vRent[flag].earnings = vRent[flag].earnings + addPositive(newAmount,amount);
		printf("\nBase   kmCost Total\n====== ====== ======\n");
		printf("%6.2lf %6.2lf %6.2lf\n\n",baseprice,kmcost,charge);
	}else{
		printf("ERROR: Vehicle ID does not exist.\n\n");
	}

	return charge;
}
double addPositive(double newAmount,double amount){
	if (newAmount>0){
		amount=newAmount;
	}
	return amount;
}
