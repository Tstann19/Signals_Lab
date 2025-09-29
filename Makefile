signals: signal.c
	gcc signal.c -o signalab 

onesignal: signal1.c
	gcc signal1.c -o signalLab1

twosignal: signal2.c
	gcc signal2.c -o signalLab2

timers: timer.c
	gcc timer.c -o timerFile