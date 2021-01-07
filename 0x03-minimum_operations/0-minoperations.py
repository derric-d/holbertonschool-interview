#!/usr/bin/python3
"""
function to get min steps needed to #n "h" characters
with just copy and paste
"""


def minOperations(n):
    """return num o ops needed"""
    i = 2
    res = 0

    if (n <= 1):
        return res

    while (i <= n // 2):
        if (n % i == 0):
            res += i
            n //= i
        else:
            i += 1

    return res + n
