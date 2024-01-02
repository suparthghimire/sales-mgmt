CXX := g++  # Change this to your C++ compiler
SRCDIR := src
BUILDDIR := build
BINDIR := bin
TARGET := YourExecutableName

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

clean:
	rm -rf $(BUILDDIR) $(BINDIR)

