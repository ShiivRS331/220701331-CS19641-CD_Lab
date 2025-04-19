#include<stdio.h>
#include<string.h>

int main(){
        char str[50],res[50];
        int ind = 0;
        printf("Enter String: ");
        scanf("%[^\n]s",str);
        for(int i=0;i<strlen(str);i++){
                if(str[i]!=' '){
                        res[ind++]=str[i];
                        res[ind]='\0';
                        }
        }
        printf("Without Space: %s\n",res);
        return 0;
}
