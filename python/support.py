import sys
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from termcolor import colored, cprint  # цветной cprint https://pypi.org/project/termcolor/
from tkinter import *
from tkinter.filedialog import askopenfilename
import networkx as nx
import matplotlib.pyplot as plt
from sys import argv
import os
import matplotlib.patches as mpatches


class GrafixStruct:
    def __init__(self, data):
        # grafix part
        self.root = Tk()
        self.fig = plt.figure(1, figsize=(5, 5), dpi=200, edgecolor='w', tight_layout=True)
        self.canvas = FigureCanvasTkAgg(figure=self.fig, master=self.root)
        if data != 0:
            self.pos = nx.spring_layout(data.graph)
        self.width = 1020
        self.height = 1060


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
        self.ants = 0
        self.start_ants = 0

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


def ft_init_graph(map, grafix):
    # ft_print_func_name('init graph')
    g = nx.Graph()
    data = ParsedData(g, 0, 0)  # init data class
    # open file
    if map == 'not map':
        cprint(map)
    if map != 'not map':
        cprint("open map: " + map)
        try:
            file = open(map)
        except FileNotFoundError:
            return
        data.start_ants = int(file.readline())
        data.ants = data.start_ants
        print("ANTS:", data.start_ants)  # todo del
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
        # print(rooms)  # todo del
        # print(len(rooms))  # todo del
        file = open(map)
        edges = []
        for line in file:
            if line[0] != '#' and '-' in line:
                line = ' '.join(line.split())  # remove '\n' for correctly splitting
                edges.append(line.split(sep='-'))
        # print(edges)  # todo del
        # print(len(edges))  # todo del
        # END parsing

        # print("len g is: ", len(g))  # todo del
        # fill Graph from list && fill all node_names
        room_names = rooms.copy()
        for i in range(len(room_names)):
            curr_node = room_names.pop()
            curr_name = curr_node.pop(0)
            g.add_node(curr_name)
            y = curr_node.pop()
            x = curr_node.pop()
            data.save_coords(curr_name, x, y)
        # print("nodes in g: ", g.nodes)  # todo del
        g.add_edges_from(edges)  # fill all edges
        # print("len g is: ", len(g), "len rooms: ", len(rooms))  # todo del
        # print('data!!!!', data.coords)  # todo del
        grafix.pos = nx.spring_layout(data.graph)
        for each in data.coords:
            grafix.pos[each['name']] = each['x'], each['y']  # fill XY coords from data
    return data


def ft_parse_solution(data):
    try:
        file = open(data.solution)
    except FileNotFoundError:
        data.solution_loaded = False
        return
    data.solution_loaded = True
    data.curr_ants = file.read().rstrip().split('\n')
    data.curr_ants.reverse()


def ft_open_solution(data, grafix):
    # new_solution
    # ft_print_func_name("open solution")
    grafix.root.attributes("-topmost", False)
    data.solution_loaded = True
    data.solution = askopenfilename()
    # print(data.solution)  # todo del
    ft_parse_solution(data)
    # print(data.curr_ants)  # todo del


def ft_open_map(data, grafix):
    grafix.root.attributes("-topmost", False)
    new_map = askopenfilename()  # open new *.map
    ft_print_func_name("open map")
    grafix.fig.clf()  # clear figure
    data = ft_init_graph(new_map, grafix)  # parse, draw
    data.solution_loaded = False
    ft_embed_graph(data, grafix)


def ft_embed_graph(data, grafix):
    # ft_print_func_name("embed graph")
    g = data.graph
    grafix.root.tk_setPalette('gray60')
    w = (grafix.root.winfo_screenwidth() // 2) - grafix.width // 2
    h = (grafix.root.winfo_screenheight() // 2) - grafix.height // 2
    grafix.root.attributes("-topmost", True)  # lift root to top of all windows
    grafix.root.geometry('1020x1060+{}+{}'.format(w, h))  # create window with shift
    grafix.root.title("lemin visualiser v 0.3")
    # draw graph
    nodes = nx.draw_networkx_nodes(g, grafix.pos,  node_color="gray", node_size=150)
    nx.draw_networkx_nodes(data.graph, grafix.pos, nodelist=[data.start_name], node_color='b', node_size=230)
    nx.draw_networkx_nodes(data.graph, grafix.pos, nodelist=[data.end_name], node_color='g', node_size=230)
    ant_patch = mpatches.Patch(color='red', label='Ants')
    start_patch = mpatches.Patch(color='b', label='Start')
    end_patch = mpatches.Patch(color='g', label='End')
    plt.legend(handles=[ant_patch, start_patch, end_patch])
    # nodes.set_edgecolor("black")
    nx.draw_networkx_labels(g, grafix.pos, font_size=8, font_color='k')
    nx.draw_networkx_edges(g, grafix.pos, edge_color='gray')
    grafix.canvas = FigureCanvasTkAgg(figure=grafix.fig, master=grafix.root)
    grafix.canvas.draw()
    grafix.canvas.get_tk_widget().grid(row=1, columnspan=3, padx=10, pady=10)
