#ifndef APP_DELEGATE_H
# define APP_DELEGATE_H

/*
 * The starting point of the delegate. It controls whatever happens in this
 * application. Takes a pointer to the model and a pointer to the view of the
 * application. Returns the exit status of the program. Therefore, this
 * function should return control to the caller once the user quits the app.
 */
int	onApplicationFinishedLaunching(void *model, void *view);

#endif
