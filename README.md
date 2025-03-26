# Tiroir

This is an `$ ls` based programm that is usefull when we want to `ls` in a directory where all files share the same prefix and have a suffix that numerically differs.

# Example

With normal ls:

```
$ls

img1  img10  img11  img12  img13  img2  img3  img4  img5  img6  img7  img8  img9
```

With this programm

```
$ls

img1 img2 img3 img4 img5 img6 img7 img8 img9 img10 img11 img12 img13
```

## Use it

`git clone https://github.com/julienlargetpiet/Tiroir`

Modify the line 115 to match your actual absolute pathfile where the programm has been cloned.

Compile:

`g++ -O3 tiroir.cpp`

In a `.bash_aliases` file.

```
alias your_alias="ls > your_absolute_path/in.txt && ~/./your_absolute_path/a.out"
```

Done


