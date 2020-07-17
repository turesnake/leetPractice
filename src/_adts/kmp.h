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
public:
    // 若 needle 为空，返回 0
    int strStr( std::string s, std::string p ){

        if( p.empty() ){ return 0; }

        int Ns = static_cast<int>(s.size());
        int Np = static_cast<int>(p.size());

        std::vector<int> next (Np, 0);
        // next[0]=0;

        //=== next ===//
        int now = 0;
        int i = 1;
        while( i<Np ){
            if( p[now]==p[i] ){
                next[i] = now+1;
                now++;
                i++;
            }else{
                if( now==0 ){
                    next[i]=0;
                    i++;
                }else{
                    now = next[now-1];// 核心
                }
            }
        }
        //cout<<"next: ";for( int i : next ){ cout<<i<<", "; }cout<<endl;

        //=== chech ===//
        std::vector<int> tgtIdxs {};// 所有匹配的 下标
        int j=0;
        i = 0;  
        while( j<Ns-Np ){
            if( s[j]==p[i] ){
                j++;
                i++;
            }else{
                if( i==0 ){// i 不能前移了，改测下一个j
                    j++;
                }else{
                    i = next[i-1];// 核心
                }
            }

            if( i==Np ){// 一次比配成功

                tgtIdxs.push_back( j-Np );

                // j 已经指向 下一位了
                i = next[i-1];
            }
        }
        return tgtIdxs.empty() ? -1 : tgtIdxs[0];
        
    }
};





}//~
#endif
