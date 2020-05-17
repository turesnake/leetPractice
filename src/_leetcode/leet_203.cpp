/*
 * ====================== leet_203.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 203. 移除链表元素
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_203 {//~




ListNode* removeElements_2( ListNode* head, int val ){

    ListNode *root = new ListNode (0);
    ListNode *p = root;
    p->next = head;
    while( p->next ){
        (p->next->val == val) ?
            p->next = p->next->next :
            p = p->next;
    }    
    return root->next;
}





//=========================================================//
void main_(){

    ListNode *l1 = create_list( { 6,1 } );
    print_list( l1, "l1 " );

    ListNode *ret = removeElements_2( l1, 6 );
    //ListNode *ret = delSecond( l1 );
    print_list( ret, "ret " );

    

    debug::log( "\n~~~~ leet: 203 :end ~~~~\n" );
}
}//~

