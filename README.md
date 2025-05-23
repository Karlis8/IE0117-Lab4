# IE0117-Lab4
# 📌 Laboratorio 4 – Programación en C  
**Autor:** Karla Méndez, B84870  
**Archivo principal:** `L4_B84870.c`  

## 📋 Descripción

Este programa en lenguaje C permite trabajar con matrices cuadradas de valores binarios (0s y 1s). A través de un menú interactivo, el usuario puede visualizar la matriz, redimensionarla sin perder los datos previos, modificar valores manualmente y encontrar la secuencia más larga de unos consecutivos en dirección diagonal descendente hacia la izquierda (↙). El código hace uso de memoria dinámica y aritmética de punteros, y está diseñado para ser eficiente y fácil de utilizar.

## ▶️ Cómo compilar y ejecutar

Para compilar y ejecutar el programa desde la terminal (Bash), asegúrese de estar ubicado en el directorio que contiene el archivo `L4_B84870.c`, y luego ejecute los siguientes comandos:

```bash
gcc -o lab4 L4_B84870.c
./lab4

Este programa incluye una función para liberar correctamente la memoria dinámica utilizada, asegurando una ejecución limpia sin pérdidas de memoria. Para comprobarlo, puede usar Valgrind con el siguiente comando:

```bash
valgrind --leak-check=full ./lab4

