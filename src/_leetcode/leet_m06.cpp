/*
 * ====================== leet_m06.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题06. 从尾到头打印链表
 */
#include "innLeet.h"
#include "ListNode.h"




namespace leet_m06 {//~



std::vector<int> reversePrint( ListNode* head ){

    std::stack<int> stk {};
    while( head ){
        stk.push(head->val);
        head=head->next;
    }
    std::vector<int> outs {};
    while( !stk.empty() ){
        outs.push_back( stk.top() );
        stk.pop();
    }
    return outs;
}






//=========================================================//
void main_(){

    ListNode *l = create_list( { 1 } );

    auto ret = reversePrint( l );
    for( int i : ret ){
        cout <<i<<", ";
    }
    cout<<endl;
    

    debug::log( "\n~~~~ leet: m06 :end ~~~~\n" );
}
}//~
