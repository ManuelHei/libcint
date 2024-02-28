/*
 * Copyright (C) 2013-  Qiming Sun <osirpt.sun@gmail.com>
 * Description: code generated by  gen-code.cl
 */
#include <stdlib.h>
#include <stdio.h>
#include "cint_bas.h"
#include "cart2sph.h"
#include "g1e.h"
#include "g1e_grids.h"
#include "g2e.h"
#include "optimizer.h"
#include "cint1e.h"
#include "cint2e.h"
#include "misc.h"
#include "c2f.h"
/* <k i|R12 |j l> : i,j \in electron 1; k,l \in electron 2
 * = (i j|R12 |k l) */
void CINTgout2e_int2e_rinv2(double *gout,
double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, i, n;
double *g0 = g;
double s[1];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
switch (nrys_roots) {
case 1:
s[0] = + g0[ix+0]*g0[iy+0]*g0[iz+0];
break;
case 2:
s[0] = + g0[ix+0]*g0[iy+0]*g0[iz+0]+ g0[ix+1]*g0[iy+1]*g0[iz+1];
break;
case 3:
s[0] = + g0[ix+0]*g0[iy+0]*g0[iz+0]+ g0[ix+1]*g0[iy+1]*g0[iz+1]+ g0[ix+2]*g0[iy+2]*g0[iz+2];
break;
case 4:
s[0] = + g0[ix+0]*g0[iy+0]*g0[iz+0]+ g0[ix+1]*g0[iy+1]*g0[iz+1]+ g0[ix+2]*g0[iy+2]*g0[iz+2]+ g0[ix+3]*g0[iy+3]*g0[iz+3];
break;
default:
for (i = 0; i < 1; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g0[ix+i] * g0[iy+i] * g0[iz+i];
} break;}
if (gout_empty) {
gout[n*1+0] = + s[0];
} else {
gout[n*1+0] += + s[0];
}}}
void int2e_rinv2_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {0, 0, 0, 0, 0, 1, 1, 1};
CINTall_2e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int2e_rinv2_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 0, 0, 0, 0, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_rinv2;
envs.common_factor *= 1.0;
return CINT2e_drv(out, dims, &envs, opt, cache, &c2s_cart_2e1);
} // int2e_rinv2_cart
CACHE_SIZE_T int2e_rinv2_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 0, 0, 0, 0, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_rinv2;
envs.common_factor *= 1.0;
return CINT2e_drv(out, dims, &envs, opt, cache, &c2s_sph_2e1);
} // int2e_rinv2_sph
CACHE_SIZE_T int2e_rinv2_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 0, 0, 0, 0, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_rinv2;
envs.common_factor *= 1.0;
return CINT2e_spinor_drv(out, dims, &envs, opt, cache, &c2s_sf_2e1, &c2s_sf_2e2);
} // int2e_rinv2_spinor
ALL_CINT(int2e_rinv2)
ALL_CINT_FORTRAN_(int2e_rinv2)
