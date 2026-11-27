// clone/npc/folk/route_traveler.c
// 跨縣官道挑夫／車馬趟子手（自動讀取所在路段資訊並回饋氣候與路況） (Ch.39-119)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("趕路趟子手");
    set_short(YEL "商隊" NOR " 趕路趟子手");
    set_long("一位小腿綁著厚麻布綁腿、肩扛扁擔或腰別短棍的車馬趟子手。\n"
             "他長年奔波在金石府城與六縣山道之間，對哪段路泥濘、哪段棧道禁重車一清二楚。\n");
    set_id(({ "route_traveler", "traveler", "porter", "carter", "趕路趟子手", "趟子手", "挑夫", "行商" }));

    setup_archetype("D", 9);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "info" }));

    add_response(({ "官道", "商道", "歇腳" }),
        "趟子手解下水囊灌了一大口冷水：「跑這條大荒山道，最怕的不是野獸，而是天時突然變臉！泥石流一堵路，這車貨全得爛在半途。」");
    add_response(({ "磨刀", "弓弦", "營務", "巡哨" }),
        "正在通鋪裡烤火的旅人點點頭：「這外營武卒的刀口早該用羊油磨一磨啦（sharpen blade），刃利了夜裡巡哨才心安。」");
    add_response(({ "借火", "火種", "取暖" }),
        "趕路趟子手搓著凍紫的雙手呼出一口白氣：「夜風把濕柴全吹熄了，麻煩搭把手用松脂點起這堆官驛篝火 (kindle fire)，大家也好烤乾綁腿！」");
    add_response(({ "車輪", "修輪", "斷軸" }),
        "趟子手皺眉指著歪斜的重車木輪：「方才壓過青石坑斷了兩根棗木輻條，幫我把備用輻條敲進輪轂別好鐵銷 (mend wheel) 罷！」");
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    object env = environment(this_object());
    mapping seg = env ? env->query_segment_info() : 0;

    if (topic == "路況" || topic == "前方" || topic == "這裡" || topic == "危險") {
        if (mapp(seg)) {
            tell_object(me, query_name() + sprintf(" 望著前方路勢道：「這裡是『%s』（全長 %d 里，%s）。平時%s，最要小心『%s』，還有別忘記：%s！」\n",
                seg["name"], seg["distance_li"], seg["travel_mode"], seg["normal_duration"],
                seg["risk"], seg["seasonal_block"]));
            return 1;
        }
    }

    return ::do_chat(me, topic);
}
