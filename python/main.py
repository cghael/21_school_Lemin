#!/usr/bin/env python3
import sys
from sys import argv
from termcolor import colored, cprint  # цветной cprint https://pypi.org/project/termcolor/
import grafix as gx
import support as s
import tkinter as tk
from tkinter import *
from tkinter import ttk
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg, NavigationToolbar2Tk)
# Implement the default Matplotlib key bindings.
from matplotlib.backend_bases import key_press_handler
from matplotlib.figure import Figure
import matplotlib.patches as mpatches


if __name__ == '__main__':
    # init graph
    print('LEN ARGV', len(argv))
    if len(argv) == 2:
        data = s.ft_init_graph(argv[1])
    else:
        data = s.ft_init_graph('not map')

    g = data.graph
    root = Tk()
    root.tk_setPalette('gray60')
    width = 1020
    height = 1060
    w = root.winfo_screenwidth()  # width of all screen
    h = root.winfo_screenheight()  # height of all screen
    w = w // 2  # for center on screen by a X
    h = h // 2
    w = w - width // 2
    h = h - height // 2
    root.attributes("-topmost", True)  # lift root to top of all windows
    root.geometry('1020x1060+{}+{}'.format(w, h))  # create window with shift
    root.title("lemin visualiser v 0.2")

    fig = plt.figure(1, figsize=(5, 5), dpi=200, edgecolor='w', tight_layout=True)
    pos = nx.spring_layout(g)
    for each in data.coords:
        pos[each['name']] = each['x'], each['y']  # fill XY coords from data

    # draw graph
    nodes = nx.draw_networkx_nodes(g, pos,  node_color="gray", node_size=150)
    # nodes.set_edgecolor("black")
    nx.draw_networkx_labels(g, pos, font_size=8, font_color='k')
    nx.draw_networkx_edges(g, pos, edge_color='gray')

    # buttons
    Button(text="Open map", width=10, command=lambda: s.ft_open_map(fig, root)).grid(row=0, column=0, padx=5, pady=5)
    Button(text="Open solution", width=10, command=lambda: s.ft_open_solution(root, data)).grid(row=0, column=1, padx=5, pady=5)


    def ft_next_step(g, pos, fig, root, data, canvas):  # idk why, but this is work correctly!
        s.ft_print_func_name("next_step")
        if not data.solution_loaded:
            cprint('need open solution file!')
        else:
            cprint('open solution: ', end=' ', color='yellow')  # todo del
            print(data.solution)  # todo del
            data.g_ants.clear()
            # fig.clf()  # clear figure
            if data.curr_ants:
                ants = data.curr_ants.pop().split(' ')
                for each in ants:
                    each = ''.join(each).split('-')[-1:]  # todo
                    for ant in each:
                        data.g_ants.add_node(ant)
                print(data.g_ants.nodes)  # todo del
                print('CURR', ants)  # todo del
            else:
                s.ft_parse_solution(data)
                cprint('open solution: ', end=' ', color='yellow')  # todo del
                print(data.solution)  # todo del
                if data.curr_ants:
                    ants = data.curr_ants.pop().split(' ')
                    for each in ants:
                        each = ''.join(each).split('-')[-1:]  # todo
                        for ant in each:
                            data.g_ants.add_node(ant)
                    print(data.g_ants.nodes)  # todo del
                    print('CURR', ants)  # todo del
                print('NEXT', data.curr_ants.pop())  # todo del
            # draw graph
            nodes = nx.draw_networkx_nodes(g, pos, node_color="gray", node_size=150)
            # nodes.set_edgecolor("black")
            nx.draw_networkx_labels(g, pos, font_size=8, font_color='k')
            nx.draw_networkx_edges(g, pos, edge_color='gray')
            nx.draw_networkx_nodes(data.g_ants, pos, node_color="r", node_size=50)
            red_patch = mpatches.Patch(color='red', label='Ants')
            plt.legend(handles=[red_patch])
            canvas.draw()

    Button(text="Next step", width=10, command=lambda: ft_next_step(g, pos, fig, root, data, canvas)).grid(row=0, column=2, padx=5, pady=5)
    # end buttons

    canvas = FigureCanvasTkAgg(figure=fig, master=root)
    canvas.draw()
    canvas.get_tk_widget().grid(row=1, columnspan=3, padx=10, pady=10)
    print("len g is: ", len(g))  # todo del
    root.mainloop()
    cprint("\nEND\n", 'magenta')
