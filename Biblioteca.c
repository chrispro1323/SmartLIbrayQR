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

// Arreglos struct y variables para prestamos
typedef struct
{
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
void UsuariosRegistrados();
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
        printf("|        2.-                      Administracion de Libros.      |\n");
        printf("|        3.-                        Prestamos/Devoluciones.      |\n");
        printf("|        4.-                                      Reportes.      |\n");
        printf("|        0.-                        Salir de la biblioteca.      |\n");
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
        printf("|                    Administracion de Usuarios                  |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|Bienvenido a nuestra biblioteca digital                         |\n");
        printf("|A continuacion puedes elegir la accion que deseas realizar:     |\n");
        printf("|                                                                |\n");
        printf("|        1.-                           Registro de Usuarios.     |\n");
        printf("|        2.-                          Modificar informacion.     |\n");
        printf("|        3.-                                Buscar Usuarios.     |\n");
        printf("|        4.-                           Usuarios registrados.     |\n");
        printf("|        5.-                              Eliminar Usuarios      |\n");
        printf("|        0.-                         Salir de la biblioteca      |\n");
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
        printf("|                   Administracion de libros                     |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|Bienvenido a nuestra biblioteca digital                         |\n");
        printf("|A continuacion puedes elegir la accion que deseas realizar:     |\n");
        printf("|                                                                |\n");
        printf("|        1.-                             Registrar libros.       |\n");
        printf("|        2.-                             Modificar libros.       |\n");
        printf("|        3.-                              Eliminar libros.       |\n");
        printf("|        4.-                                Buscar libros.       |\n");
        printf("|        5.-                     Consultar disponibilidad.       |\n");
        printf("|        6.-              Clasificar libros por categoria.       |\n");
        printf("|        0.-                       Salir de la biblioteca.       |\n");
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
        printf("|                     Prestamos/Devoluciones.                    |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|Bienvenido a nuestra biblioteca digital                         |\n");
        printf("|A continuacion puedes elegir la accion que deseas realizar:     |\n");
        printf("|                                                                |\n");
        printf("|        1.-                         Registrar un prestamo.      |\n");
        printf("|        2.-                      Registrar una devolucion.      |\n");
        printf("|        0.-                        Salir de la biblioteca.      |\n");
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
        printf("|                            Reportes                            |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|Bienvenido a nuestra biblioteca digital                         |\n");
        printf("|A continuacion puedes elegir la accion que deseas realizar:     |\n");
        printf("|                                                                |\n");
        printf("|        1.-                              Libros disponibles.    |\n");
        printf("|        2.-                                Libros prestados.    |\n");
        printf("|        3.-                            Usuarios registrados.    |\n");
        printf("|        4.-                          Historial de prestamos.    |\n");
        printf("|        5.-                       Historial de devoluciones.    |\n");
        printf("|        6.-            Libros con mayor numero de prestamos.    |\n");
        printf("|        7.-                  Usuarios con prestamos activos.    |\n");
        printf("|        0.-                          Salir de la biblioteca.    |\n");
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
            UsuariosRegistrados();
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
    char UsuarioNuevo[50];
    char comando[150];
    int Matricula, matricularep;
    int x;
    printf("-----------------------------------------------------------------\n");
    printf("|                    Administracion de Usuarios                 |\n");
    printf("|                                    > Registro de Usuario      |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|Aqui podras crearte un usuario, utilizaras tu matricula.       |\n");
    printf("-----------------------------------------------------------------\n");
    // PEDIR USUARIO
    do
    {
        printf("|>Ingresa tu nombre de usuario                                  |\n");
        printf("|>Sin espacios y solo 8 caracteres maximo:                      |\n");
        scanf("%49s", UsuarioNuevo);
        if (strlen(UsuarioNuevo) > 8)
        {
            printf("|El nombre de usuario solo admite 8 caracteres                  |\n");
        }
    } while (strlen(UsuarioNuevo) > 8);
    // PEDIR MATRICULA
    do
    {
        matricularep = Falso;
        printf("|> Ingresa tu matricula (9 digitos):                            |\n");
        scanf("%d", &Matricula);
        if (Matricula > 999999999 || Matricula < 100000000)
        {
            printf("|La matricula debe ser de 9 digitos                             |\n");
        }
        else
        {
            // RECORREMOS EL ARREGLO PARA VERIFICAR SI LA MATRICULA YA EXISTE
            for (x = 0; x < totalUsuarios; x++)
            {
                if (listaUsuarios[x].matricula == Matricula)
                {
                    printf("Esta matricula ya existe\n");
                    matricularep = Verdadero;
                }
            }
        }
    } while (!((Matricula <= 999999999 && Matricula >= 100000000) && !matricularep));
    // GUARDAMOS LOS DATOS EN EL STRUCT Y SUBIMOS EL CONTADOR DE USUARIOS
    listaUsuarios[totalUsuarios].matricula = Matricula;
    strcpy(listaUsuarios[totalUsuarios].nombre, UsuarioNuevo);
    listaUsuarios[totalUsuarios].prestamosActivos = 0;
    totalUsuarios++;
    // GENERAMOS EL CODIGO QR DEL USUARIO
    sprintf(comando, "qrencode -o ..\\qrcodes\\usuario_%d.png \"USUARIO: %s - MATRICULA: %d\"", Matricula, UsuarioNuevo, Matricula);
    system(comando);

    printf("-----------------------------------------------------------------\n");
    printf("|Usuario creado con exito.                                      |\n");
    printf("-----------------------------------------------------------------\n");
}

