# CFileSelect / CFolderSelect

Class able to launch a GUI menu asking for a file / directory.

For more info please check [This](https://stackoverflow.com/questions/18948783/c-simple-open-file-dialog-in-linux).


This lauches a simple dialog requesting a file selection:
```c++
char filename[1024];
FILE *f = popen("zenity --file-selection", "r");
fgets(filename, 1024, f);

std::cerr << "File selected is " << filename << '\n';
```

This lauches a simple dialog requesting a folder selection:
```c++
char filename[1024];
FILE *f = popen("zenity --file-selection --directory", "r");
fgets(filename, 1024, f);

std::cerr << "File selected is " << filename << '\n';
```

TODO: See how to do this asyncroniosly (non-blocking).

