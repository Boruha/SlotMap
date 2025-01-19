#pragma once

#include "Slotmap/Slot.hpp"

#include <algorithm>
#include <vector>

/*  TODOLIST:
        - Add size comprobations and resize/reserve operations.
        - Investigate forwarding.
        - Iterators
        - emplace_back
        - resize
        - reserve
*/

namespace BPW {

template <typename T>
struct Slotmap {
    using data_t  = T;
    using index_t = std::size_t; 

    constexpr Slot PushBack(data_t&& val) {        
        Slot key {.id = freelist, .gen = generation};   // Creating the slot with required information to access de underlying data.
        indices[freelist].gen = generation;             // Assing generation value and increase the counter.
        ++generation;
        erase.push_back(freelist);                      // Insert position where the index that refers new data.
        freelist             = indices[freelist].id;    // Updates next position free on indices.
        indices[freelist].id = data.size();             // Updates with the position where the data is located.
        data.push_back(val);                            // Inserts the data.
        return key;
    }

    constexpr void Erase(const Slot& key) {
        // NOTE: User's slot id indicates the indices that contains the data.
        auto& index = indices[key.id];
        if(index.gen != key.gen) { return; }

        const auto lastIndex         {data.size() - 1ul};
        indices[erase[lastIndex]].id = index.id;

        std::swap(data[index.id], data[lastIndex]);
        std::swap(erase[index.id], erase[lastIndex]);     
        
        index.id = freelist;
        freelist = key.id;
        data.pop_back();
        erase.pop_back();
    }

    constexpr index_t Size()     { return data.size();     };
    constexpr index_t Capacity() { return data.capacity(); };

private:
    index_t freelist   {}; // First slot index in indices that is available.
    index_t generation {}; // Element inserted counter.

    std::vector<Slot>    indices {}; // Vector with information for direct access to data vector.
    std::vector<data_t>  data    {}; // Slotmap' content.
    std::vector<index_t> erase   {}; // Contains the location of the data we want to remove.
};

}