/*
 * ====================== leet_94.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 94. 二叉树的中序遍历
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_94 {//~


// 递归
class S1{
    std::vector<int> elems {};
    // tp 一定非空
    void work( TreeNode *tp ){
        if( tp->left ){ work(tp->left); }
        elems.push_back(tp->val);
        if( tp->right ){ work(tp->right); }
    }
public:
    std::vector<int> inorderTraversal( TreeNode* root ){
        if( !root ){ return {}; }
        work(root);
        return elems;
    }
};



// 迭代 stack
class S2{
public:
    std::vector<int> inorderTraversal( TreeNode* root ){
        
        if( !root ){ return {}; }
        std::vector<int> elems {};
        std::stack<TreeNode*> stk {};
        // 这个过程不好理解...
        TreeNode *ptr = root; 
        while( ptr!=nullptr || !stk.empty() ){
            while( ptr!=nullptr ){
                stk.push(ptr);
                ptr = ptr->left;
            }
            ptr = stk.top();
            stk.pop();
            elems.push_back( ptr->val );
            ptr = ptr->right; // maybe nullptr
        }
        return elems;
    }
};




//=========================================================//
void main_(){

    TreeNode *t = create_a_tree( { 1,2,3,4,5,6,7 } );
    print_a_tree(t);
    cout << "\n======"<<endl;

    auto ret = S2{}.inorderTraversal( t );

    for( int i : ret ){
        cout << i << ", ";
    }
    cout <<endl;
    

    debug::log( "\n~~~~ leet: 94 :end ~~~~\n" );
}
}//~
