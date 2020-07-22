/*
 * ====================== leet_m03_05.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.22
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 03.05. 栈排序
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m03_05 {//~


// right 优先拥有元素，如果 right 无元素，那么  


//  96%  100%
class SortedStack {

    std::stack<int> left {};
    std::stack<int> right {};

public:
    SortedStack() {
    }
    
    void push(int val) {

        if( right.empty() ){// 全空
            right.push(val);
        }else{
            if( val > right.top() ){
                while( !right.empty() && right.top()<val ){
                    left.push(right.top());
                    right.pop();
                }
                right.push( val );
            }else if( val == right.top() ){
                right.push( val );
            }else{
                while( !left.empty() && left.top()>val ){
                    right.push( left.top() );
                    left.pop();
                }
                right.push(val);
            }
        }

    }
    
    void pop(){

        while( !left.empty() ){
            right.push( left.top() );
            left.pop();
        }
        if( !right.empty() ){
            right.pop();
        }
        
    }
    
    int peek() {

        if( right.empty() ){ return -1; }
        while( !left.empty() ){
            right.push( left.top() );
            left.pop();
        }
        return right.top();

    }
    
    bool isEmpty() {
        return right.empty();

    }
};


//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: m03_05 :end ~~~~\n" );
}
}//~
