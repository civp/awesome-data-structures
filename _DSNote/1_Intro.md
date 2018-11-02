# Introduction

## Lec 1

1. Basic structures: List, Tree, Graph

1. Complexity Analysis

## Lec 2

### Some Algorithm Paradigms

* Greedy Algorithm

  * Coin Problems(approximate solution)

  * Find maxValue

* Divide and Conquer

  * Maximum Subsequence Sum

    Time Complexity Analysis(N per layer, logN layers in total)

  * Merge Sort / Quick Sort(Pivot)

  * Binary Search

* Dynamic Programming

  * 0/1 sack(NP Complete)

### Loop Invariant

1. Definition

   > In computer science, a loop invariant is an invariant used to prove properties of loops.

1. Propoties

   * **Initialization**: It is true prior to the first iteration of the loop.
   * **Maintenance**:  If it is true before an iteration of the loop, it remains true before the next iteration.
   * **Termination**: When the loop terminates, the invariant gives us a useful property that helps show that the algorithm is correct.

1. [Floyd-Hoare Logic](https://en.wikipedia.org/wiki/Hoare_logic)

   1. Definition

      > A formal system with a set of logical rules for reasoning rigorously about the correctness of computer programs.

   1. Hoare Triple

      The central feature of Hoare logic is the Hoare triple. A triple describes how the execution of a piece of code changes the state of the computation. A Hoare triple is of the form

      `{P} C {Q}`

      where P and Q are assertions and C is a command. P is named the precondition and Q the postcondition: when the precondition is met, executing the command establishes the postcondition. Assertions are formulae in predicate logic.