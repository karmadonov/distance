#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define d2r (M_PI / 180.0)


double haversine_mi(double lat1, double long1, double lat2, double long2)
{
    double dlong = (long2 - long1) * d2r;
    double dlat = (lat2 - lat1) * d2r;
    double a = pow(sin(dlat/2.0), 2) + cos(lat1*d2r) * cos(lat2*d2r) * pow(sin(dlong/2.0), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = 3956 * c;

    return d;
}


double _compute_distance(const char *lat1, const char *long1, const char *lat2, const char *long2)
{
    double lt1 = atof(lat1);
    double lng1 = atof(long1);
    double lt2 = atof(lat1);
    double lng2 = atof(long2);
    double distance = haversine_mi(lt1, lng1, lt2, lng2);

    return distance;
}


static PyObject* compute(PyObject* self, PyObject* args)
{
    const char* lat1;
    const char* long1;
    const char* lat2;
    const char* long2;

    if (!PyArg_ParseTuple(args, "ssss", &lat1, &long1, &lat2, &long2))
        return NULL;

    return Py_BuildValue("f", _compute_distance(lat1, long1,lat2, long2));
}


static PyMethodDef DistanceMethods[] = {
    {"compute", compute, METH_VARARGS,
     "Calculate distance between two coordinates on the map."},
    {NULL, NULL, 0, NULL}
};


PyMODINIT_FUNC
initdistance(void)
{
    (void) Py_InitModule("distance", DistanceMethods);
}
