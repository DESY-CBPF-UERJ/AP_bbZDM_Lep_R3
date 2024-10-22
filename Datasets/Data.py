analysis = "AP_bbZDM_Lep_R3"
nano_version = 'v12'
path_22 = analysis+'/Datasets/Files/data_22/'+nano_version+'/'
path_23 = analysis+'/Datasets/Files/data_23/'+nano_version+'/'

#--------------------------------------------------------------------------------------------------
# ID digits:
# 1st-2nd = 16(2016),17(2017),18(2018)                              # Year
# 3th-4th = 00(Data),01(MC-signal),02-13(MC-bkg),99(private sample) # Group
# 5th-6th = 00(none),...                                            # Bkg -> Process
# 5th-6th = 00(none),11(250_30),12(250_40),55(1250_100)             # Signal -> Signal point
# 5th-6th = 00(none),01(A),02(B),03(C)                              # Data -> Era
# 7th     = 0,1,2,...                                               # Data taking interval (DTI)

# 2022 DTIs = 0(preEE), 1(postEE)
# 2023 DTIs = 0(preBPix), 1(postBPix)
#--------------------------------------------------------------------------------------------------


Data_Lep_0_22 = [
["Data_SingleEle_C_0_22"]             + ['2200030', path_22+"SingleEle_C.txt"],
["Data_SingleMu_C_0_22"]              + ['2200230', path_22+"SingleMu_C.txt"],
]

Data_MET_0_22 = [
["Data_MET_C_0_22"]                   + ['2200530', path_22+"MET_C.txt"],
]

Data_Lep_1_22 = [
["Data_SingleEle_F_1_22"]             + ['2200071', path_22+"SingleEle_F.txt"],
["Data_SingleMu_F_1_22"]              + ['2200271', path_22+"SingleMu_F.txt"],
]

Data_MET_1_22 = [
["Data_MET_F_1_22"]                   + ['2200571', path_22+"MET_F.txt"],
]


Data_Lep_0_23 = [
["Data_SingleEle_C_0_23"]             + ['2300030', path_23+"SingleEle_C.txt"],
["Data_SingleMu_C_0_23"]              + ['2300230', path_23+"SingleMu_C.txt"],
]

Data_MET_0_23 = [
["Data_MET_C_0_23"]                   + ['2300530', path_23+"MET_C.txt"],
]

Data_Lep_1_23 = [
["Data_SingleEle_F_1_23"]             + ['2300071', path_23+"SingleEle_F.txt"],
["Data_SingleMu_F_1_23"]              + ['2300271', path_23+"SingleMu_F.txt"],
]

Data_MET_1_23 = [
["Data_MET_F_1_23"]                   + ['2300571', path_23+"MET_F.txt"],
]

