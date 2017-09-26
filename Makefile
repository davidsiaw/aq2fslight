all:
	g++ main.cpp pin.cpp -o main -lbcm2835

run: all
	./main

cp:
	sshpass -p "raspberry" scp ./* pi@raspberrypi.local:/home/pi