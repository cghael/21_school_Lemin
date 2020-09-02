# coding=utf-8
# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.

import sys
from termcolor import colored, cprint  # цветной cprint https://pypi.org/project/termcolor/
from collections import deque # двусторонняя очередь
# import Tkinter as tk
# from random import *
from tkinter import *
import grafix
import networkx as nx
import matplotlib.pyplot as plt

def print_func_name(name):
    # end=" " - аттрибут, который меняет "\n" по-умолчанию на " ", чтобы принтилось в одну строку.
    cprint("func:", 'cyan', end=" ")
    cprint("{}\n".format(name), 'green')


def print_graph(graph):
    print_func_name('print graph')
    for row in graph:
        for item in row:
            cprint("row [{}]:".format(item), end=" ")
            cprint("->", 'grey', end=" ")
            cprint(row[item], 'white', end=" ")
            cprint("")


def init_graph():
    print_func_name('init graph')
    graph = {}
    graph["you"] = ["alice", "bob", "claire"]
    graph["bob"] = ["anuj", "peggy"]
    graph["alice"] = ["peggy"]
    graph["claire"] = ["tom", "jonny"]
    graph["anuj"] = []
    graph["peggy"] = []
    graph["tom"] = []
    graph["jonny"] = []
    return [graph]


if __name__ == '__main__':
    graph = init_graph()
    print_graph(graph)

    search_queue = deque()  # <- Соэдание новой очереди
    for each in graph:
        for elem in each:
            search_queue += each[elem]  # add elems in row from graph...

    while search_queue:
        person = search_queue.popleft()
        cprint(person, end=" ")
# ############################################# GRAFIX
    grafix.init_window(graph)
# ############################################# GRAFIX
    cprint("\nEND\n", 'magenta')
