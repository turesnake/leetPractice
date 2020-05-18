/*
 * ====================== leet_258.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 258. 各位相加
 */
#include "innLeet.h"


namespace leet_258 {//~

// 递归
int addDigits_1( int num ){

    if( num <= 9 ){ return num; }
    int sum {0};
    while( num>0 ){
        sum += num%10;
        num /= 10;
    }
    return addDigits_1( sum );
}

// 循环
int addDigits_2( int num ){

    if( num <= 9 ){ return num; }
    int sum = num;
    while( sum > 9 ){
        int n = sum;
        sum = 0;
        while( n>0 ){
            sum += n%10;
            n /= 10;
        }
    }
    return sum;
}






//=========================================================//
void main_(){

    auto ret = addDigits_2( 38 );

    cout << "ret = " << ret << endl;
    
    


    debug::log( "\n~~~~ leet: 258 :end ~~~~\n" );
}
}//~
