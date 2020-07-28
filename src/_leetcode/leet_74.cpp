/*
 * ====================== leet_74.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 74. 搜索二维矩阵
 */
#include "innLeet.h"


namespace leet_74 {//~


//  33%  100%
class S{
public:
    bool searchMatrix( std::vector<std::vector<int>>& matrix, int target ){

        if( matrix.empty() || matrix[0].empty() ){ return false; }
        if( target<matrix[0][0] || target>matrix.back().back() ){ return false; }

        int H = static_cast<int>(matrix.size());
        int W = static_cast<int>(matrix[0].size());

        int h {};
        int l=0;
        int r=H-1;
        while( l<=r ){
            if( l==r ){ h=l; break; }
            int mid = l+(r-l)/2+1;
            int midV = matrix[mid][0];
            if( midV>target ){
                r=mid-1;//坚决剔除
            }else if( midV<target ){
                l=mid;// 保留到下一回合
            }else{// ==
                return true;//find
            }
        }// now l==r
        l=0;
        r=W-1;
        while( l<=r ){
            if( l==r ){ return matrix[h][l]==target; }
            int mid = l+(r-l)/2;
            int midV = matrix[h][mid];
            if( midV>target ){
                r=mid-1;
            }else if( midV<target ){
                l=mid+1;
            }else{// ==
                return true;
            }
        }
        return false;

    }
};



//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 74 :end ~~~~\n" );
}
}//~
