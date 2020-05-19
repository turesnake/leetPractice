/*
 * ====================== leet_338.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 338. 比特位计数
 */
#include "innLeet.h"


namespace leet_338 {//~



// 使用现成函数 __builtin_popcount
std::vector<int> countBits_1( int num ){

    std::vector<int> outs ( num+1, 0 );
    for( int i=0; i<=num; i++ ){
        outs.at(i) = __builtin_popcount( i );
    }
    return outs;
}






//=========================================================//
void main_(){

    auto ret = countBits_1( 7 );

    for( int i : ret ){
        cout << i << endl;
    }
    
    





    debug::log( "\n~~~~ leet: 338 :end ~~~~\n" );
}
}//~
