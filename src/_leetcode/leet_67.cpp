/*
 * ====================== leet_67.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 67. 二进制求和
 */
#include "innLeet.h"


namespace leet_67 {//~



// 和十进制计算 是一样的
std::string addBinary( std::string a, std::string b ){

    std::deque<char> que {};
    int aLen = static_cast<int>(a.size());
    int bLen = static_cast<int>(b.size());
    int ai = aLen-1;
    int bi = bLen-1;

    int isCarry = 0;
    while( ai>=0 || bi>=0 ){
        int av = (ai>=0) ? (a.at(ai--)-'0') : 0;
        int bv = (bi>=0) ? (b.at(bi--)-'0') : 0;
        int sum = av + bv + isCarry;
        isCarry = (sum>1) ? 1 : 0;
        que.push_front( static_cast<char>( '0'+(sum%2) ) );
    }
    if( isCarry ){ que.push_front('1'); }
    return std::string( que.begin(), que.end() ); // 直接用 迭代器，初始化 string
}





//=========================================================//
void main_(){

    cout << "[" << addBinary( "111", "10110" ) << "]" << endl;

    
    

    debug::log( "\n~~~~ leet: 67 :end ~~~~\n" );
}
}//~
