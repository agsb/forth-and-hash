# forth-and-hash

_" "_[Liang Ng](https://www.youtube.com/watch?v=sSlM3Mr_9sI)

A djb2 hash list of Forth Standart word list of Annex H

# Rationale

Chuck Moore once used size and first three characters of words
as entries in Forth dictionary. 

Now with 32-bit CPUs, by use a hash instead of words, find of a code could be done just one comparation of hashes, and the header as link, hash, code.

The hash over 32-bit, reserve some high bits for flags

## Collisions

Collisions could be detected at compilation stage and allow to early block new names.

## Hash Algorithm

For just enumer the transformation of names to hashes, a simple and effective hash algorithm is the DJB2 with OR.

## Application

The Forth standart AnnexH, lists all standart forth words, and using ...

Just one collision detected, **D<** and **F~**, and a solution is change **F~ to **F~=**, also to better clarification that its not a bitwise one-complement but a approximation value.

## References

