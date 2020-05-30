/*
 * ====================== leet_106.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 106. 从中序与后序遍历序列构造二叉树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_106 {//~



// 递归 28%, 52%
class S{

    std::vector<int> *inV {nullptr};
    std::vector<int> *postV {nullptr};

    TreeNode *work( int inL, int inR, int postL, int postR ){
        int fstVal = postV->at( postR );//最后一个元素
        TreeNode *root = new TreeNode(fstVal);
        int mid = inL;
        for( ; mid<=inR; mid++ ){
            if( inV->at(mid)==fstVal ){ break; }
        }
        int Nl = mid - inL;
        int Nr = inR - mid;
        if( Nl>0 ){ root->left = work( inL, mid-1, postL, postL+Nl-1 ); }
        if( Nr>0 ){ root->right = work( mid+1, inR, postL+Nl, postR-1 ); }
        return root;
    }

public:
    TreeNode* buildTree( std::vector<int> inorder, std::vector<int> postorder ){
        
        inV = &inorder;
        postV = &postorder;
        int Nin = static_cast<int>(inorder.size());
        int Npost = static_cast<int>(postorder.size());
        if( Nin==0 ){ return nullptr; }
        return work( 0, Nin-1, 0, Npost-1 );
    }
};






//=========================================================//
void main_(){

    TreeNode *ret = S{}.buildTree( {9,3,15,20,7}, {9,15,7,20,3} );

    print_a_tree( ret );

    

    debug::log( "\n~~~~ leet: 106 :end ~~~~\n" );
}
}//~
