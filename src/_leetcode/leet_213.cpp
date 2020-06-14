/*
 * ====================== leet_213.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 213. 打家劫舍 II
 */
#include "innLeet.h"


namespace leet_213 {//~


// 一个很丑陋的 标准方案：
// 分别求 [0,N-2],[1,N-1] 两个区间的最优解
// 然后选其中最优


class S{

    std::vector<std::vector<int>> dp {};
    int &dp_at( int h, int w ){
        return dp.at(h).at(w);
    }

public:
    int rob( std::vector<int> nums ){

        if(nums.empty()){ return 0; }
        int N = static_cast<int>(nums.size());
        if(N==1){ return nums.back(); }
        dp.resize( N-1, std::vector<int>{0,0} );

        //== [0,N-2] ==//
        dp_at(0,0) = 0;
        dp_at(0,1) = nums.at(0);
        for( int i=1; i<N-1; i++ ){
            dp_at(i,1) = dp_at(i-1,0) + nums.at(i);// 偷
            dp_at(i,0) = std::max(dp_at(i-1,0), dp_at(i-1,1));// 不偷
        }
        int ans1 = std::max( dp.back().at(0), dp.back().at(1) );

        //== [1,N-1] ==//
        dp_at(0,0) = 0;
        dp_at(0,1) = nums.at(1);
        for( int i=1; i<N-1; i++ ){
            dp_at(i,1) = dp_at(i-1,0) + nums.at(i+1);// 偷
            dp_at(i,0) = std::max(dp_at(i-1,0), dp_at(i-1,1));// 不偷
        }
        int ans2 = std::max( dp.back().at(0), dp.back().at(1) );

        return std::max(ans1, ans2);

    }
};







//=========================================================//
void main_(){

    cout<<"\n"<<S{}.rob({ 1,1,3,6,7,10,7,1,8,5,9,1,4,4,3 })<<endl;

    cout<<"\n"<<S{}.rob({ 1,3,6,7,10,7,1,8,5,9,1,4,4,3 })<<endl;

    debug::log( "\n~~~~ leet: 213 :end ~~~~\n" );
}
}//~
