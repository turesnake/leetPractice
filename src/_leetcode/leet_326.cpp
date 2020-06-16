/*
 * ===================== leet_326.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 326. 3的幂
 */
#include "innLeet.h"


namespace leet_326 {//~


// 除了无耻的 穷举法，也没看出有啥更先进的方法


//  38%  100%
class S{
public:
    bool isPowerOfThree( int n ){

        if( n<=0 ){ return false; }
        for( ; n>0; n/=3 ){
            if( n==1 ){ return true; }
            if( n%3!=0 ){ return false; }
        }
        return true;


    }
};



//=========================================================//
void main_(){

    cout<<S{}.isPowerOfThree( 3 )<<endl;


    debug::log( "\n~~~~ leet: 326 :end ~~~~\n" );
}
}//~
