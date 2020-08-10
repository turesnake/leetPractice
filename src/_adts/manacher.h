/*
 * ===================== manacher.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 马拉车，求 字符串的 最长回文子串
 */
#ifndef TPR_MANACHER_H
#define TPR_MANACHER_H
#include "pch.h"

namespace tpr_manacher{//~

// 相关题目：
// 5
// 214 
//


// -1- 扩展后的字符串，奇数位 是 有效字符位，偶数位 是 分隔符位'#'
// -2- 当 i==mv[i], 恰好说明，此时的以i为中心的回文，可以覆盖 首字母
// -3- mv[i] 恰恰就是 以i为中心的回文 的长度

// 预处理字符串 能降低 实现难度，暂时不做优化了


class M{
public:
    std::string manacher( std::string s ){

        int N = static_cast<int>(s.size());

        // 制作 预处理字符串
        std::string v ( N*2+1, '#' );
        for( int i=0; i<N; i++ ){
            v[i*2+1] = s[i];
        }
        int Nv = static_cast<int>(v.size());

        std::vector<int> mv (Nv,0);// 记录 马拉车数据

        int maxR = 0;// 可以设为最小值，不影响最初的运算
        int center = 0;

        // 可选部分 -1- 最长回文
        int maxLen = 1;// 目前为止，最长回文 的长度
        int start = 0; // 目前为止，最长回文 的起始位置

        // 可选部分 -2- 以首字母开始的 最长回文
        int maxLen2 = 1;

        for( int i=0; i<Nv; i++ ){

            if( i < maxR ){// 当 i==maxR 时，下方 std::min 计算出来的结果是 0
                int mirror = 2*center-i;
                mv[i] = std::min( maxR-i, mv[mirror] );
                    // 核心
                    // 不能无脑等于 mv[mirror]，因为假设 两个回文 是部分重叠的
                    // 那么 当前 center，maxR 表达的 回文段，其前部区间某个字符的 mv值
                    // 是可以 大于 maxR-i 的。
            }

            int l = i - mv[i] - 1;
            int r = i + mv[i] + 1;
            for(; l>=0 && r<Nv && v[l]==v[r]; mv[i]++,l--,r++ ){}

            if( i+mv[i] > maxR ){
                maxR = i+mv[i];
                center = i;
            }

            // 可选部分 -1-
            if( mv[i] > maxLen ){
                maxLen = mv[i];// 很巧
                start = (i-maxLen)/2;
            }

            // 可选部分 -2-
            if( i==mv[i] ){
                maxLen2 = mv[i];// 很巧
            }
        }

        std::string tgtStr( s, start, maxLen );
        return tgtStr;
    }
};




}//~
#endif
