import matplotlib.pyplot as plt
import pandas as pd
import sys
# Takes an array of CSV files and plots a graph with a given title.
def plot_graph(filenames, title):
    xs = [[]]
    ys = [[]]
    for i in range(len(filenames)):
        df = pd.read_csv(filenames[i])
        matrix = df.to_numpy()
        xs.append([])
        ys.append([])
        for j in range(len(matrix)):
            xs[i].append(matrix[j][0])
            ys[i].append(matrix[j][1])
    plt.xlabel("r/t")
    plt.ylabel("$\mathregular{F_r}$(t, r)")
    plt.plot(xs[0], ys[0], label="Multithreaded")
    plt.plot(xs[1], ys[1], label="Reference")
    plt.legend()
    plt.title(title)
    plt.show()


def main(reference, test):
    names = [reference, test]
    filenames = []
    for name in names:
        filenames.append(name + '_transverse.csv')
        # filenames.append(name + '_longitudinal.csv')
    plot_graph(filenames, "A plot between reference and multithreaded transverse distributions")


if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
