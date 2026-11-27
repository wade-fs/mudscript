// clone/npc/square_storyteller.c
// 瞎子陳・說書盲叟 (square_storyteller) - 中央青石廣場 (Ch.43-82)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("瞎子陳");
    set_short(YEL "青石廣場說書盲叟" NOR " 瞎子陳");
    set_long("一位雙目失明、手敲梨花竹板與醒木的白鬚老叟，在中央廣場古槐樹下擺攤講古。\n"
             "從三十年前的大乾動亂到六縣奇聞、三大道統秘辛，無不在他的醒木起落之間。\n");
    set_id(({ "square_storyteller", "xiazi chen", "storyteller", "瞎子陳", "說書盲叟", "盲叟" }));

    setup_archetype("J", 10);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "info" }));
    set("schedule", "day");

    add_response(({ "講古", "三大道統", "金石城" }),
        "瞎子陳一拍醒木，朗聲唱道：「話說那八百里落龍古脈環抱金石府，西有宣道司觀星借法，東有八方館淬骨開山，北有百工坊巧奪天工，南有金石商會富甲六縣——殊不知這青石板底下，還壓著萬年前大清洗的太古廢墟哩！」");
}

int do_chat(object me, string topic) {
    if (topic && (topic == "傳聞" || topic == "消息" || topic == "風聲" || topic == "流言" ||
                  topic == "商隊" || topic == "礦難" || topic == "通寶" || topic == "六縣")) {
        object rumor_d = load_object(RUMOR_D);
        if (rumor_d) {
            string q_top = (topic == "傳聞" || topic == "消息" || topic == "風聲" || topic == "流言") ? "caravan" : topic;
            mapping rd = rumor_d->query_distorted_rumor(q_top, me);
            if (mapp(rd) && rd["display_msg"]) {
                tell_object(me, "瞎子陳一敲梨花醒木，壓低聲音對你說道：\n" + rd["display_msg"] + "\n");
                return 1;
            }
        }
    }
    return ::do_chat(me, topic);
}
