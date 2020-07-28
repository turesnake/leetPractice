/*
 * ====================== leet_j45.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 45. 把数组排成最小的数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_j45 {//~


// 本质是 实现对 字符串 的一种排序
// 针对字符串 a,b
// 用两个指针 遍历它的字符，谁找到更小的字符，谁就更小
// 当字符串不等长时，让 指针从头循环（可以循环无限次，直到找到一个 不相等的字符为止）
// 当两个指针，同时指向 字符串末尾时，比较才结束

// 在某种极端情况下，这可能会导致 很低效的循环，
// 比如，比较 "11111", "111111"
// 时，要循环很多次 才会到达尾部
// 这点损失 暂时不管


//  99%  100%
class S{

struct Less{
    // ab 非 空
    bool operator()( const std::string &s1, const std::string &s2 ){
        int N1 = static_cast<int>(s1.size());
        int N2 = static_cast<int>(s2.size());
        int i=0;
        int j=0;
        for(;;){
            if( s1[i]>s2[j] ){
                return false;
            }else if( s1[i]<s2[j] ){
                return true;
            }
            //---//
            if( i==N1-1 && j==N2-1 ){ break; }// 两字符串相同
            i==N1-1 ? i=0 : i++;
            j==N2-1 ? j=0 : j++;
        }
        return false;
    }
};


public:
    // nums 非负整数数组
    std::string minNumber( std::vector<int>& nums ){

        std::vector<std::string> strs {};
        for( int i : nums ){
            strs.push_back( std::to_string(i) );
        }
        std::sort( strs.begin(), strs.end(), Less{} );
        //for( auto &s : strs ){ cout<<":"<<s<<endl; }
        std::string ans {};
        for( const auto &s : strs ){
            ans += s;
        }
        return ans;

    }
};






//=========================================================//
void main_(){

    std::vector<int> v {
        123,
        12312
    };

    auto ret = S{}.minNumber(v);

    cout<<"ret:"<<ret<<endl;





    
    debug::log( "\n~~~~ leet: j45 :end ~~~~\n" );
}
}//~
