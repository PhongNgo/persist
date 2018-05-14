Persistence
===========

Persist is a tool that checks the **Persistent** property of concurrent programs running under the Total-Store-Order (TSO) memory model (implemented in Intel x86). Persistence is defined by *program order* (the order of instructions in the source code) and *store order* of write operations for all variables. Keeping a program persistent under TSO guarantees that the program is sequential consistent, i.e. the sets of all behaviors of the programs under TSO and SC are the same. In other words, a presistent program does not contain any non-SC behaviors.

Two  most related techniques to avoid non-SC behaviors of programs under TSO are keeping it **Robust** [1] or keeping it **Triangular race free (TRF)** [5]. Robustness is based on program order, store order of write operations per variable, and read-from relations. Robustness is considered in many previous approaches, e.g. [2,3,4]. Triangular race freedom is based on program order, store order of write operations for all variables, and read-from relations.

Persistence is incomparable to Robustness and both of them are weaker than TRF. Persistence is weaker than Robustness in the sense that Persistence does not contain read-from relations in its definition. Robustness is weaker than Persistence in the sense that the store order in the definition of robustness is the union of total store orders of  write opeartions per variable while it is total for all variables in Persistence. Another important difference between Persistence and Robust that we can verify the persistent property of programs using a **thread-modular abstraction** that makes our tool more scalable, especially for programs with a large number of processes. It is clear to see that Persistence and Robustness are weaker than TRF.

For a non-persistent program, PERSIST make it persistent by exploring a **minimal set of fences**. It is done automatically and the obtained program will be correct wrt. **any safety properties** under TSO if it is correct under SC wrt. the same properties. A different technique to correct a program under TSO by fence insertion is based on a state reachability analysis. This technique requires specifications of some safety properties that must be manually given by the users or developers.



## Source code for Persist
You can find instructions how to install, run, and reproduce all results in Table 1 and Figure 17 of the paper using material provided in this package. Here is list of files and folders:

- `README.md:` this current file.
- `Readmefirst.txt:` simimar information as README.md but shorter.
- `install.txt:` how to download and install Persist.
- `install_other_tools.txt:` how to download and install other tools (Memorax, Musketeer, Trencher, and Remmex).
- `manual.txt:` how to run and custermize input files with Persist.
- `commands.txt:` common commands to use with Trencher, Persist, Memorax, Musketeer, and Remmex.
- `examples:`  algorithm directory using in Table 1 and Figure 17 of paper.
- `run_test.sh:` file for automatic running all tests, each test includes Persist, Trencher, Musketeer, Memorax, and Remmex if available. To do this work automatically, please put executable files of Memorax (memorax), Trencher (trencher), Persist (PERSIST), Musketeer (goto-cc, musketeer, fence-insert.py) into build folder. 
- `fence-inserter.py:` script file used by Musketeer version 17 April 2014, in the case cannot find it from Musketeer's website.
- `test_cases.txt:` file used by run_test.sh. 
- `src:` source file directory.

**NOTE: using `run_test.sh`, except Persist, some examples will take longer than 40 mins (in a machine of 2.4 Ghz 2 cores, 4GB RAM), or run out of memory; you may need to stop it yourself!!!**

## References
[1] D. Shasha and M. Snir. Efficient and correct execution of parallel programs that share memory. ACM Trans. Program. Lang. Syst., 10(2):282–312, Apr. 1988.

[2] A. Bouajjani, E. Derevenetc, and R. Meyer. Checking and enforcing robustness against tso. In ESOP, pages 533–553, 2013.

[3]  S. Burckhardt and M. Musuvathi. Effective program verification for relaxed memory models. In CAV, volume 5123 of LNCS, pages 107–120. Springer, 2008.

[4] J. Alglave, D. Kroening, V. Nimal, and D. Poetzl. Don’t sit on the fence: A static analysis approach to automatic fence insertion. In CAV, volume 8559 of LNCS. Springer, 2014.

[5] S. Owens. Reasoning about the implementation of concurrency abstractions on x86-tso. In ECOOP, volume 6183 of LNCS, pages 478-503, Springer 2010.

## Contact/Bug report
Feedback, questions or bug reports should be directed to Tuan Phong Ngo (tuanphong.ngo@gmail.com).

