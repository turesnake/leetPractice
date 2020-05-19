/*
 * ====================== leet_198.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 198. 打家劫舍
 */
#include "innLeet.h"


namespace leet_198 {//~



// 动态规划
// 原型，不优化空间
int rob( std::vector<int>& nums ){

    if( nums.empty() ){ return 0; }
    if( nums.size()==1 ){ return nums.back(); }

    int Nnum = static_cast<int>(nums.size());
    std::vector<std::vector<int>> dp ( Nnum, std::vector<int> (2,0) ); // [Nnum][2]
        // [n][0] 本回合不偷
        // [n][1] 本回合偷

    dp.at(0).at(0) = 0;
    dp.at(0).at(1) = nums.at(0);


    for( int n=1; n<Nnum; n++ ){
        dp.at(n).at(0) = std::max(
            dp.at(n-1).at(0), // 上回合不偷
            dp.at(n-1).at(1)  // 上回合偷
        );
        dp.at(n).at(1) = nums.at(n) + dp.at(n-1).at(0); // 本回合偷，上回合一定不能不偷
    }

        
        cout << "-------" <<endl;
        for( int n=0; n<Nnum; n++ ){
            cout << dp.at(n).at(0) << ", " << dp.at(n).at(1) << endl;
        }
        cout << "-------" <<endl;
        

    return std::max( dp.back().at(0), dp.back().at(1) );
}



// 优化 dp 空间
int rob_2( std::vector<int>& nums ){

    if( nums.empty() ){ return 0; }
    if( nums.size()==1 ){ return nums.back(); }

    int Nnum = static_cast<int>(nums.size());
    std::vector<int> dp1 ( 2, 0 ); 
    std::vector<int> dp2 ( 2, 0 );
    auto *fst = &dp1; // 交替指针，压缩 do 空间
    auto *lst = &dp2; // 交替指针，压缩 do 空间
        // [n][0] 本回合不偷
        // [n][1] 本回合偷
    fst->at(0) = 0;
    fst->at(1) = nums.at(0);

    for( int n=1; n<Nnum; n++ ){
        lst->at(0) = std::max(
            fst->at(0), // 上回合不偷
            fst->at(1)  // 上回合偷
        );
        lst->at(1) = nums.at(n) + fst->at(0); // 本回合偷，上回合一定不能不偷
        std::swap( fst, lst );
    }




    return std::max( fst->at(0), fst->at(1) );
}






//=========================================================//
void main_(){

    std::vector<int> v { 1,2 };


    
    cout << "rob1 ret: " << rob( v ) << endl;
    cout << "rob2 ret: " << rob_2( v ) << endl;


    debug::log( "\n~~~~ leet: 198 :end ~~~~\n" );
}
}//~
