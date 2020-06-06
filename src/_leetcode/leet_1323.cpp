/*
 * ====================== leet_1323.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1323. 6 和 9 组成的最大数字
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1323 {//~


// 100% 100%
class S{
public:
    // 1 <= num <= 10^4
    int maximum69Number (int num) {
        std::stack<int> stk {};
        for( ; num>0; num/=10 ){
            stk.push( num%10 );
        }
        int out = 0;
        bool isFind {false};
        for( ; !stk.empty(); stk.pop() ){
            int val {};
            if( !isFind && stk.top()==6 ){
                val = 9;
                isFind = true;
            }else{
                val = stk.top();
            }
            out = out*10 + val;
        }
        return out;
    }
};



//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 1323 :end ~~~~\n" );
}
}//~
