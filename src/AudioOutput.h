#pragma once

// Minimal AudioOutput interface for ESP8266SAM
// ESP8266SAM requires this interface but we don't need the full ESP8266Audio library
// This provides just what ESP8266SAM needs

class AudioOutput {
public:
    virtual ~AudioOutput() {}
    virtual bool begin() { return true; }
    virtual void SetRate(uint32_t rate) {}  // Sample rate in Hz (typically 22050 for ESP8266SAM)
    virtual void SetChannels(int channels) {}  // Number of channels (1 = mono, 2 = stereo)
    virtual bool ConsumeSample(int16_t sample[2]) = 0;  // Called for each audio sample [left, right]
    virtual bool stop() { return true; }
};


