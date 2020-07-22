/*
 * ====================== leet_m17_24.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.22
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 17.24. 最大子矩阵
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m17_24 {//~


// 两次 前缀和，
// 计算 带负数的 数组内，和最大的区间的 方法


// 看到还有人使用了 dp， 暂未去考虑...


//   24%   100%
class S{
public:
    // 矩阵元素： 正整数，0，负整数
    // 1 <= matrix.length, matrix[0].length <= 200
    std::vector<int> getMaxMatrix( std::vector<std::vector<int>>& matrix ){


        int H = static_cast<int>(matrix.size());
        int W = static_cast<int>(matrix[0].size());

        std::vector<std::vector<int64_t>> m ( H, std::vector<int64_t>(W,0) );
        for( int h=0; h<H; h++ ){
            m[h][0] = matrix[h][0];
        }
        for( int h=0; h<H; h++ ){
            for( int w=1; w<W; w++ ){
                m[h][w] = matrix[h][w] + m[h][w-1];
            }
        }
        for( int h=0; h<H; h++ ){for( int w=0; w<W; w++ ){cout<<m[h][w]<<", ";}cout<<endl;}

        int tgtL =0;
        int tgtR =0;
        int tgtU =0;
        int tgtD =0;
        int maxSum = INT_MIN;

        std::vector<int64_t> tv ( H, 0 );

        for(int l=0; l<W; l++){
            for(int r=l; r<W; r++){

                for( int h=0; h<H; h++ ){
                    tv[h] = l==0 ? m[h][r] : m[h][r]-m[h][l-1];
                }

                // 在 单数组 tv 中，寻找 最大和 区间
                int tSum = tv[0];
                int tUp = 0;
                int tDown = 0;

                // tv[0]
                if( tSum > maxSum ){
                    maxSum = tSum;
                    tgtL=l; tgtR=r; tgtU=tUp; tgtD=tDown;
                }
                // tv[i], i>0
                for( int i=1; i<H; i++ ){

                    if( tSum <= 0 ){// 前部区间无效
                        tSum = tv[i];// 重新开始
                        tUp = i;
                        tDown = i;
                    }else{
                        tSum += tv[i];
                        tDown = i;
                    }

                    if( tSum > maxSum ){
                        maxSum = tSum;
                        tgtL=l; tgtR=r; tgtU=tUp; tgtD=tDown;
                    }
                }
            }
        }
        
        return { tgtU, tgtL, tgtD, tgtR };

    }
};





//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}
    };

    auto ret = S{}.getMaxMatrix(v);

    cout<<"ret: "<<endl;
    for( int i : ret ){ cout<<i<<", "; }cout<<endl;

    
    debug::log( "\n~~~~ leet: m17_24 :end ~~~~\n" );
}
}//~
