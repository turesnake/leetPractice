/*
 * ====================== leet_69.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 69. x 的平方根
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_69 {//~


class S{
public:

    // 朴素 二分查找
    // 坚决剔除大的，保留小值 
    // uint32_t 还是会溢出
    int mySqrt(int x) {

        if(x==0){ return 0; }
        uint64_t ux = static_cast<uint64_t>(x);
        uint64_t l=0;
        uint64_t r=ux;
        while( l<=r ){
            if( l==r ){ return l; }
            uint64_t mid = l+((r-l)>>1)+1;//mid-right
            uint64_t sq = mid*mid;
            //cout<<"  mid:"<<mid<<", sq="<<sq<<endl;
            if( sq > ux ){
                r = mid-1; // 大值 坚决剔除
            }else if( sq < ux ){
                l = mid; // 小值 保留到下一回合
            }else{
                return mid; // 
            }
        }
        return l;
    }

// 方法二： 牛顿法
// 未来学习....

};


//=========================================================//
void main_(){

    

    cout<<"ret:"<<S{}.mySqrt( 2147395599 )<<endl;
    S s {};
    //for( int i=0; i<100; i++ ){
    //    cout<<" "<<i<<": "<<s.mySqrt(i)<<";  ~:"<< sqrt(i)<<endl;}


    
    debug::log( "\n~~~~ leet: 69 :end ~~~~\n" );
}
}//~
