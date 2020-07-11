/*
 * ====================== leet_216.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 216. 组合总和 III
 */
#include "innLeet.h"


namespace leet_216 {//~


// 候选值为 [1,9]

//   100%   100%
class S{

    std::vector<std::vector<int>> outs {};
    std::vector<int> v {};
    int tgt {};

    // idx 本回合能用的值: [1,9]
    void work( int idx, int sum, int k ){
        k--;
        for( int i=idx; i<=9; i++ ){
            int tsum = sum + i;
            if( tsum>tgt ){ return; }
            v.push_back(i);
            if( tsum==tgt && k==0 ){// find
                outs.push_back(v);
                v.pop_back();
                return;
            }
            if( i+1<=9 && k>0 ){ work( i+1, tsum, k ); }
            v.pop_back();
        }
    }

public:
    // k>0
    std::vector<std::vector<int>> combinationSum3( int k, int n ){

        tgt = n;
        work( 1, 0, k );
        return outs;

    }
};



//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 216 :end ~~~~\n" );
}
}//~
