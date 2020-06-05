/*
 * ====================== leet_1281.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1281. 整数的各位积和之差
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1281 {//~


// 100%, 100%
class S{
public:
    // 1 <= n <= 10^5
    int subtractProductAndSum(int n) {

        int product {1};
        int sum     {0};
        for( int i=n; i>0; i/=10 ){
            int v = i%10;
            product *= v;
            sum += v;
        }
        return product - sum;
    }
};



//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 1281 :end ~~~~\n" );
}
}//~
