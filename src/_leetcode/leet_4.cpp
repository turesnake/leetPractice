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


// 排序法   debug 用 
class S1{
public:
    double findMedianSortedArrays( std::vector<int>& nums1, std::vector<int>& nums2 ){

        std::vector<int> nums ( nums1.begin(), nums1.end() );
        nums.insert( nums.end(), nums2.begin(), nums2.end() );
        std::sort( nums.begin(), nums.end() );
        int Nall = static_cast<int>(nums.size());
        int ml = (Nall-1)/2;
        int mr = (Nall&1)==0 ? ml+1 : ml;
        //cout<<"ml:"<<ml<<", mr:"<<mr<<endl;
        return static_cast<double>(nums[ml]+nums[mr])/2;
    }
};



// O(m+n) 法, debug 用 
class S2{
public:
    double findMedianSortedArrays( std::vector<int>& nums1, std::vector<int>& nums2 ){

        int N1 = static_cast<int>(nums1.size());
        int N2 = static_cast<int>(nums2.size());
        int Nall = N1 + N2;

        int mid_lV {};
        int mid_rV {};

        int midl = Nall/2;
        int midr = (Nall&1)==0 ? midl+1 : midl;
        //cout<<"midl:"<<midl<<", midr:"<<midr<<endl;

        int a=0;
        int b=0;
        int count = 0;

        while( a<N1 || b<N2 ){

            if( a>=N1 ){
                b++;
            }else if( b>=N2 ){
                a++;
            }else{
                nums1[a] <= nums2[b] ? a++ : b++;
            }

            count++;
            if( count == midl ){
                mid_lV = std::min( nums1[a], nums2[b] );
            }
            if( count == midr ){
                mid_rV = std::min( nums1[a], nums2[b] );
                break;
            }
        }
        return static_cast<double>(mid_lV+mid_rV)/2; 
        
    }
};



// 二分折半删除法

// O(log(m+n))    96%   100%
// 假设 k=mid-left-idx
// 每次对比 两数组中 [k/2] 位元素，如果某个较小，就把它以及它前面的元素统统删掉
// 然后 k-=k/2;
// ---
// 万一 某个数组长度 小于 k/2,
// 这个短数组 直接访问 尾元素，另一个数组继续访问 [k/2]
// 这样保证，每一回合，都能删除掉 k/2个元素，或者彻底删除某个数组
class S3{

    std::vector<int> *np1 {nullptr};
    std::vector<int> *np2 {nullptr};
    
    int N1 {};
    int N2 {};

    // 从 两个数字中，删掉 5 个 元素 
    int work( int l1, int l2, int k ){
        //cout<<"l1:"<<l1<<", l2:"<<l2<<", k:"<<k<<endl;
        if( l1>=N1 ){
            return np2->at( l2+k );
        }
        if( l2>=N2 ){
            return np1->at( l1+k );
        }
        if( k==0 ){
            return std::min( np1->at(l1), np2->at(l2) );
        }
        if( k==1 ){
            if( np1->at(l1) <= np2->at(l2) ){
                return work( l1+1, l2, 0 );
            }else{
                return work( l1, l2+1, 0 );
            }
        }
        int len1 = std::min( k/2, N1-l1 );
        int len2 = std::min( k/2, N2-l2 );
        int i1 = l1+len1-1;
        int i2 = l2+len2-1;
        //cout<<"~~"<<endl;
        //cout<<"i1:"<<i1<<", i2:"<<i2<<endl;
        if( np1->at(i1) <= np2->at(i2) ){
            l1 += len1;
            return work( l1, l2, k-len1 );
        }else{
            l2 += len2;
            return work( l1, l2, k-len2 );
        }
    }



public:
    double findMedianSortedArrays( std::vector<int>& nums1, std::vector<int>& nums2 ){

        N1 = static_cast<int>(nums1.size());
        N2 = static_cast<int>(nums2.size());
        int Nall = N1 + N2;

        np1 = &nums1;
        np2 = &nums2;
        bool isOdd = (Nall&1)==1;
        int lVal = work( 0, 0, (Nall-1)/2 );// mid-left
        int rVal = (Nall&1)==1 ? lVal : work( 0, 0, (Nall-1)/2+1 );// mid-right
        //cout<<"lVal:"<<lVal<<", rVal:"<<rVal<<endl;
        return static_cast<double>(lVal+rVal)/2;


    }
};









//=========================================================//
void main_(){

    std::vector<int> v1 { 1,2 };
    std::vector<int> v2 { 3,4 };

    //std::vector<int> v1 { 3,7 };
    //std::vector<int> v2 { 1,2,4,5,6 };

    // 目标:
    //std::vector<int> v1 { 1,5,6,7,8,9,9 };
    //std::vector<int> v2 { 2,3,4,8,9,10,11 };

    // 目标: 10,11
    //std::vector<int> v1 { 1,5,6,10,12,13,15 };
    //std::vector<int> v2 { 2,9,11,20,30 };

    // 目标: 10
    //std::vector<int> v1 { 1,2,3,4 };
    //std::vector<int> v2 { 9,10,11,20,30,31,40 };



    debug::log( "<0>: {}", S1{}.findMedianSortedArrays(v1,v2) );
    cout << endl;
    debug::log( "<1>: {}", S3{}.findMedianSortedArrays(v1,v2) );
    cout << endl;
    //debug::log( "<2>: {}",  S2{}.findMedianSortedArrays(v2,v1) );
    


    debug::log( "\n~~~~ leet: 4 :end ~~~~\n" );
}
}//~
