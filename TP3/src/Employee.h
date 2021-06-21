#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea un nuevo empleado en memoria dinámica
 *
 * \return Puntero de tipo Employee donde se alojará el nuevo empleado
 *
 */
Employee* employee_new();

/** \brief Recibe parámetros cargados, valida y carga
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldoStr
 * \return Nuevo empleado con datos cargados
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Libera el espacio en memoria dinámica de un empleado
 *
 * \param El empleado a eliminar
 * \return Si logró eliminarlo 1, sino 0
 *
 */
int employee_delete(Employee* this);

/** \brief Asigna Id validado al empleado pasado por parámetro
 *
 * \param Empleado
 * \param Id
 * \return 1 si asignó, 0 si no
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Asigna Id validado al empleado pasado por parámetro, de tipo char
 *
 * \param Empleado
 * \param Id
 * \return 1 si asignó, 0 si no
 *
 */
int employee_setIdChar(Employee* this,char* id);

/** \brief Accede al Id del empleado pasado por parámetro
 *
 * \param Empleado
 * \param Id
 * \return 1 si pudo, 0 si no
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Asigna nombre validado al empleado pasado por parámetro
 *
 * \param Empleado
 * \param Nombre
 * \return 1 si asignó, 0 si no
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Accede al nombre del empleado pasado por parámetro
 *
 * \param Empleado
 * \param nombre
 * \return 1 si pudo, 0 si no
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Asigna horas trabajadas validado al empleado pasado por parámetro
 *
 * \param Empleado
 * \param Horas
 * \return 1 si asignó, 0 si no
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Asigna horas trabajadas validado al empleado pasado por parámetro, de tipo char
 *
 * \param Empleado
 * \param Horas
 * \return 1 si asignó, 0 si no
 *
 */
int employee_setHorasStr(Employee* this,char* horas);

/** \brief Accede a las horas trabajadas del empleado pasado por parámetro
 *
 * \param Empleado
 * \param Horas
 * \return 1 si pudo, 0 si no
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Asigna sueldo validado al empleado pasado por parámetro
 *
 * \param Empleado
 * \param sueldo
 * \return 1 si asignó, 0 si no
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Asigna sueldo validado al empleado pasado por parámetro, de tipo char
 *
 * \param Empleado
 * \param sueldo
 * \return 1 si asignó, 0 si no
 *
 */
int employee_setSueldoStr(Employee* this,char* sueldo);

/** \brief Accede al sueldo del empleado pasado por parámetro
 *
 * \param Empleado
 * \param sueldo
 * \return 1 si pudo, 0 si no
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Recorre la lista buscando coincidencia de Id
 *
 * \param La lista a recorrer
 * \param El Id a buscar
 * \return El índice o -1 si no lo encontró
 *
 */

int employee_findEmployeeById(LinkedList* pArrayListEmployee, int id);

/** \brief Función criterio para ser utilizada en ll_sor que compara sueldo
 *
 * \param Un elemento a comparar
 * \param Otro elemento a comparar
 * \return 1 si pudo, -1 si no
 *
 */
int empleadoCmpSueldo(void* a, void* b);

/** \brief Función criterio para ser utilizada en ll_sor que compara nombre
 *
 * \param Un elemento a comparar
 * \param Otro elemento a comparar
 * \return 1 si pudo, -1 si no
 *
 */
int empleadoCmpNombre(void* a, void* b);

/** \brief Función criterio para ser utilizada en ll_sor que compara horas trabajadas
 *
 * \param Un elemento a comparar
 * \param Otro elemento a comparar
 * \return 1 si pudo, -1 si no
 *
 */
int empleadoCmpHoras(void* a, void* b);

#endif // employee_H_INCLUDED
