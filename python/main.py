# coding=utf-8
# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.

import sys
from termcolor import colored, cprint  # цветной cprint https://pypi.org/project/termcolor/
from collections import deque # двусторонняя очередь
# import Tkinter as tk
# from random import *
from tkinter import *
import grafix
import networkx as nx
import matplotlib.pyplot as plt
from sys import argv


def print_func_name(name):
    # end=" " - аттрибут, который меняет "\n" по-умолчанию на " ", чтобы принтилось в одну строку.
    cprint("func:", 'cyan', end=" ")
    cprint("{}\n".format(name), 'green')


def print_graph(graph):
    print_func_name('print graph')
    for row in graph:
        for item in row:
            cprint("row [{}]:".format(item), end=" ")
            cprint("->", 'grey', end=" ")
            cprint(row[item], 'white', end=" ")
            cprint("")


def init_graph(g):
    print_func_name('init graph')
    # open file
    file = open("../test", 'r')
    # print('im readed file: ', file.read())  # open all data
    check_start = 0
    check_end = 0
    for line in file:
        # cprint('curr line is: '+line, color='green')
        if line == '##start\n':
            # cprint('i found start!')
            # cprint(line, color='green', end=" ")
            check_start = 1
        elif line == '##end\n':
            # cprint('i found end!')
            # cprint(line, color='cyan', end=" ")
            check_end = 1
    if check_start == 1 and check_end == 1:
        cprint('start && end founded!', color='yellow')
    file = open("../test", 'r')
    line = file.readline()
    cprint(line)
    # add nodes
    g.add_node(1)
    g.add_node(2)
    g.add_node(3)
    g.add_node(4)
    # add edges
    g.add_edge(1, 2)
    g.add_edge(3, 1)
    g.add_edge(4, 1)
    # print("len g is: ", len(g))
    return [g]


if __name__ == '__main__':
    # init graph
    G = nx.Graph()
    init_graph(G)
    # print_graph(G)

    cprint(argv[1])  # print argv[1]
# ############################################# GRAFIX
    # grafix.init_window(G)

# ############################################# GRAFIX
    cprint("\nEND\n", 'magenta')
