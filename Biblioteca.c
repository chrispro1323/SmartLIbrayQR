#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define Verdadero 1
#define Falso 0
#define TAM 100

// Variables para la simulación (Administración Usuarios)
typedef struct
{
    int matricula;
    char nombre[50];
    int prestamosActivos;
} usuario;

usuario listaUsuarios[TAM];
int totalUsuarios = 0;
char ConfirmarUsuario[50];

// Variables para la simulación (Administración Libros)

typedef struct
{
    int id;
    char titulo[100];
    char autor[100];
    char categoria[40];
    int disponible;
    int numeroPrestamosHistoricos;

} libro;

libro listaLibros[TAM];
int totalLibros = 0;
int contCategoria[11] = {0};
int BuscarID;
int IDRep, EncontrarLibro;
char confirmarLIbro[50];


//Arreglos struct y variables para prestamos
typedef struct {
    int idPrestamo;
    int matriculaUsuario;
    int idLibro;          
    int devuelto;        
} prestamo;

prestamo listaPrestamos[TAM];
int totalPrestamos = 0;





// Menús Principales
void UsuariosMenu();
void LibrosMenu();
void DevolucionesMenu();
void ReportesMenu();

// Menús Administración de usuarios
void RegistroUsu();
void ModificarInf();
void BuscarUsu();
void ConsultarUsuRegistrados();
void EliminarUsu();

// Menús Administración de Libros
void RegistrarLibros();
void ModificarLibros();
void EliminarLibros();
void BuscarLibros();
void ConsultarDisponibilidad();
void ClasificarCategoria();

// Menús Préstamos/Devoluciones
void RegistrarPrestamo();
void RegistrarDevolucion();

// Menús Reportes
void LibrosDisponibles();
void LibrosPrestados();
void UsuariosResgistrados();
void HistorialPrestamos();
void HistorialDevoluciones();
void LibrosMayorPrestamos();
void UsuariosPrestamosActivos();

int main()
{
    int op;
    do
    {
        printf("------------------------------------------------------------------\n");
        printf("|                           Smart Library                        |\n");
        printf("------------------------------------------------------------------\n");
        printf("|Bienvenido a nuestra biblioteca digital                         |\n");
        printf("|A continuacion puedes elegir la accion que deseas realizar:     |\n");
        printf("|                                                                |\n");
        printf("|        1.-                    Administracion de Usuarios.      |\n");
        printf("|        2.-                     Administracion de Libros.       |\n");
        printf("|        3.-                         Prestamos/Devoluciones.     |\n");
        printf("|        4.-                                   Reportes.         |\n");
        printf("|        0.-                     Salir de la biblioteca.         |\n");
        printf("------------------------------------------------------------------\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            UsuariosMenu();
            break;
        case 2:
            LibrosMenu();
            break;
        case 3:
            DevolucionesMenu();
            break;
        case 4:
            ReportesMenu();
            break;
        case 0:
            printf("Saliendo de la biblioteca, vuelva pronto\n");
            break;
        default:
            printf("Esa opcion no existe\n");
            break;
        }
    } while (op != 0);

    return 0;
}

void UsuariosMenu()
{
    int opUsuarios;
    do
    {
        printf("-----------------------------------------------------------------\n");
        printf("|                    Administracion de Usuarios                 |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|Bienvenido a nuestra biblioteca digital                         |\n");
        printf("|A continuacion puedes elegir la accion que deseas realizar:     |\n");
        printf("|                                                                |\n");
        printf("|        1.-                           Registro de Usuarios.     |\n");
        printf("|        2.-                          Modificar informacion.     |\n");
        printf("|        3.-                               Buscar Usuarios.      |\n");
        printf("|        4.-                          Usuarios registrados.      |\n");
        printf("|        5.-                         Eliminar Usuarios.      |\n");
        printf("|        0.-                     Salir de la biblioteca.         |\n");
        printf("-----------------------------------------------------------------\n");
        scanf("%d", &opUsuarios);
        switch (opUsuarios)
        {
        case 1:
            RegistroUsu();
            break;
        case 2:
            ModificarInf();
            break;
        case 3:
            BuscarUsu();
            break;
        case 4:
            ConsultarUsuRegistrados();
            break;
        case 5:
            EliminarUsu();
            break;
        case 0:
            printf("Saliendo al menu principal\n");
            break;
        default:
            printf("Esa opcion no existe\n");
            break;
        }
    } while (opUsuarios != 0);
}

