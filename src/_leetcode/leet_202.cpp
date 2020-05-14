/*
 * ====================== leet_202.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 202. 快乐数
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_202 {//~




int calcNum( int n_ ){
    int sum {0};
    while( n_ ){
        int mod = n_%10;
        n_ = n_ / 10;
        sum += mod*mod;
    }
    return sum;
}


bool isHappy(int n) {

    int slow = n;
    int fast = n;

    while ( true ){

        if( fast==1 ){ break; }
        int fastNext = calcNum(fast);
        if( fastNext==1 ){ break; }

        fast = calcNum( fastNext );
        slow = calcNum( slow );
        if( slow==fast ){
            return false;
        }
    }
    return true;
}   









//=========================================================//
void main_(){

    int ret = calcNum( 82 );

    cout << "ret = " << ret << endl;
    


    debug::log( "\n~~~~ leet: 202 :end ~~~~\n" );
}
}//~

