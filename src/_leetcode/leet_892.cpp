/*
 * ====================== leet_892.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.13
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 892. 三维形体的表面积
 */
#include "innLeet.h"

namespace leet_892 {//~


// 朴素法  8%  100%
// 逐层分析 
// 统计相邻的边
class S{
public:
    // N*N
    // 1 <= N <= 50
    // 0 <= grid[i][j] <= 50
    int surfaceArea( std::vector<std::vector<int>>& grid ){

        int N = static_cast<int>(grid.size());
        int outSum = 0;//总面积
        for( int horizon=0; ; horizon++ ){
            int elemNum = 0;//本层元素个数 
            int sideNum = 0;//相邻边数
            for( int h=0; h<N; h++ ){
                for( int w=0; w<N; w++ ){
                    if( grid.at(h).at(w)>horizon ){//本单位在本层存在
                        elemNum++;
                        // 检查 left 
                        if( w>0 && grid.at(h).at(w-1)>horizon ){ sideNum++; }
                        // 检查 up
                        if( h>0 && grid.at(h-1).at(w)>horizon ){ sideNum++; }
                    }
                }
            }
            if( elemNum==0 ){ break; }
            if( horizon==0 ){//floor
                outSum += 2*elemNum; // 上下面
            }
            outSum += 4*elemNum - 2*sideNum;
        }
        return outSum;
    }
};



//=========================================================//
void main_(){



    debug::log( "\n~~~~ leet: 892 :end ~~~~\n" );
}
}//~
