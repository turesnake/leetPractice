/*
 * ====================== leet_m17_09.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 17.09. 第 k 个数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m17_09 {//~


// 经典的 三指针 法
// 核心在于，这三个指针，指在 dp 数组上

// 本质上，它是一道 特殊的 dp 题

//   100%  100%
class S2{
public:
    int getKthMagicNumber( int k ){

        if(k==1){ return 1; }

        std::vector<int64_t> dp (k, 1 );
        int p3 = 0;
        int p5 = 0;
        int p7 = 0;
        for( int i=1; i<k; i++ ){
            int64_t v3 = dp[p3]*3;
            int64_t v5 = dp[p5]*5;
            int64_t v7 = dp[p7]*7;
            dp[i] = std::min( std::min(v3, v5), v7 );
            if( dp[i]==v3 ){ p3++; }
            if( dp[i]==v5 ){ p5++; }
            if( dp[i]==v7 ){ p7++; }
        }
        return dp[k-1];

    }
};



// 临时自创的 特殊法，set 法

// 可行，但存在一个缺点：本质上，它不仅仅计算了 第 k 个值，
// 而是往后 多计算了 很多位。 可能会 超过 int 上限。

//   15%   100%
class S1{
public:
    int getKthMagicNumber( int k ){

        if(k==1){ return 1; }
        k--;

        std::set<int64_t> uset { 1 };
        int64_t val = 1;

        for(; k>0; k-- ){
            val = *uset.begin();
            uset.erase(val);
            uset.insert( val*3 );
            uset.insert( val*5 );
            uset.insert( val*7 );
        }
        //cout<<"uset:";for( int64_t i : uset ){ cout<<i<<", ";}cout<<endl;
        return *uset.begin();

    }
};







//=========================================================//
void main_(){

    auto ret = S1{}.getKthMagicNumber( 643 );

    cout<<"ret:"<<ret<<endl;



    debug::log( "\n~~~~ leet: m17_09 :end ~~~~\n" );
}
}//~
