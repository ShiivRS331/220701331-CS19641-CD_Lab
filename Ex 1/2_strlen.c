#include<stdio.h>
#include<string.h>

int main(){
        char str[25],substr[10];
        printf("Enter String: ");
        scanf("%s",str);
        printf("Enter Substring: ");
        scanf("%s",substr);

        int slen = strlen(str);
        int subslen = strlen(substr);

        if(subslen>slen){
                printf("Substring Not Found.\n");
                return 0;
        }
        for(int i=0;i<slen;i++){
                int flag=1;
                for(int j=0;j<subslen;j++){
                        if(str[i+j]!=substr[j]){
                                flag=0;
                                break;
                        }
                }
                if(flag){
                        printf("String found at index %d\n",i);
                        return 0;
                }
        }
        printf("String Not Found.i\n");
        return 0;
}
