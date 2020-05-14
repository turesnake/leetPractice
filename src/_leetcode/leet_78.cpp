/*
 * ====================== leet_78.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 78. 子集
 */
#include "innLeet.h"


namespace leet_78 {//~



class S {

    std::vector<std::vector<int>> outs {};
    std::vector<int> v {};
    int numsSize {};

public:

    // 从总集合中，提取 k_ 个元素
    // idx_ 本回合可以开始用的 下标，排在前面的已经不能用了
    void work( std::vector<int>& nums, int k_, int idx_ ){

        if( idx_ >= numsSize ){ return; }
        if( k_ <= 0 ){// 本次选好了
            outs.push_back( v );
            return;
        }
        int off = numsSize - idx_;
        if( off == k_ ){
            outs.push_back( v ); // copy
            for( int i=idx_; i<numsSize; i++ ){
                outs.back().push_back( nums.at(i) ); // 补全某后一段
            }
            return;
        }        
        //-1- 本位置元素 被选中
        v.push_back( nums.at(idx_) );
        work( nums, k_-1, idx_+1 );
        v.pop_back();
        //-2- 本位置元素 不被选中
        work( nums, k_, idx_+1 );
    }


    std::vector<std::vector<int>> subsets( std::vector<int>& nums) {
        this->outs.clear();
        this->numsSize = static_cast<int>( nums.size() );

        this->outs.push_back( std::vector<int>{} ); // {}
        if( nums.empty() ){ return this->outs; }
        this->outs.push_back( nums ); // full
        if( nums.size() == 1 ){ return this->outs; }

        this->v.clear();
        for( int i=1; i<=numsSize-1; i++ ){
            work( nums, i, 0 );
        }
        return this->outs;
    }
};





//=========================================================//
void main_(){

    std::vector<int> v { 6,7,8 };
    auto ret = S{}.subsets( v );

    cout << "retSize = " << ret.size() << endl;
    for( const auto &c : ret ){

        cout << "{ ";
        for( const int i : c ){
            cout << i << ", ";
        }
        cout << " }" << endl;
    }
    cout << endl;
    

    debug::log( "\n~~~~ leet: 78 :end ~~~~\n" );
}
}//~
