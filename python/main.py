#!/usr/bin/env python3
import sys
import os
from sys import argv
from termcolor import colored, cprint  # цветной cprint https://pypi.org/project/termcolor/
import support as s
import tkinter as tk
from tkinter import *
from tkinter import ttk
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg, NavigationToolbar2Tk)
# from matplotlib.figure import Figure
import matplotlib.patches as mpatches

if __name__ == '__main__':
    # init graph
    grafix = s.GrafixStruct(0)
    if len(argv) == 2:
        data = s.ft_init_graph(argv[1], grafix)
    else:
        data = s.ft_init_graph('./test', grafix)
    g = data.graph
    grafix.root.tk_setPalette('gray60')
    w = (grafix.root.winfo_screenwidth() // 2) - grafix.width // 2
    h = (grafix.root.winfo_screenheight() // 2) - grafix.height // 2
    grafix.root.attributes("-topmost", True)  # lift root to top of all windows
    grafix.root.geometry('1020x1060+{}+{}'.format(w, h))  # create window with shift
    grafix.root.title("lemin visualiser v 0.3")

    # draw graph
    nodes = nx.draw_networkx_nodes(g, grafix.pos,
                    node_color="gray", node_size=150)
    nx.draw_networkx_nodes(data.graph, grafix.pos,
                    nodelist=[data.start_name], node_color='b', node_size=230)
    nx.draw_networkx_nodes(data.graph, grafix.pos,
                    nodelist=[data.end_name], node_color='g', node_size=230)
    ant_patch = mpatches.Patch(color='red', label='Ants')
    start_patch = mpatches.Patch(color='b', label='Start')
    end_patch = mpatches.Patch(color='g', label='End')
    plt.legend(handles=[ant_patch, start_patch, end_patch])
    # nodes.set_edgecolor("black")
    nx.draw_networkx_labels(g, grafix.pos, font_size=8, font_color='k')
    nx.draw_networkx_edges(g, grafix.pos, edge_color='gray')

    # buttons
    Button(text="Open map", width=10, command=lambda:
            s.ft_open_map(data, grafix)).grid(row=0, column=0, padx=5, pady=5)
    Button(text="Open solution", width=10, command=lambda:
        s.ft_open_solution(data, grafix)).grid(row=0, column=1, padx=5, pady=5)

    def ft_next_step(data, grafix):  # idk why, but this is work correctly
        if not data.solution_loaded:
            cprint('need open solution file!')
        else:
            cprint('open solution: ', end=' ', color='yellow')  # todo del
            print(data.solution)  # todo del
            data.g_ants.clear()
            if data.curr_ants:
                ants = data.curr_ants.pop().split(' ')
                for each in ants:
                    each = ''.join(each).split('-')[-1:]  # todo
                    for ant in each:
                        data.g_ants.add_node(ant)
                        data.ants -= 1
                print('CURR', ants)  # todo del
            else:
                print('fucking ants end :)')
                # s.ft_parse_solution(data)
                # cprint('open solution: ', end=' ', color='yellow')  # todo del
                # data.ants = data.start_ants
                # print(data.solution)  # todo del
                # if data.curr_ants:
                #     ants = data.curr_ants.pop().split(' ')
                #     for each in ants:
                #         each = ''.join(each).split('-')[-1:]  # todo
                #         for ant in each:
                #             data.g_ants.add_node(ant)
                #             data.ants -= 1
                #     print('CURR', ants)  # todo del
            # draw graph
            nodes = nx.draw_networkx_nodes(g, grafix.pos,
                                            node_color="gray", node_size=150)
            nx.draw_networkx_labels(g, grafix.pos, font_size=8, font_color='k')
            nx.draw_networkx_edges(g, grafix.pos, edge_color='gray')
            nx.draw_networkx_nodes(data.g_ants, grafix.pos,
                                    node_color="r", node_size=60)
            if data.ants >= 0:
                # print('not all ants in route!')
                nx.draw_networkx_nodes(data.graph, grafix.pos,
                nodelist=[data.start_name], node_color="r", node_size=60)
            grafix.canvas.draw()

    Button(text="Next step", width=10, command=lambda: ft_next_step(data, grafix)).grid(row=0, column=2, padx=5, pady=0)
    # end buttons

    grafix.canvas = FigureCanvasTkAgg(figure=grafix.fig, master=grafix.root)
    grafix.canvas.draw()
    grafix.canvas.get_tk_widget().grid(row=2, columnspan=3, padx=10, pady=10)
    grafix.root.mainloop()
    cprint("\nEND working visualiser.\nhave a nice day! :)\n", 'magenta')
    sys.stderr.close()
