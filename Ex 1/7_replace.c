#include<stdio.h>
#include<string.h>

int main(){
        char str[10];
        char ch1,ch2;
        printf("Enter String: ");
        scanf("%s",str);
        printf("Enter char to replace: ");
        scanf(" %c",&ch1);
        printf("Enter replacing char: ");
        scanf(" %c",&ch2);
        for(int i=0;i<strlen(str);i++){
                if(str[i]==ch1)
                        str[i]=ch2;
        }
        printf("New String: %s\n",str);
        return 0;
}
