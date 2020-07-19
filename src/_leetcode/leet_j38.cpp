/*
 * ====================== leet_j38.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 38. 字符串的排列
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_j38 {//~


//   dfs + 回溯法


//   74%   100%
class S{

    std::unordered_map<char, int> umap {};
    std::vector<std::string> outStrs {};
    std::string str {};
    int N {};


    void work( int idx ){
        if( idx==N ){
            outStrs.push_back( str );// copy
            return;
        }
        for( auto &[c,n] : umap ){
            if( n==0 ){ continue; }
            str.push_back(c);
            n--;
            work( idx+1 );
            str.pop_back();
            n++;
        }
    }


public:
    // 1 <= s 的长度 <= 8
    std::vector<std::string> permutation( std::string s ){

        N = static_cast<int>(s.size());
        for( char c : s ){ umap[c]++; }
        work(0);
        return outStrs;


    }
};



//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: j38 :end ~~~~\n" );
}
}//~
