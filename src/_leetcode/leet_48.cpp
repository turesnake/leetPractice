/*
 * ====================== leet_48.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 48. 旋转图像
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_48 {//~


// 从空间上 还是时间上，都是最标准的思路


// 逐层旋转  100%  100%
// 每一层，都可以用一个 vector(4,0) 4个元素的数组 来实现旋转
class S{
public:
    // 矩阵是 正方形 
    void rotate( std::vector<std::vector<int>>& matrix ){

        if( matrix.empty() || matrix.at(0).empty() ){ return; }

        int N = static_cast<int>(matrix.size());
        int l=0;
        int r=N-1;
        std::vector<int> rot (4,0); // 辅助容器

        while( l<r ){
            for( int i=l; i<r; i++ ){// 
                // 收集四个元素
                rot.at(0) = matrix.at(l).at(i);
                rot.at(1) = matrix.at(i).at(r);
                rot.at(2) = matrix.at(r).at(r-(i-l));
                rot.at(3) = matrix.at(r-(i-l)).at(l);
                // 旋转后重分配
                matrix.at(l).at(i) = rot.at(3);
                matrix.at(i).at(r) = rot.at(0);
                matrix.at(r).at(r-(i-l)) = rot.at(1);
                matrix.at(r-(i-l)).at(l) = rot.at(2);
            }
            l++;
            r--;
        }
    }
};




//=========================================================//
void main_(){
    
    debug::log( "\n~~~~ leet: 48 :end ~~~~\n" );
}
}//~
