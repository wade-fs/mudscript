// clone/npc/caravan_yard_manager.c
// 蘇忠・蘇氏舊部商隊大掌櫃 (caravan_yard_manager) - 遠行車馬大院

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("蘇忠");
    set_short(CYN "商隊大掌櫃" NOR " 蘇忠");
    set_long("一位鬢角微霜、神色堅毅沉穩的老掌櫃，原為已故商會大掌櫃蘇遠山的授業義弟與舊部總管。\n"
             "蘇遠山在黑石鋪遇害後，他率蘇氏嫡系車馬行退守遠行車馬大院，暗中接應大小姐蘇凝霜與持有蘇氏信印的義士。\n");
    set_id(({ "caravan_yard_manager", "su zhong", "suzhong", "caravan manager", "蘇忠", "商隊大掌櫃" }));

    setup_archetype("H", 28);
    set("class", "mortal");
    set("faction", "shanghui");
    set("roles", ({ "quest_giver", "broker", "info" }));
    set("schedule", "24h");

    add_response(({ "蘇凝霜", "蘇遠山", "信印", "商隊", "錢百川" }),
        "蘇忠虎目含淚，壓低聲音道：「老主公在黑石鋪遭趙德貴暗算，總堂如今被副會長錢百川一手遮天！好在大小姐手握【天字總司大印】，凡持大小姐信印或保書來此者，我車馬行上下萬死不辭！」");

    add_response(({ "短褐", "腰牌", "苦力", "身分", "緩衝", "擔保" }),
        "蘇忠點頭道：「初入府城無依無靠者，若通曉些拳腳力氣或懂修車驗軸，可在車馬院領一塊【車馬行短褐腰牌】，保你七日合法居留，免遭官差當作流民緝拿。」");
}

int do_chat(object me, string topic) {
    if (!me || !topic || topic == "") return 0;
    if (string_in(topic, "短褐, caravan, 腰牌, 苦力, 身分, 擔保")) {
        if (!present("caravan token", me) && !present("badge", me)) {
            object token = clone_object("/clone/item/caravan_token.c");
            if (token) {
                token->move(me);
                tell_object(me, HIG "【蘇忠拍了拍你的肩膀，遞給你一塊《車馬行短褐腰牌》（+7天合法居留期）！】\n" NOR);
                return 1;
            }
        } else {
            tell_object(me, YEL "蘇忠道：「你已有車馬行腰牌在身，在南關行走安心當差即可。」\n" NOR);
            return 1;
        }
    }
    return 0;
}
