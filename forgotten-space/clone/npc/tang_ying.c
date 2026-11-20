// /clone/npc/tang_ying.c
// 唐映・八荒破軍重弓塞女校尉 (tang_ying) - 萬鈞問心谷 (Ch.87)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("唐映");
    set_short(CYN "破軍重弓女校尉" NOR " 唐映");
    set_long("二十七歲的女校尉，右眼眉骨處留有一道明顯的凍傷疤痕，背負牛角長弓與測距紅旗。\n"
             "其親弟早年在一場獸潮中失蹤，因此對拿人命粉飾「戰功數字」極度反感。\n");
    set_id(({ "tang_ying", "tang ying", "tang", "唐映", "女校尉", "校尉" }));

    setup_archetype("D", 78);
    set("class", "wu");
    set("faction", "bahuang");
    set("roles", ({ "examiner", "archer" }));
    set("home_room", "/d/sects/bahuang/gate.c");

    add_response(({ "箭矢", "配給", "射界", "響箭" }),
        "唐映看也沒多看一眼考核者，冷冷道：「配給的三支箭射完不補，自己收回箭桿是獵戶的基本功。\n"
        "出谷沒人替你收屍，真撐不住了捏碎求救響箭，巡哨隊會把人拖出去——當然，從此跟八荒武山無緣。」");

    add_response(({ "傷亡", "棄考", "戰功" }),
        "唐映凍傷的右眼微瞇：「剛才那個折返去拉棄考傷兵又把箭拔回來的小子，氣血波動比進谷前還穩。\n"
        "我不管上面那些人怎麼寫戰功簿，進了我破軍重弓塞，每支箭、每條人命都得給我記明白！」");

    add_response(({ "鬼哭冰澗", "鐵甲寒犛", "白霧雪溝", "測距" }),
        "唐映將測距紅旗插定在長城三號豁口上，眼神銳利：「長城外一里便是三倍濃烈的白霧雪溝，\n"
        "鐵甲寒犛衝車時先破牠腋下軟筋！記住軍紀——寧可扣半個月肉乾也不准追進雪溝！\n"
        "至於五年前走山隊落點的鬼哭冰澗，過了東側鐵包邊門找祁無傷探冰，箭茬切口得繪實步數才作數！」");
}
