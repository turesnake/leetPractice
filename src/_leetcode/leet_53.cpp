/*
 * ====================== leet_53.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 53. 最大子序和
 */
#include "innLeet.h"


namespace leet_53 {//~




// 动态规划
// 原始版本，未做空间优化
int maxSubArray( std::vector<int> &nums ){

    if( nums.empty() ){ return 0; }
    if( nums.size()==1 ){ return nums.back(); }
    // 接下来，nums 一定包含 2或更多元素

    int Nnum = static_cast<int>(nums.size());
    std::vector<std::vector<int>> dp ( Nnum, std::vector<int> (2,INT_MIN) ); // [Nnum][2]
        // [Nnum][0] 本回合不持有 （也许从未持有，也许已经卖出）
        // [Nnum][1] 本回合持有 （也许第一次持有，也许上回合就持有了）

    dp.at(0).at(0) = INT_MIN;
    dp.at(0).at(1) = nums.at(0);

    for( int n=1; n<Nnum; n++ ){
        int thisVal = nums.at(n);
        dp.at(n).at(0) = std::max(
            dp.at(n-1).at(0), // 上回合已经不持有
            dp.at(n-1).at(1)  // 上回合还持有，本回合已卖出
        );
        dp.at(n).at(1) = std::max(
            thisVal, // 上回合不持有，本回合是第一次
            dp.at(n-1).at(1) + thisVal // 上回合持有，累加本回合的值
        );
    }
 
    /*
    cout << "--------" << endl;
    for( int n=0; n<Nnum; n++ ){
        cout << dp.at(n).at(0) << ", " << dp.at(n).at(1) << endl;
    }
    cout << "--------" << endl;
    */


    return std::max( dp.back().at(0), dp.back().at(1) );
}


// 动态规划
// 将 dp 数组，压缩为 2层，交替使用 
int maxSubArray_2( std::vector<int> &nums ){

    if( nums.empty() ){ return 0; }
    if( nums.size()==1 ){ return nums.back(); }
    // 接下来，nums 一定包含 2或更多元素

    int Nnum = static_cast<int>(nums.size());
    std::vector<int> dp1 ( 2, INT_MIN );
    std::vector<int> dp2 ( 2, INT_MIN );
    auto *fst = &dp1; // 交替访问用指针，节省dp空间
    auto *lst = &dp2; // 交替访问用指针，节省dp空间
        // dp[0] 本回合不持有 （也许从未持有，也许已经卖出）
        // dp[1] 本回合持有 （也许第一次持有，也许上回合就持有了）

    fst->at(0) = INT_MIN;
    fst->at(1) = nums.at(0);

    for( int n=1; n<Nnum; n++ ){
        int thisVal = nums.at(n);
        lst->at(0) = std::max(
            fst->at(0), // 上回合已经不持有
            fst->at(1)  // 上回合还持有，本回合已卖出
        );
        lst->at(1) = std::max(
            thisVal, // 上回合不持有，本回合是第一次
            fst->at(1) + thisVal // 上回合持有，累加本回合的值
        );
        std::swap( fst, lst ); // 交换指针
    }
    return std::max( fst->at(0), fst->at(1) );
}





//=========================================================//
void main_(){

    std::vector<int> v { -2, -1 };
    //std::vector<int> v { -2,1,-3,4,-1,2,1,-5,4 };
    //std::vector<int> v { 77, -1, 5, -10, 22 };

    
    auto ret = maxSubArray( v );
    cout << "1 ret = " << ret << endl;

    auto ret2 = maxSubArray_2( v );
    cout << "2 ret = " << ret2 << endl;


    debug::log( "\n~~~~ leet: 53 :end ~~~~\n" );
}
}//~
