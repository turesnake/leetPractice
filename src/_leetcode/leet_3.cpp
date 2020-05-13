/*
 * ====================== leet_3.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 无重复字符的最长子串 
 */
#include "innLeet.h"


namespace leet_3 {//~






int lengthOfLongestSubstring( std::string s ) {

    if( s.empty() ){ return 0; }
    if( s.size() == 1 ){ return 1; }
 
    std::unordered_set<char> chars {};

    size_t maxLen = 0;

    auto endP = s.cend();
    auto tail = s.cbegin();
    auto head = tail;

    while( tail != endP ){

        while(true){

            if( head == endP ){
                maxLen = std::max( maxLen, chars.size() );
                return static_cast<int>(maxLen); // return 
            }

            if( chars.count(*head) != 0 ){
                maxLen = std::max( maxLen, chars.size() );
                break;
            }

            chars.insert( *head );
            head++;
        }

        while( tail < head ){

            if( *tail == *head ){
                tail++;
                break;
            }else{
                chars.erase( *tail );
                tail++;
            }
        }
        
        //-----//
        head++;
    }

    return static_cast<int>(maxLen); // return 
}




// 排名最快的算法 
/*
int lengthOfLongestSubstring2( std::string s ){
        
    std::vector<int> dict(256, -1);             //定义一个vector叫做dict，内容是256个-1
    int maxLen = 0;
    int start  = -1;            //标尺start   

    for (int i = 0; i != s.length(); i++) {
        if (dict[s[i]] > start){            //如果字符串中的字符大于标尺
            start = dict[s[i]];            //那么标尺刷新；
        }
        dict[s[i]] = i;                    //把dict中对应的值改为i（最后应该是0123456...）
        maxLen = std::max(maxLen, i - start);   //max记为最大的i-标尺
    }
    return maxLen;
}
*/


// 8ms
/*
int lengthOfLongestSubstring( std::string s ) {
        
        if(s.size()<=0) return 0;
        if(s.size()<=1) return 1;

        int count[256] = {0};

        int i = 0, j = 0;
        int res = 0;
        while( i<s.size() && j<s.size() ){
            while( j < s.size() ){
                if( count[s[j]]==0 ){
                    count[s[j]]  += 1;
                    j ++;
                }else{
                    res = std::max(res, j - i);
                    while( i<j && count[s[j]]>0 ){
                        count[s[i]] -= 1;
                        i ++;
                    }

                }
            }
        }
        res = std::max(res, j - i);
        return res;
}
*/







void print_out( const std::string &s_ ){
    cout << s_ << " length: " << lengthOfLongestSubstring(s_) << endl;
}




//=========================================================//
void main_(){

    print_out( "" );
    print_out( "a" );
    print_out( "aa" );
    print_out( "abc" );
    print_out( "abcabcbb" );
    print_out( "abcabcda" );
    print_out( "bbbbb" );
    print_out( "pwwkew" );


    debug::log( "\n~~~~ leet :end ~~~~\n" );
}
}//~
