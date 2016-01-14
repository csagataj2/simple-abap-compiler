// Generated by Bisonc++ V4.09.02 on Mon, 11 Jan 2016 01:06:14 +0100

#ifndef Parser_h_included
#define Parser_h_included

// $insert baseclass
#include "Parserbase.h"
#include "FlexLexer.h"
#include <cstdlib>

#undef Parser
class Parser: public ParserBase
{
        
    public:
        Parser(std::istream & in) : lexer(&in, &std::cerr) {}
        int parse();

    private:
        yyFlexLexer lexer;
        std::map<std::string, VariableData> symbolTable;
        
        void error(char const *msg);    // called on (syntax) errors
        int lex();                      // returns the next token from the lexical scanner. 
        void print();					//use, e.g., d_token, d_loc

    	// support functions for parse():
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
        void print__();
        void exceptionHandler__(std::exception const &exc);
};


#endif
