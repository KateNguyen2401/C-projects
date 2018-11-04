#include <stdio.h>
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
int yes(void);
void GroceryInventorySystem(void);
int menu(void);


/*
int main(void){
	int iVal;
	double dVal;
	welcome();




	printf("Listing header and footer with grand total:\n");
	printTitle();





	printFooter(1234.57);
	printf("Listing header and footer without grand total:\n");
	printTitle();
	printFooter(-1);



	pause();




	printf("Enter an integer: ");
	iVal = getInt();
	printf("You entered: %d\n",iVal);




	printf("Enter an integer between 10 and 20: ");
	iVal = getIntLimited(10, 20);
	printf("Your entered %d\n",iVal);




	printf("Enter a floating point number: ");
	dVal = getDouble();
	printf("You entered : %.2lf\n",dVal);




	printf("Enter a floating point number between 10.00 and 20.00: ");
	dVal = getDoubleLimited(10.0, 20.0);
	printf("You entered: %.2lf\n",dVal);





	GroceryInventorySystem();


	printf("End of tester program for milestone one!\n");
return 0;
}
*/
void welcome(void){
	printf("---=== Grocery Inventory System ===---\n\n");
	return;
}
void printTitle(void){
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
	return;
}
void printFooter(double gTotal){
	printf("--------------------------------------------------------+----------------\n");
	if(gTotal > 0){
		printf("                                           Grand Total: |%12.2lf\n",gTotal);
	}
	return;
}
void flushKeyboard(void){
	char c;
	do{
		scanf("%c",&c);
	}while(c != '\n');
}
void pause(void){
	printf("Press <ENTER> to continue...");
	flushKeyboard();
	return;
}
int getInt(void){
	int in;
	char ch = 'x';
	scanf("%d%c",&in,&ch);
	while(ch != '\n'){
		flushKeyboard();
		printf("Invalid integer, please try again: ");
		scanf("%d%c",&in,&ch);
	}
	return in;
}
int getIntLimited(int lowerLimit, int upperLimit){
	int inte;
	scanf("%d",&inte);
	while(inte <= 10 || inte >= 20){
		flushKeyboard();
		printf("Invalid value, %d < value < %d: ",lowerLimit,upperLimit);
		scanf("%d",&inte);
	}
	return inte;
}
double getDouble(void){
	double doub;
	char cha;
	scanf("%lf%c",&doub,&cha);
	while( cha != '\n'){
		flushKeyboard();
		printf("Invalid number, please try again: ");
		scanf("%lf%c",&doub,&cha);
	}
	return doub;
}
double getDoubleLimited(double lowerLimit, double upperLimit){
	double doubl;
	scanf("%lf",&doubl);
	while( doubl >= upperLimit || doubl <= lowerLimit){
		flushKeyboard();
		printf("Invalid value, %lf< value < %lf: ",lowerLimit,upperLimit);
		scanf("%lf",&doubl);
	}
	return doubl;
}
int yes(void){
	int i;
	char c;
	while( c != 'y' && c!= 'Y' && c!='n' && c!='N'){
		flushKeyboard();
		printf("Only (Y)es or (N)o are acceptable: ");
		scanf("%c",&c);
	}
	if(c=='y' || c=='Y')
		i=1;
	if(c=='n' || c=='N')
		i=0;
	return i;
}
int menu(void){
	int choice;
	printf("1- List all items\n2- Search by SKU\n3- Checkout an item\n4- Stock an item\n5- Add new item or update item\n6- Delete item\n7- Search by name\n0- Exit program\n");
	printf("> ");
	scanf("%d",&choice);
	while( choice > 7 || choice < 0){
		printf("Invalid value, 0 < value < 7: ");
		scanf("%d",&choice);
	}
	return choice;
}
void GroceryInventorySystem(void){
	int option;
	char s;
	welcome();
	do{
		option = menu();
		switch(option){
			case 1:
				printf("List Items under construction!\n");
				pause();
				printf("\n");
				break;        
			case 2:        
				printf("Search Items under construction!\n");
				pause();
				printf("\n");
				break;
			case 3:        
				printf("Checkout Item under construction!\n");
				pause();
				printf("\n");
				break;
			case 4:       
				printf("Stock Item under construction!\n");
				pause();
				printf("\n");
				break;
			case 5:       
				printf("Add/Update Item under construction!\n");
				pause();
				printf("\n");
				break;
			case 6:        
				printf("Delete Item under construction!\n");
				pause();
				printf("\n");
				break;        
			case 7:
				printf("Search by name under construction!\n");
				pause();
				printf("\n");
				break;
			case 0:
				flushKeyboard();
				printf("Exit the program? (Y)es/(N)o: ");
				scanf("%c",&s);
				if( s == 'y' || s=='Y')
					return;
				if( s =='n' || s=='N')
					break;
				yes();
				if(yes()==1)
					return;
				if(yes() ==0)
					break;
				break;       
		}        
	}while(option >= 0);
	return;
}
