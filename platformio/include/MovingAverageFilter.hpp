#pragma once

class MovingAverageFilter {
public:
    MovingAverageFilter(int size) {
        // TODO: initialise the filter
    }

    ~MovingAverageFilter() {
        // TODO: clean up any allocated resources
    }

    float update(float value) {
        // TODO: add a new sample and return the updated average
        return 0.0f;
    }

    float getAverage() const {
        // TODO: return the current average
        return 0.0f;
    }

    void reset() {
        // TODO: reset the filter state
    }

private:
    // TODO: store the samples and any required filter state
};