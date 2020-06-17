/*
 * ===================== leet_862.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 862. 和至少为 K 的最短子数组
 */
#include "innLeet.h"


namespace leet_862 {//~


// 求一个区间长度
// 要么是 dp，要么是滑动窗口, 也可能是前缀和
// 因为存在负数，目前看来更像 dp


// 在参考了答案后，此题的核心为：前缀和，单调"队列"(vec模拟)，二分查找


// 21%  100%
class S{

struct Elem{
    int val {};
    int idx {};
};

public:
    // 1 <= A.len <= 50000
    // -10 ^ 5 <= A[i] <= 10 ^ 5
    // 1 <= K <= 10 ^ 9
    int shortestSubarray( std::vector<int>& A, int K ){


        int N = static_cast<int>(A.size());

        std::vector<int> preSums( N,0 );
        std::vector<Elem> que {};// 伪递增队列

        int minLen = INT_MAX;

        // fst val
        int fstVal = A.at(0);
        if( fstVal>=K ){ return 1;}
        preSums.at(0) = fstVal;
        que.push_back( Elem{fstVal, 0} );

        // oth val
        for( int i=1; i<N; i++ ){
            int curVal = A.at(i);

            if( curVal>=K ){ return 1;}

            int curPreSum = preSums.at(i-1) + curVal;
            preSums.at(i) = curPreSum;

            if( curPreSum>=K ){ 
                minLen = std::min( minLen, i+1 );
            }

            if( que.front().val > curPreSum ){// 本回合前缀和，小于单调队列中任何值
                que.clear();
                que.push_back( Elem{curPreSum,i} );
            }else{
                while( !que.empty() && que.back().val > curPreSum ){
                    que.pop_back();
                }
                que.push_back( Elem{curPreSum,i} );
            }

            //cout<<"que:---\n  "; for( auto &e : que ){ cout<<e.val<<", "; }cout<<endl;

            int tgtVal = curPreSum - K;
            if( que.front().val <= tgtVal ){
                //cout<<"--"<<endl;
                // 意味着，本回合存在解
                // 二分查找 获得 解区间右边界
                int l=0; 
                int r=static_cast<int>(que.size())-1;
                while( l<=r ){
                    if( l==r ){ 
                        //cout<<"find:"<<i-l<<endl;
                        minLen = std::min( minLen, i-que.at(l).idx ); // 本回合的最短区间长度
                        break;
                    }
                    int mid = l+(r-l)/2+1;//mid-right
                    if( que.at(mid).val > tgtVal ){
                        r = mid-1; // 坚决剔除大值
                    }else{
                        l = mid; // 小于等于值，保留到下一回合
                    }
                }
            }
        }
        return minLen==INT_MAX ? -1 : minLen;

    }
};






//=========================================================//
void main_(){

    std::vector<int> v { 2,-1,3,0,1,-3,4,2,-1,-2,1 };

    auto ret = S{}.shortestSubarray( v,5 );
    cout<<"ret:"<<ret<<endl;


    debug::log( "\n~~~~ leet: 862 :end ~~~~\n" );
}
}//~
