import matplotlib.pyplot as plt
import csv

x=[]
y=[]

with open('out_Shell.txt', 'r') as csvfile:
    plots= csv.reader(csvfile, delimiter=',')
    for row in plots:
        y.append(float(row[0]))
        x.append(float(row[1]))


plt.plot(x,y, c='r')

plt.title('Runtime vs size of array')

plt.xlabel('Size')
plt.ylabel('Rumtime')

plt.show()