#ifndef __DEFINITIONS_HPP
#define __DEFINITIONS_HPP


/// Commands
enum class COMMAND{
    ADDCITY,
    ADDCOUNTRY,
    ADDFILE,
    DELCITY,
    DELCOUNTRY,
    DELDATABASE,
    EXIT,
    FILTER,
    HELP,
    PRINTTABLE,
    PRINTSORTETREE,
    SORT,
    UNKNOWN_COMMAND
};

// #define COMMAND_QTD_ARG_ADDCITY 6
// #define COMMAND_QTD_ARG_ADDCOUNTRY 4
// #define COMMAND_QTD_ARG_ADDFILE 2
// #define COMMAND_QTD_ARG_DELCITY 1
// #define COMMAND_QTD_ARG_DELCOUNTRY 1
// #define COMMAND_QTD_ARG_DELDATABASE 0
// #define COMMAND_QTD_ARG_EXIT 0
// #define COMMAND_QTD_ARG_FILTER_MIN 3
// #define COMMAND_QTD_ARG_HELP 0
// #define COMMAND_QTD_ARG_PRINTTABLE 1
// #define COMMAND_QTD_ARG_SORT 3

#define QTD_ARGS_PARSER_FUNCTIONS_MIN (int[]){\
    6, /*COMMAND_QTD_ARG_ADDCITY    */    \
    4, /*COMMAND_QTD_ARG_ADDCOUNTRY */    \
    2, /*COMMAND_QTD_ARG_ADDFILE    */    \
    1, /*COMMAND_QTD_ARG_DELCITY    */    \
    1, /*COMMAND_QTD_ARG_DELCOUNTRY */    \
    0, /*COMMAND_QTD_ARG_DELDATABASE*/    \
    0, /*COMMAND_QTD_ARG_EXIT       */    \
    3, /*COMMAND_QTD_ARG_FILTER_MIN */    \
    0, /*COMMAND_QTD_ARG_HELP       */    \
    1, /*COMMAND_QTD_ARG_PRINTSORTTREE */    \
    1, /*COMMAND_QTD_ARG_PRINTTABLE */    \
    3, /*COMMAND_QTD_ARG_SORT       */    \
} 
#define QTD_ARGS_PARSER_FUNCTIONS_MAX (int[]){\
    6, /*COMMAND_QTD_ARG_ADDCITY    */    \
    4, /*COMMAND_QTD_ARG_ADDCOUNTRY */    \
    2, /*COMMAND_QTD_ARG_ADDFILE    */    \
    1, /*COMMAND_QTD_ARG_DELCITY    */    \
    1, /*COMMAND_QTD_ARG_DELCOUNTRY */    \
    0, /*COMMAND_QTD_ARG_DELDATABASE*/    \
    0, /*COMMAND_QTD_ARG_EXIT       */    \
    40, /*COMMAND_QTD_ARG_FILTER_MIN */    \
    1, /*COMMAND_QTD_ARG_HELP       */    \
    3, /*COMMAND_QTD_ARG_PRINTSORTTREE */    \
    1, /*COMMAND_QTD_ARG_PRINTTABLE */    \
    3, /*COMMAND_QTD_ARG_SORT       */    \
} 

///Country
#define COUNTRY_NULL (Country( (int)-1 , "?" , "?" , "?", "?" ) )

/// Errors Codes
enum class Error{
    ERROR_MANY_ARGUMENTS,
    ERROR_FEW_ARGUMENTS,
    ERROR_UNKNOWN_COMMAND,
    ERROR_TABLE_TYPE_INVALID,
    ERROR_INVALID_KEY,
    ERROR_ORDER_TYPE_INVALID,
    ERROR_TABLE_FILE_OPENING,
    ERROR_REGISTERS_FILE_OPENING,
    ERROR_SORT_TREE_FILE_CREATING,
    ERROR_INVALID_NUMBER_OF_ARGUMENTS,
    ERROR_ACCESS_SORT_TREE
};

