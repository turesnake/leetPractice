/*
 * ====================== leet_70.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 70. 爬楼梯
 */
#include "innLeet.h"


namespace leet_70 {//~




// 动态规划：递归 超时
int climbStairs_1( int n ){
    if( n<=2 ){ return n; }// 0,1,2
    return climbStairs_1(n-1) + climbStairs_1(n-2);
}




// 动态规划，循环， O[1] 空间
int climbStairs_2( int n ){

    if( n<=2 ){ return n; }// 0,1,2
    int left  = 1;// [1]
    int right = 2;// [2]
    for( int i=3; i<=n; i++ ){
        int sum = left+right;
        left = right;
        right = sum;
    }
    return right;
}



//=========================================================//
void main_(){

    for( int i : { 2,3,4,5 } ){
        cout << "i:" << i << ", " << climbStairs_2(i) << endl;
    }


    debug::log( "\n~~~~ leet: 70 :end ~~~~\n" );
}
}//~
