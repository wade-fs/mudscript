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

    set_touch("default", WHT "鉛封鐵箱冰冷沉重得異常，貼著的雙層火漆封條邊緣乾燥脆硬。" NOR);
    set_smell("default", MAG "厚重鉛門內側封存著淡淡松脂火漆味與壓抑不住的隱隱血精礦腥氣。" NOR);
    set_listen("default", WHT "密閉庫房內死寂無聲，唯有鉛封鐵箱深處彷彿有極微弱的低頻嗡動。" NOR);

    mapping inspect_rule = ([
        "targets": ({ "box", "seal", "鐵箱", "封條", "工單", "" }),
        "sp_cost": 5,
        "sensory_msg": HIY "你逐字細讀《特殊工單》上的私印火漆與三方聯署封條，確認此箱未經會審絕不可擅拆。" NOR,
        "train_stat": ([ "per": 8 ]),
        "exp_gain": 10
    ]);
    add_action_rule("inspect", inspect_rule);
    add_action_rule("驗封條", inspect_rule);
}