void ModificarInf()
{
    char UsuarioNuevo[50];
    int BuscarMatricula, Matriculaencontrada;
    int x;
    char comando[150];
    printf("-----------------------------------------------------------------\n");
    printf("|                    Administracion de Usuarios                 |\n");
    printf("|                                   > Modificar Informacion     |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|Aqui podras cambiar tu nombre de usuario, tu matricula es tu.   |\n");
    printf("|identificador unico                                             |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|>Ingresa tu matricula:                                         |\n");
    scanf("%d", &BuscarMatricula);
    // VERIFICAMOS SI EL REGISTRO ESTA VACIO
    if (totalUsuarios == 0)
    {
        printf("El registro esta vacio, puedes registrarte en Registro de Usuario.\n");
    }
    else
    {
        Matriculaencontrada = Falso;
        // BUSCAMOS AL USUARIO MEDIANTE SU MATRICULA
        for (x = 0; x < totalUsuarios; x++)
        {
            if (listaUsuarios[x].matricula == BuscarMatricula)
            {
                printf("|Matricula Encontrada                                           |\n");
                Matriculaencontrada = Verdadero;
                // PEDIMOS EL NUEVO NOMBRE DE USUARIO
                do
                {
                    printf("|> Ingresa el nuevo usuario                                     |\n");
                    printf("|>Sin espacios y solo 8 caracteres maximo:                      |\n");
                    scanf("%49s", UsuarioNuevo);
                    if (strlen(UsuarioNuevo) > 8)
                    {
                        printf("|El nombre de usuario solo admite 8 caracteres                  |\n");
                    }
                } while (strlen(UsuarioNuevo) > 8);
                // SE ACTUALIZA EL STRUCT
                strcpy(listaUsuarios[x].nombre, UsuarioNuevo);
                // ACUTALIZAMOS EL QR DEL USUARIO
                sprintf(comando, "qrencode -o ..\\qrcodes\\usuario_%d.png \"USUARIO: %s - MATRICULA: %d\"", BuscarMatricula, UsuarioNuevo, BuscarMatricula);
                system(comando);
            }
        }
        if (!Matriculaencontrada)
        {
            printf("Esta matricula no existe\n");
        }
        else
        {
            printf("-----------------------------------------------------------------\n");
            printf("|Usuario cambiado con exito: %-8s                           |\n", UsuarioNuevo);
            printf("-----------------------------------------------------------------\n");
        }
    }
}

void BuscarUsu()
{
    int BuscarMatricula, Matriculaencontrada;
    int x;
    // VERIFICAMOS SI EL REGISTRO ESTA VACIO
    if (totalUsuarios == 0)
    {
        printf("El registro esta vacio, puedes registrarte en Registro de Usuario.\n");
    }
    else
    {
        printf("-----------------------------------------------------------------\n");
        printf("|                    Administracion de Usuarios                 |\n");
        printf("|                                    > Buscar Usuario           |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|Aqui podras buscar a un usuario miediante su matricula          |\n");
        printf("-----------------------------------------------------------------\n");
        printf(">Ingresa la matricula\n");
        scanf("%d", &BuscarMatricula);
        Matriculaencontrada = Falso;
        // BUSCAMOS AL USUARIO MEDIANTE SU MATRICULA
        for (x = 0; x < totalUsuarios; x++)
        {
            if (listaUsuarios[x].matricula == BuscarMatricula)
            {
                printf("-----------------------------------------------------------------\n");
                printf("|Usuario encontrado                                             |\n");
                printf("-----------------------------------------------------------------\n");
                printf("|            Matricula           |           Usuario            |\n");
                printf("-----------------------------------------------------------------\n");
                printf("|            %-9d           :           %-8s           |\n",
                       listaUsuarios[x].matricula, listaUsuarios[x].nombre);
                printf("-----------------------------------------------------------------\n");
                Matriculaencontrada = Verdadero;
            }
        }
        if (!Matriculaencontrada)
        {
            printf("Matricula inexistente\n");
        }
    }
}

void ConsultarUsuRegistrados()
{
    int x;
    // VERIFICAMOS SI EL REGISTRO ESTA VACIO
    if (totalUsuarios == 0)
    {
        printf("El registro esta vacio, puedes registrarte en Registro de Usuario.\n");
    }
    else
    {
        printf("-----------------------------------------------------------------\n");
        printf("|                    Administracion de Usuarios                 |\n");
        printf("|                            > Consultar Usuarios Registrados   |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|            Matricula           |           Usuario            |\n");
        printf("-----------------------------------------------------------------\n");
        // SE MUESTRA LA LISTA DE USUARIOS REGISTRADOS
        for (x = 0; x < totalUsuarios; x++)
        {
            printf("|            %-9d           :           %-8s           |\n",
                   listaUsuarios[x].matricula, listaUsuarios[x].nombre);
        }
        printf("-----------------------------------------------------------------\n");
    }
}

