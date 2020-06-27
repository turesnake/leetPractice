/*
 * ====================== leet_1335.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1335. 工作计划的最低难度
 */
#include "innLeet.h"


namespace leet_1335 {//~


// 二维dp
// 这其实是一道，将数组 分成 d 个区间 的问题
// 不能多不能少，正好 d 个区间 


// 这题在思路上，挺传统的 


//   65%   100%
class S{
public:
    // 1 <= jobDifficulty.len <= 300
    // 0 <= jobDifficulty[i] <= 1000
    // 1 <= d <= 10
    int minDifficulty( std::vector<int>& jobDifficulty, int d ){

        int N = static_cast<int>(jobDifficulty.size());
        if( d>N ){ return -1; }

        std::vector<std::vector<int>> dp (N, std::vector<int>(d+1, -99 ));
        // h: elem, w: d

        dp[0][1] = jobDifficulty.at(0);

        for( int i=1; i<N; i++ ){// each elem: [i-1], [i]

            dp[i][1] = std::max( dp[i-1][1], jobDifficulty[i] );

            for( int day=2; day<=d; day++ ){// each day

                if( day>(i+1) ){ continue; }// 元素太少，区间太多

                // 自己独占一个 区间时 
                int minSum = jobDifficulty[i] + dp[i-1][day-1];
                int maxElem = jobDifficulty[i];// 后部区间最大值 

                // 和前方若干元素，共用一个区间时
                for( int l=i-1; l>=day-1; l-- ){

                    maxElem = std::max( maxElem, jobDifficulty[l] );
                    int tmpSum = maxElem + dp[l-1][day-1];
                            assert( dp[l-1][day-1] > 0 );
                    minSum = std::min( minSum, tmpSum );
                    /*
                    cout<<" day:" << day
                        <<", maxElem:"<< maxElem << ",  tmpSum:"<<tmpSum
                        <<", minSum:" << minSum
                        <<endl;
                    */
                }
                dp[i][day] = minSum;
            }
        }
        //cout<<"dp: "<<endl;
        //for( auto &c : dp ){ for( int i : c ){ cout<<i<<", "; }cout<<endl; }
        return dp[N-1][d];

    }
};



//=========================================================//
void main_(){

    std::vector<int> v { 11,111,22,222,33,333,44,444 };

    auto ret = S{}.minDifficulty( v, 6 );
    cout<<"ret:"<<ret<<endl;


    
    debug::log( "\n~~~~ leet: 1335 :end ~~~~\n" );
}
}//~
