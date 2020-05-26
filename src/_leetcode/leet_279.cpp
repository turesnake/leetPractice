/*
 * ====================== leet_279.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 279. 完全平方数
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_279 {//~


// bfs
// 出人意料的好用
// 而且比 dp 更直白
struct Elem{
    int leftVal {};  // 剩余的点数，分配完就算结束
    int lastElem {}; // 上次使用的值，每次只能用 小于等于上次的值
    int times {};     // 已经分配过几个值了
};

int numSquares( int n ){

    // 收集所有可用的 平方数
    std::vector<int> sqs {};
    for( int i=1; i<=n; i++ ){
        int sq = i*i;
        if( sq > n ){ break; }
        sqs.push_back( sq );
    }
    int N = static_cast<int>(sqs.size());

    std::deque<Elem> que {}; // bfs
    que.push_back( Elem{ n, INT_MAX, 0 } );// 初始元素
    while( !que.empty() ){
        auto &elem = que.front();
        //cout << "  "<<elem.leftVal << ", " << elem.lastElem << ", " << elem.times << endl;
        for( int i=N-1; i>=0; i-- ){// 倒序，先访问大元素
            int sqVal = sqs.at(i);
            if( sqVal<=elem.lastElem && sqVal<=elem.leftVal ){
                if( sqVal == elem.leftVal ){
                    // 第一个发现的结束的路线，就是最短的那个
                    return elem.times+1;
                }
                que.push_back( Elem{ elem.leftVal-sqVal, sqVal, elem.times+1 } );
            }
        }
        que.pop_front();
    }
    return 0;//never reach
}






//=========================================================//
void main_(){

  
    cout << numSquares( 11 ) << endl;
  
    

    

    debug::log( "\n~~~~ leet: 279 :end ~~~~\n" );
}
}//~
