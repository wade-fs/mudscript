// daughter2.c
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("玲玲", ({ "Lingling", "lingling"}) );
        set("long",
                "玲玲是桃花村村長的掌上明珠，從小就深受眾人的喜愛。白皙的肌膚\n與圓圓的大眼睛，是位令人愛憐的美姑娘。\n");

        set("race", "人類");
        set("gender", "女性");
        set("age", 21);
        set("class","dancer");
        set("nickname","新娘");
        set("limbs", ({ "頭部", "身體", "左手", "右手", "左腳", "右腳" }) );

        set("per", 26);
        set("int", 20);
        set("cor", 10);

        set("combat_exp", 160000);
        set("inquiry", ([
            "桃花源"   : "這裡是一個與世隔絕的地方，這裡很少人會到這裡，直到有一天...有一個外地人的到來...\n",
			"規矩"     : "我們這裡的規矩就是，如果是個異鄉人要離開這的話，就一定要吃下\n遺忘桃，忘卻這裡的存在，可是...我，卻不想讓他吃...\n",
			"寶物"     : "寶物？你指外頭那些農作物嗎？\n",
			"村長"     : "你能幫忙救救我父親嗎？\n",
			"桃樹"     : "旁邊就是這顆就是，從小就陪著我長大。\n",
			"桃子"     : "鮮美多汁，你也要吃嗎？\n",
			"遺忘桃"   : "吃下了這種桃子，會忘記一段時間的記憶。\n",
			"傳說"     : "這...要問三姑六婆才比較清楚吧。\n",
			"玲玲"     : "你在找我嗎？你可以再靠近一點...\n",
			"水井"     : "旁邊這就是，這水喝起來相當甜喔。\n",
		]) );
        setup();
}


void init()
{
	object me;
    me=this_player();

  if( interactive(me))
   {
	  remove_call_out("greeting");
	  call_out("greeting", 0, me);
   }
	::init();
}

int greeting(object me)
{
	if(!me) return 1;
	if (me->query_temp("quests/peach/mark") == 11)
	{
		call_out("greeting2",5,me);
	}
	return 1;
}

int greeting2(object me)
{
	object gift;
	object ob=this_player();
	if (me->query_temp("quests/peach/get") != 2 && me->query("quests/peach")!=1)
	{
		if (me->query_temp("quests/peach/borrow") == 1 && me->query("quest/peach")!=2) //如果有先歸還髮簪　才觸發遺忘桃禮物
		{
			message_vision("\n與眾人敬了一巡酒之後，這對新人來到你面前。\n",me);
			message_vision(HIY + "玲玲羞赧地對你說: 因為有您的協助，所以我們才能在一起。\n" + NOR,me);
			message_vision(HIY + "玲玲說道: 這雖然並不珍貴，但卻是我們的一點小小心意，請您收下。\n" + NOR,me);
			message_vision("你打開包袱，發現到原來是一顆"+HIM + "醃漬桃子" + NOR+"。\n",me);
			gift = new(__DIR__"kill_pill.c");
			gift->set_amount(1);
			gift->move(ob);
			me->set_temp("quests/peach/mark", 12);
			me->set("quest/peach",2);
		}
		else
		{
			message_vision("\n與眾人敬了一巡酒之後，這對新人來到你面前。\n",me);
			message_vision(HIY + "玲玲羞赧地對你說: 因為有您的協助，所以我們才能在一起。\n" + NOR,me);
			message_vision(HIY + "玲玲說道: 這雖然不多，但卻是我們的一點小小心意，請您收下。\n" + NOR,me);
			message_vision("你打開包袱，發現到原來是"+HIY + "十兩金元寶" + NOR+"。\n",me);
			gift = new("/obj/money/gold");
			gift->set_amount(10);
			gift->move(ob);
			me->set_temp("quests/peach/mark", 12);
		}
	me->set_temp("quests/peach/get",2);
	}
	return 1;
}

int accept_object(object who, object ob) //接受髮簪
{
	if ( ob->query("id") == "peach hairpin")
	{
		if (who->query_temp("quests/peach/borrow") != 1)
		{
			message_vision("玲玲說道: 六婆要你拿來還的呀，真是太感謝你了。\n",who);
			who->set_temp("quests/peach/borrow",1);
			ob->move(who);
//			command("give hairpin to "+who->query("id"));//> 『暢談』小ｘ兒說道: 要不然就用 obj->move(who) 好了
			message_vision("玲玲說道: 據說它能夠帶來好運，我就把它送給你，希望你也能有個幸運的一天。\n",who);
			message_vision("於是玲玲就把髮簪交到$N手上。\n",who);
		}
		else
		{
			message_vision("玲玲說道: 謝謝$N幫忙。\n",who);
		}
	return 1;
	}
}
