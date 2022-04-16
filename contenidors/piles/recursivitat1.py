from easyinput import read
from collections import deque

stack = deque()

def work(n):
    stack.append(n)
    while not stack.empty():
        if stack.top() != 1:
            stack.pop()
            stack.append(stack.top() - 1)
            stack.append(stack.top() - 1)
        else:
            stack.pop()


def main():
    n = read(int)
    while n is not None:
        work(n)
        print()
        n = read(int)

main()
