/*
 * ====================== leet_349.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 349. 两个数组的交集
 */
#include "innLeet.h"


namespace leet_349 {//~


// 暴力法，将小数组 存入 set，然后检测 大数组元素
std::vector<int> intersection_1( std::vector<int>& nums1, std::vector<int>& nums2 ){

    std::unordered_set<int> outst {};
    std::unordered_set<int> st {};
    for( const int i : nums1 ){
        st.insert( i ); // maybe
    }
    for( const int i : nums2 ){
        if( st.find(i) != st.end() ){
            outst.insert( i ); // maybe
        }
    }
    std::vector<int> v {};
    for( const int i : outst ){
        v.push_back( i);
    }
    return v;
}


// 在 版本1 的基础上适当优化
// std::set 的初始化，可以用 vector 的迭代器
// 还使用了特殊的 查重技巧
std::vector<int> intersection_2( std::vector<int>& nums1, std::vector<int>& nums2 ){

    std::unordered_set<int> st ( nums1.begin(), nums1.end() );
    std::vector<int> v {};
    for( const int i : nums2 ){
        if( st.erase(i) ){ 
            // 只有在 st 和 nums2 中都有此元素时，才会返回 true，
            // 之后再删除重复元素，set 中已经没有了，会返回false
           v.push_back( i );
        }
    }
    return v;
}





//=========================================================//
void main_(){

    std::vector<int> v1 { 4,5,9 };
    std::vector<int> v2 { 9,4,9,8,4 };

    auto ret = intersection_2( v1, v2 );
    for( auto i : ret ){
        cout << i << ", ";
    }
    cout << endl;



    debug::log( "\n~~~~ leet: 349 :end ~~~~\n" );
}
}//~
