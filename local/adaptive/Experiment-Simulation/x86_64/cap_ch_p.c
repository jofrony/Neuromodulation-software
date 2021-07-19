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
 
#define nrn_init _nrn_init__cap_ch_p
#define _nrn_initial _nrn_initial__cap_ch_p
#define nrn_cur _nrn_cur__cap_ch_p
#define _nrn_current _nrn_current__cap_ch_p
#define nrn_jacob _nrn_jacob__cap_ch_p
#define nrn_state _nrn_state__cap_ch_p
#define _net_receive _net_receive__cap_ch_p 
#define rates rates__cap_ch_p 
#define states states__cap_ch_p 
 
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
#define modA _p[1]
#define maxModA _p[2]
#define modB _p[3]
#define maxModB _p[4]
#define ica _p[5]
#define g _p[6]
#define m _p[7]
#define cai _p[8]
#define cao _p[9]
#define T _p[10]
#define E _p[11]
#define Dm _p[12]
#define _g _p[13]
#define _ion_cai	*_ppvar[0]._pval
#define _ion_cao	*_ppvar[1]._pval
#define _ion_ica	*_ppvar[2]._pval
#define _ion_dicadv	*_ppvar[3]._pval
#define levelA	*_ppvar[4]._pval
#define _p_levelA	_ppvar[4]._pval
#define levelB	*_ppvar[5]._pval
#define _p_levelB	_ppvar[5]._pval
 
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
 static int hoc_nrnpointerindex =  4;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_ghk(void);
 static void _hoc_mtau_func(void);
 static void _hoc_modulationB(void);
 static void _hoc_modulationA(void);
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
 "setdata_cap_ch_p", _hoc_setdata,
 "ghk_cap_ch_p", _hoc_ghk,
 "mtau_func_cap_ch_p", _hoc_mtau_func,
 "modulationB_cap_ch_p", _hoc_modulationB,
 "modulationA_cap_ch_p", _hoc_modulationA,
 "rates_cap_ch_p", _hoc_rates,
 0, 0
};
#define ghk ghk_cap_ch_p
#define mtau_func mtau_func_cap_ch_p
#define modulationB modulationB_cap_ch_p
#define modulationA modulationA_cap_ch_p
 extern double ghk( double , double , double , double );
 extern double mtau_func( double );
 extern double modulationB( );
 extern double modulationA( );
 /* declare global and static user variables */
#define monovalPerm monovalPerm_cap_ch_p
 double monovalPerm = 0;
#define monovalConc monovalConc_cap_ch_p
 double monovalConc = 140;
#define mtau mtau_cap_ch_p
 double mtau = 0;
#define minf minf_cap_ch_p
 double minf = 0;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "monovalConc_cap_ch_p", "mM",
 "mtau_cap_ch_p", "ms",
 "gbar_cap_ch_p", "cm/s",
 "ica_cap_ch_p", "mA/cm2",
 "g_cap_ch_p", "S/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double m0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "monovalConc_cap_ch_p", &monovalConc_cap_ch_p,
 "monovalPerm_cap_ch_p", &monovalPerm_cap_ch_p,
 "minf_cap_ch_p", &minf_cap_ch_p,
 "mtau_cap_ch_p", &mtau_cap_ch_p,
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
 
#define _cvode_ieq _ppvar[6]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"cap_ch_p",
 "gbar_cap_ch_p",
 "modA_cap_ch_p",
 "maxModA_cap_ch_p",
 "modB_cap_ch_p",
 "maxModB_cap_ch_p",
 0,
 "ica_cap_ch_p",
 "g_cap_ch_p",
 0,
 "m_cap_ch_p",
 0,
 "levelA_cap_ch_p",
 "levelB_cap_ch_p",
 0};
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 14, _prop);
 	/*initialize range parameters*/
 	gbar = 5e-05;
 	modA = 0;
 	maxModA = 1;
 	modB = 0;
 	maxModB = 1;
 	_prop->param = _p;
 	_prop->param_size = 14;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 7, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[0]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[1]._pval = &prop_ion->param[2]; /* cao */
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 
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

 void _cap_ch_p_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("ca", -10000.);
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 14, 7);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "pointer");
  hoc_register_dparam_semantics(_mechtype, 5, "pointer");
  hoc_register_dparam_semantics(_mechtype, 6, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 cap_ch_p /home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation-software/local/adaptive/Experiment-Simulation/x86_64/cap_ch_p.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double F = 9.6485e4;
 static double R = 8.3145;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[1], _dlist1[1];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   rates ( _threadargscomma_ v ) ;
   Dm = ( minf - m ) / mtau ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 rates ( _threadargscomma_ v ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / mtau )) ;
  return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
   rates ( _threadargscomma_ v ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / mtau)))*(- ( ( ( minf ) ) / mtau ) / ( ( ( ( - 1.0 ) ) ) / mtau ) - m) ;
   }
  return 0;
}
 
