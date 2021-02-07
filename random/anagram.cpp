#include <stdio.h>  
#include <string.h> 
#include <stdlib.h>  

int checkAnagram(char* str1, char* str2);

int main(){
    char str1[100], str2[100];
    
    printf("--- anagram program ---\n\n");
    
    printf("Input the first string: ");
    fgets(str1, sizeof str1, stdin);
    printf("Input the second string: ");
    fgets(str2, sizeof str2, stdin);

    if(checkAnagram(str1, str2) == 1){
        str1[strlen(str1)-1] = '\0';
        str2[strlen(str2)-1] = '\0';
        printf("%s and %s are anagram.\n\n",str1,str2);
    }
    else {
        str1[strlen(str1)-1] = '\0';
        str2[strlen(str2)-1] = '\0';
        printf("%s and %s arent anagram.\n\n", str1, str2);
    }
    return 0;
}

int checkAnagram(char* str1, char* str2){
    int str1ChrCtr[256] = {0}, str2ChrCtr[256] = {0}, ctr;
    
    if(strlen(str1) != strlen(str2))
        return 0;
    
    for(ctr = 0; str1[ctr] != '\0'; ctr++)
        str1ChrCtr[str1[ctr]]++;

    for(ctr = 0; str2[ctr] != '\0'; ctr++)
        str2ChrCtr[str2[ctr]]++;

    for(ctr = 0; ctr < 256; ctr++){
        if(str1ChrCtr[ctr] != str2ChrCtr[ctr])
            return 0;
    }
    return 1;
}