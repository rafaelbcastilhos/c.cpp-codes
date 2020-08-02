// grade media using dynamic allocation and files
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//functions prototype
int average(double avg, int countGrades);
int writeData(FILE *fd, int countGrades);
int readFile(FILE *fd, int countGrades, char row[]);

int main(){
	FILE *fd;
	int i, countRow, countGrades;
	char row[100];

	if(access("grades.txt", F_OK) != -1){
		// file already exists and has been opened
		fd = fopen("grades.txt", "r");
		// row size
		fgets(row, sizeof(row), fd);
		countGrades = atoi(row);
		if(countGrades > 0)
			readFile(fd, countGrades, row);

		else{
			printf("\nblank file...\n\n");
			writeData(fd, countGrades);
		}
	}

	else{
    	// file doesnt exist and was successfully created
		fd = fopen("grades.txt", "w");
		writeData(fd, countGrades);
	}
	return 0;
	fclose(fd);
}

int average(double avg, int countGrades){
	avg = avg / (double)countGrades;
	printf("\nthe average is: %.2lf", avg);
	return 0;
}

int writeData(FILE *fd, int countGrades){
	int i;
  	double *grades, avg;

  	// row size
	printf("\nenter the amount of grades: ");
	scanf("%d", &countGrades);
	fprintf(fd, "%d\n", countGrades);

 	 // memory allocation according to amount of grades
	grades = malloc(sizeof(double)*countGrades);

 	 // write grades
	for(i = 0; i < countGrades; i++){
		printf("\nenter grade %d: ", i + 1);
		scanf("%lf", &grades[i]);
		fprintf(fd, "%.2lf\n", grades[i]);
		avg += grades[i];
	}

	average(avg, countGrades);
	return 0;
}

int readFile(FILE *fd, int countGrades, char row[]){
	int i, aux[10];
	double *grades, avg = 0.0;

	// memory allocation according to amount of rows
	grades = malloc(sizeof(double)*countGrades);
	printf("the amount of grades is: %d", countGrades);

	// string to double conversion
	while(fgets(row, sizeof(row), fd) != NULL){
		grades[i + 1] = atof(row);
		printf("\ngrade %d: %.2lf", i + 1, grades[i + 1]);
		avg += grades[i + 1];
		i++;
	}
	
	average(avg, countGrades);
	return 0;
}
