### Chapter 1

This README is not 100% full but here is an example on how to execure some of the examples.

The `data/` directory is meant to hold any files that will help you execute easier the examples and exercises.

Usually the text inside the files in taken from any website from internet picked on random in order to have something little bit different than "Lorem ipsum".

#### Compile the examples.

I have used the *gcc* compiler on MacOS to compile all the examples. So I sugges you use the same. I guess it is the same on Windows machines.

```
gcc exercise-1-22-fold-long-lines.c -o build/exercise-1-22-fold-long-lines.out
```

#### Run the examples.

After you have compiled the example you need, here is how to run it.

For better execution of the examples check if there is a corresponding file in the `data/` directory and run it this way:

```
cat data/exercise-1-22-fold-long-lines.txt | ./build/exercise-1-22-fold-long-lines.out
```