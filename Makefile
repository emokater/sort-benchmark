PREF_SRC = ./sources/
PREF_OBJ = ./objects/

SRCS    := $(wildcard $(PREF_SRC)*.cpp)
OBJS    := $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRCS))

TARGET := FirstLab

all: $(TARGET)

$(TARGET) : $(OBJS)
	g++ $(OBJS) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.cpp
	g++ -c $< -o $@

# --- Дополнительные действия ---

generate-datasets :
	python3 $(HOME)/Desktop/hse/mp/sort-benchmark/utilities/genDatasets.py

graphs :
	python3 $(HOME)/Desktop/hse/mp/sort-benchmark/utilities/genGraphs.py

report :
	cd doc && \
	rm -rf latex html && \
	doxygen Doxyfile && \
	cd latex && \
	make

# --- Комбинированные цели ---

run : all
	./$(TARGET)

full : clean-all generate-datasets all run graphs report

# --- Очистка ---

clean-datasets :
	rm -f $(HOME)/Desktop/hse/mp/sort-benchmark/datasets/*.csv

clean-sorted-data :
	rm -f $(HOME)/Desktop/hse/mp/sort-benchmark/sorted_data/*.txt

clean-info :
	rm -f $(HOME)/Desktop/hse/mp/sort-benchmark/info_time.txt

clean :
	rm -f $(TARGET) $(PREF_OBJ)*.o

clean-all : clean-datasets clean-sorted-data clean-info clean