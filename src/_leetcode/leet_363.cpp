/*
 * ====================== leet_363.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 363. 矩形区域不超过 K 的最大数值和
 */
#include "innLeet.h"


namespace leet_363 {//~


// 原则上需要遍历 4 层，借用两个 前缀和来加快计算
// 在 内层中，使用 O(H) 快速法来计算 hVec数组的 最大区间和 innMax
// 若 innMax<=k 就不需要去做暴力遍历了


//   86%   100%
class S{
public:
    // 矩阵非空
    // 矩阵内的矩形区域面积必须大于 0。
    // 如果行数远大于列数，你将如何解答呢？
    // [h][w] 可能为 负数
    // 
    int maxSumSubmatrix( std::vector<std::vector<int>>& matrix, int k ){


        int H = static_cast<int>(matrix.size());
        int W = static_cast<int>(matrix.at(0).size());

        // 计算 行前缀和
        for( auto &c : matrix ){
            for( int i=1; i<W; i++ ){// [i-1],[i]
                c[i] += c[i-1];
            }
        }

        std::vector<int> hVec (H,0);
        std::vector<int> hPreSum (H,0); // hVec 的 前缀和 
        int outMax = -1000000000; // 目标值

        std::vector<std::vector<int>> dp ( H, std::vector<int>(2, 0) );

        for( int r=W-1; r>=0; r-- ){
            for( int l=0; l<=r; l++ ){

                // 收集 [l,r] 区间内，所有 行区间和 的前缀和 
                int minElem = INT_MAX;
                for( int h=0; h<H; h++ ){
                    hVec[h] = l==0 ? matrix[h][r] : matrix[h][r]-matrix[h][l-1];
                    minElem = std::min( minElem, hVec[h] );
                    hPreSum[h] = h==0 ? hVec[h] : hVec[h]+hPreSum[h-1];
                }
                if( minElem == k ){ return k; }

                // =优化= 可以将成绩从  9%  提升为  86%
                // 先用 O(H) 计算出 hVec 最大区间和 innMax，若 innMax<=k, 则无需暴力遍历了
                int innMax = hVec[0];
                int innSum = hVec[0];
                for( int h=1; h<H; h++ ){
                    innSum = innSum<0 ? hVec[h] : innSum+hVec[h];
                    innMax = std::max( innMax, innSum );
                }
                if( innMax == k ){ return k; }
                if( innMax < k ){
                    outMax = std::max(outMax, innMax);
                    continue;
                }
                
                // 暴力遍历， 针对这组 行区间和，查找 不大于k的最大区间和
                for( int b=0; b<H; b++ ){
                    for( int a=0; a<=b; a++ ){
                        int sum = a==0 ? hPreSum[b] : hPreSum[b]-hPreSum[a-1];
                        if( sum == k ){ return k; }
                        if( sum < k ){ outMax = std::max( outMax, sum ); }
                    }
                }
            }    
        }
        return outMax;
        

    }
};



//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        { 5,-4,-3, 4}, 
        {-3,-4, 4, 5},
        { 5, 1, 5,-4}
    };

    auto ret = S{}.maxSumSubmatrix( v, 8 );
    cout<<"ret:"<<ret<<endl;


    
    debug::log( "\n~~~~ leet: 363 :end ~~~~\n" );
}
}//~
