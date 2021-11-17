/**
 * Function draw game field
 * @param rows count of rows
 * @param columns count of columns
 * @param field hold 2d array of characters in game
 */
void generator(const int rows, const int columns, char fidesz[rows][columns]);



/**
 * Function returns 2D array after moving characters based on player input
 * When characters are not same, nothing happens and warning appears
 * Function also find the most upper character and the lower character from columns
 * @param rows count of rows
 * @param columns count of columns
 * @param field hold 2d array of characters in game
 * @param x is column from where character should be moved
 * @param y is column where character should be moved
 */
void down_possible(const int rows, const int columns, char fidesz[rows][columns]);



/**
 * Starts interactive ball sort puzzle game
 */
void ball_sort_puzzle();
