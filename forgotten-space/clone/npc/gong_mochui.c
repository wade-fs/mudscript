// clone/npc/gong_mochui.c
// 千錘地爐坊大師 莫錘 (gong_forge_mochui)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("莫錘");
    set_short(HIR "鍛造大師" NOR " 莫錘");
    set_long("一位上身精赤、揮舞著六十斤精鋼重錘的赤面壯漢。\n"
             "地爐烈火熊熊倒映在他眼中，身後堆疊著來自烈礬縣的粗銅錠與重石縣生鐵。\n");
    set_id(({ "gong_forge_mochui", "mochui", "mo chui", "blacksmith", "莫錘", "莫大師", "鍛造大師" }));

    setup_archetype("E", 40);
    set("class", "gong_initiate");
    set("faction", "gong");
    set("roles", ({ "trainer", "quest_target" }));
    set("schedule", "24h");

    set_skill_to_teach("gong_analysis", 100);
    set_skill_to_teach("gong_qiaojin", 100);
    set_skill_to_teach("gong_yingli", 100);
    set_skill_to_teach("gong_cuihuo", 100);

    add_response(({ "辨材", "摸骨", "考核", "礦石", "鍛造" }),
        "莫錘粗聲道：「閉上眼睛摸！用心感受烈礬赤銅的滑膩與重玄鐵礦的沉澀！能盲辨生鐵核，方具開爐鍛造之基。」");

    add_response(({ "校準", "百工", "初試", "五百針", "匠帖" }),
        "莫錘沉聲喝道：「好小子！單手持錘砸落五百發平頭鋼針，無一彎折！這份手勁與公差感知，當得起我百工總會外門匠師之名！這張【百工初階匠帖】歸你了！」");

    add_response(({ "耐火泥", "烈礬", "出貨單", "工料" }),
        "莫錘端詳著單據上的金蓮環刀印，冷哼一聲：「這正是商會內堂專用印！三個月前提領三萬斤烈礬特級耐火白泥，私造坩堝私煉血精……此單即是鐵證！」");

    add_response(({ "金剛砂", "倒灌", "淹庫", "油泥" }),
        "莫錘握緊鐵鉗怒喝道：「酸洗出來的八角形尖銳細砂，正是商會內堂專用的烈礬特級金剛砂！錢百川蓄意卡死外閘倒灌暗渠，就是要以水代火泡爛地下密室的底單！」");

    add_response(({ "心眼", "格物", "精金", "破障" }),
        "莫錘大師撫著鐵錘哈哈大笑：「好小子！不借外尺、自開心眼！以心為尺、以骨為砧，這精金淬體一成，世間再難的金鐵也難不住你林鐵生了！」");
}

int do_chat(object me, string topic) {
    if (!me || !topic || topic == "") return 0;
    if (string_in(topic, "辨材, identify, 考核, test")) {
        object q_engine = load_object(QUEST_ENGINE_D);
        if (q_engine) {
            return q_engine->trigger_quest_event(me, "talk", ({ "gong_forge_mochui", "辨材" }));
        }
    }
    return 0;
}
