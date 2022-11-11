The image are runtime graphs of the respective Sorting algorithms.
In Checker.cpp:
no_array_I : The number of arrays used for sorted for a particular value of i(no of elements)
The arrays are at a distance 100 elements apart.
*****************************************************************************************
Current Setting in Checker.cpp is for Tournament Sort,
If needed to change, do:-
Line 3:-  #include "ShellSort.cpp"
Line 24:- Replace the function name by ShellSort().
Line 10:-Don't forget to change the name of the out file.
******************************************************************************************
Compilation and execution needs to be done, as executable is not included here.  

******************************************************************************************
Inference from the graph:- We can see that the upper envelope of ShellSort graph is bounded by kn^2.
Also we can note the the upper envelope of Tournament Sort is greater than linear but less than Quadratic., hence it is some where around n*logn.