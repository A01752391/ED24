# Nombre del ejecutable
TARGET = busqueda

# Compilador y opciones de compilación
CC = g++
CFLAGS = -Wall -std=c++17

# Archivos fuente
SRCS = algoritmosBusqueda.cpp

# Archivo objeto
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar archivos objeto
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(TARGET) $(OBJS)
