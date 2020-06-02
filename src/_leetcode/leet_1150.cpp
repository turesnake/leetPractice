/*
 * ====================== leet_1150.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1150. 检查一个数是否在数组中占绝大多数
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1150 {//~


// 似乎还有更快的方法



// 43%, 100%
// 只要找到两个指针，指向的值都是 target，且间距超过一半，就算正确
class S{
public:
    bool isMajorityElement( std::vector<int> nums, int target ){

        if( nums.empty() ){ return false; }
        int N = static_cast<int>(nums.size());

        //--- find fst one ---//
        int l=0;
        int r=N-1;
        bool isFind {false};
        int fstIdx {};
        while( l<=r ){
            fstIdx = l+(r-l)/2;//mid-left
            int v = nums.at(fstIdx);
            if( target < v ){
                r = fstIdx-1;
            }else if( target > v ){
                l = fstIdx+1;
            }else{
                isFind = true;
                break;
            }
        }
        if( !isFind ){ return false; }

        // 更精确的 搜索区间
        // 两个区间同时 二分查找 
        int ll = l;
        int lr = fstIdx;
        int rl = fstIdx;
        int rr = r;
        int lmid {};
        int rmid {};
        while( ll<=lr || rl<=rr ){
            while( ll<=lr ){
                if( ll==lr ){ lmid=ll; break; }// 彻底找到了
                lmid = ll+(lr-ll)/2;//mid-left
                if( nums.at(lmid) == target ){
                    lr = lmid;
                    break;
                }else{// 小于
                    ll = lmid+1; // 坚决剔除
                }
            }
            while( rl<=rr ){
                if( rl==rr ){ rmid=rl; break; }// 彻底找到了
                rmid = rl+(rr-rl)/2+1;//mid-right
                if( nums.at(rmid) == target ){
                    rl = rmid;
                    break;
                }else{//大于
                    rr = rmid-1;
                }
            }
            if( rmid-lmid+1 > N/2 ){ return true; }
            if( ll==lr && rl==rr ){ break; }
        }
        return false;
    }
};


//=========================================================//
void main_(){

    cout<<"ret: " << S{}.isMajorityElement( {1,2,2,3,4,5,6,7,8,9,10,11,12}, 2) <<endl;

    
    debug::log( "\n~~~~ leet: 1150 :end ~~~~\n" );
}
}//~
