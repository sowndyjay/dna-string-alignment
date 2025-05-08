# PS5: DNA Alignment

## Contact
Name: Sowndaryan Jayaprakash
Section: 201

Partner: John Wesley Agojo
Partner Section: 201

Time to Complete: 6 hours


## Description
The purpose of this project is to use dynamic programming to learn computational biology. The task was to optimize the sequence alignment of 2 DNA strings. This is done by measuring the two strings' edit distance, compared side to side. 

### Features
Explain how you did the actual alignment including the data structures used.

### Testing
Describe what the unit tests you wrote check for and why you picked them.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.


## Analysis

### Example
Do one additional test case by hand. It should be constructed in such a way that you know the correct  output before running your program on it, and it should be a "corner case" that helps check if your program handles all special situations correctly. 

Please list:
 - a copy of the test case input
 - the expected test case output
 - whether your program ran correctly on it or not
 - optionally, any other remarks

### Specs
Your Computer
Memory: (ex: 8gb, DDR4)
Processors: (ex: i5-8500 @ 3.00 GHz x6)

Partner's Computer
Memory: (ex: 8gb, DDR4)
Processors: (ex: i5-8500 @ 3.00 GHz x6)

### Runs
Fill in the table with the results of running your code on both your and your partner's computers.

| data file     | distance | memory (mb) | time (seconds) | partner time |
|---------------|----------|-------------|----------------|--------------|
|ecoli2500.txt  |118       |24.07        |0.110709        |              |
|ecoli5000.txt  |160       |95.76        |0.94376         |              |
|ecoli10000.txt |223       |382.2        |3.59455         |              |
|ecoli20000.txt |3135      |1491.0       |17.2026         |              |
|ecoli50000.txt |killed    |             |                |              |
|ecoli100000.txt|killed    |             |                |              |

Here is an example from another computer for some of the files.

| data file    | distance | time (s) |
|--------------|----------|----------|
|ecoli2500.txt |      118 |    0.171 |
|ecoli5000.txt |      160 |    0.529 |
|ecoli7000.txt |      194 |    0.990 |
|ecoli10000.txt|      223 |    1.972 |
|ecoli20000.txt|     3135 |    7.730 |

### Time
Assume the two strings are the same length (M = N).  By applying the doubling method to the data points that you obtained, estimate the running time of youu program in seconds as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input your program can handle if it is limited to one day of computation.

Provide a brief justification/explanation of how you applied the doubling method, and if you data seems not to work, describe what went wrong and use the sample data instead.

I calculated the ratios from each interval, 2500 to 5000, 5000 to 10000, etc. They averaged for b to be roughly 2.0. Now we know that t(n) is about a * n^2, i got that a was roughly 1.8 x 10^-9 by plugging in the numbers
 - a = 1.8 x 10^-9
 - b = 2
 - largest N = 1,550,000

### Memory
Assume the two strings are the same length (M = N).  Look at your code and determine how much memory it requires as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input size your computer can handle if limited to 8GiB of RAM.

 - a = 4
 - b = 2
 - largest N = 46,340

### Valgrind
Run valgrind and list any errors you see.  Identify whether the memory usage reported by valgrind almost matches the calculations in the previous section.

| data file     | Calculated (mb) | Measured (mb) | Difference (%) |
|---------------|-----------------|---------------|----------------|
|ecoli2500.txt  |23.84            |24.07          |+0.96%          |
|ecoli5000.txt  |95.37            |95.76          |+0.41%          |
|ecoli10000.txt |381.47           |382.20         |+0.19%          |
|ecoli20000.txt |1525.88          |1491.00        |-2.29%          |
|ecoli50000.txt |9536.74          |killed         |                |
|ecoli100000.txt|38146.98         |killed         |                |

## Pair Programming
If you worked with a partner, do you have any remarks on the pair programming method? E.g., how many times did you switch, what are the tradeoffs of driving vs. navigating, etc.?

## Extra Credit
Anything special you did.  This is required to earn bonus points.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

