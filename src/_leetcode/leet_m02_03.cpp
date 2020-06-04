/*
 * ====================== leet_m02_03.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 02.03. 删除中间节点
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m02_03 {//~


// 66%, 100%
class S{
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};





//=========================================================//
void main_(){
    
    debug::log( "\n~~~~ leet: m02_03 :end ~~~~\n" );
}
}//~
