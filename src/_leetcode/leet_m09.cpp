/*
 * ====================== leet_m09.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题09. 用两个栈实现队列
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_m09 {//~


class CQueue {
    std::stack<int> a {}; // push
    std::stack<int> b {}; // pop
public:


    CQueue() {}
    
    void appendTail(int value) {
        a.push( value );
    }

    
    int deleteHead() {
        if( b.empty() ){
            while( !a.empty() ){
                b.push( a.top() );
                a.pop();
            }
        }
        if( b.empty() ){
            return -1;
        }else{
            int out = b.top();
            b.pop();
            return out;
        }
    }


};








//=========================================================//
void main_(){

    CQueue s {};

    cout << "1: " << s.deleteHead() << endl;

    s.appendTail( 5 );
    s.appendTail( 2 );

    cout << "2: " << s.deleteHead() << endl;

    s.appendTail( 1 );
    s.appendTail( 2 );
    s.appendTail( 3 );
    
    cout << "3: " << s.deleteHead() << endl;
    cout << "4: " << s.deleteHead() << endl;
    cout << "5: " << s.deleteHead() << endl;
    cout << "6: " << s.deleteHead() << endl;
    cout << "7: " << s.deleteHead() << endl;


    debug::log( "\n~~~~ leet: m09 :end ~~~~\n" );
}
}//~
