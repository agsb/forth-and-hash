# forth-and-hash

A djb2 hash list of a list of standart words, from Forth Standart Annex H.

# Rationale

_"AI uses hash code as word, Humans uses semantics as word". "_ Liang Ng [^1]

Chuck Moore once used size and first three characters of words, four bytes as entries in Forth dictionary and made a letter about [^2]

Annex H of the Forth Standard lists 435 words, totaling about 2,719 characters. The average length of a Forth word is about 6 letters;

Now with 32-bit CPUs, everthing must be four bytes aligned. A Forth dictionary waste many bytes in pads. 

By use a 32-byte hash instead of strings, find of a word in dictionary, costs just one comparation of hashes.

The header changes to: link+flag, hash. Also could have a pointer to the original string elsewhere.

## Collisions

Collisions could be detected at compilation stage and allow to early block new names.

The compilation stage do hash over 32-bit and reserve some high bits for flags.

## Hash Algorithm

To transform names into hashes, the hashing algorithm doesn't need to be cryptographically sound, but it must be reliable, and have a public implementation. Therefore, the DJB2 [^3] algorithm, modified with OR and without control ASCII, is a fast effective choice.

## Verification

The list of all standart forth words [^4] (annexh.txt), with some edition lists (annexh.list), using a script (doit.sh), the djb2 hash value for each word was calculated (annexh.hash), then was sorted (annexh.sorted) and verified for duplicate hash values (annexh.uniq).

Over the 435 words from annex H, just one collision of hash-32 bits, was detected, **D<** and **F~**, and for hash-16 bits, three collisions **FOVER and SFLOAT+** , **EVALUATE and FASINH** and **D< and F~** .

A (my) solution is propose change F~ to F~=, also does better clarification that it's not a bitwise one's-complement but a approximation value. I did. Also arbitrary change FOVER to FOVER=, and FASINH to FASINH= .

Only FLAG_IMMEDIATE, as 0x80000000, for flag immediate words are used later to mask the hash.

## Application

The use of djb2 hash is used in milliforth for Riscv [^5]. 

## References

[^1]: Omni\*Web: the Secret Codes to Break Technofeudalism -- Liang Ng, 16\:35 : https://www.youtube.com/watch?v=sSlM3Mr_9sI
[^2]: "Letter to the Editor", page 20: https://raw.githubusercontent.com/larsbrinkhoff/forth-documents/master/Evolution.pdf
[^3]: Original djb2, from cdb_hash.c at package : https://cr.yp.to/cdb/cdb-0.75.tar.gz  https://cr.yp.to/cdb/install.html
[^4]: Forth Standart, AnnexH : https://forth-standard.org/standard/alpha
[^5]: A milliforth for RiscV : https://github.com/agsb/milliForth-RiscV

