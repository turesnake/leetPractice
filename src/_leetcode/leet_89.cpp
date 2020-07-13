/*
 * ====================== leet_89.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.13
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 89. 格雷编码
 */
#include "innLeet.h"


namespace leet_89 {//~


// 在 2进制中，2位一组，不停做循环: 0-1-3-2-...

// 这个思路的本质，就是 设计并实现一个 特殊的 钟表

//   46%   100%
class S{
    const std::vector<int> bases { 0,1,3,2 };
public:
    // n >= 0
    std::vector<int> grayCode( int n ){

        if( n==0 ){ return { 0 }; }
        if( n==1 ){ return { 0,1 }; }

        int Npair = (n-1)/2+1; // 若n为奇树，顶pair 只需要填一半
        int totalNum = static_cast<int>(pow(2,n));// 总个数

        std::vector<int> outs (totalNum, 0);
        std::vector<int> v ( Npair, 0 );// 存储idx，访问 bases
        std::vector<int> counts ( Npair, 0 );// 每个元素的 变化次数 计数器，0表示0次

         // 全局 计数器
        for( int ct=1; ct<totalNum; ct++ ){
            //=== 进位 ===//
            if( ct%4==0 ){// 关键帧
                for( int i=Npair-1; i>=0; i-- ){
                    if( counts[i]==3 ){
                        counts[i]=0;
                    }else{
                        counts[i]++;
                        v[i]++;
                        break;
                    }
                }
            }else{// 剩余 3个 非关键帧
                counts.back()++;
                v.back()++;
            }
            //=== 计算 本回合值 ===//
            for( int i=Npair-1; i>=0 && v[i]!=0; i-- ){
                outs[ct] += bases[v[i]%4] * static_cast<int>(pow(4, Npair-1-i));
            }
        }
        return outs;
    }
};



//=========================================================//
void main_(){

    auto ret = S{}.grayCode( 2 );

    cout<<"ret:"<<endl;
    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;



    debug::log( "\n~~~~ leet: 89 :end ~~~~\n" );
}
}//~
