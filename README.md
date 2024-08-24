## Project Overview

The goal of the project is to make my own implementation of Bash `cat` and `grep` utilities in C language fully supporting all original flags, including paired combinations. 

## Key Parts

- I successfully implemented cat and grep in C, with full support for all flags and their combinations.
- I wrote unit-tests in Python and Bash to validate the corectness of project.
- Also I made Makefile to automate project build and testing.

## Usage

clone this repository

**cat**:

1. `cd s21_string.h/src/cat`
2. run `make all` to build project
3. run `make test` to run tests
   
**grep**:

1. `cd s21_string.h/src/grep`
2. run `make all` to build project
3. run `make test` to run tests

## cat options

`cat [OPTION] [FILE]`

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | numbers only non-empty lines |
| 2 | -e implies -v (GNU only: -E the same, but without implying -v) | but also display end-of-line characters as $  |
| 3 | -n (GNU: --number) | number all output lines |
| 4 | -s (GNU: --squeeze-blank) | squeeze multiple adjacent blank lines |
| 5 | -t implies -v (GNU: -T the same, but without implying -v) | but also display tabs as ^I  |

## grep options

`grep [OPTION] [TEMPLATE] [FILE]`

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -e | pattern |
| 2 | -i | Ignore uppercase vs. lowercase.  |
| 3 | -v | Invert match. |
| 4 | -c | Output count of matching lines only. |
| 5 | -l | Output matching files only.  |
| 6 | -n | Precede each matching line with a line number. |
| 7 | -h | Output matching lines without preceding them by file names. |
| 8 | -s | Suppress error messages about nonexistent or unreadable files. |
| 9 | -f file | Take regexes from a file. |