#ifndef WCSimWCDAQMessenger_h
#define WCSimWCDAQMessenger_h 1

#include "G4UImessenger.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithABool.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithoutParameter.hh"

class G4UIcommand;
class WCSimEventAction;
class WCSimWCDigitizerBase;
class WCSimWCTriggerBase;

class WCSimWCDAQMessenger: public G4UImessenger
{
public:
  WCSimWCDAQMessenger(WCSimEventAction*);

  ~WCSimWCDAQMessenger();

  void SetNewValue(G4UIcommand* command, G4String newValue);

  void SetTriggerOptions();
  void SetDigitizerOptions();

  void TellMeAboutTheDigitizer  (WCSimWCDigitizerBase* digitizer)   { WCSimDigitize = digitizer; }
  void TellMeAboutTheTrigger    (WCSimWCTriggerBase*   trigger)     { WCSimTrigger  = trigger; }

private:
  WCSimEventAction*     WCSimEvent;
  WCSimWCDigitizerBase* WCSimDigitize;
  WCSimWCTriggerBase*   WCSimTrigger;

  G4UIdirectory*      WCSimDAQDir;
  G4UIcmdWithAString* DigitizerChoice;
  G4String            StoreDigitizerChoice;
  G4UIcmdWithAString* TriggerChoice;
  G4String            StoreTriggerChoice;
  G4UIcmdWithABool*   MultiDigitsPerTrigger;
  G4bool              StoreMultiDigitsPerTrigger;
  G4bool              MultiDigitsPerTriggerSet;
  G4UIcmdWithABool*   WriteGeomInfo;
  G4bool              StoreWriteGeomInfo;


  G4UIcmdWithoutParameter* DAQConstruct; //TODO remove this

  G4UIdirectory*        DigitizerDir;
  G4UIcmdWithAnInteger* DigitizerDeadTime;
  G4int                 StoreDigitizerDeadTime;
  G4UIcmdWithAnInteger* DigitizerIntegrationWindow;
  G4int                 StoreDigitizerIntegrationWindow;

  G4UIdirectory*        SaveFailuresTriggerDir;
  G4UIcmdWithAnInteger* SaveFailuresTriggerMode;
  G4int                 StoreSaveFailuresMode;
  G4UIcmdWithADouble*   SaveFailuresTriggerTime;
  G4double              StoreSaveFailuresTime;
  G4UIcmdWithAnInteger* SaveFailuresPreTriggerWindow;
  G4int                 StoreSaveFailuresPreWindow;
  G4UIcmdWithAnInteger* SaveFailuresPostTriggerWindow;
  G4int                 StoreSaveFailuresPostWindow;

  G4UIdirectory*        NDigitsTriggerDir;
  G4UIcmdWithAnInteger* NDigitsTriggerThreshold;
  G4int                 StoreNDigitsThreshold;
  G4UIcmdWithAnInteger* NDigitsTriggerWindow;
  G4int                 StoreNDigitsWindow;
  G4UIcmdWithABool*     NDigitsTriggerAdjustForNoise;
  G4bool                StoreNDigitsAdjustForNoise;
  G4UIcmdWithAnInteger* NDigitsPreTriggerWindow;
  G4int                 StoreNDigitsPreWindow;
  G4UIcmdWithAnInteger* NDigitsPostTriggerWindow;
  G4int                 StoreNDigitsPostWindow;

  G4UIdirectory*        LocalNHitsTriggerDir;
  G4UIcmdWithAnInteger* LocalNHitsTriggerNeighbours;
  G4int                 StoreLocalNHitsNeighbours;
  G4UIcmdWithAnInteger* LocalNHitsTriggerThreshold;
  G4int                 StoreLocalNHitsThreshold;
  G4UIcmdWithAnInteger* LocalNHitsTriggerWindow;
  G4int                 StoreLocalNHitsWindow;
  G4UIcmdWithABool*     LocalNHitsTriggerAdjustForNoise;
  G4bool                StoreLocalNHitsAdjustForNoise;

  G4UIdirectory*        TriggerRegionsDir;
  G4UIcmdWithAnInteger* TriggerRegionsNBinsPhi;
  G4int                 StoreLocalNHitsNBinsPhi;
  G4UIcmdWithAnInteger* TriggerRegionsNBinsZ;
  G4int                 StoreLocalNHitsNBinsZ;
  G4UIcmdWithAnInteger* TriggerRegionsNRings;
  G4int                 StoreLocalNHitsNRings;
  G4UIcmdWithAnInteger* TriggerRegionsNCentralSectors;
  G4int                 StoreLocalNHitsNCentralSectors;
  G4UIcmdWithAnInteger* TriggerRegionsNRingSectors;
  G4int                 StoreLocalNHitsNRingSectors;

  G4UIdirectory*        ITCRatioTriggerDir;
  G4UIcmdWithADouble*   ITCRatioTriggerThreshold;
  G4double              StoreITCRatioTriggerThreshold;
  G4UIcmdWithAnInteger* ITCRatioTriggerSmallWindow;
  G4int                 StoreITCRatioTriggerSmallWindow;
  G4UIcmdWithAnInteger* ITCRatioTriggerLargeWindowLow;
  G4int                 StoreITCRatioTriggerLargeWindowLow;
  G4UIcmdWithAnInteger* ITCRatioTriggerLargeWindowHigh;
  G4int                 StoreITCRatioTriggerLargeWindowHigh;

  G4String initialiseString;
  G4bool   initialised;

};

#endif
