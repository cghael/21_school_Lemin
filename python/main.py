#!/usr/bin/env python3
import sys
from sys import argv
from termcolor import colored, cprint  # цветной cprint https://pypi.org/project/termcolor/
import grafix as gx
import support as s


if __name__ == '__main__':
    # init graph
    data = s.ft_init_graph(argv)
    # ############################### GRAFIX ##############################
    gx.ft_init_window(data)
    # ############################### GRAFIX ##############################
    cprint("\nEND\n", 'magenta')
