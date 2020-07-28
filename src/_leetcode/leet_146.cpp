/*
 * ====================== leet_146.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 146. LRU缓存机制
 */
#include "innLeet.h"


namespace leet_146 {//~



// 难点在于，如何维护 删除队列
// 使用 deque 来记录次序
// 当某个元素被更新后，他在 deque 中的 元素将被保留
// 我们会添加一个 新的元素 到 deque 尾部，
// 每个 deque 元素，都携带一个 count 信息，记载了，本元素被添加之时，目标元素的 count 是多少
// 当需要 从头部删除一个元素时，那些失效的元素就可以被检测出来，直接删除掉


//  75%  92%
class LRUCache{

struct Elem{
    int val   {};
    int count {};
};

struct QElem{
    int key {};
    int count {};
};

    std::unordered_map<int,Elem> umap {};
    std::deque<QElem> que {};
    size_t cap {};


public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if( umap.count(key)==0 ){
            return -1;
        }else{// find
            umap[key].count++;
            que.push_back( QElem{ key, umap[key].count } );
            return umap[key].val;
        }
    }
    

    void put(int key, int value) {

        if( umap.count(key)==0 ){
            umap.emplace( key, Elem{value,0} );
        }else{
            umap[key].val = value;
            umap[key].count++;
        }
        que.push_back( QElem{ key, umap[key].count } );

        if( umap.size() > cap ){
            while( !que.empty() ){
                auto [eKey,eCount] = que.front();
                que.pop_front();
                if( eCount == umap[eKey].count ){// 有效的
                    umap.erase( eKey );
                    break;
                }
            }
        }
    }
};





//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 146 :end ~~~~\n" );
}
}//~
