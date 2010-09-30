////////////////////////////////////////////////////////////////////////////
//
// CVector.cpp
//
// Remi Coulom
//
// September, 2000
//
////////////////////////////////////////////////////////////////////////////
#include "CVector.h"

////////////////////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////////////////////
CVector::CVector(int SizeInit) :
 Size(0)
{
 SetSize(SizeInit);
}

////////////////////////////////////////////////////////////////////////////
// Set Size
////////////////////////////////////////////////////////////////////////////
void CVector::SetSize(int NewSize)
{
 if (Size)
 {
  delete[] pd;
  Size = 0;
 }
 if (NewSize > 0)
  pd = new double[Size = NewSize];
}

////////////////////////////////////////////////////////////////////////////
// Assignment operator
////////////////////////////////////////////////////////////////////////////
CVector &CVector::operator=(const CVector &v)
{
 if (&v != this)
 {
  if (Size != v.GetSize())
   SetSize(v.GetSize());
  for (int i = Size; --i >= 0;)
   pd[i] = v[i];
 }
 return *this;
}

////////////////////////////////////////////////////////////////////////////
// Copy constructor
////////////////////////////////////////////////////////////////////////////
CVector::CVector(const CVector &v) :
 Size(0)
{
 *this = v;
}

////////////////////////////////////////////////////////////////////////////
// Zero
////////////////////////////////////////////////////////////////////////////
void CVector::Zero()
{
 for (int i = Size; --i >= 0;)
  pd[i] = 0;
}

////////////////////////////////////////////////////////////////////////////
// Scale
////////////////////////////////////////////////////////////////////////////
void CVector::Scale(double x)
{
 for (int i = Size; --i >= 0;)
  pd[i] *= x;
}

////////////////////////////////////////////////////////////////////////////
// Add
////////////////////////////////////////////////////////////////////////////
void CVector::Add(const double *pdp)
{
 for (int i = Size; --i >= 0;)
  pd[i] += pdp[i];
}

////////////////////////////////////////////////////////////////////////////
// Add scaled
////////////////////////////////////////////////////////////////////////////
void CVector::AddScaled(const double *pdp, double x)
{
 for (int i = Size; --i >= 0;)
  pd[i] += x * pdp[i];
}

////////////////////////////////////////////////////////////////////////////
// Set from a pointer
////////////////////////////////////////////////////////////////////////////
void CVector::Set(const double *px)
{
 for (int i = Size; --i >= 0;)
  pd[i] = px[i];
}

////////////////////////////////////////////////////////////////////////////
// Destructor
////////////////////////////////////////////////////////////////////////////
CVector::~CVector()
{
 SetSize(0);
}