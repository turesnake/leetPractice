/*
 * ====================== leet_504.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 504. 七进制数
 */
#include "innLeet.h"



namespace leet_504 {//~


std::string convertToBase7( int num ){

    if( num==0 ){ return "0"; }

    // 记录正负号
    bool isNeg = num < 0;
    if( isNeg ){ num = -num; }

    std::deque<char> que {};

    for( ; num>0; num/=7 ){
        que.push_front( static_cast<char>('0'+num%7) );
    }
    if( isNeg ){ que.push_front('-'); }

    std::string out {};
    while( !que.empty() ){
        out += que.front();
        que.pop_front();
    }
    return out;
}



//=========================================================//
void main_(){

    
    for( int i : { 0,-1,-8,8,10, 100, -7 } ){
        debug::log( "ret:{}", convertToBase7( i ) );
    }

    
    

    debug::log( "\n~~~~ leet: 504 :end ~~~~\n" );
}
}//~

