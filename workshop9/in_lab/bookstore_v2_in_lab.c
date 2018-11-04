  #include <stdio.h>
#define MAX_TITLE_SIZE 21
struct Book {
	int _isbn;
	float _price;
	int _year;
	int _qty;
	char _title[MAX_TITLE_SIZE];
};
void menu();
int readRecord(FILE *fp, struct Book *b2read);
void displayInventory(const char filename[]);
float calculateCapital(const char filename[]);

int main(void){
	int option;
	//struct Book mybook;
	char filename[] = "144_w9_inventory.txt";
	printf("Welcome to the Book Store\n=========================\n");
	do{
		menu();
		printf("\nSelect: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				displayInventory(filename);
				break;
			case 2:
				printf("Not implemented\n");
				break;
			case 3:
				printf("Not implemented\n");
				break;
			case 4:
				printf("The total capital is: $%.2f.\n",calculateCapital(filename));
				break;
			case 0:
				printf("Goodbye!\n");
				return 0;
			default:
				printf("Invalid input, try again:\n");
		}
	}while(option>=0);

return 0;
}
void menu(){
	printf("Please select from the following options:\n1) Display the inventory.\n2) Add a book to the inventory.\n3) Check price.\n4) Calculate total capital of the store.\n0) Exit.\n");
	return;
}
int readRecord(FILE *fp, struct Book *b2read) {
	int rv = 0;
	rv = fscanf(fp, "%d;%f;%d;%d;%[^\n]\n", &b2read->_isbn, &b2read->_price, &b2read->_year, &b2read->_qty, b2read->_title);
	return rv;
}
void displayInventory(const char filename[]) {
	struct Book book;
	FILE *fp = fopen(filename, "r");
	printf("\n\nInventory\n");
	printf("===================================================\n");
	printf("ISBN      Title               Year Price  Quantity\n"
			"---------+-------------------+----+-------+--------\n");
	while(readRecord(fp,&book) == 5){
		printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book._isbn, book._title, book._year, book._price, book._qty);
	}
	printf("===================================================\n\n");
	fclose(fp);
}
float calculateCapital(const char filename[]) {
	float total = 0;
	struct Book book;
	FILE *fp= fopen(filename,"r");
	while (readRecord(fp, &book) == 5) {
		total = total + (book._price*book._qty);
	}
	fclose(fp);
	return total;
}
