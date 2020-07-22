/*
 * ====================== leet_m10_02.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 10.02. 变位词组
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m10_02 {//~


// 本质上，是一道，计算 字符串 hash 值的题


// 偷懒法，直接对 每个单词做 字符排序，获得 统一的 key
//    45%   100%
class S{
public:
    // 所有输入均为小写字母。
    // 不考虑答案输出的顺序。
    std::vector<std::vector<std::string>> groupAnagrams( std::vector<std::string>& strs ){

        std::vector<std::vector<std::string>> outs {};
        if( strs.empty() ){ return outs; }

        int N = static_cast<int>(strs.size());
        std::unordered_map<std::string, std::vector<int>> umap {};

        for( int i=0; i<N; i++ ){
            std::string k = strs[i];
            std::sort( k.begin(), k.end() );
            umap[k].push_back(i);
        }
        for( auto &[k,v] : umap ){
            outs.push_back( std::vector<std::string>{} );
            for( int i : v ){
                outs.back().push_back( strs[i] );
            }
        }
        return outs;


    }
};


// 为每个单词形成一个 hashkey，
// 比如, "a1b2k11" 这种


//   26%  100%
class S2{
public:
    // 所有输入均为小写字母。
    // 不考虑答案输出的顺序。
    std::vector<std::vector<std::string>> groupAnagrams( std::vector<std::string>& strs ){

        std::vector<std::vector<std::string>> outs {};
        if( strs.empty() ){ return outs; }

        int N = static_cast<int>(strs.size());
        std::unordered_map<std::string, std::vector<int>> umap {};
        std::vector<int> kv {};

        for( int i=0; i<N; i++ ){
            kv.clear();
            kv.resize(26, 0);
            for( char c : strs[i] ){
                kv[c-'a']++;
            }
            std::string k {};
            for( int i=0; i<26; i++ ){
                if( kv[i]>0 ){
                    k += 'a'+i;
                    k += std::to_string( kv[i] );
                }
            }
            umap[k].push_back(i);
        }
        for( auto &[k,v] : umap ){
            outs.push_back( std::vector<std::string>{} );
            for( int i : v ){
                outs.back().push_back( strs[i] );
            }
        }
        return outs;


    }
};





//=========================================================//
void main_(){

    std::string s = "bbcddab";

    std::sort( s.begin(), s.end() );

    cout<<"s:"<<s<<endl;



    debug::log( "\n~~~~ leet: m10_02 :end ~~~~\n" );
}
}//~
