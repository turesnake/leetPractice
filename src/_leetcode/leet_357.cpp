/*
 * ====================== leet_357.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 357. 计算各个位数不同的数字个数
 */
#include "innLeet.h"


namespace leet_357 {//~


// 最老实的办法，先计算出所有 存在重复元素的 种类，再反减
// -----------
// 暂时 未能实现 
// n = 4;
// 输出：5032
// 预期：5275
// 差了 243 个元素 
class S {

    std::vector<int> bits {}; // 记录每个位是否放了 重复数字
    int originN {}; // 参数 n
    int dupSum {}; // 存在重复数字的 元素的 个数

public:

    // 当前状态下，非头部的 重复元素个数，是否大于1
    bool isHaveSerialInnBits(){
        // find fst 非重复元素
        int i = 0;
        for( ; (i<originN) && (bits.at(i)!=0) ; i++ ){}
        if( i == originN ){ return false; } // 遍历到底也没找到
        int dupNum {0};
        for( ; i<originN; i++ ){
            if( bits.at(i)==1 ){ dupNum++; }
        }
        return (dupNum>1);
    }


    // leftK_ 本回合起，还需要要插入的 重复数字个数
    // idx_ 本回合遍历到的 位数（从左到右）[0, originN-1]
    // 一旦匹配成功，就向总容器 dupSum 累加的值
    void work( int leftK_, int idx_, int add_ ){

        if( leftK_ == 0 ){// 重复元素布置完毕
            isHaveSerialInnBits() ?
                    add_ *= 10 : // 全 10 种数字
                    add_ *= 9;  // 非头部 重复性元素 小于2个，只有 9 种
            cout << "add = " << add_ << endl;
            this->dupSum += add_;
            return;
        }
        if( idx_ == originN ){ //位置遍历完毕，但重复元素并未插满，本枝作废
            return;
        }
        // 本位 记入 重复元素
        this->bits.at(idx_) = 1;
        work( leftK_-1, idx_+1, add_ );
        // 本位 不记入 重复元素
        this->bits.at(idx_) = 0;
        work( leftK_, idx_+1, add_ );
    }

    int countNumbersWithUniqueDigits( int n ) {
        if( n==0 ){ return 1; }
        if( n==1 ){ return 10; }

        this->bits.resize( n, 0 );
        this->originN = n;
        for( int i=2; i<=n; i++ ){
            // 每找到一个匹配分布方案，就直接在总数里累加这个值 
            int add { 1 };
            for( int j=0; j<n-i; j++ ){
                add *= 9;
            }
            work( i, 0, add );
        }
        // 所有重复元素 个数 统计完毕
        int totalNum { 1 };
        for( int i=0; i<n; i++ ){
            totalNum *= 10;
        }
        return totalNum - dupSum;
    }

};





//=========================================================//
void main_(){

    auto ret = S{}.countNumbersWithUniqueDigits( 4 );
    cout << "ret = " << ret << endl;
    

    debug::log( "\n~~~~ leet: 357 :end ~~~~\n" );
}
}//~
