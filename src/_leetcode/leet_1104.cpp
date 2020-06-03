/*
 * ====================== leet_1104.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1104. 二叉树寻路
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1104 {//~


// 45% 100%
// 先生产 正常完全二叉树的 数组
// 然后把其中，反转的 层，修改下
class S{

    std::vector<int> lvlLstIdxs {};//每层尾元素序号（基于1）

    void init_lvlLstIdxs( int N ){
        lvlLstIdxs.push_back(0);//[0]空置
        int v = 1;
        for( int i=1; i<=N; i++ ){
            v *= 2;
            lvlLstIdxs.push_back( v-1 );
        }
    }

    // deep based on 1
    int calc_mirror( int v, int deep ){
        int l = lvlLstIdxs.at(deep-1)+1;
        int r = lvlLstIdxs.at(deep);
        return r-(v-l);
    }


public:
    std::vector<int> pathInZigZagTree( int label ){

        //== 如果路径长度为 偶数，说明 最后一位所在的 行，也应该是反的
        // 那就应该，先找到 label 对应的行内镜像值，在用这个镜像值，求出表。
        int roadN = 0;
        for( int i=label; i!=0; i>>=1 ){ roadN++; }

        //== 准备好 lvlLstIdxs
        init_lvlLstIdxs( roadN );
        int target = (roadN&1)==0 ? calc_mirror(label,roadN) : label;

        std::deque<int> que {};
        for( int i=target; i!=0; i>>=1  ){
            que.push_front(i);
        }
        std::vector<int> road (que.begin(), que.end());
        // 将所有 偶数行 都取镜像值 
        for( int i=1; i<roadN-1; i++ ){// 尾部元素就算是偶数行 也先不管
            if( (i&1)==1 ){// 只处理偶数
                road.at(i) = calc_mirror( road.at(i), i+1 );
            }
        }
        if( (roadN&1)==0 ){
            road.back() = label;
        }
        return road;
    }
};



// 方法2:
// 只计算 label 的镜像点
// 然后同时 生成两个点的 路径数组
// 最后将偶数位 交换一下
// 理论上这个方法会更快...



//=========================================================//
void main_(){

    auto ret = S{}.pathInZigZagTree( 26 );

    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;

    
    debug::log( "\n~~~~ leet: 1104 :end ~~~~\n" );
}
}//~
