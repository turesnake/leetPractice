/*
 * ====================== leet_368.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 368. 最大整除子集
 */
#include "innLeet.h"


namespace leet_368 {//~


// dp

// 一定要排序，这样就只要单向除一次就可以了
// ---
// 集合中所有数 相互符合整除，其实意味着，
// 新加入的那个大值，要被当前集合中 最大值 整除
// ---
// 每当发现无法被 当前最大值整除的 新值。
// 还需要拿 新值 去和 原有集合中每个元素 比较
// 收集所有 不兼容的元素 n个
// 然后分裂成 n 条支线

// 一个重要的 优化规律：
// {1,2,6}  {1,3,6} 这两个集合，可以被优化掉一个（覆盖）
// 因为，6 可以被 2，3 整除 未来添加进来的任何 值，只要能被 6 整除，就也都能被 2，3 整除
// 所以，这两个分支，只需要留一个 

// 本质上这是一颗树

// 反向链表法
// 6->3->1, 暴露在外面的指针，其实存放的是 6 这个尾节点，整个链表倒着指，最优都指向集合中最小的那个元素
// 最后，把所有 链表头（最大值节点） 存储在一个容器中，方便查找遍历
// 其实它们就是 树的叶节点

// 如果 新节点，和所有 leaf 都无法整除，就麻烦了
// 这意味着需要向前一路遍历，直到找到能整除的 元素为止

// 鉴于 不知道，新值的恶劣程度，最好将其 逆向除以 每一个小值（从大到小）
// 上面说的链表，也被组成成 数组的形式，每个值指向自己的 父节点
// 并且标明自己当前的 深度 

// 如果新值可以被 n 个 值整除，那么，它要选其中，deep 最大的那个 作为 父节点

// 鉴于每个值的 deep 是静态的，应该被存入一个 map，来排序
// 让 新值 优先除 最深的值



//   5%   25%
//  虽然上述思路很巧，但是成绩不理想
//  主要是，每个值的检测，都需要除以各个 旧值
//
//  答案中 高分解 的思路和我们的基本一致，不过在写法上更紧凑
//  而且省去了 mmap 的使用 
class S{
public:
    std::vector<int> largestDivisibleSubset( std::vector<int>& nums ){

        if(nums.empty()){ return {}; }

        std::sort( nums.begin(), nums.end() );
        int N = static_cast<int>(nums.size());

        std::multimap<int,int> mmap {}; // <deep,idx>
        std::vector<int> dp (N, -1); // 自己的父节点，-1表示自己是 root
        // [0]
        dp[0] = -1;
        mmap.emplace(1,0);

        for( int i=1; i<N; i++ ){// [i-1], [i]
            int curVal = nums.at(i);
            bool isFind = false;
            auto rit = mmap.rbegin();
            for( ; rit!=mmap.rend(); rit++ ){
                auto [deep, idx] = *rit;
                if( curVal%nums.at(idx) == 0 ){ // 找到整除数
                    isFind = true;
                    dp[i] = idx; // parent
                    mmap.emplace( deep+1, i );
                    break;
                }
            }
            if( !isFind ){// 和所有元素都不整除，自己做 新root
                dp[i] = -1;
                mmap.emplace( 1, i );
            }
        }

        std::vector<int> outs {};
        int idx = mmap.rbegin()->second;
        for( ; idx>=0; idx=dp.at(idx) ){
            outs.push_back( nums.at(idx) );
        }
        return outs;


    }
};

class Naa{
public:
    Naa()=default;
    Naa(Naa const&) = delete;
    Naa(Naa &&) = delete;
};

Naa make_Naa(){
    return Naa{};
}



//=========================================================//
void main_(){

    std::vector<int> v { 1,2,3,4,5,6,7,8,9 };

    auto ret = S{}.largestDivisibleSubset(v);
    cout<<"ret:"<<endl;
    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;


    cout<<"test-------:"<<endl;

    auto n = make_Naa();



    
    debug::log( "\n~~~~ leet: 368 :end ~~~~\n" );
}
}//~
