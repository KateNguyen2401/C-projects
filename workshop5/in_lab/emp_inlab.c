#include <stdio.h>
#define SIZE 2
struct employee{
	int id;
	int age;
	double salary;
};
int main(void){
	struct employee emp[SIZE];
	int option;
	int i=0;
	
	printf("---=== EMPLOYEE DATA ===---\n");
	do{
		printf("\n1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n");
		printf("\nPlease select from the above options: ");
		scanf("%d",&option);
		printf("\n");
		switch(option){
			case 1:
				printf("EMP ID  EMP AGE EMP SALARY\n======  ======= ==========\n");
				for(i=0;i<SIZE;i++){
				
				printf("   %d       %d   %.2lf\n",emp[i].id, emp[i].age, emp[i].salary);
				}
				break;
			case 2:
				if(i<SIZE){
					
					printf("Adding Employee\n===============\n");
					printf("Enter Employee ID: ");
					scanf("%d",&emp[i].id);
					printf("Enter Employee Age: ");
					scanf("%d",&emp[i].age);
					printf("Enter Employee Salary: ");
					scanf("%lf",&emp[i].salary);
					i=i+1;
				}else{
					printf("Adding Employee\n===============\nERROR!!! Maximum Number of Employees Reached\n");
				}
				break;
			case 0:
				printf("Exiting Employee Data Program. Good Bye!!!\n");
				return 0;
			default:
				printf("Error!! Invalid menu option selections\n");
			}
			
	}while(option>=0);

   
	
return 0;
}
