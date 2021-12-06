Abdullah Khan (mkhan94@uoguelph.ca) - 1101209

This program implements the Depth-first algorithm that creates a path through a two
dimensional array. This path represents a 2D maze. Added OpenMP commands to make 
the serial program to work in parallel with four threads of the processor.

Compile: -$ make

Run:
    ./maze -n [size of maze]
    ./maze (run programs with default 11 size maze)
    ./maze -s -n [size of maze]
    ./maze -n [size of maze] -s

*I was not able to implement the "-s" argument*