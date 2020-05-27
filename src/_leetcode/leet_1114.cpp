/*
 * ====================== leet_1114.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1114. 按序打印
 */
#include "innLeet.h"

#include <mutex>
#include <shared_mutex>



namespace leet_1114 {//~




class Foo {
    std::mutex m2;
    std::mutex m3;
public:
    Foo(){
        m2.lock();
        m3.lock();
    }

    void first( std::function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m2.unlock();
    }

    void second( std::function<void()> printSecond) {
        m2.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m3.unlock();
    }

    void third( std::function<void()> printThird) {
        m3.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};









//=========================================================//
void main_(){


    

    debug::log( "\n~~~~ leet: 1114 :end ~~~~\n" );
}
}//~
