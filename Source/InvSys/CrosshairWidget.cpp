#include "CrosshairWidget.h"
#include "InvSysCharacter.h"

void UCrosshairWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UCrosshairWidget::NativeConstruct()
{
	Super::NativeConstruct();

	PlayerCharacter = Cast<AInvSysCharacter>(GetOwningPlayerPawn());
}
