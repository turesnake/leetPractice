/*
 * ====================== leet_141.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 141. 环形链表
 */
#include "innLeet.h"

#include "ListNode.h"


namespace leet_141 {//~



// 哈希表存储法
bool hasCycle( ListNode *head ) {
        
    std::unordered_set<ListNode*> ptrs {};

    while( head ){
        if( ptrs.find(head) != ptrs.end() ){
            return true;
        }
        ptrs.insert( head );
        head = head->next;
    }
    return false;
}



// 快慢指针
bool hasCycle_2( ListNode *head ) {

    ListNode *fast = head;
    ListNode *slow = head;

    while ( fast && fast->next ){
        fast = fast->next->next;
        slow = slow->next;
        if( fast == slow ){
            return true;
        }
    }
    return false;
}





//=========================================================//
void main_(){

    
    ListNode *l1 = create_list({ 3,2,0,-4 });
    ListNode *p3 = get_listNode( l1, 3 );
    p3->next = get_listNode( l1, 1 );

    //bool retBool = hasCycle_2( l1 );
    bool retBool = hasCycle_2( nullptr );

    debug::log( "retBool = {}", retBool );


    debug::log( "\n~~~~ leet: 141 :end ~~~~\n" );
}
}//~

