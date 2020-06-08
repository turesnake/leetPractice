/*
 * ====================== leet_684.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 684. 冗余连接
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_684 {//~


// 并查集



// 64%, 100%
class S{

    std::vector<int> ufset {};

    // root, or self:v
    // 当一个值被 find 一次后，就永久地直接指向 root 了
    // 因为 root 指向 root 自己，所以最终会 推出循环
    int find( int v ){
        while( ufset.at(v)!=v ){
            v = ufset.at(v);
            ufset.at(v) = ufset.at(ufset.at(v));//路径压缩
        }
        return v;
    }

    void merge( int a, int b ){
        int rootA = find(a);
        int rootB = find(b);
        if( rootA != rootB ){
            ufset.at(rootB) = rootA;
        }
    }

public:
    // N = edges.size()
    // 3<= N <=1000
    // 1<= [i] <= N
    std::vector<int> findRedundantConnection( std::vector<std::vector<int>>& edges) {

        int N = static_cast<int>(edges.size());
        // 初始化时，每个节点指向自己，保证各自独立
        ufset.resize(N+1);
        for( int i=0; i<=N; i++ ){// [0]空置 
            ufset.at(i)=i; // 
        }
        for( auto &p : edges ){
            int a = p.at(0);
            int b = p.at(1);
            cout<<"a:"<<a<<" b:"<<b<<endl;
            int rootA = find(a);
            int rootB = find(b);
            if( rootA == rootB ){ return p; }
            merge(a,b);
        }
        return {};//never reach
    }
};




//=========================================================//
void main_(){

    //std::vector<std::vector<int>> v { {1,2}, {1,3}, {2,3} };
    std::vector<std::vector<int>> v { {1,4}, {3,4}, {1,3}, {1,2}, {4,5} };

    auto ret = S{}.findRedundantConnection(v);
    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;

    

    
    debug::log( "\n~~~~ leet: 684 :end ~~~~\n" );
}
}//~
