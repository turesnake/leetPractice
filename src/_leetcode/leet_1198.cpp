/*
 * ====================== leet_1198.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1198. 找出所有行中最小公共元素
 */
#include "innLeet.h"


namespace leet_1198 {//~



//   35%   100%
class S{
public:
    // 1 <= mat.len, mat[i].len <= 500
    // 1 <= mat[i][j] <= 10^4
    // mat[i] 已按递增顺序排列。
    int smallestCommonElement( std::vector<std::vector<int>>& mat ){

        int H = static_cast<int>(mat.size());
        int W = static_cast<int>(mat.at(0).size());

        std::vector<short> v ( 10000, -1 ); // -1 表示不存在

        for( int w=0; w<W; w++ ){// 每一列
            // 找到 本列 最大元素，并解锁
            int maxElem = 0;
            for( int h=0; h<H; h++ ){
                maxElem = std::max( maxElem, mat[h][w] );
            };
            if( v[maxElem] == -1 ){ v[maxElem] = 0; }

            // 再次遍历本列，登记所有 关键元素 
            for( int h=0; h<H; h++ ){
                int curVal = mat[h][w];
                if( v[curVal] >= 0 ){
                    v[curVal]++;
                    if( v[curVal]==H ){
                        return curVal;
                    }
                }
            }
        }
        return -1;



    }
};



//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 1198 :end ~~~~\n" );
}
}//~
