/*
 * ====================== leet_206.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.01.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 206. 反转链表  
 */
#include "innLeet.h"

#include "ListNode.h"


namespace leet_206 {//~




ListNode* reverseList(ListNode* head) {

    if( (!head) || (!head->next) ){
        return head;
    }

    ListNode *retP = reverseList( head->next );

    head->next->next = head;
    head->next = nullptr;

    return retP;
}




ListNode* reverseList2(ListNode* head) {

    if( (!head) || (!head->next) ){
        return head;
    }

    std::deque<ListNode*> que {};

    ListNode *p = head;
    
    while( p ){
        que.push_back( p );
        p = p->next;
    }

    ListNode *root = que.back();
    ListNode *f {};

    while( !que.empty() ){

        p = que.back();
        que.pop_back();

        que.empty() ?
            p->next = nullptr :
            p->next = que.back();
    }

    return root;
}




ListNode* reverseList3(ListNode* head) {

    if( (!head) || (!head->next) ){
        return head;
    }

    ListNode *cur   {nullptr};
    ListNode *pre   {head};
    ListNode *tmp   {nullptr};

    while( pre ){
        tmp = pre;
        pre = pre->next;
        //--
        tmp->next = cur;
        cur = tmp; 
    }

    return cur;
}







//=========================================================//
void main_(){


    ListNode *l1 = create_list({ 1,2,3,4,5 });

    print_list( l1, "l1" );

    ListNode *ret = reverseList3( l1 );
    print_list( ret, "ret" );



    debug::log( "\n~~~~ leet :end ~~~~\n" );
}
}//~
