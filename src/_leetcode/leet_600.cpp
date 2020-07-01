/*
 * ====================== leet_600.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 600. 不含连续1的非负整数
 */
#include "innLeet.h"


namespace leet_600 {//~


// 确实是一个 一维dp 题，思路就是，二进制表达的 位数 
// 比如，位数为 3 的情况下，有多少可能性 dp[3]
// 然后，更大的数，依赖 已经计算好的 低位数状态值

// 更为惊人的发现是，dp[i] = dp[i-1] + dp[i-2]
// 它的增长规律，是个 斐波那契数列 ！！！！！！！



//    66%   100%
class S{

    int lowbit( int v ){
        return v&(-v);
    }

public:
    // 1 <= n <= 10^9
    int findIntegers( int num ){

        // 求出 num 二进制位数
        std::vector<int> rbit {};// 倒序存储 num 二进制表达
        for( int i=num; i>0; i/=2 ){
            rbit.push_back( i&1 );
        }
        int N = static_cast<int>(rbit.size());

        // dp 是一个 标准的 斐波那契数列（规律使然）
        std::vector<int> dp (N+1, 0);
        dp[0] = 1;
        dp[1] = 2;
        for( int i=2; i<=N; i++ ){// [i-1], [i-2]
            dp[i] = dp[i-1] + dp[i-2];
        }

        // 找出 <= num 的 最大合法值，直接改写在 rbit 中
        bool isLstOne = false;
        int ri=N-1;
        for(; ri>=0; ri-- ){
            if( rbit[ri]==1 && isLstOne ){ break; }// 第一次发现 重复1
            isLstOne = rbit[ri]==1;
        }

        if( ri>=0 ){//发现了 重复1，rbit[ri] 就是第二个 重复1
            rbit[ri--] = 0;
            isLstOne = false;
            for(; ri>=0; ri-- ){
                rbit[ri] = isLstOne ? 0 : 1;
                isLstOne = rbit[ri]==1;
            }
        }
        //cout<<"rbit(2): "; for( int i : rbit ){ cout<<i<<", "; }cout<<endl;

        int  outSum = 1; // rbit 自身就已经是 有效值
        for( int i=0; i<N; i++ ){
            if( rbit[i] == 1 ){
                outSum += dp[i];
            }
        }
        return outSum;


    }
};




//=========================================================//
void main_(){

    auto ret = S{}.findIntegers( 23 );

    cout<<"ret:"<<ret<<endl;


    
    debug::log( "\n~~~~ leet: 600 :end ~~~~\n" );
}
}//~
