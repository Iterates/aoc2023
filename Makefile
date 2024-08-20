CC = g++
SRC = ${CURDIR}/cpp
OUT = ${CURDIR}/out
PYTHON = ${CURDIR}/python
APL = ${CURDIR}/apl
COMPILE_FLAGS_FILE:=compile_flags.txt
CXXFLAGS:=$(shell cat ${COMPILE_FLAGS_FILE})

default:
ifndef PART
	@echo Specify part!
	exit 1
endif
ifndef DAY
	@echo Specify day!
	exit 1
endif
	@echo Building...
	${CC} ${SRC}/day-${DAY}/part-${PART}.cpp ${SRC}/utils/*.cpp ${CXXFLAGS} -std=c++20 -o ${OUT}/${DAY}-${PART}.exe
	@echo Executing...
	${OUT}/${DAY}-${PART}.exe

clean:
	rm -rf ${OUT}/*

p:
	py ${PYTHON}/run.py ${DAY} ${PART}