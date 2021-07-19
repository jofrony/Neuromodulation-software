#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _bk_reg(void);
extern void _cadyn_reg(void);
extern void _can_reg(void);
extern void _caq_reg(void);
extern void _car_reg(void);
extern void _kaf_reg(void);
extern void _kas_reg(void);
extern void _kdr_reg(void);
extern void _kir_reg(void);
extern void _naf_reg(void);
extern void _sk_reg(void);
extern void _tmgabaa_reg(void);
extern void _tmglut_M1RH_D1_reg(void);
extern void _tmglut_reg(void);
extern void _vecevent_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," mechanisms-fsn//bk.mod");
    fprintf(stderr," mechanisms-fsn//cadyn.mod");
    fprintf(stderr," mechanisms-fsn//can.mod");
    fprintf(stderr," mechanisms-fsn//caq.mod");
    fprintf(stderr," mechanisms-fsn//car.mod");
    fprintf(stderr," mechanisms-fsn//kaf.mod");
    fprintf(stderr," mechanisms-fsn//kas.mod");
    fprintf(stderr," mechanisms-fsn//kdr.mod");
    fprintf(stderr," mechanisms-fsn//kir.mod");
    fprintf(stderr," mechanisms-fsn//naf.mod");
    fprintf(stderr," mechanisms-fsn//sk.mod");
    fprintf(stderr," mechanisms-fsn//tmgabaa.mod");
    fprintf(stderr," mechanisms-fsn//tmglut_M1RH_D1.mod");
    fprintf(stderr," mechanisms-fsn//tmglut.mod");
    fprintf(stderr," mechanisms-fsn//vecevent.mod");
    fprintf(stderr, "\n");
  }
  _bk_reg();
  _cadyn_reg();
  _can_reg();
  _caq_reg();
  _car_reg();
  _kaf_reg();
  _kas_reg();
  _kdr_reg();
  _kir_reg();
  _naf_reg();
  _sk_reg();
  _tmgabaa_reg();
  _tmglut_M1RH_D1_reg();
  _tmglut_reg();
  _vecevent_reg();
}
