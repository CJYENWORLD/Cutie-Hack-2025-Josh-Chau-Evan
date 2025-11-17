CXX = g++
CXXFLAGS = -DCPPHTTPLIB_OPENSSL_SUPPORT -D_WIN32_WINNT=0x0A00
LDFLAGS = -lssl -lcrypto -lws2_32 -lwinmm -lcrypt32

SRC = main.cpp app.cpp fileReader.cpp location.cpp level.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = DriveApp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

# --- Auto rebuild when headers change ---

app.o: app.cpp app.h
fileReader.o: fileReader.cpp fileReader.h
location.o: location.cpp location.h
level.o: level.cpp level.h
main.o: main.cpp

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

run: $(TARGET)
	./DriveApp.exe drives/street_drive_good.csv

clean:
	del $(TARGET).exe 2>nul || true
	del *.json 2>nul || true
	del *.o 2>nul || true
