// Implement member functions for SimplicialComplexOperators class.
#include "simplicial-complex-operators.h"

using namespace geometrycentral;
using namespace geometrycentral::surface;
using SM = SparseMatrix<size_t>;
using Trp = Eigen::Triplet<size_t>;
using Vec = Vector<size_t>;

/*
 * Assign a unique index to each vertex, edge, and face of a mesh.
 * All elements are 0-indexed.
 *
 * Input: None. Access geometry via the member variable <geometry>, and pointer to the mesh via <mesh>.
 * Returns: None.
 */
void SimplicialComplexOperators::assignElementIndices() {

    // You can set the index field of a vertex via geometry->vertexIndices[v], where v is a Vertex object (or an
    // integer). Similarly you can do edges and faces via geometry->edgeIndices, geometry->faceIndices, like so:

    for (size_t i = 0; i < mesh->nVertices(); i++) {
        geometry->vertexIndices[i] = i;
    }

    // // This is also valid:
    // size_t idx = 0;
    // for (Vertex v : mesh->vertices()) {
    //     geometry->vertexIndices[v] = idx;
    //     idx++;
    // }

    for (size_t i = 0; i < mesh->nEdges(); i++) {
        geometry->edgeIndices[i] = i;
    }

    for (size_t i = 0; i < mesh->nFaces(); i++) {
        geometry->faceIndices[i] = i;
    }

    // Geometry Central already sets the indices for us, though, so this function is just here for demonstration.
    // You don't have to do anything :)
}

/*
 * Construct the unsigned vertex-edge adjacency matrix A0.
 *
 * Input:
 * Returns: The sparse vertex-edge adjacency matrix which gets stored in the global variable A0.
 */
SM SimplicialComplexOperators::buildVertexEdgeAdjacencyMatrix() const {
    // Note: You can build an Eigen sparse matrix from triplets, then return it as a Geometry Central SparseMatrix.
    // See <https://eigen.tuxfamily.org/dox/group__TutorialSparse.html> for documentation.
    std::vector<Trp> triplets;
    for (Edge e : mesh->edges()) {
        for (Vertex v : e.adjacentVertices()) {
            triplets.push_back( Trp(e.getIndex(), v.getIndex(), 1) );
        }
    }
    SM matrix(mesh->nEdges(), mesh->nVertices());
    matrix.setFromTriplets(triplets.begin(), triplets.end());
    return matrix;
}

/*
 * Construct the unsigned face-edge adjacency matrix A1.
 *
 * Input:
 * Returns: The sparse face-edge adjacency matrix which gets stored in the global variable A1.
 */
SM SimplicialComplexOperators::buildFaceEdgeAdjacencyMatrix() const {
    std::vector<Trp> triplets;
    for (Face f : mesh->faces()) {
        for (Edge e : f.adjacentEdges()) {
            triplets.push_back( Trp(f.getIndex(), e.getIndex(), 1) );
        }
    }
    SM matrix(mesh->nFaces(), mesh->nEdges());
    matrix.setFromTriplets(triplets.begin(), triplets.end());
    return matrix;
}

/*
 * Construct a vector encoding the vertices in the selected subset of simplices.
 *
 * Input: Selected subset of simplices.
 * Returns: Vector of length |V|, where |V| = # of vertices in the mesh.
 */
Vec SimplicialComplexOperators::buildVertexVector(const MeshSubset& subset) const {
    Vec vector = Vec::Zero( mesh->nVertices() );
    for (size_t i : subset.vertices) vector[i] = 1;
    return vector;
}

/*
 * Construct a vector encoding the edges in the selected subset of simplices.
 *
 * Input: Selected subset of simplices.
 * Returns: Vector of length |E|, where |E| = # of edges in mesh.
 */
Vec SimplicialComplexOperators::buildEdgeVector(const MeshSubset& subset) const {
    Vec vector = Vec::Zero( mesh->nEdges() );
    for (size_t i : subset.edges) vector[i] = 1;
    return vector;
}

/*
 * Construct a vector encoding the faces in the selected subset of simplices.
 *
 * Input: Selected subset of simplices.
 * Returns: Vector of length |F|, where |F| = # of faces in mesh.
 */
Vec SimplicialComplexOperators::buildFaceVector(const MeshSubset& subset) const {
    Vec vector = Vec::Zero( mesh->nFaces() );
    for (size_t i : subset.faces) vector[i] = 1;
    return vector;
}

/*
 * Compute the simplicial star St(S) of the selected subset of simplices.
 *
 * Input: A MeshSubset object containing the indices of the currently active vertices, edges, and faces, respectively.
 * Returns: The star of the given subset.
 */
MeshSubset SimplicialComplexOperators::star(const MeshSubset& subset) const {
    MeshSubset star = subset.deepCopy();

    Vec vertexVec = this->buildVertexVector(subset);
    for (size_t i = 0; i < mesh->nVertices(); i++) {
        if (vertexVec[i] != 0) star.addVertex(i);
    }

    Vec edgeVec = this->buildEdgeVector(subset);
    edgeVec += this->buildVertexEdgeAdjacencyMatrix() * vertexVec;
    for (size_t i = 0; i < mesh->nEdges(); i++) {
        if (edgeVec[i] != 0) star.addEdge(i);
    }

    Vec faceVec = this->buildFaceVector(subset);
    faceVec += this->buildFaceEdgeAdjacencyMatrix() * edgeVec;
    for (size_t i = 0; i < mesh->nFaces(); i++) {
        if (faceVec[i] != 0) star.addFace(i);
    }

    return star;
}


/*
 * Compute the closure Cl(S) of the selected subset of simplices.
 *
 * Input: A MeshSubset object containing the indices of the currently active vertices, edges, and faces, respectively.
 * Returns: The closure of the given subset.
 */
MeshSubset SimplicialComplexOperators::closure(const MeshSubset& subset) const {

    // TODO
    return subset; // placeholder
}

/*
 * Compute the link Lk(S) of the selected subset of simplices.
 *
 * Input: A MeshSubset object containing the indices of the currently active vertices, edges, and faces, respectively.
 * Returns: The link of the given subset.
 */
MeshSubset SimplicialComplexOperators::link(const MeshSubset& subset) const {

    // TODO
    return subset; // placeholder
}

/*
 * Return true if the selected subset is a simplicial complex, false otherwise.
 *
 * Input: A MeshSubset object containing the indices of the currently active vertices, edges, and faces, respectively.
 * Returns: True if given subset is a simplicial complex, false otherwise.
 */
bool SimplicialComplexOperators::isComplex(const MeshSubset& subset) const {

    // TODO
    return false; // placeholder
}

/*
 * Check if the given subset S is a pure simplicial complex. If so, return the degree of the complex. Otherwise, return
 * -1.
 *
 * Input: A MeshSubset object containing the indices of the currently active vertices, edges, and faces, respectively.
 * Returns: int representing the degree of the given complex (-1 if not pure)
 */
int SimplicialComplexOperators::isPureComplex(const MeshSubset& subset) const {

    // TODO
    return -1; // placeholder
}

/*
 * Compute the set of simplices contained in the boundary bd(S) of the selected subset S of simplices.
 *
 * Input: A MeshSubset object containing the indices of the currently active vertices, edges, and faces, respectively.
 * Returns: The boundary of the given subset.
 */
MeshSubset SimplicialComplexOperators::boundary(const MeshSubset& subset) const {

    // TODO
    return subset; // placeholder
}