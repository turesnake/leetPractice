/*
 * ====================== leet_876.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 876. 链表的中间结点
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_876 {//~


 

ListNode* middleNode(ListNode* head) {

    ListNode *fast = head;
    ListNode *slow = head;

    while ( fast && fast->next ){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}







//=========================================================//
void main_(){

    ListNode *l1 = create_list({ 1,2,3 });
    //ListNode *l1 = create_list({ 1,2,3,4,5 });

    ListNode *mid = middleNode( l1 );

    print_list( mid, "876List: " );



    debug::log( "\n~~~~ leet: 876 :end ~~~~\n" );
}
}//~

