
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>

using namespace std;

// #include "definitions.hpp"
// #include "ParaManip.hpp"

#include "print_data.hpp"
#include "print_information.hpp"

#include "parser.hpp"

// #include "City.hpp"
// #include "Country.hpp"

// #include "sort_functions.hpp"
// #include "filter_functions.hpp"


int main( int argc , char *argv[] ){
    string input;
    COMMAND command;
    string args[15];
    int qtd_args;
    bool flag_exit = false;
    int status_execution;

    if( argc == 1 ){
        printWelcome();

        while( !flag_exit ){
            do{
                getline( cin , input );
            }while( input == "" );

            interpreter_line_input( input , command , args , qtd_args );
            status_execution = execute_line_input( command , args , qtd_args );

            if( status_execution == 1 )
                flag_exit = true;            
        }

        printBye();
    }    
    
    return 0;
}




