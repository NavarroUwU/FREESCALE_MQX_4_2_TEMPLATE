/**HEADER********************************************************************
 * 
 * Copyright (c) 2010, 2013 - 2014 Freescale Semiconductor;
 * All Rights Reserved
 *
 *************************************************************************** 
 *
 * THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
 * IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 **************************************************************************
 *
 * $FileName: ieee11073_nom_codes.h$
 * $Version : 
 * $Date    : 
 *
 * Comments:
 *
 * @brief This file contains the nomenclature codes used by IEEE_11073
 *****************************************************************************/
#ifndef __ieee11073_nom_codes__
#define __ieee11073_nom_codes__

/******************************************************************************
 * Macro's
 *****************************************************************************/
/* Partition codes */
#define MDC_PART_OBJ                                (1) /* Object Infrastr. */
#define MDC_PART_SCADA                              (2) /* SCADA (Physio IDs */
#define MDC_PART_DIM                                (4) /* Dimension */
#define MDC_PART_INFRA                              (8) /* Infrastructure */
#define MDC_PART_PHD_DM                             (128) /* Disease Mgmt */
#define MDC_PART_PHD_HF                             (129) /* Health and Fitness */
#define MDC_PART_PHD_AI                             (130) /* Aging Independently */
#define MDC_PART_RET_CODE                           (255) /* Return Codes */
#define MDC_PART_EXT_NOM                            (256) /* Ext. Nomenclature */
/**********************************************************************************
 * From Object Infrastructure (MDC_PART_OBJ)
 **********************************************************************************/
