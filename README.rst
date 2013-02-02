===========================
 Counting digits benchmark
===========================

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
results of the benchmark would be more accurate.::

    # cpupower frequency-set -g performance

And then you can run the benchmark. It will generate .png files in the
current directory.::

    $ cd scripts
    $ ./benchmark.sh

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

