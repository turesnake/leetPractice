/*
 * ====================== leet_402.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 402. 移掉K位数字
 */
#include "innLeet.h"


namespace leet_402 {//~


// 有点难写
std::string removeKdigits( std::string num, int k ) {

    if( k<=0 ){ return num; }
    if( k>=static_cast<int>(num.size()) ){ return "0"; }

    std::deque<int> que {};
    for( const char c : num ){
        int newV = static_cast<int>(c-'0');
        while( k>0 && !que.empty() && (que.back()>newV) ){
            que.pop_back();
            k--;
        }
        que.push_back(newV);
    }
 
    std::string out {};
    while( !que.empty() ){
        int v = que.front();
        que.pop_front();
        if( !(out.empty() && v==0) ){
            out += static_cast<char>('0'+v);
        }
    }

    if( k >= static_cast<int>(out.size()) ){ return "0"; }
    if( k>0 ){ out.erase( out.size()-k,k ); }
    return out;
}





//=========================================================//
void main_(){

    auto ret = removeKdigits( "1234567890", 9 );
    debug::log( "ret = {}", ret );


    debug::log( "\n~~~~ leet: 402 :end ~~~~\n" );
}
}//~
