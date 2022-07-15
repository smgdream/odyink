#ifndef LAP_LIST_H 
#define LAP_LIST_H

#include "lap_types.h"


/* 
 * 获取偏移量
 * type: 容器(父结构)类型
 * menber: 容器(父结构)list_head成员的标识符
 */
#define offset_of(type, menber) ((size_t) &((type *)0)->menber)

/* 
 * 获取容器(父结构)地址
 * type: 容器(父结构)类型
 * menber: 容器(父结构)list_head成员的标识符
 * ptr: 容器(父结构)对象list_head成员的指针
 */
#define container_of(type, menber, ptr) \
	( (type *)((void *)(ptr) - offset_of(type, menber)) ) 

/* 
 * 获取链表条目地址
 */
#define list_entry(type, menber, ptr) container_of(type, menber, ptr)

/* 
 * 创建新表头
 */
struct list_head *list_head_create();

/* 
 * 初始化表头
 */
#define list_head_init(name) { &(name), &(name) }

/* 
 * pos节点前面插入node
 */
static inline void node_insert(struct list_head *pos, struct list_head *node)
{
	node->nextp = pos;
	node->prevp = pos->prevp;
	node->nextp->prevp = node;
	node->prevp->nextp = node;
}

/* 
 * 从链表中抽出节点node
 */
static inline struct list_head *node_extract(struct list_head *node)
{
	node->prevp->nextp = node->nextp;
	node->nextp->prevp = node->prevp;
	node->nextp = node;
	node->prevp = node;
	return node;
}

/* 
 * 释放容器
 */
static inline void list_entry_remove(struct list_head *node, void *entry)
{
	node->prevp->nextp = node->nextp;
	node->nextp->prevp = node->prevp;
	free(entry);
}

/* 
 * 释放(不属于容器的)独立节点
 */
static inline void node_remove(struct list_head *node)
{
	list_entry_remove(node, node);
}

/* 
 * 正向遍历链表
 */
#define list_for_each(iter, headptr) \
	for (struct list_head *next_iter = (headptr)->nextp->nextp; \
		(iter = next_iter->prevp) != (headptr); \
		next_iter = next_iter->nextp)

/* 
 * 反向遍历链表
 */
#define list_for_each_prev(iter, headptr) \
	for (struct list_head *prev_iter = (headptr)->prevp->prevp; \
		(iter = prev_iter->nextp) != (headptr); \
		prev_iter = prev_iter->prevp)

/* 
 * 正向遍历链表条目
 */
#define list_for_each_entry(iter, headptr, type, menber) \
	for (struct list_head *_head = headptr, \
		*_node = (headptr)->nextp, *next_iter = _node->nextp; \
		_node != _head && (iter = list_entry(type, menber, _node)); \
		_node = next_iter, next_iter = next_iter->nextp)

/* 
 * 反向遍历链表条目
 */
#define list_for_each_entry_prev(iter, headptr, type, menber) \
	for (struct list_head *_head = headptr, \
		*_node = (headptr)->prevp, *prev_iter = _node->prevp; \
		_node != _head && (iter = list_entry(type, menber, _node)); \
		_node = prev_iter, prev_iter = prev_iter->prevp)

/* 
 * 链表空
 */
static inline int list_empty(struct list_head *head)
{
	return (head)->nextp == (head);
}


#endif