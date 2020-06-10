/*
 * ================== binaryTree_traversal.h ==================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 二叉树的 前/中/后 序遍历 [迭代版]
 */
#ifndef TPR_BTREE_TRAVERSAL_H
#define TPR_BTREE_TRAVERSAL_H
#include "pch.h"

#include <stack>

namespace tpr_binaryTree_traversal{//~


// tmp
struct TreeNode{
    explicit TreeNode(int x_) : val(x_),left(nullptr),right(nullptr){}
    //--
    int val;
    TreeNode *left;
    TreeNode *right;
};



// 巧妙的利用 nullptr，来分隔 父层和儿子层，
// 实用一套统一的模版，来实现 迭代版的 前/中/后 序遍历
class S3{
public:

    // 前序
    std::vector<int> preorderTraversal( TreeNode* root) {

        if( !root ){ return {}; }
        std::vector<int> elems {};
        std::stack<TreeNode*> stk {};
        stk.push( root );
        while( !stk.empty() ){
            TreeNode *tp = stk.top();
            stk.pop();
            if( tp==nullptr ){
                // HANDLE
                elems.push_back( stk.top()->val );
                stk.pop();
            }else{
                //-真正与遍历顺序有关的部分-//
                if(tp->right){stk.push(tp->right);} // lr 倒置
                if(tp->left){stk.push(tp->left);}
                stk.push(tp);// 再次压入
                stk.push(nullptr);
            }
        }
        return elems;
    }



    // 中序
    std::vector<int> preorderTraversal( TreeNode* root) {

        if( !root ){ return {}; }
        std::vector<int> elems {};
        std::stack<TreeNode*> stk {};
        stk.push( root );
        while( !stk.empty() ){
            TreeNode *tp = stk.top();
            stk.pop();
            if( tp==nullptr ){
                // HANDLE
                elems.push_back( stk.top()->val );
                stk.pop();
            }else{
                //-真正与遍历顺序有关的部分-//
                if(tp->right){stk.push(tp->right);} // lr 倒置
                stk.push(tp);// 再次压入
                stk.push(nullptr);
                if(tp->left){stk.push(tp->left);}
            }
        }
        return elems;
    }





    // 后序
    std::vector<int> postorderTraversal( TreeNode* root) {

        if( !root ){ return {}; }
        std::vector<int> elems {};
        std::stack<TreeNode*> stk {};
        stk.push( root );
        while( !stk.empty() ){
            TreeNode *tp = stk.top();
            stk.pop();
            if( tp==nullptr ){
                // HANDLE
                elems.push_back( stk.top()->val );
                stk.pop();
            }else{
                //-真正与遍历顺序有关的部分-//
                stk.push(tp);// 再次压入
                stk.push(nullptr);
                if(tp->right){stk.push(tp->right);} // lr 倒置
                if(tp->left){stk.push(tp->left);}
            }
        }
        return elems;
    }
};










}//~
#endif
