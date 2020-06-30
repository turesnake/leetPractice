/*
 * ====================== leet_1329.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1329. 将矩阵按对角线排序
 */
#include "innLeet.h"


namespace leet_1329 {//~



//   99%,  100%
class S{

    int H {};
    int W {};
    std::vector<int> vec {};
    std::vector<std::vector<int>> *matp {nullptr};


    // 以元素 [h][w] 为首的 对角线数组
    // 收集，排序，放回
    void work( int j, int i ){
        vec.clear();
        for( int h=j,w=i; h<H && w<W; h++,w++ ){
            vec.push_back( (*matp)[h][w] );
        }
        std::sort( vec.begin(), vec.end() );
        for( int h=j,w=i,k=0; h<H && w<W; h++,w++,k++ ){
            matp->at(h).at(w) = vec[k];
        }
    }

public:
    // m == mat.length
    // n == mat[i].length
    // 1 <= m, n <= 100
    // 1 <= mat[i][j] <= 100
    std::vector<std::vector<int>> diagonalSort( std::vector<std::vector<int>>& mat){

        H = static_cast<int>(mat.size());
        W = static_cast<int>(mat.at(0).size());
        matp = &mat;

        vec.reserve( std::min(H,W) );
        for( int h=0; h<H; h++ ){ work( h, 0 ); }
        for( int w=1; w<W; w++ ){ work( 0, w ); }
        return mat;

    }
};




//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 1329 :end ~~~~\n" );
}
}//~
