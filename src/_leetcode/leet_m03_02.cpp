/*
 * ====================== leet_m03_02.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.31
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 03.02. 栈的最小值
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m03_02 {//~


// 32%, 100%
class MinStack {
    std::stack<int> base {};
    std::stack<int> mins {};
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        base.push(x);
        if( mins.empty() ){
            mins.push(x);
        }else{
            if( x <= mins.top() ){ mins.push(x); }
        }
    }
    
    void pop() {
        int v = base.top();
        base.pop();
        if( mins.top()==v ){ mins.pop(); }
    }
    
    int top() {
        return base.top();
    }
    
    int getMin() {
        return mins.top();
    }
};




//=========================================================//
void main_(){


    

    debug::log( "\n~~~~ leet: m03_02 :end ~~~~\n" );
}
}//~
