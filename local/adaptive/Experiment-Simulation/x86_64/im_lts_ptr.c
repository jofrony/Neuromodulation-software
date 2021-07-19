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
 
#define nrn_init _nrn_init__im_lts_ptr
#define _nrn_initial _nrn_initial__im_lts_ptr
#define nrn_cur _nrn_cur__im_lts_ptr
#define _nrn_current _nrn_current__im_lts_ptr
#define nrn_jacob _nrn_jacob__im_lts_ptr
#define nrn_state _nrn_state__im_lts_ptr
#define _net_receive _net_receive__im_lts_ptr 
#define evaluate_fct evaluate_fct__im_lts_ptr 
#define states states__im_lts_ptr 
 
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
#define gkbar _p[0]
#define modDA _p[1]
#define maxModDA _p[2]
#define modACh _p[3]
#define maxModACh _p[4]
#define ik _p[5]
#define m_inf _p[6]
#define tau_m _p[7]
#define m _p[8]
#define ek _p[9]
#define Dm _p[10]
#define tau_peak _p[11]
#define tadj _p[12]
#define _g _p[13]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
#define levelDA	*_ppvar[3]._pval
#define _p_levelDA	_ppvar[3]._pval
#define levelACh	*_ppvar[4]._pval
#define _p_levelACh	_ppvar[4]._pval
 
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
 static void _hoc_exptable(void);
 static void _hoc_evaluate_fct(void);
 static void _hoc_modulationACh(void);
 static void _hoc_modulationDA(void);
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
 "setdata_im_lts_ptr", _hoc_setdata,
 "exptable_im_lts_ptr", _hoc_exptable,
 "evaluate_fct_im_lts_ptr", _hoc_evaluate_fct,
 "modulationACh_im_lts_ptr", _hoc_modulationACh,
 "modulationDA_im_lts_ptr", _hoc_modulationDA,
 0, 0
};
#define _f_exptable _f_exptable_im_lts_ptr
#define exptable exptable_im_lts_ptr
#define modulationACh modulationACh_im_lts_ptr
#define modulationDA modulationDA_im_lts_ptr
 extern double _f_exptable( double );
 extern double exptable( double );
 extern double modulationACh( );
 extern double modulationDA( );
 /* declare global and static user variables */
#define taumax taumax_im_lts_ptr
 double taumax = 1000;
#define usetable usetable_im_lts_ptr
 double usetable = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "usetable_im_lts_ptr", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "taumax_im_lts_ptr", "ms",
 "gkbar_im_lts_ptr", "mho/cm2",
 "ik_im_lts_ptr", "mA/cm2",
 "tau_m_im_lts_ptr", "ms",
 0,0
};
 static double delta_t = 1;
 static double m0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "taumax_im_lts_ptr", &taumax_im_lts_ptr,
 "usetable_im_lts_ptr", &usetable_im_lts_ptr,
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
 
#define _cvode_ieq _ppvar[5]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"im_lts_ptr",
 "gkbar_im_lts_ptr",
 "modDA_im_lts_ptr",
 "maxModDA_im_lts_ptr",
 "modACh_im_lts_ptr",
 "maxModACh_im_lts_ptr",
 0,
 "ik_im_lts_ptr",
 "m_inf_im_lts_ptr",
 "tau_m_im_lts_ptr",
 0,
 "m_im_lts_ptr",
 0,
 "levelDA_im_lts_ptr",
 "levelACh_im_lts_ptr",
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 14, _prop);
 	/*initialize range parameters*/
 	gkbar = 1e-06;
 	modDA = 0;
 	maxModDA = 1;
 	modACh = 0;
 	maxModACh = 1;
 	_prop->param = _p;
 	_prop->param_size = 14;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
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

 void _im_lts_ptr_reg() {
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
  hoc_register_prop_size(_mechtype, 14, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "pointer");
  hoc_register_dparam_semantics(_mechtype, 4, "pointer");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 im_lts_ptr /home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation/striatal_network/synapse-wide/Experiment-Simulation/x86_64/im_lts_ptr.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double *_t_exptable;
static int _reset;
static char *modelname = "Cortical M current";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int evaluate_fct(double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static double _n_exptable(double);
 static int _slist1[1], _dlist1[1];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   evaluate_fct ( _threadargscomma_ v ) ;
   Dm = ( m_inf - m ) / tau_m ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 evaluate_fct ( _threadargscomma_ v ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_m )) ;
  return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
   evaluate_fct ( _threadargscomma_ v ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_m)))*(- ( ( ( m_inf ) ) / tau_m ) / ( ( ( ( - 1.0 ) ) ) / tau_m ) - m) ;
   }
  return 0;
}
 
