/*
 * ====================== leet_120.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 120. 三角形最小路径和
 */
#include "innLeet.h"


namespace leet_120 {//~



// 三角形，第0行1个元素，然后逐行递增
int minimumTotal( std::vector<std::vector<int>>& triangle ){

    int H = static_cast<int>(triangle.size()); // 行数
    if( H==0 ){ return 0; }
    // 偷懒，直接利用 原始数组空间，不再额外分配 dp 空间
    // 第一行数据不改动
    for( int h=1; h<H; h++ ){
        int W = h+1;// 本行元素个数
        triangle.at(h).at(0) += triangle.at(h-1).at(0);    // 行首元素
        triangle.at(h).at(W-1) += triangle.at(h-1).at(W-2);// 行尾元素
        for( int w=1; w<W-1; w++ ){// 中部元素
            triangle.at(h).at(w) += std::min( triangle.at(h-1).at(w), triangle.at(h-1).at(w-1) ); 
        }
    }
    int mmin = INT_MAX;
    for( int i : triangle.back() ){
        mmin = std::min( mmin, i );
    }
    return mmin;
}





//=========================================================//
void main_(){

    /*
    std::vector<std::vector<int>> v {
        {2},
        {3,4},
        {6,5,1},
        {4,1,8,3}
    };
    */

    std::vector<std::vector<int>> v {
        {5}
    };

    cout << minimumTotal( v ) << endl;

    cout <<endl;
    for( auto &c : v ){
        for( int i : c ){
            cout << i <<", ";
        }
        cout << endl;
    }
    


    debug::log( "\n~~~~ leet: 120 :end ~~~~\n" );
}
}//~
