===========================
 Counting digits benchmark
===========================

In this benchmark we are trying to find the fastest implementation of
`log10(value | 1)` for integer values.


Compiling
=========

::

    $ mkdir build
    $ cd build
    $ cmake -DCMAKE_BUILD_TYPE=Release ..
    $ make

Running Benchmarks
==================

Make sure that you set cpu governor mode to performance, so the
results of the benchmark would be more accurate.

::

    # cpupower frequency-set -g performance

And then you can run the benchmark. It will generate .png files in the
current directory.

::

    $ cd scripts
    $ ./benchmark.sh

Benchmark details
=================

Each algorithm is compiled in its own benchmarking application and
testing application.

Benchmarking application support positional arguments:
 - inner loop counter
 - integer size (u8, u16, u32, u64)
 - digits

Testing application can be launched in two modes: simple testing and
random testing. For simple testing, just launch the application, and
for random testing launch application with an integer argument, it
will be used as a seed for random number generator.

benchmark.sh
++++++++++++

This script run benchmarks in two modes(cold, hot) and collect data
from it.

In the cold mode, it runs benchmark application for 100 times with
arguments (inner loop counter=1, integer size=<all>, digits=<all
values for current integer size>).

In the hot mode, it runs benchmark application for 100 times with
arguments (inner loop counter=100, integer size=<all>, digits=<all
values for current integer size>).

And then generates graphical representation of the collected data. As
a time value it uses median of all time values for each (benchmark,
integer size, digits).

Benchmarking results
====================

Linux, gcc 4.7.2 (core i5-3570k)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Cold run
--------
.. image:: https://raw.github.com/localvoid/cxx-benchmark-count-digits/master/results/linux/gcc_4_7/i5_3570k/cold_digits10_64.png
.. image:: https://raw.github.com/localvoid/cxx-benchmark-count-digits/master/results/linux/gcc_4_7/i5_3570k/cold_digits10_32.png
.. image:: https://raw.github.com/localvoid/cxx-benchmark-count-digits/master/results/linux/gcc_4_7/i5_3570k/cold_digits10_16.png
.. image:: https://raw.github.com/localvoid/cxx-benchmark-count-digits/master/results/linux/gcc_4_7/i5_3570k/cold_digits10_8.png

Hot run
-------
.. image:: https://raw.github.com/localvoid/cxx-benchmark-count-digits/master/results/linux/gcc_4_7/i5_3570k/hot_digits10_64.png
.. image:: https://raw.github.com/localvoid/cxx-benchmark-count-digits/master/results/linux/gcc_4_7/i5_3570k/hot_digits10_32.png
.. image:: https://raw.github.com/localvoid/cxx-benchmark-count-digits/master/results/linux/gcc_4_7/i5_3570k/hot_digits10_16.png
.. image:: https://raw.github.com/localvoid/cxx-benchmark-count-digits/master/results/linux/gcc_4_7/i5_3570k/hot_digits10_8.png

