/*
 * ====================== leet_230.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 230. 二叉搜索树中第K小的元素
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"

namespace leet_230 {//~





// 中序遍历 36%  5%
// 最朴素的办法，从头开始遍历 
class S{
public:
    // 1 <= k <= tree.size
    int kthSmallest( TreeNode* root, int k ){

        std::stack<TreeNode*> stk {};
        stk.push(root);
        int i=1;

        while( !stk.empty() ){
            TreeNode *node = stk.top();
            stk.pop();
            if( node==nullptr ){
                TreeNode *tp = stk.top();
                stk.pop();
                // HANDLE
                if( i==k ){ return tp->val; }
                i++;
            }else{
                if(node->right){ stk.push(node->right); } // r fst
                stk.push(node);
                stk.push(nullptr);
                if(node->left){ stk.push(node->left); }
            }
        }
        return INT_MIN;//never reach

    }
};





//=========================================================//
void main_(){


    TreeNode *t = create_a_tree({  4,2,6,1,3,5,7 });

    cout<<"ret:"<<S{}.kthSmallest( t, 5 )<<endl;





    debug::log( "\n~~~~ leet: 230 :end ~~~~\n" );
}
}//~
