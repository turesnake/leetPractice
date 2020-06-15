/*
 * ====================== leet_1246.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1246. 删除回文子数组
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1246 {//~


// dp 从小往大，逐个区间计算
// 若区间有1个元素，耗值1，
// 若区间有2个元素，相同则值为1，不同则值为2
// 区间元素超过2个的，要分别考虑2种情况
// -1- 将区间一分为二，用 dp 的方式来统计
// -2- 如果区间头尾元素相同，其值等于 [l+1,r-1] 区间的值


//   5%   100%
class S{

    std::vector<std::vector<int>> dp {};
    // [1，N] -> [0,N-1]
    int &dp_at( int h, int w ){
        return dp.at(h-1).at(w);
    }

public:
    // 1 <= arr.len <= 100
    // 1 <= arr[i] <= 20
    int minimumMoves( std::vector<int>& arr ){

        int N = static_cast<int>(arr.size());
        dp.resize(N, std::vector<int>(N,0));// [0]行空置
        // 亲手生成 [1] 层
        for( int i=0; i<N; i++ ){
            dp_at(1,i)=1;
        }
        // 亲手生成 [2] 层
        for( int i=0; i<N-1; i++ ){//[i],[i+1]
            dp_at(2,i)= arr.at(i)==arr.at(i+1) ? 1 : 2;
        }
        // 自动实现 后面层
        for( int h=3; h<=N+1; h++ ){
            int n = N+1-h;//本层几个区间
            // 本层区间内元素个数为 h 个
            for( int l=0; l<n; l++ ){// 各个区间 [l,l+h-1]
                int r = l+h-1;
                int minSteps = INT_MAX;
                //-1- 将区间 切成 [l,k],[k+1,r] 左右两个区间
                // 所获得的 最佳方案
                for( int k=l; k<r; k++ ){
                    int mmin = dp_at(k-l+1,l) + dp_at(r-k,k+1);
                    minSteps = std::min( minSteps, mmin );
                }
                //-2- 如果 区间首位元素值相同，可以直接等于 去掉头尾元素后区间的值
                if( arr.at(l)==arr.at(r) ){
                    minSteps = std::min( minSteps, dp_at(h-2, l+1) );
                }
                dp_at(h,l) = minSteps;
            }
        }

        /*
        cout<<"dp:"<<endl;
        for( auto &c : dp ){
            for( int i : c ){ cout<<i<<", "; }cout<<endl;
        }
        */

        return dp.back().at(0);
        
    }
};



//=========================================================//
void main_(){

    std::vector<int> v { 1,2 };
    //std::vector<int> v { 1,3,4,1,5 };

    cout<<S{}.minimumMoves(v)<<endl;

    
    debug::log( "\n~~~~ leet: 1246 :end ~~~~\n" );
}
}//~
