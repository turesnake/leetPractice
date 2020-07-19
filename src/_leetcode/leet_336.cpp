/*
 * ====================== leet_336.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 336. 回文对
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_336 {//~


// 朴素法 虽然勉强通过了，但看起来并不是正确思路...

// 所有单词 都是唯一的
// 这意味着，空字符串 "", 也只会有一个，它将和其它 非空字符串 相组合
// 空字符串，只有和 一个 回文组合，才能成为 回文


// 官方题解
// 反向检测法：
// 先将所有 单词，存入 uset，用于快速查找

// 然后，使用 马拉车，计算 每个单词，覆盖首字符的 所有回文串
// 然后 将单词 截掉 这些回文后，剩余字符串 反转，查找 是否在 uset 中 

// ...




// 朴素法   5%   100%
class S{

    std::vector<std::vector<int>> outs {};

    void check( const std::string &a, const std::string &b, int ia, int ib, int Na, int Nb ){

        //=== { ia, ib } ===//
        int l=0;
        int r=Nb-1;
        bool isFindDif = false;
        for(; l<Na && r>=0; l++,r-- ){
            if( a[l]!=b[r] ){ 
                isFindDif = true;// 一旦发现相异字符，一定不是回文
                break; 
            }
        }
        if( isFindDif ){ return; }

        bool isRec = false;
        if( l==Na && r==-1 ){
            isRec = true;
        }else if( l==Na ){// 剩下b段
            isFindDif = false;
            int tl = 0;
            int tr = r;
            for(; tl<tr; tl++,tr-- ){
                if( b[tl]!=b[tr] ){ isFindDif = true; break; }
            }
            isRec = !isFindDif;
        }else if( r==-1 ){// 剩下a段
            isFindDif = false;
            int tl = l;
            int tr = Na-1;
            for(; tl<tr; tl++,tr-- ){
                if( a[tl]!=a[tr] ){ isFindDif = true; break; }
            }
            isRec = !isFindDif;
        }else{
            assert(0);
        }
        if( isRec ){ outs.push_back( {ia,ib} ); }
    }


public:
    // 每个单词 都是 唯一的
    std::vector<std::vector<int>> palindromePairs( std::vector<std::string>& words ){


        int N = static_cast<int>(words.size());
        if( N<2 ){ return outs; }

        for( int j=0; j<N-1; j++ ){
            for( int i=j+1; i<N; i++ ){
                int Nj = static_cast<int>(words[j].size());
                int Ni = static_cast<int>(words[i].size());
                check( words[j], words[i], j,i, Nj, Ni );
                if( words[j] != words[i] ){
                    check( words[i], words[j], i,j, Ni, Nj );
                }
            }
        }

        return outs;

    }
};




//=========================================================//
void main_(){



    debug::log( "\n~~~~ leet: 336 :end ~~~~\n" );
}
}//~
