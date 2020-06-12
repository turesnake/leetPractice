/*
 * ====================== leet_713.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 713. 乘积小于K的子数组
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_713 {//~


// 这题也很容易出错


// 滑动窗口  58%  100%
//
// 关键的乘法部分，使用32位是要溢出的，必须上64位
// 两个相交区间，交合处的元素个数，要被剔除掉 
//
class S{
public:
    // 0 < nums.len <= 50000
    // 0 < nums[i] < 1000
    // 0 <= k < 10^6
    int numSubarrayProductLessThanK( std::vector<int> nums, int k ){

        if( k==0 ){ return 0; }

        int N = static_cast<int>(nums.size());
        uint64_t outSum = 0;
        int product = 1;//区间乘积
        int l=0;
        int r=0;
        // 上一次确定有效的区间
        // 惰性累加，只有当新区间里 l 发生变化时，才真的执行累加
        bool isFst = true;
        int lstL =0;
        int lstR =0;
        for( ; r<N; r++ ){// r 步进
            int curVal = nums.at(r);
            if( curVal >= k ){
                l = r;
                product = curVal;
            }else{
                product *= curVal;
                while( product>=k ){
                    product /= nums.at(l++);
                }
                //-- 目前这个区间合法了 --//
                if( isFst ){
                    isFst = false;
                    lstL = l;
                    lstR = r;
                }else{
                    if( lstL == l ){// 并不需要累加，只要更新下区间
                        lstR = r;
                    }else{
                        // 累加旧区间
                        uint64_t off = static_cast<uint64_t>(lstR-lstL+1);
                        //cout<<"  lstL:"<<lstL<<" lstR:"<<lstR<<" sum:"<< (off+1)*off/2<<endl;
                        outSum += (off+1)*off/2;
                        // 新旧区间的交集，要被删除 
                        if( l <= lstR ){
                            int off2 = lstR-l+1;
                            outSum -= (off2+1)*off2/2;
                        }
                        // 登记 新区间
                        lstL = l;
                        lstR = r;
                    }
                }
            }
        }
        // 补上最后一个区间
        if( !isFst ){
            uint64_t off = static_cast<uint64_t>(lstR-lstL+1);
            //cout<<"  lstL:"<<lstL<<" lstR:"<<lstR<<" sum:"<< (off+1)*off/2<<endl;
            outSum += (off+1)*off/2;
        }
        return static_cast<int>(outSum);

    }
};



//=========================================================//
void main_(){

    std::vector<int> v { 1,1,1,1,1,1,1,1 };
    int k = 9;

    cout<< "ret:\n"<<S{}.numSubarrayProductLessThanK( v,k )<<endl;



    
    debug::log( "\n~~~~ leet: 713 :end ~~~~\n" );
}
}//~
