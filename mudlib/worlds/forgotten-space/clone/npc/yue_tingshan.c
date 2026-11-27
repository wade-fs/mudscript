// /clone/npc/yue_tingshan.c
// 岳停山・八荒煞血霸體營教頭 (yue_tingshan) - 萬鈞問心谷 (Ch.87)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("岳停山");
    set_short(HIR "煞血營教頭" NOR " 岳停山");
    set_long("四十二歲上下，身材高大壯碩如鐵塔，右膝行走時微有陳年舊傷僵滯。\n"
             "他治軍極嚴，平時對弟子訓斥從不留情，但最反對無意義送死與強催氣血自焚。\n");
    set_id(({ "yue_tingshan", "yue tingshan", "tingshan", "岳停山", "教頭" }));

    setup_archetype("C", 82);
    set("class", "wu");
    set("faction", "bahuang");
    set("roles", ({ "examiner", "trainer", "quest" }));
    set("home_room", "/d/sects/bahuang/gate.c");

    add_response(({ "問心谷", "試煉", "黑石峽", "規矩" }),
        "岳停山嗓音沙啞低沉：「入谷試煉規矩只有三條：不准穿重甲、不准帶私丹，只准留三支箭在壺裡。\n"
        "穿過前面八十里地煞沖刷的黑石峽抵達黑山前哨——記住！真氣催得太急，地煞就會順著毛孔鑽進心肺爆脈；\n"
        "打得贏頭狼是本事，懂得分寸留得住命才配進黑山營！」");

    add_response(({ "鐵背荒狼", "頭狼", "氣血" }),
        "岳停山冷哼道：「黑石峽那頭缺耳頭狼最狡猾，專拖延時間等散狼合圍。\n"
        "別學那些蠢貨把氣血當煙火亂燒，收住呼吸，一箭釘死頭狼再退去前哨！」");
}
