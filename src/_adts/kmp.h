/*
 * ========================== kmp.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * kmp 查找 模式串 在 主串内的 位置
 */
#ifndef TPR_MANACHER_H
#define TPR_MANACHER_H
#include "pch.h"

namespace tpr_manacher{//~

// 相关题目：
// 28
// ...


// 此版本 没有将 next 后移一位

class KMP{

    std::string *sp {nullptr};
    std::string *pp {nullptr};
    std::vector<int> next {};
    int Ns {};
    int Np {};

    void build_next(){

        next.resize( Np, 0 );
        int i=1;
        int now = 0;
        while( i<Np ){
            if( pp->at(i)==pp->at(now) ){
                now++;
                next[i]=now;
                i++;
            }else{
                if( now>0 ){
                    now = next[now-1];// 反复下探，直到找到合适的
                }else{
                    next[i] = now;
                    i++;
                }
            }
        }
        //next.insert( next.begin(), -1 ); // 此版本 没用用到 这一步 
        //cout<<"next: "; for( int i:next ){ cout<<i<<", "; }cout<<endl;
    }

public:
    // 若 needle 为空，返回 0
    int strStr( std::string haystack, std::string needle ){

        if( needle.empty() ){ return 0; }

        sp = &haystack;
        pp = &needle;
        Ns = static_cast<int>(haystack.size());
        Np = static_cast<int>(needle.size());

        build_next();

        //=== search ===//
        int si = 0;
        int pi = 0;

        while( si < Ns ){
            if( sp->at(si)==pp->at(pi) ){//两字符相等，下一位
                si++;
                pi++;
            }else{
                if( pi==0 ){// pi到头了，改为步进 si
                    si++;
                }else{      // 两字符不相等，根据 next 移动 pi
                    pi = next[pi-1];
                }
            }
            if( pi == Np ){// 成功匹配到一个 p

                return si-Np; // find !!!

                //pi = next[pi-1]; // 继续寻找，本题不需要
            }
        }

        return -1; // 没找到
        
    }
};





}//~
#endif
