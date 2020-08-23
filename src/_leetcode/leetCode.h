/*
 * ======================== leetCode.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.01.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#ifndef TPR_LEET_CODE_H
#define TPR_LEET_CODE_H

#include "pch.h"


/* 惯用技巧：
 * -----
 * <limits.h>
 * INT_MIN = -2147483648
 * INT_MAX =  2147483647
 * LONG_MIN
 * LONG_MAX
 * -----
 * <cfloat>
 * DBL_MIN
 * DBL_MAX
 * 
 * -----
 * 字符串转 int
 * int val = std::stoi("-123");
 * 
 * -----
 * int 转 string: std::to_string()
 * 
 * -----
 * 当对 doule->string 且 小数点后N位 有要求时，
 * 请参考 m17_26 题的实现
 * 
 * -----
 * 容器可以直接用 一对迭代器来初始化
 * 
 * -----
 * 判断奇偶性，(1)取模：val%2 (2)判断末尾: val&1
 * 
 * -----
 * std::string a;
 * std::string b;
 * int ret = a.compare(b);
 *    比较 a，b 的字典序
 *    如果 a，b 相同，返回0
 *    如果 a 小于 b， 返回 一个负值，大小为字典序差值
 *    如果 a 大于 b， 返回 一个正值，大小为字典序差值
 * 
 * -----
 * a^1  异或1
 *     举例：
 *        (-4)^1 = -3
 *        (-3)^1 = -4
 *        0^1 = 1
 *        1^1 = 0
 *        2^1 = 3
 *        3^1 = 2
 *  若 a 为偶数，结果为 a+1
 *  若 a 为奇数，结果为 a-1
 *  不管 a 是正数负数还是0，都成立
 * 
 * -----
 * 消除成对的元素方法[1]
 *     if( set.erase(i)==0 ){ set.insert( i ); }
 * 消除成对的元素方法[2]
 *     异或运算 a^b^b = a
 *     可以将一整组数据都 异或起来，最后成对的元素都会被自动 对消掉
 * 
 * -----
 * double pow( int base, int exponent );
 *     计算 base 的 exponent 次方
 *  
 * -----
 * double log10(int v);   <cmath>
 *     库函数，计算 数字的 位数: (int)log10(v)+1
 *     类似的还有 log2
 * 
 * -----
 * std::reverse( v.begin(), v.end() );
 *     将 vector 颠倒
 * 
 * -----
 * it std::unique( fstIt, endIt );
 *     将 vector 中所有 “当前重复的元素” ，排到队尾，然后返回指向 重复元素区首元素的 it
 *     注意，这里的 去重，只去除 相邻的，如果整个数组含有 3个4，但都不相邻，则无法去除
 *     2，排到队尾并不是真的 排到队尾，队尾区间的 元素，可能只是 尾部元素的 重复。
 *     这个算法，时间 O(N), 实现很鸡贼
 *     ---
 *     可以利用这个函数来 高效去除 重复元素：
 *     -- std::sort( v.begin(), v.end() );
 *     -- v.erase( std::unique(v.begin(),v.end()), v.end() );
 * 
 * 
 * -----
 * it std::lower_bound( fstIt, endIt, tgtVal );
 * it std::upper_bound( fstIt, endIt, tgtVal );
 *     二分查找 目标值，返回 左/右 边界值 it，没有的话 返回 endIt
 * bool std::binary_search( fstIt, endIt, tgtVal );
 *     二分查找 目标值
 * 
 * -----
 * std::sort( fstIt,lstIt, Comp{} )
 *     此处第三参数，自定义的 比较对象，必须是 '<' 操作的，不能写 '<=' 操作的，会引发错误
 *  
 * 
 * =============== 需要周期性复习的 算法 =================
 * -- 马拉车算法： 字符串，最长回文子串               --- done
 * -- KMP算法：   两字符串，最大重复子串
 * -- 匈牙利算法： 无向图，二分图，搜索最大匹配个数（难）   
 * -- 线段树：（未学习）
 * -- 前缀树，后缀树（未学习）
 * -- 图：拓扑排序
 * -- 图：最短路径：Dijkstra 
 * -- 图：ff / ek / Dinic 算法， 最大流最小割算法
 * 
 * 
 * =============== 需要复习的内容 =================
 * -- 4:   二分折半删除法
 * -- 5:   回文 - 中心扩散法, manacher
 * -- 15:  三数之和，很麻烦...
 * -- 30:  hash，字符串题，思路不常见
 * -- 41:  原地hash 法
 * -- 69:  求平方根: 二分查找，牛顿法
 * -- 94:  二叉树中序遍历的 迭代实现
 * -- 160: 双指针轮回遍历链表法
 * -- 169: Boyer-Moore Algorithm 多数投票算法
 * -- 238: 前缀积分，后缀积
 * -- 261: 以图判树
 * -- 328: 双链表收集元素，最后合并链表
 * -- 445: 双栈，反向组装链表节点
 * -- 459: 字符串重复子串
 * -- 448: 基于下标 交换元素法
 * -- 632: 非常特殊的 滑动窗口 题
 * -- 974: 前缀和+模 计算区间和是否被整除 
 * -- 922: 特殊的双指针：奇偶指针
 * -- 942: 很有趣的 双指针 收缩空间法
 * -- 1044: Rabin-Karp，后缀数组
 * -- m17_19: 异或，求和，元素交换
 * -- m22: 双指针 固定间距法
 * -- m64: -1- 借助 逻辑运算符的短路特性，实现条件判断。-2- 快速乘
 * -- m08_05: 俄国农民乘法
 * -- m59_1: 单调队列
 * 
 * 
 * =============== 二分查找 =================
 * -1- 明确每次细分，需要剔除的是那一部分元素
 *     含糊的元素，则要保留到下一回合，继续检查
 * -2- 寻找左边界，还是右边界，要使用不同的 mid 计算法
 *     寻找左侧边界时，mid偏左
 *     寻找右侧边界时，mid偏右
 * ------ 题：
 * - 34:
 * - 35:
 * - 278:
 * - 1351:
 * - j11:  很特殊的 二分查找
 * 
 * =============== dp =================
 * 有些 dp 题思路比较奇特，记录于此
 * ------ 题：
 * - 32:  括号区间题  一维dp
 * - 221: 正方形判定
 * - 276: 栏杆题，新类型
 * - 322: 背包dp  一维dp
 * - 718: 
 * - m17_09: 本质上也是 dp 题，很特殊
 *    
 * =============== 单调栈 =================
 * stk内元素一定是有序的，递增或递减
 * 每次处理新元素，将其对比与 stk.top()
 * 分别针对 大于小于等于，进行三种方式的处理
 * 彻底遍历完所有元素后，再将栈内剩余元素，做一层处理
 * 
 * =============== 双向遍历法 =================
 * 
 * =============== 并查集 =================
 * - [0]空置，[i]=i; 初始值指向自己，这样，每个元素互不联通
 * - find(a) 时，顺带执行 路径压缩，让 a 指向 root，加速后面的查找
 * - merge 操作时，改写的是 rootA 或 rootB
 * 
 * ------ 题：
 * - 990: 未完成
 * 
 * =============== 前缀和/积 =================
 * 并不容易想到的方法
 * 
 * =============== 环 =================
 * 所有的环题都需要重视
 * 
 * ============== 需要学习更多解法的题目 ===============
 * - 76: 滑动窗口
 * 
 */


