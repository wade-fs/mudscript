// /clone/npc/ji_heng.c
// 季衡・天工閣萬機地窟值守匠師 (ji_heng) - 萬機地窟 (Ch.95)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("季衡");
    set_short(HIY "萬機地窟值守匠師" NOR " 季衡");
    set_long("三十一歲的謹慎匠師，手裡永遠緊抱著一本《地窟安全閘巡檢簿》，熟悉地窟每一條吊軌與\n"
             "壓力閥門。他對太古神機抱持技術敬畏，堅信未知原理之前絕不可強插高能晶柱試車。\n");
    set_id(({ "ji_heng", "ji heng", "jiheng", "季衡", "值守匠師" }));

    setup_archetype("E", 70);
    set("class", "gong");
    set("faction", "tiangong");
    set("roles", ({ "artisan", "warden", "quest" }));
    set("home_room", "/d/sects/tiangong/machinery_depths.c");

    add_response(({ "維護", "巨靈神機", "機件檢修", "萬機地窟" }),
        "季衡按著《地窟安全閘巡檢簿》，神色嚴肅地清點雙人批令：「按天工祖訓，內門弟子僅准對外部防塵甲片\n"
        "與次級聯動輪清灰上油（指令：inspect core）；未取得長老聯署雙印與風險評估單前，絕不得擅拆中心黑色大軸！\n"
        "這個月主軸已經自己出現過三次微弱脈衝震動，誰敢輕率亂接能源？」");

    add_response(({ "脆化麻點", "晶柱", "血精", "赤煉" }),
        "季衡抹了一把額角冷汗：「上次試壓拆檢時，凡接觸過『暗紅高能晶柱』的次級銅管內壁全出現嚴重脆化麻點！\n"
        "若按赤煉長老那張特殊工單強行塞入六根高純度晶柱，恐怕整座萬仞天工山的地肺火脈都會跟著炸塌！」");

    add_response(({ "黑鐵結構", "方舟", "冷卻管線" }),
        "季衡指尖撫過卡尺誤差讀數，難掩震驚：「你從萬丈地底方舟主導管測回的齒牙雙曲線倒角結構，\n"
        "竟與咱們地窟裡這尊【巨靈神機】分毫不差——看來這尊老古董果然只是一艘太古破界方舟右翼下方的一座輔助推進錨機！」");
}
