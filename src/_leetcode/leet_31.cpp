/*
 * ====================== leet_31.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 31. 下一个排列
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_31 {//~

// -1- 倒序遍历，找出第一对 顺序对
// -2- 遍历 顺序对 的右侧区间，找出 大于 [l] 的最小元素，两元素交换
// -3- 将右侧区间做 顺序排序 std::sort .... （其实可以直接用 std::reverse ）



// 这道题 巧得就离谱



//    51%   6%
class S{
public:
    void nextPermutation( std::vector<int>& nums ){

        int N = static_cast<int>(nums.size());
        if( N<2 ){ return; }
        if( N==2 ){
            std::swap( nums[0], nums[1] );
            return;
        }

        int l=N-2;
        int r=N-1;
        for(; l>=0 && nums[l]>=nums[r]; l--,r-- ){}

        if( l>=0 ){// 找到 顺序对
            for( int i=N-1; i>=r; i-- ){
                // 优化：
                // 原本是要 查找 右侧区间中，大于 [l] 的最小元素
                // 但右侧区间 一定是 倒序的，所以，直接倒序查找，找到的第一个就是我们要的
                // 而且，swap 置换后，右侧区间 还是保持 倒序规律
                if( nums[i]>nums[l] ){
                    std::swap( nums[l], nums[i] );
                    break;
                }
            }
        }

        std::reverse( nums.begin()+r, nums.end() );
            // 优化点
            // 本质上是做 排序，但是 尾部区间 一定是个 倒序区间，所以直接做 倒转即可
    }
};


//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 31 :end ~~~~\n" );
}
}//~
