/*
 * ====================== leet_1047.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1047. 删除字符串中的所有相邻重复项
 */
#include "innLeet.h"


namespace leet_1047 {//~


std::string removeDuplicates( std::string S ){

    std::deque<char> stk {};
    for( const char c : S ){
        if( stk.empty() ){ 
            stk.push_back(c); 
        }else{
            (stk.back() == c) ?
                    stk.pop_back() :
                    stk.push_back(c);
        }
    }
    std::string out {};
    while( !stk.empty() ){
        out += stk.front();
        stk.pop_front();
    }
    return out;
}




//=========================================================//
void main_(){

    auto ret = removeDuplicates( "g" );

    cout << "ret = " << ret << endl;

    


    debug::log( "\n~~~~ leet: 1047 :end ~~~~\n" );
}
}//~
