/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__na2_ch_ptr
#define _nrn_initial _nrn_initial__na2_ch_ptr
#define nrn_cur _nrn_cur__na2_ch_ptr
#define _nrn_current _nrn_current__na2_ch_ptr
#define nrn_jacob _nrn_jacob__na2_ch_ptr
#define nrn_state _nrn_state__na2_ch_ptr
#define _net_receive _net_receive__na2_ch_ptr 
#define kin kin__na2_ch_ptr 
#define rates rates__na2_ch_ptr 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gbar _p[0]
#define modDA _p[1]
#define maxModDA _p[2]
#define g _p[3]
#define ina _p[4]
#define a _p[5]
#define c1 _p[6]
#define c2 _p[7]
#define c3 _p[8]
#define c4 _p[9]
#define c5 _p[10]
#define ct _p[11]
#define o _p[12]
#define i1 _p[13]
#define i2 _p[14]
#define i3 _p[15]
#define i4 _p[16]
#define i5 _p[17]
#define i6 _p[18]
#define ift _p[19]
#define is1 _p[20]
#define is2 _p[21]
#define ist _p[22]
#define it _p[23]
#define ena _p[24]
#define alpha _p[25]
#define beta _p[26]
#define gamma _p[27]
#define delta _p[28]
#define Dc1 _p[29]
#define Dc2 _p[30]
#define Dc3 _p[31]
#define Dc4 _p[32]
#define Dc5 _p[33]
#define Dct _p[34]
#define Do _p[35]
#define Di1 _p[36]
#define Di2 _p[37]
#define Di3 _p[38]
#define Di4 _p[39]
#define Di5 _p[40]
#define Di6 _p[41]
#define Dift _p[42]
#define Dis1 _p[43]
#define Dis2 _p[44]
#define Dist _p[45]
#define Dit _p[46]
#define _g _p[47]
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
#define levelDA	*_ppvar[3]._pval
#define _p_levelDA	_ppvar[3]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  3;
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_modulationDA(void);
 static void _hoc_rates(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_na2_ch_ptr", _hoc_setdata,
 "modulationDA_na2_ch_ptr", _hoc_modulationDA,
 "rates_na2_ch_ptr", _hoc_rates,
 0, 0
};
#define modulationDA modulationDA_na2_ch_ptr
 extern double modulationDA( );
 /* declare global and static user variables */
#define Coff Coff_na2_ch_ptr
 double Coff = 0.1;
#define Con Con_na2_ch_ptr
 double Con = 0.001;
#define Ooff Ooff_na2_ch_ptr
 double Ooff = 0.01;
#define Oon Oon_na2_ch_ptr
 double Oon = 1.6;
#define aS2 aS2_na2_ch_ptr
 double aS2 = 0.0002;
#define aS1 aS1_na2_ch_ptr
 double aS1 = 0.0025;
#define a0 a0_na2_ch_ptr
 double a0 = 37;
#define bS bS_na2_ch_ptr
 double bS = 0.00017;
#define b0 b0_na2_ch_ptr
 double b0 = 10;
#define d0 d0_na2_ch_ptr
 double d0 = 30;
#define g0 g0_na2_ch_ptr
 double g0 = 40;
#define vcb vcb_na2_ch_ptr
 double vcb = -10;
#define vhb vhb_na2_ch_ptr
 double vhb = -50;
#define vca vca_na2_ch_ptr
 double vca = 40;
