/*
 * ====================== leet_1180.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1180. 统计只含单一字母的子串
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1180 {//~


// 100%, 100%
class S{
public:
    int countLetters( std::string S ){

        std::vector<int> v {};
        char lastC {0};
        int maxLen = 0;
        for( char c : S ){ 
            if( lastC == 0 ){// fst time
                lastC = c;
                maxLen = 1;
                v.push_back(1);
            }else{
                if( lastC == c ){
                    v.back()++;// add
                }else{
                    maxLen = std::max(maxLen, v.back());
                    v.push_back(1);// new
                }
                lastC = c;
            }
        }
        maxLen = std::max(maxLen, v.back());

        std::vector<int> nums (maxLen+1, 0);
        for( int i=1; i<=maxLen; i++  ){
            nums.at(i) = nums.at(i-1) + i;
        }
 
        int sum = 0;
        for( int i : v ){
            sum += nums.at(i);
        }
        return sum;
    }
};




//=========================================================//
void main_(){

    cout<< S{}.countLetters( "aaaba" )<<endl;
    //cout<< S{}.countLetters( "a" )<<endl;
    //cout<< S{}.countLetters( "aaaaaaaaaa" )<<endl;

    
    debug::log( "\n~~~~ leet: 1180 :end ~~~~\n" );
}
}//~
