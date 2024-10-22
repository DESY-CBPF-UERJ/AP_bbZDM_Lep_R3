import os
import sys
import argparse

# List of datasets generated with the command below (example for MuonEG).
# dasgoclient --limit 0 --query 'dataset dataset=/MuonEG/*UL2016_MiniAODv1_NanoAODv2*/NANOAOD'

#======SETUP=======================================================================================
parser = argparse.ArgumentParser()
parser.add_argument("-v", "--version")
parser.set_defaults(version=12)
args = parser.parse_args()

if args.version != "12":
    print("Please, enter a valid version: 12")
    sys.exit()

if args.version == "12":
    campaign = "CMSSW_13_2_0-130X_dataRun3_v2_RelVal"

basedir = "data_22/v"+args.version+"/"
if os.path.isdir(basedir) is False:
    os.makedirs(basedir)

datasets = [
["SingleMu_C",      "/SingleMuon/" + campaign + "_2022C"],
]


for i in range(len(datasets)):
    file_name = basedir + datasets[i][0] + ".txt"
    for k in range(9):
        ds_name = datasets[i][1] + "-v" + str(k+1) + "/NANOAOD"
        if k == 0:
            command = "dasgoclient --limit 0 --query 'dataset dataset=" + ds_name + "' > " + "temp.txt"
        else:
            command = "dasgoclient --limit 0 --query 'dataset dataset=" + ds_name + "' >> " + "temp.txt"
        os.system(command)
    has_dataset = False
    k_lines = []
    with open("temp.txt", "r") as file:
        for line in file:
            has_dataset = True
            k_lines.append(line[0:-1])
    if has_dataset:
        for dataset_name in reversed(k_lines):
            command = "dasgoclient --limit 0 --query 'file dataset=" + dataset_name + "' > " + file_name
            os.system(command)
            NumLines = sum(1 for line in open(file_name))
            if NumLines > 0:
                print(dataset_name)
                break
    else:
        open(file_name, 'a').close()
        print(datasets[i][1] + " is not available!")
    os.system("rm temp.txt")

