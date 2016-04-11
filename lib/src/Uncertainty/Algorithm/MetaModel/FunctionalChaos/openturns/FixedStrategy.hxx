//                                               -*- C++ -*-
/**
 *  @brief An implementation directly returning the full set of polynomials
 *
 *  Copyright 2005-2016 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_FIXEDSTRATEGY_HXX
#define OPENTURNS_FIXEDSTRATEGY_HXX

#include "openturns/AdaptiveStrategyImplementation.hxx"

BEGIN_NAMESPACE_OPENTURNS



/**
 * @class FixedStrategy
 *
 * An implementation directly returning the full set of polynomials
 */

class OT_API FixedStrategy
  : public AdaptiveStrategyImplementation
{
  CLASSNAME;
public:


  /** Constructor from an orthogonal basis */
  FixedStrategy(const OrthogonalBasis & basis,
                const UnsignedInteger maximumDimension);

  /** Virtual constructor */
  virtual FixedStrategy * clone() const;

  /** Compute initial basis for the approximation */
  void computeInitialBasis();

  /** Update the basis for the next iteration of approximation */
  void updateBasis(const NumericalPoint & alpha_k,
                   const NumericalScalar residual,
                   const NumericalScalar relativeError);

  /** String converter */
  virtual String __repr__() const;

  /** Method save() stores the object through the StorageManager */
  virtual void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  virtual void load(Advocate & adv);


protected:

  friend class Factory<FixedStrategy>;

  /** Default constructor */
  FixedStrategy();

private:

} ; /* class FixedStrategy */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_FIXEDSTRATEGY_HXX */