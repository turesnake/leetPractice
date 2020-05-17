/*
 * ====================== leet_m25.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题25. 合并两个排序的链表
 * 与 21 题相同
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_m25 {//~


// 效率很低，重新生成每个 node
ListNode* mergeTwoLists_1( ListNode* l1, ListNode* l2 ) {

    if( !l1 && !l2 ){ return nullptr; }
    if( !l1 ){ return l2; }
    if( !l2 ){ return l1; }

    ListNode *p = new ListNode(0);
    ListNode *root  = p;
    while( l1 && l2 ){
        if(l1->val <= l2->val){
            p->next = new ListNode( l1->val );
            l1 = l1->next;
        }else{
            p->next = new ListNode( l2->val );
            l2 = l2->next;
        }
        p = p->next;
    }
    if( !l1 && l2 ){ p->next = l2; }
    if( !l2 && l1 ){ p->next = l1; }
    return root->next;
}


// 几乎不生成 新node
ListNode* mergeTwoLists_2( ListNode* l1, ListNode* l2 ) {

    ListNode *p = new ListNode (0);
    ListNode *root  = p;

    while( l1 && l2 ){
        if(l1->val <= l2->val){
            p->next = l1;
            l1 = l1->next;
        }else{
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if( !l1 && l2 ){ p->next = l2; }
    if( !l2 && l1 ){ p->next = l1; }
    return root->next;
}




//=========================================================//
void main_(){

    ListNode *l1 = create_list( {  } );
    print_list( l1, "l1: " );
    ListNode *l2 = create_list( { 3,6,7 } );
    print_list( l2, "l2: " );

    ListNode *ret = mergeTwoLists_2( l1, l2 );
    print_list( ret, "ret: " ); 


    debug::log( "\n~~~~ leet: m25 :end ~~~~\n" );
}
}//~
