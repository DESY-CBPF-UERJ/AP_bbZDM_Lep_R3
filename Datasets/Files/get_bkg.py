import os
import sys
import argparse


#======SETUP=======================================================================================
parser = argparse.ArgumentParser()
parser.add_argument("-v", "--version")
parser.add_argument("-p", "--period")
args = parser.parse_args()

dataset_code = args.period+"_"+args.version

datasets_available = ["0_16_9", "1_16_9", "0_17_9", "0_18_9", "0_22_12", "1_22_12", "0_23_12", "1_23_12"]

if dataset_code not in datasets_available:
    print("There is no dataset for")
    print("NanoAOD version = v"+args.version)
    print("Year = 20"+args.period[-2:])
    print("DTI = "+args.period[0])
    print("Type a period and a version present in the list below in which the elements are formed as period_version.")
    print(datasets_available)
    sys.exit()


if args.version == "9":
    if args.period == "0_16":
        campaign = "RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11"
    elif args.period == "1_16":
        campaign = "RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17"
    elif args.period == "0_17":
        campaign = "RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9"
    elif args.period == "0_18":
        campaign = "RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1"

if args.version == "12":
    if args.period == "0_22":
        campaign = "Run3Summer22NanoAODv12-130X_mcRun3_2022_realistic_v5"
    elif args.period == "1_22":
        campaign = "Run3Summer22EENanoAODv12-130X_mcRun3_2022_realistic_postEE_v6"
    elif args.period == "0_23":
        campaign = "Run3Summer23NanoAODv12-130X_mcRun3_2023_realistic_v14"
    elif args.period == "1_23":
        campaign = "Run3Summer23BPixNanoAODv12-130X_mcRun3_2023_realistic_postBPix_v2"


basedir = "bkg_"+args.period[-2:]+"/dti_"+args.period[0]+"/v"+args.version+"/"
if os.path.isdir(basedir) is False:
    os.makedirs(basedir)


datasets = [
["DYto2E_MLL-50to120",          ["/DYto2E_MLL-50to120_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["DYto2Mu_MLL-50to120",         ["/DYto2Mu_MLL-50to120_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["DYto2Tau_MLL-50to120",        ["/DYto2Tau_MLL-50to120_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["DYto2E_MLL-120to200",         ["/DYto2E_MLL-120to200_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["DYto2Mu_MLL-120to200",        ["/DYto2Mu_MLL-120to200_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["DYto2Tau_MLL-120to200",       ["/DYto2Tau_MLL-120to200_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["TTto2L2Nu",                   ["/TTto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["TTtoLNu2Q",                   ["/TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["WZto3LNu",                    ["/WZto3LNu_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["ZZto2L2Nu",                   ["/ZZto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["ZZto4L",                      ["/ZZto4L_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["ZZto2L2Q",                    ["/ZZto2L2Q_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["ZZto2Nu2Q",                   ["/ZZto2Nu2Q_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["WZto2L2Q",                    ["/WZto2L2Q_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["WZtoLNu2Q",                   ["/WZtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["WWto2L2Nu",                   ["/WWto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
["WWW",                         ["/WWW_4F_TuneCP5_13p6TeV_amcatnlo-madspin-pythia8/" + campaign]],
["WWZ",                         ["/WWZ_4F_TuneCP5_13p6TeV_amcatnlo-pythia8/" + campaign]],
["WZZ",                         ["/WZZ_TuneCP5_13p6TeV_amcatnlo-pythia8/" + campaign]],
["ZZZ",                         ["/ZZZ_TuneCP5_13p6TeV_amcatnlo-pythia8/" + campaign]],
["TWminusto2L2Nu",              ["/TWminusto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8/" + campaign]],
]

for i in range(len(datasets)):
    file_name = basedir + datasets[i][0] + ".txt"

    # Main dataset
    for k in range(9):
        ds_name = datasets[i][1] + "-v" + str(k+1) + "/NANOAODSIM"
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
    os.system("rm temp.txt")
    if has_dataset:
        k_value = 9
        for dataset_name in reversed(k_lines):
            command = "dasgoclient --limit 0 --query 'file dataset=" + dataset_name + "' > " + file_name
            os.system(command)
            NumLines = sum(1 for line in open(file_name))
            if NumLines > 0:
                print(dataset_name)
                break
            k_value = k_value - 1
    else:
        open(file_name, 'a').close()
        print(datasets[i][1] + " is not available!")

    # Extension
    ds_name = datasets[i][1] + "_ext*-v" + str(k_value) + "/NANOAODSIM"
    command = "dasgoclient --limit 0 --query 'dataset dataset=" + ds_name + "' > " + "temp.txt"
    os.system(command)
    has_dataset = False
    ext_lines = []
    with open("temp.txt", "r") as file:
        for line in file:
            has_dataset = True
            ext_lines.append(line[0:-1])
    os.system("rm temp.txt")
    if has_dataset:
        for dataset_name in ext_lines:
            command = "dasgoclient --limit 0 --query 'file dataset=" + dataset_name + "' >> " + file_name
            os.system(command)
            print(dataset_name)