#define MDC_MOC_VMO_METRIC                          (4) /* */
#define MDC_MOC_VMO_METRIC_ENUM                     (5) /* */
#define MDC_MOC_VMO_METRIC_NU                       (6) /* */
#define MDC_MOC_VMO_METRIC_SA_RT                    (9) /* */
#define MDC_MOC_SCAN                                (16) /* */
#define MDC_MOC_SCAN_CFG                            (17) /* */
#define MDC_MOC_SCAN_CFG_EPI                        (18) /* */
#define MDC_MOC_SCAN_CFG_PERI                       (19) /* */
#define MDC_MOC_VMS_MDS_SIMP                        (37) /* */
#define MDC_MOC_VMO_PMSTORE                         (61) /* */
#define MDC_MOC_PM_SEGMENT                          (62) /* */
#define MDC_ATTR_CONFIRM_MODE                       (2323) /* */
#define MDC_ATTR_CONFIRM_TIMEOUT                    (2324) /* */
#define MDC_ATTR_ID_HANDLE                          (2337) /* */
#define MDC_ATTR_ID_INSTNO                          (2338) /* */
#define MDC_ATTR_ID_LABEL_STRING                    (2343) /* */
#define MDC_ATTR_ID_MODEL                           (2344) /* */
#define MDC_ATTR_ID_PHYSIO                          (2347) /* */
#define MDC_ATTR_ID_PROD_SPECN                      (2349) /* */
#define MDC_ATTR_ID_TYPE                            (2351) /* */
#define MDC_ATTR_METRIC_STORE_CAPAC_CNT             (2369) /* */
#define MDC_ATTR_METRIC_STORE_SAMPLE_ALG            (2371) /* */
#define MDC_ATTR_METRIC_STORE_USAGE_CNT             (2372) /* */
#define MDC_ATTR_MSMT_STAT                          (2375) /* */
#define MDC_ATTR_NU_ACCUR_MSMT                      (2378) /* */
#define MDC_ATTR_NU_CMPD_VAL_OBS                    (2379) /* */
#define MDC_ATTR_NU_VAL_OBS                         (2384) /* */
#define MDC_ATTR_NUM_SEG                            (2385) /* */
#define MDC_ATTR_OP_STAT                            (2387) /* */
#define MDC_ATTR_POWER_STAT                         (2389) /* */
#define MDC_ATTR_SA_SPECN                           (2413) /* */
#define MDC_ATTR_SCALE_SPECN_I16                    (2415) /* */
#define MDC_ATTR_SCALE_SPECN_I32                    (2416) /* */
#define MDC_ATTR_SCALE_SPECN_I8                     (2417) /* */
#define MDC_ATTR_SCAN_REP_PD                        (2421) /* */
#define MDC_ATTR_SEG_USAGE_CNT                      (2427) /* */
#define MDC_ATTR_SYS_ID                             (2436) /* */
#define MDC_ATTR_SYS_TYPE                           (2438) /* */
#define MDC_ATTR_TIME_ABS                           (2439) /* */
#define MDC_ATTR_TIME_BATT_REMAIN                   (2440) /* */
#define MDC_ATTR_TIME_END_SEG                       (2442) /* */
#define MDC_ATTR_TIME_PD_SAMP                       (2445) /* */
#define MDC_ATTR_TIME_REL                           (2447) /* */
#define MDC_ATTR_TIME_STAMP_ABS                     (2448) /* */
#define MDC_ATTR_TIME_STAMP_REL                     (2449) /* */
#define MDC_ATTR_TIME_START_SEG                     (2450) /* */
#define MDC_ATTR_TX_WIND                            (2453) /* */
#define MDC_ATTR_UNIT_CODE                          (2454) /* */
#define MDC_ATTR_UNIT_LABEL_STRING                  (2457) /* */
#define MDC_ATTR_VAL_BATT_CHARGE                    (2460) /* */
#define MDC_ATTR_VAL_ENUM_OBS                       (2462) /* */
#define MDC_ATTR_TIME_REL_HI_RES                    (2536) /* */
#define MDC_ATTR_TIME_STAMP_REL_HI_RES              (2537) /* */
#define MDC_ATTR_DEV_CONFIG_ID                      (2628) /* */
#define MDC_ATTR_MDS_TIME_INFO                      (2629) /* */
#define MDC_ATTR_METRIC_SPEC_SMALL                  (2630) /* */
#define MDC_ATTR_SOURCE_HANDLE_REF                  (2631) /* */
#define MDC_ATTR_SIMP_SA_OBS_VAL                    (2632) /* */
#define MDC_ATTR_ENUM_OBS_VAL_SIMP_OID              (2633) /* */
#define MDC_ATTR_ENUM_OBS_VAL_SIMP_STR              (2634) /* */
#define MDC_ATTR_REG_CERT_DATA_LIST                 (2635) /* */
#define MDC_ATTR_NU_VAL_OBS_BASIC                   (2636) /* */
#define MDC_ATTR_PM_STORE_CAPAB                     (2637) /* */
#define MDC_ATTR_PM_SEG_MAP                         (2638) /* */
#define MDC_ATTR_PM_SEG_PERSON_ID                   (2639) /* */
#define MDC_ATTR_SEG_STATS                          (2640) /* */
#define MDC_ATTR_SEG_FIXED_DATA                     (2641) /* */
#define MDC_ATTR_PM_SEG_ELEM_STAT_ATTR              (2642) /* */
#define MDC_ATTR_SCAN_HANDLE_ATTR_VAL_MAP           (2643) /* */
#define MDC_ATTR_SCAN_REP_PD_MIN                    (2644) /* */
#define MDC_ATTR_ATTRIBUTE_VAL_MAP                  (2645) /* */
#define MDC_ATTR_NU_VAL_OBS_SIMP                    (2646) /* */
#define MDC_ATTR_PM_STORE_LABEL_STRING              (2647) /* */
#define MDC_ATTR_PM_SEG_LABEL_STRING                (2648) /* */
#define MDC_ATTR_TIME_PD_MSMT_ACTIVE                (2649) /* */
#define MDC_ATTR_SYS_TYPE_SPEC_LIST                 (2650) /* */
#define MDC_ATTR_METRIC_ID_PART                     (2655) /* */
#define MDC_ATTR_ENUM_OBS_VAL_PART                  (2656) /* */
#define MDC_ATTR_SUPPLEMENTAL_TYPES                 (2657) /* */
#define MDC_ATTR_TIME_ABS_ADJUST                    (2658) /* */
#define MDC_ATTR_CLEAR_TIMEOUT                      (2659) /* */
#define MDC_ATTR_TRANSFER_TIMEOUT                   (2660) /* */
#define MDC_ATTR_ENUM_OBS_VAL_SIMP_BIT_STR          (2661) /* */
#define MDC_ATTR_ENUM_OBS_VAL_BASIC_BIT_STR         (2662) /* */
#define MDC_ATTR_METRIC_STRUCT_SMALL                (2675) /* */
#define MDC_ATTR_NU_CMPD_VAL_OBS_SIMP               (2676) /* */
#define MDC_ATTR_NU_CMPD_VAL_OBS_BASIC              (2677) /* */
#define MDC_ATTR_ID_PHYSIO_LIST                     (2678) /* */
#define MDC_ATTR_SCAN_HANDLE_LIST                   (2679) /* */
/* Partition: ACT */
#define MDC_ACT_SEG_CLR                             (3084) /* */
#define MDC_ACT_SEG_GET_INFO                        (3085) /* */
#define MDC_ACT_SET_TIME                            (3095) /* */
#define MDC_ACT_DATA_REQUEST                        (3099) /* */
#define MDC_ACT_SEG_TRIG_XFER                       (3100) /* */
#define MDC_NOTI_CONFIG                             (3356) /* */
#define MDC_NOTI_SCAN_REPORT_FIXED                  (3357) /* */
#define MDC_NOTI_SCAN_REPORT_VAR                    (3358) /* */
#define MDC_NOTI_SCAN_REPORT_MP_FIXED               (3359) /* */
#define MDC_NOTI_SCAN_REPORT_MP_VAR                 (3360) /* */
#define MDC_NOTI_SEGMENT_DATA                       (3361) /* */
#define MDC_NOTI_UNBUF_SCAN_REPORT_VAR              (3362) /* */
#define MDC_NOTI_UNBUF_SCAN_REPORT_FIXED            (3363) /* */
#define MDC_NOTI_UNBUF_SCAN_REPORT_GROUPED          (3364) /* */
#define MDC_NOTI_UNBUF_SCAN_REPORT_MP_VAR           (3365) /* */
#define MDC_NOTI_UNBUF_SCAN_REPORT_MP_FIXED         (3366) /* */
#define MDC_NOTI_UNBUF_SCAN_REPORT_MP_GROUPED       (3367) /* */
#define MDC_NOTI_BUF_SCAN_REPORT_VAR                (3368) /* */
#define MDC_NOTI_BUF_SCAN_REPORT_FIXED              (3369) /* */
#define MDC_NOTI_BUF_SCAN_REPORT_GROUPED            (3370) /* */
#define MDC_NOTI_BUF_SCAN_REPORT_MP_VAR             (3371) /* */
#define MDC_NOTI_BUF_SCAN_REPORT_MP_FIXED           (3372) /* */
#define MDC_NOTI_BUF_SCAN_REPORT_MP_GROUPED         (3373) /* */
/*********************************************************************************
 * From Medical supervisory control and data acquisition (MDC_PART_SCADA)
 **********************************************************************************/
