/*
 * ====================== leet_1287.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.07
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1287. 有序数组中出现次数超过25%的元素
 */
#include "innLeet.h"


namespace leet_1287 {//~


// 固定间距法
// 用固定间距的 双指针，遍历数组，发现某个值区间长度符合时，即找到目标值



//  96%   33%
class S{
public:
    // 1 <= arr.length <= 10^4
    // 0 <= arr[i] <= 10^5
    int findSpecialInteger( std::vector<int>& arr ){

        if( arr.size()<=2 ){ return arr[0]; }

        int N = static_cast<int>(arr.size());
        int off = N<4 ? 1 : N/4;
        int l=0;
        if( arr[l]==arr[l+off] ){ return arr[l]; }// find
        int lstElem = arr[0];
        l++;
        for(; (l+off)<N; l++ ){
            if( arr[l]==lstElem ){ continue; }
            lstElem = arr[l];
            if( arr[l]==arr[l+off] ){ return arr[l]; }// find
        }
        return arr[0];

    }
};



//=========================================================//
void main_(){

    std::vector<int> v { 1,2,2 };

    auto ret = S{}.findSpecialInteger(v);

    cout<<"ret:"<<ret<<endl;

    
    


    debug::log( "\n~~~~ leet: 1287 :end ~~~~\n" );
}
}//~
