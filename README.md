# canonicalize_path.h

pathname canonicalization header library.

---

canonicalize_path -- returns the canonicalized absolute pathname

```c
#include "canonicalize_path.h"

char *canonicalize_path( const char *pathname, int *relative );
```

**Parameters**

- `pathname`: non-NULL pathname string.
- `relative`: non-NULL integer.


**Return Values**

On success, the canonicalize_path() function returns the address (newly allocated memory) of the resulting absolute pathname. and set the non-zero value to `relative` if a pathname is relative path.
If an error occurs, canonicalize_path() returns NULL.

**Errors**

The function canonicalize_path() may fail and set the external variable errno for any of the errors specified for the library functions malloc(3) and strndup(3).

## Usage

```c
#include <stdio.h>
#include "canonicalize_path.h"

int main (int argc, const char * argv[])
{
    char *str = NULL;
    char *cwd = getcwd( NULL, 0 );
    int relative = 0;
    char *pathz[] = {
        "foo/bar/baz",
        ".foo/bar/baz",
        "/foo/./bar/../baz",
        "/foo/../bar/./baz",
        "/foo/../bar/../baz",
        "/foo/../bar/../baz./",
        "/foo/../bar/../.baz/",
        "/foo/../bar/../baz../",
        "/foo/../bar/../..baz/",
        NULL
    };
    char **ptr = pathz;
    
    while( *ptr )
    {
        str = canonicalize_path( *ptr, &relative );
        // prepend cwd
        if( relative ){
            printf("%s|%s\n", cwd, str );
        }
        else {
            printf("%s\n", str );
        }
        free( str );
        ptr++;
    }
    
    free( cwd );
    return 0;
}
```