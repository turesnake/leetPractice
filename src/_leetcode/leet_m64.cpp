/*
 * ====================== leet_m64.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题64. 求1+2+…+n
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m64 {//~



// 利用 逻辑运算符的短路特性，来做条件选择 
class S{
public:
    // 1 <= n <= 10000
    int sumNums( int n ){
        n && (n += sumNums(n-1));
        return n;
    }
};



// 还有一个方法是 快速乘
// 待学习...


// 俄罗斯农民乘法
// b 不能为 负数
int product_1( int a, int b ){
    int sum {0};
    for( int i=0; b!=0; i++, b>>=1 ){
        if(b&1){ sum += a<<i; }
    }
    return sum;
}






//=========================================================//
void main_(){

    cout<<"a*b = "<< product_1( 0, 7 ) <<endl;




    debug::log( "\n~~~~ leet: m64 :end ~~~~\n" );
}
}//~
