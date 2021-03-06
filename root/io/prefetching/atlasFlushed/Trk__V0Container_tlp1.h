//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Tue Jun 14 15:33:00 2011 by ROOT version 5.31/01)
//      from the StreamerInfo in file http://root.cern.ch/files/atlasFlushed.root
//////////////////////////////////////////////////////////


#ifndef Trk__V0Container_tlp1_h
#define Trk__V0Container_tlp1_h
namespace Trk {
class V0Container_tlp1;
} // end of namespace.

#include "Riostream.h"
#include <vector>
#include "Trk__V0Container_p1.h"
#include "Trk__V0Candidate_p1.h"
#include "Trk__V0Hypothesis_p1.h"
#include "Trk__ExtendedVxCandidate_p1.h"
#include "Trk__VxCandidate_p1.h"
#include "Trk__VxTrackAtVertex_p1.h"
#include "Trk__RecVertex_p1.h"
#include "Trk__Vertex_p1.h"
#include "Trk__Track_p1.h"
#include "Trk__TrackParameters_p1.h"
#include "Trk__Perigee_p1.h"
#include "Trk__MeasuredPerigee_p1.h"
#include "Trk__Surface_p1.h"
#include "Trk__FitQuality_p1.h"
#include "Trk__HepSymMatrix_p1.h"

namespace Trk {
class V0Container_tlp1 {

public:
// Nested classes declaration.

public:
// Data Members.
   vector<Trk::V0Container_p1> m_v0Containers;    //(Trk::V0Container_p1)
   vector<Trk::V0Candidate_p1> m_v0Candidates;    //(Trk::V0Candidate_p1)
   vector<Trk::V0Hypothesis_p1> m_v0Hypothesises;    //(Trk::V0Hypothesis_p1)
   vector<Trk::ExtendedVxCandidate_p1> m_extendedVxCandidates;    //(Trk::ExtendedVxCandidate_p1)
   vector<Trk::VxCandidate_p1>         m_vxCandidates;            //(Trk::VxCandidate_p1)
   vector<Trk::VxTrackAtVertex_p1>     m_vxTracksAtVertex;        //(Trk::VxTrackAtVertex_p1)
   vector<Trk::RecVertex_p1>           m_recVertices;             //(Trk::RecVertex_p1)
   vector<Trk::Vertex_p1>              m_vertices;                //(Trk::Vertex_p1)
   vector<Trk::Track_p1>               m_tracks;                  //(Trk::Track_p1)
   vector<Trk::TrackParameters_p1>     m_trackParameters;         //(Trk::TrackParameters_p1)
   vector<Trk::Perigee_p1>             m_perigees;                //(Trk::Perigee_p1)
   vector<Trk::MeasuredPerigee_p1>     m_measPerigees;            //(Trk::MeasuredPerigee_p1)
   vector<Trk::Surface_p1>             m_surfaces;                //(Trk::Surface_p1)
   vector<Trk::FitQuality_p1>          m_fitQualities;            //(Trk::FitQuality_p1)
   vector<Trk::HepSymMatrix_p1>        m_hepSymMatrices;          //(Trk::HepSymMatrix_p1)

   V0Container_tlp1();
   V0Container_tlp1(const V0Container_tlp1 & );
   virtual ~V0Container_tlp1();

};
} // namespace
#endif
