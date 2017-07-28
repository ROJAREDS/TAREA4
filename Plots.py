import numpy as np
import matplotlib.pyplot as plt

data= np.loadtxt("map_data.txt")
dataob = np.loadtxt("datos_obtenidos.txt")


#marcarPunto(dataob[0],dataob[1])
#tta=np.linspace(0,2*np.pi,500)

fig = plt.gcf()
ax = fig.gca()
b = plt.Circle((dataob[1],dataob[0]), dataob[2], fill = False)
plt.scatter([dataob[1]],[dataob[0]], color = 'w')
ax.add_artist(b)
plt.imshow(data)
plt.ylabel('$Longitud$ $y$')
plt.xlabel('$Latitud$ $x$')
plt.title('$Punto$ $Nemo$')
plt.savefig("PuntoNemo.pdf")