void EliminarUsu()
{
    int BuscarMatricula, Matriculaencontrada;
    int x, j, i;
    // VERIFICAMOS SI EL REGISTRO ESTA VACIO
    if (totalUsuarios == 0)
    {
        printf("El registro esta vacio, puedes registrarte en Registro de Usuario.\n");
    }
    else
    {
        printf("-----------------------------------------------------------------\n");
        printf("|                    Administracion de Usuarios                 |\n");
        printf("|                                     > Eliminar Usario         |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|Aqui podras eliminar a un usuario mediante su matricula        |\n");
        printf("-----------------------------------------------------------------\n");
        printf(">Ingresa la matricula\n");
        scanf("%d", &BuscarMatricula);
        Matriculaencontrada = Falso;
        // BUSCAMOS AL USUARIO MEDIANTE SU MATRICULA
        for (x = 0; x < totalUsuarios; x++)
        {
            if (listaUsuarios[x].matricula == BuscarMatricula)
            {
                printf("-----------------------------------------------------------------\n");
                printf("|Usuario encontrado                                             |\n");
                printf("-----------------------------------------------------------------\n");
                printf("|            Matricula           |           Usuario            |\n");
                printf("-----------------------------------------------------------------\n");
                printf("|            %-9d           :           %-8s           |\n",
                       listaUsuarios[x].matricula, listaUsuarios[x].nombre);
                printf("-----------------------------------------------------------------\n");
                // SE PIDE CONFIRMACION PARA ELIMINAR AL USUARIO
                printf("¿Estas seguro de eliminar el usuario? Si/No\n");
                scanf("%49s", ConfirmarUsuario);

                for (i = 0; ConfirmarUsuario[i] != '\0'; i++)
                {
                    ConfirmarUsuario[i] = tolower((unsigned char)ConfirmarUsuario[i]);
                }
                if (strcmp(ConfirmarUsuario, "si") == 0)
                {
                    for (j = x; j < totalUsuarios - 1; j++)
                    {
                        listaUsuarios[j] = listaUsuarios[j + 1];
                    }
                    totalUsuarios--;
                    printf("-----------------------------------------------------------------\n");
                    printf("|Usuario Eliminado                                              |\n");
                    printf("-----------------------------------------------------------------\n");
                }
                else
                {
                    printf("-----------------------------------------------------------------\n");
                    printf("|Eliminación Cancelada                                          |\n");
                    printf("-----------------------------------------------------------------\n");
                }
                Matriculaencontrada = Verdadero;
            }
        }
        if (!Matriculaencontrada)
        {
            printf("Matricula inexistente\n");
        }
    }
}

// ADMINISTRACION DE LIBROS
void RegistrarLibros()
{
    char TituloLibro[100], AutorLibro[100], CategoriaLibro[40];
    int opCategoria, CantCopias, LibrosID;
    int x;
    char comando[500];

    printf("-----------------------------------------------------------------\n");
    printf("|                    Administracion de Libros                   |\n");
    printf("|                                     > Registrar Libros        |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|Aqui podras registrar un libro, medante su categoria, titulo    |\n");
    printf("|y autor                                                         |\n");
    printf("-----------------------------------------------------------------\n");
    do
    {
        printf(">Que categoria es el libro\n");
        printf("-----------------------------------------------------------------\n");
        printf("| CATEGORIAS:                                                   |\n");
        printf("|        1.- Medicina y Salud                                   |\n");
        printf("|        2.- Derecho y Ciencias Sociales                        |\n");
        printf("|        3.- Contaduria y Administracion                        |\n");
        printf("|        4.- Ingenieria y Sistemas                              |\n");
        printf("|        5.- Humanidades y Pedagogia                            |\n");
        printf("|        6.- Ciencias Agropecuarias                             |\n");
        printf("|        7.- Literatura y Ficcion                               |\n");
        printf("|        8.- Historia, Arte y Chiapas                           |\n");
        printf("-----------------------------------------------------------------\n");
        scanf("%d", &opCategoria);
        if (opCategoria < 1 || opCategoria > 8)
        {
            printf("Esa opción no esta dentro de los parametros\n");
        }
    } while (!(opCategoria >= 1 && opCategoria <= 8));

    switch (opCategoria)
    {
    case 1:
        strcpy(CategoriaLibro, "Medicina y Salud");
        break;
    case 2:
        strcpy(CategoriaLibro, "Derecho y Ciencias Sociales");
        break;
    case 3:
        strcpy(CategoriaLibro, "Contaduria y Administracion");
        break;
    case 4:
        strcpy(CategoriaLibro, "Ingenieria y Sistemas");
        break;
    case 5:
        strcpy(CategoriaLibro, "Humanidades y Pedagogia");
        break;
    case 6:
        strcpy(CategoriaLibro, "Ciencias Agropecuarias");
        break;
    case 7:
        strcpy(CategoriaLibro, "Literatura y Ficcion");
        break;
    case 8:
        strcpy(CategoriaLibro, "Historia, Arte y Chiapas");
        break;
    }

    do
    {
        printf(">Ingresa el titulo del libro\n");
        scanf(" %99[^\n]", TituloLibro);
        if (strlen(TituloLibro) == 0)
        {
            printf("Debes llenar este campo si quieres continuar\n");
        }
    } while (!(strlen(TituloLibro) > 0));

    do
    {
        printf(">Ingresa el nombre del autor\n");
        scanf(" %99[^\n]", AutorLibro);
        if (strlen(AutorLibro) == 0)
        {
            printf("Debes llenar este campo si quieres continuar\n");
        }
    } while (!(strlen(AutorLibro) > 0));

    do
    {
        printf(">Cuantas copias de este libro hay\n");
        scanf("%d", &CantCopias);
        if (CantCopias <= 0)
        {
            printf("Debe haber minimo una copia de este libro\n");
        }
    } while (!(CantCopias > 0));

    printf("-----------------------------------------------------------------\n");
    printf("|          Numero Copias          |             Id              |\n");
    printf("-----------------------------------------------------------------\n");

    for (x = 0; x < CantCopias; x++)
    {

        contCategoria[opCategoria]++;
        LibrosID = (opCategoria * 1000) + contCategoria[opCategoria];

        listaLibros[totalLibros].id = LibrosID;
        strcpy(listaLibros[totalLibros].titulo, TituloLibro);
        strcpy(listaLibros[totalLibros].autor, AutorLibro);
        strcpy(listaLibros[totalLibros].categoria, CategoriaLibro);
        listaLibros[totalLibros].disponible = Verdadero;
        listaLibros[totalLibros].numeroPrestamosHistoricos = 0;
        sprintf(comando, "qrencode -o ..\\qrcodes\\libro_%d.png \"ID: %d - TITULO: %s - AUTOR: %s - CATEGORIA: %s\"", LibrosID, LibrosID, TituloLibro, AutorLibro, CategoriaLibro);
        system(comando);

        printf("|                %d                |             %d              |\n", x + 1, LibrosID);
        totalLibros++;
    }
    printf("-----------------------------------------------------------------\n");
    printf("|Se registraron %d copias con exito.                             |\n", CantCopias);
    printf("-----------------------------------------------------------------\n");
}

