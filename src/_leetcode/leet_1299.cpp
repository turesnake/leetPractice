/*
 * ====================== leet_1299.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1299. 将每个元素替换为右侧最大元素
 */
#include "innLeet.h"


namespace leet_1299 {//~




//   65%   7%
class S{
public:
    // 1 <= arr.len <= 10^4
    // 1 <= arr[i] <= 10^5
    std::vector<int> replaceElements( std::vector<int>& arr ){

        int N = static_cast<int>(arr.size());
        int mmax = arr.back();
        arr.back() = -1;
        for( int i=N-2; i>=0; i-- ){
            int curVal = arr[i];
            arr[i] = mmax;
            mmax = std::max( mmax, curVal );
        }
        return arr;

    }
};




//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 1299 :end ~~~~\n" );
}
}//~
