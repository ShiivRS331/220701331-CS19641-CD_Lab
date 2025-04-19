%{
#include <stdio.h>
void yyerror(const char *msg);
extern char *yytext;
%}
%token IDENTIFIER
%%
stmt: IDENTIFIER {printf("Valid variable: %s\n",yytext);return 0; }
  ;
%%
void  yyerror(const char *msg){
  printf("Invalid Variable\n");
}

int main(){
  printf("Enter a variable name: ");
  yyparse();
  return 0;
}
