# instruction-based-interpreter
## Simple Instruction-Based Interpreter 🎯📚✨

This repository contains a minimal C++ program that simulates a basic instruction-based interpreter. 🎯📚✨ The interpreter reads a vector of integer triples (instructions subleq) and performs memory operations or character output based on those instructions. 🎯📚✨

### Features 🚀🛡️🧩

- Bounds-checked memory access with error handling
- Two-operand arithmetic and conditional jumps
- Character output when operand `b == -1`
- Program termination on `c == -1`

### Instruction Format 🧠📋🛠️

Each instruction consists of three integers:

```
a, b, c
```

- **a**: memory index for the data operand
- **b**: if `-1`, output `memory[a]` as a character; otherwise, subtract `memory[a]` from `memory[b]`
- **c**: next instruction pointer; if `-1`, halt program

### Building 🛠️🏗️🔧

```bash
# Compile using g++
g++ -std=c++17 -O2 -o interpreter interpreter.cpp
```

### Running 🏃‍♂️💻🎉

```bash
# Runs the hardcoded memory sequence and prints "Hello, World!" followed by a newline
./interpreter
```

### Memory Initialization 🧩🗃️🖋️

The example in `main()` defines a vector of encoded ASCII values and uses `-1` markers for output and termination:

```cpp
std::vector<int> memory1 = {
    39, -1, -1,   // starts sequence
    72, -1, -1,   // 'H'
    101, -1, -1,  // 'e'
    ...           // more characters
    10, -1, -1    // newline
};
memory1.resize(1000, 0);
```

### Error Handling 🚫❗🧹

Any out-of-bounds or invalid access invokes `memoryErr()`, which prints an error message and exits:

```cpp
memoryErr(int memoryAddr, const std::string& desc);
```

### License 📜✅🔓

This code is released under the MIT License. 📜✅🔓 Feel free to reuse and modify as needed. 📜✅🔓
