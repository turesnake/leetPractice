/*
 * ====================== leet_718.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_718 {//~



// 朴素 dp 实现会超时
// 因为它承载了太多不相干的信息



// 5%, 33%
// dp， 对 二维数据表的 一种灵活应用 
// 不需要存储 in/out 两层数据，
// - 当本回合两字母相同时，通过查表，得知 [h-1][w-1] 位置，累积的长度
// - 当本回合两字母不同时，状态直接写 0
//   最大值 无法在 dp 尾收集，而是要在遍历过程中，即时更新
class S{
    std::vector<std::vector<int>> dp {};

    void dp_resize( int w, int h ){
        dp.resize( h, std::vector<int>( w ) );
    }

    int &dp_at( int w, int h ){
        return dp.at(h).at(w);
    }

public:
    // 1 <= len(A), len(B) <= 1000
    // 0 <= A[i], B[i] < 100
    int findLength( std::vector<int>& A, std::vector<int>& B ){

        if( A.empty() || B.empty() ){ return 0; }
        int Na = static_cast<int>(A.size());// w
        int Nb = static_cast<int>(B.size());// h
        dp_resize( Na, Nb );
        int mmax = 0;
        // 手动装填 h==0 行
        for( int w=0; w<Na; w++ ){
            if( A.at(w)==B.at(0) ){
                dp_at(w,0) = 1;
                if( mmax==0 ){ mmax = 1; }
            }else{
                dp_at(w,0) = 0;
            }
        }
        // 手动装填 w==0 列
        for( int h=1; h<Nb; h++ ){
            if( A.at(0)==B.at(h) ){
                dp_at(0,h) = 1;
                if( mmax==0 ){ mmax = 1; }
            }else{
                dp_at(0,h) = 0;
            }
        }
        for( int h=1; h<Nb; h++ ){
            for( int w=1; w<Na; w++ ){
                if( A.at(w)==B.at(h) ){
                    // 本回合，两字母相同
                    // 要么是本回合从头开始  (左上角回合.inMax == 0)
                    // 要么是继承上回合的 串 (左上角回合.inMax > 0)
                    dp_at(w,h) = dp_at(w-1,h-1) + 1;
                    mmax = std::max( mmax, dp_at(w,h) );
                }else{
                    // 本回合，两字母 不同
                    dp_at(w,h) = 0;

                }
            }
        }
        /*
        cout<<"dp:"<<endl;
        for( int h=0; h<Nb; h++ ){
            for( int w=0; w<Na; w++ ){
                cout<< dp_at(w,h) <<", ";
            } cout<<endl;
        }
        */
        return mmax;
    }
};



//=========================================================//
void main_(){

    //std::vector<int> a { 1,2,3,2,1 };
    //std::vector<int> b { 3,2,1,4,7 };

    std::vector<int> a { 1,1,0,0,1 };
    std::vector<int> b { 1,1,0,0,0 };




    cout<<"ret: "<<S{}.findLength(a,b)<<endl;

    
    debug::log( "\n~~~~ leet: 718 :end ~~~~\n" );
}
}//~
