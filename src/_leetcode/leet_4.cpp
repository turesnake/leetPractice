/*
 * ====================== leet_4.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.24
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 4. 寻找两个正序数组的中位数
 */
#include "innLeet.h"


namespace leet_4 {//~




//     目前这个方法是 错的 


// - 长数组 一定不为空，但也允许非常短
// - 短数组 [0,2] 个
// 将短数组 和 长数组的 中位[2,4]个元素 做收集排序，然后 中位数
double work( std::vector<int> &longNums, int l, int r,
             std::vector<int> &shortNums, int sIdx, int sLen ){

    std::vector<int> v {};
    if( sLen > 0 ){
        for( int i=sIdx; i<sIdx+sLen; i++ ){ v.push_back( shortNums.at(i) ); }
    }// 短数组 为空时，不处理

    bool isOdd = (r-l+1)%2!=0;
    if( r-l<=3 ){// 长数组小于 4 个元素
        for( int i=l; i<=r; i++ ){
            v.push_back( longNums.at(i) );
        }
    }else{
        int mid = l + (r-l)/2; // 中位偏左
        if( isOdd ){// 长数组 奇数个
            for( int i=mid-1; i<=mid+1; i++ ){// 3个
                v.push_back( longNums.at(i) );
            }
        }else{// 长数组 偶数个
            for( int i=mid-1; i<=mid+2; i++ ){// 4个
                v.push_back( longNums.at(i) );
            }
        }
    }
            cout << "== work: v: ";
            for( int i : v ){ cout << i << ", "; }
            cout <<endl;

    std::sort( v.begin(), v.end() );// 数据量很小
    int N = static_cast<int>(v.size());
    int mid = (N-1)/2;// 中间偏左
    isOdd = N%2!=0;

            cout << "== sorted: v: ";
            for( int i : v ){ cout << i << ", "; }
            cout <<endl;

    return isOdd ?
            static_cast<double>(v.at(mid)) :
            (static_cast<double>(v.at(mid))+static_cast<double>(v.at(mid+1)))/2.0;
}




// 两数组 不同时为空
double findMedianSortedArrays_2( std::vector<int>& nums1, std::vector<int>& nums2 ){
    
    int N1 = static_cast<int>(nums1.size());
    int N2 = static_cast<int>(nums2.size());
    int l1 = 0;
    int r1 = N1-1;
    int l2 = 0;
    int r2 = N2-1;

    if( N1<=N2 ){
        if( N1<=2 ){ return work( nums2, l2, r2, nums1, l1, N1 ); }
    }else{
        if( N2<=2 ){ return work( nums1, l1, r1, nums2, l2, N2 ); }
    }
    int minDelLen {};

        cout <<"begin:"<< endl;
        cout << "  l1:"<<l1 << ", r1:"<<r1
            << "; l2:"<<l2 << ", r2:"<<r2 << endl;

    //执行 区间删除，直到某段数据剩下 2个元素 位置
    while( (r1-l1)>1 && (r2-l2)>1 ){

        // 中位数计算，中间偏左，如果 l/r 紧邻或相同，指向l
        int mid1 = l1 + (r1-l1)/2;// 中间偏左
        int mid2 = l2 + (r2-l2)/2;// 中间偏左
        int mv1 = nums1.at(mid1);
        int mv2 = nums2.at(mid2);

        if( mv1 <= mv2 ){
            // 各删一段
            minDelLen = std::min( mid1-l1, r2-mid2 );
            l1 += minDelLen;
            r2 -= minDelLen;
        }else{
            // 各删一段
            minDelLen = std::min( r1-mid1, mid2-l2 );
            r1 -= minDelLen;
            l2 += minDelLen;
        }

            cout << "  l1:"<<l1 << ", r1:"<<r1
                << "; l2:"<<l2 << ", r2:"<<r2
                << ", minDelLen:" << minDelLen << endl;
    }
    // 现在，获得一个 长数组，和一个短数组（n==2）

        cout <<"out:"<< endl;
        cout << "  l1:"<<l1 << ", r1:"<<r1
            << "; l2:"<<l2 << ", r2:"<<r2 << endl;


    if( r1-l1==1 ){// 短数组为 1
        return work( nums2, l2, r2, nums1, l1, r1-l1+1 );
    }else{// 短数组为 2
        return work( nums1, l1, r1, nums2, l2, r2-l2+1 );
    }
}








//=========================================================//
void main_(){

    // 目标: 9,11
    std::vector<int> v1 { 1,5,6,7 };
    std::vector<int> v2 { 2,3,4,8,9,10 };

    // 目标: 10,11
    //std::vector<int> v1 { 1,5,6,10,12,13,15 };
    //std::vector<int> v2 { 2,9,11,20,30 };

    // 目标: 10
    //std::vector<int> v1 { 1,2,3,4 };
    //std::vector<int> v2 { 9,10,11,20,30,31,40 };

    
    debug::log( "<1>: {}", findMedianSortedArrays_2(v1,v2) );
    cout << endl;
    debug::log( "<2>: {}", findMedianSortedArrays_2(v2,v1) );
    


    debug::log( "\n~~~~ leet: 4 :end ~~~~\n" );
}
}//~
