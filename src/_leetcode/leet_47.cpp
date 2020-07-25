/*
 * ====================== leet_47.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 47. 全排列 II
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_47 {//~

// 用 umap 记录每种元素的 个数
// 回溯+dfs


//   90%   100%
class S{

    std::vector<std::vector<int>> outs {};
    std::vector<int> v {};
    std::unordered_map<int,int> umap {};
    int N {};

    void work( int idx ){
        if( idx==N ){
            outs.push_back(v);
            return;
        }
        for( auto &[val,n] : umap ){
            if(n==0){ continue; }
            v.push_back(val);
            n--;
            work( idx+1 );
            v.pop_back();
            n++;
        }
    }

public:
    std::vector<std::vector<int>> permuteUnique( std::vector<int>& nums ){

        if( nums.empty() ){ 
            outs.push_back( std::vector<int>{} );
            return outs; 
        }
        N = static_cast<int>(nums.size());
        for( int i : nums ){
            umap[i]++;
        }
        work( 0 );
        return outs;


    }
};


//=========================================================//
void main_(){





    
    debug::log( "\n~~~~ leet: 47 :end ~~~~\n" );
}
}//~
