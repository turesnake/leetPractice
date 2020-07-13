/*
 * ====================== leet_1063.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.13
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1063. 有效子数组的数目
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1063 {//~

// dp 思路
// 传统的 二维dp题，思路上有点类似 回文题
// 每个格子，都记录自己 是否成立
// 然后用一个 sum 来统计个数

// 唯一的问题是，元素个数最大有 5万个， dp数组 可能有 25亿个元素的 规模
// 会引发 时间/内存 超量

//    果断超时
class S{
public:
    // 1 <= A.length <= 50000
    // 0 <= A[i] <= 100000
    int validSubarrays( std::vector<int>& nums ){

        int N = static_cast<int>(nums.size());
        std::vector<std::vector<char>> dp (N+1, std::vector<char>(N,0));
        // 0:非 1:是
        int sum = 0;

        // dp[1][w]
        for( int w=0; w<N; w++ ){
            dp[1][w] = 1;
        }
        sum += N;

        // dp[h][w], h>=2
        for( int h=2; h<=N; h++ ){
            for( int w=0; w<=N-h; w++ ){

                int r=w+1;
                for(; r<w+h; ){
                    if( nums[r]<nums[w] ){ break; }// 不合格
                    int len=w+h-r;
                    for(;  len>=1 && dp[len][r]==0; len-- ){}// 最差，len 会等于 1
                    r += len;
                }
                dp[h][w] = r==w+h ? 1 : 0;
                sum += dp[h][w];
            }
        }
        return sum;


    }
};


//  单调栈 思路
//  以单调栈 的角度看，这题反而很简单

//   43%   100%
class S2{
public:
    // 1 <= A.length <= 50000
    // 0 <= A[i] <= 100000
    int validSubarrays( std::vector<int>& nums ){

        int N = static_cast<int>(nums.size());

        std::vector<int> stk {};// idx
        stk.push_back( N-1 );

        int sum {1};// dp[N-1]

        for( int i=N-2; i>=0; i-- ){

            int r=N;
            int Ns = static_cast<int>(stk.size());
            for( int k=Ns-1; k>=0; k-- ){
                if( nums[stk[k]] < nums[i] ){
                    r = stk[k];
                    break;
                }
            }
            sum += r-i;

            //=== 将本回合元素idx，压入stk ===//
            while( !stk.empty() && nums[stk.back()]>=nums[i] ){
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return sum;


    }
};




//=========================================================//
void main_(){

    std::vector<int> v { 1,4,2,5,3 };

    auto ret = S2{}.validSubarrays(v);

    cout<<"ret:"<<ret<<endl;




    debug::log( "\n~~~~ leet: 1063 :end ~~~~\n" );
}
}//~
