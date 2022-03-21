<h1 align=center>
	<b>push_swap</b>
</h1>

<h2 align=center>
	 <i>42cursus' project #7</i>
</h2>

<p align=center>
	This project's goal is to make the student get in contact with the idea of sorting algorithms and complexity. In possession of a list of numbers, the program must be able to use only two stacks and a restricted number of movements in order to sort the list out. 
</p>

---
<div align=center>
<h2>
	Final score
</h2>

<img src=https://github.com/caroldaniel/caroldaniel-utils/blob/6b25474bf78299bc7cded8a9c423eebf35fb1d75/push_swap_grade.png alt="cado-car's 42Project Score"/>
<h4>Completed + Bonus</h4>
<img src=https://github.com/caroldaniel/caroldaniel-utils/blob/6b25474bf78299bc7cded8a9c423eebf35fb1d75/push_swapm.png alt="cado-car's 42Project Badge"/>

</div>

---

<h3 align=center>
Mandatory
</h3>

> <i>For the <b>mandatory</b> part, we should:
> 1. Be able to sort the given list of numbers correctly;
> 2. Do it so with the least possible number of movements.</i>

<h3 align=center>
Bonus
</h3>

> <i>For the <b>bonus</b> part we should:
> 1. Do a checker program in order to access if the movements done can correctly sort the list given.</i>

---

<h2>
The project
</h2>

### Rules

You have 2 stacks named `A` and `B`. 
- The `stack A` contains a random amount of negative and/or positive numbers which cannot be duplicated. 
- The `stack B` is empty. 

The goal is to sort in ascending order numbers into `stack A`.
To do so you have the following operations at your disposal: 

- `sa` (swap a): Swap the first 2 elements at the top of `stack A`. Do nothing if there is only one or no elements. 
- `sb` (swap b): Swap the first 2 elements at the top of `stack B`. Do nothing if there is only one or no elements. 
- `ss` : `sa` and `sb` at the same time. 
- `pa` (push a): Take the first element at the top of `B` and put it at the top of `A`. Do nothing if `B` is empty. 
- `pb` (push b): Take the first element at the top of `A` and put it at the top of `B`. Do nothing if `A` is empty.  
- `ra` (rotate a): Shift up all elements of `stack A` by 1. The first element becomes the last one. 
- `rb` (rotate b): Shift up all elements of `stack B` by 1. The first element becomes the last one.  
- `rr`: `ra` and `rb` at the same time. 
- `rra` (reverse rotate a): Shift down all elements of `stack A` by 1. The last element becomes the first one. 
- `rrb` (reverse rotate b): Shift down all elements of `stack B` by 1. The last element becomes the first one.  
- `rrr`: `rra` and `rrb` at the same time.

You can launch the program by doing
```sh
> $ ./push_swap <list_of_integers> 
```
The list can be passed as a single array of multiple numbers, indiferently. 
```sh
> $ ./push_swap 1 3 5 4 2 0 -4
```
or
```sh
> $ ./push_swap "1 3 5 4 2 0 -4"
```

The expected output should be the instructions applied in order to sort the stack: 

```sh
> $ ./push_swap 0 4 2
> pb
> ra
> pa
```
Or an `Error` message in case of errors of any kind:
```sh
> $ ./push_swap 0 4 two
> Error
```

If no parameters are passed, the command prompted will be returned with no error message:
Or an `Error` message in case of errors of any kind:
```sh
> $ ./push_swap
> $
```

### The algorithm
After extensive research, one thing became clear to me: this project is not about finding the best algorithm. It is, however, about subverting some existing ones into thinking and doing whatever is necessary to accomplish the goal in the minimum possible number of operations - no matter how long or how much computational power it takes. 

