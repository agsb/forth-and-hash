# forth-and-hash

A djb2 hash list of a list of standart words, from Forth Standart Annex H.

# Rationale

_"AI uses hash code as word, Humans uses semantics as word". "_[Liang Ng, 16:35](https://www.youtube.com/watch?v=sSlM3Mr_9sI)

Chuck Moore once used size and first three characters of words, four bytes as entries in Forth dictionary. 

Now with 32-bit CPUs, everthing must be four bytes aligned. A Forth dictionary waste many bytes in pads. 

By use a 32-byte hash instead of strings, find of a word, and code, could be done just one comparation of hashes.

The header changes to: link, hash. Also could have a pointer to the original string elsewhere.

## Collisions

Collisions could be detected at compilation stage and allow to early block new names.

The compilation stage do hash over 32-bit and reserve some high bits for flags.

## Hash Algorithm

To transform names into hashes, the hashing algorithm doesn't need to be cryptographically sound, but it must be reliable, and have a public implementation. Therefore, the [DJB2](https://theartincode.stanis.me/008-djb2/) algorithm (with OR) is a fast effective choice.

## Application

The [Forth standart AnnexH](https://forth-standard.org/standard/alpha) (annexh.txt), with some edition lists all standart forth words (annexh.list), using a script (doit.sh), the djb2 hash value for each word was calculated (annexh.hash), then was sorted (anneh.sorted) and verified for duplicate hash values (annexh.uniq).

Over the 435 words, just one collision detected, **D<** and **F~**, and a (my) solution is propose change **F~** to **F~=**. Also does better clarification that its not a bitwise one-complement but a approximation value. I did.

## References

