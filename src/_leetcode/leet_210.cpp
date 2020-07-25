/*
 * ====================== leet_210.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 210. 课程表 II
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_210 {//~



// 有向图：拓扑排序  bfs

//   59%  87%
class S{
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites ){


        if( numCourses==0 ){ return {}; }
        if( numCourses==1 ){ return {0}; }

        std::vector<int> outs {};

        if( prerequisites.empty() ){
            for( int i=0; i<numCourses; i++ ){
                outs.push_back(i);
            }
            return outs;
        }
        //---------------//

        std::vector<int> indegrees ( numCourses, 0 );
        std::unordered_map<int,std::vector<int>> nexts {};
        std::deque<int> que {};
        int N = numCourses;

        for( auto &v : prerequisites ){// 此题中的 关系是 反的
            indegrees[v[0]]++;
            nexts[v[1]].push_back( v[0] );
        }
        for( int i=0; i<numCourses; i++ ){
            if( indegrees[i]==0 ){
                que.push_back(i);
                outs.push_back(i);
                N--;
            }
        }
        while( !que.empty() ){
            int val = que.front();
            que.pop_front();
            for( int i : nexts[val] ){
                indegrees[i]--;
                if( indegrees[i]==0 ){
                    que.push_back(i);
                    outs.push_back(i);
                    N--;
                }
            }
        }
        return N==0 ? outs : std::vector<int>{};


    }
};


//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 210 :end ~~~~\n" );
}
}//~
