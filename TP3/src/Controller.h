/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si pudo, 0 si no
 *
 */
int controller_loadFromText(LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si pudo, 0 si no
 *
 */
int controller_loadFromBinary(LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si pudo, 0 si no
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si pudo, 0 si no
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si pudo, 0 si no
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si pudo, 0 si no
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si pudo, 0 si no
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si pudo, 0 si no
 *
 */
int controller_saveAsText(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si pudo, 0 si no
 *
 */
int controller_saveAsBinary(LinkedList* pArrayListEmployee);

/** \brief Devuelve el mayor id aumentado en 1
 *
 * \param Lista a recorrer
 * \param Puntero donde guardará el Id
 * \return 1 Si logró la búsqueda, 0 si no.
 *
 */
int controller_mayorId(LinkedList* pArrayListEmployee, int* pId);