static int  evaluate_fct (  double _lv ) {
   m_inf = 1.0 / ( 1.0 + exptable ( _threadargscomma_ - ( _lv + 35.0 ) / 10.0 ) ) ;
   tau_m = tau_peak / ( 3.3 * exptable ( _threadargscomma_ ( _lv + 35.0 ) / 20.0 ) + exptable ( _threadargscomma_ - ( _lv + 35.0 ) / 20.0 ) ) ;
    return 0; }
 
static void _hoc_evaluate_fct(void) {
  double _r;
   _r = 1.;
 evaluate_fct (  *getarg(1) );
 hoc_retpushx(_r);
}
 static double _mfac_exptable, _tmin_exptable;
 static void _check_exptable();
 static void _check_exptable() {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  if (!usetable) {return;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_exptable =  - 25.0 ;
   _tmax =  25.0 ;
   _dx = (_tmax - _tmin_exptable)/10000.; _mfac_exptable = 1./_dx;
   for (_i=0, _x=_tmin_exptable; _i < 10001; _x += _dx, _i++) {
    _t_exptable[_i] = _f_exptable(_x);
   }
  }
 }

 double exptable(double _lx){ _check_exptable();
 return _n_exptable(_lx);
 }

 static double _n_exptable(double _lx){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 return _f_exptable(_lx); 
}
 _xi = _mfac_exptable * (_lx - _tmin_exptable);
 if (isnan(_xi)) {
  return _xi; }
 if (_xi <= 0.) {
 return _t_exptable[0];
 }
 if (_xi >= 10000.) {
 return _t_exptable[10000];
 }
 _i = (int) _xi;
 return _t_exptable[_i] + (_xi - (double)_i)*(_t_exptable[_i+1] - _t_exptable[_i]);
 }

 
double _f_exptable (  double _lx ) {
   double _lexptable;
 if ( ( _lx > - 25.0 )  && ( _lx < 25.0 ) ) {
     _lexptable = exp ( _lx ) ;
     }
   else {
     _lexptable = 0. ;
     }
   
return _lexptable;
 }
 
