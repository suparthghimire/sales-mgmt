CXX := g++  # Change this to your C++ compiler
SRCDIR := src
BUILDDIR := build
BINDIR := bin
TARGET := SalesMgmt

SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

CXXFLAGS := -std=c++14 -Wall  # Add any additional compiler flags here
LDFLAGS :=  # Add any additional linker flags here

.PHONY: all clean

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJS) | $(BINDIR)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BINDIR):
	mkdir -p $(BINDIR)


data:
	mkdir -p data
	mkdir -p data/invoices



create_files: data

clean:
#Windows
ifeq ($(OS),Windows_NT)
	deltree /S /Q $(BUILDDIR) $(BINDIR)	
# UNIX
else
	rm -rf $(BUILDDIR) $(BINDIR)
endif



run: ./$(BINDIR)/$(TARGET) 


compile: clean all create_files 
	echo "Compiled"

# with using run command, only using make
compile-run: clean all create_files
	./$(BINDIR)/$(TARGET)

