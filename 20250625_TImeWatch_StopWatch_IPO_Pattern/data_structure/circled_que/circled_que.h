/*
 * circled_que.h
 *
 *  Created on: Jun 25, 2025
 *      Author: kccistc
 */

#ifndef CIRCLED_QUE_CIRCLED_QUE_H_
#define CIRCLED_QUE_CIRCLED_QUE_H_

#define QUE_SIZE 4

typedef struct {
	int top;
	int tail;
	void* queData[QUE_SIZE];
}CircleQue_tpye;

void queInit(CircleQue_tpye* que);
int isQueFull(CircleQue_tpye* que);
int isQueEmpty(CircleQue_tpye* que);
int enQue(CircleQue_tpye* que, void* data);
void* deQue(CircleQue_tpye* que);
void* queFront(CircleQue_tpye* que);

#endif /* CIRCLED_QUE_CIRCLED_QUE_H_ */
