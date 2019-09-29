//
// Created by nni on 31.10.18.
//

#ifndef BINAURALWAYPOINT_AUDIO_UTILITIES_H
#define BINAURALWAYPOINT_AUDIO_UTILITIES_H

#include <cstddef>
#include <utility>

using float32_t  = float;

//functions from secret rabbit code
void src_short_to_float_array (const int16_t *in, float32_t *out, size_t len);



// naive doubling of sample rate
std::pair<float32_t  *, size_t > doubleMonoSampleRate(const float * in, size_t length);

#endif //BINAURALWAYPOINT_AUDIO_UTILITIES_H
