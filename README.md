# compactFaceToFace

This utility converts a mesh's `faceCompactLists` into `faceLists`, which
improves interoperability of meshes between OpenFOAM and foam-extend.

The original code was written by Ali Q. Raeini, which has been modified to
work with OpenFOAM 4.0.

More:
http://www.cfd-online.com/Forums/openfoam-meshing-snappyhexmesh/93142-how-use-facelist-instead-facecompactlist.html


## Building

From this directory, run `wmake`.


## Usage

From an OpenFOAM case directory, run `compactFaceToFace`.
