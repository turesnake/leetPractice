/*
 * ====================== leet_852.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_852 {//~


class S{




public:
    // 数组元素 >=3,一定为山峰，所以 i 不可能是两端元素
    // 元素都非负
    int peakIndexInMountainArray( std::vector<int>& A ){

        int N = static_cast<int>(A.size());
        int l = 1;  // 第二元素 
        int r = N-2;// 倒数第二元素
        while( l<=r ){
            int mid = l+(r-l)/2;//mid-left
            int v = A.at(mid);
            int lv = A.at(mid-1);
            int rv = A.at(mid+1);
            if( lv<v && rv<v ){ return mid; }// find
            if( lv<v && rv>v ){//search right
                l = mid+1;
            }else{//search left
                r = mid-1;
            }
        }
        return -99; // never reach

    }
};





//=========================================================//
void main_(){

    
    

    debug::log( "\n~~~~ leet: 852 :end ~~~~\n" );
}
}//~
