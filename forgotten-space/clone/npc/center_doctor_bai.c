// clone/npc/center_doctor_bai.c
// 杏林醫館館主 白先生 (clinic_baixiansheng) - 濁氣清心散、試藥童緩衝路徑 C

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("白先生");
    set_short(HIG "杏林醫館館主" NOR " 白先生");
    set_long("一位身披白葛長衫、面容慈和的老名醫，身上散發著洗靈草與艾葉的清香。\n"
             "他精通大荒草藥分診與經脈行針，常年配製【清心散】為城中修士百姓清除紅塵濁氣。\n");
    set_id(({ "clinic_baixiansheng", "doctor_bai", "bai xiansheng", "baixiansheng", "physician", "白先生", "醫館館主" }));

    setup_archetype("F", 28);
    set("class", "gong_initiate");
    set("faction", "folk");
    set("roles", ({ "shop", "service", "quest_giver", "trainer" }));
    set("rules", ([ "cleanse_turbidity": 20, "daily_limit": 3, "buffer_days": 10 ]));
    set("schedule", "24h");

    set_skill_to_teach("gong_analysis", 100);
    set_skill_to_teach("gong_xingzhen", 100);
    set_skill_to_teach("gong_fengdu", 100);

    add_response(({ "濁氣", "清心散", "買藥", "診斷", "會診" }),
        "白先生把脈道：「市井七情沉澱為紅塵濁氣，侵蝕心神靈台。老夫親手配製之【清心散】(buy pill, 50文) 每劑可清二十點濁氣，每日至多三服。」");

    add_response(({ "試藥", "藥囊", "腰牌", "緩衝", "身分" }),
        "白先生撫鬚道：「初來都城若是無處落腳，可在醫館晾曬藥草、充任試藥童。老夫可授你【杏林藥囊腰牌】，保你十日合法居留。」");
}

int do_chat(object me, string topic) {
    if (!me || !topic || topic == "") return 0;
    if (string_in(topic, "試藥, apprentice, 藥囊, 身分")) {
        if (!present("clinic token", me) && !present("yaonang", me)) {
            object token = clone_object("/clone/item/clinic_token.c");
            if (token) {
                token->move(me);
                tell_object(me, HIG "【白先生微笑點頭，贈予你一只《杏林藥囊腰牌》以作合法憑證（+10天合法期）！】\n" NOR);
                return 1;
            }
        } else {
            tell_object(me, YEL "白先生道：「你已有藥囊腰牌在身，好生研習草木物性。」\n" NOR);
            return 1;
        }
    }
    return 0;
}

void init() {
    ::init();
    add_action("do_buy", "buy");
    add_action("do_buy", "買");
}

int do_buy(string arg) {
    object me = this_player();
    if (!arg || (arg != "pill" && arg != "清心散" && arg != "散")) {
        write("你想購買什麼藥物？(buy pill - 50文一包)\n");
        return 1;
    }

    if (me->query("money") < 50) {
        write("你的銅錢不足（需要 50 文錢）。\n");
        return 1;
    }

    me->add_money(-50);
    object pill = clone_object("/clone/item/turbidity_pill.c");
    if (pill) {
        pill->move(me);
        tell_object(me, HIG "【白先生收下五十文錢，將一包清澈的杏林清心散交給了你！】\n" NOR);
    }
    return 1;
}
