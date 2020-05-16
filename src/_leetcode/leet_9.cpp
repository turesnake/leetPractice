/*
 * ====================== leet_9.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 9. 回文数
 */
#include "innLeet.h"


namespace leet_9 {//~



// 最简单的 双向队列法 8.02%, 5.95%
// 性能堪忧
bool isPalindrome( int x ){
    
    if( x < 0 ){ return false; }
    if( x <= 9 ){ return true; }

    std::deque<int> que {};
    int num = x;
    while( num > 0 ){
        que.push_front( num%10 );
        num = num/10;
    }
    while( que.size()>1 ){
        if( que.front() != que.back() ){ return false; }
        que.pop_front();
        que.pop_back();
    }
    return true;
}





//=========================================================//
void main_(){

    


    for( int i : { -1, 0, 551, 151, 1551, 12377321, 1237321  } ){
        debug::log( "{} = {}", i, isPalindrome(i) );
    }


    debug::log( "\n~~~~ leet: 9 :end ~~~~\n" );
}
}//~
