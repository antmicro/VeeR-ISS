#include <iostream>
#include <fstream>

#include <bitset>
#include "Interactive.hpp"

using namespace WdRiscv;

bool rtlIsLegalOpcode(uint32_t inst) {
	std::bitset<32> i = inst;
	if((inst&0x3) != 3)
		return  ((!i[15])&&i[12]&&(!i[0])) || ((!i[15])&&i[6]&&(!i[0])) || ((!i[15])&&i[5]&&(!i[0])) || (
			    (!i[13])&&(!i[12])&&(!i[1])&&i[0]) || ((!i[13])&&(!i[11])&&(!i[1])&&i[0]) || ((!i[15])
			    &&(!i[14])&&i[11]&&(!i[1])) || ((!i[15])&&(!i[14])&&i[10]&&(!i[1])) || ((!i[13])&&(!i[10])
			    &&(!i[1])&&i[0]) || ((!i[15])&&(!i[14])&&i[9]&&(!i[1])) || (i[15]&&i[13]&&(!i[1])) || (
			    (!i[13])&&(!i[6])&&(!i[1])&&i[0]) || ((!i[15])&&(!i[14])&&i[8]&&(!i[1])) || ((!i[15])&&(!i[14])
			    &&i[7]&&(!i[1])) || (i[12]&&i[1]&&(!i[0])) || (i[7]&&i[1]&&(!i[0])) || (i[8]&&i[1]
			    &&(!i[0])) || (i[9]&&i[1]&&(!i[0])) || (i[10]&&i[1]&&(!i[0])) || (i[11]&&i[1]&&(!i[0])) || (
			    i[14]&&i[2]&&(!i[1])) || (i[14]&&i[3]&&(!i[1])) || (i[14]&&i[4]&&(!i[1])) || (i[14]
			    &&i[6]&&(!i[1])) || (i[14]&&i[5]&&(!i[1])) || (i[14]&&i[12]&&(!i[1])) || (i[2]&&i[1]
			    &&(!i[0])) || (i[3]&&i[1]&&(!i[0])) || (i[4]&&i[1]&&(!i[0])) || (i[6]&&i[1]&&(!i[0])) || (
			    i[5]&&i[1]&&(!i[0])) || (i[14]&&(!i[0])) || (i[13]&&(!i[0])) || ((!i[15])&&i[1]&&(!i[0]));
    return
            (((!i[31])&&(!i[30])&&(!i[29])&&i[28]&&(!i[27])&&(!i[26])&&(!i[24])&&(!i[23])&&i[22]
            &&(!i[21])&&i[20]&&(!i[19])&&(!i[18])&&(!i[17])&&(!i[16])&&(!i[15])&&(!i[14])&&(!i[11])&&(!i[10])
            &&(!i[9])&&(!i[8])&&(!i[7])&&i[6]&&i[4]&&(!i[3])&&(!i[2])&&i[1]&&i[0])||((!i[31])&&(!i[30])
            &&i[28]&&(!i[27])&&(!i[26])&&(!i[25])&&(!i[24])&&(!i[23])&&(!i[22])&&i[21]&&(!i[20])&&(!i[19])
            &&(!i[18])&&(!i[17])&&(!i[16])&&(!i[15])&&(!i[14])&&(!i[11])&&(!i[10])&&(!i[9])&&(!i[8])&&(!i[7])
            &&i[6]&&i[5]&&i[4]&&(!i[3])&&(!i[2])&&i[1]&&i[0])||((!i[31])&&(!i[30])&&(!i[29])&&(!i[28])
            &&(!i[27])&&(!i[26])&&(!i[25])&&(!i[24])&&(!i[23])&&(!i[22])&&(!i[21])&&(!i[19])&&(!i[18])&&(!i[17])
            &&(!i[16])&&(!i[15])&&(!i[14])&&(!i[11])&&(!i[10])&&(!i[9])&&(!i[8])&&(!i[7])&&i[4]&&(!i[3])&&(!i[2])
            &&i[1]&&i[0])||((!i[31])&&(!i[30])&&(!i[29])&&i[28]&&(!i[27])&&(!i[26])&&i[25]&&(!i[14])
            &&(!i[11])&&(!i[10])&&(!i[9])&&(!i[8])&&(!i[7])&&i[6]&&i[4]&&(!i[3])&&(!i[2])&&i[1]&&i[0])||(
            (!i[31])&&(!i[30])&&(!i[29])&&(!i[24])&&(!i[23])&&(!i[22])&&(!i[21])&&(!i[20])&&(!i[14])&&i[13]
            &&i[5]&&(!i[4])&&i[3]&&i[2]&&i[1]&&i[0])||((!i[31])&&i[30]&&i[29]&&(!i[28])&&(!i[27])
            &&(!i[26])&&(!i[25])&&(!i[24])&&(!i[23])&&(!i[22])&&(!i[21])&&(!i[13])&&i[12]&&(!i[6])&&i[4]
            &&(!i[2])&&i[1]&&i[0])||(i[31]&&i[29]&&(!i[28])&&(!i[27])&&(!i[26])&&(!i[24])&&(!i[23])
            &&(!i[22])&&(!i[21])&&(!i[20])&&(!i[14])&&(!i[13])&&i[6]&&(!i[5])&&(!i[3])&&(!i[2])&&i[1]&&i[0])||(
            (!i[31])&&i[30]&&i[29]&&(!i[28])&&(!i[27])&&(!i[26])&&(!i[25])&&(!i[24])&&(!i[23])&&(!i[22])
            &&(!i[20])&&(!i[13])&&i[12]&&(!i[6])&&i[4]&&(!i[2])&&i[1]&&i[0])||((!i[31])&&i[30]
            &&i[29]&&(!i[28])&&(!i[26])&&(!i[25])&&(!i[24])&&(!i[23])&&(!i[21])&&(!i[6])&&(!i[5])&&i[4]
            &&(!i[3])&&i[1]&&i[0])||((!i[31])&&(!i[29])&&i[28]&&i[27]&&(!i[26])&&(!i[24])&&(!i[23])
            &&(!i[22])&&(!i[21])&&(!i[20])&&i[6]&&(!i[5])&&(!i[3])&&(!i[2])&&i[1]&&i[0])||((!i[31])
            &&i[30]&&i[29]&&(!i[28])&&(!i[26])&&(!i[25])&&i[24]&&(!i[22])&&(!i[6])&&(!i[5])&&i[4]&&(!i[3])
            &&i[1]&&i[0])||((!i[31])&&i[30]&&i[29]&&(!i[28])&&(!i[26])&&(!i[25])&&(!i[23])&&(!i[22])
            &&(!i[6])&&(!i[5])&&i[4]&&(!i[3])&&i[1]&&i[0])||((!i[31])&&(!i[30])&&(!i[29])&&(!i[28])
            &&(!i[26])&&(!i[25])&&(!i[13])&&i[12]&&(!i[6])&&i[5]&&i[4]&&(!i[2])&&i[1]&&i[0])||(
            (!i[31])&&(!i[30])&&(!i[29])&&(!i[28])&&(!i[26])&&i[25]&&i[13]&&(!i[6])&&i[4]&&(!i[3])&&i[1]
            &&i[0])||(i[31]&&i[30]&&(!i[29])&&(!i[27])&&(!i[26])&&(!i[24])&&(!i[23])&&(!i[22])&&i[6]
            &&(!i[5])&&(!i[3])&&(!i[2])&&i[1]&&i[0])||((!i[31])&&(!i[30])&&(!i[29])&&(!i[28])&&(!i[27])
            &&(!i[26])&&(!i[14])&&(!i[13])&&(!i[12])&&(!i[6])&&i[4]&&(!i[2])&&i[1]&&i[0])||((!i[31])
            &&(!i[30])&&(!i[29])&&i[27]&&(!i[14])&&i[13]&&i[5]&&(!i[4])&&i[3]&&i[2]&&i[1]&&i[0])||(
            (!i[31])&&(!i[29])&&(!i[28])&&i[27]&&(!i[26])&&(!i[25])&&i[12]&&(!i[6])&&i[4]&&(!i[3])&&i[1]
            &&i[0])||((!i[31])&&i[30]&&(!i[28])&&i[27]&&(!i[26])&&(!i[6])&&(!i[5])&&i[4]&&(!i[3])
            &&i[1]&&i[0])||((!i[31])&&i[30]&&(!i[28])&&(!i[27])&&(!i[26])&&(!i[25])&&i[14]&&(!i[13])
            &&i[12]&&(!i[6])&&i[4]&&(!i[2])&&i[1]&&i[0])||((!i[30])&&i[29]&&(!i[28])&&(!i[27])
            &&(!i[26])&&(!i[14])&&(!i[12])&&(!i[5])&&(!i[3])&&(!i[2])&&i[1]&&i[0])||((!i[31])&&i[30]
            &&(!i[28])&&(!i[26])&&i[14]&&(!i[6])&&(!i[5])&&i[4]&&(!i[3])&&i[1]&&i[0])||((!i[31])
            &&(!i[30])&&i[29]&&(!i[28])&&i[27]&&(!i[26])&&(!i[25])&&(!i[12])&&(!i[6])&&i[4]&&(!i[3])&&i[1]
            &&i[0])||((!i[31])&&i[29]&&(!i[28])&&i[27]&&(!i[26])&&(!i[6])&&(!i[5])&&i[4]&&(!i[3])
            &&i[1]&&i[0])||((!i[28])&&(!i[27])&&(!i[14])&&i[13]&&i[5]&&(!i[4])&&i[3]&&i[2]&&i[1]
            &&i[0])||((!i[31])&&(!i[30])&&(!i[28])&&(!i[26])&&(!i[14])&&(!i[13])&&i[6]&&(!i[5])&&(!i[3])
            &&(!i[2])&&i[1]&&i[0])||((!i[31])&&(!i[29])&&(!i[28])&&(!i[26])&&(!i[25])&&i[14]&&(!i[6])
            &&i[4]&&(!i[3])&&i[1]&&i[0])||((!i[31])&&(!i[30])&&(!i[29])&&(!i[28])&&(!i[26])&&i[12]
            &&i[5]&&i[4]&&(!i[3])&&(!i[2])&&i[1]&&i[0])||((!i[31])&&(!i[29])&&(!i[28])&&(!i[27])
            &&(!i[26])&&(!i[25])&&i[14]&&(!i[13])&&i[12]&&(!i[6])&&i[4]&&(!i[2])&&i[1]&&i[0])||(
            (!i[30])&&i[29]&&(!i[28])&&(!i[27])&&(!i[26])&&(!i[14])&&(!i[13])&&i[6]&&(!i[5])&&(!i[3])&&(!i[2])
            &&i[1]&&i[0])||((!i[31])&&(!i[30])&&(!i[29])&&(!i[28])&&(!i[26])&&i[14]&&(!i[6])&&i[5]
            &&i[4]&&(!i[3])&&i[1]&&i[0])||((!i[31])&&(!i[30])&&(!i[29])&&(!i[28])&&(!i[26])&&(!i[25])
            &&(!i[14])&&(!i[13])&&(!i[6])&&i[4]&&i[3]&&(!i[2])&&i[1]&&i[0])||((!i[31])&&(!i[29])
            &&(!i[28])&&(!i[27])&&(!i[26])&&i[6]&&(!i[5])&&(!i[3])&&(!i[2])&&i[1]&&i[0])||((!i[31])
            &&(!i[28])&&i[27]&&(!i[26])&&(!i[25])&&(!i[13])&&i[12]&&(!i[6])&&i[4]&&(!i[3])&&i[1]&&i[0])||(
            (!i[14])&&(!i[13])&&(!i[12])&&i[6]&&i[5]&&(!i[4])&&(!i[3])&&i[1]&&i[0])||((!i[14])&&i[13]
            &&(!i[6])&&(!i[3])&&i[2]&&i[1]&&i[0])||((!i[31])&&(!i[30])&&(!i[29])&&(!i[26])&&i[6]&&(!i[5])
            &&(!i[3])&&(!i[2])&&i[1]&&i[0])||((!i[31])&&(!i[30])&&(!i[29])&&(!i[28])&&(!i[27])&&(!i[26])
            &&(!i[6])&&i[4]&&(!i[3])&&i[1]&&i[0])||(i[14]&&i[6]&&i[5]&&(!i[4])&&(!i[3])&&(!i[2])
            &&i[1]&&i[0])||((!i[13])&&i[12]&&i[6]&&i[5]&&(!i[3])&&(!i[2])&&i[1]&&i[0])||(
            (!i[14])&&(!i[6])&&(!i[4])&&(!i[3])&&(!i[2])&&i[1]&&i[0])||((!i[31])&&(!i[30])&&(!i[29])
            &&(!i[28])&&(!i[27])&&(!i[26])&&(!i[25])&&(!i[24])&&(!i[23])&&(!i[22])&&(!i[21])&&(!i[20])&&(!i[19])
            &&(!i[18])&&(!i[17])&&(!i[16])&&(!i[15])&&(!i[14])&&(!i[13])&&(!i[11])&&(!i[10])&&(!i[9])&&(!i[8])
            &&(!i[7])&&(!i[5])&&(!i[4])&&i[3]&&i[2]&&i[1]&&i[0])||((!i[31])&&(!i[30])&&(!i[29])&&(!i[28])
            &&(!i[19])&&(!i[18])&&(!i[17])&&(!i[16])&&(!i[15])&&(!i[14])&&(!i[13])&&(!i[12])&&(!i[11])&&(!i[10])
            &&(!i[9])&&(!i[8])&&(!i[7])&&(!i[6])&&(!i[5])&&(!i[4])&&i[3]&&i[2]&&i[1]&&i[0])||(i[31]
            &&i[30]&&(!i[27])&&(!i[26])&&(!i[24])&&(!i[23])&&(!i[22])&&(!i[21])&&(!i[20])&&(!i[14])&&(!i[13])
            &&(!i[12])&&(!i[5])&&(!i[3])&&(!i[2])&&i[1]&&i[0])||(i[13]&&i[6]&&i[5]&&i[4]&&(!i[3])
            &&(!i[2])&&i[1]&&i[0])||((!i[31])&&(!i[30])&&(!i[29])&&(!i[28])&&(!i[27])&&(!i[26])&&i[25]
            &&i[14]&&(!i[6])&&i[5]&&i[4]&&(!i[2])&&i[1]&&i[0])||((!i[31])&&(!i[30])&&i[29]&&(!i[28])
            &&(!i[27])&&(!i[26])&&(!i[25])&&i[13]&&(!i[12])&&(!i[6])&&i[5]&&i[4]&&(!i[2])&&i[1]&&i[0])||(
            (!i[31])&&(!i[29])&&(!i[28])&&i[27]&&(!i[26])&&(!i[25])&&i[14]&&(!i[12])&&(!i[6])&&i[5]&&i[4]
            &&(!i[2])&&i[1]&&i[0])||((!i[31])&&i[30]&&(!i[29])&&(!i[28])&&i[27]&&(!i[26])&&(!i[25])
            &&i[14]&&i[13]&&(!i[6])&&i[5]&&i[4]&&(!i[2])&&i[1]&&i[0])||((!i[31])&&(!i[29])&&(!i[28])
            &&(!i[27])&&(!i[26])&&(!i[25])&&(!i[14])&&(!i[13])&&(!i[12])&&(!i[6])&&i[4]&&(!i[2])&&i[1]&&i[0])||(
            (!i[31])&&i[30]&&i[29]&&(!i[28])&&(!i[27])&&(!i[26])&&(!i[25])&&(!i[13])&&i[12]&&(!i[6])
            &&i[5]&&i[4]&&(!i[2])&&i[1]&&i[0])||((!i[31])&&(!i[30])&&i[29]&&(!i[28])&&(!i[27])
            &&(!i[26])&&(!i[25])&&i[14]&&(!i[12])&&(!i[6])&&i[5]&&i[4]&&(!i[2])&&i[1]&&i[0])||(
            (!i[31])&&i[29]&&(!i[28])&&i[27]&&(!i[26])&&(!i[25])&&i[14]&&(!i[13])&&i[12]&&(!i[6])&&i[4]
            &&(!i[2])&&i[1]&&i[0])||((!i[31])&&(!i[30])&&(!i[29])&&(!i[28])&&i[27]&&(!i[26])&&(!i[14])
            &&(!i[13])&&(!i[6])&&(!i[5])&&i[4]&&i[3]&&(!i[2])&&i[1]&&i[0])||((!i[26])&&i[6]&&(!i[5])
            &&(!i[4])&&i[1]&&i[0])||((!i[12])&&(!i[6])&&(!i[5])&&(!i[3])&&(!i[2])&&i[1]&&i[0])||(
            i[6]&&i[5]&&(!i[4])&&i[3]&&i[2]&&i[1]&&i[0])||((!i[14])&&(!i[13])&&(!i[12])&&(!i[6])
            &&(!i[5])&&i[4]&&(!i[2])&&i[1]&&i[0])||((!i[13])&&(!i[6])&&(!i[5])&&(!i[4])&&(!i[3])&&(!i[2])
            &&i[1]&&i[0])||(i[13]&&(!i[6])&&(!i[5])&&i[4]&&(!i[3])&&i[1]&&i[0])||((!i[6])&&i[4]
            &&(!i[3])&&i[2]&&i[1]&&i[0]));



}

