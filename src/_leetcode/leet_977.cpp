/*
 * ====================== leet_977.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 977. 有序数组的平方
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_977 {//~


// 朴素法 8%, 25%
// 这题 其实考的是 排序
// 如果借用现成的 mset 来排序，成绩不会太好看 ...
class S{
public:
    // 1<= len <= 10000
    // -10000 <= [i] <= 10000
    std::vector<int> sortedSquares( std::vector<int>& A ){

        std::multiset<int> mset {};
        for( int i : A ){
            mset.insert(  i*i );
        }
        return std::vector<int>(mset.begin(), mset.end());
    }
};





// 双指针法
// 先指向两头，然后向中间遍历，
// 一个指针只负责 负数，一个指针负责 正数和0


// 一个小优化点在于，在原始方案中，先倒序填充数组 从大到小，之后 反转
// 可以用 for 循环，从尾部开始填起


//   70%   25%
class S2{
public:
    // 1<= len <= 10000
    // -10000 <= [i] <= 10000
    std::vector<int> sortedSquares( std::vector<int>& A ){

        int N = static_cast<int>(A.size());
        int l=0;  // 只负责 负数
        int r=N-1;// 只负责 正数和0

        std::vector<int> outs (N,0);

        for(int i=N-1; i>=0; i-- ){// 小小的优化点
            int lv = A[l]<0 ?  -A[l] : -1;
            int rv = A[r]>=0 ? A[r] : -1;
            if( lv >= rv ){
                outs[i] = lv*lv;
                l++;
            }else{
                outs[i] = rv*rv;
                r--;
            }
        }
        return outs;

    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 977 :end ~~~~\n" );
}
}//~
