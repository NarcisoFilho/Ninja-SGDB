// #include "parser.hpp"

// void interpreter_line_input( string input , COMMAND& command , string* args , int& qtd_args ){
//         int end_field;

//         input = input.substr( input.find_first_not_of(' ') );
//         qtd_args = 0;

//         while( input != "" ){
//             // Remove the spaces from commando
//             input = input.substr( input.find_first_not_of( ' ' ) );

//             // Determine end of next argument 
//             end_field = input.find_first_of( ' ' );
//             if( end_field >= input.length() )
//                 end_field = input.length();
            
//             // Assign it to args[]
//             args[ qtd_args ] = input.substr( 0 , end_field );
//             qtd_args++;

//             // Remove previous argument from input
//             if( end_field < input.length() )
//                 input = input.substr( end_field + 1);
//             else
//                 input = "";
//         }

//         command = encode_command( args[0] );
// }

// COMMAND encode_command( string cmd_str ){
//         if( cmd_str == "addcity" )
//             return COMMAND::ADDCITY;
//         if( cmd_str == "addcountry" )
//             return COMMAND::ADDCOUNTRY;
//         if( cmd_str == "addfile" )
//             return COMMAND::ADDFILE;
//         if( cmd_str == "exit" )
//             return COMMAND::EXIT;
//         if( cmd_str == "filter" )
//             return COMMAND::FILTER;
//         if( cmd_str == "help" )
//             return COMMAND::HELP ;
//         if( cmd_str == "printtable" )
//             return COMMAND::PRINTTABLE;
//         if( cmd_str == "sort" )
//             return COMMAND::SORT;

//         return COMMAND::UNKNOWN_COMMAND;
// }


// int execute_line_input( COMMAND command , string *args , int qtd_args ){
//     switch( command ){
//         case COMMAND::ADDCITY:
//             if( qtd_args == 3 ){
//                 cout << endlT << "name: " << args[1] << endl;
//                 cout << endlT << "country_cod: " << args[2] << endl;
//                 cout << endlT << "population: " << args[3] << endl;
//                 cout << endlT << "tipo" << args[4] << endl;
//                 cout << endlT << "lat: " << args[5] << endl;
//                 cout << endlT << "lng: " << args[6] << endl;
//                 cout << endlT << "city_cod: " << args[7] << endl;
//             }else if( qtd_args < 7 )
//                 printError( Error::ERROR_FEW_ARGUMENTS );
//             else if( qtd_args > 7 )
//                 printError( Error::ERROR_MANY_ARGUMENTS );
//             break;

//         case COMMAND::ADDCOUNTRY :
//             if( qtd_args == 3 ){
//                     cout << endlT << "file_name: " << args[1] << endl;
//                     cout << endlT << "key: " << args[2] << endl;
//             }else if( qtd_args < 3 )
//                 printError( Error::ERROR_FEW_ARGUMENTS );
//             else if( qtd_args > 3 )
//                 printError( Error::ERROR_MANY_ARGUMENTS );
//             break;

//         case COMMAND::ADDFILE :
//             if( qtd_args == 3 ){
//                 cout << endlT << "file_name: " << args[1] << endl;
//                 cout << endlT << "file_type: " << args[2] << endl;
//             }else if( qtd_args < 3 )
//                 printError( Error::ERROR_FEW_ARGUMENTS );
//             else if( qtd_args > 3 )
//                 printError( Error::ERROR_MANY_ARGUMENTS );
//             break;

//         case COMMAND::EXIT :
//             if( qtd_args == 1 )
//                 return 1;
//             else
//                 printError( Error::ERROR_MANY_ARGUMENTS );
//             break;

//         case COMMAND::FILTER :
//             if( qtd_args == 3 ){
//                 cout << endlT << "file_name: " << args[1] << endl;
//                 cout << endlT << "key: " << args[2] << endl;
//             }else if( qtd_args < 3 )
//                 printError( Error::ERROR_FEW_ARGUMENTS );
//             break;
        
//         case COMMAND::HELP:
//             if( qtd_args == 1 )
//                 printHelp();   
//             else if( qtd_args == 2 )
//                 printHelp( args[1] );   
//             else
//                 printError( Error::ERROR_MANY_ARGUMENTS );
//             break;
//         case COMMAND::PRINTTABLE :
           
//             break;
//         case COMMAND::SORT :
           
//             break;
//             if( qtd_args == 3 ){
//                 if( args[1] == "-cityT"  ||  args[1] == "-countryT" ){
//                     if( args[2] == "-ascending"  ||  args[1] == "-descending"
//                     || args[2] == "-a"  ||  args[1] == "-d" ){
//                         cout << endlT << "table: " << args[1] << endl;
//                         cout << endlT << "key: " << args[2] << endl;
//                     }
//                     else
//                         printError( Error::ERROR_ORDER_TYPE_INVALID );
//                 }else
//                     printError( Error::ERROR_TABLE_TYPE_INVALID );
                
//             }else if( qtd_args < 3 )
//                 printError( Error::ERROR_FEW_ARGUMENTS );
//             else if( qtd_args > 3 )
//                 printError( Error::ERROR_MANY_ARGUMENTS );
//         case COMMAND::UNKNOWN_COMMAND :
//             printError( Error::ERROR_UNKNOWN_COMMAND );
//             return -1;
//             break;
//     }

//     return 0;
// }