#define MDC_TEMP_BODY                               (19292) /*TEMPbody */
#define MDC_PULS_RATE_NON_INV                       (18474) /* */
#define MDC_PRESS_BLD_NONINV                        (18948) /* NIBP */
#define MDC_PRESS_BLD_NONINV_SYS                    (18949) /* */
#define MDC_PRESS_BLD_NONINV_DIA                    (18950) /* */
#define MDC_PRESS_BLD_NONINV_MEAN                   (18951) /* */
#define MDC_MASS_BODY_ACTUAL                        (57664) /* */
#define MDC_LEN_BODY_ACTUAL                         (57666) /* */
#define MDC_RATIO_MASS_BODY_LEN_SQ                  (57680) /* */
/* Partition: SCADA/Other */
#define MDC_BODY_FAT                                (57676) /* */
#define MDC_PRESS_BLD_NONINV                        (18948) /* */
#define MDC_CONC_GLU_GEN                            (28948) /* */
#define MDC_CONC_GLU_CAPILLARY_WHOLEBLOOD           (29112) /* */
#define MDC_CONC_GLU_CAPILLARY_PLASMA               (29116) /* */
#define MDC_CONC_GLU_VENOUS_WHOLEBLOOD              (29120) /* */
#define MDC_CONC_GLU_VENOUS_PLASMA                  (29124) /* */
#define MDC_CONC_GLU_ARTERIAL_WHOLEBLOOD            (29128) /* */
#define MDC_CONC_GLU_ARTERIAL_PLASMA                (29132) /* */
#define MDC_CONC_GLU_CONTROL                        (29136) /* */
#define MDC_CONC_GLU_ISF                            (29140) /* */
#define MDC_CONC_HBA1C                              (29148) /* */
#define MDC_GLU_METER_DEV_STATUS                    (29144) /* */
#define MDC_CTXT_GLU_EXERCISE                       (29152) /* */
#define MDC_CTXT_GLU_CARB                           (29156) /* */
#define MDC_CTXT_GLU_CARB_BREAKFAST                 (29160) /* */
#define MDC_CTXT_GLU_CARB_LUNCH                     (29164) /* */
#define MDC_CTXT_GLU_CARB_DINNER                    (29168) /* */
#define MDC_CTXT_GLU_CARB_SNACK                     (29172) /* */
#define MDC_CTXT_GLU_CARB_DRINK                     (29176) /* */
#define MDC_CTXT_GLU_CARB_SUPPER                    (29180) /* */
#define MDC_CTXT_GLU_CARB_BRUNCH                    (29184) /* */
#define MDC_CTXT_MEDICATION                         (29188) /* */
#define MDC_CTXT_MEDICATION_RAPIDACTING             (29192) /* */
#define MDC_CTXT_MEDICATION_SHORTACTING             (29196) /* */
#define MDC_CTXT_MEDICATION_INTERMEDIATEACTING      (29200) /* */
#define MDC_CTXT_MEDICATION_LONGACTING              (29204) /* */
#define MDC_CTXT_MEDICATION_PREMIX                  (29208) /* */
#define MDC_CTXT_GLU_HEALTH                         (29212) /* */
#define MDC_CTXT_GLU_HEALTH_MINOR                   (29216) /* */
#define MDC_CTXT_GLU_HEALTH_MAJOR                   (29220) /* */
#define MDC_CTXT_GLU_HEALTH_MENSES                  (29224) /* */
#define MDC_CTXT_GLU_HEALTH_STRESS                  (29228) /* */
#define MDC_CTXT_GLU_HEALTH_NONE                    (29232) /* */
#define MDC_CTXT_GLU_SAMPLELOCATION                 (29236) /* */
#define MDC_CTXT_GLU_SAMPLELOCATION_FINGER          (29240) /* */
#define MDC_CTXT_GLU_SAMPLELOCATION_AST             (29244) /* */
#define MDC_CTXT_GLU_SAMPLELOCATION_EARLOBE         (29248) /* */
#define MDC_CTXT_GLU_SAMPLELOCATION_CTRLSOLUTION    (29252) /* */
#define MDC_CTXT_GLU_MEAL                           (29256) /* */
#define MDC_CTXT_GLU_MEAL_PREPRANDIAL               (29260) /* */
#define MDC_CTXT_GLU_MEAL_POSTPRANDIAL              (29264) /* */
#define MDC_CTXT_GLU_MEAL_FASTING                   (29268) /* */
#define MDC_CTXT_GLU_MEAL_CASUAL                    (29272) /* */
#define MDC_CTXT_GLU_TESTER                         (29276) /* */
#define MDC_CTXT_GLU_TESTER_SELF                    (29280) /* */
#define MDC_CTXT_GLU_TESTER_HCP                     (29284) /* */
#define MDC_CTXT_GLU_TESTER_LAB                     (29288) /* */
/*********************************************************************************
 * From Dimensions (MDC_PART_DIM)
 **********************************************************************************/
