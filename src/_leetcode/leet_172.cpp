/*
 * ====================== leet_172.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 172. 阶乘后的零
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_172 {//~





// 分别收集，有多少个2，多少个5 
// 其中，N5 的增长速度，远远小于 N2 的
// 所以可以认为，2 的数量，一定能满足 5 的使用 
// 可以优先考虑 N5
class S{
public:
    // 参数可为负数，结果和正数 值相同，添负号 
    int trailingZeroes( int n ){

        if( n==0 ){ return 0; }
        bool isNeg {false};
        uint64_t un {};
        if( n<0 ){
            un = static_cast<uint64_t>(-n);
            isNeg = true;
        }else{
            un = static_cast<uint64_t>(n);
        }
        //=== N5 ===//
        uint64_t N5 = 0;
        for( uint64_t f=5; f<=un; f*=5 ){
            N5 += un/f;
        }
        return isNeg ? -static_cast<int>(N5) : static_cast<int>(N5);
    }
};


//=========================================================//
void main_(){


    cout << "ret:"<<S{}.trailingZeroes( 2147482647 )<<endl;
    

    
    debug::log( "\n~~~~ leet: 172 :end ~~~~\n" );
}
}//~
