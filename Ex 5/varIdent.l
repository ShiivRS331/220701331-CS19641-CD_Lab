%{
#include "y.tab.h"
%}

%option noyywrap

%%
[a-zA-Z][a-zA-Z0-9]* {return IDENTIFIER;}
[\t\n] {}
. {return yytext[0];}
%%
