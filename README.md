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

<h4>Completed + Bonus</h4>

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

### The algorithms
After extensive research, one thing became clear to me: this project is not about finding the best algorithm. It is, however, about subverting some existing ones into thinking and doing whatever is necessary to accomplish the goal in the minimum possible number of operations - no matter how long or how much computational power it takes. 

Thankfully, I came across [Victor Nunes](https://github.com/victor-ln)'s solution a while ago and thought it was one of the best working solutions ever made for this project, and put my mind in trying it out! (Thanks again, Victor!).

The idea of this "algorithm" is to ensure that the most efficient movement will be done at each interaction. I took Victor's idea to heart and implemented it myself as if to prove that it actually works (spoiler alert: it does beautifully!)

### Some interesting links
- [Laís Arena](https://github.com/laisarena)'s [tester](https://github.com/laisarena/push_swap_tester)
- [Ilya Kashnitskiy](https://github.com/elijahkash)'s [graphical interface](https://github.com/elijahkash/push_swap_gui)
- [Paula Hemsi](https://github.com/paulahemsi)'s [push_swap simulator](https://phemsi-a.itch.io/push-swap)
