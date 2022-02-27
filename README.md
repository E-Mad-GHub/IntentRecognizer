# IntentRecognizer
Simple intent recognizer application (command line application) which parses (maps) inputs to outputs. And has an example usage with input as text and output as text.

#### How to install
First of all, let's clone the repository:

1. Run *$git clone* https://github.com/E-Mad-GHub/IntentRecognizer.git.
2. Then, *$cd IntentRecognizer/ && git checkout origin/master*.
3. After that, we can build the project with *$mkdir build && cd build && cmake .. && make*

#### How to run

1. on the build directory, run *$./IRecog  ./../config/config.ini* which will give the configuration file (which is needed as a part of extension for the application).
** Note.** You can change the path of the **'config.ini'** file but dont forget to give the new path to the application whenever you try to run it.

#### How to configure

1. You will find two files in the directory named **'config'** which are **'behaviorList.hpp'** and **'config.ini'**.
**a. behaviorList.hpp:** contains the functions that will be called (the output behavior needed) and can be filled by the user if needed. But keep in mind that no change will happen before compiling again.
**b. config.ini:** which is a file that has the mapping info between the input (string for this configuration) and the behavior that is needed to take place (the functions in 'behaviorList.hpp').
. config.ini -> Number: Which is the number of inputs and outputs used.
. config.ini -> Input: Which is the input pattern that is required for certain behavior.
. config.ini -> Behavior: Which is the behavior for that certain input pattern in 'config.ini -> Input'.

> Side Notes
- The one can find in total three branches, **'master'**, **'development'** and **'test'**. for the **'development'** branch, its the branch where action takes place, or where the development happens for the first time in each start of feature. and for **'test'** branch, its the next step for the implemented features in **'development'** where they can get tested with the framework **'catch2'**. And finally for the **'master'** branch, the one can find the staged after testing feature and implementation.

#### Software Architecture (class diagram)
https://drive.google.com/file/d/1_iCnv7VoZ7WyAJoYX1ce-ukJry2Fw67b/view?usp=sharing
