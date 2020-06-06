/*
 * ====================== leet_m02_07.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 02.07. 链表相交
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m02_07 {//~


// 与 160 题相同 

class S{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){

        // 下方这个写法 和 160 题略微不一样 

        if( !headA || !headB ){ return nullptr; }
        ListNode *a = headA;
        ListNode *b = headB;
        if( a==b ){ return a; }
        while( a->next || b->next ){
            a = a->next ? a->next : headB;
            b = b->next ? b->next : headA;
            if( a==b ){ return a; }
        }
        return nullptr;
    }
};



//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: m02_07 :end ~~~~\n" );
}
}//~
