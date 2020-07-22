/*
 * ====================== leet_m17_26.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.22
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 17.26. 稀疏相似度
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"

#include <sstream>
#include <iomanip>


namespace leet_m17_26 {//~


// 统一大容器 思路


// 另一个过关的 核心是，在收集 所有 合法组合时，顺带收集，每种组合，到底重合了几个元素
// 省去了后面，针对每个组合，再做一次 统计的 开销


//   95%   100%
class S{
public:
    // docs.length <= 500
    // docs[i].length <= 500
    // 空子数组 将被忽略
    // 只返回 相似度 大于0 的组合
    // 相似度，精确到 小数点后4位
    // 每个子数组内的 元素，不相同
    std::vector<std::string> computeSimilarities( std::vector<std::vector<int>>& docs ){

        int N = static_cast<int>(docs.size());
        if( N<=1 ){ return {}; }

        // 将所有数据，整合到一个 统一的 大容器中，每个元素，记录自己所属的 组们
        std::unordered_map<int,std::vector<int>> umap {};
        for( int i=0; i<N; i++ ){
            for( int val : docs[i] ){
                umap[val].push_back( i );
            }
        }

        // 收集出 所有 合法的 组合
        std::unordered_map<int,int> pairs {};//<key,nums> 核心

        for( auto &[val,vec] : umap ){
            if( vec.size()==1 ){ continue; }
            int Nv = static_cast<int>(vec.size());
            for( int l=0; l<Nv; l++ ){
                for( int r=l+1; r<Nv; r++ ){
                    int key = vec[l]*1000 + vec[r];
                    pairs[key]++; // 核心， 统计 每一对组合，重合了多少个元素
                }
            }
        }

        // 分别计算每个组合的 结果
        std::vector<std::string> outs {};

        for( auto [key,num] : pairs ){
            int l = key/1000;
            int r = key%1000;
            double uNum = static_cast<double>( docs[l].size()+docs[r].size()-num );// 核心
            double iNum = static_cast<double>(num);
            //---//
            //std::stringstream ss {};
            //ss<<l<<","<<r<<": " << std::showpoint << std::setprecision(4) << iNum/uNum;
            //outs.push_back( ss.str() );

            
            char s[20];
            sprintf(s, "%d,%d: %.4f", l, r, iNum/uNum + 1e-9);
            outs.push_back( std::string( s, s+20 ) );

        }
        return outs;



    }
};



//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: m17_26 :end ~~~~\n" );
}
}//~
