/*
 * ====================== leet_m28.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.31
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m28 {//~


class S{

    // 允许塞入 nullptr
    std::stack<TreeNode*> stk1 {};//l
    std::stack<TreeNode*> stk2 {};//r

    // 返回值可能为空 
    TreeNode* get_l(){
        TreeNode *tp = stk1.top();
        stk1.pop();
        if( !tp ){ return nullptr; }
        stk1.push(tp->left);
        stk1.push(tp->right);
        return tp;
    }

    TreeNode* get_r(){
        TreeNode *tp = stk2.top();
        stk2.pop();
        if( !tp ){ return nullptr; }
        stk2.push(tp->right);
        stk2.push(tp->left);
        return tp;
    }

    bool isSame( TreeNode *t1, TreeNode *t2 ){
        if( !t1 && !t2 ){ return true; }
        if( (!t1 && t2) ||
            (t1 && !t2) ||
            (t1->val!=t2->val) ){ return false; }
        return true;
    }



public:

    bool isSymmetric(TreeNode* root) {
        if( !root ){ return true; }
        if( (!root->left && root->right) || 
            (root->left && !root->right) ){ return false; }
        // left/right 一定非空了
        stk1.push(root->left);
        stk2.push(root->right);
        while( !stk1.empty() && !stk2.empty() ){
            TreeNode *l = get_l();
            TreeNode *r = get_r();
            if( !isSame(l,r) ){ return false; }
        }
        return true;
    }


};






//=========================================================//
void main_(){

    TreeNode *p = create_a_tree({ 1,2,2,3,4,1,3 });

    cout<<"ret: " << S{}.isSymmetric(p) <<endl;









    debug::log( "\n~~~~ leet: m28 :end ~~~~\n" );
}
}//~
