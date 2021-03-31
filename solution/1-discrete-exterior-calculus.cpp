// PLEASE READ:
//
// This file additional geometry routines for the VertexPositionGeometry class in Geometry Central. Because we are
// "inside" the class, we no longer have to call
//
//          geometry->inputVertexPositions[v], etc.
//
// We can just call
//
//          this->inputVertexPositions[v], etc.
//
// or simply
//
//          inputVertexPositions[v], etc.
//
// In addition, we no longer access the corresponding surface mesh via
//
//          mesh->vertices(), etc.
//
// but instead <mesh> is not a pointer anymore, so we use
//
//          mesh.vertices(), etc.
//
// Functions in this file can be called from other projects simply by using geometry->buildHodgeStar0Form(), etc. where
// "geometry" is a pointer to a VertexPositionGeometry. This avoids having to declare a GeometryRoutines object in every
// project, and also mimics the way that geometry routines are normally called in Geometry Central.
//
// Other notes: In this file, you can use the constant pi by using PI.

#include "geometrycentral/surface/vertex_position_geometry.h"

using SM = Eigen::SparseMatrix<double>;
using Trp = Eigen::Triplet<double>;

namespace geometrycentral {
namespace surface {


/*
 * Build Hodge operator on 0-forms.
 * By convention, the area of a vertex is 1.
 *
 * Input:
 * Returns: A sparse diagonal matrix representing the Hodge operator that can be applied to discrete 0-forms.
 */
SM VertexPositionGeometry::buildHodgeStar0Form() const {
    std::vector<Trp> triplets;
    for (Vertex v : mesh.vertices()) 
        triplets.push_back( 
            Trp(v.getIndex(), v.getIndex(), barycentricDualArea(v)) 
        );
    SM matrix(mesh.nVertices(), mesh.nVertices());
    matrix.setFromTriplets(triplets.begin(), triplets.end());
    return matrix;
}

/*
 * Build Hodge operator on 1-forms.
 *
 * Input:
 * Returns: A sparse diagonal matrix representing the Hodge operator that can be applied to discrete 1-forms.
 */
SM VertexPositionGeometry::buildHodgeStar1Form() const {
    std::vector<Trp> triplets;
    for (Edge e : mesh.edges()) {
        double area = (cotan(e.halfedge()) + cotan(e.halfedge().twin())) / 2;
        triplets.push_back( Trp(e.getIndex(), e.getIndex(), area) );
    }
    SM matrix(mesh.nEdges(), mesh.nEdges());
    matrix.setFromTriplets(triplets.begin(), triplets.end());
    return matrix;
}

/*
 * Build Hodge operator on 2-forms.
 *
 * Input:
 * Returns: A sparse diagonal matrix representing the Hodge operator that can be applied to discrete 2-forms.
 */
SM VertexPositionGeometry::buildHodgeStar2Form() const {
    std::vector<Trp> triplets;
    for (Face f : mesh.faces()) 
        triplets.push_back( 
            Trp(f.getIndex(), f.getIndex(), 1 / faceArea(f)) 
        );
    SM matrix(mesh.nFaces(), mesh.nFaces());
    matrix.setFromTriplets(triplets.begin(), triplets.end());
    return matrix;
}

/*
 * Build exterior derivative on 0-forms.
 *
 * Input:
 * Returns: A sparse diagonal matrix representing the exterior derivative that can be applied to discrete 0-forms.
 */
SM VertexPositionGeometry::buildExteriorDerivative0Form() const {
    std::vector<Trp> triplets;
    for (Edge e : mesh.edges()) {
        triplets.push_back( Trp(e.getIndex(), e.firstVertex().getIndex(), -1) );
        triplets.push_back( Trp(e.getIndex(), e.secondVertex().getIndex(), 1) );
    }
    SM matrix(mesh.nEdges(), mesh.nVertices());
    matrix.setFromTriplets(triplets.begin(), triplets.end());
    return matrix;
}

/*
 * Build exterior derivative on 1-forms.
 *
 * Input:
 * Returns: A sparse diagonal matrix representing the exterior derivative that can be applied to discrete 1-forms.
 */
SM VertexPositionGeometry::buildExteriorDerivative1Form() const {
    std::vector<Trp> triplets;
    for (Face f : mesh.faces()) 
        for (Halfedge he : f.adjacentHalfedges()) {
            double orientation = he.getIndex() < he.twin().getIndex() ? 1 : -1;
            triplets.push_back( 
                Trp(f.getIndex(), he.edge().getIndex(), orientation) 
            );
        } 
    SM matrix(mesh.nFaces(), mesh.nEdges());
    matrix.setFromTriplets(triplets.begin(), triplets.end());
    return matrix;
}

} // namespace surface
} // namespace geometrycentral