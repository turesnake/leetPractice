/*
 * ====================== leet_110.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 110 平衡二叉树
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_110 {//~


// <deep, isBalanced>
std::pair<int,bool> check( TreeNode* root ) {

    if( !root ){ return { 0, true };}

    std::pair<int,bool> ld { 0, true };
    std::pair<int,bool> rd { 0, true };
    if( root->left ){ ld = check( root->left ); }
    if( root->right ){ rd = check( root->right ); }

    return std::pair<int,bool>{
        std::max(ld.first,rd.first)+1,
        ld.second && rd.second && (std::abs(ld.first-rd.first)<=1)
    };
}


// check 的精简版
// return: deep
// -1 表示 找到 不平衡
int check2( TreeNode* root ) {
    if( !root ){ return 0; }
    int ld {0};
    int rd {0};
    if( root->left ){ ld=check2(root->left); }
    if( root->right ){ rd=check2(root->right); }
    return ((ld==-1) || (rd==-1) || (std::abs(ld-rd)>1)) ? 
        -1 : std::max(ld,rd)+1;
}



bool isBalanced( TreeNode* root ) {   
    if( (!root) ||
        (root && !root->left && !root->right) ){
        return true;
    }
    return check2(root)!=-1;
}






//=========================================================//
void main_(){

    int Nil {INT_MIN};
    std::vector<int> inputs { 3,9,20,Nil,Nil,15,7 };
    //std::vector<int> inputs { 1,2,2,3,3,Nil,Nil,4,4 };


    TreeNode *treeRoot = create_a_tree( inputs );
    print_a_tree( treeRoot );
    cout << endl;


    auto isB = isBalanced( treeRoot );
    debug::log( "ret = {}", isB );


    debug::log( "\n~~~~ leet: 110 :end ~~~~\n" );
}
}//~
