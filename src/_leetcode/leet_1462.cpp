/*
 * ====================== leet_1462.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.10
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1462. 课程安排 IV
 */
#include "innLeet.h"


namespace leet_1462 {//~


// 有向无环图



class S{
public:
    // 一个 n 个元素，{0,...n-1}
    // 2 <= n <= 100
    // 0 <= prerequisite.length <= (n * (n - 1) / 2)
    // 0 <= prerequisite[i][0], prerequisite[i][1] < n
    // prerequisite[i][0] != prerequisite[i][1]
    // 先修课程图中没有环
    // 先修课程图中没有重复的边
    // 1 <= queries.length <= 10^4
    // queries[i][0] != queries[i][1]  
    std::vector<bool> checkIfPrerequisite( int n, 
            std::vector<std::vector<int>>& prerequisites, 
            std::vector<std::vector<int>>& queries ){


        int Nq = static_cast<int>(queries.size());


        


        return {};

    }
};




//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 1462 :end ~~~~\n" );
}
}//~
