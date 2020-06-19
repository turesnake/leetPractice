/*
 * ====================== leet_983.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 983. 最低票价
 */
#include "innLeet.h"


namespace leet_983 {//~


// 一维dp  
// dp[i] 表示，[0,i] 区间 最小消费

// 这道题的一个难点是，c1，c7，c30 三种票价是 无规则的
// 不能想当然地认为， p1 最便宜


//   86%   20%
class S{
public:
    // 1 <= days.len <= 365
    // 1 <= days[i] <= 365
    // days 按顺序严格递增
    // costs.len == 3
    // 1 <= costs[i] <= 1000
    int mincostTickets( std::vector<int>& days, std::vector<int>& costs ){

        int C_1  = costs[0];
        int C_7  = costs[1];
        int C_30 = costs[2];

        int N = static_cast<int>(days.size());
        std::vector<int> dp (N, 0);
        dp[0] = std::min( C_1, std::min(C_7, C_30) );

        for( int i=1; i<N; i++ ){//[i-1], [i]
            int curVal = days.at(i);

            bool is_7  = false;
            bool is_30 = false;
            int sum_1  = dp[i-1] + C_1;
            int sum_7  = INT_MAX;
            int sum_30 = INT_MAX;
            //---//
            int off = days[i] - days[i-1] + 1; // 包含两天的区间长度
            if( off > 30 ){
                sum_7  = dp[i-1] + C_7;
                sum_30 = dp[i-1] + C_30;
            }else if( off > 7 ){
                sum_7  = dp[i-1] + C_7;
                is_30 = true;
            }else{
                is_7 = true;
                is_30 = true;
            }
            if(is_7){
                int tgtI = curVal-7;
                if( days.at(0) <= tgtI ){
                    int n=i-1;
                    for( ; n>=0 && days.at(n)>tgtI; n-- ){}// find n
                    sum_7 = C_7 + dp[n];
                }else{
                    sum_7 = C_7;
                }
            }
            if(is_30){
                int tgtI = curVal-30;
                if( days.at(0) <= tgtI ){
                    int n=i-1;
                    for( ; n>=0 && days.at(n)>tgtI; n-- ){}// find n
                    sum_30 = C_30 + dp[n];
                }else{
                    sum_30 = C_30;
                }
            }
            dp[i] = std::min( sum_1, std::min(sum_7,sum_30) );
        }
        //cout<<"dp:"<<endl; for( auto i : dp ){ cout<<"  "<<i<<endl;}
        return dp.back();


    }
};







//=========================================================//
void main_(){

    std::vector<int> v { 1,4,6,7,8,20 };
    std::vector<int> c { 7,2,15 };

    auto ret = S{}.mincostTickets( v,c );
    cout<<"ret:"<<ret<<endl;



    
    debug::log( "\n~~~~ leet: 983 :end ~~~~\n" );
}
}//~
