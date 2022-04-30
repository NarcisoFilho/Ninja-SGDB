#ifndef __COUNTRY_HPP_
#define __COUNTRY_HPP_

#include <iostream>
using namespace std;

class Country{
    public:
    int country_cod;        // PK
    char name[30];
    char alpha2[3];
    char alpha3[4];
    char region[30];

    public:
    Country( int,string,string,string,string );
    friend ostream& operator<<( ostream& , City );
    static void print_header();

};

Country::Country( int country_cod = 0, string name = "", string alpha2 = "", string alpha3 = "", string region = "" ){
    this->country_cod = country_cod;
    name.copy( this->name , name.length() ,0 );
    alpha2.copy( this->alpha2 , alpha2.length() ,0 );
    alpha3.copy( this->alpha3 , alpha3.length() ,0 );
    region.copy( this->region , region.length() ,0 );
}
void Country::print_header(){
    cout << ">>COUNTRIES TABLE" << endl;
    cout << setw(PD_NAME_COL_WIDTH) << "NAME";
    cout << " | " << setw(PD_ALPHA2_COL_WIDTH) << "ISO2";
    cout << " | " << setw(PD_REGION_COL_WIDTH) << "ISO3";
    cout << " | " << setw(PD_LNG_COL_WIDTH) << "REGION";
    cout << " | " << setw(PD_COUNTRY_CODE_COL_WIDTH) << "ID" << endl;
}


ostream& operator<<( ostream& stream , Country country ){
    stream << setw(PD_NAME_COL_WIDTH) << country.name;
    stream << " | " << setw(PD_ALPHA2_COL_WIDTH) << country.alpha2;
    stream << " | " << setw(PD_ALPHA3_COL_WIDTH) << country.alpha3;
    stream << " | " << setw(PD_REGION_COL_WIDTH) << country.region;
    stream << " | " << setw(PD_COUNTRY_CODE_COL_WIDTH) << country.country_cod << endl;

    return stream;
}


#endif      // __COUNTRY_HPP_