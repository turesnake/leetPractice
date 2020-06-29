/*
 * ====================== leet_1240.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1240. 铺瓷砖
 */
#include "innLeet.h"


namespace leet_1240 {//~


// 可能是个 四维dp，dp[n][m][kn][km]
// 四个参数，表达一个 矩形 n*m 挖去 kn*km 后的体积内，最少瓷砖数
// 在上面数据中，n>=m, kn/km 则要对齐与 n/m
// ---
// 每一个 dp[][][][] 的最优解，都可以从 4 种蚕食情况中选取


// 参考答案中，暂时没有什么很好的解...



// 自实现版dp   14%   100%
// 这个实现的问题在于，它的代码部分太繁杂了。无法一次写清，需要很多次检测和调试
class S{
public:
    // 1 <= n <= 13 (h)
    // 1 <= m <= 13 (w)
    int tilingRectangle( int n, int m ){

        if( n==m ){ return 1; }
        if( n<m ){ std::swap(n,m); }// 确保 n>=m
        if( n==1 && m==1 ){ return 1; }
        if( m==1 ){ return n; }

        // 四维 dp[n][m][kn][km]  n>=m, kn<n, km<m
        std::vector<std::vector<std::vector<std::vector<int>>>> dp (
            14, std::vector<std::vector<std::vector<int>>>(
                14, std::vector<std::vector<int>>(
                    14, std::vector<int>( 14, 0 )
                )
            )
        );

        // 手写 初始情况
        dp[2][2][0][0] = 1;
        dp[2][2][1][1] = 3;
        // [h][1][0][0]
        for( int h=1; h<=n; h++ ){
            dp[h][1][0][0] = h;
        }

        // 自动生成 oth
        for( int h=3; h<=n; h++ ){
        for( int w=2; w<=h && w<=m; w++ ){

        //-- [1~h][1~w] --//
        for( int hi=h-1; hi>=1; hi-- ){
        for( int wi=w-1; wi>=1; wi-- ){

            if( h==w && hi<wi ){
                dp[h][w][hi][wi] = dp[h][w][wi][hi];
                continue;
            }

            // 收集4种可能性，选其中最小的 
            int mmin = INT_MAX;
            int owi = w-wi;
            int ohi = h-hi;
 
            // -1- 挖去方形: wi*wi
            if( wi == ohi ){// 正好被削成一个 矩形
                int nh = h;
                int nw = owi;
                if( nh<nw ){ std::swap( nh,nw ); }
                mmin = std::min( mmin, dp[nh][nw][0][0] );
                //debug::log( "  1(a)~ [{},{},{},{}], val={}", nh,nw,0,0, dp[nh][nw][0][0] );
            }else if( wi < ohi ){
                mmin = std::min( mmin, dp[h][w][hi+wi][wi] );
                //debug::log( "  1(b)~ [{},{},{},{}], val={}", h,w,hi+wi,wi, dp[h][w][hi+wi][wi] );
            }

            // -2- 挖去方形: hi*hi
            if( hi == owi ){// 正好被削成一个 矩形
                int nh = ohi;
                int nw = w;
                if( nh<nw ){ std::swap( nh,nw ); }
                mmin = std::min( mmin, dp[nh][nw][0][0] );
                //debug::log( "  2(a)~ [{},{},{},{}], val={}", nh,nw,0,0, dp[nh][nw][0][0] );
            }else if( hi < owi ){
                mmin = std::min( mmin, dp[h][w][hi][hi+wi] );
                //debug::log( "  2(b)~ [{},{},{},{}], val={}", h,w,hi,hi-wi, dp[h][w][hi][hi+wi] );
            }

            // -3- 挖去方形: ohi*ohi 
            if( ohi == w ){// 正好被削成一个 矩形
                int nh = hi;
                int nw = owi;
                if( nh<nw ){ std::swap( nh,nw ); }
                mmin = std::min( mmin, dp[nh][nw][0][0] );
                //debug::log( "  3(a)~ [{},{},{},{}], val={}", nh,nw,0,0, dp[nh][nw][0][0] );
            }else if( ohi<w && ohi>wi ){
                mmin = std::min( mmin, dp[h][owi][ohi][owi-(w-ohi)] );
                //debug::log( "  3(b)~ [{},{},{},{}], val={}", h,owi,ohi,owi-(w-ohi), dp[h][owi][ohi][owi-(w-ohi)] );
            }else if( ohi<wi ){
                mmin = std::min( mmin, dp[h][w-ohi][hi][wi-ohi] );
                //debug::log( "  3(c)~ [{},{},{},{}], val={}", h,w-ohi,hi,wi-ohi, dp[h][w-ohi][hi][wi-ohi] );
            }

        
            // -4- 挖去方形: owi*owi
            if( owi < hi ){
                int nh = h-owi; 
                int nw = w;
                int nhi = nh-ohi;
                int nwi = wi;
                if( nh<nw ){ 
                    std::swap( nh,nw ); 
                    std::swap( nhi, nwi );
                }
                mmin = std::min( mmin, dp[nh][nw][nhi][nwi] );
                //debug::log( "  4(a)~ [{},{},{},{}], val={}", nh,nw,nhi,nwi, dp[nh][nw][nhi][nwi] );
            }else if( owi != hi ){
                int nh = ohi;
                int nw = w;
                int nhi = ohi-(h-owi);
                int nwi = owi;
                if( nh<nw ){ 
                    std::swap( nh,nw ); 
                    std::swap( nhi, nwi );
                }
                mmin = std::min( mmin, dp[nh][nw][nhi][nwi] );
                //debug::log( "  4(b)~ [{},{},{},{}], val={}", nh,nw,nhi,nwi, dp[nh][nw][nhi][nwi] );
            }
            //cout<<"dp: h_"<<h<<" w_"<<w<<" hi_"<<hi<<" wi_"<<wi<<" :"<< mmin +1 <<""<< endl;

            dp[h][w][hi][wi] = mmin +1;
        }}  


        //-- [h][w][0][0] --//
        if( h==w ){
            dp[h][w][0][0] = 1;
        }else{
            int zh = h-w;
            int zw = w;
            if( zh<zw ){ std::swap(zh,zw); }
            int zMin = dp[zh][zw][0][0]; // 削去 m*m
            for( int k=1; k<w; k++ ){
                zMin = std::min( zMin, dp[h][w][k][k] );
            }
            dp[h][w][0][0] = zMin + 1;
        }

        }}
        return dp[n][m][0][0];

    }
};




//=========================================================//
void main_(){

    cout<<S{}.tilingRectangle( 12,13 )<<endl;


    
    debug::log( "\n~~~~ leet: 1240 :end ~~~~\n" );
}
}//~