namespace leet_1 { void main_(); }

namespace leet_3 { void main_(); }
namespace leet_4 { void main_(); }
namespace leet_5 { void main_(); }
namespace leet_6 { void main_(); }
namespace leet_7 { void main_(); }
namespace leet_8 { void main_(); }
namespace leet_9 { void main_(); }// 回文数，待新方案：8.02%, 5.95% 
namespace leet_10 { void main_(); }
namespace leet_11 { void main_(); }

namespace leet_13 { void main_(); }
namespace leet_14 { void main_(); }
namespace leet_15 { void main_(); }
namespace leet_16 { void main_(); }
namespace leet_17 { void main_(); }
namespace leet_18 { void main_(); }


namespace leet_20 { void main_(); }
namespace leet_21 { void main_(); }
namespace leet_22 { void main_(); }// 回溯
namespace leet_23 { void main_(); }
namespace leet_24 { void main_(); }

namespace leet_26 { void main_(); }
namespace leet_27 { void main_(); }
namespace leet_28 { void main_(); }// kmp 

namespace leet_30 { void main_(); }
namespace leet_31 { void main_(); }// 巧
namespace leet_32 { void main_(); }
namespace leet_33 { void main_(); }// 二分查找 
namespace leet_34 { void main_(); }
namespace leet_35 { void main_(); }// 二分查找 

