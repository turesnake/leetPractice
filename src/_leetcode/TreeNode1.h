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



// 空节点标记为 INT_MIN 
inline TreeNode *create_a_tree( std::vector<int> &v_ ){

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








#endif 
