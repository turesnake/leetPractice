/*
 * ====================== leet_6.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * Z 字形变换
 */
#include "innLeet.h"


namespace leet_6 {//~




std::string convert( std::string s, int numRows ) {

    if( s.empty() || (numRows<=0) ){ return ""; }

    std::vector<std::string> sstr ( numRows, "" );
    int idx {0};
    bool isOrder {true};

    for( const char c : s ){
        sstr.at(idx).push_back( c );

        if( isOrder ){
            idx++;
            if( idx >= numRows-1 ){
                idx = numRows-1;
                isOrder = false;
            }
        }else{
            idx--;
            if( idx <= 0 ){
                idx = 0;
                isOrder = true;
            }
        }
    }

    std::string out {};
    for( const auto &s : sstr ){
        out += s;
    }
    return out;
}



//=========================================================//
void main_(){

    auto ret = convert( "AB", 1 );

    debug::log( "{}", ret );
    
    


    debug::log( "\n~~~~ leet: 6 :end ~~~~\n" );
}
}//~
