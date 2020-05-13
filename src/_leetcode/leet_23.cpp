/*
 * ====================== leet_23.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.03
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 合并K个排序链表
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_23 {//~





ListNode* mergeKLists( std::vector<ListNode*>& lists ){

    using PR = std::pair<int,int>; // <val,vecIdx>
    std::priority_queue<PR, std::vector<PR>, std::greater<PR>> heap {};

    ListNode *p = new ListNode(0);
    ListNode *head {p};
    for( int i=0; i<static_cast<int>(lists.size()); i++ ){
        ListNode *tempP = lists.at(i);
        if( tempP ){
            heap.emplace( tempP->val, i );
        }
    }
    while( !heap.empty() ){
        int val = heap.top().first;
        int vecIdx = heap.top().second;

        p->next = new ListNode(val);
        p = p->next;
        heap.pop();

        ListNode **topPP = &lists.at(vecIdx);
        *topPP = (*topPP)->next;
        if( *topPP ){
            heap.emplace( (*topPP)->val, vecIdx );
        }
    }
    return head->next;
}



//=========================================================//
void main_(){

    ListNode *l1 = create_list({ 1,4,5 });
    ListNode *l2 = create_list({ 1,3,4 });
    ListNode *l3 = create_list({ 2,6 });

    std::vector<ListNode*> v {  nullptr };
    ListNode *ret = mergeKLists( v );

    print_list( ret, "mergeTwoLists:  " );


    debug::log( "\n~~~~ leet: 23 :end ~~~~\n" );
}
}//~
