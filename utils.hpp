#ifndef __UTILS_HPP
#define __UTILS_HPP

#include <iostream>
using namespace std;

#include "utils.hpp"
string my_toupper( string str ){
    string upper_str = "";

    for( int i = 0 ; i < str.length() ; i++ ){
        if( str[ i ] >= 'a' && str[ i ] <= 'z' )
            upper_str.append( 1 , str[ i ] - ('a' - 'A') );
        else
            upper_str.append( 1 , str[ i ] );
    }
    return upper_str;
}

template<class T>
bool is_in( T element , T *array , int array_size ){
    for( int i = 0 ; i < array_size ; i++ )
        if( array[ i ] = element )
            return true;
    
    return false;
}

bool is_in( string element , string array[5] ){
    for( int i = 0 ; i < 5 ; i++ )
        if( array[ i ] == element )
            return true;
    
    return false;
}

void separate_args_from_input_line( string input , string* args , int& qtd_args , const char separator, bool discard_double_quotes ){
    int end_field;
    input = input.substr( input.find_first_not_of(' ') );
    qtd_args = 0;
    int first_space , first_quote;

    // input.replace( input.begin() , input.end() , ',' , ' ' );
    for( int i = 0 ; i < input.length() ; i++ )
        if( input[i] == ',' ){
            input[i] = ' ';
        }


    while( input != "" ){
        // Remove the spaces from commando
        input = input.substr( input.find_first_not_of( ' ' ) );

        // Determine end of next argument
        if( discard_double_quotes ){
            if( input[ 0 ] == '\"' ){
                end_field =  input.substr( 1 ).find_first_of( '\"' ) + 1;
            }else{
                end_field =  input.find_first_of( ' ' ) - 1;
            } 
        }
        // end_field = 0;
        // while( input[ end_field ] != ' ' && end_field < input.length() ){
        //     if( input[ end_field ] == '\"' ){
        //         end_field++;
        //         end_field += input.substr( end_field , input.length() - end_field ).find_first_of( '\"' ) + 1;
        //     }else
        //         end_field = input.substr( end_field , input.length() - end_field ).find_first_of( ' ' );

        //     if( end_field >= input.length() )
        //         end_field = input.length();
        //     else if( input.substr( end_field , input.length() - end_field ).find_first_of( '\"' ) 
        //     < input.substr( end_field , input.length() - end_field ).find_first_of( ' ' ) ){
        //         end_field += input.substr( end_field , input.length() - end_field ).find_first_of( '\"' );
        //     }
        // } 
        
        if( end_field >= input.length() )
            end_field = input.length() - 1;

        // Assign it to args[]
        args[ qtd_args ] = "";
        args[ qtd_args ].append( input.substr( 0 , end_field + 1 ) );
        qtd_args++;

        // Remove previous argument from input
        if( end_field < input.length() )
            input = input.substr( end_field + 1);
        else
            input = "";

        // Remove double quotes from args[i]
        if( discard_double_quotes )
            args[qtd_args - 1].erase( remove( args[qtd_args-1].begin() , args[qtd_args-1].end() , '\"' ) , args[qtd_args-1].end() );
    }

    qtd_args--;
}

#endif //__UTILS_HPP