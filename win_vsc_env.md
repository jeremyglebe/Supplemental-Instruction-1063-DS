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

### How to Manage GitHub Repo with VSCode
    * Make sure you ran the two required commands in the steps above
    * Clone your repository
        * Copy the clone link from GitHub
        ![Copy the clone link from GitHub](./vsc_git_media/git_clone_link.gif)
        * Hit CTRL+SHIFT+P, search for and use the clone command. Paste your cloning link.
        * It will ask you where to make the clone, select a folder you wish to put the repo in. (The repo itself will be in a new folder, so if you choose `desktop`, it will create `desktop/your_repo_name`)
        ![Hit CTRL+SHIFT+P, search for and use the clone command. Paste your cloning link.](./vsc_git_media/git_clone.gif)
    * Now open the new folder (`your_repo_name`) with VSCode. We'll work from this folder from now on.
    * Click around, create files, work on assignments, and whatever else you want to do.
    * Once you have changes that you need to save and send to GitHub, click on the "Source Control" tab and the "Stage All Changes" button (which looks like a '+')
    ![click on the "Source Control" tab and the "Stage All Changes" button](./vsc_git_media/stage_changes.gif)
    * Now click the check mark that says "Commit" and type in an appropriate message describing your changes
    ![click the check mark that says "Commit"" button](./vsc_git_media/commit.gif)
    * Now look at the bottom of your VSCode window. You should see two arrows forming a circle and next to them an up arrow and a down arrow (each accompanied by a number)
        * This is the "synchronize" button.
    * Click the synchronize button and you will automatically push all of your committed changes to GitHub as well as pull down anything you're missing from your local version of the repo.
        * The first time you do this, a window will pop up asking you to sign in to GitHub.