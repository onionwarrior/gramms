{%

%}
%token DIGIT DELIMITER

%left '+' '-'
%left '*' '/'
%left '^'
%left UMINUS

%union
{
	Polynomial poly;
}

%%
main: | main expr {first = 0; fprintf(yyout, "\n"); }
expr: | polynomial DELIMITER { PrintPoly($<mval>1, yyout); }

polynomial: Poly 
			| polynomial '+' polynomial 
				{ $<mval>$ = AddPoly($<mval>1, $<mval>3); }
			| polynomial '-' polynomial
				{ $<mval>$ = SubPoly($<mval>1, $<mval>3); }
			| polynomial '*' polynomial
				{ $<mval>$ = MulPoly($<mval>1, $<mval>3); }
			| '-' polynomial %prec UMINUS
				{ $<mval>$ = SubPoly(NULL, $<mval>2); }
			| '(' polynomial ')'
				{ $<mval>$ = $<mval>2; }
			| polynomial '/' polynomial
				{ $<mval>$ = DevPoly($<mval>1, $<mval>3);}
			| polynomial '^' number
			    { $<mval>$ = InvolutePoly($<mval>1, $<ival>3);}


Poly:  |number
			{ $<mval>$ = NewPoly(NULL, $<ival>1, 0); }
		| number '^' number 
				{ 
					if ($<ival>3 == 0) 
						$<mval>$ = NewPoly(NULL, 1, 0);
					else 
					{
						int ival = $<ival>1;
						for (int i=1; i<$<ival>3; i++)
							ival = ival * $<ival>1;
						$<mval>$ = NewPoly(NULL, ival, 0);
					}
				}
		 | 'x'
			{ $<mval>$ = NewPoly(NULL, 1, 1); }
		 | 'x' '^' number
			{ $<mval>$ = NewPoly(NULL, 1, $<ival>3); }
		 | number 'x' '^' number  
			{ $<mval>$ = NewPoly(NULL, $<ival>1, $<ival>4); }
		 | number 'x'
			{ $<mval>$ = NewPoly(NULL, $<ival>1, 1); }

number: DIGIT { $<ival>$ = $<cval>1 - '0'; }
	  | number DIGIT { $<ival>$ = 10 * $<ival>1 + ($<ival>2 - '0'); }
