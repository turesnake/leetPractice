/*
 * ====================== leet_1306.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1306. 跳跃游戏 III
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_1306 {//~

// 有向图
// 元素以 下标为值，[i] 只交代了自己可以连通的点

// 图中不只一个 0
// 只要跳到一个 0 上，就算成功
// 如果初始位置就是 0，也算成功

// 并查集 似乎是不成立的

//   bfs   84%   38%  
class S{
public:
    // 1 <= arr.length <= 5 * 10^4
    // 0 <= arr[i] < arr.length
    // 0 <= start < arr.length
    bool canReach( std::vector<int>& arr, int start ){

        int N = static_cast<int>(arr.size());

        std::vector<char> vis (N,0);
        std::deque<int> que {start};

        while( !que.empty() ){
            int i = que.front();
            que.pop_front();
            if( arr[i]==0 ){ return true; }
            if( vis[i]==1 ){ continue; }
            vis[i]=1;
            //--//
            int l = i-arr[i];
            int r = i+arr[i];
            if( l>=0 && vis[l]==0 ){ que.push_back( l ); }
            if( r<N  && vis[r]==0 ){ que.push_back( r ); }
        }
        return false;

    }
};


//   dfs   72%  28%
class S2{

    std::vector<int> *arrp {nullptr};
    std::vector<char> vis {};
    int N {};
    bool ans {false};

    void work( int i ){
        if( ans || vis[i]==1 ){ return; }
        vis[i]=1;
        int iv = arrp->at(i);
        if( iv==0 ){
            ans = true;
            return;
        }
        int l = i-iv;
        int r = i+iv;
        if( l>=0 && vis[l]==0 ){
            work( l );
        }
        if( r<N && vis[r]==0 ){
            work( r );
        }
    }

public:
    // 1 <= arr.length <= 5 * 10^4
    // 0 <= arr[i] < arr.length
    // 0 <= start < arr.length
    bool canReach( std::vector<int>& arr, int start ){

        N = static_cast<int>(arr.size());
        arrp = &arr;
        vis.resize(N,0);
        work(start);
        return ans;

    }
};


//=========================================================//
void main_(){

    std::vector<int> arr { 3,0,2,1,2 };

    auto ret = S2{}.canReach( arr, 2 );

    cout<<"ret:"<<ret<<endl;

    

    debug::log( "\n~~~~ leet: 1306 :end ~~~~\n" );
}
}//~
