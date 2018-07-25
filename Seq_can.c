/*
 * Seq.c    v1.0
 *
 *  Created on: 2018-7-19
 *      Author: mlzmxy
 */

// include head file for Elem_T


#include "Seq.h"

/* prototype for functions */
static int Loop(T seq, int value);



/**
 * Seq_init:       创建一个数组序列
 *
 * @param seq      创建的序列
 *
 * 创建之前，定义头文件中的元素类型与序列大小：
 *   1. Elem_T    元素类型
 *   2. CAPACITY  序列大小
 */
void Seq_init(T seq)
{
  seq->capacity = CAPACITY;
  seq->size = 0;
  seq->front = 1;
  seq->rear = 0;
}

/**
 * Seq_push: 将值value插到序列末尾
 *
 * @param seq    序列
 * @param value  插入值
 *
 * 注意：
 *   序列为空是未检查的运行时错误，在执行Seq_push之前使用Seq_isEmpty检查序列。
 */
void Seq_push(T seq, Elem_T value)
{
  seq->size++;
  seq->rear = Loop(seq, seq->rear);
  seq->data[seq->rear] = value;
}

/**
 * Seq_pop: 获取序列最前面的值
 *
 * @param seq  序列
 *
 * @return 序列最前面的值
 *
 * 注意：
 *   序列为空是未检查的运行时错误，在执行Seq_push之前使用Seq_isEmpty检查序列。
 */
Elem_T Seq_pop(T seq)
{
  seq->size--;
  int tmp = seq->front;
  seq->front = Loop(seq, seq->front);
  return seq->data[tmp];
}


/**
 * Seq_isEmpty: 序列是否为空
 *
 * @param seq 序列
 *
 * @return
 *   0 非空
 *   1 空
 */
int Seq_isEmpty(T seq)
{
  return seq->size == 0;
}

/**
 * Seq_noEmpty: 序列是否非空
 *
 * @param seq 序列
 *
 * @return
 *   1 非空
 *   0 空
 */
int Seq_noEmpty(T seq)
{
  return seq->size > 0;
}

/**
 * Seq_isFull: 序列是否已满
 *
 * @param seq 序列
 *
 * @return
 *   0 未满
 *   1 已满
 */
int Seq_isFull(T seq)
{
  return seq->size == seq->capacity;
}

/**
 * Loop: 序列索引循环
 *
 * @param seq  序列
 * @param value 序列索引值
 *
 * @return 增加的索引值
 */
static int Loop(T seq, int value)
{
  if(++value == seq->capacity)
  {
    value = 0;
  }

  return value;
}


