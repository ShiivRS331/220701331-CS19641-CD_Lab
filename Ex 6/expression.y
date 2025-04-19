%{
#include <stdio.h>
void yyerror(const char *msg);
extern char *yytext;
int regs[26];
%}
%token DIGIT LETTER
%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS
%%
list:
         |
        list stat '\n'
         |
        list error '\n'
         {
           yyerrok;
         }
         ;
stat : expr { printf("%d\n",$1); }
        | LETTER '=' expr { regs[$1]=$3; }
        ;
expr : '(' expr ')' { $$ = $2; }
        | expr '+' expr { $$ = $1+$3; }
        | expr '-' expr { $$ = $1-$3; }
        | expr '*' expr { $$ = $1*$3; }
        | expr '/' expr { $$ = $1/$3; }
        | expr '%' expr { $$ = $1%$3; }
        | expr '&' expr { $$ = $1&$3; }
        | expr '|' expr { $$ = $1|$3; }
        | '-' expr %prec UMINUS { $$=-$2; }
        | LETTER { $$=regs[$1]; }
        | number
        ;
number : DIGIT { $$=$1; }
        | number DIGIT { $$=10*$1+$2; }
        ;
%%
void  yyerror(const char *msg){
  printf("Invalid equation or expression: %s\n",msg);
}

int main(){
  printf("Enter equation or expression: ");
  yyparse();
  return 0;
}

