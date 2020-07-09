/*
 * ====================== leet_832.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 832. 翻转图像
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_832 {//~



//   72%   100%
class S{
public:
    // 1 <= A.length = A[0].length <= 20
    // 0 <= A[i][j] <= 1
    std::vector<std::vector<int>> flipAndInvertImage( std::vector<std::vector<int>>& A ){


        int H = static_cast<int>(A.size());
        int W = static_cast<int>(A[0].size());
        std::vector<std::vector<int>> out (H, std::vector<int>(W, 0));

        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                int rw = W-w-1;
                if( A[h][rw] == 0 ){ out[h][w] = 1; }
            }
        }
        return out;

    }
};



//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 832 :end ~~~~\n" );
}
}//~
