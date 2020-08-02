/*
 * ====================== leet_841.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 841. 钥匙和房间
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_841 {//~


// 简单的 bfs 思路    97%  40%
class S{
public:
    // 1 <= rooms.length <= 1000
    // 0 <= rooms[i].length <= 1000
    // 所有房间中的钥匙数量总计不超过 3000。
    bool canVisitAllRooms( std::vector<std::vector<int>>& rooms ){

        int N = static_cast<int>(rooms.size());
        std::vector<char> vis (N,0);
        std::deque<int> que { 0 };

        while( !que.empty() ){
            int e = que.front();
            que.pop_front();
            //--//
            if( vis[e]==1 ){ continue; }
            vis[e]=1;
            for( int i : rooms[e] ){
                if( vis[i]==0 ){ que.push_back(i); }
            }
        }

        for( int i : vis ){
            if(i==0){ return false; }
        }
        return true;

    }
};


//  dfs   97%  61%
class S2{
public:
    // 1 <= rooms.length <= 1000
    // 0 <= rooms[i].length <= 1000
    // 所有房间中的钥匙数量总计不超过 3000。
    bool canVisitAllRooms( std::vector<std::vector<int>>& rooms ){

        int N = static_cast<int>(rooms.size());

        std::vector<char> vis (N,0);
        std::stack<int> stk {};
        stk.push(0);
        
        while( !stk.empty() ){
            int e = stk.top();
            stk.pop();
            //--//
            if( vis[e]==1 ){ continue; }
            vis[e]=1;
            for( int i : rooms[e] ){
                if( vis[i]==0 ){ stk.push(i); }
            }
        }

        for( int i : vis ){
            if(i==0){ return false; }
        }
        return true;

    }
};


//=========================================================//
void main_(){

    

    



    debug::log( "\n~~~~ leet: 841 :end ~~~~\n" );
}
}//~