void ModificarLibros()
{
    char nombreTitulo[50];
    int opModificar, opCategoria, indiceLIbro = -1;
    char nuevoTitulo[50];
    char nuevoAutor[50];

    char nuevaCategoria[50];
    int modificado = Falso;
    if (totalLibros == 0)
    {
        printf("-----------------------------------------------------------------\n");
        printf("|                    NO HAY LIBROS REGISTRADOS                   |\n");
        printf("-----------------------------------------------------------------\n");
        return;
    }

    printf("-----------------------------------------------------------------\n");
    printf("|                    Administracion de Libros                   |\n");
    printf("|                                     > Modificar Libros        |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|Para poder modificar un libro buscalo mediante su titulo       |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Ingresa el titulo: ");
    scanf(" %99[^\n]", nombreTitulo);
    printf("\n");

    for (int i = 0; i < totalLibros; i++)
    {
        if (strcmp(listaLibros[i].titulo, nombreTitulo) == 0)
        {
            indiceLIbro = i;
            break;
        }
    }

    if (indiceLIbro == -1)
    {
        printf("EL libro no existe en el sistema\n");
        return;
    }

    printf("-----------------------------------------------------------------\n");
    printf("|Libro encontrado                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|            ID           |           Autor            |              Titulo           |             Categoria             |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|        %d          :          %s                :         %s               :               %s               |\n",
           listaLibros[indiceLIbro].id, listaLibros[indiceLIbro].autor, listaLibros[indiceLIbro].titulo, listaLibros[indiceLIbro].categoria);
    printf("-----------------------------------------------------------------\n");

    do
    {
        printf("¿Que deseas modificar? \n[1]Titulo\n[2]Autor\n[3]Categoria\n[4]Salir\n");
        scanf("%d", &opModificar);
        switch (opModificar)
        {
        case 1:
            printf("Ingresa el nuevo titulo\n");
            scanf(" %99[^\n]", nuevoTitulo);

            for (int i = 0; i < totalLibros; i++)
            {
                if (strcmp(listaLibros[i].titulo, nombreTitulo) == 0)
                {
                    strcpy(listaLibros[i].titulo, nuevoTitulo);
                    modificado = Verdadero;
                }
            }
            if (modificado)
            {
                strcpy(nombreTitulo, nuevoTitulo);
            }
            printf("Titulo actualizado con exito\n");
            break;
        case 2:
            printf("Ingresa el nombre del autor\n");
            scanf(" %99[^\n]", nuevoAutor);
            for (int i = 0; i < totalLibros; i++)
            {
                if (strcmp(listaLibros[i].titulo, nombreTitulo) == 0)
                {
                    strcpy(listaLibros[i].autor, nuevoAutor);
                }
            }
            printf("Autor actualizado con exito\n");
            break;

        case 3:
            do
            {
                printf(">Ingresa la categoria\n");
                printf("-----------------------------------------------------------------\n");
                printf("| CATEGORIAS:                                                   |\n");
                printf("|        1.- Medicina y Salud                                   |\n");
                printf("|        2.- Derecho y Ciencias Sociales                        |\n");
                printf("|        3.- Contaduria y Administracion                        |\n");
                printf("|        4.- Ingenieria y Sistemas                              |\n");
                printf("|        5.- Humanidades y Pedagogia                            |\n");
                printf("|        6.- Ciencias Agropecuarias                             |\n");
                printf("|        7.- Literatura y Ficcion                               |\n");
                printf("|        8.- Historia, Arte y Chiapas                           |\n");
                printf("-----------------------------------------------------------------\n");
                scanf("%d", &opCategoria);
                if (opCategoria < 1 || opCategoria > 8)
                {
                    printf("Esa opción no esta dentro de los parametros\n");
                }
            } while (!(opCategoria >= 1 && opCategoria <= 8));

            switch (opCategoria)
            {
            case 1:
                strcpy(nuevaCategoria, "Medicina y Salud");
                break;
            case 2:
                strcpy(nuevaCategoria, "Derecho y Ciencias Sociales");
                break;
            case 3:
                strcpy(nuevaCategoria, "Contaduria y Administracion");
                break;
            case 4:
                strcpy(nuevaCategoria, "Ingenieria y Sistemas");
                break;
            case 5:
                strcpy(nuevaCategoria, "Humanidades y Pedagogia");
                break;
            case 6:
                strcpy(nuevaCategoria, "Ciencias Agropecuarias");
                break;
            case 7:
                strcpy(nuevaCategoria, "Literatura y Ficcion");
                break;
            case 8:
                strcpy(nuevaCategoria, "Historia, Arte y Chiapas");
                break;
            }

            for (int i = 0; i < totalLibros; i++)
            {
                if (strcmp(listaLibros[i].titulo, nombreTitulo) == 0)
                {
                    strcpy(listaLibros[i].categoria, nuevaCategoria);
                }
            }
            printf("La categoria actualizada en todas las copias\n");
            break;
        case 4:
            printf("Saliendo...\n");

            break;

        default:
            printf("Esta opcion no existe\n");

            break;
        }

    } while (opModificar != 4);
}

