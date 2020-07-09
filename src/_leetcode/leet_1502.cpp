/*
 * ====================== leet_1502.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1502. 判断能否形成等差数列
 */
#include "innLeet.h"


namespace leet_1502 {//~



// 不用排序的方法：
// 遍历一次，将所有元素 装入 uset, 同时找出 max，min
// 根据 max，min，计算出 off，
// 然后逐个计算每个值，查找是否在 uset 中


//  朴素法   85%  100%
class S{
public:
    // 2 <= arr.length <= 1000
    // -10^6 <= arr[i] <= 10^6
    bool canMakeArithmeticProgression( std::vector<int>& arr ){

        if( arr.size()==2 ){ return true; }

        std::sort( arr.begin(), arr.end() );
        int N = static_cast<int>( arr.size() );
        int off = arr[1]-arr[0];

        for( int i=2; i<N; i++ ){// [i-1],[i-2]
            if( (arr[i]-arr[i-1])!=off ){ return false; }
        }
        return true;


    }
};


//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 1502 :end ~~~~\n" );
}
}//~
