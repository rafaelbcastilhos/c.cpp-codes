// recursive factorial
#include <stdio.h>

int factorial(int num){
	if(num == 1)
		return 1;

	else
		return num * factorial(num - 1);
}
	
int main(){
	int num;
	
	printf("\nenter number to be factored: ");
	scanf("%d", &num);
	
	factorial(num);
}
