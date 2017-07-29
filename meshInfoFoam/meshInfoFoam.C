/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011 OpenFOAM Foundation
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

Application
    meshInfoFoam

Description
    Test how to obtain mesh geometric information.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "setRootCase.H"

    //- Create object of class Time: runTime
    #include "createTime.H"
    //- Create object of class fvMesh: mesh
    #include "createMesh.H"
    //- Create fields and write them to 0 time folder
    #include "createFields.H"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //    

    pointField points(mesh.points());
    faceList faces(mesh.faces());
    cellList cells(mesh.cells());



    //Class: point = vector
    Info << "\n-Class: point---------" << endl;
    point &pt(points[3]);
    Info << "pt = " << pt << endl;
    //- Return x component
    Info << "pt.x() = " << pt.x() << endl;
    //- Return y component
    Info << "pt.y() = " << pt.y() << endl;
    //- Return z component
    Info << "pt.z() = " << pt.z() << endl;
    Info << "----------------------\n" << endl;



    //class: edge
    Info << "\n-Class: edges----------" << endl;
    edge eg(faces[1].faceEdge(1)), eg_(faces[1].faceEdge(3));
    label pt_1(eg.start()), &pt_2(eg.end());
    Info << "eg = " << eg << endl;
    //- Return start vertex label
    Info << "eg.start() = " << pt_1 << endl;
    //- Return end vertex label
    Info << "eg.end() = " << pt_2 << endl;
    //- Given one vertex, return the other
    Info << "eg.otherVertex(eg.end()) = " << eg.otherVertex(pt_2) << endl;
    //- Return common vertex
        //  - -1: no common vertex
    Info << "eg.commonVertex(eg_) = " << eg.commonVertex(eg_) << endl;
    //- Return reverse edge
    Info << "eg.reverseEdge() = " << eg.reverseEdge() << endl;
    //- Return centre (centroid)
    Info << "eg.centre(points) = " << eg.centre(points) << endl;
    //- Return the vector (end - start)
    Info << "eg.vec(points) = " << eg.vec(points) << endl;
    //- Return scalar magnitude
    Info << "eg.mag(points) = " << eg.mag(points) << endl;
    //- Return edge line
    Info << "eg.line(points) = " << eg.line(points) << endl;
    //- compare edges
        //  Returns:
        //  -  0: different
        //  - +1: identical
        //  - -1: same edge, but different orientation
    Info << "Foam::edge::compare(eg, eg.reverseEdge()) = " 
         << Foam::edge::compare(eg, eg.reverseEdge()) << endl;
    Info << "----------------------\n" << endl;



    //class: face
    Info << "\n-Class: face----------" << endl;
    face &fe(faces[4]);
    Info << "fe = " << fe << endl;
    //- Return true if the face is empty
    Info << "fe.empty() = " << fe.empty() << endl;
    //- Return No. of points corresponding to this face
    Info << "fe.size() = " << fe.size() << endl;
    //- Return first point
    Info << "fe.first() = " << fe.first() << endl;
    //- Return last point
    Info << "fe.last() = " << fe.last() << endl;
    //- Return n-th point
    Info << "fe.operator[](0) = " << fe.operator[](0) << endl;
    //- Return the points corresponding to this face
    Info << "fe.points(points) = " << fe.points(points) << endl;
    //- Centre point of face
    Info << "fe.centre(points) = " << fe.centre(points) << endl;
    //- Calculate average value at centroid of face
    Info << "fe.average(points, points) = " 
         << fe.average(points, points) << endl;
    //- Magnitude of face area
    Info << "fe.mag(points) = " << fe.mag(points) << endl;
    //- Vector normal; magnitude is equal to area of face
    Info << "fe.normal(points) = " << fe.normal(points) << endl;
    //- Return face with reverse direction
        //  The starting points of the original and reverse face are identical.
    Info << "fe.reverseFace() = " << fe.reverseFace() << endl;
    //- Which vertex on face (face index given a global index)
        //  returns -1 if not found
    Info << "fe.which(1966) = " << fe.which(1966) << endl;
    //- Next vertex on face
    Info << "fe.nextLabel(1) = " << fe.nextLabel(1) << endl;
    //- Previous vertex on face
    Info << "fe.prevLabel(1) = " << fe.prevLabel(1) << endl;
    //- Return number of edges
    Info << "fe.nEdges() = " << fe.nEdges() << endl;
    //- Return edges in face point ordering,
        //  i.e. edges()[0] is edge between [0] and [1]
    Info << "fe.edges() = " << fe.edges() << endl;
    //- Return n-th face edge
    Info << "fe.faceEdge(1) = " << fe.faceEdge(1) << endl;
    //- Return the edge direction on the face
        //  Returns:
        //  -  0: edge not found on the face
        //  - +1: forward (counter-clockwise) on the face
        //  - -1: reverse (clockwise) on the face
    Info << "fe.edgeDirection(fe.faceEdge(1)) = " 
         << fe.edgeDirection(fe.faceEdge(1)) << endl;
    //- compare faces
        //   0: different
        //  +1: identical
        //  -1: same face, but different orientation
    Info << "Foam::face::compare(fe, fe) = " 
         << Foam::face::compare(fe, fe) << endl;
    Info << "----------------------\n" << endl;



    //class: cell
    Info << "\n-Class: cell----------" << endl;
    cell &cl(cells[100]);
    Info << "cl = " << cl << endl;
    //- Return true if the cell is empty
    Info << "cl.empty() = " << cl.empty() << endl;
    //- Return No. of faces corresponding to this cell
    Info << "cl.size() = " << cl.size() << endl;
    //- Return first face
    Info << "cl.first() = " << cl.first() << endl;
    //- Return last face
    Info << "cl.last() = " << cl.last() << endl;
    //- Return n-th face
    Info << "cl.operator[](0) = " << cl.operator[](0) << endl;
    //- Return number of faces
    Info << "cl.nFaces() = " << cl.nFaces() << endl;
    //- Return labels of cell vertices
    Info << "cl.labels(faces) = " << cl.labels(faces) << endl;
    //- Return the cell vertices
    Info << "cl.points(faces, points) = " << cl.points(faces, points) << endl;
    //- Return cell edges
    Info << "cl.edges(faces) = " << cl.edges(faces) << endl;
    //- Returns cell centre
    Info << "cl.centre(points, faces) = " << cl.centre(points, faces) << endl;
    //- Returns cell volume
    Info << "cl.mag(points, faces) = " << cl.mag(points, faces) << endl;
    Info << "----------------------\n" << endl;

    return 0;
}

// ************************************************************************* //
