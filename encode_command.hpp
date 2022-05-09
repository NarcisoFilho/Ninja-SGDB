#ifndef __ENCODE_COMMAND_HPP
#define __ENCODE_COMMAND_HPP

#include <iostream>
#include "definitions.hpp"

using namespace std;

COMMAND encode_command( string cmd_str ){
        if( cmd_str == "addcity" )
            return COMMAND::ADDCITY;
        if( cmd_str == "addcountry" )
            return COMMAND::ADDCOUNTRY;
        if( cmd_str == "addfile" )
            return COMMAND::ADDFILE;
        if( cmd_str == "delcity" )
            return COMMAND::DELCITY;
        if( cmd_str == "delcountry" )
            return COMMAND::DELCOUNTRY;
        if( cmd_str == "deldatabase" )
            return COMMAND::DELDATABASE;
        if( cmd_str == "exit" )
            return COMMAND::EXIT;
        if( cmd_str == "filter" )
            return COMMAND::FILTER;
        if( cmd_str == "help" )
            return COMMAND::HELP ;
        if( cmd_str == "printtable" )
            return COMMAND::PRINTSORTETREE;
        if( cmd_str == "printinvfile" )
            return COMMAND::PRINTTABLE;
        if( cmd_str == "sort" )
            return COMMAND::SORT;

        return COMMAND::UNKNOWN_COMMAND;
}



#endif //__ENCODE_COMMAND_HPP