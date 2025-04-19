#include<stdio.h>
#include<string.h>

int main(){
        char str1[10],str2[10];
        printf("Enter String 1: ");
        scanf("%s",str1);
        printf("Entyer String 2: ");
        scanf("%s",str2);
        int ans = strcmp(str1,str2);
        if(ans==0)
                printf("Strings are same\n");
        else
                printf("Strings are not the same\n");
        return 0;
}
