#define _GNU_SOURCE
#define __USE_GNU
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include <string.h>
#include <unistd.h>

typedef enum TypeTag
{
    ADD,
    MUL,
    SUB,
    FIBO
} TypeTag;

typedef struct Node
{
    TypeTag type;
    long long value;
} Node;

long long aa = -1;
long long bb = -1;
Node *result;

long long fib(long long n)
{
    if (n < 0)
        n = llabs(n);

    if (n == 1 || n == 2)
    {
        return n - 1;
    }

    long long dp[2];

    dp[0] = 0;
    dp[1] = 1;

    for (long long i = 3; i <= n; ++i)
    {
        long long tmp = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = tmp;
    }

    return dp[1];
}

Node *addFuncIntegers(long long a, long long b)
{
    if (b == NULL)
    {
        result->value = fib(a);
        result->type = FIBO;
        return result;
    }

    result->value = a + b;
    return result;
}

Node *mulFuncIntegers(long long a, long long b)
{
    if (b == NULL)
    {
        result->value = fib(a);
        result->type = FIBO;
        return result;
    }

    result->value = a * b;
    return result;
}

Node *subFuncIntegers(long long a, long long b)
{
    if (b == NULL)
    {
        result->value = fib(a);
        result->type = FIBO;
        return result;
    }

    result->value = b - a;
    return result;
}

static void signalHandler(int sig, siginfo_t *info, void *ucontext)
{
    /* Assuming your architecture is Intel x86_64. */
    ucontext_t *uc = (ucontext_t *)ucontext;
    greg_t *rip = &uc->uc_mcontext.gregs[REG_RIP];

    /* Assign a new value to *rip somehow, which will be where the
       execution will continue after the signal handler returns. */
    switch (result->type)
    {
    case ADD:
        result = addFuncIntegers(aa, bb);
        asm volatile(
            "movabs $checkpoint1, %0" // checkpoint1 is the address of the next instruction after the call to addFuncIntegers
            : "=r"(*rip));
        break;
    case MUL:
        result = mulFuncIntegers(aa, bb);
        asm volatile(
            "movabs $checkpoint2, %0" // checkpoint2 is the address of the next instruction after the call to mulFuncIntegers
            : "=r"(*rip));
        break;
    case SUB:
        result = subFuncIntegers(aa, bb);
        asm volatile(
            "movabs $checkpoint3, %0" // checkpoint3 is the address of the next instruction after the call to subFuncIntegers
            : "=r"(*rip));
        break;
    }
}

Node *addFuncNodes(Node *a, Node *b)
{
    struct sigaction sa;
    sa.sa_sigaction = signalHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);

    aa = (long long)a;
    bb = (long long)b;

    if (b == NULL)
    {
        result->value = fib(a->value);
        result->type = FIBO;
        return result;
    }

    result->value = a->value + b->value;
    asm volatile("checkpoint1: .global checkpoint"
                 :);
    return result;
}

Node *mulFuncNodes(Node *a, Node *b)
{
    struct sigaction sa;
    sa.sa_sigaction = signalHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);

    aa = (long long)a;
    bb = (long long)b;

    if (b == NULL)
    {
        result->value = fib(a->value);
        result->type = FIBO;
        return result;
    }

    result->value = a->value * b->value;
    asm volatile("checkpoint2: .global checkpoint"
                 :);
    return result;
}

Node *subFuncNodes(Node *a, Node *b)
{
    struct sigaction sa;
    sa.sa_sigaction = signalHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);

    aa = (long long)a;
    bb = (long long)b;

    if (b == NULL)
    {
        result->value = fib(a->value);
        result->type = FIBO;
        return result;
    }

    result->value = b->value - a->value;
    asm volatile("checkpoint3: .global checkpoint"
                 :);
    return result;
}

typedef Node *(*FuncPtr)(Node *, Node *);
FuncPtr makeFunc(TypeTag t)
{
    result = malloc(sizeof(Node));
    result->type = t;
    if (t == ADD)
        return addFuncNodes;
    else if (t == MUL)
        return mulFuncNodes;

    return subFuncNodes;
}

void calc(Node *res)
{
    switch (res->type)
    {
    case ADD:
        printf("add: %lld\n", res->value);
        break;
    case MUL:
        printf("mul: %lld\n", res->value);
        break;
    case SUB:
        printf("sub: %lld\n", res->value);
        break;
    case FIBO:
        printf("fibo: %lld\n", res->value);
        break;
    }
}

int main()
{
    Node *add = (*makeFunc(ADD))(10, 6);
    Node *mul = (*makeFunc(MUL))(5, 4);
    Node *sub = (*makeFunc(SUB))(mul, add);
    Node *fibo = (*makeFunc(SUB))(sub, NULL);

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    return 0;
}
