%{
#include<stdio.h>
void yyerror(const char *msg);
int yylex();
%}

%token IF ELSE FOR WHILE DEFAULT SWITCH CASE
%token ID NUMBER
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COLON COMMA RELOP ASSIGN

%%
program:
        program stmt
        |
        ;
stmt:
        if_stmt
        | for_stmt
        | while_stmt
        | switch_stmt
        ;

if_stmt:
        IF LPAREN /* condition */ RPAREN LBRACE /* statements */ RBRACE
        | IF LPAREN /* condition */ RPAREN LBRACE /* statements */ RBRACE ELSE LBRACE /* statements */ RBRACE
        ;
for_stmt:
        FOR LPAREN /* initialization */ SEMICOLON /* condition */ SEMICOLON /* increment */ RPAREN LBRACE /* statements */ RBRACE
        ;

while_stmt:
        WHILE LPAREN /* condition */ RPAREN LBRACE /* statements */ RBRACE
        ;

switch_stmt:
        SWITCH LPAREN ID RPAREN LBRACE case_list default_case RBRACE
        | SWITCH LPAREN ID RPAREN LBRACE case_list RBRACE
        ;

case_list:
        case_list case_stmt
        |
        ;
case_stmt:
        CASE NUMBER COLON /* statements */
        ;

default_case:
        DEFAULT COLON /* statements */
        ;
%%
void yyerror(const char *msg){
  printf("Invalid equation or expression: %s\n",msg);
}

int main(){
  printf("Enter a Control Structure: \n");
  yyparse();
  printf("\nEntered code is valid\n");
  return 0;
}
