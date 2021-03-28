# fasta_parser
Basic package used to parse a file in the Fasta format

It provides basic functionality such as:

* Quick sequence retrieval

In the future, I plan to add new features to this package

* Installation

'cd' to the directory containing the package's source and type:

    make

You will see 2 executable files named `getseq` and `makeix` in the `./bin` directory

* Usage

Before using `getseq` with a Fasta file you need to index it by doing:

    makeix <input.fa>

Then, you can use `getseq` to fetch a particular sequence:

    getseq <input.fa> <seqid>
