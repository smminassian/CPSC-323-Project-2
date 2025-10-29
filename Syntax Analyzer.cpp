/*One possible output would be as follows:
.... more....
Token: Identifier Lexeme: a
<Statement> -> <Assign>
<Assign> -> <Identifier> = <Expression> ;
Token: Operator Lexeme: =
Token: Identifier Lexeme: b
<Expression> -> <Term> <Expression Prime>
<Term> -> <Factor> <Term Prime>
<Factor> -> <Identifier>
Token: Operator Lexeme: +
<Term Prime> -> 
<Expression Prime> -> + <Term> <Expression Prime>
Token: Identifier Lexeme: c
<Term> -> <Factor> <Term Prime>
<Factor> -> <Identifier>
Token: Separator Lexeme: ;
<Term Prime> -> 
<Expression Prime> -> 
.... more.....
This is the Rat25f production
*/




