/*
 * ====================== leet_221.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 221. 最大正方形
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_221 {//~


// dp  23%  100%
// 每个状态，记录 自己为 正方形 right-down 时，正方形最大尺寸
// = std::min(左上，左，上) + 1
class S{

    std::vector<std::vector<int>> dp {};

    void dp_resize( int w, int h ){
        dp.resize( h, std::vector<int>(w,0) );
    }

    int &dp_at( int w, int h ){
        return dp.at(h).at(w);
    }

public:
    int maximalSquare( std::vector<std::vector<char>>& matrix ){

        if( matrix.empty() || matrix.at(0).empty() ){ return 0; }
        int H = static_cast<int>(matrix.size());
        int W = static_cast<int>(matrix.at(0).size());
        dp_resize(W,H);
        int mmax = 0;
        // 手动初始化
        for( int w=0; w<W; w++ ){
            if( matrix.at(0).at(w)=='1' ){
                dp_at(w,0) = 1;
                mmax = 1;
            }
        }
        for( int h=1; h<H; h++ ){
            if( matrix.at(h).at(0)=='1' ){
                dp_at(0,h) = 1;
                mmax = 1;
            }
        }
        // 后续数据
        for( int h=1; h<H; h++ ){
            for( int w=1; w<W; w++ ){
                if( matrix.at(h).at(w)=='1' ){
                    dp_at(w,h) = std::min(std::min(dp_at(w-1,h),dp_at(w,h-1)), dp_at(w-1,h-1)) + 1;
                    mmax = std::max( mmax, dp_at(w,h) );
                }else{
                    dp_at(w,h) = 0;
                }
            }
        }

        cout<<"dp:"<<endl;
        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                cout<<dp_at(w,h)<<", ";
            }cout<<endl;
        }

        return mmax*mmax;
    }
};



//=========================================================//
void main_(){

    /*
    std::vector<std::vector<char>> v {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    */

    std::vector<std::vector<char>> v {
        {'1'}
    };


    cout<<"ret: "<< S{}.maximalSquare(v)<<endl;

    
    debug::log( "\n~~~~ leet: 221 :end ~~~~\n" );
}
}//~
