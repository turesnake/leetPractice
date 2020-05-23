/*
 * ====================== leet_1143.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1143. 最长公共子序列
 */
#include "innLeet.h"


namespace leet_1143 {//~



// 未优化 dp 空间
int longestCommonSubsequence_1( std::string text1, std::string text2 ){

    int N1 = static_cast<int>(text1.size());// w [1,1000]
    int N2 = static_cast<int>(text2.size());// h [1,1000]
    std::vector<std::vector<int>> dp (N2+1,std::vector<int>(N1+1,0));
    for( int j=1; j<=N2; j++ ){
        for( int i=1; i<=N1; i++ ){
            int up = dp.at(j-1).at(i);
            int left = dp.at(j).at(i-1);
            int corner = text1.at(i-1)==text2.at(j-1) ? dp.at(j-1).at(i-1)+1 : INT_MIN;
            dp.at(j).at(i) = std::max(std::max(up,left),corner);
        }
    }
    /*
    cout << "dp:"<< endl;
    for( auto &c : dp ){
        for( int i : c ){ cout << i << ", "; }
        cout << endl;
    }
    cout << "======" << endl;
    */
    return dp.back().back();
}


// 压缩 dp 空间 8.93%, 100%
int longestCommonSubsequence_2( std::string text1, std::string text2 ){

    int N1 = static_cast<int>(text1.size());// w [1,1000]
    int N2 = static_cast<int>(text2.size());// h [1,1000]
    std::vector<int> dp1 ( N1+1, 0 );
    std::vector<int> dp2 ( N1+1, 0 );
    auto *fst = &dp1;
    auto *lst = &dp2;
    for( int j=1; j<=N2; j++ ){// [1,N2+1]
        for( int i=1; i<=N1; i++ ){// [1,N1+1]
            int up = fst->at(i);
            int left = lst->at(i-1);
            int corner = text1.at(i-1)==text2.at(j-1) ? fst->at(i-1)+1 : INT_MIN;
            lst->at(i) = std::max(std::max(up,left),corner);
        }
        std::swap(fst,lst);
    }
    return fst->back();
}



//=========================================================//
void main_(){

    std::string a { "a" };
    std::string b { "a" };
    
    cout << longestCommonSubsequence_1( a,b ) << endl;
    cout << longestCommonSubsequence_2( a,b ) << endl;



    debug::log( "\n~~~~ leet: 1143 :end ~~~~\n" );
}
}//~
