//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "FluxComponent.h"

registerMooseObject("Engy5310PXApp-FIXME", FluxComponent);

InputParameters
VectorFlux::validParams()
{
  InputParameters params = AuxKernel::validParams();
  MooseEnum component("x y z");
  params.addClassDescription("Compute one component of the flux of a field.");
  params.addRequiredParam<MooseEnum>("component", component, "The desired component of flux.");
  // Add a "coupling parameter" to get a variable from the input file.
  params.addRequiredCoupledVar("field", "The variable field.");
  // Add add other parameters from input file
  params.addRequiredParam<Real>("param1", "Parameter 1 meaning");
  params.addRequiredParam<Real>("param2", "Parameter 2 meaning");

  return params;
}

VectorFlux::VectorFlux(const InputParameters & parameters)
  : VectorAuxKernel(parameters),
    _component(getParam<MooseEnum>("component")),
    // Initialize variable gradient
    _gradVariableName_component(coupledGradient("variableName")),
    // Initialize parameters
    _param1(getParam<Real>("param1")),
    _param2(getParam<Real>("param2"))
{
}

Real
VectorFlux::computeValue()
{
  // Access the gradient of the variable at this quadrature point, then pull out the 
  // "component" of it requested (x, y or z). Note, that getting a particular component 
  // of a gradient is done using the parenthesis operator.
  FIXME return - _param1 * _param2 * _gradVariableName_component[_qp](_component);
}