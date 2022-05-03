#ifndef __SYSTEM_HELP_HPP
#define __SYSTEM_HELP_HPP

#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

#include "definitions.hpp"

string get_cmds_basic_help_msgs( int cod ){
    static string hbm[]{
        "Append one city register to the cities table",     //addcity
        "Append one country register to the countries table",   //addcountry
        "Append data to the DataBase from a file of cities or countries",   //addfile
        "Delete one city register from the cities table",     //delcity
        "Delete one country register from the countries table",   //delcountry
        "Delete all the DataBase. Take care!!",     //deldatabase
        "Stop the progrma and return to OS",   //exit
        "Filter one table based one or many conditions", //filter
        "Show this basic guide or more detailed information about one specific command",    //help
        "Print the content of one inversefile",   //printinversefile
        "Print the content of one table or one combination of tables",   //printtable
        "Sort one table with respect to one key and return the data sorted", //sort
    };
    return hbm[ cod ];
}

string get_cmds_use_help_msgs( int cod ){
    static string hum[]{
        "addcity [name] [country_cod] [population] [tipo] [lat] [lng]",     //addcity
        "addcountry [name] [alpha-2] [alpha-3] [region]",   //addcountry
        "addfile [file] [type]",   //addfile
        "delcity [parameter] [name or city-cod]",     //delcity
        "delcountry [parameter] [name or country-cod]",   //delcountry
        "deldatabase",     //deldatabase
        "exit",   //exit
        "filter [table] [key1] [condition_key1] [key2] [condition_key2] ...", //filter
        "help or help[command]",    //help
        "printinversefile [file_name] or printinversefile [table] [key] [order]",   //printinversefile
        "printtable [table]",   //printtable
        "sort [table] [key] [order]", //sort
    };

    return hum[ cod ];
}

string get_cmds_names( int cod ){
    static string hcn[]{
        "addcity",
        "addcountry",
        "addfile",
        "delcity",
        "delcountry",
        "deldatabase",
        "exit",
        "filter",
        "help",
        "printtable",
        "printinversefile",
        "sort"
    };

    return hcn[ cod ];
}


#endif //__SYSTEM_HELP_HPP