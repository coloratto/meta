/**
 * @file dirichlet_prior.cpp
 * @author Sean Massung
 */

#include "index/ranker/dirichlet_prior.h"
#include "index/score_data.h"

namespace meta
{
namespace index
{

dirichlet_prior::dirichlet_prior(double mu) : _mu{mu}
{/* nothing */
}

double dirichlet_prior::smoothed_prob(const score_data& sd) const
{
    double pc = static_cast<double>(sd.corpus_term_count) / sd.total_terms;
    double numerator = sd.doc_term_count + _mu * pc;
    double denominator = sd.doc_size + _mu;
    return numerator / denominator;
}

double dirichlet_prior::doc_constant(const score_data& sd) const
{
    return _mu / (sd.doc_size + _mu);
}
}
}