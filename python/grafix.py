import tkinter as tk
from tkinter import *
from tkinter import ttk
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg, NavigationToolbar2Tk)
# Implement the default Matplotlib key bindings.
from matplotlib.backend_bases import key_press_handler
from matplotlib.figure import Figure
import support as s


def ft_init_window(data):
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
    root.title("lemin visualiser v 0.1")
    s.ft_embed_graph(data, root)  # including graph
    print("len g is: ", len(g))  # todo del
    root.mainloop()
