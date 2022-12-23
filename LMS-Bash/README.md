# CMake Project Template on Linux 

![avatar](https://badgen.net/badge/Language/C++11/orange)
![stars](https://badgen.net/badge/Dev%20Env./Linux/green)
![license](https://badgen.net/badge/License/Apache-2.0/blue)

## ONE - Directory ##
```
.
├── bin                 //Execurable Files
├── build               //Temporary Files
├── auto.sh             //Auto-Compile Script
├── include             //Header Files
│   ├── main.h
│   └── module1
│       └── head.h
├── CMakeLists.txt      //CMake Configuration File
├── README.md
└── src                 //Source Files
    ├── main.cpp        
    └── module1
        └── test1.cpp
```

## TWO - Command ##
* i . Compile Project .
    
    ```
        $ ./auto.sh 
    ```
    The script will clean files at **`build`** , revise **`auto.sh`** to change.


* ii . Run Project .
    ```
        $ cd bin
        $ ./${PROJECT_NAME}
    ```

## THREE - Module ##
* i . Add source files at **`/src`** .
* ii . Add included header files at **`/include`** .
* iii . Cite header file **`main.h`** , add this on your files
    ```c++
        #include <$(MODULE_NAME)/main.h>
    ```