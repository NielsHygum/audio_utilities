//
// Created by nni on 31.10.18.
//

#include <android/log.h>
#include "audio_utilities.h"

//functions from secret rabbit code
void
src_short_to_float_array (const int16_t *in, float32_t *out, size_t len)
{
    for(size_t index = 0; index < len;index+=sizeof(int16_t))
    {
        int16_t sample_value = static_cast<int16_t >(in[index]);
        float sample = static_cast<float>(sample_value)/32768.0f;
        out[index] = static_cast<float32_t>(sample);
    } ;

    return ;
} /* src_short_to_float_array */


// naive doubling of sample rate
std::pair<float32_t  *, size_t > doubleMonoSampleRate(const float32_t * in, size_t length)
{
    if(length > 1)
    {
        size_t length_out = length*2-1;
        float32_t * out = new float32_t[length_out];

        for(size_t in_index = 0; in_index < (length-1); in_index++)
        {
            out[in_index*2] = in[in_index];
            out[in_index*2+1] = (in[in_index]+in[in_index+1])/2.0f;
        }

        return std::make_pair(out, length_out);
    }

    return std::make_pair(nullptr, 0.0f);
}