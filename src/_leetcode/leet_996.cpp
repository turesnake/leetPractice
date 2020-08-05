/*
 * ====================== leet_996.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 996. 正方形数组的数目
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_996 {//~

// 检测平方和：
// 处理 平方和，一种思路是 预先计算出所有可能的 平方和，存入 uset
// 然后 检查 是否命中
// 但是这个 思路的 性能很低

// 如果改为，当场计算，目标sum 是否为 平方和
// 性能会 大幅改善

// ---
// 遍历数组中每个值，查看它和剩余的值，和是否为 平方和，如果符合，
// 存入邻接表，adjs

// ---
// 如果某个元素，不与任何元素邻接，说明数组不成立，返回0

// ---
// 然后用 回溯法+dfs， 遍历所有可能



// 此题也许涉及到 哈密顿回路



// 朴素的 回溯法   62%   54%
class S{

struct Elem{
    std::unordered_set<int> adjs {};
    int num {};
};

    std::unordered_map<int,Elem> elems {};
    int N {};
    int ans {0};

    void rec( int val, int deep ){
        if( deep == N ){
            ans++;
            return;
        }
        for( int b : elems[val].adjs ){
            if( elems[b].num<=0 ){ continue; }
            elems[b].num--;
            rec( b, deep+1 );
            elems[b].num++;
        }
    }

public:
    // 1 <= A.length <= 12
    // 0 <= A[i] <= 1e9
    // 0+0 也是符合的 组合
    int numSquarefulPerms( std::vector<int>& A ){

        N = static_cast<int>(A.size());

        for( int a=0; a<N; a++ ){
            elems[A[a]].num++;

            for( int b=0; b<N; b++ ){
                if( b==a ){ continue; }
                int sum = A[a]+A[b];
                int t = static_cast<int>(sqrt(sum)); // 现场计算
                if( t*t==sum ){
                    elems[A[a]].adjs.insert( A[b] );
                }

            }
        }

        for( auto &[val,elem] : elems ){
            if( elem.adjs.size()==0 ){ return 0; }// 无法组成 正方形排列
        }
        for( auto &[val,elem] : elems ){
            elem.num--;
            rec( val, 1 );
            elem.num++;
        }
        return ans;

    }
};





//=========================================================//
void main_(){

    


    

    debug::log( "\n~~~~ leet: 996 :end ~~~~\n" );
}
}//~
