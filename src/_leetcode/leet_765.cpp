/*
 * ====================== leet_765.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 765. 情侣牵手
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_765 {//~


// 并查集
// 原则上，排好序的数组，会形成 N/2 个 连通分量，每个连通分量，正好 2 个元素
// 当发生错乱时，有些连通分量 就会被合并到一起
// 被混合的 连通分量，被拆分回去，需要消耗的步数 是固定的


//   100%   30%
class S{

class UnionFindSet{
    std::vector<int> st {};
    int N {};
public:
    explicit UnionFindSet(int N_):N(N_){
        st.resize(N,0);
        for( int i=0; i<N; i++ ){
            st[i] = i;
        }
    }
    int find( int a ){
        if( st[a]==a ){ return a; }
        st[a] = find(st[a]);
        return st[a];
    }
    void merge( int a, int b ){
        int ra = find(a);
        int rb = find(b);
        if( ra==rb ){ return; }
        st[rb] = ra;
    }
};

public:
    // len(row) 是偶数且数值在 [4, 60]范围内
    // 可以保证row 是序列 0...len(row)-1 的一个全排列
    int minSwapsCouples( std::vector<int>& row ){

        int N = static_cast<int>(row.size());

        UnionFindSet ufs {N};

        for( int i=0; i<N; i+=2 ){// [i], [i+1]
            ufs.merge( i, i+1 );
            ufs.merge( row[i], row[i+1] );
        }

        std::vector<int> sets (N,0);// 每个 连通分量的 个数
        for( int i=0; i<N; i++ ){
            sets[ ufs.find(i) ]++;
        }

        int ans = 0;
        for(int i : sets ){
            if( i>2 ){
                ans += i/2-1;
            }
        }
        return ans;

    }
};



//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 765 :end ~~~~\n" );
}
}//~
