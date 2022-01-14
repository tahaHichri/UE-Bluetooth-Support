#include "../Public/ScanCallbackBase.h"




UScanCallbackBase::UScanCallbackBase() :
	SucceedDelegate(FDeviceScanSucceedCompleteDelegate::CreateUObject(this, &ThisClass::OnSucceedComplete))
{

}



void UScanCallbackBase::Activate()
{
	TaModule->ClearAllDeviceScanSucceedCompleteDelegate_Handle();
	SucceedDelegateHandle = TaModule->AddDeviceScanSucceedCompleteDelegate_Handle(SucceedDelegate);
	Activete_imp();
}

void UScanCallbackBase::Activete_imp()
{

}

void UScanCallbackBase::PostSucceedComplete(UBluetoothDevice* Device)
{

}

void UScanCallbackBase::OnSucceedComplete(UBluetoothDevice* Device)
{
	PostSucceedComplete(Device);
	OnResultFound.Broadcast(Device);

	// I should clear the trigger somwhere.


	SetReadyToDestroy();
}
