/*
 * ====================== leet_298.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 298. 二叉树最长连续序列
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_298 {//~


//  50%  50%
// dfs，然后在叶节点清算
class S{

    int mmax {1};// 至少有一个
    std::vector<int> road {};

    void check(){
        int N = static_cast<int>(road.size());
        if( N <= mmax ){ return; }// too shot
        int l=0;
        int r=0;
        for( int i=1; i<N; i++ ){//[i-1].[i]
            if( road.at(i)-road.at(i-1)==1 ){// 符合
                r = i;
            }else{// 不符合
                mmax = std::max( mmax, r-l+1 );// 清算
                l = i;
                r = i;
            }
        }
        mmax = std::max( mmax, r-l+1 );// 清算
    }

    // tp not null
    void work( TreeNode *tp ){
        road.push_back(tp->val);
        if( !tp->left && !tp->right ){ check(); }//leaf
        if(tp->left){work(tp->left);}
        if(tp->right){work(tp->right);}
        road.pop_back();
    }

public:
    int longestConsecutive( TreeNode* root ){
        if(!root){ return 0; }
        work(root);
        return mmax;
    }
};





//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 298 :end ~~~~\n" );
}
}//~
