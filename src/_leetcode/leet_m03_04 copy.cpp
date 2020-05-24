/*
 * ====================== leet_m03_04.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.24
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"


namespace leet_m03_04 {//~


class MyQueue {

    std::stack<int> stk1 {}; // <-
    std::stack<int> stk2 {}; // ->

public:

    /** Initialize your data structure here. */
    MyQueue() {}
    
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
                stk2.push( stk1.top() );
                stk1.pop();
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

    MyQueue q {};

    q.push(1);
    q.push(2);
    cout << q.peek() << endl;
    q.pop();
    cout << q.empty() << endl;


    
  
    


    debug::log( "\n~~~~ leet: m03_04 :end ~~~~\n" );
}
}//~
