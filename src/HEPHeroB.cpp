#include "HEPHero.h"


//---------------------------------------------------------------------------------------------------------------
// FILL CONTROL VARIABLES WITH INPUT FILE LINES
//---------------------------------------------------------------------------------------------------------------
void HEPHero::FillControlVariables( string key, string value){

    //----CORRECTIONS------------------------------------------------------------------------------------


    //----METADATA FILES---------------------------------------------------------------------------------


    //----SELECTION--------------------------------------------------------------------------------------


}


//---------------------------------------------------------------------------------------------------------------
// Init
//---------------------------------------------------------------------------------------------------------------
bool HEPHero::Init() {
    
    //======SET HISTOGRAMS STYLE===================================================================
    setStyle(1.0,true,0.15);

    if( _ANALYSIS != "GEN" ){
        //======SET THE BRANCH ADDRESSES===============================================================
        _inputTree->SetBranchAddress("run", &run);
        _inputTree->SetBranchAddress("luminosityBlock", &luminosityBlock);
        _inputTree->SetBranchAddress("event", &event);
        _inputTree->SetBranchAddress("bunchCrossing", &bunchCrossing);

        _inputTree->SetBranchAddress("nFatJet", &nFatJet);
        _inputTree->SetBranchAddress("FatJet_jetId", &FatJet_jetId);
        _inputTree->SetBranchAddress("FatJet_nConstituents", &FatJet_nConstituents);
        _inputTree->SetBranchAddress("FatJet_subJetIdx1", &FatJet_subJetIdx1);
        _inputTree->SetBranchAddress("FatJet_subJetIdx2", &FatJet_subJetIdx2);
        _inputTree->SetBranchAddress("FatJet_electronIdx3SJ", &FatJet_electronIdx3SJ);
        _inputTree->SetBranchAddress("FatJet_muonIdx3SJ", &FatJet_muonIdx3SJ);
        _inputTree->SetBranchAddress("FatJet_area", &FatJet_area);
        _inputTree->SetBranchAddress("FatJet_btagDDBvLV2", &FatJet_btagDDBvLV2);
        _inputTree->SetBranchAddress("FatJet_btagDDCvBV2", &FatJet_btagDDCvBV2);
        _inputTree->SetBranchAddress("FatJet_btagDDCvLV2", &FatJet_btagDDCvLV2);
        _inputTree->SetBranchAddress("FatJet_btagDeepB", &FatJet_btagDeepB);
        _inputTree->SetBranchAddress("FatJet_btagHbb", &FatJet_btagHbb);
        _inputTree->SetBranchAddress("FatJet_eta", &FatJet_eta);
        _inputTree->SetBranchAddress("FatJet_mass", &FatJet_mass);
        _inputTree->SetBranchAddress("FatJet_msoftdrop", &FatJet_msoftdrop);
        _inputTree->SetBranchAddress("FatJet_n2b1", &FatJet_n2b1);
        _inputTree->SetBranchAddress("FatJet_n3b1", &FatJet_n3b1);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_H4qvsQCD", &FatJet_particleNetWithMass_H4qvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_HbbvsQCD", &FatJet_particleNetWithMass_HbbvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_HccvsQCD", &FatJet_particleNetWithMass_HccvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_QCD", &FatJet_particleNetWithMass_QCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_TvsQCD", &FatJet_particleNetWithMass_TvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_WvsQCD", &FatJet_particleNetWithMass_WvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_ZvsQCD", &FatJet_particleNetWithMass_ZvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_QCD", &FatJet_particleNet_QCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_QCD0HF", &FatJet_particleNet_QCD0HF);
        _inputTree->SetBranchAddress("FatJet_particleNet_QCD1HF", &FatJet_particleNet_QCD1HF);
        _inputTree->SetBranchAddress("FatJet_particleNet_QCD2HF", &FatJet_particleNet_QCD2HF);
        _inputTree->SetBranchAddress("FatJet_particleNet_XbbVsQCD", &FatJet_particleNet_XbbVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XccVsQCD", &FatJet_particleNet_XccVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XggVsQCD", &FatJet_particleNet_XggVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XqqVsQCD", &FatJet_particleNet_XqqVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XteVsQCD", &FatJet_particleNet_XteVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XtmVsQCD", &FatJet_particleNet_XtmVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XttVsQCD", &FatJet_particleNet_XttVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_massCorr", &FatJet_particleNet_massCorr);
        _inputTree->SetBranchAddress("FatJet_phi", &FatJet_phi);
        _inputTree->SetBranchAddress("FatJet_pt", &FatJet_pt);
        _inputTree->SetBranchAddress("FatJet_rawFactor", &FatJet_rawFactor);
        _inputTree->SetBranchAddress("FatJet_tau1", &FatJet_tau1);
        _inputTree->SetBranchAddress("FatJet_tau2", &FatJet_tau2);
        _inputTree->SetBranchAddress("FatJet_tau3", &FatJet_tau3);
        _inputTree->SetBranchAddress("FatJet_tau4", &FatJet_tau4);
        _inputTree->SetBranchAddress("FatJet_lsf3", &FatJet_lsf3);

        _inputTree->SetBranchAddress("nJet", &nJet);
        _inputTree->SetBranchAddress("Jet_jetId", &Jet_jetId);
        _inputTree->SetBranchAddress("Jet_nConstituents", &Jet_nConstituents);
        _inputTree->SetBranchAddress("Jet_nElectrons", &Jet_nElectrons);
        _inputTree->SetBranchAddress("Jet_nMuons", &Jet_nMuons);
        _inputTree->SetBranchAddress("Jet_nSVs", &Jet_nSVs);
        _inputTree->SetBranchAddress("Jet_electronIdx1", &Jet_electronIdx1);
        _inputTree->SetBranchAddress("Jet_electronIdx2", &Jet_electronIdx2);
        _inputTree->SetBranchAddress("Jet_muonIdx1", &Jet_muonIdx1);
        _inputTree->SetBranchAddress("Jet_muonIdx2", &Jet_muonIdx2);
        _inputTree->SetBranchAddress("Jet_svIdx1", &Jet_svIdx1);
        _inputTree->SetBranchAddress("Jet_svIdx2", &Jet_svIdx2);
        _inputTree->SetBranchAddress("Jet_hfadjacentEtaStripsSize", &Jet_hfadjacentEtaStripsSize);
        _inputTree->SetBranchAddress("Jet_hfcentralEtaStripSize", &Jet_hfcentralEtaStripSize);
        _inputTree->SetBranchAddress("Jet_PNetRegPtRawCorr", &Jet_PNetRegPtRawCorr);
        _inputTree->SetBranchAddress("Jet_PNetRegPtRawCorrNeutrino", &Jet_PNetRegPtRawCorrNeutrino);
        _inputTree->SetBranchAddress("Jet_PNetRegPtRawRes", &Jet_PNetRegPtRawRes);
        _inputTree->SetBranchAddress("Jet_area", &Jet_area);
        _inputTree->SetBranchAddress("Jet_btagDeepFlavB", &Jet_btagDeepFlavB);
        _inputTree->SetBranchAddress("Jet_btagDeepFlavCvB", &Jet_btagDeepFlavCvB);
        _inputTree->SetBranchAddress("Jet_btagDeepFlavCvL", &Jet_btagDeepFlavCvL);
        _inputTree->SetBranchAddress("Jet_btagDeepFlavQG", &Jet_btagDeepFlavQG);
        _inputTree->SetBranchAddress("Jet_btagPNetB", &Jet_btagPNetB);
        _inputTree->SetBranchAddress("Jet_btagPNetCvB", &Jet_btagPNetCvB);
        _inputTree->SetBranchAddress("Jet_btagPNetCvL", &Jet_btagPNetCvL);
        _inputTree->SetBranchAddress("Jet_btagPNetQvG", &Jet_btagPNetQvG);
        _inputTree->SetBranchAddress("Jet_btagPNetTauVJet", &Jet_btagPNetTauVJet);
        _inputTree->SetBranchAddress("Jet_btagRobustParTAK4B", &Jet_btagRobustParTAK4B);
        _inputTree->SetBranchAddress("Jet_btagRobustParTAK4CvB", &Jet_btagRobustParTAK4CvB);
        _inputTree->SetBranchAddress("Jet_btagRobustParTAK4CvL", &Jet_btagRobustParTAK4CvL);
        _inputTree->SetBranchAddress("Jet_btagRobustParTAK4QG", &Jet_btagRobustParTAK4QG);
        _inputTree->SetBranchAddress("Jet_chEmEF", &Jet_chEmEF);
        _inputTree->SetBranchAddress("Jet_chHEF", &Jet_chHEF);
        _inputTree->SetBranchAddress("Jet_eta", &Jet_eta);
        _inputTree->SetBranchAddress("Jet_hfsigmaEtaEta", &Jet_hfsigmaEtaEta);
        _inputTree->SetBranchAddress("Jet_hfsigmaPhiPhi", &Jet_hfsigmaPhiPhi);
        _inputTree->SetBranchAddress("Jet_mass", &Jet_mass);
        _inputTree->SetBranchAddress("Jet_muEF", &Jet_muEF);
        _inputTree->SetBranchAddress("Jet_muonSubtrFactor", &Jet_muonSubtrFactor);
        _inputTree->SetBranchAddress("Jet_neEmEF", &Jet_neEmEF);
        _inputTree->SetBranchAddress("Jet_neHEF", &Jet_neHEF);
        _inputTree->SetBranchAddress("Jet_phi", &Jet_phi);
        _inputTree->SetBranchAddress("Jet_pt", &Jet_pt);
        _inputTree->SetBranchAddress("Jet_rawFactor", &Jet_rawFactor);
        

        
        //-----------------------------------------------------------------------------------------------------------------------
        if( dataset_group != "Data" ) {
            _inputTree->SetBranchAddress("nGenJetAK8", &nGenJetAK8);
            _inputTree->SetBranchAddress("GenJetAK8_eta", &GenJetAK8_eta);
            _inputTree->SetBranchAddress("GenJetAK8_mass", &GenJetAK8_mass);
            _inputTree->SetBranchAddress("GenJetAK8_phi", &GenJetAK8_phi);
            _inputTree->SetBranchAddress("GenJetAK8_pt", &GenJetAK8_pt);

            _inputTree->SetBranchAddress("nGenJet", &nGenJet);
            _inputTree->SetBranchAddress("GenJet_eta", &GenJet_eta);
            _inputTree->SetBranchAddress("GenJet_mass", &GenJet_mass);
            _inputTree->SetBranchAddress("GenJet_phi", &GenJet_phi);
            _inputTree->SetBranchAddress("GenJet_pt", &GenJet_pt);

            _inputTree->SetBranchAddress("nGenPart", &nGenPart);
            _inputTree->SetBranchAddress("GenPart_genPartIdxMother", &GenPart_genPartIdxMother);
            _inputTree->SetBranchAddress("GenPart_statusFlags", &GenPart_statusFlags);
            _inputTree->SetBranchAddress("GenPart_pdgId", &GenPart_pdgId);
            _inputTree->SetBranchAddress("GenPart_status", &GenPart_status);
            _inputTree->SetBranchAddress("GenPart_eta", &GenPart_eta);
            _inputTree->SetBranchAddress("GenPart_mass", &GenPart_mass);
            _inputTree->SetBranchAddress("GenPart_phi", &GenPart_phi);
            _inputTree->SetBranchAddress("GenPart_pt", &GenPart_pt);

            _inputTree->SetBranchAddress("nSubGenJetAK8", &nSubGenJetAK8);
            _inputTree->SetBranchAddress("SubGenJetAK8_eta", &SubGenJetAK8_eta);
            _inputTree->SetBranchAddress("SubGenJetAK8_mass", &SubGenJetAK8_mass);
            _inputTree->SetBranchAddress("SubGenJetAK8_phi", &SubGenJetAK8_phi);
            _inputTree->SetBranchAddress("SubGenJetAK8_pt", &SubGenJetAK8_pt);

            _inputTree->SetBranchAddress("genWeight", &genWeight);
            _inputTree->SetBranchAddress("LHEWeight_originalXWGTUP", &LHEWeight_originalXWGTUP);
            _inputTree->SetBranchAddress("nLHEPdfWeight", &nLHEPdfWeight);
            _inputTree->SetBranchAddress("LHEPdfWeight", &LHEPdfWeight);
            _inputTree->SetBranchAddress("nLHEReweightingWeight", &nLHEReweightingWeight);
            _inputTree->SetBranchAddress("LHEReweightingWeight", &LHEReweightingWeight);
            _inputTree->SetBranchAddress("nLHEScaleWeight", &nLHEScaleWeight);
            _inputTree->SetBranchAddress("LHEScaleWeight", &LHEScaleWeight);
            _inputTree->SetBranchAddress("nPSWeight", &nPSWeight);
            _inputTree->SetBranchAddress("PSWeight", &PSWeight);
            

        }

    }

    return true;
}


//---------------------------------------------------------------------------------------------------------------
// Weight corrections
//---------------------------------------------------------------------------------------------------------------
void HEPHero::Weight_corrections(){

    //pileup_wgt = 1.;

    if(dataset_group != "Data"){

        /*
        if( apply_pileup_wgt ){
            pileup_wgt = GetPileupWeight(Pileup_nTrueInt, "nominal");
            evtWeight *= pileup_wgt;
        }
        */
    }
}


//---------------------------------------------------------------------------------------------------------------
// Get size of vertical systematic weights
// Keep the same order used in runSelection.py
//---------------------------------------------------------------------------------------------------------------
void HEPHero::VerticalSysSizes( ){
    if( (_sysID_lateral == 0) && (dataset_group != "Data") ) {
        sys_vertical_size.clear();
        _inputTree->GetEntry(0);

        //get_Pileup_sfs = false;

        for( int ivert = 0; ivert < _sysNames_vertical.size(); ++ivert ){
            string sysName = _sysNames_vertical.at(ivert);

            /*
            if( sysName == "Pileup" ){
                sys_vertical_size.push_back(2);
                get_Pileup_sfs = true;
            }
            */
        }
    }
}


//---------------------------------------------------------------------------------------------------------------
// Vertical systematics
// Keep the same order used in runSelection.py
//---------------------------------------------------------------------------------------------------------------
void HEPHero::VerticalSys(){
    if( (_sysID_lateral == 0) && (dataset_group != "Data") ) {
        sys_vertical_sfs.clear();

        //-----------------------------------------------------------------------------------
        /*
        if( get_Pileup_sfs ){
            vector<float> Pileup_sfs;
            double pileup_wgt_down = GetPileupWeight(Pileup_nTrueInt, "down");
            double pileup_wgt_up = GetPileupWeight(Pileup_nTrueInt, "up");
            Pileup_sfs.push_back(pileup_wgt_down/pileup_wgt);
            Pileup_sfs.push_back(pileup_wgt_up/pileup_wgt);
            sys_vertical_sfs.insert(pair<string, vector<float>>("Pileup", Pileup_sfs));
        }
        */
    }
}



//---------------------------------------------------------------------------------------------------------------
// MCsamples processing
//---------------------------------------------------------------------------------------------------------------
bool HEPHero::MC_processing(){

    bool pass_cut = true;
    string dsName = _datasetName.substr(0,_datasetName.length()-5);



    return pass_cut;
}


//---------------------------------------------------------------------------------------------------------------
// ANAFILES' ROUTINES
//---------------------------------------------------------------------------------------------------------------
void HEPHero::SetupAna(){
    if( false );
    else if( _SELECTION == "Test" ) SetupTest();
    // SETUP YOUR SELECTION HERE
    else {
      cout << "Unknown selection requested. Exiting. " << endl;
      return;
    }
}

bool HEPHero::AnaRegion(){
    bool Selected = true;
    if( _SELECTION == "Test" && !TestRegion() ) Selected = false;
    // SET THE REGION OF YOUR SELECTION HERE

    return Selected;
}

void HEPHero::AnaSelection(){
    if( _SELECTION == "Test" ) TestSelection();
    // CALL YOUR SELECTION HERE
}

void HEPHero::AnaSystematic(){
    if( _SELECTION == "Test" ) TestSystematic();
    // PRODUCE THE SYSTEMATIC OF YOUR SELECTION HERE
}

void HEPHero::FinishAna(){
    if( _SELECTION == "Test" ) FinishTest();
    // FINISH YOUR SELECTION HERE
}
   