#define vha vha_na2_ch_ptr
 double vha = 45;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "a0_na2_ch_ptr", "1/ms",
 "vha_na2_ch_ptr", "mV",
 "vca_na2_ch_ptr", "mV",
 "b0_na2_ch_ptr", "1/ms",
 "vhb_na2_ch_ptr", "mV",
 "vcb_na2_ch_ptr", "mV",
 "g0_na2_ch_ptr", "1/ms",
 "d0_na2_ch_ptr", "1/ms",
 "aS1_na2_ch_ptr", "1/ms",
 "aS2_na2_ch_ptr", "1/ms",
 "bS_na2_ch_ptr", "1/ms",
 "Con_na2_ch_ptr", "1/ms",
 "Coff_na2_ch_ptr", "1/ms",
 "Oon_na2_ch_ptr", "1/ms",
 "Ooff_na2_ch_ptr", "1/ms",
 "gbar_na2_ch_ptr", "S/cm2",
 "g_na2_ch_ptr", "S/cm2",
 "ina_na2_ch_ptr", "mA/cm2",
 0,0
};
 static double ct0 = 0;
 static double c50 = 0;
 static double c40 = 0;
 static double c30 = 0;
 static double c20 = 0;
 static double c10 = 0;
 static double delta_t = 0.01;
 static double it0 = 0;
 static double ist0 = 0;
 static double is20 = 0;
 static double is10 = 0;
 static double ift0 = 0;
 static double i60 = 0;
 static double i50 = 0;
 static double i40 = 0;
 static double i30 = 0;
 static double i20 = 0;
 static double i10 = 0;
 static double o0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "a0_na2_ch_ptr", &a0_na2_ch_ptr,
 "vha_na2_ch_ptr", &vha_na2_ch_ptr,
 "vca_na2_ch_ptr", &vca_na2_ch_ptr,
 "b0_na2_ch_ptr", &b0_na2_ch_ptr,
 "vhb_na2_ch_ptr", &vhb_na2_ch_ptr,
 "vcb_na2_ch_ptr", &vcb_na2_ch_ptr,
 "g0_na2_ch_ptr", &g0_na2_ch_ptr,
 "d0_na2_ch_ptr", &d0_na2_ch_ptr,
 "aS1_na2_ch_ptr", &aS1_na2_ch_ptr,
 "aS2_na2_ch_ptr", &aS2_na2_ch_ptr,
 "bS_na2_ch_ptr", &bS_na2_ch_ptr,
 "Con_na2_ch_ptr", &Con_na2_ch_ptr,
 "Coff_na2_ch_ptr", &Coff_na2_ch_ptr,
 "Oon_na2_ch_ptr", &Oon_na2_ch_ptr,
 "Ooff_na2_ch_ptr", &Ooff_na2_ch_ptr,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[4]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"na2_ch_ptr",
 "gbar_na2_ch_ptr",
 "modDA_na2_ch_ptr",
 "maxModDA_na2_ch_ptr",
 0,
 "g_na2_ch_ptr",
 "ina_na2_ch_ptr",
 "a_na2_ch_ptr",
 0,
 "c1_na2_ch_ptr",
 "c2_na2_ch_ptr",
 "c3_na2_ch_ptr",
 "c4_na2_ch_ptr",
 "c5_na2_ch_ptr",
 "ct_na2_ch_ptr",
 "o_na2_ch_ptr",
 "i1_na2_ch_ptr",
 "i2_na2_ch_ptr",
 "i3_na2_ch_ptr",
 "i4_na2_ch_ptr",
 "i5_na2_ch_ptr",
 "i6_na2_ch_ptr",
 "ift_na2_ch_ptr",
 "is1_na2_ch_ptr",
 "is2_na2_ch_ptr",
 "ist_na2_ch_ptr",
 "it_na2_ch_ptr",
 0,
 "levelDA_na2_ch_ptr",
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 48, _prop);
 	/*initialize range parameters*/
 	gbar = 1;
 	modDA = 0;
 	maxModDA = 1;
 	_prop->param = _p;
 	_prop->param_size = 48;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _na2_ch_ptr_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("na", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 48, 5);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "pointer");
  hoc_register_dparam_semantics(_mechtype, 4, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 na2_ch_ptr /home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation/striatal_network/synapse-wide/Experiment-Simulation/x86_64/na2_ch_ptr.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(double);
 extern double *_getelm();
 
#define _MATELM1(_row,_col)	*(_getelm(_row + 1, _col + 1))
 
#define _RHS1(_arg) _coef1[_arg + 1]
 static double *_coef1;
 
#define _linmat1  1
 static void* _sparseobj1;
 static void* _cvsparseobj1;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[14], _dlist1[14]; static double *_temp1;
 static int kin();
 
static int kin ()
 {_reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<14;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargscomma_ v ) ;
   /* ~ c1 <-> c2 ( 4.0 * alpha , beta )*/
 f_flux =  4.0 * alpha * c1 ;
 b_flux =  beta * c2 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  4.0 * alpha ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  beta ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ c2 <-> c3 ( 3.0 * alpha , 2.0 * beta )*/
 f_flux =  3.0 * alpha * c2 ;
 b_flux =  2.0 * beta * c3 ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  3.0 * alpha ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  2.0 * beta ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ c3 <-> c4 ( 2.0 * alpha , 3.0 * beta )*/
 f_flux =  2.0 * alpha * c3 ;
 b_flux =  3.0 * beta * c4 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  2.0 * alpha ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  3.0 * beta ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ c4 <-> c5 ( alpha , 4.0 * beta )*/
 f_flux =  alpha * c4 ;
 b_flux =  4.0 * beta * c5 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  alpha ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  4.0 * beta ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ c5 <-> o ( gamma , delta )*/
 f_flux =  gamma * c5 ;
 b_flux =  delta * o ;
 _RHS1( 1) -= (f_flux - b_flux);
 
 _term =  gamma ;
 _MATELM1( 1 ,1)  += _term;
 _term =  delta ;
 _MATELM1( 1 ,0)  -= _term;
 /*REACTION*/
  /* ~ o <-> is1 ( aS1 , bS )*/
 f_flux =  aS1 * o ;
 b_flux =  bS * is1 ;
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  aS1 ;
 _MATELM1( 7 ,0)  -= _term;
 _term =  bS ;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ i1 <-> i2 ( 4.0 * alpha * a , beta / a )*/
 f_flux =  4.0 * alpha * a * i1 ;
 b_flux =  beta / a * i2 ;
 _RHS1( 13) -= (f_flux - b_flux);
 _RHS1( 12) += (f_flux - b_flux);
 
 _term =  4.0 * alpha * a ;
 _MATELM1( 13 ,13)  += _term;
 _MATELM1( 12 ,13)  -= _term;
 _term =  beta / a ;
 _MATELM1( 13 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ i2 <-> i3 ( 3.0 * alpha * a , 2.0 * beta / a )*/
 f_flux =  3.0 * alpha * a * i2 ;
 b_flux =  2.0 * beta / a * i3 ;
 _RHS1( 12) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  3.0 * alpha * a ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  2.0 * beta / a ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ i3 <-> i4 ( 2.0 * alpha * a , 3.0 * beta / a )*/
 f_flux =  2.0 * alpha * a * i3 ;
 b_flux =  3.0 * beta / a * i4 ;
 _RHS1( 11) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  2.0 * alpha * a ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 10 ,11)  -= _term;
 _term =  3.0 * beta / a ;
 _MATELM1( 11 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ i4 <-> i5 ( alpha * a , 4.0 * beta / a )*/
 f_flux =  alpha * a * i4 ;
 b_flux =  4.0 * beta / a * i5 ;
 _RHS1( 10) -= (f_flux - b_flux);
 _RHS1( 9) += (f_flux - b_flux);
 
 _term =  alpha * a ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 9 ,10)  -= _term;
 _term =  4.0 * beta / a ;
 _MATELM1( 10 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ i5 <-> i6 ( gamma , delta )*/
 f_flux =  gamma * i5 ;
 b_flux =  delta * i6 ;
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 8) += (f_flux - b_flux);
 
 _term =  gamma ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  delta ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ i6 <-> is2 ( aS2 , bS )*/
 f_flux =  aS2 * i6 ;
 b_flux =  bS * is2 ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 6) += (f_flux - b_flux);
 
 _term =  aS2 ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 6 ,8)  -= _term;
 _term =  bS ;
 _MATELM1( 8 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ c1 <-> i1 ( Con , Coff )*/
 f_flux =  Con * c1 ;
 b_flux =  Coff * i1 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 13) += (f_flux - b_flux);
 
 _term =  Con ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 13 ,5)  -= _term;
 _term =  Coff ;
 _MATELM1( 5 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  /* ~ c2 <-> i2 ( Con * a , Coff / a )*/
 f_flux =  Con * a * c2 ;
 b_flux =  Coff / a * i2 ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 12) += (f_flux - b_flux);
 
 _term =  Con * a ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 12 ,4)  -= _term;
 _term =  Coff / a ;
 _MATELM1( 4 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ c3 <-> i3 ( Con * pow( a , 2.0 ) , Coff / pow( a , 2.0 ) )*/
 f_flux =  Con * pow( a , 2.0 ) * c3 ;
 b_flux =  Coff / pow( a , 2.0 ) * i3 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  Con * pow( a , 2.0 ) ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 11 ,3)  -= _term;
 _term =  Coff / pow( a , 2.0 ) ;
 _MATELM1( 3 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ c4 <-> i4 ( Con * pow( a , 3.0 ) , Coff / pow( a , 3.0 ) )*/
 f_flux =  Con * pow( a , 3.0 ) * c4 ;
 b_flux =  Coff / pow( a , 3.0 ) * i4 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  Con * pow( a , 3.0 ) ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 10 ,2)  -= _term;
 _term =  Coff / pow( a , 3.0 ) ;
 _MATELM1( 2 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ c5 <-> i5 ( Con * pow( a , 4.0 ) , Coff / pow( a , 4.0 ) )*/
 f_flux =  Con * pow( a , 4.0 ) * c5 ;
 b_flux =  Coff / pow( a , 4.0 ) * i5 ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 9) += (f_flux - b_flux);
 
 _term =  Con * pow( a , 4.0 ) ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 9 ,1)  -= _term;
 _term =  Coff / pow( a , 4.0 ) ;
 _MATELM1( 1 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ o <-> i6 ( Oon , Ooff )*/
 f_flux =  Oon * o ;
 b_flux =  Ooff * i6 ;
 _RHS1( 8) += (f_flux - b_flux);
 
 _term =  Oon ;
 _MATELM1( 8 ,0)  -= _term;
 _term =  Ooff ;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
   /* c1 + c2 + c3 + c4 + c5 + i1 + i2 + i3 + i4 + i5 + i6 + is1 + is2 + o = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= o ;
 _MATELM1(0, 6) = 1;
 _RHS1(0) -= is2 ;
 _MATELM1(0, 7) = 1;
 _RHS1(0) -= is1 ;
 _MATELM1(0, 8) = 1;
 _RHS1(0) -= i6 ;
 _MATELM1(0, 9) = 1;
 _RHS1(0) -= i5 ;
 _MATELM1(0, 10) = 1;
 _RHS1(0) -= i4 ;
 _MATELM1(0, 11) = 1;
 _RHS1(0) -= i3 ;
 _MATELM1(0, 12) = 1;
 _RHS1(0) -= i2 ;
 _MATELM1(0, 13) = 1;
 _RHS1(0) -= i1 ;
 _MATELM1(0, 1) = 1;
 _RHS1(0) -= c5 ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= c4 ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= c3 ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= c2 ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= c1 ;
 /*CONSERVATION*/
   } return _reset;
 }
 
