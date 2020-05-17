/*
 * ====================== leet_m24.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题24. 反转链表 
 * 与 206 题相同
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_m24 {//~


// 不够简介的写法
// 用了 3 个指针
ListNode* reverseList( ListNode* head ){

    if( !head || !(head->next) ){ return head; } //null or single
    // 以下至少有 2 个元素
    ListNode *left = head;
    ListNode *right = left->next;
    ListNode *f = nullptr; // future
    while( true ){
        f = right->next;
        right->next = left;
        if( f ){
            left = right;
            right = f;
        }else{
            break;
        }
    }
    head->next = nullptr; // 尾元素指空
    return right;
}



//=========================================================//
void main_(){

    ListNode *l1 = create_list( { 1,2,3,4,5 } );
    print_list( l1, "m24: " );

    ListNode *ret = reverseList( l1 );
    print_list( ret, "ret: " );


    debug::log( "\n~~~~ leet: m24 :end ~~~~\n" );
}
}//~
