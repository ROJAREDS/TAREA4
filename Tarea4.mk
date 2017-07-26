#Tarea4.mk
PuntoNemo.pdf: resultados.txt
    python Plots.py
resultados.txt: PuntoGeographic.x
    ./PuntoGeographic.x
PuntoGeographic.x:PuntoGeographic.c
    cc PuntoGeographic.c -lm -o PuntoGeographic.x
PuntoGeographic.c: map_data.txt
    cc PuntoGeographic.c -lm -o PuntoGeographic.x
    