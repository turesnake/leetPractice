/*
 * ====================== leet_190.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 190. 颠倒二进制位
 */
#include "innLeet.h"


namespace leet_190 {//~


//  59%  100%
class S{
public:
    uint32_t reverseBits( uint32_t n ){

        uint32_t ans {0};
        for( int i=0; i<32; i++ ){
            ans = ans*2 + n%2;
            n>>=1;
        }
        return ans;
        
    }
};



//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 190 :end ~~~~\n" );
}
}//~
