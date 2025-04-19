#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
        char str[15];
        printf("Enter String: ");
        scanf("%s",str);
        for(int i=0;i<strlen(str);i++){
                str[i]=toupper(str[i]);
        }
        printf("Uppercase: %s\n",str);
        return 0;
}
