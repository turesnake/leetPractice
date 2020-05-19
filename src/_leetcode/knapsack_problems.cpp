/*
 * =================== knapsack_problems.cpp =================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 动态规划: 背包问题
 */
#include "innLeet.h"


namespace leet_knapsack_problems {//~



// 简化版，假设 每个物价，重量是相同的，背包只能容纳 k 个物件
// 此时如何用 动态规划来实现
// 未对空间做优化，保持了 dp数组的 原始面貌
int simple_knapsack_0( std::vector<int> &items, int Knum ){

    if( items.empty() || Knum<=0 ){ return 0; }
    // 以下，k一定大于等于1，items 一定有元素
    int Nnum = static_cast<int>(items.size()); // Nnum 个 物件
    std::vector<std::vector<int>> dp ( Nnum, std::vector<int> (Knum+1,0) );// [Nnum][Knum+1]
        // 每个元素，存储的是，在 [n][k] 条件下，最优解
        // 排在后方的元素，依赖之前的元素来被 快速计算（迭代）

    // k==0 时，表示一次也没选择，值都为 0
    for( int n=0; n<Nnum; n++ ){
        dp.at(n).at(0) = 0;
    }
    // 当 Nnum==1 ,k>0 时，最优解是相同的，都是 items.at(0)
    for( int k=1; k<Knum+1; k++ ){
        dp.at(0).at(k) = items.at(0);
    }

    for( int n=1; n<Nnum; n++ ){ // 第 n 个物件 [base on 0]
        for( int k=1; k<Knum+1; k++ ){ // 已经选中了第 k 次 [base on 0]

            dp.at(n).at(k) = std::max(
                dp.at(n-1).at(k-1) + items.at(n), // 本回合执行 第k次 选中，联合上回合 选中k-1次 的最优解
                dp.at(n-1).at(k) // 本回合不选中，继承 上回合 第k次选中的 最优解
            );
        }
    }
    return dp.back().back();
}



// items <weight,val>
// ret: 背包能装下的 最大价值 是多少


// 暴力解
// idx: 本回合的起始下标
int knapsack_1_0( std::vector<std::vector<int>> &items, int idx, int weightLimit ){

    int ssize = static_cast<int>(items.size());
    int thisWeight = items.at(idx).at(0);
    int thisVal    = items.at(idx).at(1);

    if( idx == ssize-1 ){//包里只有一个元素了
        return (weightLimit < thisWeight) ? 
                            0 :  // 空间不够，不能选
                            thisVal; // 最大值，就是这个元素的 val
    }
    
    if( weightLimit == thisWeight ){
        return thisVal;
    }else if( weightLimit > thisWeight ){
        int choose = thisVal + knapsack_1_0( items, idx+1, weightLimit-thisWeight );
        int notChoose = knapsack_1_0( items, idx+1, weightLimit );
        return std::max( choose, notChoose );
    }else{
        return 0;
    }
}


// 动态规划
// 原始版，未做 空间优化
// items: <weight,val>
int knapsack_1_1( std::vector<std::vector<int>> &items, int weightLimit ){

    if( items.empty() || weightLimit==0 ){ return 0; }

    int Nnum = static_cast<int>(items.size());
    std::vector<std::vector<int>> dp ( Nnum, std::vector(weightLimit+1,0) );// [Nnum][weightLimit+1]
            // 每个元素代表在 [n][k] 条件下的 最优解 （最大vals）

    // k==0 时，没有任何空间 放置任何物件，最优解全部为 0
    for( int n=0; n<Nnum; n++ ){
        dp.at(n).at(0) = 0;
    }
    // 当 items 只有一个物件可选时，只需要比较这个 唯一物件的 weight，和 weightLimit
    // 不达标就不选，达标就选它
    for( int k=1; k<weightLimit+1; k++ ){
        int thisVal = items.at(0).at(1);
        int thisWeight = items.at(0).at(0);
        dp.at(0).at(k) = (k<thisWeight) ? 0 : thisVal;
    }

    for( int n=1; n<Nnum; n++ ){ // 当前正在处理 哪个 物件
        int thisVal = items.at(n).at(1);
        int thisWeight = items.at(n).at(0);
        for( int k=1; k<weightLimit+1; k++ ){ // 当前还剩下 多少 剩余空间/重量
            if( k-thisWeight < 0 ){//当前剩余的空间，已经不足以放下本回合物件了
                dp.at(n).at(k) = dp.at(n-1).at(k); // 本回合只能不选
                // 不能使用 break，要老老实实填满整张 dp 表
            }else{
                dp.at(n).at(k) = std::max(
                    thisVal + dp.at(n-1).at(k-thisWeight), // 本回合选
                    dp.at(n-1).at(k) // 本回合不选
                );
            }
        }
    }
    return dp.back().back();
}






//=========================================================//
void main_(){

    /*
    {// 简化版，从n个元素中，选取k个，求和的最大值
        std::vector<int> v { 7,11,3,6,9 };
        auto ret = simple_knapsack_0( v, 0 ); // 取三个元素
        cout << "simple ret = " << ret << endl;
    }
    */


    {
        std::vector<std::vector<int>> v{
            { 3,5 },
            { 4,11 },
            { 5,10 }
        };
        auto ret = knapsack_1_1( v, 10 );
        cout << "knapsack ret = " << ret << endl;
    }
    

    debug::log( "\n~~~~ leet: knapsack_problems :end ~~~~\n" );
}
}//~
