#pragma once

template<typename T, unsigned N>
constexpr size_t length(T(&arr)[N])
{
    return N;
}