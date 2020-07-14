/*
 * ====================== leet_1227.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.13
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1227. 飞机座位分配概率
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1227 {//~


// 朴素法： 回溯
//   递归回溯 很容易实现，但 n最大为 100000，一定会超时 超内存

//  很遗憾，无论怎么优化，都是 超时
class S{

    std::vector<int> road {};
    int N {};
    int sum    {1};// 分母
    int getNum {1};// 分子

    // val 本回合 要写的 值，通常从 1 开始
    void work( int val, int fstEmpty ){
        if( val >= N ){
            sum++;
            if( road.back()==N-1 ){ getNum++; }
            return;
        }

        if( val==fstEmpty ){//从本元素开始，后区间元素都对齐了
            sum++;
            getNum++;
            return;
        }

        //== 自己位置可坐时，一定选自己位置 ==//
        if( road[val]==-1 ){

            road[val]=val;
            work( val+1, fstEmpty );
            road[val]=-1; // 释放
            return;
        }
        //== 只有自己位置被占，才随机坐其它位置 ==//
        for( int i=0; i<N; i++ ){
            if( road[i]==-1 ){
                road[i] = val;
                int f = fstEmpty;
                if( i==fstEmpty ){
                    for(; f<N && road[f]!=-1; f++ ){}
                }
                work( val+1,f );
                road[i] = -1;// 释放
            }
        }
    }



public:
    // 1 <= n <= 10^5
    double nthPersonGetsNthSeat( int n ){

        N = n;
        road.resize( n, -1 );

        for( int i=1; i<n; i++ ){
            road[i]=0;
            work( 1, 0 );
            road[i]=-1;
        }
        return static_cast<double>(getNum) / static_cast<double>(sum);

    }
};




// 找规律....
class S2{
public:
    double nthPersonGetsNthSeat(int n) {
        return n==1 ? 1.0 : 0.5;
    }
};




// 还存在 dp 解....





//=========================================================//
void main_(){

    


    for( int i=1; i<=50; i++ ){

        auto ret = S{}.nthPersonGetsNthSeat( i );
        cout<<" "<<i<<": "<<ret<<endl;

    }




    debug::log( "\n~~~~ leet: 1227 :end ~~~~\n" );
}
}//~
