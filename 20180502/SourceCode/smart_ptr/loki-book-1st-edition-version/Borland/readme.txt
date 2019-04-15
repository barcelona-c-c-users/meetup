Last update: August 9, 2002

Directions:

To use Loki, simply extract the files from the archive, give your compiler access to their path, and include them appropriately in your code via #include.

If you use the small object allocator directly or indirectly (through the Functor class) you must add SmallObj.cpp to your project/makefile.

If you use Singletons with longevity you must add Singleton.cpp to your project/makefile.

Compatibility:

Loki has been tested with Metrowerks CodeWarrior Pro 6 under Windows. CodeWarrior has a problem with the Conversion template (see TypeManip.h) and, though it compiles it, it doesn't provide correct results. Consequently, the DerivedToFront algorithm in Typelist.h does not function. This affects the static dispatcher in Multimethods.h. As a fix, you must order the types (putting the most derived ones in the front) when providing the typelist argument to StaticDispatcher.

Also, Loki has been ported to g++ 2.95.3 by Nick Thurn.


This is a ported version of Loki to Borland C++ Builder 6.0. However, it uses standard C++, so it should work on the other compilers, as well.

More info:

http://moderncppdesign.com
