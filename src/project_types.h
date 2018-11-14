/**
 * @brief Abreviation for unsigned ints
 * 
 */
typedef unsigned int uint;

/**
 * @brief Contextual typedef for ID's
 * 
 * Since IDs are unsigned integers, this typedef helps get rid of mistakes where people
 * might use a signed int for IDs and cause overflow problems.
 * 
 */
typedef unsigned int id_t;