void EliminarLibros()
{

    int libroExiste = Falso;
    char tituloLibro[50];
    char confirmarLIbro[40];

    printf("-----------------------------------------------------------------\n");
    printf("|                    Administracion de Libros                   |\n");
    printf("|                                      > Eliminar Libros        |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|Aqui podras eliminar a un libro mediante su titulo                 |\n");
    printf("-----------------------------------------------------------------\n");
    if (totalLibros == 0)
    {
        printf("|            NO SE ENCUENTRAN LIBROS DISPONIBLES              |\n");
        printf("-----------------------------------------------------------------\n");
        return;
    }
    printf("Ingresa su titulo: ");
    scanf(" %49[^\n]", tituloLibro);
    printf("\n");

    for (int i = 0; i < totalLibros; i++)
    {
        if (strcmp(listaLibros[i].titulo, tituloLibro) == 0)
        {
            libroExiste = Verdadero;
            printf("-----------------------------------------------------------------\n");
            printf("|Libro encontrado                                               |\n");
            printf("-----------------------------------------------------------------\n");
            printf("|            ID           |           Autor            |              Titulo           |             Categoria             |\n");
            printf("-----------------------------------------------------------------\n");
            printf("|         %d          :         %s                :          %s               :          %s               |\n",
                   listaLibros[i].id, listaLibros[i].autor, listaLibros[i].titulo, listaLibros[i].categoria);
            printf("-----------------------------------------------------------------\n");
            break;
        }
    }

    if (libroExiste)
    {
        printf("¿Estas seguro de eliminar el libro? si/no\n");
        scanf("%49s", confirmarLIbro);

        for (int i = 0; confirmarLIbro[i] != '\0'; i++)
        {
            confirmarLIbro[i] = tolower((unsigned char)confirmarLIbro[i]);
        }

        if (strcmp(confirmarLIbro, "si") == 0)
        {
            int i = 0;
            while (i < totalLibros)
            {
                if (strcmp(listaLibros[i].titulo, tituloLibro) == 0)
                {
                    for (int j = i; j < totalLibros - 1; j++)
                    {
                        listaLibros[j] = listaLibros[j + 1];
                    }
                    totalLibros--;
                }
                else
                {
                    i++;
                }
            }

            printf("-----------------------------------------------------------------\n");
            printf("|Todas las copias del libro fueron eliminadas con exito.       |\n");
            printf("-----------------------------------------------------------------\n");
        }
        else
        {
            printf("-----------------------------------------------------------------\n");
            printf("|Eliminacion cancelada.                                         |\n");
            printf("-----------------------------------------------------------------\n");
        }
    }
    else
    {

        printf("-----------------------------------------------------------------\n");
        printf("|No se encontro ningun libro con ese titulo.                     |\n");
        printf("-----------------------------------------------------------------\n");
    }
}

