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
    SORT,
    UNKNOWN_COMMAND
};

#define COMMAND_QTD_ARG_ADDCITY 6
#define COMMAND_QTD_ARG_ADDCOUNTRY 4
#define COMMAND_QTD_ARG_ADDFILE 2
#define COMMAND_QTD_ARG_DELCITY 1
#define COMMAND_QTD_ARG_DELCOUNTRY 1
#define COMMAND_QTD_ARG_DELDATABASE 0
#define COMMAND_QTD_ARG_EXIT 0
#define COMMAND_QTD_ARG_FILTER_MIN 3
#define COMMAND_QTD_ARG_HELP 0
#define COMMAND_QTD_ARG_PRINTTABLE 1
#define COMMAND_QTD_ARG_SORT 3

///Country
#define COUNTRY_NULL (Country( -1 , "UNKNOWN" , "-" , "-", "-" ) )

/// Errors Codes
enum class Error{
    ERROR_MANY_ARGUMENTS,
    ERROR_FEW_ARGUMENTS,
    ERROR_UNKNOWN_COMMAND,
    ERROR_TABLE_TYPE_INVALID,
    ERROR_ORDER_TYPE_INVALID
};

/// Files
#define CITIES_T "Tables/CitiesT.bin"
#define COUNTRIES_T "Tables/CountryT.bin"
#define F_OUT_APP ios::app | ios::binary
#define F_IN_OUT_ATE ios::in | ios::out | ios::ate | ios::binary
#define F_IN ios::in | ios::binary

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
    #define PD_TYPE_COL_WIDTH 12
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