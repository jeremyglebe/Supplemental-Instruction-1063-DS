## Study Session: Development Environment

### Setting Up a Dev Environment With VSCode & Windows
* Install [VSCode](https://code.visualstudio.com/)
* Install [Git](https://git-scm.com/downloads)
    * As far as I can tell, it is unavoidable that you will have to do a quick config through the command line. Don't worry, just two commands and then everything else can be done through VSCode.
    * Open Git Bash and type the following two commands (replacing the name and email with your name and email)
        * `git config --global user.name "John Doe"`
        * `git config --global user.email "johndoe1955@hotmail.com"`
* Install [MinGW](https://osdn.net/projects/mingw/releases/)
    * When choosing which elements of MinGW to install, make sure to select the C++ compiler `g++`
        * Once you've selected which elements of MinGW to install, click `installation` in the top left corner and then `apply changes`
    * NOTE which directory MinGW is installed to, it should contain a folder called `bin\`
    * Add MinGW's `bin\` folder to your `PATH`
    * On Windows 10, PATH can be modified by following these steps
        1. In Search, search for and then select: Edit the system environment variables
        2. Click Environment Variables. In the section System Variables, find the PATH environment variable and select it. Click Edit. If the PATH environment variable does not exist, click New.
        3. In the Edit System Variable (or New System Variable) window, click "new" to add a new line to the PATH, then enter the path of MinGW's bin folder (C:\\\wherever\i\installed\it\mingw\bin\). Click OK. Close all remaining windows by clicking OK.
* Add extension "code runner" to VSCode
    * **THE FOLLOWING STEPS ARE ONLY NEEDED IF VSCODE IS NOT COMPILING ALL OF YOUR FILES. IF YOU CAN COMPILE MULTIPLE FILES - THIS IS NOT NECESSARY.**
    * Configure code runner's command for executing C++ code
    * Change the `cpp` command to `cd $dir && g++ *.cpp -o $fileNameWithoutExt && $dir$fileNameWithoutExt` (add `cpp` to the list if necessary)
    * To configure, search the VSCode settings for something like
```
{
    "code-runner.executorMap": {
        "javascript": "node",
        "php": "C:\\php\\php.exe",
        "python": "python",
        "perl": "perl",
        "ruby": "C:\\Ruby23-x64\\bin\\ruby.exe",
        "go": "go run",
        "html": "\"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe\"",
        "java": "cd $dir && javac $fileName && java $fileNameWithoutExt",
        "c": "cd $dir && gcc $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
        "cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
    }
}
```
