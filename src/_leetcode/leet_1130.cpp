/*
 * ====================== leet_1130.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1130. 叶值的最小代价生成树
 */
#include "innLeet.h"


namespace leet_1130 {//~


// 29.51%, 50%
// 暂时不做优化 ...
class S{
    
struct Node{
    Node()=default;
    int sum {};// 非叶节点 总和
    int mmax {};// 叶节点 最大值
};


    std::vector<std::vector<Node>> dp {};

    Node &dp_at( int j, int i ){
        return dp.at(j).at(i);
    }

    void dp_resize( int n ){
        dp.resize( n+1, std::vector<Node>{} );
        // [0] 暂空置
        for( int i=1; i<=n; i++ ){
            dp.at(i).resize( n-i+1 );
        }
    }


public:


    int mctFromLeafValues( std::vector<int>& arr ){

        int N = static_cast<int>(arr.size());
        dp_resize( N );

        // 手工生成 dp [1] 层 元素
        int len = N-1+1; // dp中 [1] 层元素个数
        for( int i=0; i<len; i++ ){
            auto &node = dp_at(1,i);
            node.mmax = arr.at(i);
            node.sum = 0; // 没有 非叶节点
        }

        // 手工生成 dp [2] 层 元素
        len = N-2+1; // dp中 [2] 层元素个数
        for( int i=0; i<len; i++ ){
            auto &node = dp_at(2,i);
            int l = arr.at(i);
            int r = arr.at(i+1);
            node.mmax = std::max(l,r);
            node.sum = l*r;
        }

        for( int n=3; n<=N; n++ ){// 3开始的每一层
            len = N-n+1; // dp中 本层元素个数
            for( int i=0; i<len; i++ ){// 本层中 每个元素
                // 目标区间 [i, i+n-1], 有 n-1 种分割方式
                auto &selfNode = dp_at(n, i);
                bool isMaxSet {false};
                int minSum {INT_MAX};
                for( int k=i+1; k<=i+n-1; k++ ){// 每种分割方式，k代表右侧首元素
                    // 分割成 2个区间:
                    auto &node1 = dp_at( k-i, i );   // [i,k-1], 长度为 k-i 个
                    auto &node2 = dp_at( n-k+i, k ); // [k,i+n-1], 长度为 n-k+i 个
                    if( !isMaxSet ){
                        isMaxSet = true;
                        selfNode.mmax = std::max( node1.mmax, node2.mmax );
                    }
                    int tmpSum = node1.mmax*node2.mmax + node1.sum + node2.sum;
                    minSum = std::min( minSum, tmpSum );
                }
                selfNode.sum = minSum;
            }
        }
        return dp_at( N,0 ).sum;
    }




};



//=========================================================//
void main_(){

    std::vector<int> v { 6,2 };

    cout << S{}.mctFromLeafValues(v) << endl;
    



    debug::log( "\n~~~~ leet: 1130 :end ~~~~\n" );
}
}//~
