#ifndef BEST_H
#define BEST_H

typedef struct best Best;

struct best
{
    void *prim;
    void *ult;
};

int best_fit(int* vetor, int tmn_vetor);

#endif