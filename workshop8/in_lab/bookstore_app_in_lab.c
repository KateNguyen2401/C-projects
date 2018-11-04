#include <stdio.h>
#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20
struct Book{
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};
void menu();
void displayInventory(const struct Book book[], const int size);
void addBook(struct Book book[], int *size);
void flushKeyboard(void);
int main(void){
	struct Book book[MAX_BOOKS];
	int size=0;
	int option;
	printf("Welcome to the Book Store\n=========================\n");
	do{
		menu();
		printf("\nSelect: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				displayInventory(book, size);
				break;
			case 2:
				addBook(book,&size);
				size++;
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
	printf("Please select from the following options:\n1) Display the inventory.\n2) Add a book to the inventory.\n3) Check price.\n0) Exit.\n");
	return;
}
void displayInventory(const struct Book book[], const int size){
	int i;
	if(size == 0){
		printf("The inventory is empty!\n");
		printf("===================================================\n\n");
	}else{
		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n"
			"---------+-------------------+----+-------+--------\n");
	      
		for(i=0;i<size;i++){
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n",book[i]._isbn,book[i]._title,book[i]._year,book[i]._price,book[i]._qty);
		
		}
	printf("===================================================\n\n");
	}
	return;
}
void addBook(struct Book book[], int *size){
	if(*size < MAX_BOOKS ){
		printf("ISBN:");
		scanf("%d",&book[*size]._isbn);
		flushKeyboard();
		printf("Title:");
		scanf("%[^\n]",book[*size]._title);
		flushKeyboard();
		printf("Year:");
		scanf("%d",&book[*size]._year);
		printf("Price:");
		scanf("%f",&book[*size]._price);
		printf("Quantity:");
		scanf("%d",&book[*size]._qty);
		printf("The book is successfully added to the inventory.\n\n");
	}else{
		printf("ERROR!!! Book Inventory is full.\n");
	}
	return;
}
void flushKeyboard(void){
	while(getchar() != '\n');
}
