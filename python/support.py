import sys
from termcolor import colored, cprint  # цветной cprint https://pypi.org/project/termcolor/
# from collections import deque # двусторонняя очередь
# import Tkinter as tk
# from random import *
from tkinter import *
import networkx as nx
import matplotlib.pyplot as plt
from sys import argv
import grafix


class ParsedData:
    def __init__(self, graph, coords):
        self.graph = graph
        self.coords = coords


def ft_print_func_name(name):
    # end=" " - аттрибут, который меняет "\n" по-умолчанию на " ", чтобы принтилось в одну строку.
    cprint("func:", 'cyan', end=" ")
    cprint("{}\n".format(name), 'green')


def ft_init_graph(argv):
    ft_print_func_name('init graph')
    g = nx.Graph()
    # open file
    file = open("../test", 'r')
    # print('im readed file: ', file.read())  # open all data
    check_start = 0
    check_end = 0
    for line in file:
        if line == '##start\n':
            check_start = 1
        elif line == '##end\n':
            check_end = 1
    if check_start == 1 and check_end == 1:
        cprint('start && end founded!', color='yellow')
    cprint("open file: "+argv[1])  # print argv[1]
    file = open(argv[1])
    ants = int(file.readline())
    print("ANTS from argv:", ants)
    rooms = []
    check_start = 0
    check_end = 0
    for line in file:
        # check & save start, end
        if check_start == 1:
            start_name = line.split().pop(0)
            print("start name: ", start_name)
            check_start = 0
        if check_end == 1:
            end_name = line.split().pop(0)
            print("end name: ", end_name)
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
    edges = []
    for line in file:
        if line[0] != '#' and '-' in line:
            line = ' '.join(line.split())  # remove '\n' for correctly splitting
            edges.append(line.split(sep='-'))
    print(edges)
    print(len(edges))
    # END parsing
    print("len g is: ", len(g))
    # fill Graph from list && fill all node_names
    r_names = rooms.copy()
    for i in range(len(r_names)):
        g.add_node(r_names.pop().pop(0))
    print("nodes in g: ", g.nodes)
    # fill all edges
    g.add_edges_from(edges)
    # end fill Graph
    print("len g is: ", len(g), "len rooms: ", len(rooms))
    print(g.nodes(data=True))
    # return [g]
    data = ParsedData(g, edges)
    return data
