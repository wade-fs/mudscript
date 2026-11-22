// /d/wastes/black_ice_valley.c
// 黑冰斷谷・走山絕谷主遺址（Ch.104：五年前爆破塌山現場、九具遺骸與韓林「乙十七」銅哨）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北荒裂谷・黑冰斷谷");
    set_long("群山腹地內被萬年厚冰完全封死的凹陷絕谷，完全無風死寂，地上散布著百餘步人工\n"
             "爆破崩落的碎岩與半掩於冰面下的九具人類遺骸——其中兩具著八荒武山殘破巡哨皮甲，\n"
             "胸口赫然插著三支制式破甲鐵弩箭，一具頸間掛著生出綠鏽的「北線斥候・乙十七」銅哨\n"
             "（仔細勘驗並雙人簽字編號遺物：excavate remains）。\n"
             "沿垂降麻繩向上爬回【墨黑雪壁垂降崖】，往西踏進【舊勘探隊營地廢墟】。\n");

    set_exits(([
        "up":   "/d/wastes/rift_watch.c",
        "west": "/d/wastes/old_expedition_camp.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIW "萬年黑冰表面光滑如鏡、寒氣透過鞋底直透骨髓，青銅哨遺物表面覆著薄霜與綠鏽。" NOR);
    set_smell("default", CYN "完全封閉的死寂冰谷裡只有陳年凍血微腥與人工爆破崩岩留下的冷淡硫磺殘氣。" NOR);
    set_listen("default", WHT "此處無風無鳥獸，寂靜得彷彿能聽見自己心跳與冰層深處偶爾傳來的「喀」一聲微裂。" NOR);
}

void init() {
    ::init();
    add_action("do_excavate", "excavate");
}

int do_excavate(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "remains" && arg != "whistle" && arg != "遺骸" && arg != "銅哨") {
        notify_fail("你想勘驗什麼？試試：excavate remains\n");
        return 0;
    }
    message_vision("$N蹲下繪出九具遺骸確切方位，取小木盒妥善收起頸間「北線斥候・乙十七」銅哨\n"
                   "與三支制式破甲鐵弩箭簇，並清點確證九具屍骨中並無燕隼大伯燕山。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "excavate", "target": "remains" ]));
    }
    return 1;
}
