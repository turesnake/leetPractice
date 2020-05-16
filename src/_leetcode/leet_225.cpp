/*
 * ====================== leet_225.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 225. 用队列实现栈
 */
#include "innLeet.h"


namespace leet_225 {//~


// 无脑题
class MyStack {
    std::deque<int> que {};
public:
    /** Initialize your data structure here. */
    MyStack(){}
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int v = que.back();
        que.pop_back();
        return v;
    }
    
    /** Get the top element. */
    int top() {
        return que.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};





//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 225 :end ~~~~\n" );
}
}//~
