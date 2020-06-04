/*
 * ====================== leet_889.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.03
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 889. 根据前序和后序遍历构造二叉树
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_889 {//~


// 递归 88%， 100%
class S{
    std::vector<int> *preP {};
    std::vector<int> *postP {};

    // 区间一定有值，但可以只有 1 个值
    TreeNode *work( int preL, int preR, int postL, int postR ){

        int N = preR - preL +1;
        if(N==1){ return new TreeNode(preP->at(preL)); }//区间只有一个值
        TreeNode *parent = new TreeNode(preP->at(preL));
        int i=postL;
        for( ; i<postR-1; i++ ){
            if( postP->at(i) == preP->at(preL+1) ){
                break;
            }
        }
        int Nl = i-postL+1; // left子区间 元素个数
        int Nr = N-1-Nl;
        if(Nl>0){ parent->left  = work( preL+1, preL+Nl, postL, postL+Nl-1 ); }
        if(Nr>0){ parent->right = work( preR-Nr+1, preR, postL+Nl, postR-1 ); }
        return parent;
    }

public:
    // 参数数组 至少有 一个元素
    TreeNode* constructFromPrePost( std::vector<int>& pre, std::vector<int>& post){

        preP = &pre;
        postP = &post;
        int N = static_cast<int>(pre.size());
        return work( 0, N-1, 0, N-1 );
    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 889 :end ~~~~\n" );
}
}//~
