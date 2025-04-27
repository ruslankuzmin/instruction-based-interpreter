#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

// Function to handle memory access errors
void memoryErr(int memoryAddr, const std::string& desc) {
    std::cerr << "Memory access error " << memoryAddr << " " << desc << std::endl;
    exit(1);
}

// Function that simulates a simple instruction-based program
void program(int instruction_pointer, std::vector<int>& memory, size_t ticks_limit) {
    size_t tick = 0;
    size_t mem_size = memory.size();

    while (tick < ticks_limit) {
        // Validate instruction pointer
        if (instruction_pointer < 0) {
            memoryErr(instruction_pointer, "Negative instruction pointer");
        }
        if (instruction_pointer + 2 >= static_cast<int>(mem_size)) {
            memoryErr(instruction_pointer + 2, "Instruction pointer out of bounds");
        }

        int a = memory[instruction_pointer];
        int b = memory[instruction_pointer + 1];
        int c = memory[instruction_pointer + 2];

        // Validate operands a, b, and c
        if (a < 0) {
            memoryErr(a, "A is negative");
        }
        if (a >= static_cast<int>(mem_size)) {
            memoryErr(a, "A exceeds memory size");
        }

        if (b < -1) {
            memoryErr(b, "B is less than -1");
        }
        if (b >= static_cast<int>(mem_size)) {
            memoryErr(b, "B exceeds memory size");
        }

        if (c >= static_cast<int>(mem_size)) {
            memoryErr(c, "C exceeds memory size");
        }

        // Execute instruction
        if (b == -1) {
            std::cout << static_cast<char>(memory[a]); // Output a character
        } else {
            memory[b] -= memory[a]; // Subtract value at a from value at b
        }

        // Control flow
        if (b != -1 && memory[b] <= 0) {
            if (c < 0) {
                return;
            }
            instruction_pointer = c; // Jump to c if memory[b] <= 0
        } else {
            instruction_pointer += 3; // Move to next instruction
        }
        tick++;
    }
}

int main() {
    std::cout << "Example of operating system" << std::endl;

    // Program 1 memory initialization. Print Hello, World!
    std::vector<int> memory1 = {
        12, 12, 3,
        36, 37, 6,
        37, 12, 9,
        37, 37, 12,
        0, -1, 15,
        38, 36, 18,
        12, 12, 21,
        53, 37, 24,
        37, 12, 27,
        37, 37, 30,
        36, 12, -1,
        37, 37, 0,
        39, 0, -1,
        72, 101, 108,
        108, 111, 44,
        32, 87, 111,
        114, 108, 100,
        33, 10, 53
    };

    memory1.resize(1000, 0); // Expand memory to 1000 elements

    // Program 2 memory initialization. Print 398
    std::vector<int> memory2 = {
        15, -1, 3,
        16, -1, 6,
        17, -1, 9,
        18, -1, 12,
        0, 0, -1,
        51,
        57,
        56,
        10
    };

    memory2.resize(1000, 0); // Expand memory to 1000 elements

    // Run both programs
    program(0, memory1, 300);
    program(0, memory2, 300);

    return 0;
}
