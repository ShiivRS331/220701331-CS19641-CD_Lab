#include<stdio.h>
#include<string.h>

int main(){
        char str1[10],str2[10];
        printf("Enter String 1: ");
        scanf("%s",str1);
        printf("Enter String 2: ");
        scanf("%s",str2);
        strcat(str1,str2);
        printf("Concatenated String: %s\n",str1);
        return 0;
}
