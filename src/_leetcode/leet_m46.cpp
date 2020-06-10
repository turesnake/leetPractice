/*
 * ====================== leet_m46.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题46. 把数字翻译成字符串
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m46 {//~


// 这是一道结构上类似 斐波契纳 的dp 题
// 所以，它也是可以被 递归来实现的 ...

// 而且，因为递归实现，省略了前期的 整理出所有数字的操作
// 反而更快了...



// dp 21%， 100%
// 非常罕见的 一维dp
class S{

    // 可被合并
    bool isMergeable( int l, int r ){
        if(l==0){ return false; }
        return (10*l+r) <= 25;
    }

public:
    // 0 <= num < 231
    int translateNum( int num ){

        if( num<10 ){ return 1; }

        std::deque<int> que {};
        for( int i=num; i>0; i/=10 ){
            que.push_front(i%10);
        }
        std::vector<int> nums ( que.begin(), que.end() );
        int N = static_cast<int>(nums.size());

        std::vector<int> dp (N,0); // 未做空间压缩 
        dp.at(0)=1;
        dp.at(1) = isMergeable(nums.at(0),nums.at(1)) ? 2 : 1;

        for( int i=2; i<N; i++ ){// [i-2],[i-1]
            int l = (isMergeable(nums.at(i-1),nums.at(i)) ? 1 : 0) * dp.at(i-2);
            dp.at(i) = dp.at(i-1) + l;
        }
        //cout<<"dp: "; for( int i : dp ){ cout<<i<<", "; } cout<<endl;
        return dp.back();
    }
};





//=========================================================//
void main_(){

    cout << S{}.translateNum( 12258 )<<endl;


    
    debug::log( "\n~~~~ leet: m46 :end ~~~~\n" );
}
}//~
