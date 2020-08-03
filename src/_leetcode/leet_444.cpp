/*
 * ====================== leet_444.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.03
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 444. 序列重建
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_444 {//~


// 序列集 seqs 的 “最短公共超序列”，就是 能让 seqs 中所有 子序列 都是该 “最短公共超序列” 的子序列
// （子序列 不同于 子串， 是可以离散分布的）
// 确定是否只可以从 seqs 重建唯一的序列，且该序列就是 org

// 如果 seqs 无法建立 唯一公共超序列，判 false，
// 如果 建出来的 公共超序列，和 org 不相同，判 false

// 本质上，这是一个 数组题，而不是 图 题


// 这题 有点问题，暂时不做 ...


class S{
public:
    bool sequenceReconstruction( std::vector<int>& org,  std::vector<std::vector<int>>& seqs ){




        return false;
    }
};



//=========================================================//
void main_(){


    

    debug::log( "\n~~~~ leet: 444 :end ~~~~\n" );
}
}//~
