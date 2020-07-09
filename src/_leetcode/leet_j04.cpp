/*
 * ====================== leet_j04.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 04. 二维数组中的查找
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_j04 {//~


// 利用 递增矩阵 左下角 和 右上角 的特殊性，
// 从 左下角开始，以逐个比较的方式，向 右上方 遍历
// 直到 找到目标元素，or 走出 矩阵区间

// 实现起来很简单，没有用上 二分查找
// 时间 O(H+W)
// 空间 O(1)

//   83%   100%
class S{
public:
    // 0 <= n,m <= 1000
    bool findNumberIn2DArray( std::vector<std::vector<int>>& matrix, int target ){

        if( matrix.empty() || matrix[0].empty() ){ return false; }

        int H = static_cast<int>(matrix.size());
        int W = static_cast<int>(matrix[0].size());

        int w=0;
        int h=H-1;
        while( w<W && h>=0 ){
            if( matrix[h][w]<target ){
                w++;
            }else if( matrix[h][w]>target ){
                if( w>0 ){ w--; }
                h--;
            }else{
                return true;
            }
        }
        return false;

    }
};



//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: j04 :end ~~~~\n" );
}
}//~
