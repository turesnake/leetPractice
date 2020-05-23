/*
 * ====================== leet_486.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.22
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 486. 预测赢家
 */
#include "innLeet.h"


namespace leet_486 {//~



// 判断三个值,返回最优情况下，先手和 与 后手和 
// <先手和，后手和>
std::pair<int,int> threeElem( int v1, int v2, int v3 ){
    int mmax = std::max(std::max(v1,v2), v3);
    if( v2 == mmax ){// 中间值最大
        int smlSum = v1+v3;//两小数之和
        return { smlSum, mmax };
    }else{// 两侧某值最大 
        return (v1==mmax) ? 
            std::pair<int,int>{ mmax+v3, v2 } :
            std::pair<int,int>{ mmax+v1, v2 };
    }
}


// 动态规划 100%  100%
// 1<= nums.size() << 20
// 0 <= elem <= 10000000
// 若两人分数相同，也判定 先手为赢
bool PredictTheWinner( std::vector<int>& nums ){

    int N = static_cast<int>(nums.size());
    if( N<3 ){ return true; }// 1,2 个元素时，先手必胜
    if( N==3 ){ 
        auto p = threeElem( nums.at(0), nums.at(1), nums.at(2) ); 
        return (p.first >= p.second);
    }

    std::vector<std::vector<std::pair<int,int>>> dp ( N+1, std::vector<std::pair<int,int>>{} );
        // char: 1:必胜， 0:必输。
        // [0],[1],[2] 三个 子集空置，从 [3] 开始使用
    // 手动实现 3元素 的 值集
    for( int i=0; i<N-3+1; i++ ){// 窗口尺寸:3
        dp.at(3).push_back( threeElem( nums.at(i), nums.at(i+1), nums.at(i+2) ) );
    }
    // 连锁生成 更高层的 数据
    for( int len=4; len<=N; len++ ){// 每种窗口尺寸
        int n = N-len+1;
        dp.at(len).resize( n );
        for( int i=0; i<n; i++ ){// len个元素 的 值集
            //-1- {}+1
            auto p1 = dp.at(len-1).at(i);
            std::swap( p1.first, p1.second );
            p1.first += nums.at(i+len-1);
            bool b1 = p1.first >= p1.second;
            //-2- 1+{}
            auto p2 = dp.at(len-1).at(i+1);
            std::swap( p2.first, p2.second );
            p2.first += nums.at(i);
            bool b2 = p2.first >= p2.second;

            if( b1 && b2 ){// 两种结构 都必胜
                (p1.first-p1.second) >= (p2.first-p2.second) ?
                    dp.at(len).at(i) = p1 :
                    dp.at(len).at(i) = p2;
            }else if( b1 ){// 只有 p1 赢
                dp.at(len).at(i) = p1;
            }else if( b2 ){// 只有 p2 赢
                dp.at(len).at(i) = p2;
            }else{// 两种结果 都输
                (p1.second-p1.first) <= (p2.second-p2.first) ?
                    dp.at(len).at(i) = p1 :
                    dp.at(len).at(i) = p2;
            }
        }
    }
    /*
    for( auto &c : dp ){
        for( auto p : c ){
            cout << p.first << "-" << p.second << "; ";
        }
        cout << endl;
    }
    cout << endl;
    */
    auto &e = dp.back().at(0);
    return (e.first >= e.second );
}





//=========================================================//
void main_(){

    std::vector<int> v { 1,567,1,1,99,100  };
    //std::vector<int> v { 1, 5, 233, 7  };
    //std::vector<int> v { 1, 8, 3  };



    cout << "ret = " << PredictTheWinner(v) << endl;




    debug::log( "\n~~~~ leet: 486 :end ~~~~\n" );
}
}//~
