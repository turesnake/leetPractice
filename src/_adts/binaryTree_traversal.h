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


//===== 一种统一的，实现 前中后序遍历 的方法 ======//
// 核心思维是，在 stk 中插入 nullptr:
// -1-
// 在一回合中，如果 top 元素 不是 nullptr，说明这个元素并未被 预处理过
// 需要访问它的 左右儿子，并且按照次序，把儿子和自己压入 stk 中
// 因为自己算是被 预处理过了，所以在将本节点 压入stk 中，立刻再压入一个 nullptr
// -2-
// 在一回合中，如果 top 元素是 nullptr
// 说明 后面紧随的是一个 已经被 预处理过的 元素，现在可以正式访问它了
// 在这个回合中，不光要 pop 头部的 nullptr 元素，还要 pop 后面的 被访问元素


// 巧妙的利用 nullptr，来分隔 父层和儿子层，
// 实用一套统一的模版，来实现 迭代版的 前/中/后 序遍历
class S3{
public:

    //----- 前序 -----//
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

    //----- 中序 -----//
    std::vector<int> inorderTraversal( TreeNode* root) {

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


    //----- 后序 -----//
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
