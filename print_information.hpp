#ifndef __PRINT_INFORMATION_HPP
#define __PRINT_INFORMATION_HPP

#include "system_help.hpp"
#include "ParaManip.hpp"



/// Prototypes
// void printWelcome();
// void printError( Error );
// void printHelp();
// void printHelp( string );
void print_help_other_msgs( COMMAND );


void printWelcome(){
    cout << "############-------------NINJA SGDB------------############" << endl;
    cout << "#                                                         #" << endl;
    cout << "# Welcome!                                                #" << endl;
    cout << "# If you are new here, or want to know more, type 'help'  #" << endl;
    cout << "#                                                         #" << endl;
    cout << "###########################################################" << endl << endl;
}

void printBye(){
    cout << endl;
    cout << "- - - - - - |  Thank for use! See you later.. |- - - - - - " << endl;
    cout << "            |------------NINJA SGDB-----------|            " << endl;
}

void printError( Error error ){
    cout << endl << "\aERROR: ";
    switch( error ){
        case Error::ERROR_MANY_ARGUMENTS:
            cout << "Too many arguments for this command" << endl;
            break; 
        case Error::ERROR_FEW_ARGUMENTS:
            cout << "Too few arguments for this command" << endl;
            break; 
        case Error::ERROR_UNKNOWN_COMMAND:
            cout << "Unknown command" << endl;
            break; 
        case Error::ERROR_TABLE_TYPE_INVALID:
            cout << "Invalid Table Type" << endl;
            break; 
    }
    cout << tab << "Tip: Try to use the command 'help'..." << endl;
}



void printHelp(){
    cout << tab << "______________NINJA SGDB______________" << endl;
    cout << tab << "These are the commands you can use:" << endl << endl;

    for( int i = 0 ; i < QTD_HELP_BASIC_MSGS ; i++ )
        cout << tab(2) << setw(15) << left << get_cmds_names(i) + ':' << get_cmds_basic_help_msgs(i) << endl;
}

void printHelp( COMMAND command ){
    cout << tab << "Use: " << get_cmds_use_help_msgs( static_cast<int>( command ) ) << endl;
    print_help_other_msgs( command );
}

void print_help_other_msgs( COMMAND command ){
    cout << tab(2);
    switch( command ){
        case COMMAND::ADDCITY:
                cout << "Append one register of city to the cities table" << endl;
                break;
        case COMMAND::ADDCOUNTRY:
                cout << "Append one register of country to the countries table" << endl;
                break;
        case COMMAND::ADDFILE:
                cout << "It take all the registers in the file and append them in the respective table." << endl;

                cout << endl << tab(2) << "Types:" << endl;
                cout << tab(3) << "-cityf" << "A city file" << endl;
                cout << tab(3) << "-countryf" << "A country file" << endl;

                cout << endl << tab(2) << "Examples:" << endl;
                cout << tab(3) << " addfile my_file_of_cities -cityf" << endl;
                cout << tab(3) << " addfile my_file_of_countries -countryf" << endl;
                break;
        case COMMAND::DELCITY:
                cout << "Delete one register of the Cities Table." << endl;

                cout << endl << tab(2) << "Examples:" << endl;
                cout << tab(3) << "delcity city_name" << endl;
                cout << tab(3) << "delcity city_cod" << endl;
                break;
        case COMMAND::EXIT:
                cout << "exit: Stop the program  and go out to the OS" << endl;
                break;
        case COMMAND::FILTER:
                cout << "Return only the registers wiches key(s) attend(s) the conditions." << endl;

                cout << endl << tab(2) << "Operators for the conditions:" << endl;
                cout << tab(3) << "[=]: " << "Use equals sign at the beginning of condition to say that the key must be equal to value " << endl;
                cout << tab(3) << "[!]: " << "Use exclamation at the beginning of condition to say that the key must be diferent to value " << endl;
                cout << tab(3) << "[<]: " << "Use less than sign at beginning of condition to say that key must be less than value " << endl;
                cout << tab(3) << "[>]: " << "Use greater than sign at beginning of condition to say that key must be greater than value " << endl;
                cout << endl << tab(2) << "Parameters:" << endl;
                cout << tab(3) << "-ncs: No Case Sensitive.Disregards if the letters are capitalized or not in the comparation of strings." << endl;

                cout << endl << tab(2) << "Examples:" << endl;
                cout << tab(3) << " filter my_file age >18   // This filter the registers with age greter than 18 years" << endl;
                cout << tab(3) << " filter my_file name =Peter   // This filter the registers with name equal to Peter(with capital P)" << endl;
                cout << tab(3) << " filter my_file name =Peter -ncs   // This make almost the same, but do not matter capital or non capital letters" << endl;
                break;
        case COMMAND::HELP:
                cout << "Show a list of all the commands and a brief" << endl;
                cout << tab(2) << "It can also recieve a parameter [command]. In this case it show a more deeply explanation about one specific command" << endl;
                cout << endl << tab(2) << "Examples:" << endl;
                cout << tab(3) << "help filter   // This will show a significantily completely guide of the instruction 'filter'" << endl;
                break;
        case COMMAND::PRINTTABLE:
                cout << "Print one table or the combination of some tables." << endl;
                cout << endl << tab(2) << "Types:" << endl;
                cout << tab(3) << "-citiesT: The city table " << endl;
                cout << tab(3) << "-countryT: The country table" << endl;
                cout << tab(3) << "-ccT: The city table showing country data (combination)" << endl;
                break;
        case COMMAND::SORT:
                cout << "Sort one array in respect with some key" << endl;
                cout << tab(2) << "Table Options" << endl;
                cout << tab(3) << "-citiesT: Cities Table" << endl;
                cout << tab(3) << "-countryT: Countries Table" << endl;
                
                cout << tab(2) << "Order Options" << endl;
                cout << tab(3) << "-ascending: Ascending order" << endl;
                cout << tab(3) << "-a: Brief for Ascending order" << endl;
                cout << tab(3) << "-descending: Descending order" << endl;
                cout << tab(3) << "-d: Brief for Descending order" << endl;
                break;
    }
}


