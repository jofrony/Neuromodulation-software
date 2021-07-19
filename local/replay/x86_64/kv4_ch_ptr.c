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
 
#define nrn_init _nrn_init__kv4_ch_ptr
#define _nrn_initial _nrn_initial__kv4_ch_ptr
#define nrn_cur _nrn_cur__kv4_ch_ptr
#define _nrn_current _nrn_current__kv4_ch_ptr
#define nrn_jacob _nrn_jacob__kv4_ch_ptr
#define nrn_state _nrn_state__kv4_ch_ptr
#define _net_receive _net_receive__kv4_ch_ptr 
#define kin kin__kv4_ch_ptr 
#define rates rates__kv4_ch_ptr 
 
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
#define ik _p[4]
#define c1 _p[5]
#define c2 _p[6]
#define c3 _p[7]
#define c4 _p[8]
#define o _p[9]
#define i1 _p[10]
#define i2 _p[11]
#define i3 _p[12]
#define i4 _p[13]
#define i5 _p[14]
#define is _p[15]
#define ek _p[16]
#define Dc1 _p[17]
#define Dc2 _p[18]
#define Dc3 _p[19]
#define Dc4 _p[20]
#define Do _p[21]
#define Di1 _p[22]
#define Di2 _p[23]
#define Di3 _p[24]
#define Di4 _p[25]
#define Di5 _p[26]
#define Dis _p[27]
#define _g _p[28]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
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
 extern double celsius;
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
 "setdata_kv4_ch_ptr", _hoc_setdata,
 "modulationDA_kv4_ch_ptr", _hoc_modulationDA,
 "rates_kv4_ch_ptr", _hoc_rates,
 0, 0
};
#define modulationDA modulationDA_kv4_ch_ptr
 extern double modulationDA( );
 /* declare global and static user variables */
#define am am_kv4_ch_ptr
 double am = 1;
#define a a_kv4_ch_ptr
 double a = 3;
#define alpha alpha_kv4_ch_ptr
 double alpha = 0;
#define bm bm_kv4_ch_ptr
 double bm = 7;
#define b b_kv4_ch_ptr
 double b = 40;
#define beta beta_kv4_ch_ptr
 double beta = 0;
#define ci ci_kv4_ch_ptr
 double ci = 0.2;
#define delta delta_kv4_ch_ptr
 double delta = 4;
#define gamma gamma_kv4_ch_ptr
 double gamma = 200;
#define isi5 isi5_kv4_ch_ptr
 double isi5 = 0.001;
#define i5is i5is_kv4_ch_ptr
 double i5is = 0.001;
#define io io_kv4_ch_ptr
 double io = 0.01;
#define ic ic_kv4_ch_ptr
 double ic = 500;
#define oi oi_kv4_ch_ptr
 double oi = 1e-09;
#define q10v q10v_kv4_ch_ptr
 double q10v = 3;
#define q10i q10i_kv4_ch_ptr
 double q10i = 3;
#define vhb vhb_kv4_ch_ptr
 double vhb = -30;
#define vha vha_kv4_ch_ptr
 double vha = -75;
