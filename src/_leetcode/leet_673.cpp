/*
 * ====================== leet_673.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 673. 最长递增子序列的个数
 */
#include "innLeet.h"


namespace leet_673 {//~


// dp[i] 表示，以 a[i] 为最高值的 “最长递增序列” 的:
// -1- len: 最长递增区间的长度
// -2- num: 最长区间个数
// -3- l: 最长区间 left 元素下标（可以计算出，某段区间是否可以直接跳过 ）
// -4- mmin: 前缀最小值。
//           倒序查找时，如果发现没有比自己更小的值了，就不再遍历了
//           而且，由于元素都是整数，甚至可以算出理论最大差值，要是差值太小，也不用遍历了


// 在计算一个 dp 值时，需要向前 倒序遍历，收集所有 值比自己小的 dp[n]
// 在它们的基础上 计算出，累加上 a[i] 后的 新的 区间长度 和个数


// 官方答案也使用了类似的思路: O(N^2)
// 也需要两层遍历，
// 我们的方法额外做了些 减枝操作。


//   84%  16%
class S{

struct Elem{
    int len  {0}; // “最长区间” 长度
    int num  {0}; // “最长区间” 个数
    int l    {0}; // "最长区间" 左端元素 idx
    int mmin {0}; // [0,i] 内最小值
};

public:
    int findNumberOfLIS( std::vector<int>& nums ){

        int N = static_cast<int>(nums.size());
        if( N<=1 ){ return N; }

        std::vector<Elem> dp (N, Elem{});
        dp[0] = Elem{ 1,1,0, nums.at(0) }; 

        int maxLen = 0;

        for( int i=1; i<N; i++ ){
            int curVal = nums.at(i);

            if( curVal <= dp[i-1].mmin ){//最小值
                dp[i].len = 1;
                dp[i].num = 1;
                dp[i].l = i;
                dp[i].mmin = curVal;
                maxLen = std::max(maxLen, dp[i].len);
                continue;
            }
            dp[i].mmin = dp[i-1].mmin;

            int rangeLen = -99;
            int rangeNum = 0;
            int rangeL = 0; // 计算方式有点问题

            // 倒序遍历之前的所有元素，统计出 最大区间，及其个数
            for( int n=i-1; n>=0; ){// [n]

                if( dp[n].mmin >= curVal ){ break; } // 再往前的都不需要遍历了

                if( nums.at(n) >= curVal  ){
                    n--;
                    continue;
                }

                int tlen = dp[n].len + 1;
                if( tlen>rangeLen ){// 新记录
                    rangeLen = tlen;
                    rangeNum = dp[n].num; // 从头开始
                    rangeL = dp[n].l;
                }else if( tlen==rangeLen ){
                    rangeNum += dp[n].num;
                    rangeL = dp[n].l;
                }
                
                int off = n - dp[n].l + 1;
                if( off == dp[n].len ){// 可以直接跳过这个区间
                    n = dp[n].l - 1;
                }else{
                    n--;
                }
            }

            dp[i].len = rangeLen;
            dp[i].num = rangeNum;
            dp[i].l   = rangeL;
            maxLen = std::max(maxLen, dp[i].len);
        }

                /*
                cout<<"dp === :"<<endl;
                for( auto &e : dp ){
                    cout<<"  len:"<<e.len
                        <<",  num:"<<e.num
                        <<",  l:"<<e.l
                        <<",  mmin:"<<e.mmin
                        <<endl;
                }cout<<endl;
                */


        int outNum = 0;
        for( auto &e : dp ){
            if( e.len == maxLen ){
                outNum += e.num;
            }
        }
        return outNum;

    }
};





//=========================================================//
void main_(){

    //std::vector<int> v { 1,3,5,4,7 };
    std::vector<int> v { 6,13,-8,-9,6,3,1,8,5,8,9,2,-4,0,5,5,4,7 };

    auto ret = S{}.findNumberOfLIS(v);
    cout<<"ret:"<<ret<<endl;


    
    debug::log( "\n~~~~ leet: 673 :end ~~~~\n" );
}
}//~
