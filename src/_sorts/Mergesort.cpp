/*
 * ======================= Mergesort.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.10
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#include "innSorts.h"


namespace sorts_mergesort {//~


// 递归版 实现
class MergeSort {
public:

    void merge( std::vector<int> &v_, int fst_, int mid_, int lst_ ){

        int a = fst_;
        int b = mid_ + 1;
        int i = 0; // 每次都是使用 tmpV 的头部 空间
        for( ; a<=mid_ && b<=lst_; i++ ){
            (v_.at(a) <= v_.at(b)) ?
                    tmpV.at(i) = v_.at(a++) :
                    tmpV.at(i) = v_.at(b++);
        }
        for( ; a<=mid_; a++,i++ ){ tmpV.at(i)=v_.at(a); }
        for( ; b<=lst_; b++,i++ ){ tmpV.at(i)=v_.at(b); }
        for( i=0,a=fst_; i<(lst_-fst_+1); i++,a++ ){
            v_.at(a) = tmpV.at(i);
        }
    }

    
    void split( std::vector<int> &v_, int fst_, int lst_ ){
        if( lst_-fst_+1 == 1 ){ return; }
        int mid = fst_ + (lst_-fst_)/2; // 很不直观的计算
        split( v_, fst_, mid );
        split( v_, mid+1, lst_ );
        merge( v_, fst_, mid, lst_ );
    }


    // 
    std::vector<int> mergesort_1( std::vector<int> &v_ ){
        if( v_.size()<2 ){ return v_; } // do nothing    
        this->tmpV.resize(v_.size()+1, 0);
        int lst = static_cast<int>(v_.size()) - 1;
        int mid = 0 + (lst-0)/2; // 很不直观的计算
        split( v_, 0, mid );
        split( v_, mid+1, lst );
        merge( v_, 0, mid, lst );
        return v_;
    }


private:
    std::vector<int> tmpV {};
};




//=========================================================//
void main_(){

    //std::vector<int> v { 5,8,1,3,0,7,2,9,4,6, };
    //std::vector<int> v { 0,1,2,3,4,5,6,7,8,9 };
    //std::vector<int> v { 3,0,4,2,1,5,6,7,8,9 };
    std::vector<int> v { 9,8,7,6,5,4,3,2,1,0 };
    //std::vector<int> v { 5,1,2 };

    std::swap( *v.begin(), *v.begin() );

    {//----------------//
        cout << "origin datas:" << endl;
        for( const auto i : v ){ cout << i << ", "; }
        cout << endl;
    }

    auto ret = MergeSort{}.mergesort_1( v );

    {//----------------//
        cout << "sort out:" << endl;
        for( const auto i : ret ){ cout << i << ", "; }
        cout << endl;
    }

    debug::log( "\n~~~~ sorts: merge_Sort :end ~~~~\n" );
}
}//~
