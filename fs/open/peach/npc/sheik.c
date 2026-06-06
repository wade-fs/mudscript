// sheik.c

inherit NPC;
#include <ansi.h>
string ask_home();

void create()
{
        set_name("村長", ({ "Sheik", "sheik" }) );
        set("long",
                "桃花源村的村長。為了女兒美滿的婚姻而欲使那男人吃下遺忘桃進而\n忘卻外面世界的種種。\n");

        set("race", "人類");
        set("gender", "男性");
        set("age", 50);
        set("limbs", ({ "頭部", "身體", "左手", "右手", "左腳", "右腳" }) );
        set("cor", 10);
        set("cps", 20);
        set("kar", 25);
        set("per", 19);
		set("combat_exp", 120000);

        set("inquiry", ([
            "回家"      : (:ask_home:),
            "桃花源"       : "這裡真是一個好地方，不是嗎？\n",
			"規矩"         : "村裡的規矩就是像你這種外地人，要離開前得吃下一顆遺忘桃。\n",
			"寶物"         : "村裡的寶物就是那口(井)了，喝起來真是甜美呀。\n",
			"傳說"         : "傳說有很多個...你想知道哪一個？關於水裡的那個女人嗎？\n",
			"玲玲"         : "你...你想對我家的玲玲做什麼！\n",
			"村長"         : "我家代代都是這個村的村長，將來玲玲她丈夫也要繼承。\n",
			"水井"         : "桃花村共用一口井。\n",
			"桃樹"         : "村里有很多顆喔。\n",
			"桃子"         : "家的大門那裡有種，自己採沒關係。\n",
			"遺忘桃"       : "我可以拿給你吃喔，不保證後果呢...\n",
		]));



        set("chat_chance", 15);
        set("chat_msg", ({
            (: this_object(), "quest" :),
            "村長驚慌說道: 不要打我... \n",
            "村長柔性勸說: 別激動！別激動！有話慢慢說...\n",
            "村長向天乞求: 老天呀...誰來救救我吧～\n",
            "村長喃喃自語: 女兒呀，父親先走一步了...\n",

        }) );

       setup();
}

string ask_home()
{
	object me = this_player();
	if (me->query_temp("quests/peach/mark")==4)
	{
		if (me->query_temp("quests/peach/die")==1)
		{
			command("say 真是非常謝謝你惡徒手中救了老朽。");
			command("say 老朽就跟在你後頭，不好意思麻煩你帶老朽回家。");
			command("村長就跟在你後方。");
			me->set_temp("quests/peach/mark",5);
			destruct(this_object());
		}
    	else
	    {
	    	command("say 大俠，請你救救我吧。");
	    	command("groan");
	    }
	}
	else
	{
		command("hmm");
	}
	return "";
}