void LibrosMenu()
{
    int opLibros;
    do
    {
        printf("-----------------------------------------------------------------\n");
        printf("|                   Administracion de libros                    |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|Bienvenido a nuestra biblioteca digital                         |\n");
        printf("|A continuacion puedes elegir la accion que deseas realizar:     |\n");
        printf("|                                                                |\n");
        printf("|        1.-                             Registrar libros.       |\n");
        printf("|        2.-                              Modificar libros.      |\n");
        printf("|        3.-                               Eliminar libros.      |\n");
        printf("|        4.-                                  Buscar libros.     |\n");
        printf("|        5.-                      Consultar disponibilidad.      |\n");
        printf("|        6.-               Clasificar libros por categoria.      |\n");
        printf("|        0.-                     Salir de la biblioteca.         |\n");
        printf("-----------------------------------------------------------------\n");
        scanf("%d", &opLibros);
        switch (opLibros)
        {
        case 1:
            RegistrarLibros();
            break;
        case 2:
            ModificarLibros();
            break;
        case 3:
            EliminarLibros();
            break;
        case 4:
            BuscarLibros();
            break;
        case 5:
            ConsultarDisponibilidad();
            break;
        case 6:
            ClasificarCategoria();
            break;
        case 0:
            printf("Saliendo al menu principal\n");
            break;
        default:
            printf("Esa opcion no existe\n");
            break;
        }
    } while (opLibros != 0);
}

void DevolucionesMenu()
{
    int opPresDev;
    do
    {
        printf("-----------------------------------------------------------------\n");
        printf("|                     Prestamos/Devoluciones.                   |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|Bienvenido a nuestra biblioteca digital                         |\n");
        printf("|A continuacion puedes elegir la accion que deseas realizar:     |\n");
        printf("|                                                                |\n");
        printf("|        1.-                         Registrar un prestamo.      |\n");
        printf("|        2.-                      Registrar una devolucion.      |\n");
        printf("|        0.-                     Salir de la biblioteca.         |\n");
        printf("-----------------------------------------------------------------\n");
        scanf("%d", &opPresDev);
        switch (opPresDev)
        {
        case 1:
            RegistrarPrestamo();
            break;
        case 2:
            RegistrarDevolucion();
            break;
        case 0:
            printf("Saliendo al menu principal\n");
            break;
        default:
            printf("Esa opcion no existe\n");
            break;
        }
    } while (opPresDev != 0);
}

void ReportesMenu()
{
    int opReportes;
    do
    {
        printf("-----------------------------------------------------------------\n");
        printf("|                            Reportes                           |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|Bienvenido a nuestra biblioteca digital                         |\n");
        printf("|A continuacion puedes elegir la accion que deseas realizar:     |\n");
        printf("|                                                                |\n");
        printf("|        1.-                                Libros disponibles.  |\n");
        printf("|        2.-                                Libros prestados.    |\n");
        printf("|        3.-                            Usuarios registrados.    |\n");
        printf("|        4.-                            Historial de prestamos.  |\n");
        printf("|        5.-                         Historial de devoluciones  |\n");
        printf("|        6.-           Libros con mayor numero de prestamos.     |\n");
        printf("|        7.-                     Usuarios con prestamos activos. |\n");
        printf("|        0.-                     Salir de la biblioteca.         |\n");
        printf("-----------------------------------------------------------------\n");
        scanf("%d", &opReportes);
        switch (opReportes)
        {
        case 1:
            LibrosDisponibles();
            break;
        case 2:
            LibrosPrestados();
            break;
        case 3:
            UsuariosResgistrados();
            break;
        case 4:
            HistorialPrestamos();
            break;
        case 5:
            HistorialDevoluciones();
            break;
        case 6:
            LibrosMayorPrestamos();
            break;
        case 7:
            UsuariosPrestamosActivos();
            break;
        case 0:
            printf("Saliendo al menu principal\n");
            break;
        default:
            printf("Esa opcion no existe\n");
            break;
        }
    } while (opReportes != 0);
}

