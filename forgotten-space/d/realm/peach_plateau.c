// /d/realm/peach_plateau.c
// Tier 3 桃花源洞天初臨地・荒蕪碎石高原 (Ch.126 第三卷大結局：非仙境而見三座太古巨構對峙)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("桃花源洞天・荒蕪碎石高原");
    set_long("預想中的十里桃花、靈泉仙鶴俱無半點蹤影——頭頂是一片詭異暗鐵青色、彷彿永遠\n"
             "停格於黎明前最壓抑時刻的巨大靜止天穹，不見熟悉日星與二十八宿，空氣冰冷稀薄。\n"
             "狂風捲著砂礫掠過腳下枯死如鐵絲般的灰白草叢與無盡灰褐碎石高原；遙望荒野邊緣\n"
             "隱現數點孤零幽冷燈火與灰黑煙塵。地平線三個極端盡頭，相隔不知幾萬里巍然矗立著\n"
             "三座高聳入雲、無聲對峙的太古巨構輪廓——可凝神遠眺方位（gaze horizon）。\n"
             "（※ 單向古陣已因身後雷劫崩毀無歸途；若欲暫以神識回溯人間據點測試可輸入 vision return。）\n");

    set_exits(([]));
    set("is_outdoor", 1);
}

void init() {
    ::init();
    add_action("do_gaze", "gaze");
    add_action("do_vision", "vision");
}

int do_gaze(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (!arg || arg == "") arg = "horizon";
    tell_object(me, HIY
        "【異界洞天地平線初窺（第四卷前瞻）】\n"
        "・正北雲霧高空——【太虛神宮】：懸浮於高天、通體純白星輝玉石築成，散發令神魂幾乎自行跪拜臣服的冰冷秩序威壓。\n"
        "・西南焦土裂谷——【戰祖魔殿】：巨獸白骨與暗紅玄鐵堆疊而成，時刻似有洪荒凶煞血氣自焦黑裂谷騰湧翻滾。\n"
        "・正東無邊荒漠——【萬物主機城】：閃爍億萬道青金幾何電路與無數巨型轉動齒輪，發出大地亦為之震顫的低頻轟鳴。\n"
        "握緊百斤鐵胎弓、小鍛錘、藥囊與微溫的【天門引】，無論門後是避難所抑或更深囚籠，這筆帳正要從第一頁算起。\n" NOR);
    return 1;
}

int do_vision(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "return" && arg != "mortal") {
        notify_fail("單向古陣已無實體歸途；若以測試神識返回雲津總號請用：vision return\n");
        return 0;
    }
    object dst = load_object("/d/yunjin/mudway_store.c");
    if (dst) {
        tell_object(me, CYN "你以一縷神識記憶暫返雲津【萬山泥途總號】查閱人間留守帳冊……\n" NOR);
        me->move(dst);
    }
    return 1;
}
