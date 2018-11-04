#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int isJediMaster(const char name[]);
void formatJediPhoneRecord(char formattedRecord[], const char fullname[], const char npa[], const char co[], const char number[]);
/*int main(void) {
	FILE* fptr = fopen("starwars_directory.csv", "r");
	char name[31];
	char npa[4];
	char co[4];
	char number[5];
	char formatted[45] = "";
	if (fptr != NULL) {
		while (fscanf(fptr, "%[^,],%s%s%s\n", name, npa, co, number) == 4) {
			//strcpy(formatted,"");
			formatJediPhoneRecord(formatted, name, npa, co, number);
			printf("%s\n", formatted);
		}
		fclose(fptr);
	}
	else {
		printf("File not found!\n");
	}
	return 0;

}*/
int isJediMaster(const char name[]) {
	int isJedi = 0;
	char check[31];
	FILE *fp=NULL;
	fp = fopen("jedi_master.txt", "r");
	if(fp != NULL){
		while (fscanf(fp, "%[^\n]%*c", check) > 0) {
			if (strcmp(check, name) == 0) {
				isJedi = 1;
			}
		}
	}
	else{
		printf("Failed to open the file!\n");
	}
	fclose(fp);
	return isJedi;
}
void formatJediPhoneRecord(char formattedRecord[], const char fullname[], const char npa[], const char co[], const char number[]) {
	int i;
	char check[20];
	char full[45];
	strcpy(formattedRecord,"");
	if (strlen(fullname) > 16) {
		strncpy(check, fullname,14);
		check[14] = '\0';
		strcpy(full, check);
		strcat(full, "..");
	}
	else {
		strcpy(full, fullname);
		for(i=0;i<16-strlen(fullname);i++)
			strcat(full, " ");
	}
	strcat(formattedRecord, full);
	strcat(formattedRecord, " (");
	strcat(formattedRecord, npa);
	strcat(formattedRecord, ") ");
	strcat(formattedRecord, co);
	strcat(formattedRecord, "-");
	strcat(formattedRecord, number);
	if (isJediMaster(fullname) == 1)
		strcat(formattedRecord, " Jedi Master");

}
