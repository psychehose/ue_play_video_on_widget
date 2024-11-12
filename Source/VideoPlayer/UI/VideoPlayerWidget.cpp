// VideoPlayerWidget.cpp
#include "UI/VideoPlayerWidget.h"

UVideoPlayerWidget::UVideoPlayerWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UVideoPlayerWidget::NativeConstruct()
{
    Super::NativeConstruct();
    SetupMediaPlayer();
}

void UVideoPlayerWidget::NativeDestruct()
{
    if (MediaPlayer)
    {
        MediaPlayer->Close();
    }
    Super::NativeDestruct();
}

void UVideoPlayerWidget::SetupMediaPlayer()
{
    // 기존 에셋 로드
    MediaPlayer = LoadObject<UMediaPlayer>(nullptr, TEXT("/Game/Movies/MyMediaPlayer"));
    MediaTexture = LoadObject<UMediaTexture>(nullptr, TEXT("/Game/Movies/MyMediaPlayer_Video"));
    MediaSource = LoadObject<UMediaSource>(nullptr, TEXT("/Game/Movies/MyMediaSource"));

    if (VideoImage)
    {
        // 머티리얼 로드
		UMaterialInterface* Material = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/Movies/M_MyMediaPlayer_Video"));
		if (Material)
		{
			VideoImage->SetBrushFromMaterial(Material);
		}
    }
}

void UVideoPlayerWidget::PlayVideo()
{
    if (MediaPlayer && MediaSource)
    {
        MediaPlayer->OpenSource(MediaSource);
        MediaPlayer->Play();
    }
}

void UVideoPlayerWidget::PauseVideo()
{
    if (MediaPlayer)
    {
        MediaPlayer->Pause();
    }
}

void UVideoPlayerWidget::ResumeVideo()
{
    if (MediaPlayer)
    {
        MediaPlayer->Play();
    }
}

void UVideoPlayerWidget::StopVideo()
{
    if (MediaPlayer)
    {
        MediaPlayer->Close();
    }
}