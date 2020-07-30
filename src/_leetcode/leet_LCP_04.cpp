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
// 左集：{m...}  全奇数项
// 右集：{n...}  全偶数项
//
// 实现方式为，h+w 的奇偶性 


// key = h*W + w;


//  65%  100%
class S1{

    int H {};// broken.size()    [1,8]
    int W {};// broken[0].size() [1,8]
    int Ntotal {};// 所有元素个数 H*W
    
    std::vector<std::vector<char>> mat {};//<Ntotal,Ntotal>
    // 0:无效边 1:有效边
    std::vector<int> pre {}; // 右集合元素 n，暂时匹配的 左元素m下标
    std::vector<char> vis {};// 单次周期内，右集合元素n，是否被访问过 
    // 以上两张表 容量都是 Ntotal, 但实际上，因为 黑白棋盘的缘故，只使用了 一半空间

    bool check( int km ){
        // 遍历每个 右集元素（偶数项）
        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                if( ((h+w)&1)==1 ){ continue; }// 跳过 奇数项
                int kn = h*W + w;

                if( mat[km][kn]==0 ){ continue; }// 无效边
                if( vis[kn]==1 ){ continue; }// 在本周期内，元素kn 已经被访问过了
                vis[kn]=1; // 先登记

                if( pre[kn]==-1 || check(pre[kn]) ){// 核心，寻找“临时”匹配项  
                    pre[kn] = km;
                    return true;
                }
            }
        }
        return false;
    }


public:
    // 1 <= n,m <= 8
    // 0 <= b <= n*m
    int domino( int n, int m, std::vector<std::vector<int>>& broken ){

        H=n;
        W=m;
        Ntotal = H*W;

        std::vector<std::vector<char>> brks {};//<h,w>
        brks.resize( H, std::vector<char>(W, 0));
        for( auto &e : broken ){
            brks[e[0]][e[1]]=1;// 无效边
        }

        // 这个装填实现，其实浪费了一部分性能
        // 只需要登记 mat[km][kn] 信息即可
        mat.resize( Ntotal, std::vector<char>(Ntotal, 0));
        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                if( brks[h][w]==1 ){ continue; }
                int k = h*W + w;
                //-- right --//
                if( w+1<W && brks[h][w+1]==0 ){
                    int kr = h*W + (w+1);
                    mat[k][kr]=1;
                    mat[kr][k]=1;
                }
                //-- down --//
                if( h+1<H && brks[h+1][w]==0 ){
                    int kd = (h+1)*W + w;
                    mat[k][kd]=1;
                    mat[kd][k]=1;
                }
            }
        }

        pre.resize( Ntotal, -1 );

        int ans = 0;
        // 遍历每个 左集元素（奇数项）
        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                if( ((h+w)&1)==0 ){ continue; }// 跳过 偶数项
                vis.clear();
                vis.resize( Ntotal, 0 );
                if( check(h*W+w) ){ ans++; }
            }
        }
        return ans;

    }
};






//  官网代码 复制 
//  其实暂时没看懂...
class S0{

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
        {1,1},
        {2,1}
    };

    auto ret = S1{}.domino( 3,2,b );
    cout<<"ret:"<<ret<<endl;

    
    debug::log( "\n~~~~ leet: LCP_04 :end ~~~~\n" );
}
}//~
