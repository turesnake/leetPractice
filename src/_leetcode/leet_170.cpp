/*
 * ====================== leet_170.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 170. 两数之和 III - 数据结构设计
 */
#include "innLeet.h"


namespace leet_170 {//~


//   66%   100%
class TwoSum {
    std::unordered_map<int,int> umap {};
public:
    /** Initialize your data structure here. */
    TwoSum() {
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        umap[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {

        for( auto [a,n] : umap ){
            int b = value-a;
            if( umap.count(b)==0 ){ continue; }
            if( a==b && n<2 ){ continue; }
            return true;
        }
        return false;
    }
};




//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 170 :end ~~~~\n" );
}
}//~
