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
from pyparsing import *
import re


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
            check_start = 1
        elif line == '##end\n':
            check_end = 1
    if check_start == 1 and check_end == 1:
        cprint('start && end founded!', color='yellow')
    file = open("../test", 'r')
    line = file.readline()
    cprint("numbers of ant:"+line)

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

# START parsing mb need create class?
    cprint("open file: "+argv[1])  # print argv[1]
    file = open(argv[1])
    ants = int(file.readline())
    print("ANTS from argv:", ants)
    rooms = []
    check_start = 0
    check_end = 0
    for line in file:
        # start, end
        if check_start == 1:
            rooms.append("start->")
            check_start = 0
        if check_end == 1:
            rooms.append("end->")
            check_end = 0
        if line == '##start\n':
            check_start = 1
        elif line == '##end\n':
            check_end = 1
        if ' ' not in line and line[0] != '#':
            break
        if line[0] != '#':
            rooms.append(line.split())
    print(rooms)
    print(len(rooms))
    file = open(argv[1])
    links = []
    for line in file:
        if line[0] != '#' and '-' in line:
            line = ' '.join(line.split())  # remove '\n' for correctly splitting
            links.append(line.split(sep='-'))
    print(links)
    print(len(links))
# END parsing


# ############################################# GRAFIX
#     grafix.init_window(G)

# ############################################# GRAFIX
    cprint("\nEND\n", 'magenta')
