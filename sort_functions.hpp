#ifndef __SORT_FUNCTIONS_HPP
#define __SORT_FUNCTIONS_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
using namespace std;

#include "definitions.hpp"
#include "print_information.hpp"
#include "commands.hpp"
#include <limits>
#include <vector>
#include <cstring>
#include "utils.hpp"

// template<class Entity>
// Entity get_entity( fstream& table , int n ){
//     Entity entity;

//     tree_sort.seekg(n);
//     table.read( (char*)&entity , sizeof(Entity) );

//     return entity;
// }


// int get_key_val(fstream& tree_sort , int n , int qtd ){
//     int key_val;

//     if( n >= qtd ){
//         key_val = -1;
//     }else{
//         tree_sort.seekg( n );
//         tree_sort.read( (char*)&key_val , sizeof( int ) );
//     }

//     return key_val;
// }

// template <class Entity>
// void heapify( fstream& tree_sort , ifstream& table , int key_cod , bool descending = false  , int root , int qtd_elements ){
//     Entity entity , left_sun , right_sun;

//     int *pos_table = new int;
//     bool flag_troca = true;

//     do{
//         tree_sort.seekg(0);
//         tree_sort.read( (char*)pos_table , sizeof(int) );

//         entity = get_entity<Entity>( table , pos_table );

//         if( 2 * pos_table + 1 < qtd_elements ){
//             left_sun = get_entity<Entity>( table , 2 * pos_table + 1 );
//             if( 2 * pos_table + 2 < qtd_elements ){
//                 right_sun = get_entity<Entity>( table , 2 * pos_table + 2 );
//                 if( left_sun.key > right_sun.key ){

//                 }else

//             }else{
//                 root = 2 * pos_table + 1;
//             }
//         }else
//             flag_troca = false;
            
//     }while( flag_troca );

//     delete pos_table;
// }

// // HeapSort
// template <class Entity>
// void sort( fstream& tree_sort , ifstream& table , int key_cod , bool descending = false ){
//     int *qtd_registers = new int;
//     tree_sort.seekg( -sizeof(int) , ios::end );
//     tree_sort.read( (char*)qtd_registers , sizeof( int ) );
//     qtd_registers++;

//     int index_last_sub_tree = ( (qtd_registers) / 2 ) - 1;

//     for( int r = index_last_sub_tree ; r >= 0 ; r-- )
//         heapify<Entity>( tree_sort , table , key_cod , descending , r , qtd_registers );
//     while( *qtd_registers > 0 ){
//         heapify<Entity>( tree_sort , table , key_cod , descending , 0 , qtd_registers );
//         swap_registers_file( tree_sort , 0 , qtd_registers );
//         (*qtd_registers)--;
//     }
    // delete qtd_registers;
// }


bool sort_check_correct_order( City ref , City comp , int key_cod , bool descending = false ){
    bool check_relation;
    string ref_name_str = ref.name;
    string comp_name_str = comp.name;
    string ref_type_str = ref.type;
    string comp_type_str = comp.type;

    switch(key_cod){
        case 0:
            check_relation = (ref.id < comp.id);
            break;
        case 1:
            check_relation = ( my_toupper(ref_name_str) < my_toupper(comp_name_str) );
            break;
        case 2:
            check_relation = (ref.population < comp.population);
            break;
        case 3:
            check_relation = ( my_toupper(ref_type_str) < my_toupper(comp_type_str) );
            break;
        case 4:
            check_relation = (ref.lat < comp.lat);
            break;
        case 5:
            check_relation = (ref.lng < comp.lng);
            break;
        case 6:
            check_relation = (ref.country_cod < comp.country_cod);
            break;
        case 7:
            check_relation = (ref.country_cod < comp.country_cod);
            break;
    }
    // cout << "## ref.name = " << ref.name << "    comp.name = " << comp.name << endl;
    // cout << "## key = " << key_cod << "    check_relation = " << check_relation << endl;
    // cout << "## (check_relation && !descending)  || (!check_relation && descending) = " << ( (check_relation && !descending)  || (!check_relation && descending) ) << endl;
    return (check_relation && !descending)  || (!check_relation && descending) ;
}