#define vc vc_kv4_ch_ptr
 double vc = 10;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gamma_kv4_ch_ptr", "1/ms",
 "delta_kv4_ch_ptr", "1/ms",
 "ic_kv4_ch_ptr", "/ms",
 "oi_kv4_ch_ptr", "/ms",
 "io_kv4_ch_ptr", "/ms",
 "ci_kv4_ch_ptr", "/ms",
 "am_kv4_ch_ptr", "1/ms",
 "bm_kv4_ch_ptr", "1/ms",
 "vc_kv4_ch_ptr", "mV",
 "vha_kv4_ch_ptr", "mV",
 "vhb_kv4_ch_ptr", "mV",
 "i5is_kv4_ch_ptr", "/ms",
 "isi5_kv4_ch_ptr", "/ms",
 "alpha_kv4_ch_ptr", "/ms",
 "beta_kv4_ch_ptr", "/ms",
 "gbar_kv4_ch_ptr", "S/cm2",
 "g_kv4_ch_ptr", "S/cm2",
 "ik_kv4_ch_ptr", "mA/cm2",
 0,0
};
 static double c40 = 0;
 static double c30 = 0;
 static double c20 = 0;
 static double c10 = 0;
 static double delta_t = 0.01;
 static double is0 = 0;
 static double i50 = 0;
 static double i40 = 0;
 static double i30 = 0;
 static double i20 = 0;
 static double i10 = 0;
 static double o0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "gamma_kv4_ch_ptr", &gamma_kv4_ch_ptr,
 "delta_kv4_ch_ptr", &delta_kv4_ch_ptr,
 "a_kv4_ch_ptr", &a_kv4_ch_ptr,
 "b_kv4_ch_ptr", &b_kv4_ch_ptr,
 "ic_kv4_ch_ptr", &ic_kv4_ch_ptr,
 "oi_kv4_ch_ptr", &oi_kv4_ch_ptr,
 "io_kv4_ch_ptr", &io_kv4_ch_ptr,
 "ci_kv4_ch_ptr", &ci_kv4_ch_ptr,
 "am_kv4_ch_ptr", &am_kv4_ch_ptr,
 "bm_kv4_ch_ptr", &bm_kv4_ch_ptr,
 "vc_kv4_ch_ptr", &vc_kv4_ch_ptr,
 "vha_kv4_ch_ptr", &vha_kv4_ch_ptr,
 "vhb_kv4_ch_ptr", &vhb_kv4_ch_ptr,
 "i5is_kv4_ch_ptr", &i5is_kv4_ch_ptr,
 "isi5_kv4_ch_ptr", &isi5_kv4_ch_ptr,
 "q10i_kv4_ch_ptr", &q10i_kv4_ch_ptr,
 "q10v_kv4_ch_ptr", &q10v_kv4_ch_ptr,
 "alpha_kv4_ch_ptr", &alpha_kv4_ch_ptr,
 "beta_kv4_ch_ptr", &beta_kv4_ch_ptr,
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
"kv4_ch_ptr",
 "gbar_kv4_ch_ptr",
 "modDA_kv4_ch_ptr",
 "maxModDA_kv4_ch_ptr",
 0,
 "g_kv4_ch_ptr",
 "ik_kv4_ch_ptr",
 0,
 "c1_kv4_ch_ptr",
 "c2_kv4_ch_ptr",
 "c3_kv4_ch_ptr",
 "c4_kv4_ch_ptr",
 "o_kv4_ch_ptr",
 "i1_kv4_ch_ptr",
 "i2_kv4_ch_ptr",
 "i3_kv4_ch_ptr",
 "i4_kv4_ch_ptr",
 "i5_kv4_ch_ptr",
 "is_kv4_ch_ptr",
 0,
 "levelDA_kv4_ch_ptr",
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 29, _prop);
 	/*initialize range parameters*/
 	gbar = 1;
 	modDA = 0;
 	maxModDA = 1;
 	_prop->param = _p;
 	_prop->param_size = 29;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
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

 void _kv4_ch_ptr_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 29, 5);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "pointer");
  hoc_register_dparam_semantics(_mechtype, 4, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 kv4_ch_ptr /home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation-software/local/x86_64/kv4_ch_ptr.mod\n");
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
 static int _slist1[11], _dlist1[11]; static double *_temp1;
 static int kin();
 
static int kin ()
 {_reset=0;
 {
   double _lq10 ;
 double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<11;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 _lq10 = pow( q10i , ( ( celsius - 22.0 ) / 10.0 ) ) ;
   rates ( _threadargscomma_ v ) ;
   /* ~ c1 <-> c2 ( 3.0 * alpha , beta )*/
 f_flux =  3.0 * alpha * c1 ;
 b_flux =  beta * c2 ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  3.0 * alpha ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  beta ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ c2 <-> c3 ( 2.0 * alpha , 2.0 * beta )*/
 f_flux =  2.0 * alpha * c2 ;
 b_flux =  2.0 * beta * c3 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  2.0 * alpha ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  2.0 * beta ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ c3 <-> c4 ( alpha , 3.0 * beta )*/
 f_flux =  alpha * c3 ;
 b_flux =  3.0 * beta * c4 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  alpha ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  3.0 * beta ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ c4 <-> o ( _lq10 * gamma , _lq10 * delta )*/
 f_flux =  _lq10 * gamma * c4 ;
 b_flux =  _lq10 * delta * o ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  _lq10 * gamma ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 10 ,1)  -= _term;
 _term =  _lq10 * delta ;
 _MATELM1( 1 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ i1 <-> i2 ( 3.0 * alpha * a , beta / b )*/
 f_flux =  3.0 * alpha * a * i1 ;
 b_flux =  beta / b * i2 ;
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 8) += (f_flux - b_flux);
 
 _term =  3.0 * alpha * a ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  beta / b ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ i2 <-> i3 ( 2.0 * alpha * a , 2.0 * beta / b )*/
 f_flux =  2.0 * alpha * a * i2 ;
 b_flux =  2.0 * beta / b * i3 ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  2.0 * alpha * a ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  2.0 * beta / b ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ i3 <-> i4 ( alpha * a , 3.0 * beta / b )*/
 f_flux =  alpha * a * i3 ;
 b_flux =  3.0 * beta / b * i4 ;
 _RHS1( 7) -= (f_flux - b_flux);
 _RHS1( 6) += (f_flux - b_flux);
 
 _term =  alpha * a ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 6 ,7)  -= _term;
 _term =  3.0 * beta / b ;
 _MATELM1( 7 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ i4 <-> i5 ( _lq10 * gamma , _lq10 * delta )*/
 f_flux =  _lq10 * gamma * i4 ;
 b_flux =  _lq10 * delta * i5 ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  _lq10 * gamma ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  _lq10 * delta ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ i5 <-> is ( _lq10 * i5is , _lq10 * isi5 )*/
 f_flux =  _lq10 * i5is * i5 ;
 b_flux =  _lq10 * isi5 * is ;
 _RHS1( 5) -= (f_flux - b_flux);
 
 _term =  _lq10 * i5is ;
 _MATELM1( 5 ,5)  += _term;
 _term =  _lq10 * isi5 ;
 _MATELM1( 5 ,0)  -= _term;
 /*REACTION*/
  /* ~ i1 <-> c1 ( _lq10 * ic , _lq10 * ci )*/
 f_flux =  _lq10 * ic * i1 ;
 b_flux =  _lq10 * ci * c1 ;
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  _lq10 * ic ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 4 ,9)  -= _term;
 _term =  _lq10 * ci ;
 _MATELM1( 9 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ i2 <-> c2 ( _lq10 * ic / b , _lq10 * ci * a )*/
 f_flux =  _lq10 * ic / b * i2 ;
 b_flux =  _lq10 * ci * a * c2 ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  _lq10 * ic / b ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 3 ,8)  -= _term;
 _term =  _lq10 * ci * a ;
 _MATELM1( 8 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ i3 <-> c3 ( _lq10 * ic / pow( b , 2.0 ) , _lq10 * ci * pow( a , 2.0 ) )*/
 f_flux =  _lq10 * ic / pow( b , 2.0 ) * i3 ;
 b_flux =  _lq10 * ci * pow( a , 2.0 ) * c3 ;
 _RHS1( 7) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  _lq10 * ic / pow( b , 2.0 ) ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 2 ,7)  -= _term;
 _term =  _lq10 * ci * pow( a , 2.0 ) ;
 _MATELM1( 7 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ i4 <-> c4 ( _lq10 * ic / pow( b , 3.0 ) , _lq10 * ci * pow( a , 3.0 ) )*/
 f_flux =  _lq10 * ic / pow( b , 3.0 ) * i4 ;
 b_flux =  _lq10 * ci * pow( a , 3.0 ) * c4 ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  _lq10 * ic / pow( b , 3.0 ) ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 1 ,6)  -= _term;
 _term =  _lq10 * ci * pow( a , 3.0 ) ;
 _MATELM1( 6 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ i5 <-> o ( _lq10 * io , _lq10 * oi )*/
 f_flux =  _lq10 * io * i5 ;
 b_flux =  _lq10 * oi * o ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  _lq10 * io ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 10 ,5)  -= _term;
 _term =  _lq10 * oi ;
 _MATELM1( 5 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
   /* c1 + c2 + c3 + c4 + i1 + i2 + i3 + i4 + i5 + o + is = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= is ;
 _MATELM1(0, 10) = 1;
 _RHS1(0) -= o ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= i5 ;
 _MATELM1(0, 6) = 1;
 _RHS1(0) -= i4 ;
 _MATELM1(0, 7) = 1;
 _RHS1(0) -= i3 ;
 _MATELM1(0, 8) = 1;
 _RHS1(0) -= i2 ;
 _MATELM1(0, 9) = 1;
 _RHS1(0) -= i1 ;
 _MATELM1(0, 1) = 1;
 _RHS1(0) -= c4 ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= c3 ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= c2 ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= c1 ;
 /*CONSERVATION*/
   } return _reset;
 }
 
