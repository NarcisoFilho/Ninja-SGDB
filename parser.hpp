#ifndef __PARSER_HPP
#define __PARSER_HPP

#include "print_information.hpp"
#include "CITY.hpp"
#include "COUNTRY.hpp"
#include "commands.hpp"
#include "parser_invocations.hpp"
#include <algorithm>

void interpreter_line_input( string , COMMAND& , string* , int& );
COMMAND encode_command( string );
int execute_line_input( COMMAND , string* , int );



void interpreter_line_input( string input , COMMAND& command , string* args , int& qtd_args ){
        input = input.substr( input.find_first_not_of(' ') );

        separate_args_from_input_line( input , args , qtd_args , ' ' , true );

        command = encode_command( args[0] );
}

int execute_line_input( COMMAND command , string *args , int qtd_args ){

    int (*parser_functions[])(string*,int) = {
        parser_ADDCITY , 
        parser_ADDCOUNTRY,
        parser_ADDFILE,
        parser_DELCITY,
        parser_DELCOUNTRY,
        parser_DELDATABASE,
        parser_EXIT,
        parser_FILTER,
        parser_HELP,
        parser_PRINTINVERSEFILE,
        parser_PRINTTABLE,
        parser_SORT,
        parser_UNKNOWN_COMMAND
    };

    if( qtd_args < QTD_ARGS_PARSER_FUNCTIONS_MIN[ static_cast<int>(command)] ){
        printError( Error::ERROR_FEW_ARGUMENTS );
        return 2;
    }else if( qtd_args > QTD_ARGS_PARSER_FUNCTIONS_MAX[ static_cast<int>(command)] ){
        printError( Error::ERROR_MANY_ARGUMENTS );
        return 3;
    }

    return parser_functions[ static_cast<int>(command) ]( args , qtd_args );
}
#endif //__PARSER_HPP