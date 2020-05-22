/*
 * ====================== leet_1277.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1277. 统计全为 1 的正方形子矩阵
 */
#include "innLeet.h"


namespace leet_1277 {//~


// 暴力法
int countSquares_1( std::vector<std::vector<int>>& matrix ){

    int H = static_cast<int>(matrix.size());
    int W = static_cast<int>(matrix.at(0).size());
    int sum = 0;
    int limit = std::min(H,W); // 正方形直径 最大值
    
    for( int n=1; n<=limit; n++ ){// 每种直径的 正方形
        int hSize = H-n+1;// 搜索 [0,hSize) 区域
        int wSize = W-n+1;// 搜索 [0,wSize) 区域
        
        for( int h=0; h<hSize; h++ ){
            for( int w=0; w<wSize; w++ ){// 遍历矩阵中 每个匹配的区域

                bool isFindZero {false};
                for( int j=0; j<n; j++ ){
                    for( int i=0; i<n; i++ ){
                        if( matrix.at(h+j).at(w+i)==0 ){
                            isFindZero = true;
                            break;
                        }
                    }
                    if( isFindZero==true ){ break; }
                }
                if( !isFindZero ){ 
                    //cout << "n:" << n << endl;
                    sum++; 
                }
            }
        }
    }
    return sum;
}



// 动态规划 5.07%， 50%
// 在时间上，仍然不算正确的优化方式
//
// 参考答案中，使用了另一种不同的方案。 有待正式学习 ...
//
int countSquares_2( std::vector<std::vector<int>>& matrix ){

    int H = static_cast<int>(matrix.size());
    int W = static_cast<int>(matrix.at(0).size());
    int sum = 0;
    int limit = std::min(H,W); // 正方形直径 最大值

    std::vector<std::vector<int>> dp (matrix.begin(), matrix.end());
        // 每个元素，记载以自己为起点的 较小的N值时，自己是不是 全是1
        // 如果已经在较小的阶段 存在 0 了，就不需要 额外检查这个区域了
        // 如果一个元素 为 1，它未来可能被改成 0
        // 如果一个元素 为 0，它将永远为 0;
        
    for( int n=1; n<=limit; n++ ){// 每种直径的 正方形，都要检测
        int hSize = H-n+1;// 搜索 [0,hSize) 区域
        int wSize = W-n+1;// 搜索 [0,wSize) 区域

        for( int h=0; h<hSize; h++ ){
            for( int w=0; w<wSize; w++ ){// 遍历矩阵中 每个匹配的区域

                bool isFindZero {false};
                // 如果 dp中，头元素已经标为 0，说明 以此元素 开头的正方形，都不可能 全为1 了
                if( dp.at(h).at(w)==0 ){
                    isFindZero = true;
                }else{
                    for( int i=0; i<n; i++ ){// 下方行
                        if( matrix.at(h+n-1).at(w+i)==0 ){
                            isFindZero = true;
                            break;
                        }
                    }
                    if( !isFindZero ){
                        for( int j=0; j<n-1; j++ ){// 右边列
                            if( matrix.at(h+j).at(w+n-1)==0 ){
                                isFindZero = true;
                                break;
                            }
                        }
                    }
                    if( isFindZero ){ dp.at(h).at(w) = 0; }// 永久修改为 0
                }
                if( !isFindZero ){ sum++; }
            }
        }
    }
    return sum;
}










//=========================================================//
void main_(){

    
    std::vector<std::vector<int>> mat {
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1},
    };
    
    

    /*
    std::vector<std::vector<int>> mat {
        {1,0,1},
        {1,1,0},
        {1,1,0},
    };
    */
    

    /*
    std::vector<std::vector<int>> mat {
        {0},
        {0}
    };
    */


    cout << countSquares_1(mat) << endl;
    cout << countSquares_2(mat) << endl;
    
    

    debug::log( "\n~~~~ leet: 1277 :end ~~~~\n" );
}
}//~
