#pragma once

#include "ofMain.h"

struct ScopedMatrix {
    ScopedMatrix() { ofPushMatrix(); }
    ~ScopedMatrix() { ofPopMatrix(); }

    ScopedMatrix(const ScopedMatrix &) = delete;
    ScopedMatrix &operator=(const ScopedMatrix &) = delete;
};