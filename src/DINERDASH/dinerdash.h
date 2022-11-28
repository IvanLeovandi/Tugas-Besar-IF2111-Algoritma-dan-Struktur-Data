/* File dinerdash.h */
#include "../RNG/random_number.h"
#include "../adt/Queue/queue_diner.h"
#include "../adt/Mesin/mesinkata.h"
#include "../adt/Mesin/mesinkarakter.h"
#include "../adt/Array/array_diner.h"

#ifndef DINER_DASH_H
#define DINER_DASH_H

int fromStr(char *x);
void putaran(int *id, QueueDiner *pesanan, ArrayDiner *masak, ArrayDiner *saji);
void displayQueueDiner(QueueDiner pesanan, ArrayDiner masak, ArrayDiner saji, int* saldo);
void DinerDash(int *score);

#endif