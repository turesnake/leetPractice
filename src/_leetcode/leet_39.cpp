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


// 将元素 按 从小到大 排序后，遍历过程会适当快些（减少了一部分 递归函数调用）


// 非排序版   83%   100%
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






// 排序版   97%   100%  (确实更快了)
class S2{

    std::vector<int> *candsp {nullptr};
    std::vector<std::vector<int>> outs {};
    std::vector<int> v {};
    int N {};
    int tgt {};

    // idx: 本回合 起始检测元素下标
    void work( int idx, int sum ){

        for( int i=idx; i<N; i++ ){
            int val = candsp->at(i);
            int tsum = sum + val;
            if( tsum>tgt ){ return; }// 后面的值很大，不需要遍历了

            v.push_back( val );
            if( tsum==tgt ){ // find
                outs.push_back( v );
                v.pop_back();
                return;// 后面的值很大，不需要遍历了
            }
            // tsum < tgt
            work( i, tsum );
            v.pop_back();
        }
    }


public:
    std::vector<std::vector<int>> combinationSum( std::vector<int>& candidates, int target ){

        std::sort( candidates.begin(), candidates.end() );// 从小到大
        candsp = &candidates;
        tgt = target;
        N = static_cast<int>(candidates.size());
        work(0, 0);
        return outs;

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
