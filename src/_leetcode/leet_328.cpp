/*
 * ====================== leet_328.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 328. 奇偶链表
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_328 {//~


// 双链表收集元素。最后合并 91%， 68%
class S{
public:
    ListNode* oddEvenList( ListNode* head ){

        if(!head){ return nullptr; }

        ListNode *odd = new ListNode(0);
        ListNode *eve = new ListNode(0);
        ListNode *op = odd;
        ListNode *ep = eve;
        for( int i=1; head; i++,head=head->next ){
            if( (i&1)==0 ){//eve
                ep->next = head;
                ep = ep->next;
            }else{//odd
                op->next = head;
                op = op->next;
            }
        }
        op->next = eve->next;
        ep->next = nullptr;
        return odd->next; 
    }
};





//=========================================================//
void main_(){

    ListNode *l = create_list({ 2,1,4,3,6,5 });

    ListNode *ret = S{}.oddEvenList(l);
    print_list(ret,"KK");   

    
    debug::log( "\n~~~~ leet: 328 :end ~~~~\n" );
}
}//~
