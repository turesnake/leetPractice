/*
 * ====================== leet_1290.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1290
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1290 {//~


// 100%, 89%
class S{
public:
    // 链表非空
    int getDecimalValue( ListNode* head){

        std::deque<int> que {};
        while( head ){
            que.push_back( head->val );
            head = head->next;
        }
        int out = 0;
        for( ; !que.empty(); que.pop_front() ){
            out = (out<<1) + que.front();
        }
        return out;
    }
};



//=========================================================//
void main_(){

    ListNode *l = create_list({ 1,0,1 });

    cout<< S{}.getDecimalValue(l)<<endl;

    debug::log( "\n~~~~ leet: 1290 :end ~~~~\n" );
}
}//~
