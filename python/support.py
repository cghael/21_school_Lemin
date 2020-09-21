import sys
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from termcolor import colored, cprint  # цветной cprint https://pypi.org/project/termcolor/
from tkinter import *
from tkinter.filedialog import askopenfilename
import networkx as nx
import matplotlib.pyplot as plt
from sys import argv
import grafix
import os
import matplotlib.patches as mpatches


class ParsedData:
    def __init__(self, graph, start_name, end_name):
        self.graph = graph
        self.coords = []
        self.start_name = start_name
        self.end_name = end_name
        self.curr_node = 0
        self.solution_loaded = False
        self.solution = []
        self.curr_ants = []
        self.g_ants = nx.Graph()
        # self.ant = 0

    def save_coords(self, curr_name, x, y):
        tmp_node = {}
        tmp_node['name'] = curr_name
        tmp_node['x'] = int(x)
        tmp_node['y'] = int(y)
        self.coords.append(tmp_node)


def ft_print_func_name(name):  # todo del
    # end=" " - аттрибут, который меняет "\n" по-умолчанию на " ", чтобы принтилось в одну строку.
    cprint("func:", 'cyan', end=" ")
    cprint("{}\n".format(name), 'green')


def ft_init_graph(map):
    ft_print_func_name('init graph')
    g = nx.Graph()
    data = ParsedData(g, 0, 0)  # init data class

    # open file
    if map == 'not map':
        cprint(map)

    if map != 'not map':
        cprint("open file: " + map)
        file = open(map)
        ants = int(file.readline())
        print("ANTS from argv:", ants)  # todo del
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
        file = open(map)
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
        print('data!!!!', data.coords)  # todo del
    return data


def ft_open_map(fig, root):
    root.attributes("-topmost", False)
    new_map = askopenfilename()  # open new *.map
    ft_print_func_name("open map")
    fig.clf()  # clear figure
    fig.clear()
    plt.close(fig)
    data = ft_init_graph(new_map)  # parse, draw
    ft_embed_graph(data, root)


def ft_parse_solution(data):
    file = open(data.solution)
    data.solution_loaded = True
    data.curr_ants = file.read().rstrip().split('\n')
    data.curr_ants.reverse()


def ft_open_solution(root, data):
    # new_solution
    ft_print_func_name("open solution")
    root.attributes("-topmost", False)
    data.solution_loaded = True
    data.solution = askopenfilename()
    print(data.solution)  # todo del
    ft_parse_solution(data)
    print(data.curr_ants)  # todo del


def ft_embed_graph(data, root):
    g = data.graph
    fig = plt.figure(1, figsize=(5, 5), dpi=200, edgecolor='w', tight_layout=True)
    pos = nx.spring_layout(g)
    for each in data.coords:
        pos[each['name']] = each['x'], each['y']  # fill XY coords from data

    # draw graph
    nodes = nx.draw_networkx_nodes(g, pos,  node_color="gray", node_size=100)
    # nodes.set_edgecolor("black")
    nx.draw_networkx_labels(g, pos, font_size=8, font_color='k')
    nx.draw_networkx_edges(g, pos, edge_color='gray')

    # red patch with Ants marker?
    # red_patch = mpatches.Patch(color='red', label='Ants')
    # plt.legend(handles=[red_patch])

    canvas = FigureCanvasTkAgg(figure=fig, master=root)
    canvas.draw()
    canvas.get_tk_widget().grid(row=1, columnspan=3, padx=10, pady=10)


