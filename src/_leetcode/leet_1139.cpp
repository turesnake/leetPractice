/*
 * ====================== leet_1139.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1139. 最大的以 1 为边界的正方形
 */
#include "innLeet.h"


namespace leet_1139 {//~


// 非常直观的 三维dp，每个边长为 k 的正方形，其状态由 两个 k-1 正方形 确定
// 缺点就是 运行较慢

//  dp   5%   100%
class S{

struct Elem{
    bool u {false};// up
    bool d {false};// down
    bool l {false};// left
    bool r {false};// right
};

public:
    // 1 <= grid.len <= 100
    // 1 <= grid[0].len <= 100
    // grid[i][j] 为 0 或 1
    int largest1BorderedSquare( std::vector<std::vector<int>>& grid ){

        int H = static_cast<int>(grid.size());
        int W = static_cast<int>(grid.at(0).size());
        int K = std::min( H,W );
        std::vector<std::vector<std::vector<Elem>>> dp (
            H, std::vector<std::vector<Elem>>(
                W, std::vector<Elem>( 
                    K+1, Elem{} 
                )
            )
        );

        int maxLen = 0; // 最大正方形的边长
        // [h][w][1]
        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                dp[h][w][1] = grid[h][w]==1 ? 
                                Elem{ true, true, true, true } : 
                                Elem{ false,false,false,false };
                if( grid[h][w]==1 ){ maxLen=1; }
            }
        }

        // k>1
        for( int k=2; k<=K; k++ ){
            for( int h=k-1; h<H; h++ ){
                for( int w=k-1; w<W; w++ ){
                    auto &elem = dp[h][w][k];
                    elem.u = grid[h-k+1][w-k+1]==1 && dp[h-1][w][k-1].u;
                    elem.r = grid[h][w]==1         && dp[h-1][w][k-1].r;
                    elem.d = grid[h][w]==1         && dp[h][w-1][k-1].d;
                    elem.l = grid[h-k+1][w-k+1]==1 && dp[h][w-1][k-1].l;
                    if( elem.u && elem.r && elem.d && elem.l ){
                        maxLen = std::max( maxLen, k );
                    }
                }
            }
        }
        return maxLen*maxLen;



    }
};


// 第二种 dp 思路：每个格子，都可以记录，自己左侧有几个连续的1，上方有几个连续的1

//   64%   100%
class S2{

struct Elem{
    int up   {0};// 上侧有几个连续的1
    int left {0};// 左侧有几个连续的1
};

public:
    // 1 <= grid.len <= 100
    // 1 <= grid[0].len <= 100
    // grid[i][j] 为 0 或 1
    int largest1BorderedSquare( std::vector<std::vector<int>>& grid ){


        int H = static_cast<int>(grid.size());
        int W = static_cast<int>(grid.at(0).size());
        std::vector<std::vector<Elem>> dp ( H, std::vector<Elem>( W, Elem{} ));

        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                auto &elem = dp[h][w];
                int curVal = grid[h][w];
                elem.up = h==0 ? 
                            curVal :
                            (curVal==0 ? 0 : dp[h-1][w].up+1);
                elem.left = w==0 ?
                            curVal :
                            (curVal==0 ? 0 : dp[h][w-1].left+1);
            }
        }

        int maxLen = 0;
        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
    
                int curVal = grid[h][w];
                if( curVal==0 ){ continue; }

                bool isFind = false;
                int len = std::min( dp[h][w].up, dp[h][w].left ); // 此格能实现的最大 方形边长
                for(; len>=1; len-- ){
                    if( dp[h-len+1][w].left>=len && dp[h][w-len+1].up>=len ){
                        isFind = true;
                        break;
                    }
                }

                if( isFind ){
                    maxLen = std::max( maxLen, len );
                }
            }
        }
        return maxLen*maxLen;

    
    }
};




//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    auto ret = S{}.largest1BorderedSquare(v);
    cout<<"ret:"<<ret<<endl;


    
    debug::log( "\n~~~~ leet: 1139 :end ~~~~\n" );
}
}//~
