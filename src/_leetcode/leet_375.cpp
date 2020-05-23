/*
 * ====================== leet_375.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 375. 猜数字大小 II
 */
#include "innLeet.h"
//#include "TreeNode1.h"


namespace leet_375 {//~


//============================== 第一套方案是 错误的 ===================//

// 计算 区间 [l,r] 的 所有元素的和
int calc_sum( int l, int r ){
    return (l+r)*(r-l+1)/2;
}


// 在区间 [l,r] 之间，寻找一个 中间点，使得两侧元素之和最接近
// 返回这个中间点的值
int findMid( int left, int right ){
    int N = right-left+1;
    switch (N){
        case 1: return left; // l,r 相同
        case 2: return left;
        case 3: return left+1;
        case 4: return left+2;
        default: break;
    }
    int mid = left+N/2;
    int lSum = calc_sum(left,mid-1);
    int rSum = calc_sum(mid+1,right);
    int off = std::abs( lSum - rSum );
    mid++;
    while( mid < right ){
        lSum += mid-1;
        rSum -= mid;
        int newOff = std::abs( lSum - rSum );
        if( newOff > off ){ return (mid-1); }// 上一个 mid就是合适的
        // 本次 mid 更合适
        off = newOff;
        mid++;
    }
    return (mid-1);// == righ-1
}


// 返回 区间 [l,r] 的 最小 遍历路径和
int work( int left, int right ){
    int N = right-left+1;
    switch (N){
        case 1: return 0;
        case 2: return left;
        case 3: return left+1;
        default: break;
    }
    int mid = findMid( left, right );
    return mid + std::max( work(left,mid-1), work(mid+1,right) );
}



// n>=1
int getMoneyAmount(int n) {
   return work( 1, n );
}


//=====================================================================//

// 动态规划解 39.78%， 100%
class S{

    // 每个元素，记载了 [a,b] 区间 的所有最优解的 最大值
    std::vector<std::vector<int>> dp {};//[b][a]
    auto &dp_at( int a, int b ){ return dp.at(b-1).at(a-1); }//参数颠倒

    // dp 实际空间为 三角形，
    //在不将 dp 压缩为两个 数组之前，最大程度地节省空间
    void dp_resize( int n ){
        dp.resize( n, std::vector<int>{} );
        for( int i=0; i<n; i++ ){
            dp.at(i).resize(i+1, 0);
        }
    }

    // 计算 区间 [a,b] 最优情况的 最大值
    int calc_min( int a, int b ){
        int N = b-a+1;
            switch (N){
            case 1: return 0;
            case 2: return a;
            case 3: return a+1;
            default: break;
        }
        int mid = a + N/2 - 1;// 区间[1,b] 中间元素（双值则偏小）
                // 若设为 中部偏右，会无法算到 最优解
        int mmin {INT_MAX};
        for( ; mid<b; mid++ ){
            int v = mid + std::max( dp_at(a,mid-1), dp_at(mid+1,b) );
            mmin = std::min( mmin, v );
        }
        return mmin;
    }

public:
    // n>=1
    int getMoneyAmount( int n ){
        
        dp_resize( n );
        for( int b=1; b<=n; b++ ){// b 其实遍历的是 w（横向）
            for( int a=b; a>=1; a-- ){// a 遍历的是 h（纵向）,倒序
                dp_at(a,b) = calc_min(a,b);
            }
        }
        /*
        cout << "dp:" << endl;
        for( auto &c : dp ){
            for( int i : c ){ cout << i << ", "; }
            cout << endl;
        }
        cout << "=======" << endl;
        */
        return dp_at(1,n);
    }

};



//=========================================================//
void main_(){

    //cout << findMid( 11, 16 ) << endl;

    cout << S{}.getMoneyAmount( 9 ) << endl;

    debug::log( "\n~~~~ leet: 375 :end ~~~~\n" );
}
}//~
