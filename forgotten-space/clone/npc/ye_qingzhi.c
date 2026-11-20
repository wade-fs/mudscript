// /clone/npc/ye_qingzhi.c
// 葉青枝・丹鼎宗百草谷靈植管事 (ye_qingzhi) - 百毒試藥谷暨百草谷 (Ch.89)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("葉青枝");
    set_short(GRN "百草谷靈植管事" NOR " 葉青枝");
    set_long("三十八歲的女藥農管事，捲著褲腳，指甲縫裡常年帶著黑褐色的泥土痕跡。\n"
             "她極為熟悉山地水源、菌根共生與靈植輪作，對近期藥田水脈異常下降心懷深深憂慮。\n");
    set_id(({ "ye_qingzhi", "ye qingzhi", "qingzhi", "葉青枝", "靈植管事" }));

    setup_archetype("F", 56);
    set("class", "gong");
    set("faction", "danding");
    set("roles", ({ "gardener", "herbalist", "quest" }));
    set("home_room", "/d/sects/danding/herb_garden.c");

    add_response(({ "藥田", "寒髓草", "水脈", "水渠" }),
        "葉青枝眉心微緊，抓緊了手中的竹籃邊緣，低聲道：「這些寒髓草葉片冒出紫紅斑紋不是一兩天的事了，\n"
        "連上游水渠裡的沉積泥漿都帶著澀口礦酸味……可谷裡的事輪不到我一個小管事拍板。你要採樣對照便留下一份紀錄，\n"
        "千萬別把數據張揚出去，免得上面直接封了整片藥田斷掉藥農活路。」");

    add_response(({ "雪線苔", "泥土" }),
        "葉青枝點頭道：「那冰藍色微苔自己從染毒根鬚旁長出來替草根吸走酸濁，算是自然生息自救的引子。\n"
        "記住保留樣本做小區對照，莫把單一現象當成所有靈草都一樣的定論。」");
}
