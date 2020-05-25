/*
 * ====================== leet_654.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 654. 最大二叉树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_654 {//~


// 朴素法 居然优于 dp法


// dp 版，性能不佳 5.13%, 7.69%
// 本题的核心在于，每次针对一个 区间建树，都需要 找到其值最大的元素
// 此方案使用 dp 来优化这个 查找过程 
class S{

    struct Elem{
        Elem()=default;
        int idx {0};
        int val {INT_MIN};
    };

    std::vector<int>                *numsp {nullptr};
    std::vector<std::vector<Elem>>  dp {};

    Elem &dp_at( int idx, int len ){
        return dp.at(len-2).at(idx);
    }

    void dp_resize( int N ){
        dp.resize( N-1 );
        for( int n=2; n<=N; n++ ){
            dp.at(n-2).resize( N-n+1, Elem{} );
        }
    }


    // 在目标区间内，提取最大值，建立父节点，
    // 子节点是 两侧的小区间
    TreeNode *work( int idx, int len ){
        if( len==0 ){ return nullptr; }
        if( len==1 ){ return new TreeNode ( numsp->at(idx) ); }// 叶节点
        // >=2
        auto &elem = dp_at(idx,len);
        TreeNode *t = new TreeNode (elem.val);
        t->left = work( idx, elem.idx-idx );
        t->right = work( elem.idx+1, idx+len-(elem.idx+1) );
        return t;
    }


public:


    TreeNode* constructMaximumBinaryTree( std::vector<int>& nums ){

        numsp = &nums;
        int N = static_cast<int>(nums.size());
        dp_resize( N );

        // 手动生成 dp[2] 数据
        int n = 2;
        for( int i=0; i<N-n+1; i++ ){// dp[2] 层每个元素
            if( nums.at(i) >= nums.at(i+1) ){
                dp_at(i,n).val = nums.at(i);
                dp_at(i,n).idx = i;
            }else{
                dp_at(i,n).val = nums.at(i+1);
                dp_at(i,n).idx = i+1;
            }
        }
        // 剩余 dp 数据
        for( n=3; n<=N; n++ ){ // dp[n]
            for( int i=0; i<N-n+1; i++ ){// dp[n][i]
                if( dp_at(i,n-1).val >= nums.at(i+n-1) ){
                    dp_at(i,n) = dp_at(i,n-1);
                }else{
                    dp_at(i,n).val = nums.at(i+n-1);
                    dp_at(i,n).idx = i+n-1;
                }
            }
        }

                cout << "dp:"<< endl;
                for( auto &c : dp ){
                    for( auto i : c ){ cout << i.idx << ":" << i.val << ", "; }
                    cout << endl;
                }cout << "===" << endl;

        return work( 0, N );
    }



};



// 49.44%, 7.69%
// 尝试朴素搜索法
class S2{
    std::vector<int>                *numsp {nullptr};
    // 在目标区间内，提取最大值，建立父节点，
    // 子节点是 两侧的小区间
    TreeNode *work( int idx, int len ){
        if( len==0 ){ return nullptr; }
        if( len==1 ){ return new TreeNode ( numsp->at(idx) ); }// 叶节点
        // >=2
        // 使用朴素方法，找到 区间 最大值
        int maxVal {INT_MIN};
        int maxIdx {0};
        for( int i=idx; i<idx+len; i++ ){
            int v = numsp->at(i);
            if( v > maxVal ){
                maxVal = v;
                maxIdx = i;
            }
        }
        TreeNode *t = new TreeNode (maxVal);
        t->left = work( idx, maxIdx-idx );
        t->right = work( maxIdx+1, idx+len-(maxIdx+1) );
        return t;
    }

public:

    TreeNode* constructMaximumBinaryTree( std::vector<int>& nums ){
        numsp = &nums;
        return work( 0, static_cast<int>(nums.size()) );
    }
};



//=========================================================//
void main_(){

    std::vector<int> v { 3,2,1,6,0,5 };
    //std::vector<int> v { -23,-2 };


    TreeNode *ret = S2{}.constructMaximumBinaryTree(v);
    print_a_tree( ret );
    cout<<endl;

    auto ret2 = tree_2_vector(ret);
    for( TreeNode *p : ret2 ){
        if( !p ){
            cout << "null, ";
        }else{
            cout << p->val << ",";
        }
    }
    cout << endl;
    

    
    



    debug::log( "\n~~~~ leet: 654 :end ~~~~\n" );
}
}//~
