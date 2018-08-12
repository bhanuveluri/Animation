#include "mainwindow.h"
#include <QApplication>
#include <vtkAutoInit.h>

#include <vtkKdTreePointLocator.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    VTK_MODULE_INIT(vtkRenderingOpenGL2);
    VTK_MODULE_INIT(vtkInteractionStyle);
    VTK_MODULE_INIT(vtkRenderingFreeType);
    MainWindow w;
    w.show();


    //    // Setup point coordinates
    //      double x[3] = {1.0, 0.0, 0.0};
    //      double y[3] = {0.0, 1.0, 0.0};
    //      double z[3] = {0.0, 0.0, 1.0};

    //    std::vector< double > x;
    //    std::vector< double > y;
    //    std::vector< double > z;

    //    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    //    //points->InsertNextPoint(x);
    //    // points->InsertNextPoint(y);
    //    //points->InsertNextPoint(z);

    //    for(int i = 0; i < 1000; i++)
    //    {
    //        x.push_back(i);
    //        y.push_back(i);
    //        z.push_back(i);
    //        points->InsertNextPoint(x[i], y[i], z[i]);
    //    }

    //    vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
    //    polydata->SetPoints(points);

    //    // Create the tree
    //    vtkSmartPointer<vtkKdTreePointLocator> kDTree = vtkSmartPointer<vtkKdTreePointLocator>::New();
    //    kDTree->SetDataSet(polydata);
    //    kDTree->BuildLocator();



    //    // Find the k closest points to (0,0,0)
    //    vtkIdType k = 1;
    //    double testPoint[3] = {0.0, 0.0, 0.0};
    //    vtkSmartPointer<vtkIdList> result = vtkSmartPointer<vtkIdList>::New();

    //    kDTree->FindPointsWithinRadius(2.0, testPoint, result);

    //    for(vtkIdType i = 0; i < result->GetNumberOfIds(); i++)
    //    {
    //        vtkIdType point_ind = result->GetId(i);
    //        double p[3];
    //        kDTree->GetDataSet()->GetPoint(point_ind, p);
    //        std::cout << "Closest point " << i << ": Point "
    //                  << point_ind << ": (" << p[0] << ", " << p[1] << ", " << p[2] << ")" << std::endl;
    //    }





    //    double testPoint[3] = {0.0, 0.0, 10.9};

    //    // Find the closest points to TestPoint
    //    //vtkIdType iD = kDTree->FindClosestPoint(testPoint);

    //    for(int i = 0; i < x.size(); i++)
    //    {
    //        double dist;
    //        vtkIdList * list;

    //        vtkIdType iD = kDTree->FindClosestPointWithinRadius(100.5, testPoint, dist);
    //        std::cout << "The closest point is point " << "iD" << "  dist  " << dist << std::endl;

    //       // for(int j = 0; j < list->GetNumberOfIds(); j++)
    //        //{
    //            //Get the coordinates of the closest point
    //            double closestPoint[3];
    //            kDTree->GetDataSet()->GetPoint(list->GetId(j), closestPoint);
    //            std::cout << "Coordinates: " << closestPoint[0] << " " << closestPoint[1] << " " << closestPoint[2] << std::endl;
    //        //}
    //    }
    return a.exec();
}
