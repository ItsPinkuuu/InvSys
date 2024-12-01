#include "DragItemVisual.h"




FReply UDragItemVisual::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

	if (InMouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{
		UE_LOG(LogTemp, Warning, TEXT("Right clicked on drag visual."))
		
		return Reply.Handled();
	}

	return Reply.Unhandled(); 
}
