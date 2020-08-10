/*
 * ====================== leet_145.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 145. 二叉树的后序遍历
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_145 {//~


// 递归
class S1{
    std::vector<int> elems {};
public:
    // tp 一定非 nullptr
    void work( TreeNode *tp ){
        if( tp->left  ){ work(tp->left); }
        if( tp->right ){ work(tp->right); }
        elems.push_back( tp->val );
    } 

    std::vector<int> postorderTraversal( TreeNode* root ){
        if( !root ){ return {}; }
        work(root);
        return elems;
    }
};


// 迭代（stack）
// 这个版本实现的并不好，几乎无法实用
class S2{
public:

    std::vector<int> postorderTraversal( TreeNode* root) {

        if( !root ){ return {}; }
        std::vector<int> elems {};
        std::stack<TreeNode*> stk {};
        stk.push( root );
        while( !stk.empty() ){
            TreeNode *tp = stk.top();
            stk.pop();
            elems.push_back(tp->val);
            if( tp->left  ){ stk.push(tp->left); }
            if( tp->right ){ stk.push(tp->right); }
        }
        std::reverse( elems.begin(), elems.end() );
        return elems;
    }
};



// 迭代
// 借助 nullptr 实现的 通用模版
class S3{
public:

    std::vector<int> postorderTraversal( TreeNode* root) {

        if( !root ){ return {}; }
        std::vector<int> elems {};
        std::stack<TreeNode*> stk {};
        stk.push( root );

        while( !stk.empty() ){
            TreeNode *tp = stk.top();
            if( tp==nullptr ){
                stk.pop();
                elems.push_back( stk.top()->val );
                stk.pop();
            }else{
                stk.push(nullptr);
                if(tp->right){stk.push(tp->right);}// lr 倒置
                if(tp->left){stk.push(tp->left);}
            }
        }

        return elems;
    }
};







//=========================================================//
void main_(){

    TreeNode *t = create_a_tree( { 1,2,3,4,5,6,7 } );
    print_a_tree(t);
    cout << "\n======"<<endl;

    auto ret = S1{}.postorderTraversal( t );
    for( int i : ret ){ cout << i << ", "; }
    cout << endl;

    auto ret2 = S3{}.postorderTraversal( t );
    for( int i : ret2 ){ cout << i << ", "; }
    cout << endl;

    

    debug::log( "\n~~~~ leet: 145 :end ~~~~\n" );
}
}//~
