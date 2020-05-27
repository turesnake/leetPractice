/*
 * ====================== leet_m04_02.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 04.02. 最小高度树
 */
#include "innLeet.h"
#include "TreeNode1.h"




namespace leet_m04_02 {//~



class S{

    std::vector<int>    *numsp {};
    int                 N {};

    TreeNode* work( int l, int r ){
        int mid = l + (r-l)/2;//中间偏左
        TreeNode *p = new TreeNode(numsp->at(mid));
        p->left  = (mid==l) ? nullptr : work(l,mid-1);
        p->right = (mid==r) ? nullptr : work(mid+1,r);
        return p;
    }

public:
    TreeNode* sortedArrayToBST( std::vector<int>& nums ){

        if( nums.empty() ){ return nullptr; }
        numsp = &nums;
        N = static_cast<int>(nums.size());
        return work(0,N-1);
    }

};


//=========================================================//
void main_(){

    std::vector<int> v { -10,-3,0,5,9 };
    //std::vector<int> v { 7,9 };

    
    TreeNode *ret = S{}.sortedArrayToBST( v );

    print_a_tree(ret);
    cout<<endl;
    
    

    debug::log( "\n~~~~ leet: m04_02 :end ~~~~\n" );
}
}//~