static int  rates (  double _lv ) {
   double _lq10 ;
 _lq10 = pow( q10v , ( ( celsius - 22.0 ) / 10.0 ) ) ;
   alpha = _lq10 * am * exp ( ( _lv - vha ) / vc ) ;
   beta = _lq10 * bm * exp ( ( _lv - vhb ) / - vc ) ;
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
 double _lq10 ;
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<11;_i++) _p[_dlist1[_i]] = 0.0;}
 _lq10 = pow( q10i , ( ( celsius - 22.0 ) / 10.0 ) ) ;
 rates ( _threadargscomma_ v ) ;
 /* ~ c1 <-> c2 ( 3.0 * alpha , beta )*/
 f_flux =  3.0 * alpha * c1 ;
 b_flux =  beta * c2 ;
 Dc1 -= (f_flux - b_flux);
 Dc2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c2 <-> c3 ( 2.0 * alpha , 2.0 * beta )*/
 f_flux =  2.0 * alpha * c2 ;
 b_flux =  2.0 * beta * c3 ;
 Dc2 -= (f_flux - b_flux);
 Dc3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c3 <-> c4 ( alpha , 3.0 * beta )*/
 f_flux =  alpha * c3 ;
 b_flux =  3.0 * beta * c4 ;
 Dc3 -= (f_flux - b_flux);
 Dc4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c4 <-> o ( _lq10 * gamma , _lq10 * delta )*/
 f_flux =  _lq10 * gamma * c4 ;
 b_flux =  _lq10 * delta * o ;
 Dc4 -= (f_flux - b_flux);
 Do += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i1 <-> i2 ( 3.0 * alpha * a , beta / b )*/
 f_flux =  3.0 * alpha * a * i1 ;
 b_flux =  beta / b * i2 ;
 Di1 -= (f_flux - b_flux);
 Di2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i2 <-> i3 ( 2.0 * alpha * a , 2.0 * beta / b )*/
 f_flux =  2.0 * alpha * a * i2 ;
 b_flux =  2.0 * beta / b * i3 ;
 Di2 -= (f_flux - b_flux);
 Di3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i3 <-> i4 ( alpha * a , 3.0 * beta / b )*/
 f_flux =  alpha * a * i3 ;
 b_flux =  3.0 * beta / b * i4 ;
 Di3 -= (f_flux - b_flux);
 Di4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i4 <-> i5 ( _lq10 * gamma , _lq10 * delta )*/
 f_flux =  _lq10 * gamma * i4 ;
 b_flux =  _lq10 * delta * i5 ;
 Di4 -= (f_flux - b_flux);
 Di5 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i5 <-> is ( _lq10 * i5is , _lq10 * isi5 )*/
 f_flux =  _lq10 * i5is * i5 ;
 b_flux =  _lq10 * isi5 * is ;
 Di5 -= (f_flux - b_flux);
 Dis += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i1 <-> c1 ( _lq10 * ic , _lq10 * ci )*/
 f_flux =  _lq10 * ic * i1 ;
 b_flux =  _lq10 * ci * c1 ;
 Di1 -= (f_flux - b_flux);
 Dc1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i2 <-> c2 ( _lq10 * ic / b , _lq10 * ci * a )*/
 f_flux =  _lq10 * ic / b * i2 ;
 b_flux =  _lq10 * ci * a * c2 ;
 Di2 -= (f_flux - b_flux);
 Dc2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i3 <-> c3 ( _lq10 * ic / pow( b , 2.0 ) , _lq10 * ci * pow( a , 2.0 ) )*/
 f_flux =  _lq10 * ic / pow( b , 2.0 ) * i3 ;
 b_flux =  _lq10 * ci * pow( a , 2.0 ) * c3 ;
 Di3 -= (f_flux - b_flux);
 Dc3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i4 <-> c4 ( _lq10 * ic / pow( b , 3.0 ) , _lq10 * ci * pow( a , 3.0 ) )*/
 f_flux =  _lq10 * ic / pow( b , 3.0 ) * i4 ;
 b_flux =  _lq10 * ci * pow( a , 3.0 ) * c4 ;
 Di4 -= (f_flux - b_flux);
 Dc4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i5 <-> o ( _lq10 * io , _lq10 * oi )*/
 f_flux =  _lq10 * io * i5 ;
 b_flux =  _lq10 * oi * o ;
 Di5 -= (f_flux - b_flux);
 Do += (f_flux - b_flux);
 
 /*REACTION*/
   /* c1 + c2 + c3 + c4 + i1 + i2 + i3 + i4 + i5 + o + is = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1() {_reset=0;{
 double _lq10 ;
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<11;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 _lq10 = pow( q10i , ( ( celsius - 22.0 ) / 10.0 ) ) ;
 rates ( _threadargscomma_ v ) ;
 /* ~ c1 <-> c2 ( 3.0 * alpha , beta )*/
 _term =  3.0 * alpha ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  beta ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ c2 <-> c3 ( 2.0 * alpha , 2.0 * beta )*/
 _term =  2.0 * alpha ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  2.0 * beta ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ c3 <-> c4 ( alpha , 3.0 * beta )*/
 _term =  alpha ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  3.0 * beta ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ c4 <-> o ( _lq10 * gamma , _lq10 * delta )*/
 _term =  _lq10 * gamma ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 10 ,1)  -= _term;
 _term =  _lq10 * delta ;
 _MATELM1( 1 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ i1 <-> i2 ( 3.0 * alpha * a , beta / b )*/
 _term =  3.0 * alpha * a ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  beta / b ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ i2 <-> i3 ( 2.0 * alpha * a , 2.0 * beta / b )*/
 _term =  2.0 * alpha * a ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  2.0 * beta / b ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ i3 <-> i4 ( alpha * a , 3.0 * beta / b )*/
 _term =  alpha * a ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 6 ,7)  -= _term;
 _term =  3.0 * beta / b ;
 _MATELM1( 7 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ i4 <-> i5 ( _lq10 * gamma , _lq10 * delta )*/
 _term =  _lq10 * gamma ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  _lq10 * delta ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ i5 <-> is ( _lq10 * i5is , _lq10 * isi5 )*/
 _term =  _lq10 * i5is ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 0 ,5)  -= _term;
 _term =  _lq10 * isi5 ;
 _MATELM1( 5 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ i1 <-> c1 ( _lq10 * ic , _lq10 * ci )*/
 _term =  _lq10 * ic ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 4 ,9)  -= _term;
 _term =  _lq10 * ci ;
 _MATELM1( 9 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ i2 <-> c2 ( _lq10 * ic / b , _lq10 * ci * a )*/
 _term =  _lq10 * ic / b ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 3 ,8)  -= _term;
 _term =  _lq10 * ci * a ;
 _MATELM1( 8 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ i3 <-> c3 ( _lq10 * ic / pow( b , 2.0 ) , _lq10 * ci * pow( a , 2.0 ) )*/
 _term =  _lq10 * ic / pow( b , 2.0 ) ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 2 ,7)  -= _term;
 _term =  _lq10 * ci * pow( a , 2.0 ) ;
 _MATELM1( 7 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ i4 <-> c4 ( _lq10 * ic / pow( b , 3.0 ) , _lq10 * ci * pow( a , 3.0 ) )*/
 _term =  _lq10 * ic / pow( b , 3.0 ) ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 1 ,6)  -= _term;
 _term =  _lq10 * ci * pow( a , 3.0 ) ;
 _MATELM1( 6 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ i5 <-> o ( _lq10 * io , _lq10 * oi )*/
 _term =  _lq10 * io ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 10 ,5)  -= _term;
 _term =  _lq10 * oi ;
 _MATELM1( 5 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
   /* c1 + c2 + c3 + c4 + i1 + i2 + i3 + i4 + i5 + o + is = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 11;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
     _ode_spec1 ();
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 11; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse(&_cvsparseobj1, 11, _dlist1, _p, _ode_matsol1, &_coef1);
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
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  c4 = c40;
  c3 = c30;
  c2 = c20;
  c1 = c10;
  is = is0;
  i5 = i50;
  i4 = i40;
  i3 = i30;
  i2 = i20;
  i1 = i10;
  o = o0;
 {
   error = _ss_sparse(&_sparseobj1, 11, _slist1, _dlist1, _p, &t, dt, kin,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 108 in file kv4_ch_ptr.mod:\n	SOLVE kin STEADYSTATE sparse\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 11; ++_i) {
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
  ek = _ion_ek;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   g = gbar * o * modulationDA ( _threadargs_ ) ;
   ik = g * ( v - ek ) ;
   }
 _current += ik;

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
  ek = _ion_ek;
 _g = _nrn_current(_v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
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
  ek = _ion_ek;
 { error = sparse(&_sparseobj1, 11, _slist1, _dlist1, _p, &t, dt, kin,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 102 in file kv4_ch_ptr.mod:\n	SOLVE kin METHOD sparse\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 11; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(is) - _p;  _dlist1[0] = &(Dis) - _p;
 _slist1[1] = &(c4) - _p;  _dlist1[1] = &(Dc4) - _p;
 _slist1[2] = &(c3) - _p;  _dlist1[2] = &(Dc3) - _p;
 _slist1[3] = &(c2) - _p;  _dlist1[3] = &(Dc2) - _p;
 _slist1[4] = &(c1) - _p;  _dlist1[4] = &(Dc1) - _p;
 _slist1[5] = &(i5) - _p;  _dlist1[5] = &(Di5) - _p;
 _slist1[6] = &(i4) - _p;  _dlist1[6] = &(Di4) - _p;
 _slist1[7] = &(i3) - _p;  _dlist1[7] = &(Di3) - _p;
 _slist1[8] = &(i2) - _p;  _dlist1[8] = &(Di2) - _p;
 _slist1[9] = &(i1) - _p;  _dlist1[9] = &(Di1) - _p;
 _slist1[10] = &(o) - _p;  _dlist1[10] = &(Do) - _p;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation-software/local/mechanisms-modulation-ptr/kv4_ch_ptr.mod";
static const char* nmodl_file_text = 
  "COMMENT\n"
  "\n"
  "c1 - c2 - c3 - c4 - o\n"
  "|    |    |    |    |\n"
  "i1 - i2 - i3 - i4 - i5 - is\n"
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
  "	SUFFIX kv4_ch_ptr\n"
  "	USEION k READ ek WRITE ik\n"
  "	RANGE g, ik, gbar\n"
  "	GLOBAL alpha, beta\n"
  "	GLOBAL ci, ic, oi, io, a, b, am, bm, vc, gamma, delta, vha, vhb\n"
  "	GLOBAL i5is, isi5\n"
  "	GLOBAL q10i, q10v\n"
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
  "	gamma = 200	(1/ms)\n"
  "	delta = 4	(1/ms)\n"
  "	a = 3\n"
  "	b = 40\n"
  "	ic = 500	(/ms)\n"
  "	oi = 1e-9	(/ms)\n"
  "	io = .01	(/ms)\n"
  "	ci = .2		(/ms)\n"
  "	am = 1		(1/ms)\n"
  "	bm = 7		(1/ms)\n"
  "	vc = 10		(mV)\n"
  "	vha = -75	(mV)\n"
  "	vhb = -30	(mV)\n"
  "	i5is = .001	(/ms)\n"
  "	isi5 = .001	(/ms)\n"
  "	q10i = 3\n"
  "	q10v = 3\n"
  "	celsius		(degC)\n"
  "        modDA = 0\n"
  "        maxModDA = 1\n"
  "        levelDA = 0\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	v	(mV)\n"
  "	ek	(mV)\n"
  "	g	(S/cm2)\n"
  "	ik	(mA/cm2)\n"
  "	alpha	(/ms)\n"
  "	beta	(/ms)\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	c1\n"
  "	c2\n"
  "	c3\n"
  "	c4\n"
  "	o\n"
  "	i1\n"
  "	i2\n"
  "	i3\n"
  "	i4\n"
  "	i5\n"
  "	is\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE kin METHOD sparse\n"
  "	g = gbar*o*modulationDA()\n"
  "	ik = g*(v-ek)\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	SOLVE kin STEADYSTATE sparse\n"
  "}\n"
  "\n"
  "KINETIC kin{LOCAL q10\n"
  "	q10 = q10i^((celsius - 22 (degC))/10 (degC))\n"
  "	rates(v)\n"
  "	~ c1 <-> c2 (3*alpha,beta)\n"
  "	~ c2 <-> c3 (2*alpha,2*beta)\n"
  "	~ c3 <-> c4 (alpha,3*beta)\n"
  "	~ c4 <-> o  (q10*gamma,q10*delta)\n"
  "\n"
  "	~ i1 <-> i2 (3*alpha*a,beta/b)\n"
  "	~ i2 <-> i3 (2*alpha*a,2*beta/b)\n"
  "	~ i3 <-> i4 (alpha*a,3*beta/b)\n"
  "	~ i4 <-> i5 (q10*gamma,q10*delta)\n"
  "	~ i5 <-> is (q10*i5is,q10*isi5)\n"
  "\n"
  "	~ i1 <-> c1 (q10*ic,q10*ci)\n"
  "	~ i2 <-> c2 (q10*ic/b,q10*ci*a)\n"
  "	~ i3 <-> c3 (q10*ic/b^2,q10*ci*a^2)\n"
  "	~ i4 <-> c4 (q10*ic/b^3,q10*ci*a^3)\n"
  "	~ i5 <-> o  (q10*io,q10*oi)\n"
  "\n"
  "	CONSERVE c1+c2+c3+c4+i1+i2+i3+i4+i5+o+is=1\n"
  "}\n"
  "\n"
  "PROCEDURE rates(v(millivolt)) {LOCAL q10\n"
  "	q10 = q10v^((celsius - 22 (degC))/10 (degC))\n"
  "	alpha = q10*am*exp((v-vha)/vc)\n"
  "	beta = q10*bm*exp((v-vhb)/-vc)\n"
  "}\n"
  "\n"
  "FUNCTION modulationDA() {\n"
  "    : returns modulation factor\n"
  "    \n"
  "    modulationDA = 1 + modDA*(maxModDA-1)*levelDA \n"
  "}\n"
  ;
#endif
