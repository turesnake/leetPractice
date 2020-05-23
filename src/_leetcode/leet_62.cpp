/*
 * ====================== leet_62.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 62. 不同路径
 */
#include "innLeet.h"


namespace leet_62 {//~



// 原版，未优化 dp 空间
int uniquePaths_1(int m, int n) {
        
    std::vector<std::vector<int>> dp (n, std::vector<int>(m,0) );
    // 第一横行
    for( int i=0; i<m; i++ ){
        dp.at(0).at(i) = 1;
    }
    // 第一纵列
    for( int i=1; i<n; i++ ){
        dp.at(i).at(0) = 1;
    }
    for( int j=1; j<n; j++ ){
        for( int i=1; i<m; i++ ){
            dp.at(j).at(i) = dp.at(j-1).at(i) + dp.at(j).at(i-1);
        }
    }
    return dp.back().back();
}


// 压缩 dp 空间
int uniquePaths_2(int m, int n){

    std::vector<int> dp1 ( m, 1 );
    std::vector<int> dp2 ( m, 0 );
    auto *fst = &dp1;
    auto *lst = &dp2;
    for( int j=1; j<n; j++ ){
        for( int i=0; i<m; i++ ){
            lst->at(i) = (i==0) ? 1 : fst->at(i) + lst->at(i-1);
        }
        std::swap( lst,fst );
    }
    return fst->back();
}







//=========================================================//
void main_(){

    cout << uniquePaths_1( 1,1 ) << endl;
    cout << uniquePaths_2( 1,1 ) << endl;
    




    debug::log( "\n~~~~ leet: 62 :end ~~~~\n" );
}
}//~
