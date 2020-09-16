#!/usr/bin/env python3
import sys
from sys import argv
from termcolor import colored, cprint  # цветной cprint https://pypi.org/project/termcolor/
import grafix as gx
import support as s


if __name__ == '__main__':
    # init graph
    print('LEN ARGV', len(argv))
    if (len(argv) == 2):
        data = s.ft_init_graph(argv[1])
        gx.ft_init_window(data)
    else:
        data = s.ft_init_graph('not map')
        gx.ft_init_window(data)

    cprint("\nEND\n", 'magenta')
