#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=156,189
AudioMixer4              mixer;         //xy=339,178
AudioEffectDelayExternal delayExt(AUDIO_MEMORY_23LC1024,1400);      //xy=380,379
AudioOutputI2S           i2s1;           //xy=605,354
AudioConnection          patchCord1(i2s2, 0, mixer, 0);
AudioConnection          patchCord2(mixer, delayExt);
AudioConnection          patchCord3(delayExt, 0, mixer, 1);
AudioConnection          patchCord4(delayExt, 0, i2s1, 0);
AudioConnection          patchCord5(delayExt, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=165,351
// GUItool: end automatically generated code

void setup() {
  //Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  AudioMemory(160);
  sgtl5000_1.enable();
  sgtl5000_1.volume(1.0);
  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN);
  sgtl5000_1.micGain(50);
  mixer.gain(0, 1.0);
  mixer.gain(1, 0.9);
  delayExt.delay(0, 1400);
  delay(1000);
}

void loop(){}
