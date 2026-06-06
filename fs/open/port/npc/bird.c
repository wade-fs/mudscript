inherit NPC;

void create()
{
	set_name("麻雀",({"bird"}));
        set("race", "野獸");
        set("age", 1);
        set("long", "
一支普通的麻雀 , 正在枝頭上高歌 .");
        set("str", 10);
        set("cor", 20);
        set("verbs", ({ "bite"}));
                set("limbs", ({ "頭部", "身體",  }) );
	set("chat_chance",10);
        set("chat_msg", ({
	(: this_object(),"random_move" :),
                       }) );
        setup();

}
