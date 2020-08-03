/*
 * ====================== leet_1267.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1267. 统计参与通信的服务器
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1267 {//~



//   30%  30%
class S{
public:
    // m == grid.length
    // n == grid[i].length
    // 1 <= m <= 250
    // 1 <= n <= 250
    // grid[i][j] == 0 or 1
    int countServers( std::vector<std::vector<int>>& grid ){

        int H = static_cast<int>(grid.size());
        int W = static_cast<int>(grid[0].size());
        int Ntotal = 0;
        int Nsingle = 0;

        std::vector<int> hv (H,0);
        std::vector<int> wv (W,0);

        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                if( grid[h][w]==1 ){
                    Ntotal++;
                    hv[h]++;
                    wv[w]++;
                }
            }
        }
        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                if( grid[h][w]==1 && hv[h]==1 && wv[w]==1 ){
                    Nsingle++;
                }
            }
        }
        return Ntotal - Nsingle;

    }
};


//=========================================================//
void main_(){


 
    

    debug::log( "\n~~~~ leet: 1267 :end ~~~~\n" );
}
}//~
