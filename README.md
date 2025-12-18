#### This project has been created as part of the 42 curriculum by anfarenc

# PUSH_SWAP

## Description
The aim of this project is to sort in ascending order one continued list numbers in one stack with two stack (a, b), by using 11 predefined operations :

- **sa  :** Swap the first 2 elements at the top of stack a.Do nothing if there is only one element or none.
- **sb  :** Swap the first 2 elements at the top of stack b.Do nothing if there is only one element or none.
- **ss  :** sa and sb at the same time.
- **pa  :** Take the first element at the top of b and put it at the top of a.Do nothing if b is empty
- **pb  :** Take the first element at the top of a and put it at the top of b.Do nothing if a is empty.
- **ra  :** Shift up all elements of stack a by 1.The first element becomes the last one.
- **rb  :** Shift up all elements of stack b by 1.The first element becomes the last one.
- **rr  :** ra and rb at the same time.
- **rra :** Shift down all elements of stack a by 1.The last element becomes the first one.
- **rrb :** Shift down all elements of stack b by 1.The last element becomes the first one.
- **rrr :** rra and rrb at the same time.

### Demo
[visualizer](github-video/demo.gif)

## Instruction

### Compilation
**Push_swap** <br>
` make ` <br>
**Checker** <br>
` make bonus`
### Execute
**Normally** <br>
` $>./push_swap  2 1 3 6 5 8 ` <br>
` $>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l ` <br>
**With Checker** <br>
`$> ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG `

## Resources
- [Wikepedia Longest increasing subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence) <br>
- [Stack in C](https://www.geeksforgeeks.org/c/implement-stack-in-c/)