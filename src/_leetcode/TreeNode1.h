/*
 * ========================= TreeNode1.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * TreeNode 1
 */
#ifndef TPR_TREE_NODE_1_H
#define TPR_TREE_NODE_1_H

#include "innLeet.h"
#include <stack>


#include <iostream>
using std::cout;
using std::endl;



struct TreeNode{
    explicit TreeNode(int x_) : val(x_),left(nullptr),right(nullptr){}
    //--
    int val;
    TreeNode *left;
    TreeNode *right;
};

constexpr int niln = INT_MIN; // null 节点


// 空节点标记为 INT_MIN 
inline TreeNode *create_a_tree( std::vector<int> v_ ){

    if( v_.empty() ){ return nullptr; }
    TreeNode *sentry = new TreeNode(0);// root = sentry->right
    std::stack<int> roads {};// 1=left, 2=right

    for( int i=0; i<static_cast<int>(v_.size()); i++ ){
        if( v_.at(i) == INT_MIN ){ continue; }
        int treeIdx = i+1;// 数组中 0 号，二叉树中的 1 号
        // build roads
        while( treeIdx > 0 ){   
            (treeIdx == (treeIdx/2*2)) ? roads.push(1) : roads.push(2);
            treeIdx /= 2;
        }
        // use roads find parents
        TreeNode *p {sentry};
        while( roads.size() > 1 ){
            ( roads.top() == 1 ) ? p=p->left : p=p->right;
            roads.pop();
        }
        // now, p is parent
        if( roads.top() == 1 ){
            tprAssert( !(p->left) );
            p->left = new TreeNode( v_.at(i) );
        }else{
            tprAssert( !(p->right) );
            p->right = new TreeNode( v_.at(i) );
        }
        roads.pop(); // last one
        tprAssert( roads.empty() );
    }
    return sentry->right;
}


// 显示一棵树的层次关系
inline void print_a_tree( TreeNode *tree_ ){
    if( !tree_ ){ return; }
    if( tree_->left ){
        cout << "{";
        print_a_tree( tree_->left );
    }
    cout << tree_->val << ", ";
    if( tree_->right ){
        print_a_tree( tree_->right );
        cout << "}";
    }
}


// 遍历一棵树，生成符合输出要求的 指针数组
inline std::vector<TreeNode*> tree_2_vector( TreeNode *root ){

    std::vector<TreeNode*> out {};
    std::deque<TreeNode*> que {};
    que.push_back( root );

    while( !que.empty() ){
        TreeNode *p = que.front();
        que.pop_front();
        if( !p ){
            //if( out.back()!=nullptr ){ out.push_back(nullptr); }//只需要一个 nullptr
            // 先无脑清理掉所有 尾部的 nullptr
            //while( !out.empty() && out.back()==nullptr ){
            //    out.pop_back(); 
            //}
            out.push_back(nullptr); // 再添加唯一的一个 nullptr
                // 目前为止，这是符合 leetcode 题目中 示范的打印效果 ...
            continue;
        }
        out.push_back( p );
        que.push_back( p->left );  // maybe nullptr
        que.push_back( p->right ); // maybe nullptr
    }
    while( !out.empty() && out.back()==nullptr ){ 
        out.pop_back(); 
    }
    return out;
}







#endif 
