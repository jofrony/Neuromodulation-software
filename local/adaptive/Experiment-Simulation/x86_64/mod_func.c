#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _bk_ch_reg(void);
extern void _bk_fs_reg(void);
extern void _bk_ms_reg(void);
extern void _ca_ch_reg(void);
extern void _cadyn_fs_reg(void);
extern void _cadyn_ms_reg(void);
extern void _cal12_ms_reg(void);
extern void _cal12_ms_ptr_reg(void);
extern void _cal13_ms_reg(void);
extern void _cal13_ms_ptr_reg(void);
extern void _cal_ch_reg(void);
extern void _cal_ch_ptr_reg(void);
extern void _caldyn_ms_reg(void);
extern void _can_fs_reg(void);
extern void _can_ms_reg(void);
extern void _can_ms_ptr_reg(void);
extern void _cap_ch_reg(void);
extern void _cap_ch_ptr_reg(void);
extern void _caq_fs_reg(void);
extern void _caq_ms_reg(void);
extern void _car_fs_reg(void);
extern void _car_ms_reg(void);
extern void _car_ms_ptr_reg(void);
extern void _cat32_ms_reg(void);
extern void _cat33_ms_reg(void);
extern void _concACh_reg(void);
extern void _concDA_reg(void);
extern void _hcn12_ch_reg(void);
extern void _hcn12_ch_ptr_reg(void);
extern void _hd_lts_reg(void);
extern void _hd_lts_ptr_reg(void);
extern void _im_lts_reg(void);
extern void _im_lts_ptr_reg(void);
extern void _Im_ms_reg(void);
extern void _Im_ms_ptr_reg(void);
extern void _it_lts_reg(void);
extern void _it_lts_ptr_reg(void);
extern void _kaf_fs_reg(void);
extern void _kaf_fs_ptr_reg(void);
extern void _kaf_lts_reg(void);
extern void _kaf_lts_ptr_reg(void);
extern void _kaf_ms_reg(void);
extern void _kaf_ms_ptr_reg(void);
extern void _kas_fs_reg(void);
extern void _kas_fs_ptr_reg(void);
extern void _kas_ms_reg(void);
extern void _kas_ms_ptr_reg(void);
extern void _kcnq_ch_reg(void);
extern void _kdb_lts_reg(void);
extern void _kdrbca1_lts_reg(void);
extern void _kdr_fs_reg(void);
extern void _kdr_lts_reg(void);
extern void _kdr_lts_ptr_reg(void);
extern void _kdr_ms_reg(void);
extern void _kir23_ch_reg(void);
extern void _kir23_ch_ptr_reg(void);
extern void _kir23_lts_reg(void);
extern void _kir23_lts_ptr_reg(void);
extern void _kir2_ch_reg(void);
extern void _kir2_ch_ptr_reg(void);
extern void _kir_fs_reg(void);
extern void _kir_fs_ptr_reg(void);
extern void _kir_ms_reg(void);
extern void _kir_ms_ptr_reg(void);
extern void _kv2_ch_reg(void);
extern void _kv4_ch_reg(void);
extern void _kv4_ch_ptr_reg(void);
extern void _na2_ch_reg(void);
extern void _na2_ch_ptr_reg(void);
extern void _na3n_lts_reg(void);
extern void _na3n_lts_ptr_reg(void);
extern void _na_ch_reg(void);
extern void _na_ch_ptr_reg(void);
extern void _naf_fs_reg(void);
extern void _naf_fs_ptr_reg(void);
extern void _naf_lts_reg(void);
extern void _naf_lts_ptr_reg(void);
extern void _naf_ms_reg(void);
extern void _naf_ms_ptr_reg(void);
extern void _NO_reg(void);
extern void _par_ggap_reg(void);
extern void _sk_ch_reg(void);
extern void _sk_fs_reg(void);
extern void _sk_ms_reg(void);
extern void _tmgabaa_reg(void);
extern void _tmgabaa_ptr_reg(void);
extern void _tmglut_M1RH_D1_reg(void);
extern void _tmglut_M1RH_D1_ptr_reg(void);
extern void _tmglut_reg(void);
extern void _tmglut_ptr_reg(void);
extern void _vecevent_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//bk_ch.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//bk_fs.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//bk_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//ca_ch.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//cadyn_fs.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//cadyn_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//cal12_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//cal12_ms_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//cal13_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//cal13_ms_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//cal_ch.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//cal_ch_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//caldyn_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//can_fs.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//can_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//can_ms_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//cap_ch.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//cap_ch_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//caq_fs.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//caq_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//car_fs.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//car_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//car_ms_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//cat32_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//cat33_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//concACh.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//concDA.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//hcn12_ch.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//hcn12_ch_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//hd_lts.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//hd_lts_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//im_lts.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//im_lts_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//Im_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//Im_ms_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//it_lts.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//it_lts_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kaf_fs.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kaf_fs_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kaf_lts.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kaf_lts_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kaf_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kaf_ms_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kas_fs.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kas_fs_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kas_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kas_ms_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kcnq_ch.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kdb_lts.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kdrbca1_lts.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kdr_fs.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kdr_lts.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kdr_lts_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kdr_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kir23_ch.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kir23_ch_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kir23_lts.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kir23_lts_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kir2_ch.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kir2_ch_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kir_fs.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kir_fs_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kir_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kir_ms_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kv2_ch.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kv4_ch.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//kv4_ch_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//na2_ch.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//na2_ch_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//na3n_lts.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//na3n_lts_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//na_ch.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//na_ch_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//naf_fs.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//naf_fs_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//naf_lts.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//naf_lts_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//naf_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//naf_ms_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//NO.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//par_ggap.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//sk_ch.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//sk_fs.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//sk_ms.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//tmgabaa.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//tmgabaa_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//tmglut_M1RH_D1.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//tmglut_M1RH_D1_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//tmglut.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//tmglut_ptr.mod");
    fprintf(stderr," ../../../../../BasalGangliaData/mod-ptr-files//vecevent.mod");
    fprintf(stderr, "\n");
  }
  _bk_ch_reg();
  _bk_fs_reg();
  _bk_ms_reg();
  _ca_ch_reg();
  _cadyn_fs_reg();
  _cadyn_ms_reg();
  _cal12_ms_reg();
  _cal12_ms_ptr_reg();
  _cal13_ms_reg();
  _cal13_ms_ptr_reg();
  _cal_ch_reg();
  _cal_ch_ptr_reg();
  _caldyn_ms_reg();
  _can_fs_reg();
  _can_ms_reg();
  _can_ms_ptr_reg();
  _cap_ch_reg();
  _cap_ch_ptr_reg();
  _caq_fs_reg();
  _caq_ms_reg();
  _car_fs_reg();
  _car_ms_reg();
  _car_ms_ptr_reg();
  _cat32_ms_reg();
  _cat33_ms_reg();
  _concACh_reg();
  _concDA_reg();
  _hcn12_ch_reg();
  _hcn12_ch_ptr_reg();
  _hd_lts_reg();
  _hd_lts_ptr_reg();
  _im_lts_reg();
  _im_lts_ptr_reg();
  _Im_ms_reg();
  _Im_ms_ptr_reg();
  _it_lts_reg();
  _it_lts_ptr_reg();
  _kaf_fs_reg();
  _kaf_fs_ptr_reg();
  _kaf_lts_reg();
  _kaf_lts_ptr_reg();
  _kaf_ms_reg();
  _kaf_ms_ptr_reg();
  _kas_fs_reg();
  _kas_fs_ptr_reg();
  _kas_ms_reg();
  _kas_ms_ptr_reg();
  _kcnq_ch_reg();
  _kdb_lts_reg();
  _kdrbca1_lts_reg();
  _kdr_fs_reg();
  _kdr_lts_reg();
  _kdr_lts_ptr_reg();
  _kdr_ms_reg();
  _kir23_ch_reg();
  _kir23_ch_ptr_reg();
  _kir23_lts_reg();
  _kir23_lts_ptr_reg();
  _kir2_ch_reg();
  _kir2_ch_ptr_reg();
  _kir_fs_reg();
  _kir_fs_ptr_reg();
  _kir_ms_reg();
  _kir_ms_ptr_reg();
  _kv2_ch_reg();
  _kv4_ch_reg();
  _kv4_ch_ptr_reg();
  _na2_ch_reg();
  _na2_ch_ptr_reg();
  _na3n_lts_reg();
  _na3n_lts_ptr_reg();
  _na_ch_reg();
  _na_ch_ptr_reg();
  _naf_fs_reg();
  _naf_fs_ptr_reg();
  _naf_lts_reg();
  _naf_lts_ptr_reg();
  _naf_ms_reg();
  _naf_ms_ptr_reg();
  _NO_reg();
  _par_ggap_reg();
  _sk_ch_reg();
  _sk_fs_reg();
  _sk_ms_reg();
  _tmgabaa_reg();
  _tmgabaa_ptr_reg();
  _tmglut_M1RH_D1_reg();
  _tmglut_M1RH_D1_ptr_reg();
  _tmglut_reg();
  _tmglut_ptr_reg();
  _vecevent_reg();
}
