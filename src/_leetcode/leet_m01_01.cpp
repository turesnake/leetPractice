/*
 * ====================== leet_m01_01.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.24
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 01.01. 判定字符是否唯一
 */
#include "innLeet.h"


namespace leet_m01_01 {//~


bool isUnique( std::string astr ){

    if( astr.size()<2 ){ return true; }
    std::unordered_set<char> sett {};
    for( char c : astr ){
        if( sett.erase(c)==0 ){
            sett.insert(c);
        }else{
            return false;
        }
    }
    return true;
}






//=========================================================//
void main_(){

    for( std::string &s : std::vector<std::string>{ "leet", "abc", "", "a", "abnhjueska" } ){

        cout << s << " : " << isUnique(s) << endl;
         
    }
  
    


    debug::log( "\n~~~~ leet: m01_01 :end ~~~~\n" );
}
}//~
