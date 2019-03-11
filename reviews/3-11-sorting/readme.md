## Time Comparisons of Sorting Algorithms

### Fill in this table as the program runs
| Sorting Algorithm | 1,000 | 5,000 | 10,000 | 50,000 | 100,000 | 200,000 | 300,000 |
|:-----------------:|-------|-------|--------|--------|---------|---------|---------|
|    Bubble Sort    |       |       |        |        |         |         |         |
|   Insertion Sort  |       |       |        |        |         |         |         |
|     Quick Sort    |       |       |        |        |         |         |         |

### Using those results, fill in *this* table about **bubble sort**
| Bubble Sort             | Input increased by a factor of: | Execution time increased by a factor of: |
|-------------------------|---------------------------------|------------------------------------------|
| From 5,000 to 10,000    | 2                               |                                          |
| From 10,000 to 50,000   | 5                               |                                          |
| From 5,000 to 50,000    |                                 |                                          |
| From 50,000 to 100,000  |                                 |                                          |
| From 50,000 to 300,000  |                                 |                                          |
| From 100,000 to 200,000 |                                 |                                          |
| From 100,000 to 300,000 |                                 |                                          |

### How would you express execution time as a function of input size (for **bubble sort**)?

### Using those results, fill in *this* table about **insertion sort**
| Insertion Sort             | Input increased by a factor of: | Execution time increased by a factor of: |
|----------------------------|---------------------------------|------------------------------------------|
| From 5,000 to 10,000       | 2                               |                                          |
| From 10,000 to 50,000      | 5                               |                                          |
| From 5,000 to 50,000       |                                 |                                          |
| From 50,000 to 100,000     |                                 |                                          |
| From 50,000 to 300,000     |                                 |                                          |
| From 100,000 to 200,000    |                                 |                                          |
| From 100,000 to 300,000    |                                 |                                          |

### How would you express execution time as a function of input size (for **insertion sort**)?

### Now do you see why bubble sort and insertion sort belong to **O(n^2)**?

#### Hint
 - To calculate the "factor" value for each column divide the 2nd number by the first.  I have filled in the first 2 under input size.  10,000 / 5,000 = 2.  Now divide the execution time for 10,000 by the execution time for 5000.