namespace leet_38 { void main_(); }
namespace leet_39 { void main_(); }
namespace leet_40 { void main_(); }
namespace leet_41 { void main_(); }
namespace leet_42 { void main_(); }
namespace leet_43 { void main_(); }// 19.69% 40.74%
namespace leet_44 { void main_(); }
namespace leet_46 { void main_(); }
namespace leet_47 { void main_(); }
namespace leet_48 { void main_(); }// 矩阵
namespace leet_49 { void main_(); }

namespace leet_53 { void main_(); }// dp
namespace leet_54 { void main_(); }
namespace leet_56 { void main_(); }
namespace leet_57 { void main_(); }
namespace leet_58 { void main_(); }//...无脑...

namespace leet_60 { void main_(); }
namespace leet_62 { void main_(); }// dp 基础
namespace leet_63 { void main_(); }// dp
namespace leet_64 { void main_(); }// dp

namespace leet_66 { void main_(); }//...无脑...
namespace leet_67 { void main_(); }

namespace leet_69 { void main_(); }
namespace leet_70 { void main_(); }// dp
namespace leet_72 { void main_(); }
namespace leet_73 { void main_(); }
namespace leet_74 { void main_(); }
namespace leet_75 { void main_(); }
namespace leet_76 { void main_(); }
namespace leet_77 { void main_(); }// dfs + 回溯

namespace leet_78 { void main_(); }
namespace leet_79 { void main_(); }

namespace leet_83 { void main_(); }
namespace leet_84 { void main_(); }// 单调栈
namespace leet_85 { void main_(); }// 单调栈 基于84的升级版

namespace leet_86 { void main_(); }
namespace leet_88 { void main_(); }
namespace leet_89 { void main_(); }

namespace leet_92 { void main_(); }
namespace leet_94 { void main_(); }
namespace leet_95 { void main_(); }// dp
namespace leet_96 { void main_(); }// dp
namespace leet_97 { void main_(); }

namespace leet_98 { void main_(); }

namespace leet_100 { void main_(); }
namespace leet_101 { void main_(); }
namespace leet_102 { void main_(); }

namespace leet_104 { void main_(); }
namespace leet_105 { void main_(); }
namespace leet_106 { void main_(); }
namespace leet_107 { void main_(); }
namespace leet_108 { void main_(); }
namespace leet_109 { void main_(); }
namespace leet_110 { void main_(); }
namespace leet_111 { void main_(); }
namespace leet_112 { void main_(); }

namespace leet_116 { void main_(); }

namespace leet_120 { void main_(); }// dp
namespace leet_121 { void main_(); }
namespace leet_122 { void main_(); }// dp

namespace leet_124 { void main_(); }
namespace leet_125 { void main_(); }

namespace leet_128 { void main_(); }
namespace leet_129 { void main_(); }
namespace leet_130 { void main_(); }// bfs
namespace leet_131 { void main_(); }// dp记忆化 + dfs + 回溯 -- 简陋的缝合怪
namespace leet_132 { void main_(); }
namespace leet_136 { void main_(); }// 异或消除成对元素
namespace leet_137 { void main_(); }// 异或
namespace leet_138 { void main_(); }
namespace leet_139 { void main_(); }

namespace leet_141 { void main_(); }
namespace leet_142 { void main_(); }// 环
namespace leet_143 { void main_(); }
namespace leet_144 { void main_(); }
namespace leet_145 { void main_(); }
namespace leet_146 { void main_(); }

namespace leet_148 { void main_(); }

namespace leet_152 { void main_(); }
namespace leet_153 { void main_(); }
namespace leet_154 { void main_(); }
namespace leet_155 { void main_(); }

namespace leet_160 { void main_(); }

namespace leet_164 { void main_(); }
namespace leet_167 { void main_(); }
namespace leet_168 { void main_(); }
namespace leet_169 { void main_(); }// Boyer-Moore Algorithm 多数投票算法


