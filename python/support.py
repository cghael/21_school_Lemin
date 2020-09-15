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
    def __init__(self, graph, curr_node, start_name, end_name):
        self.graph = graph
        self.coords = []
        self.start_name = start_name
        self.end_name = end_name
        self.curr_node = 0

    def save_coords(self, curr_name, x, y):
        tmp_node = {}
        tmp_node['name'] = curr_name
        tmp_node['x'] = int(x)
        tmp_node['y'] = int(y)
        # print('curr_node: ', tmp_node['name'], tmp_node['x'], tmp_node['y'])
        self.coords.append(tmp_node)


def ft_print_func_name(name):
    # end=" " - аттрибут, который меняет "\n" по-умолчанию на " ", чтобы принтилось в одну строку.
    cprint("func:", 'cyan', end=" ")
    cprint("{}\n".format(name), 'green')


def ft_init_graph(argv):
    ft_print_func_name('init graph')
    g = nx.Graph()
    # coords = {}

    # open file
    cprint("open file: "+argv[1])  # print argv[1]
    file = open(argv[1])
    ants = int(file.readline())
    print("ANTS from argv:", ants)  # todo del

    data = ParsedData(g, 0, 0, 0)  # init data class

    rooms = []
    check_start = 0
    check_end = 0
    for line in file:
        # check & save start, end
        if check_start == 1:
            data.start_name = line.split().pop(0)
            print("start name: ", data.start_name)  # todo del
            check_start = 0
        if check_end == 1:
            data.end_name = line.split().pop(0)
            print("end name: ", data.end_name)  # todo del
            check_end = 0
        if line == '##start\n':
            check_start = 1
        elif line == '##end\n':
            check_end = 1
        if ' ' not in line and line[0] != '#':  # filter edges (links)
            break
        if line[0] != '#':
            rooms.append(line.split())
    print(rooms)  # todo del
    print(len(rooms))  # todo del
    file = open(argv[1])
    edges = []
    for line in file:
        if line[0] != '#' and '-' in line:
            line = ' '.join(line.split())  # remove '\n' for correctly splitting
            edges.append(line.split(sep='-'))
    print(edges)  # todo del
    print(len(edges))  # todo del
    # END parsing

    print("len g is: ", len(g))  # todo del
    # fill Graph from list && fill all node_names
    room_names = rooms.copy()
    for i in range(len(room_names)):
        curr_node = room_names.pop()
        curr_name = curr_node.pop(0)
        g.add_node(curr_name)
        y = curr_node.pop()
        x = curr_node.pop()
        data.save_coords(curr_name, x, y)
    print("nodes in g: ", g.nodes)  # todo del
    # fill all edges
    g.add_edges_from(edges)
    # end fill Graph
    print("len g is: ", len(g), "len rooms: ", len(rooms))  # todo del
    print(g.nodes(data=True))  # todo del
    # return [g]
    print('data!!!!', data.coords)  # todo del
    return data
