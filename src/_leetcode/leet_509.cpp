/*
 * ====================== leet_509.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 509. 斐波那契数
 */
#include "innLeet.h"


namespace leet_509 {//~


// 递归
int fib( int N ){
    if( N==0 ){ return 0; }
    if( N==1 ){ return 1; }
    return (fib(N-1) + fib(N-2));
}

// 递归
int fib_2( int N ){
    if( N==0 ){ return 0; }
    if( N==1 ){ return 1; }
    // 以下从2开始
    int left = 0; //[0]
    int right = 1; //[1]
    for( int i=2; i<=N; i++ ){
        int sum = left + right;
        left = right;
        right = sum;
    }
    return right;
}






//=========================================================//
void main_(){

    for( int i : { 0,1,2,3,4,5,6,7,8,9,10 } ){
        cout << "i:" << i << ", fib = " << fib_2(i) << endl;
    }

    

  
    debug::log( "\n~~~~ leet: 509 :end ~~~~\n" );
}
}//~
