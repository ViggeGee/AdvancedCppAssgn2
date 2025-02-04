#pragma once
#include <vector>

template <typename Container>
auto Sum(const Container& c) {
    // Deduce the element type by inspecting the first element
    using RawElementType = std::remove_const_t<std::remove_reference_t<decltype(*std::begin(c))>>;

    RawElementType sum{};  // Default initialization (e.g., 0 for numbers)

    for (const auto& element : c) {
        sum += element;
    }

    return sum;
}