/*
 * ====================== leet_24.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 24. 两两交换链表中的节点
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_24 {//~


// 67%, 100%
class S{

    ListNode *root {};
    ListNode *fp {};
    ListNode *l {};
    ListNode *r {};

    // 一次前进2格
    bool move(){
        if( r->next && r->next->next ){
            r = r->next->next;
            l = l->next->next;
            fp = fp->next->next;
            return true;
        }else{
            return false;
        }
    }

public:
    ListNode* swapPairs( ListNode* head ){
        if( !head || !head->next ){ return head; }//不满2个，不工作
        l = head;
        r = head->next;
        root = new ListNode(0);//sentry
        fp = root;
        fp->next = l;
        do{
            l->next = r->next;
            r->next = l;
            fp->next = r;
            std::swap(l,r);
        }while( move() );
        return root->next;
    }
};



//=========================================================//
void main_(){

    ListNode *l = create_list({ 1,2,3,4 });
    ListNode *ret = S{}.swapPairs(l);
    print_list(ret, "000:");

  
    debug::log( "\n~~~~ leet: 24 :end ~~~~\n" );
}
}//~
