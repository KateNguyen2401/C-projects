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
void flushKeyboard();
int readRecord(FILE *fp, struct Book *b2read);
void displayInventory(const char filename[]);
float calculateCapital(const char filename[]);
int searchInventory(FILE *fp, const int isbn2find);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);
int main(void){
	int option,isbn;
	struct Book mybook;
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
				addBook(filename, &mybook);
				break;
			case 3:
				printf("Please input the ISBN number of the book:\n\n");
				scanf("%d", &isbn);
				checkPrice(filename, isbn);
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
int searchInventory(FILE *fp, const int isbn2find) {
	int flag = -1,i;
	struct Book b;
	fp = fopen("144_w9_inventory.txt", "r");
	for(i=0;readRecord(fp,&b)==5;i++){
		if (b._isbn == isbn2find)
			flag = i;
	}
	return flag;
}
void addBook(const char filename[], struct Book *b2Add) {
	int isbn;
	FILE *fp = fopen(filename, "a");
	printf("ISBN:");
	scanf("%d", &isbn);
	flushKeyboard();
	(*b2Add)._isbn = isbn;
	printf("Title:");
	scanf("%[^\n]", (*b2Add)._title);
	flushKeyboard();
	printf("Year:");
	scanf("%d", &(*b2Add)._year);
	printf("Price:");
	scanf("%f", &(*b2Add)._price);
	printf("Quantity:");
	scanf("%d", &(*b2Add)._qty);
	if (searchInventory(fp, isbn) != -1) {
		printf("The book exists in the repository!\n\n");
	}
	else {
		fprintf(fp, "%d;%.2f;%d;%d;%s\n", b2Add->_isbn, b2Add->_price, b2Add->_year, b2Add->_qty, b2Add->_title);
		printf("The book is successfully added to the inventory.\n\n");
	}
	fclose(fp);
}
void flushKeyboard() {
	while (getchar() != '\n');
}
void checkPrice(const char filename[], const int isbn2find) {
	struct Book b;
	FILE *fp = fopen(filename, "r");             
	if (searchInventory(fp, isbn2find) != -1) {
		while(readRecord(fp,&b)==5){
			if(b._isbn == isbn2find)
			printf("Book %d costs $%.2f\n\n", isbn2find, b._price);
		}
	}
	else {
		printf("The book does not exist in the inventory.\n\n");
	}
	
}