void BuscarLibros()
{
    int opBuscar, IDLibro, libroExiste = Falso;
    char libroTitulo[50];

    printf("-----------------------------------------------------------------\n");
    printf("|                    Administracion de Libros                   |\n");
    printf("|                                        > Buscar Libros        |\n");
    printf("-----------------------------------------------------------------\n");
    if (totalLibros == 0)
    {
        printf("|               NO EXISTEN LIBROS                               |\n");
        printf("-----------------------------------------------------------------\n");
        return;
    }
    printf("¿Como deseas buscar el libro? [1]ID [2]Titulo\nElige: ");
    scanf("%d", &opBuscar);
    printf("\n");

    switch (opBuscar)
    {
    case 1:
        printf("Ingresa el ID: ");
        scanf("%d", &IDLibro);
        printf("\n");

        for (int i = 0; i < totalLibros; i++)
        {
            if (listaLibros[i].id == IDLibro)
            {
                libroExiste = Verdadero;
                printf("-----------------------------------------------------------------\n");
                printf("|Libro encontrado                                               |\n");
                printf("-----------------------------------------------------------------\n");
                printf("|            ID           |           Autor            |              Titulo           |             Categoria             |\n");
                printf("-----------------------------------------------------------------\n");
                printf("|       %d         :          %s             :           %s             :          %s           |\n",
                       listaLibros[i].id, listaLibros[i].autor, listaLibros[i].titulo, listaLibros[i].categoria);
                printf("-----------------------------------------------------------------\n");
                break;
            }
        }
        if (!libroExiste)
        {
            printf("-----------------------------------------------------------------\n");
            printf("|               No se encontro ningun libro                        |\n");
            printf("-----------------------------------------------------------------\n");
        }
        break;
    case 2:
        printf("Ingresa el titulo del libro\n");
        scanf(" %49[^\n]", libroTitulo);

        for (int i = 0; i < totalLibros; i++)
        {
            if (strcmp(listaLibros[i].titulo, libroTitulo) == 0)
            {
                libroExiste = Verdadero;
                printf("-----------------------------------------------------------------\n");
                printf("|Libro encontrado                                               |\n");
                printf("-----------------------------------------------------------------\n");
                printf("|            ID           |           Autor            |              Titulo           |             Categoria             |\n");
                printf("-----------------------------------------------------------------\n");
                printf("|            %d          :           %s                :              %s               :                  %s               |\n",
                       listaLibros[i].id, listaLibros[i].autor, listaLibros[i].titulo, listaLibros[i].categoria);
                printf("-----------------------------------------------------------------\n");
                break;
            }
        }
        if (!libroExiste)
        {
            printf("-----------------------------------------------------------------\n");
            printf("|               No se encontro ningun libro                        |\n");
            printf("-----------------------------------------------------------------\n");
        }
        break;
    default:
        printf("Opcion invalida\n");
        break;
    }
}

void ConsultarDisponibilidad()
{
    char tituloLibro[50];
    int copiasTotales = 0, copiasDisponibles = 0, indiceLibro;

    printf("-----------------------------------------------------------------\n");
    printf("|                    Administracion de Libros                   |\n");
    printf("|                                     > Consultar Disponibilidad|\n");
    printf("-----------------------------------------------------------------\n");
    if (totalLibros == 0)
    {
        printf("|                       NO EXISTE NINGUN LIBRO                   |\n");
        printf("-----------------------------------------------------------------\n");
        return;
    }
    printf("Ingresa el titulo del libro para consultar su disponibilidad: \n");
    scanf(" %49[^\n]", tituloLibro);

    for (int i = 0; i < totalLibros; i++)
    {
        if (strcmp(listaLibros[i].titulo, tituloLibro) == 0)
        {
            indiceLibro = i;
            copiasTotales++;
            if (listaLibros[i].disponible == Verdadero)
            {
                copiasDisponibles++;
            }
        }
    }

    if (copiasTotales == 0)
    {
        printf("-----------------------------------------------------------------\n");
        printf("|                     No existe el libro                        |\n");
        printf("-----------------------------------------------------------------\n");
    }
    else if (copiasTotales > 0)
    {
        printf("-----------------------------------------------------------------\n");
        printf("|Libro encontrado                                               |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|           Autor            |              Titulo           |             Categoria             |          Disponibilidad           |\n");
        printf("-----------------------------------------------------------------\n");
        printf("|      %s                :              %s               :         %s          :           %d copias        |\n",
               listaLibros[indiceLibro].autor, listaLibros[indiceLibro].titulo, listaLibros[indiceLibro].categoria, copiasDisponibles);
        printf("-----------------------------------------------------------------\n");
    }
}

