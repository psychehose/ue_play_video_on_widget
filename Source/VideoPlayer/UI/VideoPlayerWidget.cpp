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
    // ���� ���� �ε�
    MediaPlayer = LoadObject<UMediaPlayer>(nullptr, TEXT("/Game/Movies/MyMediaPlayer"));
    MediaTexture = LoadObject<UMediaTexture>(nullptr, TEXT("/Game/Movies/MyMediaPlayer_Video"));
    MediaSource = LoadObject<UMediaSource>(nullptr, TEXT("/Game/Movies/MyMediaSource"));

    if (VideoImage)
    {
        // ��Ƽ���� �ε�
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