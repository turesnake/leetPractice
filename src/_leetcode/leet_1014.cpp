/*
 * ===================== leet_1014.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1014. 最佳观光组合
 */
#include "innLeet.h"


namespace leet_1014 {//~


// 用一种很巧的方法去解   60%  25%

// 将值减去自己的 idx，就能抵消掉各个值之间的距离
// 最后逐个计算每个元素的 解时，把 idx 再加回来，就行了

// 然后通过倒序遍历，维护 v 中最大值，

class S{
public:
    // 2 <= A.len <= 50000
    // 1 <= A[i] <= 1000
    int maxScoreSightseeingPair( std::vector<int>& A ){

        int N = static_cast<int>(A.size());

        std::vector<int> v (N,0);
        for( int i=0; i<N; i++ ){
            v.at(i)= A.at(i)-i;
        }

        int out = 0;
        int maxVVal = v.back(); // 倒叙找到的 v 中最大值

        // 倒序遍历，计算每个元素的 最高分
        for( int i=N-2; i>=0; i-- ){
            int tmp = A.at(i) + i + maxVVal;
            out = std::max( out, tmp );
            maxVVal = std::max(maxVVal, v.at(i));
        }

        return out;


    }
};





//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 1014 :end ~~~~\n" );
}
}//~
