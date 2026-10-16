// d/village/mine_depths.c
// 黑石古礦・地下崩塌坑道 (小說第13、14章核心場景)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑石古礦・地下崩塌坑道");
    set_long("此處深懸於黑石斷崖地下百米，漆黑沉重，四周瀰漫著濃烈的硫磺焦臭與\n"
             "暗紫色的地煞毒煙。腳下烏黑的鐵軌已被萬鈞落石扭曲成麻花狀，\n"
             "前方被一堵兩丈高的巨型黑玄石壁死死截斷。\n"
             "石縫深處隱隱透出微弱的震動，若伏地傾聽 (listen)，或許能辨識其中的生機；\n"
             "右下角嵌著一塊三尺厚的【斷龍卡隼石】(tenon stone)，可嘗試以鋼鑿破石 (strike stone)。\n"
             "向上順著生鐵索具可攀回礦道口 (up)。\n");

    set_exits(([
        "up": "/d/village/mine.c",
    ]));

    set("is_underground", 1);
}

void init() {
    ::init();
    add_action("do_listen", "listen");
    add_action("do_listen", "聽風");
    add_action("do_listen", "傾聽");
    add_action("do_strike", "strike");
    add_action("do_strike", "破石");
    add_action("do_strike", "開道");
    add_action("do_strike", "鑿石");
}

int do_listen(string arg) {
    object me = this_player();
    if (!me) return 0;

    write(CYN "你屏住呼吸，整個人伏在冰冷黏滑的黑鐵軌道旁，將耳朵死死貼進岩壁裂縫深處……\n" NOR);
    write(HIY "「噹——噹——噹——！噹！噹！」\n" NOR);
    write(HIG "【暗號傳音】極遠處傳來清脆而富有節奏的鋼鎬敲軌聲——三長兩短！\n" +
              "那正是老礦工魯大山獨門的採礦暗號！被困的二十三名老礦工果然退守在地煞避風穹頂！\n" NOR);
    write(WHT "然而岩縫中噴湧的地煞紫霧愈發濃烈，時間緊迫，必須儘快擊碎斷龍卡隼石 (strike stone)！\n" NOR);

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([
            "verb": "listen"
        ]));
    }
    return 1;
}

int do_strike(string arg) {
    object me = this_player();
    if (!me) return 0;

    if (arg && arg != "stone" && arg != "卡隼石" && arg != "巨石" && arg != "斷龍卡隼石") {
        write("你要鑿擊什麼？用法：strike stone 或 破石\n");
        return 1;
    }

    object chisel = present("steel chisel", me);
    if (!chisel) chisel = present("chisel", me);
    if (!chisel) chisel = present("玄鐵鋼鑿", me);
    if (!chisel) chisel = present("smith hammer", me);

    if (!chisel) {
        write(HIR "你赤手空拳，如何破得開這萬斤沉鐵黑玄石？\n" +
              "（你需要前往鐵匠鋪向阿鐵取得【百煉破煞玄鐵鋼鑿】）\n" NOR);
        return 1;
    }

    if (me->query(VITAL_KEE) < 15 || me->query(VITAL_SP) < 10) {
        write(HIR "你氣血虛弱、雙臂發麻，已無力掄動沉重的百煉鋼鑿了！\n" NOR);
        return 1;
    }

    me->add(VITAL_KEE, -15);
    me->add(VITAL_SP, -10);

    write(HIB "你雙手扣緊百煉破煞玄鐵鋼鑿，將冰冷的鑿尖精準抵入斷龍卡隼石的石眼死穴！\n" NOR);
    write(YEL "你沉腰扎馬，周身氣血如太古地爐般狂暴運轉，剛猛霸道的螺旋暗勁順著鑿身狠狠轟入！\n" NOR);
    write(HIR "「轟隆隆隆————！！」\n" NOR);
    write(HIY "伴隨著一聲驚天動地的巨響，三尺厚的卡隼石轟然爆碎！無數滾落的黑玄巨石順著排沙暗渠向兩側滑開，\n" +
              "硬生生在封死的石壁深處露出一道可供一人爬行的狹窄通風暗道！\n" NOR);

    me->train_stat(STAT_STR, 30);
    me->train_stat(STAT_CON, 20);
    me->gain_exp(30);

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([
            "verb": "strike",
            "target": "stone"
        ]));
    }
    return 1;
}
