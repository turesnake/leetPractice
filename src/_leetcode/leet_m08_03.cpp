/*
 * ====================== leet_m08_03.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 08.03. 魔术索引
 */
#include "innLeet.h"


namespace leet_m08_03 {//~


// 这题 其实很难，
// 递归版有 剪枝 的优势，更快




//    28%   100%
class S{

struct Elem{
    int l {};
    int r {};
};

public:
    // nums 为 有序整数数组
    // nums长度在[1, 1000000]之间
    int findMagicIndex( std::vector<int>& nums ){

        int N = static_cast<int>(nums.size());
        std::deque<Elem> que { Elem{0,N-1} };
        int minIdx = INT_MAX;

        while( !que.empty() ){
            Elem e = que.front();
            que.pop_front();

            if( e.l >= minIdx ){ continue; }// 这个区间过大，不用找了
            if( e.l==e.r ){
                if( nums[e.l]==e.l ){
                    minIdx = std::min( minIdx, e.l );
                }
                continue;
            }

            int mid = e.l+(e.r-e.l)/2;//mid-left
            if( nums[mid]<mid ){
                if( e.l<=nums[mid] ){ que.push_back( Elem{e.l, nums[mid]} ); }
                if( mid+1<=e.r ){ que.push_back( Elem{mid+1, e.r} ); }

            }else if( nums[mid]>mid ){
                if( e.l<=mid-1 ){ que.push_back( Elem{e.l, mid-1} ); }
                if( nums[mid]<=e.r ){ que.push_back( Elem{nums[mid], e.r} ); }

            }else{// ==
                minIdx = std::min( minIdx, mid );
                que.clear();
                if( e.l<=mid-1 ){ que.push_back( Elem{e.l, mid-1} ); } // 只需检查 前母区间了
            }
        }
        return minIdx==INT_MAX ? -1 : minIdx;

    }
};





// 递归版，相对于 迭代版，简化了 deque，
// 并通过剪枝，节省了 收缩的 区间个数
//    96%    100%
class S2{

    std::vector<int> *np {nullptr};
    int minIdx {INT_MAX};

    // ret: 在本区间，是否找到 合适值
    bool work( int l, int r ){

        if( l>=minIdx ){ return false; }// 这个区间过大，不用找了
        if( l==r ){
            if( np->at(l)==l ){
                minIdx = std::min( minIdx, l );
                return true;
            }else{
                return false;
            }
        }
        //---//
        int mid = l+(r-l)/2;//mid-left
        int midVal = np->at(mid);
        if( midVal<mid ){
            if( l<=midVal && work(l,midVal) ){ return true; }// 若左区间找到，就不要找 右侧了
            if( mid+1<=r ){ return work(mid+1,r); }
            return false;

        }else if( midVal>mid ){

            if( l<=mid-1 && work(l,mid-1) ){ return true; }// 若左区间找到，就不要找 右侧了
            if( midVal<=r ){ return work(midVal,r); }
            return false;

        }else{// ==
            minIdx = std::min( minIdx, mid );
            if( l<=mid-1 ){ work(l,mid-1); }// 试探性查找 左区间，找不找到都没关系
            return true;
        }
    }


public:
    // nums 为 有序整数数组
    // nums长度在[1, 1000000]之间
    int findMagicIndex( std::vector<int>& nums ){

        int N = static_cast<int>(nums.size());
        np = &nums;
        bool bl = work(0, N-1);
        return bl ? minIdx : -1;

    }
};




//=========================================================//
void main_(){

    std::vector<int> v { 0,1,2,3,4 };

    auto ret = S2{}.findMagicIndex(v);

    cout<<"ret:"<<ret<<endl;




    
    debug::log( "\n~~~~ leet: m08_03 :end ~~~~\n" );
}
}//~
