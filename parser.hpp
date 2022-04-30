#ifndef __PARSER_HPP
#define __PARSER_HPP

#include "print_information.hpp"
#include "CITY.hpp"
#include "COUNTRY.hpp"
#include "commands.hpp"


void interpreter_line_input( string , COMMAND& , string* , int& );
COMMAND encode_command( string );
int execute_line_input( COMMAND , string* , int );


void interpreter_line_input( string input , COMMAND& command , string* args , int& qtd_args ){
        int end_field;

        input = input.substr( input.find_first_not_of(' ') );
        qtd_args = 0;

        while( input != "" ){
            // Remove the spaces from commando
            input = input.substr( input.find_first_not_of( ' ' ) );

            // Determine end of next argument 
            end_field = input.find_first_of( ' ' );
            if( end_field >= input.length() )
                end_field = input.length();
            
            // Assign it to args[]
            args[ qtd_args ] = input.substr( 0 , end_field );
            qtd_args++;

            // Remove previous argument from input
            if( end_field < input.length() )
                input = input.substr( end_field + 1);
            else
                input = "";
        }

        qtd_args--;
        command = encode_command( args[0] );
}

COMMAND encode_command( string cmd_str ){
        if( cmd_str == "addcity" )
            return COMMAND::ADDCITY;
        if( cmd_str == "addcountry" )
            return COMMAND::ADDCOUNTRY;
        if( cmd_str == "addfile" )
            return COMMAND::ADDFILE;
        if( cmd_str == "delcity" )
            return COMMAND::DELCITY;
        if( cmd_str == "delcountry" )
            return COMMAND::DELCOUNTRY;
        if( cmd_str == "deldatabase" )
            return COMMAND::DELDATABASE;
        if( cmd_str == "exit" )
            return COMMAND::EXIT;
        if( cmd_str == "filter" )
            return COMMAND::FILTER;
        if( cmd_str == "help" )
            return COMMAND::HELP ;
        if( cmd_str == "printtable" )
            return COMMAND::PRINTTABLE;
        if( cmd_str == "sort" )
            return COMMAND::SORT;

        return COMMAND::UNKNOWN_COMMAND;
}


