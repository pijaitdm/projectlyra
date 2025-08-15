# Nama executable
TARGET = lcr

# Daftar file sumber
SRCS = main.cpp menu.cpp input.cpp pilih1.cpp pilih2.cpp pilih3.cpp folder.cpp lcr.cpp

# Compiler dan flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Objek file dari sumber
OBJS = $(SRCS:.cpp=.o)

# Rule utama
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "✅ Build sukses --> $@"

# Rule default object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Bersihkan file object dan executable
clean:
	rm -f $(OBJS) $(TARGET)
run: lcr
	@echo "🚀 Menjalankan $(TARGET)..."
	@./$(TARGET)
