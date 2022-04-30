#ifndef __CITY_HPP_
#define __CITY_HPP_

#include <iostream>
#include "ParaManip.hpp"

class City{
    public:
    long int city_cod;  // PK
    char name[30];
    int country_cod;    // FK
    long int population;
    char type[15];
    float lat;
    float lng;

    public:
    friend ostream& operator<<( ostream& , City );
    static void print_header();
};

void City::print_header(){
    cout << ">>CITIES TABLE" << endl;
    cout << setw(PD_CITY_CODE_COL_WIDTH) << "ID";
    cout << " | " << setw(PD_NAME_COL_WIDTH) << "NAME";
    cout << " | " << setw(PD_POP_COL_WIDTH) << "POPULATION";
    cout << " | " << setw(PD_TYPE_COL_WIDTH) << "TYPE";
    cout << " | " << setw(PD_LAT_COL_WIDTH) << "LAT";
    cout << " | " << setw(PD_LNG_COL_WIDTH) << "LNG";
    cout << " | " << setw(PD_COUNTRY_CODE_COL_WIDTH) << "COUNTRY COD" << endl;  
}


ostream& operator<<( ostream& stream , City city ){
    stream << setw(PD_NAME_COL_WIDTH) << city.name;
    stream << " | " << setw(PD_POP_COL_WIDTH) << city.population;
    stream << " | " << setw(PD_TYPE_COL_WIDTH) << city.type;
    stream << " | " << setw(PD_LAT_COL_WIDTH) << city.lat;
    stream << " | " << setw(PD_LNG_COL_WIDTH) << city.lng;
    stream << " | " << setw(PD_COUNTRY_CODE_COL_WIDTH) << city.country_cod;
    stream << " | " << setw(PD_CITY_CODE_COL_WIDTH) << city.city_cod << endl;

    return stream;
}




#endif      // __CITY_HPP_