%{
#include<stdio.h>
#include<stdlib.h>
int valid =1;
int yywrap(){return 1;}
%}

DIGIT [0-9]
NUMBER {DIGIT}+\.?{DIGIT}*
OPERATOR [+-*/%]
PAREN [()]

%%
{NUMBER} {printf("Number: %s\n",yytext);}
{OPERATOR} {printf("Operator: %s\n",yytext);}
{PAREN} {printf("Parenthesis: %s\n",yytext);}
[\t\n] {}
. {printf("Invalid Token: %s\n", yytext);}
%%

int main(){
printf("Enter Arithmatic Expression: ");
yylex();
if(valid)
        printf("Valid Arithmatic Expression");
else
        printf("Invalid Arithmatic Expression");
return 0;
}
