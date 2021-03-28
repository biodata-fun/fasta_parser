# fasta_parser
Basic package used to parse a file in the Fasta format

It provides basic functionality such as:

* Quick sequence retrieval
* Get number of sequences in the file
* Print out the sequence ids

In the future, I plan to add new features to this package

# Installation

'cd' to the directory containing the package's source and type:

    make

You will see the differenct executable files  in the `./bin` directory

# Usage

## `getseq`:

Before using `getseq` with a Fasta file you need to index it by doing:

    makeix <input.fa>

Then, you can use `getseq` to fetch a particular sequence:

    getseq <input.fa> <seqid>

## `getids`

Program to print out the ids in `<input.fa>`

## `getseqno`

Program to print out the number of sequences in `<input.fa>`

