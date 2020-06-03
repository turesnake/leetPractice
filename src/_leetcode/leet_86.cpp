/*
 * ====================== leet_86.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.03
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 86. 分隔链表
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_86 {//~


// 94%, 100%
// 用 vector 将 第一个大值后面的 小数，都暂存起来
// 最后再在分界口，填进去
class S{
public:
    ListNode* partition(ListNode* head, int x) {

        if(!head){ return nullptr; }
        std::vector<int> smls {};
        ListNode *root = new ListNode(0);
        ListNode *p = root;
        p->next = head;

        ListNode *targetP {};// 新的节点，查到其 next 处
        bool isFindTarget {false};

        while( p->next ){
            if( !isFindTarget && p->next->val>=x ){ 
                targetP = p; 
                isFindTarget = true;
                p = p->next;
                continue;
            }
            if( isFindTarget && p->next->val<x ){
                smls.push_back(p->next->val);
                // 删除 p->next 节点
                p->next = p->next->next;//maybe null
                continue;
            }
            p = p->next;
        }

        if( isFindTarget && !smls.empty() ){
            int N = static_cast<int>(smls.size());
            ListNode *l = new ListNode(smls.at(0));
            ListNode *r = l;
            for( int i=1; i<N; i++ ){
                r->next = new ListNode(smls.at(i));
                r = r->next;
            }
            r->next = targetP->next;
            targetP->next = l;
        }
        return root->next;
    }
};



// 双哨兵法
// 设置 大/小 两个哨兵，遍历每个元素，重绑到两个链表上
// 最后再整合下 



//=========================================================//
void main_(){

    ListNode *l = create_list({ 1,4 });

    ListNode *ret = S{}.partition( l, 3 );

    print_list( ret, "KKK" );

    
    debug::log( "\n~~~~ leet: 86 :end ~~~~\n" );
}
}//~