static int  rates (  double _lv ) {
   alpha = a0 * exp ( ( _lv - vha ) / vca ) ;
   beta = b0 * exp ( ( _lv - vhb ) / vcb ) ;
   gamma = g0 ;
   delta = d0 ;
   a = pow( ( ( Coff / Con ) / ( Ooff / Oon ) ) , ( 1.0 / 8.0 ) ) ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   _r = 1.;
 rates (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double modulationDA (  ) {
   double _lmodulationDA;
 _lmodulationDA = 1.0 + modDA * ( maxModDA - 1.0 ) * levelDA ;
   
return _lmodulationDA;
 }
 
static void _hoc_modulationDA(void) {
  double _r;
   _r =  modulationDA (  );
 hoc_retpushx(_r);
}
 
/*CVODE ode begin*/
 static int _ode_spec1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<14;_i++) _p[_dlist1[_i]] = 0.0;}
 rates ( _threadargscomma_ v ) ;
 /* ~ c1 <-> c2 ( 4.0 * alpha , beta )*/
 f_flux =  4.0 * alpha * c1 ;
 b_flux =  beta * c2 ;
 Dc1 -= (f_flux - b_flux);
 Dc2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c2 <-> c3 ( 3.0 * alpha , 2.0 * beta )*/
 f_flux =  3.0 * alpha * c2 ;
 b_flux =  2.0 * beta * c3 ;
 Dc2 -= (f_flux - b_flux);
 Dc3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c3 <-> c4 ( 2.0 * alpha , 3.0 * beta )*/
 f_flux =  2.0 * alpha * c3 ;
 b_flux =  3.0 * beta * c4 ;
 Dc3 -= (f_flux - b_flux);
 Dc4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c4 <-> c5 ( alpha , 4.0 * beta )*/
 f_flux =  alpha * c4 ;
 b_flux =  4.0 * beta * c5 ;
 Dc4 -= (f_flux - b_flux);
 Dc5 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c5 <-> o ( gamma , delta )*/
 f_flux =  gamma * c5 ;
 b_flux =  delta * o ;
 Dc5 -= (f_flux - b_flux);
 Do += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ o <-> is1 ( aS1 , bS )*/
 f_flux =  aS1 * o ;
 b_flux =  bS * is1 ;
 Do -= (f_flux - b_flux);
 Dis1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i1 <-> i2 ( 4.0 * alpha * a , beta / a )*/
 f_flux =  4.0 * alpha * a * i1 ;
 b_flux =  beta / a * i2 ;
 Di1 -= (f_flux - b_flux);
 Di2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i2 <-> i3 ( 3.0 * alpha * a , 2.0 * beta / a )*/
 f_flux =  3.0 * alpha * a * i2 ;
 b_flux =  2.0 * beta / a * i3 ;
 Di2 -= (f_flux - b_flux);
 Di3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i3 <-> i4 ( 2.0 * alpha * a , 3.0 * beta / a )*/
 f_flux =  2.0 * alpha * a * i3 ;
 b_flux =  3.0 * beta / a * i4 ;
 Di3 -= (f_flux - b_flux);
 Di4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i4 <-> i5 ( alpha * a , 4.0 * beta / a )*/
 f_flux =  alpha * a * i4 ;
 b_flux =  4.0 * beta / a * i5 ;
 Di4 -= (f_flux - b_flux);
 Di5 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i5 <-> i6 ( gamma , delta )*/
 f_flux =  gamma * i5 ;
 b_flux =  delta * i6 ;
 Di5 -= (f_flux - b_flux);
 Di6 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i6 <-> is2 ( aS2 , bS )*/
 f_flux =  aS2 * i6 ;
 b_flux =  bS * is2 ;
 Di6 -= (f_flux - b_flux);
 Dis2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c1 <-> i1 ( Con , Coff )*/
 f_flux =  Con * c1 ;
 b_flux =  Coff * i1 ;
 Dc1 -= (f_flux - b_flux);
 Di1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c2 <-> i2 ( Con * a , Coff / a )*/
 f_flux =  Con * a * c2 ;
 b_flux =  Coff / a * i2 ;
 Dc2 -= (f_flux - b_flux);
 Di2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c3 <-> i3 ( Con * pow( a , 2.0 ) , Coff / pow( a , 2.0 ) )*/
 f_flux =  Con * pow( a , 2.0 ) * c3 ;
 b_flux =  Coff / pow( a , 2.0 ) * i3 ;
 Dc3 -= (f_flux - b_flux);
 Di3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c4 <-> i4 ( Con * pow( a , 3.0 ) , Coff / pow( a , 3.0 ) )*/
 f_flux =  Con * pow( a , 3.0 ) * c4 ;
 b_flux =  Coff / pow( a , 3.0 ) * i4 ;
 Dc4 -= (f_flux - b_flux);
 Di4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c5 <-> i5 ( Con * pow( a , 4.0 ) , Coff / pow( a , 4.0 ) )*/
 f_flux =  Con * pow( a , 4.0 ) * c5 ;
 b_flux =  Coff / pow( a , 4.0 ) * i5 ;
 Dc5 -= (f_flux - b_flux);
 Di5 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ o <-> i6 ( Oon , Ooff )*/
 f_flux =  Oon * o ;
 b_flux =  Ooff * i6 ;
 Do -= (f_flux - b_flux);
 Di6 += (f_flux - b_flux);
 
 /*REACTION*/
   /* c1 + c2 + c3 + c4 + c5 + i1 + i2 + i3 + i4 + i5 + i6 + is1 + is2 + o = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<14;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargscomma_ v ) ;
 /* ~ c1 <-> c2 ( 4.0 * alpha , beta )*/
 _term =  4.0 * alpha ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  beta ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ c2 <-> c3 ( 3.0 * alpha , 2.0 * beta )*/
 _term =  3.0 * alpha ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  2.0 * beta ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ c3 <-> c4 ( 2.0 * alpha , 3.0 * beta )*/
 _term =  2.0 * alpha ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  3.0 * beta ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ c4 <-> c5 ( alpha , 4.0 * beta )*/
 _term =  alpha ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  4.0 * beta ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ c5 <-> o ( gamma , delta )*/
 _term =  gamma ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  delta ;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ o <-> is1 ( aS1 , bS )*/
 _term =  aS1 ;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 7 ,0)  -= _term;
 _term =  bS ;
 _MATELM1( 0 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ i1 <-> i2 ( 4.0 * alpha * a , beta / a )*/
 _term =  4.0 * alpha * a ;
 _MATELM1( 13 ,13)  += _term;
 _MATELM1( 12 ,13)  -= _term;
 _term =  beta / a ;
 _MATELM1( 13 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ i2 <-> i3 ( 3.0 * alpha * a , 2.0 * beta / a )*/
 _term =  3.0 * alpha * a ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  2.0 * beta / a ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ i3 <-> i4 ( 2.0 * alpha * a , 3.0 * beta / a )*/
 _term =  2.0 * alpha * a ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 10 ,11)  -= _term;
 _term =  3.0 * beta / a ;
 _MATELM1( 11 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ i4 <-> i5 ( alpha * a , 4.0 * beta / a )*/
 _term =  alpha * a ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 9 ,10)  -= _term;
 _term =  4.0 * beta / a ;
 _MATELM1( 10 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ i5 <-> i6 ( gamma , delta )*/
 _term =  gamma ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  delta ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ i6 <-> is2 ( aS2 , bS )*/
 _term =  aS2 ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 6 ,8)  -= _term;
 _term =  bS ;
 _MATELM1( 8 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ c1 <-> i1 ( Con , Coff )*/
 _term =  Con ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 13 ,5)  -= _term;
 _term =  Coff ;
 _MATELM1( 5 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  /* ~ c2 <-> i2 ( Con * a , Coff / a )*/
 _term =  Con * a ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 12 ,4)  -= _term;
 _term =  Coff / a ;
 _MATELM1( 4 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ c3 <-> i3 ( Con * pow( a , 2.0 ) , Coff / pow( a , 2.0 ) )*/
 _term =  Con * pow( a , 2.0 ) ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 11 ,3)  -= _term;
 _term =  Coff / pow( a , 2.0 ) ;
 _MATELM1( 3 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ c4 <-> i4 ( Con * pow( a , 3.0 ) , Coff / pow( a , 3.0 ) )*/
 _term =  Con * pow( a , 3.0 ) ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 10 ,2)  -= _term;
 _term =  Coff / pow( a , 3.0 ) ;
 _MATELM1( 2 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ c5 <-> i5 ( Con * pow( a , 4.0 ) , Coff / pow( a , 4.0 ) )*/
 _term =  Con * pow( a , 4.0 ) ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 9 ,1)  -= _term;
 _term =  Coff / pow( a , 4.0 ) ;
 _MATELM1( 1 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ o <-> i6 ( Oon , Ooff )*/
 _term =  Oon ;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 8 ,0)  -= _term;
 _term =  Ooff ;
 _MATELM1( 0 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
   /* c1 + c2 + c3 + c4 + c5 + i1 + i2 + i3 + i4 + i5 + i6 + is1 + is2 + o = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 14;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
     _ode_spec1 ();
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 14; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse(&_cvsparseobj1, 14, _dlist1, _p, _ode_matsol1, &_coef1);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  ct = ct0;
  c5 = c50;
  c4 = c40;
  c3 = c30;
  c2 = c20;
  c1 = c10;
  it = it0;
  ist = ist0;
  is2 = is20;
  is1 = is10;
  ift = ift0;
  i6 = i60;
  i5 = i50;
  i4 = i40;
  i3 = i30;
  i2 = i20;
  i1 = i10;
  o = o0;
 {
   error = _ss_sparse(&_sparseobj1, 14, _slist1, _dlist1, _p, &t, dt, kin,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 132 in file na2_ch_ptr.mod:\n	SOLVE kin STEADYSTATE sparse\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 14; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ena = _ion_ena;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   g = gbar * o * modulationDA ( _threadargs_ ) ;
   ina = g * ( v - ena ) ;
   ct = c1 + c2 + c3 + c4 + c5 ;
   ift = i1 + i2 + i3 + i4 + i5 + i6 ;
   ist = is1 + is2 ;
   it = ift + ist ;
   }
 _current += ina;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ena = _ion_ena;
 _g = _nrn_current(_v + .001);
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ena = _ion_ena;
 { error = sparse(&_sparseobj1, 14, _slist1, _dlist1, _p, &t, dt, kin,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 122 in file na2_ch_ptr.mod:\n	SOLVE kin METHOD sparse\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 14; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(o) - _p;  _dlist1[0] = &(Do) - _p;
 _slist1[1] = &(c5) - _p;  _dlist1[1] = &(Dc5) - _p;
 _slist1[2] = &(c4) - _p;  _dlist1[2] = &(Dc4) - _p;
 _slist1[3] = &(c3) - _p;  _dlist1[3] = &(Dc3) - _p;
 _slist1[4] = &(c2) - _p;  _dlist1[4] = &(Dc2) - _p;
 _slist1[5] = &(c1) - _p;  _dlist1[5] = &(Dc1) - _p;
 _slist1[6] = &(is2) - _p;  _dlist1[6] = &(Dis2) - _p;
 _slist1[7] = &(is1) - _p;  _dlist1[7] = &(Dis1) - _p;
 _slist1[8] = &(i6) - _p;  _dlist1[8] = &(Di6) - _p;
 _slist1[9] = &(i5) - _p;  _dlist1[9] = &(Di5) - _p;
 _slist1[10] = &(i4) - _p;  _dlist1[10] = &(Di4) - _p;
 _slist1[11] = &(i3) - _p;  _dlist1[11] = &(Di3) - _p;
 _slist1[12] = &(i2) - _p;  _dlist1[12] = &(Di2) - _p;
 _slist1[13] = &(i1) - _p;  _dlist1[13] = &(Di1) - _p;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/home/jofrony/Documents/Repositories/BasalGangliaData/mod-ptr-files/na2_ch_ptr.mod";
static const char* nmodl_file_text = 
  "COMMENT\n"
  "NA2_CH.MOD\n"
  "\n"
  "c1 - c2 - c3 - c4 - c5 - o  - is1\n"
  "|    |    |    |    |    |\n"
  "i1 - i2 - i3 - i4 - i5 - i6 - is2\n"
  "\n"
  "FAST\n"
  "\n"
  "6/18/2003\n"
  "\n"
  "\n"
  "Neuromodulation is added as functions:\n"
  "    \n"
  "    modulationDA = 1 + modDA*(maxModDA-1)*levelDA\n"
  "\n"
  "where:\n"
  "    \n"
  "    modDA  [0]: is a switch for turning modulation on or off {1/0}\n"
  "    maxModDA [1]: is the maximum modulation for this specific channel (read from the param file)\n"
  "                    e.g. 10% increase would correspond to a factor of 1.1 (100% +10%) {0-inf}\n"
  "    levelDA  [0]: is an additional parameter for scaling modulation. \n"
  "                Can be used simulate non static modulation by gradually changing the value from 0 to 1 {0-1}\n"
  "									\n"
  "	  Further neuromodulators can be added by for example:\n"
  "          modulationDA = 1 + modDA*(maxModDA-1)\n"
  "	  modulationACh = 1 + modACh*(maxModACh-1)\n"
  "	  ....\n"
  "\n"
  "	  etc. for other neuromodulators\n"
  "	  \n"
  "	   \n"
  "								     \n"
  "[] == default values\n"
  "{} == ranges\n"
  "    \n"
  "ENDCOMMENT\n"
  "\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX na2_ch_ptr\n"
  "	USEION na READ ena WRITE ina\n"
  "	RANGE g, ina, gbar, a\n"
  "	GLOBAL Con, Coff, Oon, Ooff\n"
  "	GLOBAL a0, vha, vca\n"
  "	GLOBAL b0, vhb, vcb\n"
  "	GLOBAL g0\n"
  "	GLOBAL d0\n"
  "	GLOBAL aS1, aS2, bS\n"
  "    POINTER levelDA\n"
  "    RANGE modDA,maxModDA\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(mV) = (millivolt)\n"
  "	(mA) = (milliamp)\n"
  "	(S) = (siemens)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	gbar = 1	(S/cm2)\n"
  "\n"
  "	a0 = 37		(1/ms)	: alpha\n"
  "	vha  = 45	(mV)\n"
  "	vca = 40	(mV)\n"
  "\n"
  "	b0 = 10		(1/ms)	: beta\n"
  "	vhb = -50	(mV)\n"
  "	vcb = -10	(mV)\n"
  "\n"
  "	g0 = 40		(1/ms)	: gamma\n"
  "\n"
  "	d0 = 30		(1/ms)	: delta\n"
  "\n"
  "	aS1 = 0.0025	(1/ms)\n"
  "	aS2 = 0.0002	(1/ms)\n"
  "	bS = 0.00017	(1/ms)\n"
  "\n"
  "	Con = 0.001	(1/ms)\n"
  "	Coff = 0.1	(1/ms)\n"
  "	Oon = 1.6	(1/ms)\n"
  "	Ooff = 0.01	(1/ms)\n"
  "        modDA = 0\n"
  "        maxModDA = 1\n"
  "        levelDA = 0\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	v	(mV)\n"
  "	ena	(mV)\n"
  "	g	(S/cm2)\n"
  "	ina	(mA/cm2)\n"
  "	alpha	(1/ms)\n"
  "	beta	(1/ms)\n"
  "	gamma	(1/ms)\n"
  "	delta	(1/ms)\n"
  "	a\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	c1  : closed\n"
  "	c2\n"
  "	c3\n"
  "	c4\n"
  "	c5\n"
  "	ct  : total closed\n"
  "	o   : open\n"
  "	i1  : fast inactivated\n"
  "	i2\n"
  "	i3\n"
  "	i4\n"
  "	i5\n"
  "	i6   \n"
  "	ift : total fast inactivated\n"
  "	is1 : slow inactivated\n"
  "	is2\n"
  "	ist : total slow inactivated\n"
  "	it  : total inactivated\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE kin METHOD sparse\n"
  "	g = gbar*o*modulationDA()\n"
  "	ina = g*(v-ena)\n"
  "	ct = c1 + c2 + c3 + c4 + c5\n"
  "	ift = i1 + i2 + i3 + i4 + i5 + i6\n"
  "	ist = is1 + is2\n"
  "	it = ift + ist\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	SOLVE kin STEADYSTATE sparse\n"
  "}\n"
  "\n"
  "KINETIC kin{\n"
  "	rates(v)\n"
  "\n"
  "	~ c1 <-> c2 (4*alpha, beta)\n"
  "	~ c2 <-> c3 (3*alpha, 2*beta)\n"
  "	~ c3 <-> c4 (2*alpha, 3*beta)\n"
  "	~ c4 <-> c5 (alpha, 4*beta)\n"
  "	~ c5 <-> o  (gamma, delta)\n"
  "	~ o <-> is1 (aS1, bS)\n"
  "\n"
  "	~ i1 <-> i2 (4*alpha*a, beta/a)\n"
  "	~ i2 <-> i3 (3*alpha*a, 2*beta/a)\n"
  "	~ i3 <-> i4 (2*alpha*a, 3*beta/a)\n"
  "	~ i4 <-> i5 (alpha*a, 4*beta/a)\n"
  "	~ i5 <-> i6 (gamma, delta)\n"
  "	~ i6 <-> is2 (aS2, bS)\n"
  "\n"
  "	~ c1 <-> i1 (Con, Coff)\n"
  "	~ c2 <-> i2 (Con*a, Coff/a)\n"
  "	~ c3 <-> i3 (Con*a^2, Coff/a^2)\n"
  "	~ c4 <-> i4 (Con*a^3, Coff/a^3)\n"
  "	~ c5 <-> i5 (Con*a^4, Coff/a^4)\n"
  "	~ o <-> i6  (Oon, Ooff)\n"
  "\n"
  "	CONSERVE c1+c2+c3+c4+c5+i1+i2+i3+i4+i5+i6+is1+is2+o=1\n"
  "}\n"
  "\n"
  "PROCEDURE rates(v(millivolt)) {\n"
  "	alpha = a0*exp((v-vha)/vca)\n"
  "	beta = b0*exp((v-vhb)/vcb)\n"
  "	gamma = g0\n"
  "	delta = d0\n"
  "\n"
  "	a = ((Coff/Con)/(Ooff/Oon))^(1/8)\n"
  "}\n"
  "\n"
  "FUNCTION modulationDA() {\n"
  "    : returns modulation factor\n"
  "    \n"
  "    modulationDA = 1 + modDA*(maxModDA-1)*levelDA \n"
  "}\n"
  ;
#endif