namespace leet_172 { void main_(); }
namespace leet_173 { void main_(); }

namespace leet_189 { void main_(); }
namespace leet_190 { void main_(); }
namespace leet_191 { void main_(); }//...无脑...

namespace leet_198 { void main_(); }// dp
namespace leet_200 { void main_(); }
namespace leet_201 { void main_(); }
namespace leet_202 { void main_(); }
namespace leet_203 { void main_(); }
namespace leet_204 { void main_(); }// 18.16%，84.62%

namespace leet_206 { void main_(); }

namespace leet_208 { void main_(); }
namespace leet_209 { void main_(); }

namespace leet_213 { void main_(); }
namespace leet_214 { void main_(); }
namespace leet_215 { void main_(); }
namespace leet_216 { void main_(); }
namespace leet_217 { void main_(); }

namespace leet_221 { void main_(); }
namespace leet_222 { void main_(); }
namespace leet_225 { void main_(); }//...无脑...
namespace leet_226 { void main_(); }

namespace leet_230 { void main_(); }
namespace leet_231 { void main_(); }//...无脑...
namespace leet_232 { void main_(); }

namespace leet_234 { void main_(); }
namespace leet_235 { void main_(); }
namespace leet_236 { void main_(); }
namespace leet_237 { void main_(); }
namespace leet_238 { void main_(); }
namespace leet_239 { void main_(); }

namespace leet_243 { void main_(); }
namespace leet_244 { void main_(); }
namespace leet_245 { void main_(); }
namespace leet_246 { void main_(); }
namespace leet_247 { void main_(); }

namespace leet_252 { void main_(); }// 区间
namespace leet_253 { void main_(); }// 区间

namespace leet_256 { void main_(); }// dp
namespace leet_257 { void main_(); }
namespace leet_258 { void main_(); }
namespace leet_259 { void main_(); }
namespace leet_260 { void main_(); }// 位运算，异或 + lowbit
namespace leet_261 { void main_(); }// 以图判树，查找连通分量个数，无向图是否有环，并查集

namespace leet_263 { void main_(); }
namespace leet_264 { void main_(); }

namespace leet_266 { void main_(); }
namespace leet_267 { void main_(); }
namespace leet_269 { void main_(); }

namespace leet_270 { void main_(); }

namespace leet_276 { void main_(); }// dp
namespace leet_278 { void main_(); }
namespace leet_279 { void main_(); }// bfs

namespace leet_281 { void main_(); }
namespace leet_283 { void main_(); }

namespace leet_285 { void main_(); }
namespace leet_287 { void main_(); }// 环

namespace leet_292 { void main_(); }
namespace leet_293 { void main_(); }//...无脑...
namespace leet_295 { void main_(); }// 最大堆+最小堆 求中位数
namespace leet_297 { void main_(); }
namespace leet_298 { void main_(); }

namespace leet_300 { void main_(); }// **难**
namespace leet_303 { void main_(); }// 树状数组
namespace leet_307 { void main_(); }// 树状数组
namespace leet_309 { void main_(); }// dp
namespace leet_310 { void main_(); }// 图 -> 最小高度树

namespace leet_312 { void main_(); }// dp hard
namespace leet_314 { void main_(); }
namespace leet_315 { void main_(); }

namespace leet_322 { void main_(); }// 背包 dp
namespace leet_323 { void main_(); }// 图，连通分量， 并查集

namespace leet_326 { void main_(); }//...无脑...
namespace leet_328 { void main_(); }
namespace leet_329 { void main_(); }

namespace leet_337 { void main_(); }
namespace leet_338 { void main_(); }// 临时方案，等待更正式的方案
namespace leet_339 { void main_(); }// 图，带权 并查集

namespace leet_342 { void main_(); }// 二进制/位运算
namespace leet_343 { void main_(); }// dp
namespace leet_344 { void main_(); }//...无脑...
namespace leet_346 { void main_(); }
namespace leet_347 { void main_(); }
namespace leet_349 { void main_(); }
namespace leet_350 { void main_(); }

namespace leet_357 { void main_(); }

namespace leet_378 { void main_(); }// 有序矩阵，左下角遍历法(2): 统计 <=tgt 元素个数

namespace leet_363 { void main_(); }

