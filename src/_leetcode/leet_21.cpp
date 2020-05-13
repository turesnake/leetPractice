/*
 * ====================== leet_21.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.03
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 合并两个有序链表
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_21 {//~




ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    if( !l1 && !l2 ){ return nullptr; }
    if( !l1 && l2 ){ return l2; }
    if( l1 && !l2 ){ return l1; }

    ListNode *p = new ListNode(0);
    ListNode *head {p};

    while( l1 && l2 ){
        if( l1->val <= l2->val ){
            p->next = new ListNode ( l1->val );
            p = p->next;
            l1 = l1->next;
        }else{
            p->next = new ListNode ( l2->val );
            p = p->next;
            l2 = l2->next;
        }
    }

    p->next = (!l1) ? l2 : l1;
    return head->next;
}



//=========================================================//
void main_(){

    ListNode *l1 = create_list({ 1,2,4 });
    ListNode *l2 = create_list({ 1,3,4 });

    ListNode *ret = mergeTwoLists( l1, l2 );

    print_list( ret, "mergeTwoLists:  " );



    debug::log( "\n~~~~ leet: 21 :end ~~~~\n" );
}
}//~
