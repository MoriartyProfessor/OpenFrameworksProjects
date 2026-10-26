#pragma once

template <typename T> 
struct SliderRange {
    static_assert(std::is_arithmetic_v<T>);
    T MIN;
    T MAX;
    T DEFAULT;
    SliderRange(T min, T max, T def)
        : MIN{min}, MAX{max}, DEFAULT{def} {}
};
