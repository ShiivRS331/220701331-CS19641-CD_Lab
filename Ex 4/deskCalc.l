%{
#include<stdio.h>
#include<stdlib.h>
int valid = 1;
int yywrap(){ return 1; }
%}

DIGIT [0-9]
NUMBER {DIGIT}+\.?{DIGIT}*
OPERATOR [-+*/%]
PAREN [()]
WHITESPACE [\t\n]+

%%
{NUMBER}      { printf("Number: %s\n", yytext); }
{OPERATOR}    { printf("Operator: %s\n", yytext); }
{PAREN}       { printf("Parenthesis: %s\n", yytext); }
{WHITESPACE}  { /* Ignore whitespace */ }
.             { printf("Invalid Token: %s\n", yytext); valid = 0; }
%%

int main(){
    printf("Enter Arithmetic Expression: ");
    yylex();
    if(valid)
        printf("Valid Arithmetic Expression\n");
    else
        printf("Invalid Arithmetic Expression\n");
    return 0;
}
