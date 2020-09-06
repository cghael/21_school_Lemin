from tkinter import *
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg, NavigationToolbar2Tk)
# Implement the default Matplotlib key bindings.
from matplotlib.backend_bases import key_press_handler
from matplotlib.figure import Figure
import matplotlib.patches as mpatches


import tkinter
import numpy as np


def about():
    a = Toplevel()
    a.geometry('500x100')
    # a['bg'] = 'gray'
    a.overrideredirect(True)
    Label(a, text="This is a visualiser for lem in by a cghael && ksemele!").pack(expand=1)
    a.after(1000, lambda: a.destroy())  # autokill window after 1000 ms


def init_window(g):
    root = Tk()
    width = 600
    height = 600
    w = root.winfo_screenwidth()  # width of all screen
    h = root.winfo_screenheight()  # height of all screen
    # w = w // 2  # for center on screen
    h = h // 2
    w = w - width // 2
    h = h - height // 2
    root.geometry('600x600+{}+{}'.format(w, h))  # create window with shift
    root.title("lemin visualiser v 0.1")

    Button(text="Open map", width=20).pack()
    # Label(text="Имя карты?", width=20, height=3).pack()
    Button(text="About", width=20, command=about).pack()


    print("len g is: ", len(g))
# graph plot
#     nx.draw(g, with_labels=True)

    def embed_graph(g):
        pos = nx.spring_layout(g)
        nx.draw(g, pos, node_color='', edge_color='blue', with_labels=True)
        # red patch with Ants marker?
        red_patch = mpatches.Patch(color='red', label='Ants')
        plt.legend(handles=[red_patch])
        canvas = FigureCanvasTkAgg(plt.figure(1), master=root)
        canvas.draw()
        canvas.get_tk_widget().pack(side="top")

    embed_graph(g)
    root.mainloop()
