/*
 * ====================== leet_232.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.31
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 232. 用栈实现队列
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_232 {//~



class MyQueue {
    std::stack<int> stk1 {};// <-
    std::stack<int> stk2 {};// ->
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int v = peek();
        stk2.pop();
        return v;
    }
    
    /** Get the front element. */
    int peek() {
        if( stk2.empty() ){
            while( !stk1.empty() ){
                int v = stk1.top();
                stk1.pop();
                stk2.push(v);
            }
        }
        return stk2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};





//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: 232 :end ~~~~\n" );
}
}//~
