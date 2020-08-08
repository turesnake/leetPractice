/*
 * ====================== leet_322.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 322. 零钱兑换
 */
#include "innLeet.h"


namespace leet_322 {//~



// 可以是 dp，类似 背包问题
// 也可以是 回溯



// 回溯解法  这个方案 目测会超时 .....
class S{

    bool isFind {false};
    int minNum {INT_MAX};

    std::vector<int> *coinsp {nullptr};
    int Nc {};

    // idx 当前能使用的 最大值 
    // leftNum 还需要分配的值 
    // deep 分配次数 
    void work( int idx,  int leftNum, int deep ){
        deep++;
        for( int i=idx; i<Nc; i++ ){// 从大到小
            int curCoin = coinsp->at(i);
            if( curCoin == leftNum ){
                if( !isFind ){ isFind=true; }
                minNum = std::min(minNum, deep);
                return;
            }else if( curCoin > leftNum ){
                continue;
            }else{// <
                work( i, leftNum-curCoin, deep );
            }
        }
    }
public:
    int coinChange( std::vector<int>& coins, int amount ){
        if( amount==0 ){
            return coins.empty() ? -1 : 0; 
        }else{
            if( coins.empty() ){ return -1; }
        }
        std::sort( coins.begin(), coins.end(), std::greater<int>{} );
        coinsp = &coins;
        Nc = static_cast<int>(coins.size());
        work( 0, amount, 0 );
        return isFind ? minNum : -1;

    }
};




// dp   10%,  11%
// 背包dp 的本质是 一维的！！！
class S2{
public:
    int coinChange( std::vector<int>& coins, int amount) {

        if( amount==0 ){
            return coins.empty() ? -1 : 0; 
        }else{
            if( coins.empty() ){ return -1; }
        }
        std::vector<int> dp ( amount+1, 0);// 到达本格，消耗的最少硬币数
        // dp[0]=0;
        for( int n=1; n<=amount; n++ ){
            int mmin = INT_MAX;
            bool isFind = false;
            for( int i : coins ){// each coin
                if( i<=0 ){ continue; }
                int iOff = n-i;
                if( iOff<0 ){ continue; }
                if( dp[iOff]==-1 ){ continue; }
                if( !isFind ){ isFind=true; }
                mmin = std::min( mmin, dp.at(iOff) );
            }
            dp[n] = isFind ? (mmin+1) : -1;
        }
            //cout<<"dp:"<<endl; for( int i : dp ){ cout<<i<<", "; }cout<<endl;
        return dp[amount];


    }
};





//=========================================================//
void main_(){

    std::vector<int> v { 0 };

    cout<<S2{}.coinChange( v, 11 )<<endl;


    debug::log( "\n~~~~ leet: 322 :end ~~~~\n" );
}
}//~
