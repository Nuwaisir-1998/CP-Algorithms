import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

s = [*set(map(int,input().split()))]
s.sort(key=lambda x:x if x%2 else 10**10-x)
print(*s)