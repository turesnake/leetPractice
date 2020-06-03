/*
 * ====================== leet_m08_05.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 08.05. 递归乘法
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m08_05 {//~


// 俄国农民乘法 
class S{
public:
    // 两个正整数
    int multiply(int A, int B) {
        if( B==0 ){ return 0; }
        int v = (B&1) ? A : 0;
        return v + multiply( A<<1, B>>1 );
    }
};



//=========================================================//
void main_(){

    cout << S{}.multiply( 17, 33 ) <<endl;
    
    debug::log( "\n~~~~ leet: m08_05 :end ~~~~\n" );
}
}//~