#define MDC_DIM_PERCENT                             (544) /* % */
#define MDC_DIM_MILLI_L  1618 /* ml */
#define MDC_DIM_MILLI_G  1746 /* mg */
#define MDC_DIM_MILLI_G_PER_DL  2130 /* mg dl-1 */
#define MDC_DIM_MILLI_MOLE_PER_L  4722 /* mmol l-1 */
#define MDC_DIM_X_G  1728 /* g */
#define MDC_DIM_KILO_G                              (1731) /* kg */
#define MDC_DIM_KG_PER_M_SQ 1952 /* kg/m2 */
#define MDC_DIM_MIN                                 (2208) /* min */
#define MDC_DIM_HR                                  (2240) /* h */
#define MDC_DIM_DAY                                 (2272) /* d */
#define MDC_DIM_DEGC                                (6048) /* oC */
#define MDC_DIM_MMHG                                (3872)
#define MDC_DIM_CENTI_M                             (1297) /* cm */
#define MDC_DIM_BEAT_PER_MIN 2720 /* bpm */
/*********************************************************************************
 * From Communication Infrastructure (MDC_PART_INFRA)
 **********************************************************************************/
#define MDC_DEV_SPEC_PROFILE_PULS_OXIM              (4100) /* */
#define MDC_DEV_SPEC_PROFILE_BP                     (4103) /* */
#define MDC_DEV_SPEC_PROFILE_TEMP                   (4104) /* */
#define MDC_DEV_SPEC_PROFILE_SCALE                  (4111) /* */
#define MDC_DEV_SPEC_PROFILE_GLUCOSE                (4113) /* */
#define MDC_DEV_SPEC_PROFILE_HF_CARDIO              (4137) /* */
#define MDC_DEV_SPEC_PROFILE_HF_STRENGTH            (4138) /* */
#define MDC_DEV_SPEC_PROFILE_AI_ACTIVITY_HUB        (4167) /* */
#define MDC_DEV_SPEC_PROFILE_AI_MED_MINDER          (4168) /* */
/* Placed 256 back from the start of the last Partition: OptionalPackageIdentifiers
 (i.e. 8192-256). */
