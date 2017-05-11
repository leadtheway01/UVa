/*Wright Kim
  wdk7bj
*/

%{
int byteNumber = 0;
%}
any [a-f0-9][a-f0-9]
%%

{any}	{byteNumber++;}
68{any}{any}{any}{any}c3	{printf("WARNING! Tricky Jump: byte number: %d\n", byteNumber);printf("%s\n", yytext); byteNumber+=6;}		

%%


