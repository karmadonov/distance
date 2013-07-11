distance
========

Calculate distance (in miles) between two coordinates on the map usin Python/C API

Installation
------------

    python setup.py install

Usage
-----

    >>> import distance
    >>> distance.compute('10.1', '12.1', '10.1', '10.1')
    135.95027527032235

Сomparison
----------

```python

import distance
import math

from decimal import Decimal

lat1 = lng2 = lat2 = Decimal('10.1')
lng1 = Decimal('12.1')


def compute_distance(lat1d, lon1d, lat2d, lon2d):
    lat1 = math.radians(lat1d)
    lat2 = math.radians(lat2d)
    lon1 = math.radians(lon1d)
    lon2 = math.radians(lon2d)
    R = 3956  # miles
    d_miles = math.acos(math.sin(lat1) * math.sin(lat2) + math.cos(lat1) * math.cos(lat2) * math.cos(lon2 - lon1)) * R
    return d_miles


%timeit distance.compute(str(lat1), str(lng1), str(lat2), str(lng2))
100000 loops, best of 3: 6.11 us per loop

%timeit compute_distance(lat1, lng1, lat2, lng2)
100000 loops, best of 3: 8.55 us per loop
```

Checked under Python 2.7 and Python 3.3
_______________________________________
