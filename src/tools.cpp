#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
	if (estimations.size() != ground_truth.size() || estimations.size() == 0) {
		return VectorXd(4);
	}

	VectorXd RMSE = VectorXd(estimations[0].size());
	RMSE.fill(0.0);

	for (size_t i = 0; i < estimations.size(); i++)
	{
		VectorXd residual = estimations[i] - ground_truth[i];

		//sum up the sqaure difference
		residual = residual.array()*residual.array();
		RMSE += residual;
	}

	//calc. mean
	RMSE = RMSE / estimations.size();

	//calc. square root
	RMSE = RMSE.array().sqrt();

	return RMSE;
}