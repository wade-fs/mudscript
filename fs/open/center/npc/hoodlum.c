// 改寫自 bandit.c
// hoodlum.c by powell

#include "/open/open.h"
inherit NPC;

void create()
{
        set_name("流氓", ({ "Hoodlum", "hoodlum" }) );
        set("gender", "男性");
        set("age", 25);
        set("long",
            "這傢伙突然轉過頭來瞪了瞪你, 一付要把你吃下去的樣子, 還是別惹他的好。\n"
            "他常常在妓院逗留，目的就是專門想敲凱子的竹槓。\n"
        );

        set("combat_exp",390);
        set("score", 1);
        set("attitude", "peaceful");
        set_skill("dodge", 10);
        set("inquiry", ([
            "移花宮"    :       "聽說移花宮清一色是女人，而且是個個絕代佳人呢!",
            "妓女"      :       "年輕人，先繳點錢再找妓女吧。",
            "保護費"    :       "算了，今天大爺心情好，放過你一馬。",
            "繳點錢"    :       "繳錢? 直接給我就好了嘛。",
            "繳錢"      :       "繳錢? 直接給我就好了嘛。",
            "惡人谷"    :       "這我只聽京裡的兄弟提過，詳情就不得而知了。",
            "老鴇"      :       "她是我大姊頭，我在這兒也只是收收保護費罷了。",
            "水仙姑娘"  :       "她最可惡了，看都不看我一眼。",
            "哥兒們"    :       "誰是你的哥兒們啊，少臭美了。",
            "英俊的哥兒們":     "誰誰誰? 你這是在說我嗎?",
        ]) );

        setup();
        add_money("silver", 3);
        carry_object(CENTER_OBJ"club1")->wield();
        carry_object(CENTER_OBJ"belt1")->wear();
}
