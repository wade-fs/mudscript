// /d/sects/taiqing/ascension_platform.c
// 太清偏峰・升仙台石築靈堂 (Ch.92：鶴鳴真人玉化真相與聚星抽取陣紋)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太清偏峰・升仙台石築靈堂");
    set_long("偏峰懸崖頂端高大森嚴的封閉石築靈堂，門外三十步處置有一方安放測算盤的石台。\n"
             "罡風呼嘯掠過青色雲錦帷幕一角，地下三條主聚星陣紋正隱隱反過來將靈堂中央那尊\n"
             "人形淡青半透明晶石雕像的殘存靈流抽往九天高處——這便是官方宣稱「功德圓滿飛升」\n"
             "的 Lv.92 鶴鳴真人真身。雪縫裡偶見風震滑落的碎屑（指令：collect crystal）。\n"
             "向南沿積雪石階下返【清修偏峰】。\n");

    set_exits(([
        "south": "/d/sects/taiqing/quiet_peak.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIW "升仙台寒玉石階冷得幾乎粘手，雪縫裡滾落的晶體碎屑銳利冰寒如碎冰。" NOR);
    set_smell("default", HIC "極高寒峰頂沒有半點草木塵氣，唯有一股近乎抽空肺腑的清冽高空雪氣。" NOR);
    set_listen("default", WHT "雲海罡風在石築靈堂四角發出空靈長嘯，靈堂深處彷彿萬籟俱寂。" NOR);

    spawn_npc("/clone/npc/xuan_ming.c");
}

void init() {
    ::init();
    add_action("do_collect", "collect");
}

int do_collect(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "crystal" && arg != "晶屑" && arg != "道化晶石") {
        notify_fail("你想採集什麼樣本？試試：collect crystal\n");
        return 0;
    }
    message_vision("$N藉罡風吹倒測算盤之掩護伏下身去，悄無聲息將滾落石台積雪縫隙裡的\n"
                   "米粒大淡青色晶體碎屑夾入蠟封小木盒，同時記下主聚星陣紋倒抽靈力的流向！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "collect", "target": "crystal" ]));
    }
    return 1;
}
