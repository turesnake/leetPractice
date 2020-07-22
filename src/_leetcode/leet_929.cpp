/*
 * ====================== leet_929.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 929. 独特的电子邮件地址
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_929 {//~


// 针对每个 字符串，重新生成它的 本地名称，然后拼出完整的 邮件地址

//   47%   66%
class S{
public:
    // 1 <= emails[i].length <= 100
    // 1 <= emails.length <= 100
    // 每封 emails[i] 都包含有且仅有一个 '@' 字符
    int numUniqueEmails( std::vector<std::string>& emails ){

        std::unordered_set<std::string> uset {};

        for( const auto &eml : emails ){
            int N = static_cast<int>(eml.size());
            std::string s {};
            int i = 0;
            for(; i<N; i++ ){
                if( eml[i]=='@' ){ break; }
                if( eml[i]=='.' ){ continue; }
                if( eml[i]=='+' ){
                    for(; i<N && eml[i]!='@'; i++ ){}
                    break;
                }
                s.push_back( eml[i] );
            }
            s.append( eml, i, N-i );
            uset.insert( s );
        }
        return uset.size();


    }
};



//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 929 :end ~~~~\n" );
}
}//~
