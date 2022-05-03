#ifndef __PRINT_DATA_HPP
#define __PRINT_DATA_HPP

#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

#include "definitions.hpp"
#include "print_information.hpp"

#include "CITY.hpp"
#include "COUNTRY.hpp"

void print_full_header();

template<class Entity>
void print_table_sort_tree( ifstream& sort_tree ){
    ifstream table;
    Entity *register_element = new Entity;
    bool flag_ccT = false;
    int *id_register = new int;
    
    if( typeid(Entity) == typeid(City) ){
        table.open( CITIES_T , F_IN ); 
        flag_ccT = true;
    }else if( typeid(Entity) == typeid(Country) )
        table.open( COUNTRIES_T , F_IN );
    

    if( table.is_open() ){
        if( !flag_ccT )
            Entity::print_header();
        else 
            print_full_header();

        sort_tree.seekg(0);
        
        sort_tree.read( (char*)id_register , sizeof(int) );
        while( !sort_tree.eof() ){
            // Random Access to table file
            table.seekg( *id_register * sizeof(Entity) );
            table.read( (char*)register_element , sizeof(Entity) );

            if( !flag_ccT )
                cout << *register_element;
            else
                print_full_city( *register_element );
        
            sort_tree.read( (char*)id_register , sizeof(int) );
        }


        // Close table
        table.close();
    }else{
        if( !table.eof() ){
            cout << tab << "___Table EMPTY___" << endl;
            table.close();
        }

    }

    delete register_element;
    delete id_register;
}

template<class Entity>
int print_table(){
    ifstream table;
    Entity entity;
    
    if( typeid(Entity) == typeid(City) )
        table.open( CITIES_T , F_IN ); 
    else if( typeid(Entity) == typeid(Country) )
        table.open( COUNTRIES_T , F_IN );
    

    if( table.is_open() &&  !table.eof() ){
        Entity::print_header();
        
        while( !table.eof() ){
            table.read( (char*)&entity , sizeof(Entity) );    // Pass data from file to variable
            if( table.rdstate() == ios::goodbit )
                cout << entity;   // Print data
        }


        // Close table
        table.close();
        return 1;
    }else{
        if( !table.eof() ){
            cout << tab << "___Table EMPTY___" << endl;
            table.close();
        }

        return 0;
    }
}

void print_full_header(){
    cout << tab << ">>CITIES WITH COUNTRIES TABLE" << endl;

    cout << tab << setw(PD_CITY_CODE_COL_WIDTH) << "ID";
    cout << " | " << setw(PD_NAME_COL_WIDTH) << "NAME";
    cout << " | " << setw(PD_POP_COL_WIDTH) << "POPULATION";
    cout << " | " << setw(PD_TYPE_COL_WIDTH) << "TYPE";
    cout << " | " << setw(PD_LAT_COL_WIDTH) << "LAT";
    cout << " | " << setw(PD_LNG_COL_WIDTH) << "LNG";
    cout << " | " << setw(PD_NAME_COL_WIDTH) << "COUNTRY";
    cout << " | " << setw(PD_ALPHA2_COL_WIDTH) << "ISO2";
    cout << " | " << setw(PD_ALPHA3_COL_WIDTH) << "ISO3";
    cout << " | " << setw(PD_REGION_COL_WIDTH) << "REGION" << endl;
}

void print_full_city2( City city , Country country = COUNTRY_NULL ){
    cout << tab << setw(PD_CITY_CODE_COL_WIDTH) << city.id;
    cout << " | " << setw(PD_NAME_COL_WIDTH) << city.name;
    cout << " | " << setw(PD_POP_COL_WIDTH) << city.population;
    cout << " | " << setw(PD_TYPE_COL_WIDTH) << city.type;
    cout << " | " << setw(PD_LAT_COL_WIDTH) << city.lat;
    cout << " | " << setw(PD_LNG_COL_WIDTH) << city.lng;
    cout << " | " << setw(PD_NAME_COL_WIDTH) << country.name;
    cout << " | " << setw(PD_ALPHA2_COL_WIDTH) << country.alpha2;
    cout << " | " << setw(PD_ALPHA3_COL_WIDTH) << country.alpha3;
    cout << " | " << setw(PD_REGION_COL_WIDTH) << country.region << endl;
}

void print_full_city( Country country ){
}

void print_full_city( City city ){
    ifstream countriesT( COUNTRIES_T , F_IN );
    Country *country = new Country;

    if ( !countriesT.is_open() ){
        *country = COUNTRY_NULL;
    }else{
        countriesT.seekg( city.country_cod * sizeof( Country ) );
        countriesT.read( (char*)country , sizeof(Country) );
        countriesT.close();
    }

    cout << tab << setw(PD_CITY_CODE_COL_WIDTH) << city.id;
    cout << " | " << setw(PD_NAME_COL_WIDTH) << city.name;
    cout << " | " << setw(PD_POP_COL_WIDTH) << city.population;
    cout << " | " << setw(PD_TYPE_COL_WIDTH) << city.type;
    cout << " | " << setw(PD_LAT_COL_WIDTH) << city.lat;
    cout << " | " << setw(PD_LNG_COL_WIDTH) << city.lng;
    cout << " | " << setw(PD_NAME_COL_WIDTH) << country->name;
    cout << " | " << setw(PD_ALPHA2_COL_WIDTH) << country->alpha2;
    cout << " | " << setw(PD_ALPHA3_COL_WIDTH) << country->alpha3;
    cout << " | " << setw(PD_REGION_COL_WIDTH) << country->region << endl;

    delete country;
}


int print_full_table(){
    ifstream citiesT( CITIES_T , F_IN ); 
    ifstream countriesT( COUNTRIES_T , F_IN );
    City city;
    Country country;
    
    if( citiesT.is_open() )
        citiesT.peek();

    if( citiesT.is_open() && !citiesT.eof() ){
        print_full_header();
        
        while( !citiesT.eof() ){
            citiesT.read( (char*)&city , sizeof(City) );    // Pass data from file to variable
            if( citiesT.rdstate() == ios::goodbit ){
                countriesT.seekg( city.country_cod * sizeof(Country) , ios::beg );
                countriesT.read( (char*)&country , sizeof(Country) );
                if( countriesT.good() )
                    print_full_city2( city , country );
                    // print_full_city( city );
                else
                    print_full_city2( city );
            }
                
        }


        // Close cities table
        citiesT.close();
        return 1;
    }else{
        if( !citiesT.eof() ){
            print_table_empty();
            citiesT.close();
        }

        return 0;
    }
}


void print_sort_tree( string name ){
    ifstream sort_tree( name , ios::binary );
    int *index = new int;
    string folder_name = TABLE_FOLDER;

    if( sort_tree.is_open() ){
        sort_tree.clear();
        sort_tree.seekg(0);
        sort_tree.peek();

        cout << tab << "Inverse File: " << name.substr( folder_name.length() + 1 ) << endl;
        sort_tree.read( (char*)index , sizeof( int ) );
        while( !sort_tree.eof() ){
            cout << tab(2) << *index << endl;
            sort_tree.read( (char*)index , sizeof( int ) );
        }
    }else{
        printError( Error::ERROR_ACCESS_SORT_TREE );
    }

    delete index;
}

#endif //__PRINT_DATA_HPP