/*
 * ====================== leet_1381.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1381. 设计一个支持增量操作的栈
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1381 {//~


// 朴素版。用 vector 来实现 stk 43%, 100%

// 改进版，用一个 adds 来记录 增量信息。 23%, 100%
// 理论上这个版本更好...

// 改进版
class CustomStack {
    std::vector<int> datas {};
    std::vector<int> adds  {};
    size_t mmaxSize {};

public:
    CustomStack( int maxSize ){
        mmaxSize = static_cast<size_t>(maxSize);
        datas.reserve(maxSize);
        adds.resize( maxSize, 0 );
    }

    void push(int x) {
        if( datas.size()>=mmaxSize ){ return; }
        datas.push_back(x);
    }

    int pop() {
        if( datas.empty() ){
            return -1;
        }else{
            size_t idx = datas.size()-1;
            if( idx>0 ){ adds.at(idx-1) += adds.at(idx); }// 增量继承给低位
            int v = datas.back() + adds.at(idx);
            datas.pop_back();
            adds.at(idx) = 0;// 记得清空
            return v;
        }
    }
    
    void increment(int k, int val) {
        int n = std::min( k, static_cast<int>(datas.size()) );
        if( n>0 ){ adds.at(n-1) += val; }
    }
};



//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 1381 :end ~~~~\n" );
}
}//~
