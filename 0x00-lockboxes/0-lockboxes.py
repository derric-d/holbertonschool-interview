#!/usr/bin/python3


def canUnlockAll(boxes):

    if len(boxes) == 0:
        return True

    keys = [0]
    checked = [0]

    while keys:
        curr_b = keys.pop()
        for key in boxes[curr_b]:
            if type(key) == int\
                    and 0 <= key < len(boxes)\
                    and key not in checked:
                keys.append(key)
                checked.append(key)

    return len(boxes) == len(checked)
