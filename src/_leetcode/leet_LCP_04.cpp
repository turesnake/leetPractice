/*
 * ====================== leet_LCP_04.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * LCP 04. 覆盖
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_LCP_04 {//~


// 图论：二分图，匈牙利算法


// 将矩阵，按照棋盘格黑白色，分为两个点集
// 实现方式为，h+w 的奇偶性 



//  其实暂时没看懂...


class S{

    std::vector<std::vector<char>> bks {};
    std::vector<std::vector<int>> mat {};// 邻接矩阵
    std::vector<char> vis {};
    std::vector<int> from {};

    int H {}; 
    int W {};
    int Ntotal {};
    

    bool match( int x ){

        for (int i = 0; i<Ntotal; ++i){
            int dh = i/W;
            int dw = i%W;

            if( ((dh+dw)&1)==1 ) continue;// 只检测白格
            if( bks[dh][dw]==1 ) continue;
            if( mat[x][i]==0 ) continue;

            if( vis[i]==0 ){
                vis[i] = 1;
                if( from[i]<0 || match(from[i]) ){
                    from[i]=x;
                    return true;
                }
            }
        }
        return false;
    }


public:
    int domino(int n, int m, std::vector<std::vector<int>>& broken ){

        H = n;
        W = m;
        Ntotal = H*W;
        
        bks.resize( H, std::vector<char>(W, 0) );
        for ( auto &p: broken){
            bks[p[0]][p[1]]=1;
        }

        mat.resize( 105, std::vector<int>(105, 0) );

        for (int h=0; h<H; ++h ){
            for (int w=0; w<W; ++w ){
                if( bks[h][w]==1 ){ continue; }
                int i = h*W + w;  // key
                if( w+1 < W && bks[h][w+1]==0 ){// 横放
                    int j = h*W + (w+1);
                    mat[i][j] = 1;
                    mat[j][i] = 1;
                }
                if ( h+1<H && bks[h+1][w]==0 ){// 竖放
                    int j = (h+1)*W + w;
                    mat[i][j] = 1;
                    mat[j][i] = 1;
                }
            }
        }
        //--- Hungary ---//
        // 认为 (x 坐标 + y 坐标) 为奇数时格子是黑色，对黑色格子找匹配
        int ans = 0;

        from.resize( 105, -1 );

        for (int i = 0; i<Ntotal; ++i){
            int dh = i/W;
            int dw = i%W;
            if( ((dh+dw)&1)==0 ){ continue; }// 只检测黑格
            if( bks[dh][dw]==1 ){ continue; }

            vis.clear();
            vis.resize( 105,0 );

            if( match(i) ){ ans++; }
        }
        return ans;



    }
};




//=========================================================//
void main_(){

    std::vector<std::vector<int>> b {
    };

    auto ret = S{}.domino( 3,3,b );
    cout<<"ret:"<<ret<<endl;

    
    debug::log( "\n~~~~ leet: LCP_04 :end ~~~~\n" );
}
}//~
