// seconds to hours converter
#include <stdio.h>

void converter(int time); // prototype

int main(){
	int time;
	
	printf("\nenter the seconds: ");
	scanf("%d", &time);
	
	converter(time);
}

void converter(int time){
	int hours, minutes, seconds;
	int secHours = 3600;
	int minHours = 60;

	hours = (time/secHours);
	minutes = (time - (secHours * hours)) / minHours;
	seconds = (time - (secHours * hours) - (minutes*minHours));
	
	printf("\n%dh : %dm : %ds \n", hours, minutes, seconds);
}
