/*
 * ====================== leet_m10_1.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题10- I. 斐波那契数列
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m10_1 {//~


// 迭代版 100%， 100%
// 结果需要取模 1e9+7（1000000007）int装得下
class S{
public:
    int fib( int n ){
        if(n<2){ return n; }
        if(n==2){ return 1; }
        int a = 1;//[1]
        int b = 1;//[2]
        for( int i=3; i<=n; i++ ){
            int tmp = a+b;
            a = b;
            b = tmp%1000000007;
        }
        return b;
    }
};



//=========================================================//
void main_(){

    
    

    debug::log( "\n~~~~ leet: m10_1 :end ~~~~\n" );
}
}//~
