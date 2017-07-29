    //Mesh cell volumes
    volScalarField cellVolume
    (
        IOobject
        (
            "cellVolume",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("", dimVolume, 0.0)
    );    
    cellVolume.internalField() = mesh.V();
    
    
    //Mesh cell centers
    volVectorField cellCenter
    (
        IOobject
        (
            "cellCenter",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedVector("", dimLength, vector(0.0, 0.0, 0.0))
    );    
    cellCenter.internalField() = mesh.C();
    
    
    //Mesh face areas
    surfaceScalarField faceArea
    (
        IOobject
        (
            "faceArea",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("", dimArea, 0.0)
    );    
    faceArea.internalField() = mesh.magSf();
    
    
    //Mesh face area vectors
    surfaceVectorField faceCenter
    (
        IOobject
        (
            "faceCenter",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedVector("", dimLength, vector(0.0, 0.0, 0.0))
    );    
    faceCenter.internalField() = mesh.Cf();
    
    
    //Mesh face area vectors
    surfaceVectorField faceAreaVector
    (
        IOobject
        (
            "faceAreaVector",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedVector("", dimArea, vector(0.0, 0.0, 0.0))
    );    
    faceAreaVector.internalField() = mesh.Sf();
    
    
    //Mesh face area vectors
    surfaceVectorField faceUnitNormalVector
    (
        IOobject
        (
            "faceUnitNormalVector",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedVector("", dimless, vector(0.0, 0.0, 0.0))
    );    
    faceUnitNormalVector.internalField() = mesh.Sf() / mesh.magSf();
    
    
    //Write data
    cellVolume.write();
    cellCenter.write();
    faceArea.write();
    faceCenter.write();
    faceAreaVector.write();
    faceUnitNormalVector.write();