// void printHelp( string command ){

//     if( command == "addcity" ){
//         cout << tab(2) << "addcity [name] [country_cod] [population] [tipo] [lat] [lng] [city_cod]  " << endl;
//         cout << tab(3) << "Append one register of city to the cities table" << endl;
//     }else if( command == "addcountry" ){
//         cout << tab(2) << "addcountry [name] [region] [exitalpha-2] [alpha-3] [country-cod]" << endl;
//         cout << tab(3) << "Append one register of country to the countries table" << endl;
//     }else if( command == "addfile" ){
//         cout << tab << "addfile [file] [type]: Append the table of cities or countries by one file." << endl;
//         cout << tab(2) << "It take all the registers in the file and append them in the respective table." << endl;

//         cout << endl << tab(2) << "Types" << endl;
//         cout << tab(3) << "-cityf" << "A city file" << endl;
//         cout << tab(3) << "-countryf" << "A country file" << endl;

//         cout << endl << tab(2) << "Examples:" << endl;
//         cout << tab(3) << " addfile my_file_of_cities -cityf" << endl;
//         cout << tab(3) << " addfile my_file_of_countries -countryf" << endl;
//     }else if( command == "exit" ){
//         cout << tab << "exit: Stop the program  and go out to the OS" << endl;
//     }else if( command == "filter" ){
//         cout << tab << "filter [table] [key1] [condition_key1] [key2] [condition_key2] ... :" << endl;
//         cout << tab(2) << "Return only the registers wiches key(s) attend(s) the conditions." << endl;

//         cout << endl << tab(2) << "Operators for the conditions:" << endl;
//         cout << tab(3) << "[=]: " << "Use equals sign at the beginning of condition to say that the key must be equal to value " << endl;
//         cout << tab(3) << "[!]: " << "Use exclamation at the beginning of condition to say that the key must be diferent to value " << endl;
//         cout << tab(3) << "[<]: " << "Use less than sign at beginning of condition to say that key must be less than value " << endl;
//         cout << tab(3) << "[>]: " << "Use greater than sign at beginning of condition to say that key must be greater than value " << endl;
//         cout << endl << tab(2) << "Parameters:" << endl;
//         cout << tab(3) << "-ncs: No Case Sensitive.Disregards if the letters are capitalized or not in the comparation of strings." << endl;

//         cout << endl << tab(2) << "Examples:" << endl;
//         cout << tab(3) << " filter my_file age >18   // This filter the registers with age greter than 18 years" << endl;
//         cout << tab(3) << " filter my_file name =Peter   // This filter the registers with name equal to Peter(with capital P)" << endl;
//         cout << tab(3) << " filter my_file name =Peter -ncs   // This make almost the same, but do not matter capital or non capital letters" << endl;
//     }else if( command == "help" ){
//         cout << tab << "- help: Show a list of all the commands and a brief" << endl;
//         cout << tab << "- help [command]: Show a more deeply explanation about one specific command" << endl;
//     }else if( command == "printtable" ){
//         cout << tab << "printtable [table]: Print the content of one table or combinations" << endl;
//         cout << tab(2) << "Types:" << endl;
//         cout << tab(3) << "-citiesT: The city table " << endl;
//         cout << tab(3) << "-countryT: The country table" << endl;
//         cout << tab(3) << "-ccT: The city table showing country data" << endl;
//     }else if( command == "sort" ){
//         cout << tab << "sort [table] [key] [order]: Sort and return the data from one table. The sorting is made with respect to key" << endl;
        
//         cout << tab(2) << "Table Options" << endl;
//         cout << tab(3) << "-citiesT: Cities Table" << endl;
//         cout << tab(3) << "-countryT: Countries Table" << endl;
        
//         cout << tab(2) << "Order Options" << endl;
//         cout << tab(3) << "-ascending: Ascending order" << endl;
//         cout << tab(3) << "-a: Brief for Ascending order" << endl;
//         cout << tab(3) << "-descending: Descending order" << endl;
//         cout << tab(3) << "-d: Brief for Descending order" << endl;
//     }
// }


#endif //__PRINT_INFORMATION_HPP