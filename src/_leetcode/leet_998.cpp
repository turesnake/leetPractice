/*
 * ====================== leet_998.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 998. 最大二叉树 II
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_998 {//~



class S{
public:
    TreeNode* insertIntoMaxTree( TreeNode* root, int val ){
        if( !root ){ return new TreeNode(val); }
        if( root->val<val ){ 
            TreeNode *newP = new TreeNode(val);
            newP->left = root;// maybe nullptr
            return newP;
        }
        root->right = insertIntoMaxTree(root->right,val);
        return root;
    }
};







//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: 998 :end ~~~~\n" );
}
}//~
