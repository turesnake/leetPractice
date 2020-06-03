/*
 * ====================== leet_237.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 237. 删除链表中的节点
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_237 {//~



class S{
public:
    // node 非末尾节点,
    // 意味着 node->next 一定非空
    void deleteNode( ListNode* node ){
        node->val = node->next->val;
        node->next = node->next->next;
    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 237 :end ~~~~\n" );
}
}//~
