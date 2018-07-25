/*
 * Seq.h    v1.0
 * 
 * Seq是一个使用数组存储元素的序列，主要包括以下功能：
 *   1. 将一个元素放入序列末尾
 *   2. 获得将序列最前面的元素，并删除该元素
 *   3. 判断序列是否为空
 *   4. 判断序列是否非空
 *   5. 判断序列是否已满
 *
 * 使用须知：
 *   1. 使用前需设置序列大小和元素类型
 *   2. 必要时添加元素类型的头文件
 *
 * 警告：
 *   1. 在执行 Seq_push 和 Seq_pop 时，序列为空是未检查的运行时错误，
 *      因此在执行 Seq_push 和 Seq_pop 之前必须使用 Seq_isEmpty 检查序列。
 *
 *  Created on: 2018-7-19
 *      Author: mlzmxy
 */

#ifndef SEQ_H
#define SEQ_H

#ifndef NULL
#define NULL 0
#endif

// 设置序列大小
#define CAPACITY 10
// 设置序列元素类型
#define Elem_T int

struct Seq_T
{
	int capacity;
	int size;
	int front;
	int rear;
	Elem_T data[CAPACITY];
};
typedef struct Seq_T* T;

/* declaration for functions */
void Seq_init(T seq);                //序列初始化
void Seq_push(T seq, Elem_T value);  //将元素放入序列末尾
Elem_T Seq_pop(T seq);               //获得序列最前面的元素值，并删除元素
int Seq_isEmpty(T seq);              //判断序列是否为空
int Seq_noEmpty(T seq);              //判断序列是否非空
int Seq_isFull(T seq);               //判断序列是否已满

#endif /* SEQ_H */
