# Nama executable
TARGET = LCR

# Daftar file sumber
SRCS = main.cpp menu.cpp input.cpp pilih1.cpp

# Compiler dan flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Objek file dari sumber
OBJS = $(SRCS:.cpp=.o)

# Rule utama
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule default object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Bersihkan file object dan executable
clean:
	rm -f $(OBJS) $(TARGET)

