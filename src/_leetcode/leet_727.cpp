/*
 * ====================== leet_727.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 727. 最小窗口子序列
 */
#include "innLeet.h"


namespace leet_727 {//~


// 二维dp


// 高分方法用了滑动窗口...


//   9%   33%
class S{

struct Elem{
    int  head   {-1};// head idx
    bool isFind {false}; // 本层的字母是否找到
};

public:
    // 1<= s.len <= 20000
    // 1<= t.len <= 100
    std::string minWindow( std::string S, std::string T ){

        int W = static_cast<int>(S.size());
        int H = static_cast<int>(T.size());
        if( W<H ){ return ""; }

        std::vector<std::vector<Elem>> dp (H, std::vector<Elem>(W, Elem{}));

        // [0][w]
        bool isFindFst = false;
        for( int w=0; w<W; w++ ){
            if( S[w] == T[0] ){
                dp[0][w] = Elem{ w, true };
                if( !isFindFst ){ isFindFst = true; }
            }
        }
        if( !isFindFst ){ return ""; } // 首字母就没找到

        // [oth][w]
        for( int h=1; h<H; h++ ){
            bool isFindChar = false;

            for( int w=1; w<W; w++ ){
                // 优先选择 左上角
                if( dp[h-1][w-1].isFind ){
                    dp[h][w].head = dp[h-1][w-1].head;
                    dp[h][w].isFind = S[w]==T[h];
                    if( dp[h][w].isFind ){ isFindChar = true; }
                    continue;
                }

                // 其次考虑 左侧
                if( dp[h][w-1].head >= 0 ){ // 左侧值 要被考虑
                    if( !dp[h][w-1].isFind ){
                        // 万一 左侧已经找到 本层字母，本位设空
                        // 如果 左侧未找到，本位 继续帮着找
                        dp[h][w].head = dp[h][w-1].head;
                        dp[h][w].isFind = S[w]==T[h];
                        if( dp[h][w].isFind ){ isFindChar = true; }
                    }
                }
            }
            // 本层没找到 目标字母，直接 查找失败
            if( !isFindChar ){ return ""; }
        }

        int ll = 0;
        int rr = 0;
        int minOff = INT_MAX;

        for( int w=0; w<W; w++ ){
            if( dp[H-1][w].isFind ){
                int off = w - dp[H-1][w].head;
                if( off < minOff ){
                    minOff = off;
                    ll = dp[H-1][w].head;
                    rr = w;
                }
            }
        }
        return std::string( S, ll, rr-ll+1 );


    }
};



//=========================================================//
void main_(){

    std::string s = "a";
    std::string t = "k";

    auto ret = S{}.minWindow( s, t );
    cout<<"ret:"<<ret<<endl;

    
    debug::log( "\n~~~~ leet: 727 :end ~~~~\n" );
}
}//~
