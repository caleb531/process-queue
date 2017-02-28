# CS 433 Process Queue

*Copyright 2017 Caleb Evans, Jonathan Tapia*

## How to run

Run `make` to compile the program, then run `./process-queue.out` to execute the
compiled program.

## Data Structure

We implemented our priority queue using a one-dimensional static array
structured as a heap. Using an array to store the heap nodes maximizes space
efficiency while minimizing time spent performing inserts/deletes. The array is
also fixed-sized, which improves the performance of inserts/deletes even
further.

## Time complexity

### Insertion

Inserting a node into the queue can be thought of as a two-step process:

The first step is appending the node the end of the internal heap-array, an O(1)
operation given that our array is fixed-size.

The second step is tricking the node up the conceptual heap-tree by swapping it
with parents as needed; this is an O(log n) operation in the worst case because
log (n - 1) swaps must be made if the node trickles all the way up to become the
new root. In the best case, no swapping is required, leaving the time complexity
at O(1).

### Deletion

Removing the highest-priority node from the queue requires can also be thought
of as a two-step process:

The first step is replacing the root node (i.e. the highest-priority node) with
the last node in the heap-array—an O(1) operation.

The second step is to trickle the temporary root down the heap-tree to its
proper place by comparing it with its child nodes—an O(log n) operation in the
worst case (i.e. if the node is trickled down to the bottom of the heap). Again,
in the best case, no swapping is required, resulting in a time complexity of
O(1).
