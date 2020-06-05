/*
 * ====================== leet_m02_02.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 02.02. 返回倒数第 k 个节点
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m02_02 {//~



// 双指针固定间距法
class S{
public:
    // 参数k一定有效 
    int kthToLast( ListNode* head, int k ){

        ListNode *l = head;
        ListNode *r = l;
        for( int i=0; i<k-1; i++ ){
            r = r->next;
        }
        while(r->next){
            l = l->next;
            r = r->next;
        }
        return l->val;
    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: m02_02 :end ~~~~\n" );
}
}//~
