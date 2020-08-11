/*
 * ====================== leet_1056.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1056. 易混淆数
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_1056 {//~

// 不可颠倒数：2,3,4,5,7
// 可颠倒数： 0,1,6,8,9
//   其中，0,1,8 属于 翻转后不变的数

// 双指针法

// -1- 找到不可颠倒数，直接返回 false
// -2- 如果 l/r 指向的值都是 对称的，比如，
//     0-0， 1-1， 8-8， 6-9， 9-6
//     那可以认为，这个值反转后不变
//     如果整个数组，都是对称的，返回 false
//     否则返回 true

//   13%   6%
class S{
public:
    // 0 <= N <= 10^9
    // 可以忽略掉旋转后得到的前导零，例如，如果我们旋转后得到 0008 那么该数字就是 8
    bool confusingNumber( int N ){


        if( N==0 ){ return false; }

        std::unordered_set<int> twoSums { 0,2,16,15 };// 互为对称数 之和
        std::unordered_set<int> unVals { 2,3,4,5,7 };// 反转后无效

        std::vector<int> v {};
        for( int i=N; i>0; i/=10 ){
            int a = i%10;
            if( unVals.count(a)>0 ){ return false; }
            v.push_back( a );
        }
        int Nn = static_cast<int>(v.size());

        int l=0; 
        int r=Nn-1;
        for(; l<=r; l++,r-- ){
            if( twoSums.count(v[l]+v[r])==0 ){ return true; }// find
        }
        return false;
        

    }
};


//=========================================================//
void main_(){





    

    debug::log( "\n~~~~ leet: 1056 :end ~~~~\n" );
}
}//~
