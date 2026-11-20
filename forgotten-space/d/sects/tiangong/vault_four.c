// /d/sects/tiangong/vault_four.c
// 天工閣・萬機四號庫房 (Ch.95：魯長老與監察文吏會同封存之血精晶柱鉛封箱)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("天工閣・萬機四號庫房");
    set_long("萬機地窟東側加設厚重鉛門的備品封存庫房。角落石台上落著一只貼了魯長老與兩名\n"
             "監察文吏聯合封條的沉重鉛封鐵箱——裡頭封存著赤煉長老企圖強塞進巨靈神機動力槽的\n"
             "六根尺許長「高純度地煞血精晶柱」，旁壓一張蓋有私人火漆的《特殊工單》。\n"
             "向西退回【萬機地窟】。\n");

    set_exits(([
        "west": "/d/sects/tiangong/machinery_depths.c",
    ]));

    set("is_outdoor", 0);
}