namespace leet_368 { void main_(); }//  有趣
namespace leet_369 { void main_(); }//...无脑...

namespace leet_371 { void main_(); }

namespace leet_374 { void main_(); }// 奇怪，与本机运行不一致...
namespace leet_375 { void main_(); }// dp **难**

namespace leet_392 { void main_(); }
namespace leet_394 { void main_(); }

namespace leet_400 { void main_(); }
namespace leet_401 { void main_(); }
namespace leet_402 { void main_(); }
namespace leet_406 { void main_(); }// 贪心算法
namespace leet_407 { void main_(); }
namespace leet_409 { void main_(); }
namespace leet_410 { void main_(); }

namespace leet_413 { void main_(); }// dp
namespace leet_414 { void main_(); }
namespace leet_415 { void main_(); }

namespace leet_421 { void main_(); }

namespace leet_429 { void main_(); }

namespace leet_437 { void main_(); }// 前缀和

namespace leet_444 { void main_(); }
namespace leet_445 { void main_(); }
namespace leet_448 { void main_(); }
namespace leet_449 { void main_(); }

namespace leet_451 { void main_(); }
namespace leet_452 { void main_(); }
namespace leet_455 { void main_(); }


namespace leet_461 { void main_(); }//...无脑...
namespace leet_464 { void main_(); }

namespace leet_474 { void main_(); }

namespace leet_486 { void main_(); }// dp 100%  100%

namespace leet_494 { void main_(); }
namespace leet_496 { void main_(); }// 单调栈

namespace leet_500 { void main_(); }//...无脑...
namespace leet_504 { void main_(); }
namespace leet_509 { void main_(); }

namespace leet_513 { void main_(); }
namespace leet_515 { void main_(); }// 27%, 25%

namespace leet_516 { void main_(); }// dp 5.34% 75% 

namespace leet_520 { void main_(); }//...无脑...
namespace leet_521 { void main_(); }//...无脑...
namespace leet_523 { void main_(); }// 前缀和

namespace leet_530 { void main_(); }

namespace leet_538 { void main_(); }// 倒置的 中序遍历 26% 7%

namespace leet_540 { void main_(); }

namespace leet_543 { void main_(); }
namespace leet_546 { void main_(); }
namespace leet_547 { void main_(); }// 并查集

namespace leet_557 { void main_(); }
namespace leet_559 { void main_(); }
namespace leet_560 { void main_(); }// 前缀和/积

namespace leet_563 { void main_(); }

namespace leet_572 { void main_(); }

namespace leet_581 { void main_(); }// 双向遍历法， 单调栈

namespace leet_589 { void main_(); }
namespace leet_590 { void main_(); }

namespace leet_598 { void main_(); }
namespace leet_600 { void main_(); }

namespace leet_605 { void main_(); }

namespace leet_617 { void main_(); }

namespace leet_628 { void main_(); }
namespace leet_629 { void main_(); }

namespace leet_632 { void main_(); }
namespace leet_633 { void main_(); }
namespace leet_637 { void main_(); }
namespace leet_638 { void main_(); }// dp

namespace leet_646 { void main_(); }// dp
namespace leet_647 { void main_(); }// dp // 27% 78%
namespace leet_648 { void main_(); }// 字典树

namespace leet_652 { void main_(); }// 序列化 5%
namespace leet_653 { void main_(); }
namespace leet_654 { void main_(); }// 5.13%, 7.69%

namespace leet_657 { void main_(); }//...无脑...

namespace leet_663 { void main_(); }

namespace leet_671 { void main_(); }
namespace leet_673 { void main_(); }

namespace leet_677 { void main_(); }// 字典树

namespace leet_680 { void main_(); }

namespace leet_684 { void main_(); }// 并查集
namespace leet_685 { void main_(); }// 并查集 很有挑战
namespace leet_687 { void main_(); }

namespace leet_696 { void main_(); }
namespace leet_698 { void main_(); }

namespace leet_701 { void main_(); }
namespace leet_702 { void main_(); }
namespace leet_704 { void main_(); }
namespace leet_709 { void main_(); }//...无脑...

namespace leet_712 { void main_(); }// dp 5.28%  55.56%
namespace leet_713 { void main_(); }
namespace leet_714 { void main_(); }// dp

