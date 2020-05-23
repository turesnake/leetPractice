/*
 * ====================== leet_m16_17.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.22
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 16.17. 连续数列
 * 与 53, m42 题相同
 */
#include "innLeet.h"


namespace leet_m16_17 {//~


struct Elem{
    Elem( int v_, bool b_ ): val(v_), isUsed(b_){}
    int  val;
    bool isUsed; // 是否已经被持有过，此位可以拓展为：持有次数
};



// 优化了 dp 空间。  34.46%，100%
// 设计上好像存在问题，
int maxSubArray( std::vector<int> & nums ){

    int N = static_cast<int>(nums.size());
    if( N==0 ){ return 0; }

    std::vector<Elem> dp1 { Elem{INT_MIN,false}, Elem{nums.at(0),true} };
    std::vector<Elem> dp2 ( 2, Elem{INT_MIN,false} );
    auto *fst = &dp1; // 交替使用，节省 dp空间
    auto *lst = &dp2; // 交替使用，节省 dp空间

    for( int n=1; n<N; n++ ){
        //--- 本回合持有 ---
        int mmax = (fst->at(0).isUsed==false) ?
            nums.at(n) + std::max(fst->at(0).val, fst->at(1).val) :// 上一回合的 “不持有位”，没被持有过
            nums.at(n) + fst->at(1).val;// 上一回合的 “不持有位”，已经被持有过
        lst->at(1).val = std::max( mmax, nums.at(n) );// 继承 或者彻底抛弃之前的片段
        lst->at(1).isUsed = true;

                    // 在 53 题中，有很好的实现 

        //--- 本回合不持有 ---
        if( fst->at(0).val >= fst->at(1).val ){
            lst->at(0) = fst->at(0); // 完整继承
        }else{
            lst->at(0).val = fst->at(1).val;
            lst->at(0).isUsed = true;
        }
        std::swap(fst,lst);
    }
    return std::max( fst->at(0).val, fst->at(1).val ); 
}












//=========================================================//
void main_(){

    //std::vector<int> v { -2,1,-3,4,-1,2,1,-5,4 };
    //std::vector<int> v { -2, 1, -3, 4 };
    std::vector<int> v { -2,-10,-3,-4 };

    cout << maxSubArray(v) << endl;
    
    


    debug::log( "\n~~~~ leet: m16_17 :end ~~~~\n" );
}
}//~