// ADMINISTRACION DE USUARIOS
void RegistroUsu()
{
 
    printf("-----------------------------------------------------------------\n");
    printf("|                    Administracion de Usuarios                 |\n");
    printf("|                                    > Registro de Usuario      |\n");
    printf("-----------------------------------------------------------------\n");

}

void ModificarInf()
{
 

    printf("-----------------------------------------------------------------\n");
    printf("|                    Administracion de Usuarios                 |\n");
    printf("|                                   > Modificar Informacion     |\n");
    printf("-----------------------------------------------------------------\n");

}

void BuscarUsu()
{

        printf("-----------------------------------------------------------------\n");
        printf("|                    Administracion de Usuarios                 |\n");
        printf("|                                    > Buscar Usuario           |\n");
        printf("-----------------------------------------------------------------\n");

}

void ConsultarUsuRegistrados()
{
  
        printf("-----------------------------------------------------------------\n");
        printf("|                    Administracion de Usuarios                 |\n");
        printf("|                            > Consultar Usuarios Registrados   |\n");
        printf("-----------------------------------------------------------------\n");

}

void EliminarUsu()
{
  
        printf("-----------------------------------------------------------------\n");
        printf("|                    Administracion de Usuarios                 |\n");
        printf("|                                     > Eliminar Usario         |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|Aqui podras eliminar a un usuario mediante su matricula        |\n");
        printf("-----------------------------------------------------------------\n");

}

// ADMINISTRACION DE LIBROS
void RegistrarLibros()
{
  
    printf("-----------------------------------------------------------------\n");
    printf("|                    Administracion de Libros                   |\n");
    printf("|                                     > Registrar Libros        |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|Aqui podras registrar un libro, medante su categoria, titulo    |\n");
    printf("|y autor                                                         |\n");
    printf("-----------------------------------------------------------------\n");
  
}

void ModificarLibros()
{

}

void EliminarLibros()
{

   
}

void BuscarLibros()
{
 
}

void ConsultarDisponibilidad()
{
  

    printf("-----------------------------------------------------------------\n");
    printf("|                    Administracion de Libros                   |\n");
    printf("|                                     > Consultar Disponibilidad|\n");
    printf("-----------------------------------------------------------------\n");
 
}

void ClasificarCategoria()
{
  

    printf("-----------------------------------------------------------------\n");
    printf("|                    Administracion de Libros                   |\n");
    printf("|                                  > Clasificar por Categoria   |\n");
    printf("-----------------------------------------------------------------\n");
    

}

// PRESTAMOS/DEVOLUCIONES
void RegistrarPrestamo()
{

    printf("-----------------------------------------------------------------\n");
    printf("|                     Prestamos                                 |\n");
    printf("|                                > Registrar Prestamo           |\n");
    printf("-----------------------------------------------------------------\n");

}

void RegistrarDevolucion()
{

    printf("-----------------------------------------------------------------\n");
    printf("|                     Prestamos/Devoluciones                    |\n");
    printf("|                               > Registrar Devolucion          |\n");
    printf("-----------------------------------------------------------------\n");

   
    
}

// REPORTES
void LibrosDisponibles()
{

    printf("-----------------------------------------------------------------\n");
    printf("|                            Reportes                           |\n");
    printf("|                             > Libros Disponibles              |\n");
    printf("-----------------------------------------------------------------\n");

}

void LibrosPrestados()
{
    printf("-----------------------------------------------------------------\n");
    printf("|                            Reportes                           |\n");
    printf("|                                > Libros Prestados             |\n");
    printf("-----------------------------------------------------------------\n");
}

void UsuariosResgistrados()
{
    printf("-----------------------------------------------------------------\n");
    printf("|                            Reportes                           |\n");
    printf("|                             > Usuarios Registrados            |\n");
    printf("-----------------------------------------------------------------\n");
}

void HistorialPrestamos()
{
    printf("-----------------------------------------------------------------\n");
    printf("|                            Reportes                           |\n");
    printf("|                             > Historial de Prestamos          |\n");
    printf("-----------------------------------------------------------------\n");
}

void HistorialDevoluciones()
{
  
}

void LibrosMayorPrestamos()
{
  
}

void UsuariosPrestamosActivos()
{
   

    
}