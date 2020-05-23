/*
 * ====================== leet_63.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 63. 不同路径 II
 */
#include "innLeet.h"


namespace leet_63 {//~




// 26.6%, 100%
int uniquePathsWithObstacles( std::vector<std::vector<int>>& obstacleGrid){

    int H = static_cast<int>(obstacleGrid.size());
    int W = static_cast<int>(obstacleGrid.at(0).size());
    std::vector<int> dp1 ( W, 0 );
    std::vector<int> dp2 ( W, 0 );
    auto *fst = &dp1;
    auto *lst = &dp2;
    //--
    fst->at(0) = (obstacleGrid.at(0).at(0)==1) ? 0 : 1;
    for( int i=1; i<W; i++ ){
        fst->at(i) = (obstacleGrid.at(0).at(i)==1) ? 0 : fst->at(i-1);
    }
    /*
    cout <<"dp1:"<< endl;
    for( int i : dp1 ){
        cout << i << ", ";
    }
    cout << endl;
    */
    for( int j=1; j<H; j++ ){
        for( int i=0; i<W; i++ ){
            if( obstacleGrid.at(j).at(i)==1 ){
                lst->at(i) = 0;
            }else{
                lst->at(i) = (i==0) ?
                    fst->at(i) :
                    fst->at(i)+lst->at(i-1);
            }
        }
        std::swap(fst,lst);
    }
    return fst->back(); 
}






//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    cout << uniquePathsWithObstacles(v) << endl;
    




    debug::log( "\n~~~~ leet: 63 :end ~~~~\n" );
}
}//~
