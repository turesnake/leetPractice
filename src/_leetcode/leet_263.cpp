/*
 * ====================== leet_263.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 263. 丑数
 */
#include "innLeet.h"


namespace leet_263 {//~



bool isUgly( int num ){
    if( num<1 ){ return false; }
    while( num%2==0 ){ num /= 2; }
    while( num%3==0 ){ num /= 3; }
    while( num%5==0 ){ num /= 5; }
    return (num==1);
}





//=========================================================//
void main_(){

    for( int i : { -1,0,1,2,3,4,5,6,7,8,9,10 } ){
        cout << i << ": " << isUgly(i) << endl;
    }
    


    debug::log( "\n~~~~ leet: 263 :end ~~~~\n" );
}
}//~
