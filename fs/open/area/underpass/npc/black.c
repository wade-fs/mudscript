inherit NPC;

void create()
{
        set_name("黑無常", ({ "black gargoyle", "gargoyle" }) );
        set("long",
                "黑無常伸著長長的舌頭瞪著你﹐黝黑的臉上看不出任何喜怒哀樂。\n");
        set("attitude", "peaceful");
        set("random_move",3);
        set("chat_chance", 15);
        set("chat_msg", ({
                "黑無常發出一陣像呻吟的聲音﹐當他發現你正注視著他的時候﹐瞪了你一眼。\n",
                "黑無常把長長的舌頭伸出來﹐緩緩地舔了舔自己又黑又長的手指。\n"
        }) );
        set("age", 217);
        set("combat_exp", 20000);
        set("max_gin", 900);
        set("max_kee", 900);
        set("max_sen", 200);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_temp("apply/armor", 60);
        set_temp("apply/damage", 20);
        setup();
}

void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return ;
	say("黑無常說：又來了一個孤魂野鬼！咦～
黑無常不斷的翻閱\著生死簿！\n");
	call_out("msg01",3,this_player());
}

void msg01()
{
	tell_object(this_player(),"
黑無常說：怪了，生死簿沒有你的名字～...
黑無常說：一定又是那個白骨精搞的鬼！
\n");
	call_out("msg02",3,this_player());
}

void msg02()
{
	tell_object(this_player(),"
黑無常說：你的精力都被那白骨精給吸走了！我先送你去一個地方，記得去找一個叫夢婆的人！
黑無常說：他應該有辦法幫你回會成以往的功\力～\n");
	call_out("msg03",3,this_player());
}

void msg03()
{
	this_player()->move("/open/area/forest/sh01");
}
