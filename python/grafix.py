from tkinter import *
import networkx as nx



def about():
    a = Toplevel()
    a.geometry('600x600')
    a['bg'] = 'gray'
    a.overrideredirect(True)
    Label(a, text="This is a visualiser for lem in by a cghael && ksemele!").pack(expand=1)
    a.after(7000, lambda: a.destroy())  # autokill window after 1000 ms


def init_window(graph):
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

    Button(text="Button", width=20).pack()
    Label(text="Label", width=20, height=3).pack()
    Button(text="About", width=20, command=about).pack()

    root.mainloop()
