from tkinter import *
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg, NavigationToolbar2Tk)
# Implement the default Matplotlib key bindings.
from matplotlib.backend_bases import key_press_handler
from matplotlib.figure import Figure

import tkinter
import numpy as np


def about():
    a = Toplevel()
    a.geometry('600x600')
    a['bg'] = 'gray'
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
    Label(text="Label", width=20, height=3).pack()
    Button(text="About", width=20, command=about).pack()

    print("len g is: ", len(g))
# graph plot
#     nx.draw(g, with_labels=True)
    nx.draw(g, node_color='green', edge_color='blue', with_labels=True)
    plt.show()
    root.mainloop()

    # root = tkinter.Tk()
    # root.wm_title("Embedding in Tk")
    #
    # fig = Figure(figsize=(5, 4), dpi=100)
    # t = np.arange(0, 3, .01)
    #
    # canvas = FigureCanvasTkAgg(fig, master=root)  # A tk.DrawingArea.
    # canvas.draw()
    # canvas.get_tk_widget().pack(side=tkinter.TOP, fill=tkinter.BOTH, expand=1)
    #
    # toolbar = NavigationToolbar2Tk(canvas, root)
    # toolbar.update()
    # canvas.get_tk_widget().pack(side=tkinter.TOP, fill=tkinter.BOTH, expand=1)
    #
    # def on_key_press(event):
    #     print("you pressed {}".format(event.key))
    #     key_press_handler(event, canvas, toolbar)
    # canvas.mpl_connect("key_press_event", on_key_press)
    #
    # def _quit():
    #     root.quit()  # stops mainloop
    #     root.destroy()  # this is necessary on Windows to prevent
    # # Fatal Python Error: PyEval_RestoreThread: NULL tstate
    # button = tkinter.Button(master=root, text="Quit", command=_quit)
    # button.pack(side=tkinter.BOTTOM)
    #
    # tkinter.mainloop()
# If you put root.destroy() here, it will cause an error if the window is
# closed with the window manager.
