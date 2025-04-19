#include<stdio.h>
#include<string.h>

int main(){
        char str[10];
        int freq[256]={0};
        printf("Enter String: ");
        scanf("%s",str);
        for(int i=0;i<strlen(str);i++)
                freq[str[i]]++;
        printf("Character Frequencies: \n");
        for(int i=0;i<256;i++){
                if(freq[i]>0)
                        printf("%c : %d\n",i,freq[i]);
        }
        return 0;
}
