/*
 * ====================== leet_543.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 543. 二叉树的直径
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_543 {//~


// ===== 1 =====
// 依次计算出每个 节点树中，最长路径，收集起来。
// 同时递归返回 本节点树的最大深度
// 会重复计算很多次，效率不高
int doo( TreeNode* root, int &mmax_ ) {
    if( !root->left && !root->right ){  return 1; }
    int l {0};
    int r {0};
    if( root->left ){  l = doo(root->left, mmax_); }
    if( root->right ){ r = doo(root->right, mmax_); }
    mmax_ = std::max( mmax_, l+r );
    return std::max(l,r)+1;
}
int diameterOfBinaryTree( TreeNode* root ) {
    if( !root ){ return 0; }
    if( !root->left && !root->right ){ return 0; }
    int mmax {0};
    doo( root, mmax );
    return mmax;
}




//=========================================================//
void main_(){

    int Nil {INT_MIN};

    std::vector<int> inputs { 1,2,3,4 };
    //std::vector<int> inputs { 1,2,3,4,5 };
    //std::vector<int> inputs { 1,2,3,4,5,Nil,Nil,8,9,10,11,Nil,Nil,Nil,Nil,16 };
    TreeNode *treeRoot = create_a_tree( inputs );
    //TreeNode *treeRoot = nullptr;
    print_a_tree( treeRoot );
    cout << endl;

    //---
    auto ret = diameterOfBinaryTree( treeRoot );
    cout << "ret = " << ret << endl;
    

    debug::log( "\n~~~~ leet: 543 :end ~~~~\n" );
}
}//~