static void _hoc_exptable(void) {
  double _r;
    _r =  exptable (  *getarg(1) );
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
 
double modulationACh (  ) {
   double _lmodulationACh;
 _lmodulationACh = 1.0 + modACh * ( maxModACh - 1.0 ) * levelACh ;
   
return _lmodulationACh;
 }
 
static void _hoc_modulationACh(void) {
  double _r;
   _r =  modulationACh (  );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 1;}
 
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
	for (_i=0; _i < 1; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 ();
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
  m = m0;
 {
   evaluate_fct ( _threadargscomma_ v ) ;
   m = 0.0 ;
   tadj = pow( 2.3 , ( ( celsius - 36.0 ) / 10.0 ) ) ;
   tau_peak = taumax / tadj ;
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
   ik = gkbar * m * ( v - ek ) * modulationDA ( _threadargs_ ) * modulationACh ( _threadargs_ ) ;
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
 { error =  states();
 if(error){fprintf(stderr,"at line 98 in file im_lts_ptr.mod:\n	SOLVE states METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m) - _p;  _dlist1[0] = &(Dm) - _p;
   _t_exptable = makevector(10001*sizeof(double));
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/home/jofrony/Documents/Repositories/BasalGangliaData/mod-ptr-files/im_lts_ptr.mod";
static const char* nmodl_file_text = 
  "TITLE Cortical M current\n"
  ":\n"
  ":   M-current, responsible for the adaptation of firing rate and the \n"
  ":   afterhyperpolarization (AHP) of cortical pyramidal cells\n"
  ":\n"
  ":   First-order model described by hodgkin-Hyxley like equations.\n"
  ":   K+ current, activated by depolarization, noninactivating.\n"
  ":\n"
  ":   Model taken from Yamada, W.M., Koch, C. and Adams, P.R.  Multiple \n"
  ":   channels and calcium dynamics.  In: Methods in Neuronal Modeling, \n"
  ":   edited by C. Koch and I. Segev, MIT press, 1989, p 97-134.\n"
  ":\n"
  ":   See also: McCormick, D.A., Wang, Z. and Huguenard, J. Neurotransmitter \n"
  ":   control of neocortical neuronal activity and excitability. \n"
  ":   Cerebral Cortex 3: 387-398, 1993.\n"
  ":\n"
  ":   Written by Alain Destexhe, Laval University, 1995\n"
  ":\n"
  "\n"
  "\n"
  "COMMENT\n"
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
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX im_lts_ptr\n"
  "	USEION k READ ek WRITE ik\n"
  "        RANGE gkbar, m_inf, tau_m, ik\n"
  "	GLOBAL taumax\n"
  "    POINTER levelDA\n"
  "    POINTER levelACh\n"
  "    RANGE modDA,maxModDA,modACh,maxModACh\n"
  "	\n"
  "\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "}\n"
  "\n"
  "\n"
  "PARAMETER {\n"
  "	v		(mV)\n"
  "	celsius = 36    (degC)\n"
  "	ek		(mV)\n"
  "	gkbar	= 1e-6	(mho/cm2)\n"
  "	taumax	= 1000	(ms)		: peak value of tau\n"
  "        modDA = 0\n"
  "        maxModDA = 1\n"
  "        levelDA = 0\n"
  "        modACh = 0\n"
  "        maxModACh = 1 \n"
  "        levelACh = 0\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "STATE {\n"
  "	m\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	ik	(mA/cm2)\n"
  "	m_inf\n"
  "	tau_m	(ms)\n"
  "	tau_peak	(ms)\n"
  "	tadj\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states METHOD cnexp\n"
  "	ik = gkbar * m * (v - ek)*modulationDA()*modulationACh()\n"
  "}\n"
  "\n"
  "DERIVATIVE states { \n"
  "	evaluate_fct(v)\n"
  "\n"
  "	m' = (m_inf - m) / tau_m\n"
  "}\n"
  "\n"
  "UNITSOFF\n"
  "INITIAL {\n"
  "	evaluate_fct(v)\n"
  "	m = 0\n"
  ":\n"
  ":  The Q10 value is assumed to be 2.3\n"
  ":\n"
  "        tadj = 2.3 ^ ((celsius-36)/10)\n"
  "	tau_peak = taumax / tadj\n"
  "}\n"
  "\n"
  "PROCEDURE evaluate_fct(v(mV)) {\n"
  "\n"
  "	m_inf = 1 / ( 1 + exptable(-(v+35)/10) )\n"
  "	tau_m = tau_peak / ( 3.3 * exptable((v+35)/20) + exptable(-(v+35)/20) )\n"
  "}\n"
  "UNITSON\n"
  "\n"
  "\n"
  "FUNCTION exptable(x) { \n"
  "	TABLE  FROM -25 TO 25 WITH 10000\n"
  "\n"
  "	if ((x > -25) && (x < 25)) {\n"
  "		exptable = exp(x)\n"
  "	} else {\n"
  "		exptable = 0.\n"
  "	}\n"
  "}\n"
  "\n"
  "FUNCTION modulationDA() {\n"
  "    : returns modulation factor\n"
  "    \n"
  "    modulationDA = 1 + modDA*(maxModDA-1)*levelDA \n"
  "}\n"
  "\n"
  "FUNCTION modulationACh() {\n"
  "    : returns modulation factor\n"
  "    \n"
  "    modulationACh = 1 + modACh*(maxModACh-1)*levelACh \n"
  "}\n"
  ;
#endif
