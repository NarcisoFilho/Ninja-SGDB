#ifndef __COMMANDS_HPP
#define __COMMANDS_HPP

#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

#include "definitions.hpp"

#include "CITY.hpp"
#include "COUNTRY.hpp"
#include "utils.hpp"
#include "keys_list.hpp"


template <class Entity>
string decode_table_file_name(){
    string table_file_name;

    if( typeid(Entity) == typeid(City) )
        table_file_name = CITIES_T;
    else if( typeid(Entity) == typeid(Country) )
        table_file_name = COUNTRIES_T;
    
    return table_file_name;
}

template <class Entity>
string decode_deleted_registers_file_name(){
    string deleted_registers_file_name;

    if( typeid(Entity) == typeid(City) )
        deleted_registers_file_name = DELETED_CITIES;
    else if( typeid(Entity) == typeid(Country) )
        deleted_registers_file_name = DELETED_COUNTRIES;
    
    return deleted_registers_file_name;
}

template <class Entity>
int encode_key_name( string key_str ){
    int key_code = -1;
    int qtd_keys;
    // string **keys_array;
    // string keys_array[5];
    
    if( typeid(Entity) == typeid(City) ){
        qtd_keys = QTD_KEYS_CC;
        for( int i = 0 ; i < qtd_keys ; i++ ){

            if( is_in( my_toupper( key_str ) , KEYS_NAMES_CITY[ i ] ) )
            // for( int j = 0 ; j < 5 ; j++ ){
                // if( my_toupper( key_str ) == KEYS_NAMES_CITY[ i ][ j ] )
                    key_code = i;
                // cout << "@key_str = " << key_str << "  ==  KEYS_NAMES_CITY [ i ][ j ] = " << KEYS_NAMES_CITY[ i ][ j ]  << " ? " << boolalpha << ( my_toupper( key_str ) == KEYS_NAMES_CITY[ i ][ j ] ) << endl;
                // cout << "@key_str = " << key_str << "  in  KEYS_NAMES_CITY[" << i << "]  ?  " << boolalpha << (bool)( my_toupper( is_in( my_toupper( key_str ) , KEYS_NAMES_CITY[ i ] ) ) ) << endl;
        }
    

    }else if( typeid(Entity) == typeid(Country) ){
        qtd_keys = QTD_KEYS_COUNTRY;
        for( int i = 0 ; i < qtd_keys ; i++ )
            // if( is_in( my_toupper( key_str ) , KEYS_NAMES_COUNTRY[ i ] ) )
            for( int j = 0 ; j < 5 ; j++ )
                if( my_toupper( key_str ) == KEYS_NAMES_CITY[ i ][ j ] )
                    key_code = i;
    }
    
    // if( typeid(Entity) == typeid(City) ){
    //     keys_array = (string**)KEYS_NAMES_CITY;
    //     qtd_keys = QTD_KEYS_CC;
    // }else if( typeid(Entity) == typeid(Country) ){
    //     keys_array = (string**)KEYS_NAMES_COUNTRY;
    //     qtd_keys = QTD_KEYS_COUNTRY;
    // }
    
    // for( int i = 0 ; i < qtd_keys ; i++ )
    //     if( is_in( my_toupper( key_str ) , (string[5])( keys_array ) , qtd_keys ) )
    //         key_code = i;
    // cout << "##key_str = " << key_code << endl;
    return key_code;
}





template<class Entity>
int determine_next_id(){
    string table_file_name , deleted_registers_file_name;
    ifstream table;
    fstream deleted_registers_table; 
    Entity last_register;
    int id_deleted;
    
    table_file_name = decode_table_file_name<Entity>();
    deleted_registers_file_name = decode_deleted_registers_file_name<Entity>();

    deleted_registers_table.open( deleted_registers_file_name , ios::in | ios::out | ios::binary );
    // Deleteds file empty
    if( deleted_registers_table.is_open() )
        deleted_registers_table.peek();

    if( !deleted_registers_table.is_open() || deleted_registers_table.eof() ){
        // Get Last Register
        table.open( table_file_name , F_IN );
        
        if( table.is_open() )
            table.peek();
        if( !table.is_open() || table.eof()){
            if( table.is_open() )
                table.close();
            return 0;
        }else{
            table.seekg( - sizeof(Entity) , ios::end );
            table.read( (char*)&last_register , sizeof(Entity) );
            table.close();
            last_register.id++;
            return last_register.id;
        }
    }else{  // Deleted file not empty
        fs::path p = fs::current_path()/deleted_registers_file_name;
        uintmax_t size_del_file = fs::file_size( p );  

        deleted_registers_table.seekg( - sizeof(int) , ios::end );
        deleted_registers_table.read( (char*)&id_deleted , sizeof(int) );
        deleted_registers_table.close();


        fs::resize_file( p , size_del_file - sizeof(int) );

        return id_deleted;
    }

}


template<class Entity>
int add_register( Entity *entity ){
    ofstream table;     
    if( typeid(Entity) == typeid(City) )
        table.open( CITIES_T , F_OUT_APP ); 
    else if( typeid(Entity) == typeid(Country) )
        table.open( COUNTRIES_T , F_OUT_APP ); 
    
    
    if( table.is_open() ){
        // Defining register id
        entity->id = determine_next_id<Entity>();

        // Pass data from variable to table file
        table.write( (char*)entity , sizeof(Entity) );

        // Close table
        table.close();
        return 1;
    }else{
        return 0;
    }
}

void delete_database(){
    char confirmation = 'n';

    cout << "This command will DELETE ALL THE DATA! Are you sure(y/n)?   " << endl;
    cin >>  confirmation;
    if( toupper( confirmation ) == 'Y' ) {
        remove( CITIES_T );
        remove( COUNTRIES_T );
        
        ofstream dci( DELETED_CITIES , ios::trunc | ios::binary );
        ofstream dco( DELETED_COUNTRIES , ios::trunc | ios::binary );
        dci.close();
        dco.close();
        
        cout << "____Data base deleted Succesfully___" << endl;
    }else{
        cout << "___Operation Canceled___" << endl;
    }

}

#endif //__COMMANDS_HPP