/// Files
#define TABLE_FOLDER "Tables"
#define CITIES_T "Tables/CitiesT.bin"
#define COUNTRIES_T "Tables/CountriesT.bin"
#define DELETED_CITIES "Tables/DeletedCities.bin"
#define DELETED_COUNTRIES "Tables/DeletedCountries.bin"
#define F_OUT_APP ios::app | ios::binary | ios::out
#define F_IN_OUT_ATE ios::in | ios::out | ios::ate | ios::binary
#define F_IN ios::in | ios::binary

/// Table Keys
#define QTD_KEYS_CITY 7
#define QTD_KEYS_CC 10
#define QTD_KEYS_COUNTRY 5
// #define KEYS_NAMES_CITY (string[QTD_KEYS_CC][5]){\
//     {"ID" , "COD" , "CODE" , "INDENTIFIER" , "n"},    \
//     {"NAME" , "NOME" , "CITY NAME" , "NOME DA CIDADE" , "n"},    \
//     {"POP" , "POPULATION" , "POPULACAO" , "POPULAT" , "n"},    \
//     {"TYPE" , "TIPO" , "CLASS" , "CLASSE" , "n"},    \
//     {"LAT" , "LATITUDE" , "n" , "n" , "n" },    \
//     {"LNG" , "LONGITUDE" , "n" , "n" , "n" },    \
//     {"COUNTRY" , "COUNTRY_CODE" , "PAIS" , "CODIGO DO PAIS" , "COUNTRY NAME" },    \
//     {"ISO2" , "ALPHA2" , "ALPHA-2" , "n" , "n" },    \
//     {"ISO3" , "ALPHA3" , "ALPHA-3" , "n" , "n" },    \
//     {"REGION" , "CONTINENTE" , "n" , "n" , "n" }    \
// }
// #define KEYS_NAMES_COUNTRY (string[QTD_KEYS_COUNTRY][5]){\
//     {"ID" , "COD" , "CODE" , "INDENTIFIER" , "n"},    \
//     {"NAME" , "NOME" , "COUNTRY NAME" , "NOME DO PAIS" , "n"},    \
//     {"ISO2" , "ALPHA2" , "ALPHA-2" , "n" , "n" },    \
//     {"ISO3" , "ALPHA3" , "ALPHA-3" , "n" , "n" },    \
//     {"REGION" , "CONTINENTE" , "n" , "n" , "n" }    \
// }

/// MetaData
#define CITY_FIELDS_QTD 8
#define COUNTRY_FIELDS_QTD 7
#define CITY_PRINTABLE_FIELDS_QTD ( CITY_FIELDS_QTD - 1 )
#define COUNTRY_PRINTABLE_FIELDS_QTD ( COUNTRY_FIELDS_QTD - 1 )
#define CC_PRINTABLE_FIELDS_QTD ( CITY_PRINTABLE_FIELDS_QTD + COUNTRY_PRINTABLE_FIELDS_QTD - 1 )

/// Print Data
    // City
    #define PD_NAME_COL_WIDTH 30
    #define PD_POP_COL_WIDTH 17
    #define PD_TYPE_COL_WIDTH 20
    #define PD_LAT_COL_WIDTH 17
    #define PD_LNG_COL_WIDTH 17
    #define PD_COUNTRY_CODE_COL_WIDTH 10
    #define PD_CITY_CODE_COL_WIDTH 10

    //Country
    #define PD_NAME_COL_WIDTH 30
    #define PD_ALPHA2_COL_WIDTH 6
    #define PD_ALPHA3_COL_WIDTH 7
    #define PD_REGION_COL_WIDTH 12
    #define PD_COUNTRY_CODE_COL_WIDTH 10


/// System
#define QTD_COMMANDS 11


/// System Help
#define QTD_HELP_BASIC_MSGS QTD_COMMANDS

#endif //__DEFINITIONS_HPP