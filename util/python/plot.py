import matplotlib.pyplot as plt
import pandas as pd

# Takes an array of CSV files and plots a graph with a given title.

def read_list(line):
    line = line.split(',')
    line = line[2:-1]
    return [float(x) for x in line]
def plot_graph(filename, title):
    plt.clf()
    single = []
    multi = []
    gpu = []
    with open(filename, 'r') as f:
        single = read_list(f.readline())
        multi = read_list(f.readline())
        gpu = read_list(f.readline())
        x = [x for x in range(len(single))]
    plt.plot(x, single, label='Reference')
    plt.plot(x, multi, label='Parallel')
    plt.plot(x, gpu, label='GPU')
    plt.legend()
    plt.title(title)
    # plt.show()
    plt.savefig(filename[:-3]+'svg')
def main():
    plot_graph("trans.csv", "Transversal histograms")
    plot_graph("long.csv", "Longitudinal histograms")

if __name__ == "__main__":
    main()
