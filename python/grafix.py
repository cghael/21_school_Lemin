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
import support as s
import numpy as np
import buttons as btn


def ft_about():
    a = Toplevel()
    a.geometry('500x100')
    # a['bg'] = 'gray'
    a.overrideredirect(True)
    Label(a, text="This is a visualiser for lem in by a cghael && ksemele!").grid()
    a.after(1000, lambda: a.destroy())  # autokill window after 1000 ms


def ft_open_map():
    # destroy figure
    # open new .map
    # parse, draw
    s.ft_print_func_name("open map")


def ft_embed_graph(g, root):
    pos = nx.spring_layout(g)
    nx.draw(g, pos, node_color='g', with_labels=True)
    # red patch with Ants marker?
    red_patch = mpatches.Patch(color='red', label='Ants')
    plt.legend(handles=[red_patch])
    canvas = FigureCanvasTkAgg(plt.figure(1), master=root)
    canvas.draw()
    canvas.get_tk_widget().grid(row=1, columnspan=3, padx=5, pady=5)


def ft_destroy_graph():
    s.ft_print_func_name("destroy")


def ft_init_window(g):
    root = Tk()
    root.tk_setPalette('gray60')
    width = 650
    height = 500
    w = root.winfo_screenwidth()  # width of all screen
    h = root.winfo_screenheight()  # height of all screen
    w = w // 2  # for center on screen by a X
    h = h // 2
    w = w - width // 2
    h = h - height // 2
    root.geometry('650x530+{}+{}'.format(w, h))  # create window with shift
    root.title("lemin visualiser v 0.1")
# buttons
    Button(text="Open map", width=10, command=ft_open_map).grid(row=0, column=0, padx=5, pady=5)
    Button(text="About", width=10, command=ft_about).grid(row=0, column=1, padx=5, pady=5)
    Button(text="destroy", width=10, command=ft_destroy_graph).grid(row=0, column=2, padx=5, pady=5)
# end buttons
    print("len g is: ", len(g))  #todo
    ft_embed_graph(g, root)  # including graph ^^^
    root.mainloop()
