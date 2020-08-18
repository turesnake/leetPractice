/*
 * ====================== leet_605.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 605. 种花问题
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_605 {//~


// 连续为0的区间，这个区间 大于等于3，才有效
// 当区间 头元素，尾元素，恰好是 数组边界时，要补0


//   83%  75%
class S{
public:
    // 数组内已种好的花不会违反种植规则。
    // 输入的数组长度范围为 [1, 20000]。
    // n 是非负整数，且不会超过输入数组的大小。
    bool canPlaceFlowers( std::vector<int>& flowerbed, int n ){

        int N = static_cast<int>(flowerbed.size());
        if( N==1 ){
            int ret = flowerbed[0]==1 ? 0 : 1;
            return ret >= n;
        }
        int sum = 0;
        int l=0;
        int r=0;

        while( l<N ){
            if( flowerbed[l]==1 ){ l++; continue; }
            // 现在 l 指向 0区间 首元素

            for( r=l; r<N && flowerbed[r]==0; r++ ){}// r 指向本区间后一个元素
            
            int len = r-l;// 0区间元素个数
            if( l==0 ){ len++; } // patch
            if( r==N ){ len++; } // patch

            sum += (len-1)/2;

            if( sum>=n ){ return true; }

            l = r;
        }
        return sum >= n;

    }
};



//=========================================================//
void main_(){





    

    debug::log( "\n~~~~ leet: 605 :end ~~~~\n" );
}
}//~
