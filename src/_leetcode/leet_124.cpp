/*
 * ====================== leet_124.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.10
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 124. 二叉树中的最大路径和
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_124 {//~


// 因为有负数的存在，实际要检测的情况 非常复杂，很容易出错 


// 后序遍历 49%  7%
class S{

    int maxSum {INT_MIN};

    // tp not null
    // ret: 包含自身节点的 最大单路径和
    int work( TreeNode *tp ){
        int tpVal = tp->val;

        if( !tp->left && !tp->right ){// leaf
            maxSum = std::max(maxSum, tpVal);
            return tpVal;
        }// 以下情况，must not leaf

        int vl = tp->left ? work(tp->left) : INT_MIN;
        int vr = tp->right ? work(tp->right) : INT_MIN;
        int bigSon = std::max(vl,vr);

        //== 本树内，路径最大和，不用考虑向上传递 ==//
        int innSum {0};
        if(tpVal>=0){
            innSum = tpVal;
            if(vl>0){ innSum += vl; }
            if(vr>0){ innSum += vr; }
        }else{// 自己就是 负数
            if( bigSon < 0 ){
                // 说明， tpVal, vl,vr 都是负数，选最大的就行
                innSum = std::max(tpVal, bigSon);
            }else{
                // 说明 vl,vr 至少有一个值 大于等于 0
                // 最大链，要么是包含 tpVal 的大链，要么是 不含 tpVal 的小链
                int all = tpVal;
                if(tp->left){  all+=vl; }
                if(tp->right){ all+=vr; }
                innSum = std::max( bigSon, all );
            }
        }
        maxSum = std::max( maxSum, innSum ); // 登记

        //== 需要传递给上级的单链 ==//
        // 不管 tpVal 是否为正，都要包含
        // 但不一定要包含 叶子链
        return bigSon>0 ? (tpVal+bigSon) : tpVal;
    }

public:

    // root not null
    int maxPathSum( TreeNode* root ){

        work(root);
        return maxSum;
    }
};




//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 124 :end ~~~~\n" );
}
}//~
