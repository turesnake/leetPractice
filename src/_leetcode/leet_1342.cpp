/*
 * ====================== leet_1342.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.07
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1342. 将数字变成 0 的操作次数
 */
#include "innLeet.h"


namespace leet_1342 {//~


// 朴素法，顺着题意的解法
//  30%  100%
class S{
public:
    int numberOfSteps (int num) {

        int times = 0;
        for(; num>0; times++ ){
            if( (num&1)==0 ){// eve
                num >>= 1;
            }else{// odd
                num -= 1;
            }
        }
        return times;

    }
};


//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 1342 :end ~~~~\n" );
}
}//~
