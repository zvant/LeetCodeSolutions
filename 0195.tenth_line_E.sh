# https://leetcode.com/problems/tenth-line/description/
# 2016/08
# 12 ms

# Read from the file file.txt and output the tenth line to stdout.
cat -n -b file.txt | grep ' 10[^0-9]' | cut -f2-
