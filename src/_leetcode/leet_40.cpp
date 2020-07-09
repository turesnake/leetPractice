/*
 * ====================== leet_40.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 40. 组合总和 II
 */
#include "innLeet.h"


namespace leet_40 {//~



// 每个元素只能使用一次，其实只需要基于 39题 做细微变化
// 唯一需要注意的是，相同值的元素，不应该在 “同一层” 被使用


//   97%   100%
class S{

    std::vector<int> *candsp {nullptr};
    std::vector<std::vector<int>> outs {};
    std::vector<int> v {};
    int N {};
    int tgt {};

    void work( int idx, int sum ){
        int lstVal {};
        bool isFst {true};
        for( int i=idx; i<N; i++ ){
            int val = candsp->at(i);

            if( isFst ){
                isFst = false;
            }else{
                if( val==lstVal ){ continue; }// 不在 同一层 使用相同值的 元素
            }
            lstVal = val;
            //---//
            int tsum = sum + val;
            if( tsum > tgt ){ return; }
            v.push_back(val);
            if( tsum == tgt ){// find
                outs.push_back( v );
                v.pop_back();
                return;
            }
            if( i+1<N ){ work( i+1, tsum ); }
            v.pop_back();
        }
    }



public:
    std::vector<std::vector<int>> combinationSum2( std::vector<int>& candidates, int target ){


        std::sort( candidates.begin(), candidates.end() );
        N = static_cast<int>(candidates.size());
        candsp = &candidates;
        tgt = target;
        work( 0,0 );
        return outs;

        
    }
};




//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 40 :end ~~~~\n" );
}
}//~
