// tic tac toe with some functions
#include<stdio.h>
#define DIM 3

// functions prototype
void init(char matrix[DIM][DIM]);
int insert(char matrix[DIM][DIM], char x, char o, int l);
int print(char matrix[DIM][DIM]);

int main(void){
    char matrix[DIM][DIM], o='o', x='x';
    int l = 0;
    
    init(matrix);
    
    do{
		l = insert(matrix, x, o, l);

		if((matrix[0][0]==o && matrix[0][1]==o && matrix[0][2]==o)||
        (matrix[1][0]==o && matrix[1][1]==o && matrix[1][2]==o)||
        (matrix[2][0]==o && matrix[2][1]==o && matrix[2][2]==o)||
        (matrix[0][0]==o && matrix[1][0]==o && matrix[2][0]==o)||
        (matrix[0][1]==o && matrix[1][1]==o && matrix[2][1]==o)||
        (matrix[0][2]==o && matrix[1][2]==o && matrix[2][2]==o)||
        (matrix[0][0]==o && matrix[1][1]==o && matrix[2][2]==o)||
        (matrix[0][2]==o && matrix[1][1]==o && matrix[2][0]==o)){
			printf("\t\t###################\n");
			printf("\t\t## player 1 won! ##\n");
			printf("\t\t###################\n");
			print(matrix);
			break;
		}
    
		if((matrix[0][0]==x && matrix[0][1]==x && matrix[0][2]==x)||
			(matrix[1][0]==x && matrix[1][1]==x && matrix[1][2]==x)||
			(matrix[2][0]==x && matrix[2][1]==x && matrix[2][2]==x)||
			(matrix[0][0]==x && matrix[1][0]==x && matrix[2][0]==x)||
			(matrix[0][1]==x && matrix[1][1]==x && matrix[2][1]==x)||
			(matrix[0][2]==x && matrix[1][2]==x && matrix[2][2]==x)||
			(matrix[0][0]==x && matrix[1][1]==x && matrix[2][2]==x)||
			(matrix[0][2]==x && matrix[1][1]==x && matrix[2][0]==x)){
				printf("\t\t###################\n");
				printf("\t\t## player 2 won! ##\n");
				printf("\t\t###################\n");
				print(matrix);
				break;
		}
		
		if(l==9){
			printf("\t\t###################\n");
			printf("\t\t###### draw! ######\n");
			printf("\t\t###################\n");
			print(matrix);
			break;
		}
    }while(l <= 9);
    
    return 0;
}

void init(char matrix[DIM][DIM]){
	// starter matrix
	int i, j;
	
	for(i = 0; i < DIM; i++){
        for(j = 0; j < DIM; j++)
            matrix[i][j]=' ';
	}
}

int insert(char matrix[DIM][DIM], char x, char o, int l){
	// input coordinates
	int i, j;
	
	printf("\t\t###################\n");
    printf("\t\t# tic - tac - toe #\n");
	printf("\t\t###################\n\n");
    for(i = 0; i < DIM; i++){
        printf("\t\t     %c \xBA %c \xBA %c\n", matrix[i][0], matrix[i][1], matrix[i][2]);
        if(i < DIM-1){
            printf("\t\t    ---\xCE---\xCE---\n");
        }
    }
        
    printf("\n\ninsert coordinates!\n");
	if(l%2)
		printf("player 2 (x)\nrow: ");
	else 
		printf("player 1 (o)\nrow: ");
		scanf("%d",&i);
		printf("column: ");
		scanf("%d",&j);
			
	if(matrix[i-1][j-1] == ' '){
		if(l%2)
			matrix[i-1][j-1]=x;
		else{
			matrix[i-1][j-1]=o;
			l++;
		}
	}
    return l;    
}

int print(char matrix[DIM][DIM]){
	// print matrix with results
	int i, j;
	
	for(i = 0; i < DIM; i++){
        printf("\t\t     %c \xBA %c \xBA %c\n", matrix[i][0], matrix[i][1], matrix[i][2]);
        if(i < DIM-1)
			printf("\t\t    ---\xCE---\xCE---\n");
    }
    return 0;
}
