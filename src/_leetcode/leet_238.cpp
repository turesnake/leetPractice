/*
 * ====================== leet_238.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 238. 除自身以外数组的乘积
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_238 {//~


// 非常奇妙的思路...


// 前缀积，后缀积
// 一个元素，等于 前缀积 * 后缀积
class S{
public:
    // 在完整实现中，需要用 两个数组，分别记录每个元素的 前缀积， 和 后缀积
    // 但是这样会破坏题目 空间O[1] 的要求
    // 所以将 后缀积 压缩为 一个 值来累计
    // 但这样一来，把代码变得 难懂了
    std::vector<int> productExceptSelf( std::vector<int>& nums ){

        int N = static_cast<int>(nums.size());
        std::vector<int> outs (N,1);
        //-- 将每个元素的 前缀积，直接记录在 outs 中
        for( int i=1; i<N; i++ ){// [i-1], [i]
            outs.at(i) = outs.at(i-1)*nums.at(i-1);
        }
        //-- 反向遍历数组，用 right，记录 后缀积
        int right = 1;
        for( int i=N-2; i>=0; i-- ){// [i],[i+1]
            right *= nums.at(i+1);
            outs.at(i) *= right;
        }
        return outs;
    }
};



// 另一个解法：
// 从数组两端相向遍历，用 left，right 两个值，分别记录 前缀积 和 后缀积
// 在两指针 相交之前，把各自的 积，记录在 outs 数组内
// 相交后，用自身的值，配合 数组中记录的另一个值，相乘 得到最终值
// 很精妙的想法



//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 238 :end ~~~~\n" );
}
}//~
