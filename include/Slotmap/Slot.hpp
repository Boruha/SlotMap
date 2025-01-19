#pragma once

#include <cstdlib>

namespace BPW {

// Slot works as well as 'keys' on a unordered_map,
// allows to access directly to and specific position.
struct Slot {
    std::size_t id  {};
    std::size_t gen {};
};

}