template<typename URV>
void 
Interactive<URV>::runAllOpcodes(Hart<URV>& hart) {

	static std::vector<std::string> instIdToNames = {
     "illegal",

     // "Base".
     "lui",
     "auipc",
     "jal",
     "jalr",
     "beq",
     "bne",
     "blt",
     "bge",
     "bltu",
     "bgeu",
     "lb",
     "lh",
     "lw",
     "lbu",
     "lhu",
     "sb",
     "sh",
     "sw",
     "addi",
     "slti",
     "sltiu",
     "xori",
     "ori",
     "andi",
     "slli",
     "srli",
     "srai",
     "add",
     "sub",
     "sll",
     "slt",
     "sltu",
     "xor_",
     "srl",
     "sra",
     "or_",
     "and_",
     "fence",
     "fencei",
     "ecall",
     "ebreak",

     // "CSR"
     "csrrw",
     "csrrs",
     "csrrc",
     "csrrwi",
     "csrrsi",
     "csrrci",

     // "rv64i"
     "lwu",
     "ld",
     "sd",
     "addiw",
     "slliw",
     "srliw",
     "sraiw",
     "addw",
     "subw",
     "sllw",
     "srlw",
     "sraw",
 
     // "Mul"/div
     "mul",
     "mulh",
     "mulhsu",
     "mulhu",
     "div",
     "divu",
     "rem",
     "remu",

     // "64"-bit mul/div
     "mulw",
     "divw",
     "divuw",
     "remw",
     "remuw",

     // "Atomic"
     "lr_w",
     "sc_w",
     "amoswap_w",
     "amoadd_w",
     "amoxor_w",
     "amoand_w",
     "amoor_w",
     "amomin_w",
     "amomax_w",
     "amominu_w",
     "amomaxu_w",

     // "64"-bit atomic
     "lr_d",
     "sc_d",
     "amoswap_d",
     "amoadd_d",
     "amoxor_d",
     "amoand_d",
     "amoor_d",
     "amomin_d",
     "amomax_d",
     "amominu_d",
     "amomaxu_d",

     // "rv32f"
     "flw",
     "fsw",
     "fmadd_s",
     "fmsub_s",
     "fnmsub_s",
     "fnmadd_s",
     "fadd_s",
     "fsub_s",
     "fmul_s",
     "fdiv_s",
     "fsqrt_s",
     "fsgnj_s",
     "fsgnjn_s",
     "fsgnjx_s",
     "fmin_s",
     "fmax_s",
     "fcvt_w_s",
     "fcvt_wu_s",
     "fmv_x_w",
     "feq_s",
     "flt_s",
     "fle_s",
     "fclass_s",
     "fcvt_s_w",
     "fcvt_s_wu",
     "fmv_w_x",

     // "rv64f"
     "fcvt_l_s",
     "fcvt_lu_s",
     "fcvt_s_l",
     "fcvt_s_lu",

     // "rv32d"
     "fld",
     "fsd",
     "fmadd_d",
     "fmsub_d",
     "fnmsub_d",
     "fnmadd_d",
     "fadd_d",
     "fsub_d",
     "fmul_d",
     "fdiv_d",
     "fsqrt_d",
     "fsgnj_d",
     "fsgnjn_d",
     "fsgnjx_d",
     "fmin_d",
     "fmax_d",
     "fcvt_s_d",
     "fcvt_d_s",
     "feq_d",
     "flt_d",
     "fle_d",
     "fclass_d",
     "fcvt_w_d",
     "fcvt_wu_d",
     "fcvt_d_w",
     "fcvt_d_wu",

     // "rv64f"
     "fcvt_l_d",
     "fcvt_lu_d",
     "fmv_x_d",
     "fcvt_d_l",
     "fcvt_d_lu",
     "fmv_d_x",

     // "zfh" (half precision floating point)
     "flh",
     "fsh",
     "fmadd_h",
     "fmsub_h",
     "fnmsub_h",
     "fnmadd_h",
     "fadd_h",
     "fsub_h",
     "fmul_h",
     "fdiv_h",
     "fsqrt_h",
     "fsgnj_h",
     "fsgnjn_h",
     "fsgnjx_h",
     "fmin_h",
     "fmax_h",
     "fcvt_s_h",
     "fcvt_d_h",
     "fcvt_h_s",
     "fcvt_h_d",
     "fcvt_w_h",
     "fcvt_wu_h",
     "fmv_x_h",
     "feq_h",
     "flt_h",
     "fle_h",
     "fclass_h",
     "fcvt_h_w",
     "fcvt_h_wu",
     "fmv_h_x",

     // "rv64" + zfh
     "fcvt_l_h",
     "fcvt_lu_h",
     "fcvt_h_l",
     "fcvt_h_lu",

     // "Privileged"
     "mret",
     "uret",
     "sret",
     "wfi",

     // "Supervisor"
     "sfence_vma",

     // "Compressed" insts
     "c_addi4spn",
     "c_fld",
     "c_lq",
     "c_lw",
     "c_flw",
     "c_ld",
     "c_fsd",
     "c_sq",
     "c_sw",
     "c_fsw",
     "c_sd",
     "c_addi",
     "c_jal",
     "c_li",
     "c_addi16sp",
     "c_lui",
     "c_srli",
     "c_srli64",
     "c_srai",
     "c_srai64",
     "c_andi",
     "c_sub",
     "c_xor",
     "c_or",
     "c_and",
     "c_subw",
     "c_addw",
     "c_j",
     "c_beqz",
     "c_bnez",
     "c_slli",
     "c_slli64",
     "c_fldsp",
     "c_lwsp",
     "c_flwsp",
     "c_ldsp",
     "c_jr",
     "c_mv",
     "c_ebreak",
     "c_jalr",
     "c_add",
     "c_fsdsp",
     "c_swsp",
     "c_fswsp",
     "c_addiw",
     "c_sdsp",

     // "zbb"
     "clz",
     "ctz",
     "cpop",
     "clzw",
     "ctzw",
     "cpopw",
     "min",
     "max",
     "minu",
     "maxu",
     "sext_b",
     "sext_h",
     "andn",
     "orn",
     "xnor",
     "rol",
     "ror",
     "rori",
     "rolw",
     "rorw",
     "roriw",
     "rev8",  // was bswap

     // "zbp"
     "pack",
     "packh",
     "packu",
     "packw",
     "packuw",
     "grev",
     "grevi",
     "grevw",
     "greviw",
     "gorc",
     "gorci",
     "gorcw",
     "gorciw",
     "shfl",
     "shflw",
     "shfli",
     "unshfl",
     "unshfli",
     "unshflw",
     "xperm_n",
     "xperm_b",
     "xperm_h",
     "xperm_w",

     // "zbs"
     "bset",
     "bclr",
     "binv",
     "bext",
     "bseti",
     "bclri",
     "binvi",
     "bexti",

     // "zbe"
     "bcompress",    // was bext
     "bdecompress",  // Was bdep
     "bcompressw",
     "bdecompressw",

     // "zbf"
     "bfp",
     "bfpw",

     // "zbc"
     "clmul",
     "clmulh",
     "clmulr",

     // "zba"
     "sh1add",
     "sh2add",
     "sh3add",
     "sh1add_uw",
     "sh2add_uw",
     "sh3add_uw",
     "add_uw",
     "slli_uw",

     // "zbr"
     "crc32_b",
     "crc32_h",
     "crc32_w",
     "crc32_d",
     "crc32c_b",
     "crc32c_h",
     "crc32c_w",
     "crc32c_d",

     // "zbm"
     "bmator",
     "bmatxor",
     "bmatflip",

     // "zbt"
     "cmov",
     "cmix",
     "fsl",
     "fsr",
     "fsri",
     "fslw",
     "fsrw",
     "fsriw",

     // "Custom" instructions
     "load64",
     "store64",
     "bbarrier",

     // "vector"
     "vsetvli",
     "vsetivli",
     "vsetvl",

     "vadd_vv",
     "vadd_vx",
     "vadd_vi",
     "vsub_vv",
     "vsub_vx",
     "vrsub_vx",
     "vrsub_vi",

     "vwaddu_vv",
     "vwaddu_vx",
     "vwsubu_vv",
     "vwsubu_vx",
     "vwadd_vv",
     "vwadd_vx",
     "vwsub_vv",
     "vwsub_vx",
     "vwaddu_wv",
     "vwaddu_wx",
     "vwsubu_wv",
     "vwsubu_wx",
     "vwadd_wv",
     "vwadd_wx",
     "vwsub_wv",
     "vwsub_wx",

     "vmseq_vv",
     "vmseq_vx",
     "vmseq_vi",
     "vmsne_vv",
     "vmsne_vx",
     "vmsne_vi",
     "vmsltu_vv",
     "vmsltu_vx",
     "vmslt_vv",
     "vmslt_vx",
     "vmsleu_vv",
     "vmsleu_vx",
     "vmsleu_vi",
     "vmsle_vv",
     "vmsle_vx",
     "vmsle_vi",
     "vmsgtu_vx",
     "vmsgtu_vi",
     "vmsgt_vx",
     "vmsgt_vi",

     "vminu_vv",
     "vminu_vx",
     "vmin_vv",
     "vmin_vx",
     "vmaxu_vv",
     "vmaxu_vx",
     "vmax_vv",
     "vmax_vx",

     "vand_vv",
     "vand_vx",
     "vand_vi",
     "vor_vv",
     "vor_vx",
     "vor_vi",
     "vxor_vv",
     "vxor_vx",
     "vxor_vi",

     "vsll_vv",
     "vsll_vx",
     "vsll_vi",
     "vsrl_vv",
     "vsrl_vx",
     "vsrl_vi",
     "vsra_vv",
     "vsra_vx",
     "vsra_vi",

     "vnsrl_wv",
     "vnsrl_wx",
     "vnsrl_wi",
     "vnsra_wv",
     "vnsra_wx",
     "vnsra_wi",

     "vrgather_vv",
     "vrgather_vx",
     "vrgather_vi",
     "vrgatherei16_vv",

     "vcompress_vm",

     "vredsum_vs",
     "vredand_vs",
     "vredor_vs",
     "vredxor_vs",
     "vredminu_vs",
     "vredmin_vs",
     "vredmaxu_vs",
     "vredmax_vs",
     "vwredsumu_vs",
     "vwredsum_vs",

     "vmand_mm",
     "vmnand_mm",
     "vmandnot_mm",
     "vmxor_mm",
     "vmor_mm",
     "vmnor_mm",
     "vmornot_mm",
     "vmxnor_mm",
     "vpopc_m",
     "vfirst_m",
     "vmsbf_m",
     "vmsif_m",
     "vmsof_m",
     "viota_m",
     "vid_v",

     "vslideup_vx",
     "vslideup_vi",
     "vslide1up_vx",
     "vslidedown_vx",
     "vslidedown_vi",
     "vslide1down_vx",

     "vfslide1up_vf",
     "vfslide1down_vf",

     "vmul_vv",
     "vmul_vx",
     "vmulh_vv",
     "vmulh_vx",
     "vmulhu_vv",
     "vmulhu_vx",
     "vmulhsu_vv",
     "vmulhsu_vx",

     "vmadd_vv",
     "vmadd_vx",
     "vnmsub_vv",
     "vnmsub_vx",
     "vmacc_vv",
     "vmacc_vx",
     "vnmsac_vv",
     "vnmsac_vx",

     "vwmulu_vv",
     "vwmulu_vx",
     "vwmul_vv",
     "vwmul_vx",
     "vwmulsu_vv",
     "vwmulsu_vx",

     "vwmaccu_vv",
     "vwmaccu_vx",
     "vwmacc_vv",
     "vwmacc_vx",
     "vwmaccsu_vv",
     "vwmaccsu_vx",
     "vwmaccus_vx",

     "vdivu_vv",
     "vdivu_vx",
     "vdiv_vv",
     "vdiv_vx",
     "vremu_vv",
     "vremu_vx",
     "vrem_vv",
     "vrem_vx",

     "vsext_vf2",
     "vsext_vf4",
     "vsext_vf8",
     "vzext_vf2",
     "vzext_vf4",
     "vzext_vf8",

     "vadc_vvm",
     "vadc_vxm",
     "vadc_vim",
     "vsbc_vvm",
     "vsbc_vxm",
     "vmadc_vvm",
     "vmadc_vxm",
     "vmadc_vim",
     "vmsbc_vvm",
     "vmsbc_vxm",

     "vmerge_vvm",
     "vmerge_vxm",
     "vmerge_vim",

     "vmv_x_s",
     "vmv_s_x",
     "vfmv_f_s",
     "vfmv_s_f",

     "vmv_v_v",
     "vmv_v_x",
     "vmv_v_i",

     "vmv1r_v",
     "vmv2r_v",
     "vmv4r_v",
     "vmv8r_v",

     "vsaddu_vv",
     "vsaddu_vx",
     "vsaddu_vi",
     "vsadd_vv",
     "vsadd_vx",
     "vsadd_vi",
     "vssubu_vv",
     "vssubu_vx",
     "vssub_vv",
     "vssub_vx",
     "vaaddu_vv",
     "vaaddu_vx",
     "vaadd_vv",
     "vaadd_vx",
     "vasubu_vv",
     "vasubu_vx",
     "vasub_vv",
     "vasub_vx",
     "vsmul_vv",
     "vsmul_vx",
     "vssrl_vv",
     "vssrl_vx",
     "vssrl_vi",
     "vssra_vv",
     "vssra_vx",
     "vssra_vi",
     "vnclipu_wv",
     "vnclipu_wx",
     "vnclipu_wi",
     "vnclip_wv",
     "vnclip_wx",
     "vnclip_wi",

     "vle8_v",
     "vle16_v",
     "vle32_v",
     "vle64_v",
     "vle128_v",
     "vle256_v",
     "vle512_v",
     "vle1024_v",

     "vse8_v",
     "vse16_v",
     "vse32_v",
     "vse64_v",
     "vse128_v",
     "vse256_v",
     "vse512_v",
     "vse1024_v",

     "vlm_v",
     "vsm_v",

     "vlre8_v",
     "vlre16_v",
     "vlre32_v",
     "vlre64_v",
     "vlre128_v",
     "vlre256_v",
     "vlre512_v",
     "vlre1024_v",

     "vs1r_v",
     "vs2r_v",
     "vs4r_v",
     "vs8r_v",

     "vle8ff_v",
     "vle16ff_v",
     "vle32ff_v",
     "vle64ff_v",
     "vle128ff_v",
     "vle256ff_v",
     "vle512ff_v",
     "vle1024ff_v",

     "vlse8_v",
     "vlse16_v",
     "vlse32_v",
     "vlse64_v",
     "vlse128_v",
     "vlse256_v",
     "vlse512_v",
     "vlse1024_v",

     "vsse8_v",
     "vsse16_v",
     "vsse32_v",
     "vsse64_v",
     "vsse128_v",
     "vsse256_v",
     "vsse512_v",
     "vsse1024_v",

     "vloxei8_v",
     "vloxei16_v",
     "vloxei32_v",
     "vloxei64_v",
     "vluxei8_v",
     "vluxei16_v",
     "vluxei32_v",
     "vluxei64_v",

     "vsoxei8_v",
     "vsoxei16_v",
     "vsoxei32_v",
     "vsoxei64_v",
     "vsuxei8_v",
     "vsuxei16_v",
     "vsuxei32_v",
     "vsuxei64_v",

     "vlsege8_v",
     "vlsege16_v",
     "vlsege32_v",
     "vlsege64_v",
     "vlsege128_v",
     "vlsege256_v",
     "vlsege512_v",
     "vlsege1024_v",

     "vssege8_v",
     "vssege16_v",
     "vssege32_v",
     "vssege64_v",
     "vssege128_v",
     "vssege256_v",
     "vssege512_v",
     "vssege1024_v",

     "vlssege8_v",
     "vlssege16_v",
     "vlssege32_v",
     "vlssege64_v",
     "vlssege128_v",
     "vlssege256_v",
     "vlssege512_v",
     "vlssege1024_v",

     "vsssege8_v",
     "vsssege16_v",
     "vsssege32_v",
     "vsssege64_v",
     "vsssege128_v",
     "vsssege256_v",
     "vsssege512_v",
     "vsssege1024_v",

     "vluxsegei8_v",
     "vluxsegei16_v",
     "vluxsegei32_v",
     "vluxsegei64_v",
     "vluxsegei128_v",
     "vluxsegei256_v",
     "vluxsegei512_v",
     "vluxsegei1024_v",

     "vsuxsegei8_v",
     "vsuxsegei16_v",
     "vsuxsegei32_v",
     "vsuxsegei64_v",
     "vsuxsegei128_v",
     "vsuxsegei256_v",
     "vsuxsegei512_v",
     "vsuxsegei1024_v",

     "vloxsegei8_v",
     "vloxsegei16_v",
     "vloxsegei32_v",
     "vloxsegei64_v",
     "vloxsegei128_v",
     "vloxsegei256_v",
     "vloxsegei512_v",
     "vloxsegei1024_v",

     "vsoxsegei8_v",
     "vsoxsegei16_v",
     "vsoxsegei32_v",
     "vsoxsegei64_v",
     "vsoxsegei128_v",
     "vsoxsegei256_v",
     "vsoxsegei512_v",
     "vsoxsegei1024_v",

     "vlsege8ff_v",
     "vlsege16ff_v",
     "vlsege32ff_v",
     "vlsege64ff_v",
     "vlsege128ff_v",
     "vlsege256ff_v",
     "vlsege512ff_v",
     "vlsege1024ff_v",

     "vfadd_vv",
     "vfadd_vf",
     "vfsub_vv",
     "vfsub_vf",
     "vfrsub_vf",

     "vfwadd_vv",
     "vfwadd_vf",
     "vfwsub_vv",
     "vfwsub_vf",

     "vfwadd_wv",
     "vfwadd_wf",
     "vfwsub_wv",
     "vfwsub_wf",

     "vfmul_vv",
     "vfmul_vf",
     "vfdiv_vv",
     "vfdiv_vf",
     "vfrdiv_vf",
     "vfwmul_vv",
     "vfwmul_vf",

     "vfmadd_vv",
     "vfmadd_vf",
     "vfnmadd_vv",
     "vfnmadd_vf",
     "vfmsub_vv",
     "vfmsub_vf",
     "vfnmsub_vv",
     "vfnmsub_vf",

     "vfmacc_vv",
     "vfmacc_vf",
     "vfnmacc_vv",
     "vfnmacc_vf",
     "vfmsac_vv",
     "vfmsac_vf",
     "vfnmsac_vv",
     "vfnmsac_vf",

     "vfwmacc_vv",
     "vfwmacc_vf",
     "vfwnmacc_vv",
     "vfwnmacc_vf",
     "vfwmsac_vv",
     "vfwmsac_vf",
     "vfwnmsac_vv",
     "vfwnmsac_vf",

     "vfsqrt_v",

     "vfmerge_vfm",
     "vfmv_v_f",

     "vmfeq_vv",
     "vmfeq_vf",
     "vmfne_vv",
     "vmfne_vf",
     "vmflt_vv",
     "vmflt_vf",
     "vmfle_vv",
     "vmfle_vf",
     "vmfgt_vf",
     "vmfge_vf",

     "vfclass_v",

     "vfcvt_xu_f_v",
     "vfcvt_x_f_v",
     "vfcvt_rtz_xu_f_v",
     "vfcvt_rtz_x_f_v",
     "vfcvt_f_xu_v",
     "vfcvt_f_x_v",

     "vfwcvt_xu_f_v",
     "vfwcvt_x_f_v",
     "vfwcvt_rtz_xu_f_v",
     "vfwcvt_rtz_x_f_v",
     "vfwcvt_f_xu_v",
     "vfwcvt_f_x_v",
     "vfwcvt_f_f_v",
     
     "vfncvt_xu_f_w",
     "vfncvt_x_f_w" ,
     "vfncvt_rtz_xu_f_w",
     "vfncvt_rtz_x_f_w" ,
     "vfncvt_f_xu_w",
     "vfncvt_f_x_w" ,
     "vfncvt_f_f_w",
     "vfncvt_rod_f_f_w",

     "vfredsum_vs",
     "vfredosum_vs",
     "vfredmin_vs",
     "vfredmax_vs",
     "vfwredsum_vs",
     "vfwredosum_vs",

     "vfrsqrt7_v",
     "vfrec7_v",

     "vfmin_vv",
     "vfmin_vf",
     "vfmax_vv",
     "vfmax_vf",

     "vfsgnj_vv",
     "vfsgnj_vf",
     "vfsgnjn_vv",
     "vfsgnjn_vf",
     "vfsgnjx_vv",
     "vfsgnjx_vf"

    
    };
	std::ofstream outfile;
	outfile.open("decodeall.log");
	for(uint32_t inst=0; inst<0xffff; inst++) {
		auto instId = hart.getInstId(inst);
		bool issLegal = instId != InstId::illegal and instId!=InstId::load64 and instId != InstId::store64 and instId != InstId::bbarrier;
		bool rtlLegal = rtlIsLegalOpcode(inst);
		if(issLegal!=rtlLegal) {
			outfile << "Mismatch " << std::hex << inst << " iss: " << instIdToNames[unsigned(instId)] <<" rtl: " << rtlLegal << "\n";
			std::cout << "Mismatch " << std::hex << inst << " iss: " << instIdToNames[unsigned(instId)] <<" rtl: " << rtlLegal << "\n";

		}

	}
	for(uint32_t inst=0xffff+4; inst<0xffffffff; inst+=4) {
		auto instId = hart.getInstId(inst);
		bool issLegal = instId != InstId::illegal and instId!=InstId::load64 and instId != InstId::store64 and instId != InstId::bbarrier;
		bool rtlLegal = rtlIsLegalOpcode(inst);
		if(issLegal!=rtlLegal) {
			outfile << "mismatch " << std::hex << inst << " iss: " << instIdToNames[unsigned(instId)] <<" rtl: " << rtlLegal << "\n";
			std::cout << "mismatch " << std::hex << inst << " iss: " << instIdToNames[unsigned(instId)] <<" rtl: " << rtlLegal << "\n";
		}

	}
	outfile.close();
}


template void WdRiscv::Interactive<uint32_t>::runAllOpcodes(Hart<uint32_t>& hart);
template void WdRiscv::Interactive<uint64_t>::runAllOpcodes(Hart<uint64_t>& hart);
