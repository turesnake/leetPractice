/*
 * ====================== leet_m10_09.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 10.09. 排序矩阵查找
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m10_09 {//~


// 左下角 查找法
//   56%  100%
class S{
public:
    bool searchMatrix( std::vector<std::vector<int>>& matrix, int target ){

        if( matrix.empty() || matrix[0].empty() ){ return false; }
        int H = static_cast<int>(matrix.size());
        int W = static_cast<int>(matrix[0].size());

        int w = 0;
        int h = H-1;
        while( h>=0 && w<W ){
            
            if( matrix[h][w]>target ){
                h--;
            }else if( matrix[h][w]<target ){
                w++;
            }else{// ==
                return true;
            }
        }
        return false;

    }
};



//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: m10_09 :end ~~~~\n" );
}
}//~
