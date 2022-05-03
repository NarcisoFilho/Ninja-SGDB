#ifndef __PARSER_INVICATION_HPP
#define __PARSER_INVICATION_HPP

#include "print_information.hpp"
#include "print_data.hpp"
#include "CITY.hpp"
#include "COUNTRY.hpp"
#include "commands.hpp"
#include "encode_command.hpp"
#include "keys_list.hpp"
#include "sort_functions.hpp"

int parser_ADDCITY( string *args , int qtd_args ){
    City city;

    // Pass data to variable city
    args[1].copy( city.name , args[1].length() , 0 );   // name
    city.name[ args[1].length() ] = '\0';

    city.population = stoi( args[2] ); // population
    
    args[3].copy( city.type , args[3].length() , 0 ); // type
    city.type[ args[3].length() ] = '\0';

    city.lat = stoi( args[4] ); // lat
    city.lng = stoi( args[5] ); // lng
    city.country_cod = stoi( args[6] ); // country_cod

    // Write city in the table
    add_register( &city );

    return 0;
}

int parser_ADDCOUNTRY( string *args , int qtd_args ){
    Country country;

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

    return 0;
}

#include <filesystem>
namespace fs = std::filesystem;

int parser_ADDFILE( string *args , int qtd_args ){
    ifstream registers_file( args[ 2 ] , F_IN );
    string input_line;
    string *atributes = new string[4 * QTD_KEYS_CITY];
    int qtd_atributes;
    int *col_atributes = new int[4 * QTD_KEYS_CITY];
cout << args[2] << endl;
cout << fs::current_path() << endl;
    for( int i = 0 ; i < 4 * QTD_KEYS_CITY ; i++ )
        col_atributes[ i ] = -1;
    
    if( registers_file.is_open() ){
        getline( registers_file , input_line );
        separate_args_from_input_line( input_line , atributes , qtd_atributes , ',' , true );
        cout << input_line << endl;
        
        for( int i = 0 ; i < qtd_atributes ; i++ ){
            cout << atributes[ i ] << endl;
            for( int j = 0 ; j < QTD_KEYS_CITY ; j++ ){
                if( is_in( my_toupper(atributes[ i ]) , KEYS_NAMES_CITY[ j ] ) )
                    col_atributes[ i ] = j;
            }
        }

        for( int t = 0  ; t < qtd_atributes ; t++ )
            cout << "Header Column " << t << " : " << atributes[ t ] << "    -> " << col_atributes[ t ] << endl;
    }else{
        printError( Error::ERROR_REGISTERS_FILE_OPENING );
    }

    return 0;
}

int parser_DELCITY( string *args , int qtd_args ){

    return 0;
}

int parser_DELCOUNTRY( string *args , int qtd_args ){

    return 0;
}

int parser_DELDATABASE( string *args , int qtd_args ){
    delete_database();
    return 0;
}

int parser_EXIT( string *args , int qtd_args ){
    return 1;
}

int parser_FILTER( string *args , int qtd_args ){
    return 0;
}

int parser_HELP( string *args , int qtd_args ){
    if( !qtd_args  )
        printHelp();   
    else if( qtd_args == 1 )
        printHelp( encode_command( args[1] ) );  

    return 0;
}


int parser_PRINTINVERSEFILE( string *args , int qtd_args ){
    if( qtd_args == 3){
        string sort_tree_name = "";
        bool descending = false;

        if( args[3] == "-a" || args[3] == "-ascending" )
            descending = false;
        else if( args[3] == "-d" || args[3] == "-descending" )
            descending = true;

        if( args[1] == "-citiesT" )
            sort_tree_name += get_name_sort_tree<City>( args[2] , descending );
        else if( args[1] == "-countriesT" )
            sort_tree_name += get_name_sort_tree<Country>( args[2] , descending );

        print_sort_tree( sort_tree_name );
    }else if( qtd_args == 1 ){
        print_sort_tree( args[1] );
    }else{
        printError( Error::ERROR_INVALID_NUMBER_OF_ARGUMENTS );
    }

    return 0;
}

int parser_PRINTTABLE( string *args , int qtd_args ){
    if( args[1] == "-citiesT" ){
        print_table<City>();
    }else if( args[1] == "-countriesT" ){
        print_table<Country>();
    }else if( args[1] == "-ccT" ){
        print_full_table();
    }else
        printError( Error::ERROR_TABLE_TYPE_INVALID );

    return 0;
}

int parser_SORT( string *args , int qtd_args ){
    int command_cod;
    bool flag_descending;

    if( args[1] == "-citiesT"  ||  args[1] == "-countryT" ){
        if( args[1] == "-citiesT" )
            command_cod = encode_key_name<City>( args[2] );
        else if( args[1] == "-countries" )
            command_cod = encode_key_name<Country>( args[2] );
        
        if( command_cod != -1 ){
            if( args[3] == "-ascending"  ||  args[3] == "-descending"
            || args[3] == "-a"  ||  args[3] == "-d" ){
                // cout << endlT << "table: " << args[1] << endl;
                // cout << endlT << "key: " << args[2] << endl;
                // cout << endlT << "order type: " << args[3] << endl;
                flag_descending = (args[3].substr(0 , 2) == "-d" ? true : false );
                if( args[1] == "-citiesT" )
                    sort<City>( args[2] , flag_descending );
                else if( args[1] == "-countries" )
                    sort<Country>( args[2] , flag_descending );
            }
            else
                printError( Error::ERROR_ORDER_TYPE_INVALID );
        }else
            printError( Error::ERROR_INVALID_KEY );

    }else
        printError( Error::ERROR_TABLE_TYPE_INVALID );
            
    return 0;
}

int parser_UNKNOWN_COMMAND( string *args , int qtd_args ){
    printError( Error::ERROR_UNKNOWN_COMMAND );
    return -1;
}


#endif //__PARSER_INVICATION_HPP