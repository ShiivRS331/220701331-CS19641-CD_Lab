%{
#include "y.tab.h"
%}
%%
"if" { return IF; }
"else" { return ELSE; }
"for" { return FOR; }
"while" { return WHILE; }
"default" { return DEFAULT; }
"switch" { return SWITCH; }
"case" { return CASE; }
"(" { return LPAREN; }
")" { return RPAREN; }
"{" { return LBRACE; }
"}" { return RBRACE; }
";" { return SEMICOLON; }
":" { return COLON; }
"," { return COMMA; }
[a-zA-Z_][a-zA-Z0-9_]* { return ID; }
[0-9]+ { return NUMBER; }
"=="|"!="|">"|"<"|">="|"<=" { return RELOP; }
"="|"++"|"--" { return ASSIGN; }
[\t\n]+ ;
. ;
%%

int yywrap() {
    return 1;
}
