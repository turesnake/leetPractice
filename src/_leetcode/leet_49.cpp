/*
 * ====================== leet_49.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 49. 字母异位词分组
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_49 {//~



// 另一种方法是，将每个单词字母排序，排序后的那个str。就是key
// 更简单 



// hash法   30%  100%
// 针对每个单词使用了什么字母，为其生成一个 hash值 "3a1e1t"
// 然后存入一个 umap 中
class S{
public:
    // 所有输入均为小写字母
    // 不考虑答案输出的顺序
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs ){


        if(strs.empty()){ return {}; }

        std::vector<int> charNums (26,0);//每个单词，使用各个字母的个数
        //key是自制的，val是合规str 在vec 中的下标
        std::unordered_map<std::string,std::vector<int>> umap{};
        
        int N = static_cast<int>(strs.size());
        for( int i=0; i<N; i++ ){
            const auto &word = strs.at(i);
            if( word.empty() ){
                umap["0"].push_back(i);
                continue;
            }
            charNums.clear();
            charNums.resize(26,0);
            for( char c : word ){
                charNums.at(c-'a')++;
            }
            // build key
            std::string key = "";
            for( int i=0; i<26; i++ ){
                int num = charNums.at(i);
                if( num>0 ){
                    key += std::to_string(num);
                    key += 'a'+i;
                }
            }
            cout<<" key:"<<key<<endl;
            umap[key].push_back(i);
        }
        //===//
        std::vector<std::vector<std::string>> outs {};
        for( auto &[key,vec] : umap ){
            outs.push_back( std::vector<std::string>{} );
            auto &b = outs.back();
            for( int i : vec ){
                b.push_back( strs.at(i) );
            }
        }
        return outs;
    }
};




//=========================================================//
void main_(){

    std::vector<std::string> v {
        "eat", "tea", "tan", "atte", "nat", "bat"
    };

    auto ret = S{}.groupAnagrams(v);

    for( auto &c : ret ){
        cout<<"----"<<endl;
        for( std::string &s : c ){
            cout<<s<<",  ";
        }cout<<endl;
    }


    
    debug::log( "\n~~~~ leet: 49 :end ~~~~\n" );
}
}//~
