// sheik2.c
// 增加call_out 的應用

inherit NPC;
#include <command.h>
#include <mudlib.h>
#include <room.h>
#include <ansi.h>
string ask_marry();

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
            "桃花源"       : "這裡真是一個好地方，不是嗎？\n",
			"規矩"         : "村裡的規矩就是像你這種外地人，要離開前得吃下一顆遺忘桃。\n",
			"寶物"         : "村裡的寶物就是那口(水井)了，喝起來真是甜美呀。\n",
			"傳說"         : "傳說有很多個...你想知道哪一個？關於水裡的那個女人嗎？\n",
			"玲玲"         : "你...你想對我家的玲玲做什麼！\n",
			"村長"         : "我家代代都是這個村的村長，將來玲玲她丈夫也要繼承。\n",
			"水井"         : "桃花村共用一口水井。\n",
			"桃樹"         : "村里有很多顆喔。\n",
			"桃子"         : "家的大門那裡有種，自己採沒關係。\n",
			"遺忘桃"       : "我可以拿給你吃喔，不保證後果呢...\n",
			]));

		setup();
}


void init()
{
	object me = this_player();
	if( interactive(me))
	{
		if (me->query_temp("quests/peach/mark")==6)
		{
			remove_call_out("greeting");
			call_out("greeting", 4, me);
		}
		else if (me->query_temp("quests/peach/mark")==8)
		{
			remove_call_out("greeting4");
			call_out("greeting4", 4, me);
		}
		else if (me->query_temp("quests/peach/mark")==10)
		{
			remove_call_out("greeting5");
			call_out("greeting5", 4, me);
		}
	}
	return;
	::init();
}

int greeting()
{
	object me = this_player();
	if(!me) return 1;
	if (environment(me)==environment())
	{
		command("say 如果當初老朽不反對就好了...");
		command("sigh");
	}
	call_out("greeting2",4,me);
	return 1;
}

int greeting2()
{
	object me = this_player();
	if(!me) return 1;
	if (environment(me)==environment())
	{
		command("say 其實...那年輕人會離開是老朽的要求。");
		command("say 老朽當時強迫要他吃下遺忘桃，是為了要保護這村子的寧靜。");
		command("say 老朽那時以為女兒只是單純因為好奇而嚮往外面世界的新鮮。");
		command("say 所以才會想盡辦法趕他走。");
		command("say 沒想到女兒是真的長大了....");
		command("say 對於自己的戀情已經明白自己在追求些什麼。");
	}
	call_out("greeting3",4,me);
	return 1;
}

int greeting3()
{
	object me = this_player();
	if(!me) return 1;
	if (environment(me)==environment())
	{
		command("say 大俠能否麻煩你將那年輕人帶回來。");
		command("say 既然是老朽惹下的禍，老朽來向女兒解釋，老朽希望(成全)他們。");
		me->set_temp("quests/peach/mark",7);
	}
	return 1;
}

int greeting4()
{
	object me = this_player();
	if(!me) return 1;
	if (environment(me)==environment())
	{
		me->set_temp("quests/peach/mark",9);
		command("say 謝謝你把他送回來，老朽對於大俠你的大恩大德，實在無以言表。");
		command("say 請大俠三天後再來觀賞小女的婚禮。");
		command("haha");
		message_vision("村長大笑之中轉身進入房內開始準備婚禮。\n",me);
		destruct(this_object());
	}
	return 1;
}

int greeting5()
{
	object me = this_player();
	if(!me) return 1;
	if (environment(me)==environment())
	{
		message_vision(HIY + "\n一陣陣鞭炮聲響起，象徵著一對新人即將誕生。\n\n" + NOR,me);
	}
	call_out("greeting6",6,me);
	return 1;
}

int greeting6()
{
	object me = this_player();
	if(!me) return 1;
	if (environment(me)==environment())
	{
		message_vision(HIY + "街坊鄰居也來湊熱鬧共襄盛舉，\n" + NOR,me);
		message_vision(HIY + "但是你卻聽見站在你隔壁的三姑正和六婆論著男方的是非。\n" + NOR,me);
		message_vision(HIC + "你耳尖地聽見寶物這敏感的字眼。\n\n" + NOR,me);
	}
	call_out("greeting7",5,me);
	return 1;
}

int greeting7()
{
	object me = this_player();
	if(!me) return 1;
	if (environment(me)==environment())
	{
		message_vision(HIY + "只聞道.....\n" + NOR,me);
		message_vision(HIY + "三姑說道: 聽說那男方本來是要來搶寶物的，還帶人來搶呢。\n" + NOR,me);
		message_vision(HIY + "六婆說道: 真的嗎！外地來的果真沒好心眼。\n" + NOR,me);
		message_vision(HIY + "三姑說道: 是呀是呀。\n" + NOR,me);
		message_vision(HIY + "六婆說道: 還是我們桃花村的村民最純樸了。\n" + NOR,me);
		message_vision(HIY + "三姑說道: 沒錯沒錯。\n" + NOR,me);
		message_vision(HIY + "六婆說道: 搞不好那男方會婚變呢。\n" + NOR,me);
		message_vision(HIY + "三姑說道: 一定一定。\n" + NOR,me);
		message_vision(HIY + "六婆說道: 還好我們村長記性不好，早就忘了那寶物地點。\n" + NOR,me);
		message_vision(HIY + "三姑說道: 還好還好。\n" + NOR,me);
		message_vision(HIY + "六婆說道: 幸好我還記得。\n" + NOR,me);
		message_vision(HIY + "三姑說道: 不就在那水....\n" + NOR,me);
		message_vision(HIY + "六婆說道: 噓，小心隔牆有耳...\n" + NOR,me);
		message_vision(HIY + "你發覺她們愈說愈小聲....\n\n" + NOR,me);
	}
	call_out("greeting8",5,me);
	return 1;
}

int greeting8()
{
	object me = this_player();
	if(!me) return 1;
	if (environment(me)==environment())
	{
		message_vision(HIY + "她們也發覺你在注意她們....\n" + NOR,me);
		message_vision(HIY + "然後她們毅然轉身離去。\n" + NOR,me);
		message_vision(HIY + "你隱隱約約知道這桃花村傳說中的寶物就在那水...什麼裡面。\n" + NOR,me);
		message_vision(HIY + "現在，你有股衝動想追出去詢問個清楚。\n" + NOR,me);
		me->set_temp("quests/peach/mark",11);
	}
	return 1;
}
