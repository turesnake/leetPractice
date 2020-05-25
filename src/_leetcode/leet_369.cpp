/*
 * ====================== leet_369.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 369. 给单链表加一
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_369 {//~


// 递归调用，如果要进位，返回 1
int work( ListNode* head ){
    if( !head ){ return 1; }
    int sum = head->val + work(head->next);
    head->val = sum%10;
    return (sum>9) ? 1 : 0;
}



ListNode* plusOne( ListNode* head ){
    int isCarry = work(head);
    if( isCarry>0 ){
        ListNode *root = new ListNode (1);
        root->next = head;
        return root;
    }else{
        return head;
    }
}



//=========================================================//
void main_(){

    ListNode *l = create_list( { 9,6,9 } );
    print_list( l, "before" );


    ListNode *ret = plusOne( l );
    print_list( ret, "ret" );
    
    


    debug::log( "\n~~~~ leet: 369 :end ~~~~\n" );
}
}//~