void ClasificarCategoria()
{
    int opCategoria, NoExistenLibros = Falso;
    char categoriaBuscada[50];

    printf("-----------------------------------------------------------------\n");
    printf("|                    Administracion de Libros                   |\n");
    printf("|                                  > Clasificar por Categoria   |\n");
    printf("-----------------------------------------------------------------\n");

    if (totalLibros == 0)
    {
        printf("|            NO SE ENCUENTRAN LIBROS DISPONIBLES              |\n");
        printf("-----------------------------------------------------------------\n");
        return;
    }

    do
    {
        printf(">Que categoria es el libro\n");
        printf("-----------------------------------------------------------------\n");
        printf("| CATEGORIAS:                                                   |\n");
        printf("|        1.- Medicina y Salud                                   |\n");
        printf("|        2.- Derecho y Ciencias Sociales                        |\n");
        printf("|        3.- Contaduria y Administracion                        |\n");
        printf("|        4.- Ingenieria y Sistemas                              |\n");
        printf("|        5.- Humanidades y Pedagogia                            |\n");
        printf("|        6.- Ciencias Agropecuarias                             |\n");
        printf("|        7.- Literatura y Ficcion                               |\n");
        printf("|        8.- Historia, Arte y Chiapas                           |\n");
        printf("-----------------------------------------------------------------\n");
        scanf("%d", &opCategoria);
        if (opCategoria < 1 || opCategoria > 8)
        {
            printf("Esa opcion no esta dentro de los parametros\n");
        }
    } while (!(opCategoria >= 1 && opCategoria <= 8));

    switch (opCategoria)
    {
    case 1:
        strcpy(categoriaBuscada, "Medicina y Salud");
        break;
    case 2:
        strcpy(categoriaBuscada, "Derecho y Ciencias Sociales");
        break;
    case 3:
        strcpy(categoriaBuscada, "Contaduria y Administracion");
        break;
    case 4:
        strcpy(categoriaBuscada, "Ingenieria y Sistemas");
        break;
    case 5:
        strcpy(categoriaBuscada, "Humanidades y Pedagogia");
        break;
    case 6:
        strcpy(categoriaBuscada, "Ciencias Agropecuarias");
        break;
    case 7:
        strcpy(categoriaBuscada, "Literatura y Ficcion");
        break;
    case 8:
        strcpy(categoriaBuscada, "Historia, Arte y Chiapas");
        break;
    }

    printf("-----------------------------------------------------------------\n");
    printf("|Categoria: %-52s|\n", categoriaBuscada);
    printf("-----------------------------------------------------------------\n");
    printf("|            ID           |           Autor            |              Titulo           |\n");
    printf("---------------------------------------------------------------------------------------\n");

    for (int i = 0; i < totalLibros; i++)
    {
        if (strcmp(listaLibros[i].categoria, categoriaBuscada) == 0)
        {
            NoExistenLibros = Verdadero;

            printf("|            %-13d:           %-17s:              %-17s|\n",
                   listaLibros[i].id, listaLibros[i].autor, listaLibros[i].titulo);
            printf("---------------------------------------------------------------------------------------\n");
        }
    }

    if (!NoExistenLibros)
    {
        printf("-----------------------------------------------------------------\n");
        printf("|            NO HAY LIBROS DISPONIBLES EN ESTA CATEGORIA         |\n");
        printf("-----------------------------------------------------------------\n");
    }
}

// PRESTAMOS/DEVOLUCIONES
void RegistrarPrestamo()
{
    int QRMatriculaUsuario, QRIDLibro, matriculaEncontradaUsuario = Falso, IDEncontradoLibro = Falso, copiaDisponible = Falso;
    int indiceUsuario;

    printf("-----------------------------------------------------------------\n");
    printf("|                     Prestamos                                 |\n");
    printf("|                                > Registrar Prestamo           |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Escanea el codigo QR del usuario....\n");
    scanf("%d", &QRMatriculaUsuario);

    for (int i = 0; i < totalUsuarios; i++)
    {
        if (listaUsuarios[i].matricula == QRMatriculaUsuario)
        {
            matriculaEncontradaUsuario = Verdadero;
            indiceUsuario = i;
            break;
        }
    }
    if (!matriculaEncontradaUsuario)
    {
        printf("-----------------------------------------------------------------\n");
        printf("|                  No se encontro la matricula                  |\n");
        printf("-----------------------------------------------------------------\n");
        return;
    }

    printf("Escanea el QR del libro que desee....\n");
    scanf("%d", &QRIDLibro);
    for (int i = 0; i < totalLibros; i++)
    {
        if (listaLibros[i].id == QRIDLibro)
        {
            IDEncontradoLibro = Verdadero;

            if (listaLibros[i].disponible == Verdadero)
            {
                copiaDisponible = Verdadero;
                listaPrestamos[totalPrestamos].idPrestamo = totalPrestamos + 1;
                listaPrestamos[totalPrestamos].matriculaUsuario = QRMatriculaUsuario;
                listaPrestamos[totalPrestamos].idLibro = QRIDLibro;
                listaPrestamos[totalPrestamos].devuelto = Falso;
                totalPrestamos++;

                listaUsuarios[indiceUsuario].prestamosActivos++;

                listaLibros[i].disponible = Falso;
                listaLibros[i].numeroPrestamosHistoricos++;

                printf("-----------------------------------------------------------------\n");
                printf("|                  DISFRUTE EL LIBRO                             |\n");
                printf("-----------------------------------------------------------------\n");
                printf("recuerde devolver el libro\n");

                return;
            }
        }
    }

    if (!IDEncontradoLibro)
    {
        printf("-----------------------------------------------------------------\n");
        printf("|              No se encontro ningun libro con ese ID              |\n");
        printf("-----------------------------------------------------------------\n");
        return;
    }
    if (!copiaDisponible)
    {
        printf("-----------------------------------------------------------------\n");
        printf("|              No hay copias Disponibles                        |\n");
        printf("-----------------------------------------------------------------\n");
    }
}
void RegistrarDevolucion()
{
    int QRMatriculaUsuario, QRIDLibro, indiceDatosUsuario;
    int existePrestamo = Falso, cantidadPrestamos = 0, libroDevuelto = Falso;
    printf("-----------------------------------------------------------------\n");
    printf("|                     Prestamos/Devoluciones                    |\n");
    printf("|                               > Registrar Devolucion          |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Escanea el codigo QR del usuario...\n");
    scanf("%d", &QRMatriculaUsuario);

    for (int i = 0; i < totalPrestamos; i++)
    {
        if (listaPrestamos[i].matriculaUsuario == QRMatriculaUsuario && listaPrestamos[i].devuelto == Falso)
        {
            cantidadPrestamos++;
            existePrestamo = Verdadero;
        }
    }
    if (!existePrestamo)
    {
        printf("-----------------------------------------------------------------\n");
        printf("|                  Este usuario no tiene prestamos                 |\n");
        printf("-----------------------------------------------------------------\n");
        return;
    }

    for (int i = 0; i < totalUsuarios; i++)
    {
        if (listaUsuarios[i].matricula == QRMatriculaUsuario)
        {
            indiceDatosUsuario = i;
            break;
        }
    }

    printf("-----------------------------------------------------\n");
    printf("        Usuario         |       Prestamos           |\n");
    printf("          %s            :            %d              |\n",
           listaUsuarios[indiceDatosUsuario].nombre, cantidadPrestamos);
    printf("Escanea el codigo QR del libro a devolver...\n");
    scanf("%d", &QRIDLibro);

    for (int i = 0; i < totalPrestamos; i++)
    {
        if (listaPrestamos[i].idLibro == QRIDLibro && listaPrestamos[i].matriculaUsuario == QRMatriculaUsuario && listaPrestamos[i].devuelto == Falso)
        {
            libroDevuelto = Verdadero;
            listaPrestamos[i].devuelto = Verdadero;

            listaUsuarios[indiceDatosUsuario].prestamosActivos--;

            for (int i = 0; i < totalLibros; i++)
            {
                if (listaLibros[i].id == QRIDLibro)
                {
                    listaLibros[i].disponible = Verdadero;
                    break;
                }
            }

            printf("-----------------------------------------------------------------\n");
            printf("|              DEVOLUCION REGISTRADA CON EXITO                  |\n");
            printf("-----------------------------------------------------------------\n");
            return;
        }
    }

    if (!libroDevuelto)
    {
        printf("-----------------------------------------------------------------\n");
        printf("|    Este usuario no tiene prestado este libro actualmente       |\n");
        printf("-----------------------------------------------------------------\n");
    }
}

