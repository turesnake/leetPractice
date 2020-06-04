/*
 * ====================== leet_83.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 83. 删除排序链表中的重复元素
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_83 {//~


// 51%, 100%
// 链表本身是排序的，只要记住上一个值即可 
class S{
public:
    ListNode* deleteDuplicates( ListNode* head ){

        ListNode *sentry = new ListNode(0);
        ListNode *p = sentry;
        p->next = head;
        bool isFst {true};
        int  lstVal {};
        while( p->next ){
            if( isFst ){
                isFst = false;
                lstVal = p->next->val;
                p = p->next;
                continue;
            }
            if( p->next->val == lstVal ){
                // 删除 p->next
                p->next = p->next->next;//maybe null
            }else{
                lstVal = p->next->val;
                p = p->next;
            }
        }
        return sentry->next;
    }
};



//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 83 :end ~~~~\n" );
}
}//~
