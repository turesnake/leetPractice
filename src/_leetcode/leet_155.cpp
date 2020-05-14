/*
 * ====================== leet_155.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 155. 最小栈
 */
#include "innLeet.h"

#include "ListNode.h"


namespace leet_155 {//~




class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        this->data.push_back( x );
        if( this->mins.empty() ){
            this->mins.push_back(x);
        }else{
            if( x <= this->mins.back() ){
                this->mins.push_back(x);
            }
        }
    }
    
    void pop() {
        if( !this->data.empty() ){
            if( this->top() == this->mins.back() ){
                this->mins.pop_back();
            }
            this->data.pop_back();
        }
    }
    
    int top() {
        assert( !this->data.empty() );
        return this->data.back();
    }
    
    int getMin() {
        assert( !this->mins.empty() );
        return this->mins.back();
    }
private:
    std::deque<int> data {};
    std::deque<int> mins {};
};





//=========================================================//
void main_(){

    MinStack ms {};

    ms.push( -2 );
    ms.push( 0 );
    ms.push( -3 );
    cout << "getMin() = " << ms.getMin() << endl;
    ms.pop();
    cout << "top() = " << ms.top() << endl;
    cout << "getMin() = " << ms.getMin() << endl;
    


    debug::log( "\n~~~~ leet: 155 :end ~~~~\n" );
}
}//~

