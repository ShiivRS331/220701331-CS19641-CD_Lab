%{
#include <stdio.h>
%}
identifier    [a-zA-Z_][a-zA-Z0-9_]*
integer       [0-9]+
float         [0-9]*\.[0-9]+
operator      [-+*/=<>!&|]
comment_start  "/*"
comment_end    "*/"
string        \"([^\\\n]|(\\.))*?\"
keyword       "int"|"float"|"char"|"if"|"else"|"while"|"for"|"return"|"void"|"double"|"struct"|"switch"|"case"|"break"|"continue"

%%
{keyword}     { printf("Keyword: %s\n",yytext); }
{identifier}  { printf("Identifier: %s\n", yytext); }
{integer}     { printf("Integer: %s\n", yytext); }
{float}       { printf("Float: %s\n", yytext); }
{operator}    { printf("Operator: %s\n", yytext); }
{comment_start}.*{comment_end} { printf("Comment: %s\n", yytext); }
"//".*         { printf("Comment: %s\n", yytext); }
{string}      {printf("String: %s\n", yytext);}
"("           { printf("Left Parenthesis: %s\n", yytext); }
")"           { printf("Right Parenthesis: %s\n", yytext); }
"{"           { printf("Left Brace: %s\n", yytext); }
"}"           { printf("Right Brace: %s\n", yytext); }
";"           { printf("Semicolon: %s\n", yytext); }
","           { printf("Comma: %s\n", yytext); }
[ \t\n]       ; /* Ignore whitespace */
.             { printf("Unknown token: %s\n", yytext); }

%%

int yywrap(void){};

int main() {
    printf("Input Source Code:");
    yylex();
    return 0;
}
