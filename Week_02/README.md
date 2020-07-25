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

二叉树的中序遍历：3

二叉树的前序遍历：3

周二：

N叉树的前序遍历：3

N叉树的后序遍历：3

周三：

最小的k个数：3

前k个高频元素：3

周四：

组合：3

N叉树的层序遍历：3

周五：

丑数：3



## 学习总结

### 树、二叉树、二叉搜索树

**链表是特殊化的树，树是特殊化的图**

```C++
struct TreeNode* {
	int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```



二叉树的三种遍历代码：递归代码



```C++
vector<int> ThreeTraversalBinaryTree(TreeNode* root) {
    vector<int> res;
    helper(root, res);
    return res;
}
void helper(TreeNode* root, vector<int>& res) {
    if (root) {
        // 前序遍历
        res.push_back(root->val);
        if (root->left) helper(root->left, res);
        if (root->right) helper(root->right, res);
        // 中序遍历
        if (root->left) helper(root->left, res);
        res.push_back(root->val);
        if (root->right) helper(root->right, res);
        // 后序遍历
        if (root->left) helper(root->left, res);
        if (root->right) helper(root->right, res);
        res.push_back(root->val);
    }
}
```



二叉搜索树：有序二叉树，具有一下性质：1）左子树上的**所有结点**的值均小于它的根结点的值；2）右子树上的所有结点的值均大于它的根结点的值；3）左右子树也分别是二叉搜索树。

**二叉搜索树的中序遍历是一个升序排列**！！！

二叉搜索树的lookup、insert、delete操作都是log(n)的时间复杂度。



### 泛型递归、树的递归

树的面试题一般都用递归解决：节点的定义，自相似性。



递归代码模板：

```C++
vector<int> recursion(int level, int parm1, int param2, ...) {
    // recursion terminator
    if (level > maxLevel) {
        precess_result;
        return res;
    }
    
    // process logic in current level
    process(level, data...);
    
    // drill down
    recursion(level + 1, p1, ...);
    
    // reverse the current level status if needed
    
}
```



**思维要点：**

1. 不要人肉进行递归（最大误区）
2. 找到最近最简方法，将其拆解成可重复解决的问题（重复子问题）
3. 数学归纳法思想



## 堆 Heap 和 二叉堆 Binary Heap



Heap：可以迅速找到一堆数中的最大或者最小值的数据结构

根结点最大的堆叫做大顶堆或大根堆，反之叫做小顶堆或者小根堆，常见的堆有二叉堆、斐波那契堆等



大顶堆常见的API：

find_max:		O(1)

delete_max:	O(logN)

insert(create):	O(logN) or O(1)  注：O(1) 是斐波那契堆的时间复杂度



二叉堆（大顶）的性质：1）一颗完全二叉树；2）树中任意结点的值总是 >= 其子结点的值；



二叉堆一般通过数组来实现

根结点是：a[0]

- 索引为 i 的左孩子的索引是 (2*i + 1);
- 索引为 i 的右孩子的索引是 (2*i + 2);
- 索引为 i 的父节点的索引是 floor ((i - 1) / 2);



**插入操作：**O(logN)

1. 新元素一律先插到堆的尾部
2. 依次向上调整整个堆的结构（一直到根即可）



**删除堆顶操作**

1. 将堆尾元素替换到顶部
2. 依次从根部向下调整整个堆的结构（一直到堆尾即可）



**注意：二叉堆是堆（优先队列的一种简单实现），但并不是最优的实现**



### 图：不作为面试重点，但也需要了解基本的知识



![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200725114642.png)

图的分类：

无向无权图，有向无权图，无向有权图，有向有权图



![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200725114903.png)



![](https://gitee.com/j_s_wang/blog_image_staging/raw/master/img/20200725114918.png)



# 本周学习心得

由于自己在数据结构方面知识的欠缺，导致这周的课程和题目完成度都不是很好，往往一个题目就花费了2个小时，才琢磨透。但是超哥的方法确实是行之有效，能够体会到自己的点滴进步，自己认真按照超哥的方法，将一些模板直接背下来，在写代码的时候，特别是树的递归那一块，闭着眼睛也能写出来了。

虽然树的递归能够很好的实现，但是在其他需要用到递归的地方又有点懵逼了，即使背了超哥的模板，还是需要通过题目的积累，才能达到一定的量，引起质变。

自己对于堆还不是很了解，用的一点都不熟悉，这次也是勉强将别人的优秀的解法背下来的，有点挫败感，但是自己并不会因此放弃，还是会一如既往的坚持下去。



PS：即使再难也按照超哥的五毒神掌刷题，加油。



