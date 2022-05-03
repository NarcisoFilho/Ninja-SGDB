#ifndef __KEYS_LIST_HPP
#define __KEYS_LIST_HPP


#include <iostream>
using namespace std;

#include "definitions.hpp"

string KEYS_NAMES_CITY[QTD_KEYS_CC][5] = {
    {"ID" , "COD" , "CODE" , "INDENTIFIER" , "n"},    
    {"NAME" , "NOME" , "CITY NAME" , "CIDADE" , "CITY"},    
    {"POP" , "POPULATION" , "POPULACAO" , "POPULAT" , "n"},    
    {"TYPE" , "TIPO" , "CLASS" , "CLASSE" , "n"},    
    {"LAT" , "LATITUDE" , "n" , "n" , "n" },    
    {"LNG" , "LONGITUDE" , "n" , "n" , "n" },   
    {"COUNTRY" , "COUNTRY_CODE" , "PAIS" , "CODIGO DO PAIS" , "COUNTRY NAME" },    
    {"ISO2" , "ALPHA2" , "ALPHA-2" , "n" , "n" },    
    {"ISO3" , "ALPHA3" , "ALPHA-3" , "n" , "n" },  
    {"REGION" , "CONTINENTE" , "n" , "n" , "n" }    
};
string KEYS_NAMES_COUNTRY[QTD_KEYS_COUNTRY][5] = {
    {"ID" , "COD" , "CODE" , "INDENTIFIER" , "n"},    
    {"NAME" , "NOME" , "COUNTRY NAME" , "NOME DO PAIS" , "n"},    
    {"ISO2" , "ALPHA2" , "ALPHA-2" , "n" , "n" },    
    {"ISO3" , "ALPHA3" , "ALPHA-3" , "n" , "n" },    
    {"REGION" , "CONTINENTE" , "n" , "n" , "n" }    
};


#endif //__KEYS_LIST_HPP