bool sort_check_correct_order( Country ref , Country comp , int key_cod , bool descending = false ){
    bool check_relation;
    switch(key_cod){
        case 0:
            check_relation = ( ref.id < comp.id );
            break;
        case 1:
            check_relation = ( ref.name < comp.name );
            break;
        case 2:
            check_relation = ( ref.alpha2 < comp.alpha2 );
            break;
        case 3:
            check_relation = ( ref.alpha3 < comp.alpha3 );
            break;
        case 4:
            check_relation = ( ref.region < comp.region );
            break;
    }
    return (check_relation && !descending)  || (!check_relation && descending) ;
}

// BubleSort
template <class Entity>
void BubleSort( fstream& tree_sort , ifstream& table , int key_cod , bool descending = false ){
    int *qtd_registers = new int;
    int *a = new int;
    
    int final_ref;
    int ref;
    int comp;
    int ref_index;
    int comp_index;
    Entity ent_ref;
    Entity ent_comp;
    
    table.clear();
    table.seekg( -sizeof(Entity) , ios::end );
    table.read( (char*)&ent_ref , sizeof( Entity ) );
    *qtd_registers = ent_ref.id;
    (*qtd_registers)++;

    for( final_ref = (*qtd_registers) - 2 ; final_ref >= 0 ; final_ref-- ){
        for( ref = 0 ; ref <= final_ref ; ref++ ){
            comp = ref + 1;

            tree_sort.seekg( ref * sizeof( int ) );
            tree_sort.read( (char*)&ref_index , sizeof(int) );
            tree_sort.seekg( comp * sizeof( int ) );
            tree_sort.read( (char*)&comp_index , sizeof(int) );

            table.seekg( ref_index * sizeof( Entity ) );
            table.read( (char*)&ent_ref , sizeof( Entity ) );
            table.seekg( comp_index * sizeof( Entity )  );
            table.read( (char*)&ent_comp , sizeof( Entity ) );
            if( sort_check_correct_order( ent_ref , ent_comp , key_cod , descending ) == false ){
                tree_sort.seekp( comp * sizeof( int ) );
                tree_sort.write( (char*)&ref_index , sizeof( int ) );
                tree_sort.seekp( ref * sizeof( int ) );
                tree_sort.write( (char*)&comp_index , sizeof( int ) );
            }
        }
    }

    delete qtd_registers;
    delete a;
}

template <class Entity>
string get_name_sort_tree( string key , bool descending ){
    return  decode_table_file_name<Entity>().substr( 0 , 10 ) + "_" + key + "_" + ( !descending ? 'a':'d' ) + ".bin";
}

template<class Entity>
void create_sort_tree( string key , bool descending = false ){
    string table_file_name = decode_table_file_name<Entity>();
    string sort_tree_file_name = get_name_sort_tree<Entity>( key , descending );
    ifstream table( table_file_name , F_IN );
    fstream sort_tree( sort_tree_file_name , ios::binary | ios::in | ios::out | ios::trunc );
    Entity entity;
    int key_cod = encode_key_name<Entity>( key );
    
    if( !sort_tree.is_open() )
        printError( Error::ERROR_SORT_TREE_FILE_CREATING );
    else if( table.is_open() ){
        table.read( (char*)&entity , sizeof(Entity) );
        while( !table.eof() ){
            sort_tree.write( (char*)&(entity.id) , sizeof(int) );
            table.read( (char*)&entity , sizeof(Entity) );
        }

        BubleSort<Entity>( sort_tree , table , key_cod , descending );
    }
}

template<class Entity>
void sort( string key , bool descending = false ){
    ifstream table( decode_table_file_name<Entity>() , ios::binary | ios::in );
    ifstream sort_tree;
    string sort_tree_file_name; 

    if( !table.is_open() ){
        print_table_empty();
    }else{
        sort_tree_file_name = get_name_sort_tree<Entity>( key ,descending );
        sort_tree.open( sort_tree_file_name , ios::binary | ios::in );
        if( !sort_tree.is_open() ){
            create_sort_tree<Entity>( key , descending );
            sort_tree.open( sort_tree_file_name , ios::binary | ios::in );
        }

        if( !sort_tree.is_open() ){
            printError( Error::ERROR_ACCESS_SORT_TREE); 
        }else{
            print_table_sort_tree<Entity>( sort_tree );
        }
    }
}




#endif //__SORT_FUNCTIONS_HPP