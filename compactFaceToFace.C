/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 191-210 OpenCFD Ltd.
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Description
    Convert faceCompactList to faceList

\*---------------------------------------------------------------------------*/

#include "argList.H"
#include "Time.H"
#include "polyMesh.H"
#include "IFstream.H"
#include "polyPatch.H"
#include "ListOps.H"
#include "cellModeller.H"

#include <fstream>

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    #include "createTime.H"

    objectRegistry registry(runTime);

    faceCompactIOList facesCompact
    (
        IOobject
        (
             "faces",
             "constant",
             "polyMesh",
             runTime,
             IOobject::MUST_READ
        )
    );

    faceIOList faces
    (
        IOobject
        (
            "faces",
            "constant",
            "polyMesh",
            runTime,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        facesCompact
    );

    faces.write();

    Info<< "end" << endl;

    return 0;
}


// ************************************************************************* //
