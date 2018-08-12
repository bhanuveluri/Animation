#-------------------------------------------------
#
# Project created by QtCreator 2018-07-17T17:34:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Animation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Renderer.cpp \
    VtkRendererWidget.cpp \
    MenuBar.cpp \
    ImportDialog.cpp \
    ContextMenu.cpp \
    MouseInteractorStyle.cpp \
    GearAnimationDialog.cpp \
    TransformDialog.cpp

HEADERS  += mainwindow.h \
    Renderer.h \
    VtkRendererWidget.h \
    MenuBar.h \
    ImportDialog.h \
    ContextMenu.h \
    MouseInteractorStyle.h \
    GearAnimationDialog.h \
    TransformDialog.h

FORMS    +=


CONFIG += c++11

unix:!macx: {

 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkalglib-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkChartsCore-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkCommonColor-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkCommonComputationalGeometry-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkCommonCore-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkCommonDataModel-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkCommonExecutionModel-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkCommonMath-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkCommonMisc-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkCommonSystem-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkCommonTransforms-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkDICOMParser-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkDomainsChemistry-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkDomainsChemistryOpenGL2-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkexoIIc-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkexpat-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersAMR-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersCore-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersExtraction-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersFlowPaths-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersGeneral-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersGeneric-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersGeometry-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersHybrid-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersHyperTree-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersImaging-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersModeling-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersParallel-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersParallelImaging-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersPoints-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersProgrammable-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersSelection-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersSMP-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersSources-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersStatistics-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersTexture-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersTopology-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkFiltersVerdict-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkfreetype-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkGeovisCore-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkgl2ps-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkglew-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkGUISupportQt-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkGUISupportQtSQL-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkhdf5-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkhdf5_hl-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkImagingColor-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkImagingCore-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkImagingFourier-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkImagingGeneral-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkImagingHybrid-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkImagingMath-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkImagingMorphological-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkImagingSources-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkImagingStatistics-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkImagingStencil-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkInfovisCore-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkInfovisLayout-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkInteractionImage-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkInteractionStyle-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkInteractionWidgets-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOAMR-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOCore-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOEnSight-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOExodus-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOExport-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOExportOpenGL2-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOGeometry-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOImage-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOImport-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOInfovis-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOLegacy-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOLSDyna-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOMINC-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOMovie-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIONetCDF-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOParallel-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOParallelXML-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOPLY-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOSQL-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOTecplotTable-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOVideo-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOXML-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkIOXMLParser-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkjpeg-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkjsoncpp-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtklibharu-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtklibxml2-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtklz4-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkmetaio-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkNetCDF-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtknetcdfcpp-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkoggtheora-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkParallelCore-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkpng-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkproj4-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkRenderingAnnotation-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkRenderingContext2D-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkRenderingContextOpenGL2-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkRenderingCore-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkRenderingFreeType-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkRenderingGL2PSOpenGL2-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkRenderingImage-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkRenderingLabel-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkRenderingLOD-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkRenderingOpenGL2-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkRenderingQt-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkRenderingVolume-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkRenderingVolumeOpenGL2-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtksqlite-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtksys-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtktiff-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkverdict-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkViewsContext2D-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkViewsCore-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkViewsInfovis-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkViewsQt-8.1
 LIBS += -L$$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/lib/ -lvtkzlib-8.1

INCLUDEPATH += $$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/include/vtk-8.1
DEPENDPATH += $$PWD/../../../Downloads/VTK-8.1.1/VTK_INSTALL/include/vtk-8.1


LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/hdf5/serial/ -lhdf5_cpp
LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/hdf5/serial/ -lhdf5_hl
LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/hdf5/serial/ -lhdf5

INCLUDEPATH += $$PWD/../../../../../usr/include/hdf5/serial
DEPENDPATH += $$PWD/../../../../../usr/include/hdf5/serial

}




unix:!macx: LIBS += -L$$PWD/../../NewParticleGenerator/Debug/ -lpargen

INCLUDEPATH += $$PWD/../../NewParticleGenerator/Include
DEPENDPATH += $$PWD/../../NewParticleGenerator/Include

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/cuda/lib64/ -lOpenCL

INCLUDEPATH += $$PWD/../../../../../usr/local/cuda/include
DEPENDPATH += $$PWD/../../../../../usr/local/cuda/include
