/*
  ==============================================================================

    DeckGUI.h
    Created: 2 Feb 2022 10:54:22am
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "DJAudioPlayer.h"
#include "WaveformDisplay.h"
#include "PlaylistComponent.h"

//==============================================================================
/*
*/
class DeckGUI  : public juce::Component, 
                 public juce::Button::Listener, 
                 public juce::Slider::Listener,
                 public juce::FileDragAndDropTarget,
                 public juce::Timer
{
public:
    DeckGUI(DJAudioPlayer* player,
            juce::AudioFormatManager & formatManagerToUse,
            juce::AudioThumbnailCache & cacheToUse);
    ~DeckGUI();    

    void paint (juce::Graphics&) override;
    void resized() override;

    /** implement Button::Listener*/
    void buttonClicked(juce::Button*) override;

    /** implement Slider::Listener*/
    void sliderValueChanged(juce::Slider* slider) override;

    bool isInterestedInFileDrag(const juce::StringArray &files) override;
    void filesDropped(const juce::StringArray& files, int x, int y) override;

    void timerCallback() override; //Timer function which is used to check whether user has selected whether to loop or not
    void playlistToDeckGUI(); // This function reads which audio file the user has selected to be added into either Deck 1 or 2

private:
    juce::ImageButton playButton{ "PLAY" };
    juce::ImageButton stopButton{ "STOP" };
    juce::ToggleButton loopButton{ "LOOP" };
    juce::TextEditor trackName;
    juce::String mtrackName;
    juce::TextButton loadButton{ "LOAD" };
    juce::Label volSliderLabel;
    juce::Label speedSliderLabel;
    juce::Slider volSlider;
    juce::Slider speedSlider;
    juce::Slider posSlider;
    DJAudioPlayer* player;
    WaveformDisplay waveformDisplay;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DeckGUI)

};
