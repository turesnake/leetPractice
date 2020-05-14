/*
 * ====================== leet_46.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 46. 全排列
 */
#include "innLeet.h"


namespace leet_46 {//~



class S {

    std::vector<std::vector<int>> outs {};
    int numsSize {};
    std::unordered_set<int> usedIdxs {};// 已经使用的 elem-idx
    std::vector<int> v {}; // 当前被组合的案例

public:

    void work(  std::vector<int>& nums_ ){
        if( usedIdxs.size() == nums_.size() ){ // 排列完毕
            this->outs.push_back( v );
            return; 
        }
        for( int i=0; i<numsSize; i++ ){
            if( usedIdxs.find(i) != usedIdxs.end() ){ continue; } // used

            usedIdxs.insert( i );
            v.push_back( nums_.at(i) );
            work( nums_ );
            v.pop_back();
            usedIdxs.erase( i );
        }
    }


    std::vector<std::vector<int>> permute( std::vector<int>& nums ) {
        this->outs.clear();
        if( nums.empty() ){ return this->outs; }
        this->numsSize = static_cast<int>( nums.size() );
        this->usedIdxs.clear();
        this->v.clear();
        work( nums );
        return this->outs;
    }
};






//=========================================================//
void main_(){

    std::vector<int> v { 1,2,3,4 };


    auto ret = S{}.permute( v );
    cout << "retNum = " << ret.size() << endl;
    for( const auto &vv : ret ){
        for( const int i : vv ){
            cout << i << ", ";
        }
        cout << endl;
    }
    


    debug::log( "\n~~~~ leet: 46 :end ~~~~\n" );
}
}//~
