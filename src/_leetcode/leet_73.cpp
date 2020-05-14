/*
 * ====================== leet_73.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 73. 矩阵置零
 */
#include "innLeet.h"


namespace leet_73 {//~



void setZeroes( std::vector<std::vector<int>>& matrix ){

    if( matrix.empty() || matrix.at(0).empty() ){ return; }
    int H = matrix.size();
    int W = matrix.at(0).size();
    std::unordered_set<int> ws {};
    std::unordered_set<int> hs {};
    // find 0
    for( int h=0; h<H; h++ ){
        for( int w=0; w<W; w++ ){
            if( matrix.at(h).at(w) == 0 ){
                hs.insert(h);
                ws.insert(w);
            }
        }
    }
    // change h
    for( const auto h : hs ){
        for( auto &i : matrix.at(h) ){
            i = 0;
        }
    }
    // change w
    for( const auto w : ws ){
        for( int h=0; h<H; h++ ){
            matrix.at(h).at(w) = 0;
        }
    }  
}




//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    setZeroes( v );

    int H = v.size();
    int W = v.at(0).size();

    for( int h=0; h<H; h++ ){
        for( int w=0; w<W; w++ ){
            cout << "  " << v.at(h).at(w) << ", ";
        }
        cout << endl;
    }


    debug::log( "\n~~~~ leet: 73 :end ~~~~\n" );
}
}//~
