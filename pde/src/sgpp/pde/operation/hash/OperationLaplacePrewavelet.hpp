// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsegrids.org

#ifndef OPERATIONLAPLACEPREWAVELET_HPP
#define OPERATIONLAPLACEPREWAVELET_HPP

#include <sgpp/pde/algorithm/UpDownOneOpDimWithShadow.hpp>

#include <sgpp/base/operation/hash/OperationMatrix.hpp>

#include <sgpp/base/algorithm/sweep.hpp>

#include <sgpp/base/grid/GridStorage.hpp>
#include <sgpp/base/datatypes/DataVector.hpp>

#include <sgpp/globaldef.hpp>

#include <iostream>

namespace sgpp {
namespace pde {

/**
 * Implementation for linear functions of Laplace Operation, prewavelet grids without boundaries.
 * With prewavelets the calculation of the gradient part of the up down algorithm is the more
 * complicated
 * one whereas the normal part is eased. For details on the implementation please refer to the
 * documentation
 * of the detail-classes LaplaceDownGradientPrewavelet.hpp, LaplaceUpGradientPrewavelet.hpp and
 * LaplaceDownPrewavelet.hpp.
 */
class OperationLaplacePrewavelet : public UpDownOneOpDimWithShadow {
 public:
  /**
   * Constructor of OperationLaplacePrewavelet
   *
   * @param storage Pointer to the grid's gridstorage obejct
   * @param shadowstorage shadow storage fuer prewavelets
   */
  OperationLaplacePrewavelet(sgpp::base::GridStorage* storage,
                             sgpp::base::GridStorage* shadowstorage);

  /**
   * Destructor
   */
  virtual ~OperationLaplacePrewavelet();

 protected:
  virtual void up(sgpp::base::DataVector& alpha, sgpp::base::DataVector& result, size_t dim);

  virtual void down(sgpp::base::DataVector& alpha, sgpp::base::DataVector& result, size_t dim);

  virtual void downOpDim(sgpp::base::DataVector& alpha, sgpp::base::DataVector& result, size_t dim);

  virtual void upOpDim(sgpp::base::DataVector& alpha, sgpp::base::DataVector& result, size_t dim);
};
}  // namespace pde
}  // namespace sgpp

#endif /* OPERATIONLAPLACEPREWAVELET_HPP */
