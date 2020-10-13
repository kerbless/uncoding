import csv
import os

with open('dumpOUT-01.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    for row in csv_reader:
        print(', '.join(row))
with open('

os.remove('dumpOUT-01.csv')
