# Sequence A001155 Generator
This program will generate a specified number of entries in Sequence A001155 as defined in the OEIS library.
https://oeis.org/A001155

This sequence reads the previous sequence and uses the frequency of similar numbers to generate the next.
For example, starting at 0:
- 0
- 10 (because there is 1 0)
- 1110 (because there is 1 1 and 1 0)
- 3110 (because there are 3 1s and 1 0)
- 132110 (because there is 1 3, 2 1s, and 1 0)

Note that none of these inputs are valid since they do not exist in the function; I use them here to demonstrate how the sequence works.

The program is compiled through normal means.
