# push_swap
Creating an algorithm to sort a stack of random numbers  

You start with two stacks. Stack "a" is filled with random integers entered via command line arguments.  
Stack "b" is used to temporarily store some integers of stack a and bring them in a specific order.  

Only these moves are allowed:  

• sa : swap a - swap the first 2 elements at the top of stack a. (Do nothing if there is only one or no elements).  
• sb : swap b - swap the first 2 elements at the top of stack b. (Do nothing if there is only one or no elements).  
• ss : sa and sb at the same time.  
• pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.  
• pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.  
• ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.  
• rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.  
• rr : ra and rb at the same time.  
• rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.  
• rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.  
• rrr : rra and rrb at the same time.  

At the end, stack b must be empty empty and all integers must be in stack a, sorted in ascending order.  

![push_swap]([https://github.com/cyberKev42/push_swap/blob/main/push_swap_visualized.gif])
