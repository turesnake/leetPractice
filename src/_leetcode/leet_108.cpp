/*
 * ====================== leet_108.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 108. 将有序数组转换为二叉搜索树
 */
#include "innLeet.h"
#include "TreeNode1.h"



namespace leet_108 {//~





// 递归实现 37%, 24%
class S{

    std::vector<int> *numsp {};
    int             N {};

    TreeNode *work( int l, int r ){
        int mid = l + (r-l)/2; //mid-left
        TreeNode *tp = new TreeNode(numsp->at(mid));
        tp->left =  (mid==l) ? nullptr : work(l,mid-1);
        tp->right = (mid==r) ? nullptr : work(mid+1,r);
        return tp;
    }

public:

    TreeNode* sortedArrayToBST( std::vector<int>& nums ){
        if( nums.empty() ){ return nullptr; }
        numsp = &nums;
        N = static_cast<int>(nums.size());
        return work(0, N-1);
    }

};


// 迭代实现 37%, 24%
class S2{

    struct Elem{
        Elem()=default;
        TreeNode    **pparent {};
        int         l {};
        int         r {};
    };

public:

    TreeNode* sortedArrayToBST( std::vector<int>& nums ){

        if( nums.empty() ){ return nullptr; }
        int N = static_cast<int>(nums.size());

        TreeNode *root {};
        std::deque<Elem> que {};
        que.push_back( Elem{&root,0,N-1} );

        while( !que.empty() ){
            auto [tpp,l,r] = que.front();
            que.pop_front();

            int mid = l+(r-l)/2;//mid-left

            *tpp = new TreeNode (nums.at(mid));
            if(mid==l){ (*tpp)->left = nullptr;
            }else{      que.push_back( Elem{ &((*tpp)->left), l, mid-1 } ); }
            if(mid==r){ (*tpp)->right = nullptr;
            }else{      que.push_back( Elem{ &((*tpp)->right), mid+1, r } );    }
        }
        return root;
    }

};




//=========================================================//
void main_(){

    std::vector<int> v { -10,-3,0,5,9 };

    TreeNode *ret = S2{}.sortedArrayToBST(v);
    print_a_tree( ret );
    cout << endl;
    
    

    debug::log( "\n~~~~ leet: 108 :end ~~~~\n" );
}
}//~
