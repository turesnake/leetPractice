/*
 * ====================== leet_872.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.31
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 872. 叶子相似的树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_872 {//~

// 前序列遍历
class S{

    std::stack<TreeNode*> stk1 {};
    std::stack<TreeNode*> stk2 {};

    int findLeaf( std::stack<TreeNode*> &stk ){
        while( !stk.empty() ){
            TreeNode *tp =stk.top();
            stk.pop();
            if( !tp->left && !tp->right ){//leaf
                return tp->val;
            }
            if(tp->left){stk.push(tp->left);}
            if(tp->right){stk.push(tp->right);}
        }
        return -1;//没叶节点了
    }

public:


    bool leafSimilar(TreeNode* root1, TreeNode* root2){

        stk1.push(root1);
        stk2.push(root2);

        while( !stk1.empty() && !stk2.empty() ){
            
            int leaf1 = findLeaf( stk1 );
            int leaf2 = findLeaf( stk2 );
            if( (leaf1==-1 && leaf2!=-1) || 
                (leaf1!=-1 && leaf2==-1) ||
                (leaf1 != leaf2) ){
                return false;
            }
        }
        return true;
    }


};




//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: 872 :end ~~~~\n" );
}
}//~