namespace leet_716 { void main_(); }
namespace leet_718 { void main_(); }

namespace leet_720 { void main_(); }// 字典树
namespace leet_721 { void main_(); }// 并查集

namespace leet_724 { void main_(); }

namespace leet_727 { void main_(); }// 9%
namespace leet_728 { void main_(); }

namespace leet_739 { void main_(); }// 单调栈
namespace leet_740 { void main_(); }
namespace leet_743 { void main_(); }// Dijkstra

namespace leet_746 { void main_(); }// dp


namespace leet_760 { void main_(); }//...无脑...
namespace leet_763 { void main_(); }
namespace leet_765 { void main_(); }// 并查集
namespace leet_766 { void main_(); }// 矩阵


namespace leet_771 { void main_(); }//...无脑...

namespace leet_783 { void main_(); }
namespace leet_784 { void main_(); }

namespace leet_785 { void main_(); }// 二分图判断，并查集 活用
namespace leet_787 { void main_(); }

namespace leet_802 { void main_(); }
namespace leet_804 { void main_(); }
namespace leet_809 { void main_(); }

namespace leet_814 { void main_(); }

namespace leet_821 { void main_(); }

namespace leet_832 { void main_(); }//...无脑...

namespace leet_836 { void main_(); }//...无脑...
namespace leet_841 { void main_(); }

namespace leet_862 { void main_(); }

namespace leet_876 { void main_(); }

namespace leet_886 { void main_(); }// 并查集
namespace leet_889 { void main_(); }

namespace leet_892 { void main_(); }
namespace leet_897 { void main_(); }

namespace leet_901 { void main_(); }// 单调栈
namespace leet_902 { void main_(); }// 难

namespace leet_905 { void main_(); }
namespace leet_908 { void main_(); }
namespace leet_910 { void main_(); }// 贪心
namespace leet_912 { void main_(); }// sorts

namespace leet_922 { void main_(); }// 双指针：奇偶指针
namespace leet_929 { void main_(); }

namespace leet_931 { void main_(); }// dp

namespace leet_938 { void main_(); }

namespace leet_941 { void main_(); }
namespace leet_942 { void main_(); }// 有趣
namespace leet_945 { void main_(); }

namespace leet_949 { void main_(); }

namespace leet_959 { void main_(); }// 有趣  并查集 变种

namespace leet_974 { void main_(); }
namespace leet_876 { void main_(); }
namespace leet_977 { void main_(); }

namespace leet_980 { void main_(); }
namespace leet_983 { void main_(); }

namespace leet_989 { void main_(); }
namespace leet_990 { void main_(); }

namespace leet_997 { void main_(); }// 图
namespace leet_998 { void main_(); }

namespace leet_1002 { void main_(); }

namespace leet_1013 { void main_(); }

namespace leet_1022 { void main_(); }
namespace leet_1025 { void main_(); }// dp
namespace leet_1042 { void main_(); }// 图
namespace leet_1044 { void main_(); }// 字符串， Rabin-Karp， 后缀数组
namespace leet_1047 { void main_(); }
namespace leet_1055 { void main_(); }
namespace leet_1062 { void main_(); }
namespace leet_1063 { void main_(); }
namespace leet_1064 { void main_(); }// 17.22%  33.33% 未来精进
namespace leet_1065 { void main_(); }// 字典树
namespace leet_1071 { void main_(); }

namespace leet_1085 { void main_(); }//...无脑...
namespace leet_1089 { void main_(); }

namespace leet_1099 { void main_(); }

namespace leet_1100 { void main_(); }
namespace leet_1102 { void main_(); }// dijkstra
namespace leet_1104 { void main_(); }

namespace leet_1108 { void main_(); }//...无脑...

namespace leet_1111 { void main_(); }
namespace leet_1114 { void main_(); }// threads
namespace leet_1119 { void main_(); }//...无脑...

namespace leet_1121 { void main_(); }

namespace leet_1129 { void main_(); }// 图， 最小限度的 环 (而不是彻底屏蔽环)
namespace leet_1130 { void main_(); }// dp 29.51%, 50%
namespace leet_1133 { void main_(); }
namespace leet_1134 { void main_(); }//...无脑...
namespace leet_1135 { void main_(); }// 图 最小生成树

