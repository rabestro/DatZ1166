# Lab. H10

Create program in C++ using STD map. For details see Lab requirements.

H10. Read text from two given text files. Text in both given file contains identified words. One line in file is one word in format
`<integer ID> <Word max 30 characters>`

  - Merge both files in third file. 
  - Print data in third file in descending order by ID value. 
  - The same ID may not appear twice in third file. 
  - If two words have the same ID, concatenate them in third file.

## Test case

### one.txt

```
10 test
11 hello
13 bike
9 world
27 deep
23 bar
```

### two.txt

```
4 test2
11 ---hello
12 drum
9 2-world
23 blue
25 brown
```

### out.txt

```
4 test2
9 world2-world
10 test
11 hello---hello
12 drum
13 bike
23 barblue
25 brown
27 deep
```
