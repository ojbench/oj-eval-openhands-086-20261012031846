# Problem 086 - 交换树节点

**ACMOJ Problem ID**: 2049

## Table of Contents

- [Problem 086 - 交换树节点](#problem-086-交换树节点)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **2049. 交换树节点** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/086/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

助教M给大家出了一道主要考察基础知识点的题目。

相信大家都已经知道二叉树，也了解了左子树、右子树的概念。在抛出问题之前，我们先明确二叉树上深度(depth)的概念。对于一棵二叉树$T$，定义
* 根节点的深度为$1$
* 其它节点的深度=其父节点的深度+1

其次，给出一个好玩儿的**交换**操作，它的定义如下：对于树$T$上的节点$n$，对$n$实行交换操作后，它的左右子树互换，即$n$的左子树变成右子树，右子树变成左子树。下图是一个对节点$1$实行变换操作的示例：

![](https://img1.imgtp.com/2023/11/07/e8CjTeV5.jpg)

助教M觉得无聊，给了一棵树$T$，想让你对这棵树$T$中的一些节点执行**交换**操作。具体来说，小M每给出一个正整数$k$，你需要对$T$上所有深度是$k$的倍数的节点执行**交换操作**。执行完操作后，小M需要知道这棵树变化后的**中序遍历**结果。

注：小M会给你好多整数$k$，对于每个$k$，操作完后这棵树不需要再恢复原状，而是继续操作。

### Input Format

第一行是一个正整数$n$，表示给定树的节点数目。

接下来$n$行每行会有两个空格间隔的正整数: $a$, $b$。其中，第$i(i=1,2,...,n)$行的两个数$a$和$b$表示第$i$个节点的左儿子和右儿子分别是第$a$和$b$个节点，$-1$表示空节点。

下一行给出一个正整数$t$，表示小$M$会给出的整数$k$的个数。

接下来$t$行每行一个正整数，表示小M按照顺序给的正整数$k$。

### Output Format

对于小M给的每个正整数$k$，输出交换操作完后的树的中序遍历序列，空格间隔。

注意：最后一个节点后有空格也没关系。

### Samples

#### Sample 1

**Input:**
```
3
2 3
-1 -1
-1 -1
2
1
1
```

**Output:**
```
3 1 2
2 1 3
```

### Data Constraints

$1\le n \le 1024$

$1\le t \le 100 $

$1\le k \le n$

$a=-1$ 或 $2\le a \le n$

$b=-1$ 或 $2\le b \le n$

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 1000 ms
- **Memory Limit (per test case)**: 244 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/086/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
