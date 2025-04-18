# Nome do compilador
CXX = g++

# Flags de compilação (avisos e padrão C++ moderno)
CXXFLAGS = -Wall -Wextra -std=c++11

# Nome do executável final
TARGET = conversao

# Lista de arquivos objeto gerados
OBJ = main.o conversao.o

# Regra principal: compila o programa
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regra para compilar main.cpp
main.o: main.cpp conversao.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Regra para compilar conversao.cpp
conversao.o: conversao.cpp conversao.h
	$(CXX) $(CXXFLAGS) -c conversao.cpp

# Limpeza: remove arquivos objeto e executável
clean:
	rm -f $(OBJ) $(TARGET)
