/*
 * ====================== leet_931.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 931. 下降路径最小和
 */
#include "innLeet.h"


namespace leet_931 {//~




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


// H,W: [1,100]
// elem: [-100,100] 有负数
int minFallingPathSum( std::vector<std::vector<int>>& A){

    int H = static_cast<int>(A.size());
    int W = static_cast<int>(A.at(0).size());
    std::vector<int> dp1 ( A.back().begin(), A.back().end() );
    std::vector<int> dp2 ( W, 0 );
    auto *fst = &dp1; // 这次倒序遍历，fst 指向更下的一行
    auto *lst = &dp2;

    for( int j=H-2; j>=0; j-- ){// 倒序遍历层
        for( int i=0; i<W; i++ ){
            int l = (i==0) ? INT_MAX : fst->at(i-1);
            int m = fst->at(i);
            int r = (i==W-1) ? INT_MAX : fst->at(i+1);
            lst->at(i) = std::min(std::min(l,m),r) + A.at(j).at(i);
        }
        std::swap(fst,lst);
    }
    int mmin {INT_MAX};
    for( int i : *fst ){ mmin = std::min(mmin,i); }
    return mmin;
}






//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        {3}
    };

    cout << minFallingPathSum(v) << endl;
    

    debug::log( "\n~~~~ leet: 931 :end ~~~~\n" );
}
}//~
