#ifndef biginteger_H
#define biginteger_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct BigInteger
{
    int data;
    struct BigInteger *next;
};
struct BigInteger   initialize(char *);
struct BigInteger *  initializeq(char *);
struct BigInteger * sumq(struct BigInteger * ,struct BigInteger * );
struct BigInteger * subq(struct BigInteger * ,struct BigInteger * );
void displayq(struct BigInteger *);
int length(struct BigInteger *);
struct BigInteger * sign(struct BigInteger *);
void  reverse(struct BigInteger**);
struct BigInteger* mulq(struct BigInteger * , struct BigInteger *);
struct BigInteger* multiplyByDigit(struct BigInteger *  , int digit);
struct BigInteger  add(struct BigInteger  ,struct BigInteger  );
struct BigInteger  sub(struct BigInteger  ,struct BigInteger  );
void display(struct BigInteger );
int lengthq(struct BigInteger );
struct BigInteger  signq(struct BigInteger );
void  reverseq(struct BigInteger*);
struct BigInteger mul(struct BigInteger  , struct BigInteger );
struct BigInteger multiplyByDigitq(struct BigInteger   , int digit);
struct BigInteger* div1q(struct BigInteger* n1, struct BigInteger* n2);
struct BigInteger div1(struct BigInteger n1, struct BigInteger n2);
struct BigInteger *modq(struct BigInteger *n1,struct BigInteger *n2);
struct BigInteger mod(struct BigInteger n1,struct BigInteger n2);
#endif