import sys

from distutils.core import setup, Extension

if sys.version_info[0] == 3:
    ext = Extension("distance", sources=["src/distance.c"])
else:
    ext = Extension("distance", sources=["src/distance2.c"])

setup(
    name="distance",
    version="0.0.1",
    description="Compute distance module",
    ext_modules=[ext],
)
