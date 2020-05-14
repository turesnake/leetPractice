/*
 * ====================== leet_14.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 14. 最长公共前缀
 */
#include "innLeet.h"


namespace leet_14 {//~



std::string longestCommonPrefix( std::vector<std::string>& strs) {

    if( strs.size()==1 ){ return strs.front(); }
        
    int idx {0};
    std::string out {""};
    std::set<char> cSet {};

    while( true ){

        cSet.clear();
        for( size_t i=0; i<strs.size(); i++ ){ // each str
            if( idx >= static_cast<int>(strs.at(i).size()) ){
                return out; 
            }
            cSet.insert( strs.at(i).at(idx) );
        }

        if( cSet.size() != 1){
            return out; 
        }

        out += *cSet.begin();
        idx++;
    }

    return out;
}





//=========================================================//
void main_(){

    std::vector<std::string> data { "asddwdwd" };

    auto ret = longestCommonPrefix( data );


    debug::log( "ret = {}", ret );
    
    


    debug::log( "\n~~~~ leet: 14 :end ~~~~\n" );
}
}//~
