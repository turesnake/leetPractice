/*
 * ====================== leet_m02_01.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 02.01. 移除重复节点
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m02_01 {//~


// 后移指针:      p = p->next;
// 删除下一个指针: p->next = p->next->next;
class S{
public:
    // 链表长度在[0, 20000]范围内
    // 链表元素在[0, 20000]范围内
    ListNode* removeDuplicateNodes( ListNode* head ){

        std::unordered_set<int> uset {};
        ListNode *root = new ListNode(0);
        root->next = head;
        ListNode *p = root;
        while( p->next ){
            int v = p->next->val;
            if( uset.count(v) == 0 ){
                uset.insert(v);
                p = p->next; // 后移
            }else{
                p->next = p->next->next; // 删除
            }
        }
        return root->next;
        

    }
};





//=========================================================//
void main_(){

    ListNode *l = create_list({ 1,2,3,3,2,1 });




    
    debug::log( "\n~~~~ leet: m02_01 :end ~~~~\n" );
}
}//~