// REPORTES
void LibrosDisponibles()
{

    printf("-----------------------------------------------------------------\n");
    printf("|                            Reportes                           |\n");
    printf("|                             > Libros Disponibles              |\n");
    printf("-----------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("        Titulo             |          Autor                |             Categoria                         | Copias Disponibles |\n");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < totalLibros; i++)
    {
        int YaProcesado = Falso;
        int copiasDsiponibles = 0;

        for (int k = 0; k < i; k++)
        {
            if (strcmp(listaLibros[i].titulo, listaLibros[k].titulo) == 0)
            {
                YaProcesado = Verdadero;
                break;
            }
        }

        if (!YaProcesado)
        {
            for (int j = 0; j < totalLibros; j++)
            {
                if (strcmp(listaLibros[i].titulo, listaLibros[j].titulo) == 0 && listaLibros[j].disponible == Verdadero)
                {
                    copiasDsiponibles++;
                }
            }
            if (copiasDsiponibles > 0)
            {
                printf("%-25s       |      %-20s      | %-25s       | %d\n",
                       listaLibros[i].titulo,
                       listaLibros[i].autor,
                       listaLibros[i].categoria,
                       copiasDsiponibles);
            }

        }
    }
}
void LibrosPrestados()
{
    int hayPrestados = Falso;
    char nombreUsuario[50];
    char tituloLibro[100];
    printf("-----------------------------------------------------------------\n");
    printf("|                            Reportes                           |\n");
    printf("|                                > Libros Prestados             |\n");
    printf("-----------------------------------------------------------------\n");
    if (totalPrestamos == 0)
    {
        printf("|               No hay registro alguno de prestamos             |\n");
        printf("-----------------------------------------------------------------\n");
        return;
    }
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("    ID Prestamo    |    Matricula    |    Usuario     |    ID Libro    |              Titulo del Libro              \n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < totalPrestamos; i++)
    {
        if (listaPrestamos[i].devuelto == Falso)
        {
            hayPrestados = Verdadero;
            strcpy(nombreUsuario, "Sin registro");
            strcpy(tituloLibro, "Sin registro");
            for (int u = 0; u < totalUsuarios; u++)
            {
                if (listaUsuarios[u].matricula == listaPrestamos[i].matriculaUsuario)
                {
                    strcpy(nombreUsuario, listaUsuarios[u].nombre);
                    break;
                }
            }
            for (int l = 0; l < totalLibros; l++)
            {
                if (listaLibros[l].id == listaPrestamos[i].idLibro)
                {
                    strcpy(tituloLibro, listaLibros[l].titulo);
                    break;
                }
            }
            printf("     %-10d|     %-13d |  %-14s|   %-11d | %-45s\n",
                   listaPrestamos[i].idPrestamo,
                   listaPrestamos[i].matriculaUsuario,
                   nombreUsuario,
                   listaPrestamos[i].idLibro,
                   tituloLibro);
        }
    }

    printf("--------------------------------------------------------------------------------------------------------------------\n");

    if (!hayPrestados)
    {
        printf("-----------------------------------------------------------------\n");
        printf("|          ACTUALMENTE NO HAY LIBROS PRESTADOS                  |\n");
        printf("-----------------------------------------------------------------\n");
    }
}

void UsuariosRegistrados()
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