double ghk (  double _lv , double _lci , double _lco , double _lz ) {
   double _lghk;
 double _lCi ;
 T = celsius + 273.19 ;
   E = ( 1e-3 ) * _lv ;
   _lCi = _lci + ( monovalPerm ) * ( monovalConc ) ;
   if ( fabs ( 1.0 - exp ( - _lz * ( F * E ) / ( R * T ) ) ) < 1e-6 ) {
     _lghk = ( 1e-6 ) * _lz * F * ( _lCi - _lco * exp ( - _lz * ( F * E ) / ( R * T ) ) ) * ( 1.0 - ( _lz * ( F * E ) / ( R * T ) ) ) ;
     }
   else {
     _lghk = ( 1e-6 ) * pow( _lz , 2.0 ) * ( E * pow( F , 2.0 ) ) / ( R * T ) * ( _lCi - _lco * exp ( - _lz * ( F * E ) / ( R * T ) ) ) / ( 1.0 - exp ( - _lz * ( F * E ) / ( R * T ) ) ) ;
     }
   
return _lghk;
 }
 
static void _hoc_ghk(void) {
  double _r;
   _r =  ghk (  *getarg(1) , *getarg(2) , *getarg(3) , *getarg(4) );
 hoc_retpushx(_r);
}
 
static int  rates (  double _lv ) {
    minf = 1.0 / ( 1.0 + exp ( - ( _lv - ( - 19.0 ) ) / 5.5 ) ) ;
   mtau = ( mtau_func ( _threadargscomma_ _lv ) ) * 1e3 ;
     return 0; }
 
