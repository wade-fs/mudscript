//這是萱萱的 file

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("雪緣", ({ "fairy" }) );
        set("nickname", HIM + "星塵之妻" + NOR );
        set("gender", "女性");
        set("age", 19);
        set("long", HIW + "你看到一位身穿白紗的少女，美目含笑的望著你，她清麗脫俗的
臉龐深深吸引著你的目光．\n" + NOR );

        set("str", 24);
        set("cor", 26);
        set("int", 29);

        set_skill("dodge", 100);
        set_skill("parry", 100);

	set("random_move",2);
        set("chat_chance", 20);
        set("chat_msg", ({
                HIW + "雪緣深深的歎了一口氣.......\n" + NOR,
                HIW + "雪緣喃喃自語：該做什麼菜給星塵吃呢?\n" + NOR,
                HIW + "雪緣玩弄著髮梢，突然臉紅了起來，大概是想到〞星塵〞了～\n" + NOR,
                 (: random_move :) })
            );
             
        set_temp("apply/attack", 0);
        set_temp("armor", 300000);
	set("combat_exp",83437);
        setup();
}

