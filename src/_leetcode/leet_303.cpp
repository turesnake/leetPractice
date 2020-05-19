/*
 * ====================== leet_303.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 303. 区域和检索 - 数组不可变
 */
#include "innLeet.h"


namespace leet_303 {//~



// 树状数组
class NumArray{


class TTree{
    std::vector<int> data {};// 0号位空置
    int             ssize {};// 不计算0号位
    int lowbits( int v ){ return v&(-v); }//二进制表达最低位1
public:
    TTree()=default;

    void init( int num ){
        data.resize( num+1, 0 );
        ssize = num+1;
    }

    void add( int idx, int add ){// 只能累加值
        int i = idx+1;// 0号位空置
        while( i < ssize ){
            data.at(i) += add;
            i += lowbits( i );
        }
    }

    int sum( int idx ){
        int i = idx+1;
        int sum {0};
        while( i > 0 ){
            sum += data.at(i);
            i -= lowbits( i );
        }
        return sum;
    }
};

    TTree tree {};


public:
    NumArray( std::vector<int>& nums ){
        int ssize = static_cast<int>(nums.size());
        tree.init( ssize );
        for( int i=0; i<ssize; i++ ){
            tree.add( i, nums.at(i) );
        }
    }
    
    int sumRange(int i, int j){
        return (tree.sum(j)-tree.sum(i-1));
    }

};




// 用动态规划的思路，来存储 前缀和
class NumArray_2 {
    std::vector<int> sums {};
public:
    NumArray_2( std::vector<int>& nums ){
        int Nnum = static_cast<int>(nums.size());
        sums.resize( Nnum+1, 0 );
        if( Nnum==0 ){ return; }
        sums.at(1) = nums.at(0);
        for( int i=1; i<Nnum; i++ ){
            sums.at(i+1) = sums.at(i) + nums.at(i);
        }
    }
    int sumRange(int i, int j){
        int Nnum = static_cast<int>(sums.size()) - 1;
        if( i>=Nnum || j>=Nnum ){  return 0;  }
        return (i==0) ? 
            sums.at(j+1) :
            sums.at(j+1) - sums.at(i);
    }
};




//=========================================================//
void main_(){

    std::vector<int> v {  };
    //std::vector<int> v { -2, 0, 3, -5, 2, -1 };
    //std::vector<int> v { 1,1,1,1,1,1,1,1,1,1 };

    NumArray_2 obj { v };

    /*
    for( size_t i=0; i<v.size(); i++ ){
        cout << i << ": " << obj.sumRange( i,i ) << endl;
    }
    */



    
    cout << obj.sumRange( 0,0 ) << endl;
    //cout << obj.sumRange( 2,5 ) << endl;
    //cout << obj.sumRange( 0,5 ) << endl;
    





    debug::log( "\n~~~~ leet: 303 :end ~~~~\n" );
}
}//~
