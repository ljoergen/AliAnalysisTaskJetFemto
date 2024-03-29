#ifndef AliAnalysisTaskJetFemto_cxx
#define AliAnalysisTaskJetFemto_cxx

//======================== Jet Femtoscopy ========================//
//                                                                //
//    Reconstructing jets and performing a femtoscopic analysis   //
//             on them to find the source size in jets             //
//                                                                //
//================================================================//

#include "AliAnalysisTaskSE.h"
#include "AliMultSelection.h"
#include "AliAnalysisUtils.h"
#include "AliAODTrackSelection.h"
#include "AliAnalysisTask.h"
#include "AliPIDResponse.h"
#include "AliESDtrackCuts.h"
#include "AliAODVertex.h"
#include "AliEventCuts.h"
#include "AliAODEvent.h"
#include "AliAODTrack.h"
#include "TObjString.h"
#include "THnSparse.h"
#include "TList.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include <vector>

//___________________________________________________________________________________________________________________________________________
class AliAnalysisTaskJetFemto : public AliAnalysisTaskSE {

public:
    AliAnalysisTaskJetFemto();
    AliAnalysisTaskJetFemto(const char *name);
    virtual ~AliAnalysisTaskJetFemto();

    //Running Mode
    void SetRunningMode (Bool_t runData) {
        fRunData      = runData;
    }

    //General Functions
    virtual void UserCreateOutputObjects();
    virtual void UserExec  (Option_t *option);
    virtual void Terminate (Option_t *);
    void  RunData();

    //User Functions
    Bool_t   GetEvent                   ();
    Bool_t   IsProton                   (AliAODTrack  track);
    Bool_t   PassedTrackSelection       (AliAODTrack *track);
    Double_t GetDCAtoPrimaryVertex      (AliAODTrack *track, Int_t index);
    Double_t GetRapidity                (AliAODTrack *track, Double_t mass);

private:
    AliAODEvent     *fAODEvent;     //!
    AliPIDResponse  *fPIDResponse;  //!
    AliAODTrackSelection *fAODTrackCuts;         //!
    AliESDtrackCuts *fESDTrackCuts; //!
    TList           *fOutputList;   //!
    TList           *fQAList;       //!
    Bool_t           fRunData;      //

    TH1F *hNumberOfEvents;          //!
    TH1F *hNumberOfTracks;          //!
    TH2F *hLeadingIDs;              //!
    TH1D *hFullPt;                  //!
    TH1D *hJetPt;                   //!
    TH1D *hJetProtonPt;             //!
    TH1D *hSameEventRelMomentum;    //!
    TH1D *hMixedEventRelMomentum;   //!
    TH1F *hProtonYield;             //!
    TH2F *hTPCnsigma;               //!
    TH2F *hTOFnsigma;               //!
    TH1F *hDCAxy;                   //!

    Double_t fJetRadius;
    Double_t fMaximumPt;

    AliAnalysisTaskJetFemto(const AliAnalysisTaskJetFemto&);
    AliAnalysisTaskJetFemto& operator=(const AliAnalysisTaskJetFemto&);

    ClassDef(AliAnalysisTaskJetFemto, 1);

};
//___________________________________________________________________________________________________________________________________________

#endif
