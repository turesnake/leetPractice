/*
 * ====================== leet_85.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 85. 最大矩形
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_85 {//~





// 这题并不能用 正方形题 的思路简单套用

// 有的解法，用到了 单调栈，遍历每一层，以每层为底，将高度压缩
// 然后对每一层的情况做统计 
// 类似 84 题



// dp 
//
//        目前的解法不对 
//
class S{

struct Elem{
    int w {0};
    int h {0};
};

    std::vector<std::vector<Elem>> dp {};

    void dp_resize( int w, int h ){
        dp.resize( h, std::vector<Elem>( w, Elem{0,0} ) );
    }

    Elem &dp_at( int w, int h ){
        return dp.at(h).at(w);
    }


public:
    int maximalRectangle( std::vector<std::vector<char>>& matrix ){

        if( matrix.empty() || matrix.at(0).empty() ){ return 0; }
        int H = static_cast<int>(matrix.size());
        int W = static_cast<int>(matrix.at(0).size());
        dp_resize(W,H);
        int maxW = 0;
        int maxH = 0;
        // 手动实现边界
        for( int w=1; w<W; w++ ){
            if( matrix.at(0).at(w)=='1' ){
                auto &elem = dp_at(w,0);
                elem.w = dp_at(w-1,0).w + 1;
                elem.h = 1;
                maxW = std::max(maxW, elem.w );
                maxH = 1;
            }
        }
        for( int h=1; h<H; h++ ){
            if( matrix.at(h).at(0)=='1' ){
                auto &elem = dp_at(0,h);
                elem.w = 1;
                elem.h = dp_at(0,h-1).h + 1;
                maxW = std::max(maxW, elem.w );
                maxH = std::max(maxH, elem.h);
            }
        }
        // 后续数据
        for( int h=1; h<H; h++ ){
            for( int w=1; w<W; w++ ){
                auto &elem = dp_at(w,h);
                if( matrix.at(h).at(w)=='1' ){
                    int tmpW = std::max(dp_at(w,h-1).w-1, 0);// 不能小于0
                    elem.w = std::min( std::min(dp_at(w-1,h-1).w, dp_at(w-1,h).w), tmpW) + 1;
                    int tmpH = std::max(dp_at(w-1,h).h-1, 0);// 不能小于0
                    elem.h = std::min( std::min(dp_at(w-1,h-1).h, dp_at(w,h-1).h), tmpH) + 1;
                    maxW = std::max( maxW, elem.w );
                    maxH = std::max( maxH, elem.h );
                }else{
                    elem.w = 0;
                    elem.h = 0;
                }
            }
        }



            cout<<"dp:"<<endl;
            for( int h=0; h<H; h++ ){
                for( int w=0; w<W; w++ ){
                    auto &e = dp_at(w,h);
                    cout<<"["<<e.w<<","<<e.h<<"], ";
                }cout<<endl;
            }cout<<"W:"<<maxW<<", H:"<<maxH<<endl;


        return maxW*maxH;
    }
};




//=========================================================//
void main_(){

    
    std::vector<std::vector<char>> v {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    
    /*
    std::vector<std::vector<char>> v {
        {'1'}
    };
    */


    cout<<"ret: "<< S{}.maximalRectangle(v)<<endl;

    
    debug::log( "\n~~~~ leet: 85 :end ~~~~\n" );
}
}//~
