#ifndef __PRINT_DATA_HPP
#define __PRINT_DATA_HPP

#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

#include "definitions.hpp"

#include "CITY.hpp"
#include "COUNTRY.hpp"

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
    cout << ">>CITIES WITH COUNTRIES TABLE" << endl;

    cout << setw(PD_CITY_CODE_COL_WIDTH) << "ID";
    cout << " | " << setw(PD_NAME_COL_WIDTH) << "NAME";
    cout << " | " << setw(PD_POP_COL_WIDTH) << "POPULATION";
    cout << " | " << setw(PD_TYPE_COL_WIDTH) << "TYPE";
    cout << " | " << setw(PD_NAME_COL_WIDTH) << "COUNTRY";
    cout << " | " << setw(PD_ALPHA2_COL_WIDTH) << "ISO2";
    cout << " | " << setw(PD_REGION_COL_WIDTH) << "ISO3";
    cout << " | " << setw(PD_LNG_COL_WIDTH) << "REGION";
    cout << " | " << setw(PD_LAT_COL_WIDTH) << "LAT";
    cout << " | " << setw(PD_LNG_COL_WIDTH) << "LNG" << endl;
}

void print_full_city( City city , Country country = COUNTRY_NULL ){
    cout << setw(PD_CITY_CODE_COL_WIDTH) << city.city_cod;
    cout << " | " << setw(PD_NAME_COL_WIDTH) << city.name;
    cout << " | " << setw(PD_POP_COL_WIDTH) << city.population;
    cout << " | " << setw(PD_TYPE_COL_WIDTH) << city.type;
    cout << " | " << setw(PD_NAME_COL_WIDTH) << country.name;
    cout << " | " << setw(PD_ALPHA2_COL_WIDTH) << country.alpha2;
    cout << " | " << setw(PD_REGION_COL_WIDTH) << country.alpha3;
    cout << " | " << setw(PD_LNG_COL_WIDTH) << country.region;
    cout << " | " << setw(PD_LAT_COL_WIDTH) << city.lat;
    cout << " | " << setw(PD_LNG_COL_WIDTH) << city.lng << endl;
}


int print_full_table(){
    ifstream citiesT( CITIES_T , F_IN ); 
    ifstream countriesT( COUNTRIES_T , F_IN );
    City city;
    Country country;
    
    if( citiesT.is_open() &&  !citiesT.eof() ){
        print_full_header();
        
        while( !citiesT.eof() ){
            citiesT.read( (char*)&city , sizeof(City) );    // Pass data from file to variable
            if( citiesT.rdstate() == ios::goodbit ){
                countriesT.seekg( ios::beg + city.country_cod * sizeof(Country) );
                countriesT.read( (char*)&country , sizeof(Country) );
                if( countriesT.good() )
                    print_full_city( city , country );
                else
                    print_full_city( city );
            }
                
        }


        // Close cities table
        citiesT.close();
        return 1;
    }else{
        if( !citiesT.eof() ){
            cout << tab << "___Table EMPTY___" << endl;
            citiesT.close();
        }

        return 0;
    }
}

#endif //__PRINT_DATA_HPP