namespace leet_1136 { void main_(); }// 拓扑排序
namespace leet_1139 { void main_(); }

namespace leet_1143 { void main_(); }// dp 8.93%, 100%
namespace leet_1147 { void main_(); }

namespace leet_1150 { void main_(); }

namespace leet_1156 { void main_(); }

namespace leet_1160 { void main_(); }// 5.15% 20%
namespace leet_1162 { void main_(); }

namespace leet_1165 { void main_(); }//...无脑...
namespace leet_1168 { void main_(); }// 最小生成树 小顶堆 并查集 kruskal

namespace leet_1180 { void main_(); }//...无脑...

namespace leet_1198 { void main_(); }

namespace leet_1207 { void main_(); }//...无脑...

namespace leet_1214 { void main_(); }

namespace leet_1227 { void main_(); }
namespace leet_1228 { void main_(); }//...无脑...

namespace leet_1240 { void main_(); }// dp

namespace leet_1246 { void main_(); }// dp hard

namespace leet_1252 { void main_(); }
namespace leet_1255 { void main_(); }

namespace leet_1259 { void main_(); }

namespace leet_1265 { void main_(); }//...无脑...

namespace leet_1277 { void main_(); }// dp 5.07%， 50%
namespace leet_1278 { void main_(); }

namespace leet_1281 { void main_(); }//...无脑...

namespace leet_1284 { void main_(); }

namespace leet_1287 { void main_(); }

namespace leet_1289 { void main_(); }// dp
namespace leet_1290 { void main_(); }


namespace leet_1299 { void main_(); }//...无脑...
namespace leet_1300 { void main_(); }
namespace leet_1302 { void main_(); }
namespace leet_1304 { void main_(); }//...无脑...
namespace leet_1305 { void main_(); }
namespace leet_1306 { void main_(); }

namespace leet_1312 { void main_(); }
namespace leet_1313 { void main_(); }//...无脑...
namespace leet_1314 { void main_(); }// dp
namespace leet_1315 { void main_(); }

namespace leet_1323 { void main_(); }//...无脑...
namespace leet_1325 { void main_(); }

namespace leet_1328 { void main_(); }

namespace leet_1332 { void main_(); }
namespace leet_1334 { void main_(); }
namespace leet_1335 { void main_(); }

namespace leet_1342 { void main_(); }

namespace leet_1349 { void main_(); }// 状态压缩dp， 匈牙利， 最大流，ff， dinic
namespace leet_1351 { void main_(); }

namespace leet_1361 { void main_(); }
namespace leet_1365 { void main_(); }

namespace leet_1381 { void main_(); }
namespace leet_1382 { void main_(); }
namespace leet_1387 { void main_(); }

namespace leet_1400 { void main_(); }
namespace leet_1402 { void main_(); }

namespace leet_1431 { void main_(); }//...无脑...

namespace leet_1439 { void main_(); }
namespace leet_1441 { void main_(); }
namespace leet_1450 { void main_(); }
namespace leet_1457 { void main_(); }

namespace leet_1460 { void main_(); }//...无脑...
namespace leet_1464 { void main_(); }

namespace leet_1470 { void main_(); }//...无脑...

namespace leet_1480 { void main_(); }//...无脑...

namespace leet_1492 { void main_(); }
namespace leet_1494 { void main_(); }// 图， 复杂且综合

namespace leet_1502 { void main_(); }

namespace leet_1512 { void main_(); }// 排列组合


namespace leet_j04 { void main_(); }// 有序矩阵，左下角遍历法(1): 查找 tgt元素 是否存在
namespace leet_j10_11 { void main_(); }
namespace leet_j14_1 { void main_(); }
namespace leet_j17 { void main_(); }//...无脑...
namespace leet_j21 { void main_(); }
namespace leet_j38 { void main_(); }
namespace leet_j44 { void main_(); }
namespace leet_j45 { void main_(); }
namespace leet_j49 { void main_(); }
namespace leet_j51 { void main_(); }
namespace leet_j55_11 { void main_(); }
namespace leet_j56_11 { void main_(); }
namespace leet_j60 { void main_(); }
namespace leet_j66 { void main_(); }


namespace leet_LCP_01 { void main_(); }//...无脑...
namespace leet_LCP_04 { void main_(); }// 二分图，匈牙利算法
namespace leet_LCP_06 { void main_(); }//...无脑...

