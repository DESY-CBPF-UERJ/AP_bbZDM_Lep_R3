import os
import sys
import argparse

# List of datasets generated with the dasgoclient command.
# Example: dasgoclient --limit 0 --query 'dataset dataset=/MET*/*22*/NANOAOD'

#======SETUP=======================================================================================
parser = argparse.ArgumentParser()
parser.add_argument("-t", "--tag")
args = parser.parse_args()

campaign = "*"+args.tag+"*/NANOAOD"

datasets = [
"SingleMuon",
"SingleElectron",
"MET",
]

print("#############################################################################################")
for i in range(len(datasets)):
    command = "dasgoclient --limit 0 --query 'dataset dataset=/" + datasets[i] + "/*" + campaign + "'"
    print(">>>> " + command)
    os.system(command)
    print(" ")


