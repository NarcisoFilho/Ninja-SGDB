#ifndef __COMMANDS_HPP
#define __COMMANDS_HPP

#include <iostream>
#include <fstream>

using namespace std;

#include "definitions.hpp"

#include "CITY.hpp"
#include "COUNTRY.hpp"

template<class Entity>
int add_register( Entity *entity ){
    ofstream table; 
    
    if( typeid(entity) == typeid(City*) )
        table.open( CITIES_T , F_OUT_APP ); 
    else if( typeid(entity) == typeid(Country*) )
        table.open( COUNTRIES_T , F_OUT_APP ); 

    
    if( table.is_open() ){
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
        cout << "____Data base deleted Succesfully___" << endl;
    }else{
        cout << "___Operation Canceled___" << endl;
    }

}

#endif //__COMMANDS_HPP