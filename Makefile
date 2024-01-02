CXX := g++  # Change this to your C++ compiler
SRCDIR := src
BUILDDIR := build
BINDIR := bin
TARGET := SalesMgmt

SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

CXXFLAGS := -std=c++11 -Wall  # Add any additional compiler flags here
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

data/customers.csv:
	mkdir -p data
	echo "This is customers.csv" > data/customers.csv

data/invoices.csv:
	mkdir -p data
	echo "This is invoices.csv" > data/invoices.csv

data/products.csv:
	mkdir -p data
	echo "This is products.csv" > data/products.csv

create_files: data/customers.csv data/invoices.csv data/products.csv

clean:
	rm -rf $(BUILDDIR) $(BINDIR)



run: ./$(BINDIR)/$(TARGET) 


compile: clean all create_files 
	echo "Compiled"

# with using run command, only using make
compile-run: clean all create_files
	./$(BINDIR)/$(TARGET)

