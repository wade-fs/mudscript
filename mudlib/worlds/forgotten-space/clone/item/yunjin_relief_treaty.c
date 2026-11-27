// /clone/item/yunjin_relief_treaty.c
// 《雲津萬山臨時互市與救濟協約》暨五份忠烈歸籍憑證抄本（第三卷 Ch.120）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("雲津臨時互市與救濟協約", ({ "yunjin_relief_treaty", "relief_treaty", "雲津新約", "互市救濟協約" }));
    set_short(HIW "三宗掌門聯署・《雲津萬山臨時互市與救濟協約》" NOR);
    set_long("劫後第七日經兩日兩夜議事簽署、由三宗掌門與羅九秤聯署蓋印之正式改革協約抄本，附帶：\n"
             "一、八荒鐵背山主頒予韓素一行五份加印《忠烈歸籍與撫恤憑證》（韓林入刻黑山烈士碑）；\n"
             "二、《三十年前舊商盟除名案初步平反文書》（雲記恢復名分，高層簽字責任鏈仍留白待填）；\n"
             "三、泥途商棧取得三宗外門大宗採買透明查帳席位，及改組西街空倉試辦合法無毒炭料回收廠之條約。\n");
    set_weight(240);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "conclusive");
}
