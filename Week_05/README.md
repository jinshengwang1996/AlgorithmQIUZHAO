# 学习笔记

## 刷题记录

严格按照超哥给出的五毒神掌刷题：以下是自己每天刷题的数目。

**第一周**

周一：

两数之和：4

移动零：4

周二：

加一：4

爬楼梯：4

盛最多水的容器：4

三个数之和：4

周三：

反转链表：4

两两交换链表中的结点：4

移除重复元素：4

周四：

旋转数组：4

合并两个有序数组：4

周五：

合并两个有序链表：4

有效的字母异位词：4



**第二周**

周一：

二叉树的中序遍历：4

二叉树的前序遍历：4

周二：

N叉树的前序遍历：4

N叉树的后序遍历：4

周三：

最小的k个数：4

前k个高频元素：4

周四：

组合：4

N叉树的层序遍历：4

周五：

丑数：4



**第三周**

周一：

多数元素：4

周二：

二叉树的层序遍历：4

周三：

分发饼干：4

搜索二维矩阵：4

周四：

Pow(x, n) ：4

N 皇后：4

周五：

买卖股票的最佳时机：4

寻找旋转排序数组的中的最小值：4



**第四周：**为了深入理解递归的原理，将之前的一些比较经典的题目又做了一遍，或者重新做了一下，不然来不及。课后作业只完成了6道题

递归题解合集：

周一：

翻转二叉树：4

验证二叉搜索树：4

最小路径和：4

周二：

二叉树的最大深度：4

二叉树的最小深度：4

解码方法：4

周三：

任务调度器：4

最大正方形：4

周四：

N叉树的最大深度：4

回文子串：4

周五：

最长有效括号：4





**第五周：**

周一：

爬楼梯：5

比特位计数：3

周二：

朋友圈：3

周三：

括号生成：3

周四：

岛屿数量：3

解数独：3

周五：

单词接龙：3



## 学习总结

### 字典树和并查集

字典树，即trie树，又称单词查找树或键树，是一种树形结构。优点是能够最大限度地减少无谓的字符串比较，查询效率比哈希表高。

**基本性质：**

1. 结点本身不存完整单词；
2. 从根结点到某一结点，路径上经过的字符连接起来，为该结点对应的
   字符串；
3. 每个结点的所有子结点路径代表的字符都不相同。

**核心思想：**

- Trie 树的核心思想是空间换时间。
- 利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。



并查集，适用于组团或配对问题。

**基本操作：**

- makeSet(s)：建立一个新的并查集，其中包含 s 个单元素集合。 
- unionSet(x, y)：把元素 x 和元素 y 所在的集合合并，要求 x 和 y 所在
  的集合不相交，如果相交则不合并。
- find(x)：找到元素 x 所在的集合的代表，该操作也可以用于判断两个元
  素是否位于同一个集合，只要将它们各自的代表比较一下就可以了。

![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200814225113.png)



![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200814225132.png)



### 高级搜索

**剪枝**

**双向BFS**

**启发式搜索**



**初级搜索：**

1. 朴素搜索

2. 优化方向：不重复(fibonacci), 剪枝(生成括号问题)

3. 搜索方向：

   DFS

   BFS

   双向搜索、启发式搜索



剪枝，其实就是将一些逻辑上不可能的分支，利用程序代码进行判断，减少递归的次数。



双向BFS：

![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815104754.png)



![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815104815.png)



![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815104830.png)



启发式搜索：

![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815104918.png)



**估价函数**

启发式函数：h(n), 它用来评价哪些结点最有希望的是一个我们要找的结点，h(n) 会返回一个非负实数，也可以认为是从一个结点n的目标结点路径的估计成本。



启发式函数是一种告知搜索方向的方法，它提供一种明智的方法来猜测哪个邻居结点会导向一个目标。



### 高级树、AVL树和红黑树