static void _hoc_rates(void) {
  double _r;
   _r = 1.;
 rates (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double mtau_func (  double _lv ) {
   double _lmtau_func;
  if ( _lv > - 50.0 ) {
     _lmtau_func = .000191 + .00376 * exp ( - pow( ( ( _lv - ( - 41.9 ) ) / 27.8 ) , 2.0 ) ) ;
     }
   else {
     _lmtau_func = .00026367 + .1278 * exp ( .10327 * _lv ) ;
     }
    
return _lmtau_func;
 }
 
static void _hoc_mtau_func(void) {
  double _r;
   _r =  mtau_func (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double modulationA (  ) {
   double _lmodulationA;
 _lmodulationA = 1.0 + modA * ( maxModA - 1.0 ) * levelA ;
   
return _lmodulationA;
 }
 
static void _hoc_modulationA(void) {
  double _r;
   _r =  modulationA (  );
 hoc_retpushx(_r);
}
 
double modulationB (  ) {
   double _lmodulationB;
 _lmodulationB = 1.0 + modB * ( maxModB - 1.0 ) * levelB ;
   
return _lmodulationB;
 }
 
static void _hoc_modulationB(void) {
  double _r;
   _r =  modulationB (  );
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
  cai = _ion_cai;
  cao = _ion_cao;
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
  cai = _ion_cai;
  cao = _ion_cao;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 2);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 3, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  m = m0;
 {
   rates ( _threadargscomma_ v ) ;
   m = minf ;
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
  cai = _ion_cai;
  cao = _ion_cao;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   g = ( 1e3 ) * gbar * m * modulationA ( _threadargs_ ) * modulationB ( _threadargs_ ) ;
   ica = g * ghk ( _threadargscomma_ v , cai , cao , 2.0 ) ;
   }
 _current += ica;

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
  cai = _ion_cai;
  cao = _ion_cao;
 _g = _nrn_current(_v + .001);
 	{ double _dica;
  _dica = ica;
 _rhs = _nrn_current(_v);
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ica += ica ;
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
  cai = _ion_cai;
  cao = _ion_cao;
 { error =  states();
 if(error){fprintf(stderr,"at line 91 in file cap_ch_p.mod:\n     SOLVE states METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m) - _p;  _dlist1[0] = &(Dm) - _p;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation-software/local/adaptive/Experiment-Simulation/mechanisms-ptr/cap_ch_p.mod";
static const char* nmodl_file_text = 
  ": HH P-type Calcium current\n"
  ": Created 8/13/02 - nwg\n"
  "\n"
  ": copy by josh for cholinergic interneuron\n"
  "\n"
  "\n"
  "COMMENT\n"
  "\n"
  "Neuromodulation is added as functions:\n"
  "    \n"
  "    modulationA = 1 + modA*(maxModA-1)*levelA\n"
  "\n"
  "where:\n"
  "    \n"
  "    modA  [0]: is a switch for turning modulation on or off {1/0}\n"
  "    maxModA [1]: is the maximum modulation for this specific channel (read from the param file)\n"
  "                    e.g. 10% increase would correspond to a factor of 1.1 (100% +10%) {0-inf}\n"
  "    levelA  [0]: is an additional parameter for scaling modulation. \n"
  "                Can be used simulate non static modulation by gradually changing the value from 0 to 1 {0-1}\n"
  "									\n"
  "	  Further neuromodulators can be added by for example:\n"
  "          modulationA = 1 + modA*(maxModA-1)\n"
  "	  modulationB = 1 + modB*(maxModB-1)\n"
  "	  ....\n"
  "\n"
  "	  etc. for other neuromodulators\n"
  "	  \n"
  "	   \n"
  "								     \n"
  "[] == default values\n"
  "{} == ranges\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX cap_ch_p\n"
  "	USEION ca READ cai, cao WRITE ica\n"
  "	RANGE gbar, ica ,g\n"
  "	GLOBAL minf,mtau\n"
  "	GLOBAL monovalConc, monovalPerm\n"
  "        RANGE modA, maxModA\n"
  "        POINTER levelA\n"
  "        RANGE modB, maxModB\n"
  "        POINTER levelB\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(mV) = (millivolt)\n"
  "	(mA) = (milliamp)\n"
  "	(mM) = (milli/liter)\n"
  "	F = 9.6485e4   (coul)\n"
  "	R = 8.3145 (joule/degC)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	v (mV)\n"
  "\n"
  "	gbar = .00005	(cm/s)\n"
  "	monovalConc = 140     (mM)\n"
  "	monovalPerm = 0\n"
  "	celsius = 35\n"
  "	cai             (milli/liter)\n"
  "	cao             (milli/liter)\n"
  "        modA = 0\n"
  "        maxModA = 1\n"
  "        levelA = 0\n"
  "	modB = 0\n"
  "        maxModB = 1\n"
  "        levelB = 0\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	ica            (mA/cm2)\n"
  "        minf\n"
  "	mtau           (ms)\n"
  "	T              (degC)\n"
  "	E              (volts)\n"
  "	g	(S/cm2)\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	m\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	rates(v)\n"
  "	m = minf\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "     SOLVE states METHOD cnexp\n"
  "	g = (1e3) * gbar * m *modulationA()*modulationB()\n"
  "	ica = g * ghk(v, cai, cao, 2)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "	rates(v)\n"
  "	m' = (minf - m)/mtau\n"
  "}\n"
  "\n"
  "FUNCTION ghk( v(mV), ci(mM), co(mM), z)  (coul/cm3) { LOCAL Ci\n"
  "	T = celsius + 273.19  : Kelvin\n"
  "        E = (1e-3) * v\n"
  "        Ci = ci + (monovalPerm) * (monovalConc)        : Monovalent permeability\n"
  "	if (fabs(1-exp(-z*(F*E)/(R*T))) < 1e-6) { : denominator is small -> Taylor series\n"
  "		ghk = (1e-6) * z * F * (Ci-co*exp(-z*(F*E)/(R*T)))*(1-(z*(F*E)/(R*T)))\n"
  "	} else {\n"
  "		ghk = (1e-6) * z^2*(E*F^2)/(R*T)*(Ci-co*exp(-z*(F*E)/(R*T)))/(1-exp(-z*(F*E)/(R*T)))\n"
  "	}\n"
  "}\n"
  "\n"
  "PROCEDURE rates (v (mV)) {\n"
  "        UNITSOFF\n"
  "	minf = 1/(1+exp(-(v - (-19)) / 5.5))\n"
  "	mtau = (mtau_func(v)) * 1e3\n"
  "        UNITSON\n"
  "}\n"
  "\n"
  "FUNCTION mtau_func( v (mV) ) (ms) {\n"
  "        UNITSOFF\n"
  "        if (v > -50) {\n"
  "            mtau_func = .000191 + .00376*exp(-((v-(-41.9))/27.8)^2)\n"
  "        } else {\n"
  "            mtau_func = .00026367 + .1278 * exp(.10327*v)\n"
  "        }\n"
  "        UNITSON\n"
  "}\n"
  "\n"
  "\n"
  "FUNCTION modulationA() {\n"
  "    : returns modulation factor\n"
  "    \n"
  "    modulationA = 1 + modA*(maxModA-1)*levelA \n"
  "}\n"
  "\n"
  "FUNCTION modulationB() {\n"
  "    : returns modulation factor\n"
  "    \n"
  "    modulationB = 1 + modB*(maxModB-1)*levelB \n"
  "}\n"
  ;
#endif