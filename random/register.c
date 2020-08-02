// registers using struct -> name, age and address
#include <stdio.h>
#define STRING 25

typedef	struct{
	char name[STRING];
	int age;
	char address[STRING];
} registerp;

int main(){
	int i, sz;
	
	printf("\nenter the number of registers: ");
	scanf("%d", &sz);
	
	registerp r[sz];
	
	for(i = 0; i < sz; i++){
		printf("\nenter your name: ");
		scanf(" %[^\n]s", r[i].name);
		printf("\nenter your age: ");
		scanf("%d", &r[i].age);
		printf("\nenter your address: ");
		scanf(" %[^\n]s", r[i].address);
	}
	
	printf("\nregistration table: ");
	printf("\nname:\t\t| age:\t\t| address:\n");
	
	for(i = 0; i < sz; i++)
		printf("%s\t| %d\t\t| %s\n", r[i].name, r[i].age, r[i].address);
}

