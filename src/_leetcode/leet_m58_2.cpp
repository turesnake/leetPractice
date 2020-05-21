/*
 * ====================== leet_m58_2.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题58 - II. 左旋转字符串
 */
#include "innLeet.h"


namespace leet_m58_2 {//~



std::string reverseLeftWords( std::string s, int n ){
    return std::string(s,n) + std::string(s,0,n);
}


//=========================================================//
void main_(){

    cout << reverseLeftWords( "a2", 1 ) << endl;

    
    

    debug::log( "\n~~~~ leet: m58_2 :end ~~~~\n" );
}
}//~