#define MDC_TIME_SYNC_NONE                          (7936) /* no time synchronization protocol supported */
#define MDC_TIME_SYNC_NTPV3                         (7937) /* RFC 1305 1992 Mar obs: 1119,1059,958 */
#define MDC_TIME_SYNC_NTPV4                         (7938) /* <under development at ntp.org> */
#define MDC_TIME_SYNC_SNTPV4                        (7939) /* RFC 2030 1996 Oct obs: 1769 */
#define MDC_TIME_SYNC_SNTPV4330                     (7940) /* RFC 4330 2006 Jan obs: 2030,1769 */
#define MDC_TIME_SYNC_BTV1                          (7941) /* Bluetooth Medical Device Profile */
/*********************************************************************************
 * From Return Codes (MDC_PART_RET_CODE)
 **********************************************************************************/
#define MDC_RET_CODE_UNKNOWN                        (1) /* Generic error code */
/* Partition MDC_PART_RET_CODE/OBJ Object errors */
#define MDC_RET_CODE_OBJ_BUSY                       (1000) /* Object is busy so cannot handle the request */
/* Partition MDC_PART_RETURN_CODES/STORE Storage errors */
#define MDC_RET_CODE_STORE_EXH                      (2000) /* Storage such as disk is full */
#define MDC_RET_CODE_STORE_OFFLN                    (2001) /* Storage such as disk is offline */

#define MDC_MODALITY_FAST                           (0x4C34)
#define MDC_TEMP_ORAL                               (0xE008)
#define MDC_TEMP_RECT                               (0xE004)
#define MDC_HF_ACT_WALK                             (1017)

/* Types */
typedef struct nomenclature_ascii_struct
{
    oid_type_t type;
    int8_t *ascii_string;
} nomenclature_ascii_struct_t;

typedef struct partition_ascii_struct
{
    nom_partition_t partition;
    int8_t *ascii_string;
} partition_ascii_struct_t;

extern const nomenclature_ascii_struct_t g_nomenclature_ascii_table[];
extern const partition_ascii_struct_t g_partition_ascii_table[];
extern const uint16_t g_nom_ascii_count;
extern const uint16_t g_partition_ascii_count;

#endif /* __ieee11073_nom_codes__ */
