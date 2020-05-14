/*
 * ====================== leet_39.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 39. 组合总和
 */
#include "innLeet.h"


namespace leet_39 {//~



class S {

    std::vector<std::vector<int>> outs {};
    std::vector<int> v {};
    int numsSize {};
    int targetNum {};

public:


    void work( std::vector<int>& candidates_, int sum_, int idx_ ){
        for( int i=idx_; i<numsSize; i++ ){
            int newV = candidates_.at(i);
            int sm = sum_ + newV;
            if( sm > targetNum ){ continue; }

            v.push_back( newV );
            if( sm == targetNum ){// 匹配
                outs.push_back( v );
            }else{
                work( candidates_, sm, i );
            }
            v.pop_back();
        }
    }


    std::vector<std::vector<int>> combinationSum( std::vector<int>& candidates, int target ){
        this->outs.clear();
        if( candidates.empty() ){ return this->outs; } // empty
        this->numsSize = static_cast<int>(candidates.size());
        this->targetNum = target;
        work( candidates, 0, 0 );
        return this->outs;
    }
};





//=========================================================//
void main_(){

    std::vector<int> v { 2,3,6,7 };
    auto ret = S{}.combinationSum( v, 7 );

    cout << "retSize = " << ret.size() << endl;
    for( const auto &c : ret ){
        cout << "{ ";
        for( const int i : c ){
            cout << i << ", ";
        }
        cout << " }" << endl;
    }
    cout << endl;
    

    debug::log( "\n~~~~ leet: 39 :end ~~~~\n" );
}
}//~
