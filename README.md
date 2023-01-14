# Simulation of trip management made by taxis

### Description

This project was created for evaluation in the subject of **Algorithms and Data Structures** of the course **Web Development and Multimedia** at the **Instituto Politécnico do Cávado e do Ave (IPCA)**.

* This application was developed in C language. 
* We proceeded to use a binary file to store the data. 
* We created a library of functions capable of registering and storing information about trips and taxis, also implementing functionalities such as listing trips, calculating statistics and searching for specific information.

### Instructions

After downloading the solution, you can run the application, it is already compiled.


**Application usage:**

The application already comes with some registered trips, but if you prefer to clear the existing data, just choose option 4 from the main menu and then use the "Inciar / Reniciar Empresa" function.

**Compilation commands:**

***Windows***
- Compile: all
- Clear all: cleanw
- Clean only .d files: cleandepw

***Linux and MacOS***
- Compile: all
- Clear all: clean
- Clean only .d files: cleandep

### Data structure

The data structure consists of two main structs: **"Viagem"** and **"Taxi"**. The "Viagem" struct contains information about a trip, such as its reference, type, value and distance. The "Taxi" struct contains information about a taxi, such as its identification number, the trips associated with it, and the number of trips taken. In addition, there is an enum "TipoViagem" that defines the possible types of trip (local, national, international and other).
There is a global constant "MAX_TRIPS" that specifies the maximum number of trips that can be recorded for a single taxi. There are also global constants "NUM_TAXIS" and "IVA" that specify, respectively, the total number of existing taxis and the VAT rate to be applied to the trip values.

**Code:**
```c

#define MAX_VIAGENS 50
#define NUM_TAXIS 20
#define IVA 0.23

typedef enum {
  LOCAL,
  NACIONAL,
  INTERNACIONAL,
  OUTRA
} TipoViagem;

typedef struct {
  int ref;
  TipoViagem tipo;
  float valor;
  float distancia;
} Viagem;

typedef struct {
  int num;
  Viagem viagens[MAX_VIAGENS];
  int num_viagens;
} Taxi;

```

### Credits

- [Rúben Oliveira](https://github.com/RubenO94)
- [Rafael Gomes](https://github.com/RafaelGGomes)


