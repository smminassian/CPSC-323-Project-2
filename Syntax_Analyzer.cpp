/* R1. <Rat25F> ::= <Opt Function Definitions> # <Opt Declaration List> <Statement List> 
R2. <Opt Function Definitions> ::= <Function Definitions> | <Empty>
R3. <Function Definitions> ::= <Function> | <Function> <Function Definitions>
R4. <Function> ::= function <Identifier> ( <Opt Parameter List> ) <Opt Declaration List> <Body>
R5. <Opt Parameter List> ::= <Parameter List> | <Empty>
R6. <Parameter List> ::= <Parameter> | <Parameter> , <Parameter List>
R7. <Parameter> ::= <IDs > <Qualifier>
R8. <Qualifier> ::= integer | boolean | real
R9. <Body> ::= { < Statement List> }
R10. <Opt Declaration List> ::= <Declaration List> | <Empty>
R11. <Declaration List> := <Declaration> ; | <Declaration> ; <Declaration List>
R12. <Declaration> ::= <Qualifier > <IDs>
R13. <IDs> ::= <Identifier> | <Identifier>, <IDs>
R14. <Statement List> ::= <Statement> | <Statement> <Statement List>
R15. <Statement> ::= <Compound> | <Assign> | <If> | <Return> | <Print> | <Scan> | <While>
R16. <Compound> ::= { <Statement List> }
R17. <Assign> ::= <Identifier> = <Expression> ;
R18. <If> ::= if ( <Condition> ) <Statement> fi |
              else if ( <Condition> ) <Statement> else <Statement> fi
R19. <Return> ::= return return Prime ; 
     <Return Prime> ::= <Expression> | ε
R21. <Print> ::= put ( <Expression>);
R21. <Scan> ::= get ( <IDs> );
R22. <While> ::= while ( <Condition> ) <Statement>
R23. <Condition> ::= <Expression> <Relop> <Expression>
R24. <Relop> ::= == | != | > | < | <= | =>
R25. <Expression> ::= <Term> | Term + Term ExpressionPrime | Term - Term ExpressionPrime
     <ExpressionPrime> ::= + <Term> <ExpressionPrime> | - <Term> <ExpressionPrime> | ε
R26. <Term> ::= <Factor> * <Factor> TermPrime | <Factor> / <Factor> TermPrime | <Factor>
R26. <TermPrime> ::= * <Factor> <TermPrime> | / <Factor> <TermPrime> | ε
R27. <Factor> ::= - <Primary> | <Primary>
R28. <Primary> ::= <Identifier> | <Integer> | <Identifier> ( <IDs> ) | ( <Expression> ) | <Real> | true | false
R29. <Empty> ::= ε
*/


#include "Lexical_Analyzer.h"
#include <iostream>
using namespace std;

Token globalToken; 
int indexPos = 0;

void NextToken()
{
    if (indexPos < globalToken.lexeme.size())
    {
        cout << "Next Token: " << globalToken.token[indexPos] << " Lexeme: " << globalToken.lexeme[indexPos] << endl;
        indexPos++;
    }
    else
    {
        cout << "End of tokens reached." << endl;
    }
}

void match(string expectedLexeme)
{
    if (indexPos < globalToken.lexeme.size())
    {
        if (globalToken.lexeme[indexPos] == expectedLexeme)
        {
            cout << "Matched Token: " << globalToken.token[indexPos] << " Lexeme: " << globalToken.lexeme[indexPos] << endl;
            indexPos++;
        }
        else
        {
            cerr << "Syntax Error: Expected token " << expectedLexeme << " but found " << globalToken.token[indexPos] << " Lexeme: " << globalToken.lexeme[indexPos] << endl;
            exit(1);
        }
    }
    else
    {
        cerr << "Syntax Error: No more tokens available to match." << endl;
        exit(1);
    }
}

int main(){
     ifstream myFile("Rat25f.txt");
     if(!myFile){
         cerr << "Error opening file!" << endl;
         return 1;
     }

     globalToken = lexer(myFile);
     
     cout << "Lexical Analysis Complete. Tokens and Lexemes will be printed" << endl;
     while(indexPos < globalToken.lexeme.size()){
         NextToken();
     }

     //Parsing stuff goes here 

     myFile.close();
     return 0;
}