int execute_line_input( COMMAND command , string *args , int qtd_args ){
    // fstream citiesT("Tables/CitiesT" , ios::in | ios::out | ios::binary );
    // fstream countriesT("Tables/CountriesT" , ios::in | ios::out | ios::binary );
    fstream citiesT;
    fstream countriesT;
    City city;
    Country country;
    
    switch( command ){
        case COMMAND::ADDCITY:
            if( qtd_args == COMMAND_QTD_ARG_ADDCITY ){
                // Pass data to variable city
                args[1].copy( city.name , args[1].length() , 0 );   // name
                city.name[ args[1].length() ] = '\0';

                city.country_cod = stoi( args[2] ); // country_cod
                city.population = stoi( args[3] ); // population
                
                args[4].copy( city.type , args[4].length() , 0 ); // type
                city.type[ args[4].length() ] = '\0';

                city.lat = stoi( args[5] ); // lat
                city.lng = stoi( args[6] ); // lng

                // Write city in the table
                add_register( &city );
            }else if( qtd_args < COMMAND_QTD_ARG_ADDCITY )
                printError( Error::ERROR_FEW_ARGUMENTS );
            else if( qtd_args > COMMAND_QTD_ARG_ADDCITY )
                printError( Error::ERROR_MANY_ARGUMENTS );
            
            break;
        case COMMAND::ADDCOUNTRY :
            if( qtd_args == COMMAND_QTD_ARG_ADDCOUNTRY ){
                // Pass data to variable country
                args[1].copy( country.name , args[1].length() , 0 );   // name
                country.name[ args[1].length() ] = '\0';
                
                args[2].copy( country.alpha2 , args[2].length() , 0 ); // alpha2
                country.alpha2[ args[2].length() ] = '\0';
                
                args[3].copy( country.alpha3 , args[3].length() , 0 ); // alpha3
                country.alpha3[ args[3].length() ] = '\0';
                
                args[4].copy( country.region , args[4].length() , 0 ); // region
                country.region[ args[4].length() ] = '\0';

                // Write country in the table
                add_register( &country );
            }else if( qtd_args < COMMAND_QTD_ARG_ADDCOUNTRY )
                printError( Error::ERROR_FEW_ARGUMENTS );
            else if( qtd_args > COMMAND_QTD_ARG_ADDCOUNTRY )
                printError( Error::ERROR_MANY_ARGUMENTS );
            break;
        case COMMAND::ADDFILE :
            if( qtd_args == COMMAND_QTD_ARG_ADDFILE ){
                cout << endlT << "file_name: " << args[1] << endl;
                cout << endlT << "file_type: " << args[2] << endl;
            }else if( qtd_args < COMMAND_QTD_ARG_ADDFILE )
                printError( Error::ERROR_FEW_ARGUMENTS );
            else if( qtd_args > COMMAND_QTD_ARG_ADDFILE )
                printError( Error::ERROR_MANY_ARGUMENTS );
            
            break;
        case COMMAND::DELCITY :
            if( qtd_args == COMMAND_QTD_ARG_DELCITY ){
                cout << endlT << "file_name: " << args[1] << endl;
                cout << endlT << "file_type: " << args[2] << endl;
            }else if( qtd_args < COMMAND_QTD_ARG_DELCITY )
                printError( Error::ERROR_FEW_ARGUMENTS );
            else if( qtd_args > COMMAND_QTD_ARG_DELCITY )
                printError( Error::ERROR_MANY_ARGUMENTS );
            break;
        case COMMAND::DELCOUNTRY :
            if( qtd_args == COMMAND_QTD_ARG_DELCOUNTRY ){
                cout << endlT << "file_name: " << args[1] << endl;
                cout << endlT << "file_type: " << args[2] << endl;
            }else if( qtd_args < COMMAND_QTD_ARG_DELCOUNTRY )
                printError( Error::ERROR_FEW_ARGUMENTS );
            else if( qtd_args > COMMAND_QTD_ARG_DELCOUNTRY )
                printError( Error::ERROR_MANY_ARGUMENTS );
            
            break;
        case COMMAND::DELDATABASE :
            if( qtd_args == COMMAND_QTD_ARG_DELDATABASE )
                delete_database();
            else
                printError( Error::ERROR_MANY_ARGUMENTS );
            
            break;
        case COMMAND::EXIT :
            if( qtd_args == COMMAND_QTD_ARG_EXIT )
                return 1;
            else
                printError( Error::ERROR_MANY_ARGUMENTS );
            
            break;
        case COMMAND::FILTER :
            if( qtd_args >= COMMAND_QTD_ARG_FILTER_MIN ){
                cout << endlT << "file_name: " << args[1] << endl;
                cout << endlT << "key: " << args[2] << endl;
            }else if( qtd_args < COMMAND_QTD_ARG_FILTER_MIN )
                printError( Error::ERROR_FEW_ARGUMENTS );
            
            break;
        case COMMAND::HELP:
            if( qtd_args == COMMAND_QTD_ARG_HELP )
                printHelp();   
            else if( qtd_args == 1 )
                printHelp( encode_command( args[1] ) );   
            else
                printError( Error::ERROR_MANY_ARGUMENTS );
            
            break;
        case COMMAND::PRINTTABLE :
            if( qtd_args == COMMAND_QTD_ARG_PRINTTABLE ){
                if( args[1] == "-citiesT" ){
                    print_table<City>();
                }else if( args[1] == "-countriesT" ){
                    print_table<Country>();
                }else if( args[1] == "-ccT" ){
                    print_full_table();
                }else
                    printError( Error::ERROR_TABLE_TYPE_INVALID );

            }else if( qtd_args < COMMAND_QTD_ARG_PRINTTABLE)   
                printError( Error::ERROR_FEW_ARGUMENTS );
            else if( qtd_args > COMMAND_QTD_ARG_PRINTTABLE)   
                printError( Error::ERROR_MANY_ARGUMENTS );

            break;
        case COMMAND::SORT :           
            if( qtd_args == COMMAND_QTD_ARG_SORT ){
                if( args[1] == "-citiesT"  ||  args[1] == "-countryT" ){
                    if( args[2] == "-ascending"  ||  args[1] == "-descending"
                    || args[2] == "-a"  ||  args[1] == "-d" ){
                        cout << endlT << "table: " << args[1] << endl;
                        cout << endlT << "key: " << args[2] << endl;
                    }
                    else
                        printError( Error::ERROR_ORDER_TYPE_INVALID );
                }else
                    printError( Error::ERROR_TABLE_TYPE_INVALID );
                
            }else if( qtd_args < COMMAND_QTD_ARG_SORT )
                printError( Error::ERROR_FEW_ARGUMENTS );
            else if( qtd_args > COMMAND_QTD_ARG_SORT )
                printError( Error::ERROR_MANY_ARGUMENTS );
            
            break;
        case COMMAND::UNKNOWN_COMMAND :
            printError( Error::ERROR_UNKNOWN_COMMAND );
            return -1;
            
            break;
    }

    return 0;
}
#endif //__PARSER_HPP