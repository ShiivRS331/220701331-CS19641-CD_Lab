#include<math.h>
#include<stdio.h>

int main(){
        int a,b;
        char op;
        printf("Enter a: ");
        scanf("%d",&a);
        printf("Enter operator(+-*/%): ");
        scanf(" %c",&op);
        printf("Enter b: ");
        scanf("%d",&b);
        switch(op){
                case '+': printf("%d + %d = %d\n", a,b, a+b); break;
                case '-': printf("%d - %d = %d\n", a,b, a-b); break;
                case '*': printf("%d * %d = %d\n", a,b, a*b); break;
                case '/': printf("%d / %d = %d\n", a,b, a/b); break;
                case '%': printf("%d %% %d = %d\n", a,b, a%b); break;
//              case '^': printf("%d ^ %d = %lf\n", a,b, pow(a,b)); break;
                default: printf("Invalid Operator");
        }
}
