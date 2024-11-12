// VideoPlayerWidget.h
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MediaPlayer.h"
#include "MediaTexture.h"
#include "MediaSource.h"
#include "Components/Image.h"
#include "VideoPlayerWidget.generated.h"

UCLASS()
class VIDEOPLAYER_API UVideoPlayerWidget : public UUserWidget
{
    GENERATED_BODY()
    
public:
    UVideoPlayerWidget(const FObjectInitializer& ObjectInitializer);
    
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION(BlueprintCallable, Category = "Media")
    void PlayVideo();

    UFUNCTION(BlueprintCallable, Category = "Media")
    void PauseVideo();

    UFUNCTION(BlueprintCallable, Category = "Media")
    void ResumeVideo();

    UFUNCTION(BlueprintCallable, Category = "Media")
    void StopVideo();

protected:
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UImage* VideoImage;

    UPROPERTY()
    UMediaPlayer* MediaPlayer;

    UPROPERTY()
    UMediaTexture* MediaTexture;

    UPROPERTY()
    UMediaSource* MediaSource;

    virtual void SetupMediaPlayer();
};