Thankfully, I came across [Victor Nunes](https://github.com/victor-ln)'s solution a while ago and thought it was one of the best ever made for this project. So, I put all my efforts and my mind in trying it out! (Thanks again, Victor!).

![push_swap_visualizer](./imgs/push_swap_visualizer.gif)

The idea of this "algorithm" is to ensure that the most efficient movement will be done at each interation. I took Victor's idea to heart and implemented it myself as if to prove that it actually works (spoiler alert: it does beautifully!). The program runs on average 22% more efficiently then the maximum accepted for a 100% score. For example, in a 500 numbers' stack, the average iteration count is around 4300 movements (where the aim is to reach up to 5500 for an A grade).

The idea is very simple and is divided in four basic steps: 
- `Step 1`: calculate if the top number at stack A is among the 30%ish lowest numbers in the entire stack (this number was not chosen on random - it came from multiple test for the most optimized combination). If it is, push it to stack B. The program will do the math for every number on stack A until it is at most 5 numbers long;
- `Step 2`: sort the five numbers left at stack A, so that it becomes ready to receive the numbers at stack B back;
- `Step 3`: push the numbers from stack B back to A, but with a minor detail: the program will calculate the correct place for that number to be, so that when it is pushed, stack A will never be out of order again. More then that, it will calculate which number from stack B takes the minimum amount of movements (the one at the top, the second or the last one). It will only move a number if it can make sure that it is the most optimum choice;
- `Step 4`: when all the numbers from stack B are back and in order on stack A, then the program will align the stack, making sure that it starts with the lowest number.

As you can see, it takes a lot of computational power. The stacks are iterated over multiple times, and a bunch of calculations are done at every step. However, this is the beauty of `push_swap`: it is not about computational performance; it is about being smart and subverting the algorithms to work in your favor. 

### The implementation

- [`Makefile`](Makefile)

Header file
- [`push_swap.h`](include/push_swap.h)

Main function	
- [`main.c`](src/main.c)

Initialization
- [`init.c`](src/init.c)
- [`args.c`](src/args.c)

Linked list utils
- [`list_utils_1.c`](src/list_utils_1.c)
- [`list_utils_2.c`](src/list_utils_2.c)

Stack management and operations
- [`stack_op_1.c`](src/stack_op_1.c)
- [`stack_op_2.c`](src/stack_op_2.c)

Sorting
- [`sort.c`](src/sort.c)
- [`sort_utils_1.c`](src/sort_utils_1.c)
- [`sort_utils_2.c`](src/sort_utils_2.c)

Code utilities
- [`utils_1.c`](src/utils_1.c)
- [`utils_2.c`](src/utils_2.c)
- [`utils_3.c`](src/utils_3.c)


Error management and program closing
- [`error.c`](src/error.c)

### Bonus

The bonus part of this project consists in producing a `checker` executable that will check, for the stack given, it the instructions passed on the command prompt in fact are able to sort the stack.

You can launch the program by typing:
```sh
> $ ./checker <list_of_integers> 
``` 

And then typing the instructions in order to sort them, only separated by a new line. By pressing `Ctrl+D` at the end, the program will return `OK` if list is sorted:
```sh
> $ ./push_swap 0 4 2
> $ pb
> $ ra
> $ pa
> OK
```
`KO` if not:
```sh
> $ ./push_swap 0 4 2
> $ pb
> $ ra
> KO
```
And `Error` if there were any errors in reading the instructions or parsing the list:
```sh
> $ ./push_swap 0 4 2
> $ not_a_comand
> Error
```

The implementation for the Bonus part can be found below:
	
- [`checker.c`](src/checker.c)
- [`utils_bonus.c`](src/utils_bonus.c)

### Some interesting links
- [Laís Arena](https://github.com/laisarena)'s [tester](https://github.com/laisarena/push_swap_tester)
- [Ilya Kashnitskiy](https://github.com/elijahkash)'s [graphical interface](https://github.com/elijahkash/push_swap_gui)
- [Paula Hemsi](https://github.com/paulahemsi)'s [push_swap simulator](https://phemsi-a.itch.io/push-swap)
- [Emmanuel Ruaud](https://github.com/o-reo)'s [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
