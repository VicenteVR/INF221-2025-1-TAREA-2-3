# Tarea 2-3: Diferencias entre Secuencias — INF-221 2025-1

### Vicente Vizcarra Rubio 202173036-2

Este repositorio contiene la implementación, experimentación y reporte del análisis de dos algoritmos para encontrar diferencias mínimas entre pares de cadenas de texto, utilizando la subsecuencia común más larga (LCS) como base. Se implementan y comparan dos enfoques: fuerza bruta y programación dinámica.

---

## 🔧 Ejecución y medición

### Fuerza Bruta

Desde el directorio code/brute_force, se ejecuta
```
make
```
Esto:
- Lee entrada desde data/brute_force_input/a.txt
- Escribe salida en data/brute_force_output/a.txt
- Registra mediciones en data/measurements/a.txt

### Programación Dinámica

Desde el directorio code/dynamic_programming, se ejecuta
```
make
```
Esto:
- Lee entrada desde data/dynamic_programming_input/a.txt
- Escribe salida en data/dynamic_programming_output/a.txt
- Registra mediciones en data/measurements/a.txt

## Visualización de resultados

Desde los directorios code/brute_force y code/dynamic_programming, se ejecuta
```
python3 scripts/plot_generator.py
```
Esto genera los siguientes gráficos en los directorios correspondientes (../data/plots):
- tiempo_vs_tamanoDP.png
- memoria_vs_tamanoDP.png
- tiempo_vs_tamanoBF.png
- memoria_vs_tamanoBF.png

## Generador de datos

En caso de querer generar nuevos datos se debe ejecutar desde la ruta code/dynamic_programming/scripts
```
python3 input_generator.py
```
Esto genera datos aleatorios y los copia a la carpetas correspondientes.