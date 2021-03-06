GTKWAVE:=$(shell which gtkwave)

all: dff

dff:prerequisites
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c main.cpp monitor.cc driver.cc nand.cc invertergate.cc 

	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "dff" main.o dff.o monitor.o invertergate.o nand.o driver.o -lsystemc
	./dff
	gtkwave -c 4 vcd_trace.vcd

prerequisites:
ifdef $(GTKWAVE)
	@echo "running gtkwave"
else
	@echo 'installing gtkwave, please be patient'
	sudo apt-get install -y gtkwave
endif

clean:
	rm -f dff *.o vcd_trace.vcd
.PHONY: dff
