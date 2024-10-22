import os
import sys
import argparse

# List of datasets generated with the dasgoclient command.
# Example: dasgoclient --limit 0 --query 'dataset dataset=/QCD*/*22*v12*/NANOAODSIM'

#======SETUP=======================================================================================
parser = argparse.ArgumentParser()
parser.add_argument("-t", "--tag")
args = parser.parse_args()

campaign = "*"+args.tag+"*/NANOAODSIM"


datasets = [
"DYto2E_MLL-50to120_TuneCP5_13p6TeV_powheg-pythia8",
"DYto2Mu_MLL-50to120_TuneCP5_13p6TeV_powheg-pythia8",
"DYto2Tau_MLL-50to120_TuneCP5_13p6TeV_powheg-pythia8",
"DYto2E_MLL-120to200_TuneCP5_13p6TeV_powheg-pythia8",
"DYto2Mu_MLL-120to200_TuneCP5_13p6TeV_powheg-pythia8",
"DYto2Tau_MLL-120to200_TuneCP5_13p6TeV_powheg-pythia8",
"TTto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8",
"TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8",
"WZto3LNu_TuneCP5_13p6TeV_powheg-pythia8",
"ZZto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8",
"ZZto4L_TuneCP5_13p6TeV_powheg-pythia8",
"ZZto2L2Q_TuneCP5_13p6TeV_powheg-pythia8",
"ZZto2Nu2Q_TuneCP5_13p6TeV_powheg-pythia8",
"WZto2L2Q_TuneCP5_13p6TeV_powheg-pythia8",
"WZtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8",
"WWto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8",
"WWW_4F_TuneCP5_13p6TeV_amcatnlo-madspin-pythia8",
"WWZ_4F_TuneCP5_13p6TeV_amcatnlo-pythia8",
"WZZ_TuneCP5_13p6TeV_amcatnlo-pythia8",
"ZZZ_TuneCP5_13p6TeV_amcatnlo-pythia8",
"TWminusto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8",
]


print("#############################################################################################")
for i in range(len(datasets)):
    command = "dasgoclient --limit 0 --query 'dataset dataset=/" + datasets[i] + "*/" + campaign + "'"
    print(">>>> " + command)
    os.system(command)
    print(" ")
