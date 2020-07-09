/*
 * ====================== leet_240.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.07
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 240. 搜索二维矩阵 II
 */
#include "innLeet.h"


namespace leet_240 {//~

// 二分查找
// 在每一行中，找到 大于等于 tgt 的最小值，以此确定 right 边界


// 并不是最快的方法


// 另一种标准的办法就是 如 j04 题所写的，从左下角开始的 逐元素收缩法
// 虽然 没有使用 二分查找，但反而更快了


//  13%   100%
class S{
public:
    bool searchMatrix( std::vector<std::vector<int>>& matrix, int target ){

        if( matrix.empty() || matrix[0].empty() ){ return false; }
        if( target<matrix[0][0] || target>matrix.back().back() ){ return false; }

        int H = static_cast<int>(matrix.size());
        int W = static_cast<int>(matrix[0].size());

        int r=W-1;

        // 找到 第一个 有效行
        int h=0;
        for(; h<H; h++ ){
            if( target>=matrix[h][0] && target<=matrix[h].back() ){ break; }
        }

        for(; h<H; h++ ){
            if( target < matrix[h][0] ){ return false; }
            auto &line = matrix[h];

            // 寻找 右边界
            int l=0;
            while( l<=r ){
                if( l==r ){
                    if( line[l]==target ){ return true; }
                    break;
                }
                int mid = l+(r-l)/2;//mid-left
                if( line[mid] == target ){
                    return true; // find
                }else if( line[mid] > target ){
                    r = mid; // 保留到 下一回合
                }else{
                    l = mid+1; // 剔除
                }
            }
        }
        return false;
        
    }
};



//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 240 :end ~~~~\n" );
}
}//~
