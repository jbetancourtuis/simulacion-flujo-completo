****************************************************************************************************************
****************************************************************************************************************
****Código para simular la interacción del flujo de fondo de rayos cósmicos con minas antipersonas**************
****************************************************************************************************************
****************************************************************************************************************
Por Adriana Vásquez, tomando como base el código para las Simulaciones de los Detectores Cherenkov de Agua de LAGO, escrito por Mauricio Suárez, Adriana Vásquez y Andrei Jaimes.
****************************************************************************************************************
Dudas a adrianacvr67@gmail.com 
****************************************************************************************************************

***Para iniciar las simulaciones cambie el material del suelo, o de la mina, en el DetectorConstruccion.cc. Si va a simular sólo el suelo, cambie el material de la mina al suelo correspondiente. Si va a simular el suelo con la mina, mantenga el material del suelo y cambie el material de la mina a ANFO. 

***Para cambiar el radio de la superficie de donde salen los secundarios, modifique Ro en la clase PrimarySpectrum: 
Ro = 133.*cm;

***Cree una nueva carpeta donde va a compilar el código.

***Dentro de esta carpeta ejecute la siguiente línea, tomando en cuenta la ruta de instalación de su Geant4:
cmake -DGeant4_DIR=/home/adriana/GEANT4/geant4.10.3-install/lib/Geant4-10.3.1/ ../minas/; make -j2;

***Verifique o cambie el número deseado de partículas secundarias, en la última línea del archivo input.in:
/run/beamOn 3855333

***Para ejecutar su simulación realice:
time ./wcd -m input.in

***El código arroja el archivo minas.root, con 10 histogramas que corresponden a lo siguiente:
0: Partículas secundarias que interactuan con el suelo.
1: Total de partículas generadas producto de la interacción anterior. El bin 1 corresponde al total, el bin 2 a los electrones y positrones, el 3 a los gammas, el 4 a los neutrones y el 5 a los protones.
2: Energía de los electrones y positrones generados.
3: Energía de los gamma generados.
4: Energía de los neutrones generados.
5: Energía de los protones generados.
6: Total de electrones y positrones que llegan al detector.
7: Total de gammas que llegan al detector.
8: Energía de los electrones y positrones del histograma 6.
9: Energía de los gammas del histograma 7.

***Se recomienda guardar este archivo en otra carpeta (datos) con el nombre asociado a la simulación realizada.

Enjoy! :)  