对于二叉搜索树，lookup的时间复杂度为O(logN)，为了避免极端情况的出现(类似于链表)，需要保证平衡，而保证平衡的关键就是：

1. 保证二维维度！ --->  左右子树结点平衡
2. balanced



基于以上思考与讨论，就出现了AVL树（只需要记住具体的操作，代码实现可以不用理会）

1. 为什么叫AVL树，因为这是发明者的首字母

2. 平衡因子（balance factor）

   是它的左子树的高度减去它的右子树的高度（有时相反）

   balance factor = {-1，0， 1}

3. 通过旋转操作来平衡（四种）



四种旋转操作：

1. 左旋
2. 右旋
3. 左右旋
4. 右左旋

![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815110503.png)



![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815110543.png)



![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815110627.png)

![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815110650.png)



![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815110715.png)

![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815110723.png)



**带有子树的旋转**

[参考动画](https://zhuanlan.zhihu.com/p/63272157)



**AVL总结：**

1. 平衡二叉搜索树
2. 每个结点存 balance factor = {-1， 0， 1}
3. 四种旋转操作



不足之处：需要额外的空间存储额外的信息、且调整次数频繁



**红黑树**

红黑树，是一种**近似平衡**的二叉搜索树，它能够确保任何一个结点的左右子树的**高度差小于二倍**。具体来说，红黑树是满足如下条件的二叉搜索树：

- 每个结点要么是红色要么是黑色
- 根结点是黑色
- 每个叶结点（NIL结点，空结点）是黑色的
- 不能有相邻接的两个红色结点
- 从任一结点到其每个叶子的所有路径都包含相同数目的黑色结点

![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815111539.png)



关键点：从根到叶子的最长的可能路径不多于最短的可能路径的两倍长。



对比严格平衡树：

- A V L trees provide faster lookups than Red Black Trees because they are m o re strictly 
  balanced.
- Red Black Trees provide faster insertion and removal operations than A V L trees as 
  fewer rotations are done due to relatively relaxed balancing 
- A V L trees store balance factors or heights with each nod e, thus requires storage for 
  an integer per node whereas Red Black Tree requires only 1 bit of information per 
  node.
- Red Black Trees are used in most of the language libraries  like map, multimap, multisetin C + + whereas A V L trees are used in databases where faster retrievals are required.



### 位运算

- 位运算符
- 算数移位与逻辑移位
- 位运算的应用

为什么需要位运算？机器里的数字表示方式和存储格式就是二进制

| 左移     | <<   |
| :------- | ---- |
| 右移     | >>   |
| 按位或   | \|   |
| 按位与   | &    |
| 按位取反 | ~    |
| 按位异或 | ^    |

![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815112439.png)



![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815112450.png)



![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200815112500.png)



# 本周学习心得



本周首先进行了简历指导，专业的HR小姐姐给出了很多的建议，根据这些建议，自己进一步认真仔细的修改，改完之后还发给班班看了，班班也提出了一点修改建议，修改后的简历自己都觉得耳目一新，对比发现进步真的很大。之前没觉得简历有啥重要的，后来发现需要让别人在5s内看到你的优点，必须在简历上下足功夫。



本周学习的内容来说，还算是相对简单，所以自己在完成相关练习后，更多的其实还是对dp方程和递归那一块的知识进行的巩固。自己题目做的还是太少了，还需要多练习，一些陌生的题目拿到手之后发现根本就不会，没有思路，即使有思路自己也不敢写，写着写着自己就绕进去了，但是一看题解又觉得自己好傻，这么简单的题目都不会实在是不应该。总之还是需要多练习这一块的题目，走出自己的舒适区，让自己变得更加优秀。



时间过得实在是太快了，还有最后一个周的时间就毕业了。自己现在的做题状态，以及自己写代码的自信相比于之前都提高了不少，很感谢极客大学给我的帮助，自己也会一如既往的坚持下去，按照超哥说的五毒神掌坚持。



PS：再难也要坚持下去，即使少做，也不可以不做。

