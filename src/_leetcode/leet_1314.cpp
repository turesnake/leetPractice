/*
 * ====================== leet_1314.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1314. 矩阵区域和
 */
#include "innLeet.h"


namespace leet_1314 {//~


// 先用暴力法 来验证
// 这题的本质是，计算矩阵中一个点，向四周外衍K个单位后，形成的小区域的 和
std::vector<std::vector<int>> matrixBlockSum_1( std::vector<std::vector<int>>& mat, int K ){

    int H = static_cast<int>(mat.size());
    int W = static_cast<int>(mat.at(0).size());

    std::vector<std::vector<int>> outs (H, std::vector<int>(W,0));

    for( int j=0; j<H; j++ ){
        for( int i=0; i<W; i++ ){ // 逐个生成 outs 中每一个元素
            // 用朴素的办法，查找整个原始矩阵，收集所有符合要求的 元素的和
            int sum = 0;
            for( int r=0; r<H; r++ ){
                for( int c=0; c<W; c++ ){
                    int v = mat.at(r).at(c);
                    if( r>=j-K && r<=j+K && c>=i-K && c<=i+K ){
                        sum += v;
                    }
                }
            }
            outs.at(j).at(i) = sum;
        }
    }
    return outs;
}



// 动态规划 尝试版
// 看起来不太完整，只是使用了 “数据复用” 思维
// 1<= K <= 100
std::vector<std::vector<int>> matrixBlockSum_2( std::vector<std::vector<int>>& mat, int K ){

    int H = static_cast<int>(mat.size());
    int W = static_cast<int>(mat.at(0).size());

    //----- K 特大 -----//
    if( K+1 >= std::max(H,W) ){// 如果k特别大, 返回矩阵中，每个元素都是最大值
        int sum = 0;
        for( const auto &c : mat ){
            for( int i : c ){
                sum += i;
            }
        }
        return std::vector<std::vector<int>> ( H, std::vector<int>(W,sum) );
    }

    //----- 主流程 -----//
    // 矩阵中，一个横条中。每个点为中心，一条纵向的，长度为 (2K+1) 的长条区域 的元素的和
    // 它将被复合用，用来快速计算 最终数据
    std::vector<int> lens (W, 0);
    std::vector<std::vector<int>> outs (H, std::vector<int>(W,0));

    for( int j=0; j<H; j++ ){
        // 为每一行，准备 lens 数据
        // 第一行 要手动生成，后续的每一行，只要做一次有限的增减
        if( j==0 ){
            for( int w=0; w<W; w++ ){
                int sum = 0;
                int hLimit = std::min( K+1, H );
                for( int h=0; h<hLimit; h++ ){// 纵条的上半条是没有的，只有中间元素 和 下半条
                    sum += mat.at(h).at(w);
                }
                lens.at(w) = sum;
            }
        }else{
            int loH = j-K-1;// 需要减的 行idx
            int hiH = j+K;// 需要加的 行idx
            for( int w=0; w<W; w++ ){
                if( loH>=0 ){ lens.at(w) -= mat.at(loH).at(w); }
                if( hiH<H ){ lens.at(w) += mat.at(hiH).at(w); }
            }
        }

        // 正式生成 outs 数据
        int box = 0;
        for( int i=0; i<W; i++ ){ // 逐个生成 outs 中每一个元素
            // 行首第一个数据，要手动生成，后续的只要做一次增减
            if( i==0 ){
                int wLimit = std::min( K+1, W );
                for( int a=0; a<wLimit; a++ ){// 行首第一个数据，一般只有中间列，和右侧 K列
                    box += lens.at(a);
                }
            }else{
                int leftW = i-K-1; // 要删的 列
                int rightW = i+K; // 要增的 列
                if( leftW>=0 ){ box -= lens.at(leftW); }
                if( rightW<W ){ box += lens.at(rightW); }
            }
            outs.at(j).at(i) = box;
        }
    }
    return outs;
}





//=========================================================//
void main_(){

    /*
    std::vector<std::vector<int>> mat {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    */

    /*
    std::vector<std::vector<int>> mat {
        {67,64,78},
        {99,98,38},
        {82,46,46},
        {6, 52,55},
        {55,99,45}
    };
    */
    

    
    std::vector<std::vector<int>> mat {
        {1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1}
    };
    

    {
        auto ret = matrixBlockSum_1( mat, 3 );
        for( auto &c : ret ){
            for( int i : c ){
                cout << i << ", ";
            }
            cout << endl;
        }
        cout << "\n" << endl;
    }

    {
        auto ret = matrixBlockSum_2( mat, 3 );
        for( auto &c : ret ){
            for( int i : c ){
                cout << i << ", ";
            }
            cout << endl;
        }
    }
    
    

    debug::log( "\n~~~~ leet: 1314 :end ~~~~\n" );
}
}//~
