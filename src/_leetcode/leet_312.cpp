/*
 * ====================== leet_312.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 312. 戳气球
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_312 {//~



// dp
// dp[i,j] 表示，戳破开区间(i,j) 中全部元素，累积的值。不包含ij
// 然后，我们要用 k 遍历 (i,j) 中每个元素，分别计算出：
// dp[i,k] + dp[k,j] + [i]*[k]*[j]
// 找出所有可能性中的最大值

// 这个 dp 是非常特殊的，它的 w，h 不再代表 区间首元素 和 区间长度
// 而是 区间首位元素

// 当 j<=i+1; (i,j)区间内是没有元素的，此时 dp[i,j] 为 0



//  5%   100%
class S{

    std::vector<std::vector<int>> dp {};//暂不压缩 
    //[0,N+1]
    int &dp_at( int i, int j ){
        return dp.at(j).at(i);
    }

public:
    // n 个气球，[0,n-1] 
    // 0 ≤ n ≤ 500
    // 0 ≤ nums[i] ≤ 100
    int maxCoins( std::vector<int>& nums ){

        if(nums.empty()){ return 0; }
        int N = static_cast<int>(nums.size());//origin array

        // 准备一个扩大版的 nums，[0],[N+1] 填写 1
        std::vector<int> bNums {1};
        bNums.insert( bNums.end(), nums.begin(), nums.end() );
        bNums.push_back(1);
        // dp //
        dp.resize(N+2, std::vector<int>(N+2, 0));//其实浪费了大量空间，但是暂不管
        // 手动填写 [i,i+2] 区间内只有一个值的
        for( int i=0; i<=N-1; i++ ){// [i],[i+1],[i+2]
            dp_at(i,i+2)= bNums.at(i) * bNums.at(i+1) * bNums.at(i+2);
        }
        // 自动装填 后续层
        // off = j-i
        for( int off=3; off<=N+1; off++ ){//每一组更大的区间
            int lstI = (N+1)-off;

            for( int i=0; i<=lstI; i++ ){// 组内的 每个区间
                int j = i+off;
                int vi = bNums.at(i);
                int vj = bNums.at(j);
                int mmax = 0;
                for( int k=i+1; k<j; k++ ){
                    int sum = dp_at(i,k) + dp_at(k,j) + vi*vj*bNums.at(k);
                    mmax = std::max( mmax, sum );
                }
                dp_at(i,j) = mmax;
            }
        }
            /*
            cout<<"dp: "<<endl;
            for( auto &c : dp ){
                for( int i : c ){ cout<<i<<", "; }cout<<endl; }
            */

        return dp_at(0,N+1);
    }
};



//=========================================================//
void main_(){

    std::vector<int> v { 3,1,5,8 };

    cout<<S{}.maxCoins(v)<<endl;

    

    
    debug::log( "\n~~~~ leet: 312 :end ~~~~\n" );
}
}//~
