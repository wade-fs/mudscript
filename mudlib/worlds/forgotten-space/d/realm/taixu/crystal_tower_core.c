// /d/realm/taixu/crystal_tower_core.c
// 太虛神宮・靜謐玉化晶核塔 (Ch.136 活體晶核真相 / Ch.164 歸墟深碑警報)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太虛神宮・靜謐玉化晶核塔");
    set_long("無聲無息的高塔內壁嵌滿了上百龕半透明玉石龕位，每一龕中皆靜立著一尊早已失去體溫、\n"
             "神識徹底玉化凝結的昔年飛升修士晶核，宛如一排排替天羅供能的冷白燭台。\n"
             "最深處崩裂的核心碑座夾層露出一段比太虛更古老的幽暗刻文，可上前查驗（inspect core）。\n"
             "向南退返【三百年校準偏殿】。\n");

    set_exits(([
        "south" : "/d/realm/taixu/calibration_hall.c",
    ]));
    set("is_outdoor", 0);

    set_touch("default", WHT "玉石龕壁毫無生人溫度，唯有底層核心碑座邊緣隱約傳來跨越萬古的極微震顫。" NOR);
    set_smell("default", HIW "死寂無塵的冷玉寒氣裡，隱含陳年凝脂與被抽乾神識後的枯槁塵味。" NOR);
    set_listen("default", HIB "塔內靜得連心跳都顯刺耳，只有核心深碑夾層偶爾傳出極低頻的警報微鳴。" NOR);
}

void init() {
    ::init();
    add_action("do_inspect", "inspect");
}

int do_inspect(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "core" && arg != "stele" && arg != "晶核") {
        notify_fail("你要查驗什麼？試試：inspect core\n");
        return 0;
    }

    tell_object(me, HIR
        "【玉化晶核實證與歸墟深碑警報（EV420）】\n"
        "你在這座高塔裡看見歷代失蹤先輩的真實終局——所謂白日飛升，不過是化作陣眼晶核。\n"
        "而在崩裂核心碑座夾層，一行更古老的銘文悄然亮起：\n"
        "『太古三元總樞・歸墟古淵深層盟約：若三極均衡遭外力長期停擺，十個歲象後自行啟動強制清算。』\n" NOR);
    say(me->query_name() + " 凝視玉化晶核與崩裂深碑夾層，神色驟然沉重。\n");

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "inspect", "target": "core" ]));
    }
    return 1;
}
