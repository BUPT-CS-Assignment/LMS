# LMS Server

![avatar](https://badgen.net/badge/Language/C++11/orange)
![stars](https://badgen.net/badge/Dev%20Env./Windows/green)
![license](https://badgen.net/badge/License/Apache-2.0/blue)

## ONE - Directory ##
```
.
├── bin                 //Execurable Files
├── build               //Temporary Files
├── auto.bat            //Auto-Compile Script
├── include             //Header Files
│   ├── sys.h
│   └── module1
│       └── header.h
├── CMakeLists.txt      //CMake Configuration File
├── README.md
└── src                 //Source Files
    ├── main.cpp        
    └── module1
        └── test1.cpp
```

## TWO - Command ##
* i . Compile And Run Project .
    
    ```
        $ ./auto.bat 
    ```
    revise **`auto.sh`** for make-only.


## THREE - Module ##
* i . Add source files at **`/src`** .
* ii . Add included header files at **`/include`** .
* iii . Cite header file **`sys.h`** , add this on your files
    ```c++
        #include <$(MODULE_NAME)/sys.h>
    ```