namespace leet_m01_1 { void main_(); }
namespace leet_m01_01 { void main_(); }//...无脑...
namespace leet_m01_04 { void main_(); }//...无脑...
namespace leet_m01_06 { void main_(); }

namespace leet_m02_03 { void main_(); }
namespace leet_m02_06 { void main_(); }
namespace leet_m02_07 { void main_(); }

namespace leet_m03 { void main_(); }
namespace leet_m03_02 { void main_(); }
namespace leet_m03_04 { void main_(); }//...无脑...
namespace leet_m03_05 { void main_(); }

namespace leet_m04_01 { void main_(); }
namespace leet_m04_02 { void main_(); }
namespace leet_m04_03 { void main_(); }
namespace leet_m04_04 { void main_(); }

namespace leet_m05 { void main_(); }//...无脑...
namespace leet_m06 { void main_(); }
namespace leet_m07 { void main_(); }

namespace leet_m08_01 { void main_(); }// dp
namespace leet_m08_03 { void main_(); }// 非常有挑战！
namespace leet_m08_05 { void main_(); }
namespace leet_m08_07 { void main_(); }
namespace leet_m08_09 { void main_(); }
namespace leet_m08_11 { void main_(); }
namespace leet_m08_13 { void main_(); }

namespace leet_m09 { void main_(); }// 用两栈实现队列，...无脑...
namespace leet_m10_01 { void main_(); }
namespace leet_m10_02 { void main_(); }
namespace leet_m10_03 { void main_(); }
namespace leet_m10_09 { void main_(); }
namespace leet_m15 { void main_(); }//...无脑...

namespace leet_m16_01 { void main_(); }
namespace leet_m16_07 { void main_(); }
namespace leet_m16_11 { void main_(); }
namespace leet_m16_16 { void main_(); }
namespace leet_m16_17 { void main_(); }// dp 34.46%，100%


namespace leet_m17_04 { void main_(); }
namespace leet_m17_07 { void main_(); }
namespace leet_m17_09 { void main_(); }// 特殊的 dp 题
namespace leet_m17_10 { void main_(); }
namespace leet_m17_12 { void main_(); }
namespace leet_m17_16 { void main_(); }// dp
namespace leet_m17_17 { void main_(); }// kmp
namespace leet_m17_19 { void main_(); }// 异或，求和，元素交换
namespace leet_m17_24 { void main_(); }
namespace leet_m17_25 { void main_(); }
namespace leet_m17_26 { void main_(); }

namespace leet_m22 { void main_(); }// 双指针固定间距法
namespace leet_m24 { void main_(); }
namespace leet_m25 { void main_(); }
namespace leet_m27 { void main_(); }
namespace leet_m28 { void main_(); }
namespace leet_m29 { void main_(); }
namespace leet_m32_1 { void main_(); }
namespace leet_m32_2 { void main_(); }
namespace leet_m37 { void main_(); }
namespace leet_m39 { void main_(); }
namespace leet_m40 { void main_(); }
namespace leet_m42 { void main_(); }// dp
namespace leet_m46 { void main_(); }
namespace leet_m47 { void main_(); }// dp
namespace leet_m50 { void main_(); }//...无脑...
namespace leet_m53 { void main_(); }// 二分查找
namespace leet_m53_1 { void main_(); }
namespace leet_m55_1 { void main_(); }
namespace leet_m56_1 { void main_(); }
namespace leet_m57 { void main_(); }
namespace leet_m57_2 { void main_(); }
namespace leet_m58_1 { void main_(); }//...无脑...
namespace leet_m58_2 { void main_(); }//...无脑...
namespace leet_m59_1 { void main_(); }// 单调队列 [罕见]
namespace leet_m62 { void main_(); }
namespace leet_m63 { void main_(); }
namespace leet_m64 { void main_(); }





namespace leet_test { void main_(); }


// oths:
namespace leet_knapsack_problems { void main_(); }// 背包问题练习


inline void leetCode_mian(){
    debug::log("\n\n============= Leet Code: Begin ================>>\n");


    leet_201::main_();

    //leet_test::main_();


    debug::log("\n============= Leet Code: End ==================<<\n\n");
}


#endif 

