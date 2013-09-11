# lttng-studio

lttng-studio is a trace viewer and analyzer for software developers and system administrators, based on the Linux Tracing Toolkit infrastructure.

# Project setup

The project is using C++, Qt 5 and qmake.

First, load 3rd party submodules:

<pre><code>
  git submodule init
  git submodule update
</pre></code>

Then, the usual makefile generation and compilation:

<pre><code>
  qmake -r
  make
</pre></code>

# Running unit tests
==========

Use the target "test" to run unit tests:

<pre><code>
  make test
</pre></code>

QMakeTestRunner adds the target "test" and export LD_LIBRARY_PATH for the local build. To run tests manually, libraries must be available in LD_LIBRARY_PATH or globaly.

# Writing unit tests

Each test is in its own directory (and .pro file) under "tests". Tests are written with QTest library. For more information on how to use QTest, see [http://qt-project.org/doc/](QT doc).

# License, contributions, issues and support

lttng-studio is Free Software licenced under the GPL, version 3. Contributions to it are welcome, please propose them as Github pull requests. To submit a bug report or feature wish, please use the Github issue tracker for the project.

Have fun!
