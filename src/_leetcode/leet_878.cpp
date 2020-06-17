/*
 * ===================== leet_878.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 878. 第 N 个神奇数字
 */
#include "innLeet.h"


namespace leet_878 {//~



// 这题要用到 数学归纳法 和 二分查找...



//  朴素法 直接超时
class S{
public:
    // 值 取模 10^9+7
    // 1 <= N <= 10^9
    // 2 <= A <= 40000
    // 2 <= B <= 40000
    int nthMagicalNumber( int N, int A, int B ){


        int64_t mod = 1000000007;
        int64_t ai = 1;
        int64_t bi = 1;
        int64_t av = A;
        int64_t bv = B;
        int64_t tgt = 0;
        for( int i=0; i<N; i++ ){
            if( av < bv ){// choose av
                tgt = av;
                ai++;
                av = (A*ai)%mod;

            }else if( av > bv ){// choose bv
                tgt = bv;
                bi++;
                bv = (B*bi)%mod;

            }else{// ==
                tgt = av;
                ai++;
                av = (A*ai)%mod;
                bi++;
                bv = (B*bi)%mod;
            }
        }
        return static_cast<int>(tgt);
    
    }
};




//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 878 :end ~~~~\n" );
}
}//~
