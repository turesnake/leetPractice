/*
 * ====================== leet_105.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 105. 从前序与中序遍历序列构造二叉树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_105 {//~


// 递归 25%， 45%
class S{

    std::vector<int> *preV {nullptr};// 前序数组
    std::vector<int> *inV {nullptr}; // 中序数组

    // 返回子树的 父节点
    TreeNode* work( int preL, int preR, int inL, int inR ){

        int fstVal = preV->at(preL);
        TreeNode *root = new TreeNode(fstVal);
        // 找到 父节点值，在中序遍历中的下标
        int mid = inL;
        for( ; mid<=inR; mid++ ){
            if( inV->at(mid)==fstVal ){ break; }
        }
        int Nl = mid-inL;// left 节点数
        int Nr = inR-mid;// right 节点数
        if( Nl>0 ){ root->left = work( preL+1, preL+Nl, inL, mid-1 ); }
        if( Nr>0 ){ root->right = work( preR-Nr+1, preR, mid+1, inR ); }
        return root;
    }

public:

    TreeNode* buildTree( std::vector<int> preorder, std::vector<int> inorder ){

        preV = &preorder;
        inV = &inorder;
        int Npre = static_cast<int>(preorder.size());
        int Nin = static_cast<int>(inorder.size());
        if( Npre==0 ){ return nullptr; }
        return work( 0, Npre-1, 0, Nin-1 );
    }
};






//=========================================================//
void main_(){

    TreeNode *ret = S{}.buildTree( {}, {} );
    print_a_tree( ret );

    

    debug::log( "\n~~~~ leet: 105 :end ~~~~\n" );
}
}//~
