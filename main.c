/*
 *  Copyright 2015 Masatoshi Teruya. All rights reserved.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *
 *
 *  main.c
 *
 *  Created by Masatoshi Teruya on 2015/02/20.
 *
 */

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


