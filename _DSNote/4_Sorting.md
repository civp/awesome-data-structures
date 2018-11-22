# Sorting

## Quicksort

### Picking the Pivot

How to balance the partitioning?

1. Random Pick

   Expensive time cost

1. Advanced Random Pick

   Definition: performance *P* of partitioning is defined as the relative length of the shorter part

Algorithm: Random Pick until *P > 1/4*, *E(X)=2*.

1. Median-of-Three Partitioning

   *P* of Median-of-Five is greater than *30%*, which is easy to verify.

### Partitioning Strategy

The elements of a loop

* States sequence *S*

* Update function *u*

* Loop condition *C*

In a loop, we keep *S*, the sequence of s(i), where *s(i)* denotes the state of the *i-th* step.

A loop can be represented as *s(i+1) = u(s(i) + [i+1]) if C(s(i))*, where *u* denotes the update function, *[i+1]* denotes the new information. *C(s(i))* checks current state and determine whether to terminate. This update function is the core of a loop.

To implement a loop, we have to define the state *S*(includes the initial state *s(0)* and terminal state *s(n)*), update function *u*, loop condition *C*. Loop condition *C* is primely used for the termination. But to kick off, *C* in turn determines the initial state *s(0)*.

So the definition of loop itself is a loop! The states sequence should be **well-defined** to stablize this process.