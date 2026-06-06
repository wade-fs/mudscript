// daughter.c by blazakira
// 增加少林廚藝學院的quest相關 2010/09/06 by blazakira

inherit NPC;
#include <ansi.h>

string ask_him();
string ask_yes();
string ask_no();
string ask_tofu();

void create()
{
        set_name("玲玲", ({ "Lingling", "lingling"}) );
        set("long",
                "玲玲是桃花村村長的掌上明珠，從小就深受眾人的喜愛。白皙的肌膚\n與圓圓的大眼睛，是位令人愛憐的美姑娘。不過她現在看起來像是為\n了某件事而憂傷。\n");

        set("race", "人類");
        set("gender", "女性");
        set("age", 21);
        set("class","dancer");
        set("nickname","清純甜美"+HIW + "豆腐西施" + NOR);
        set("limbs", ({ "頭部", "身體", "左手", "右手", "左腳", "右腳" }) );

        set("per", 26);
        set("int", 20);
        set("cor", 10);

        set("inquiry", ([
            "him"      :(:ask_him:),
            "like"     : HIY + "我愛他，就像是魚離不開水，樹離不開土地般。他是我的空氣，\n沒有了他，我失去了人生的意義(value)。\n" + NOR,
            "value"    : HIY + "沒想到他竟然不為了我而留下來，只想離開這裡，回到那鉤心鬥\n角的江湖(world)呢。\n" + NOR,
            "world"    : HIY + "他回來了，而且夥同他的同伴將我的父親綁走，曾經的山盟海誓\n原來都是假的！他個壞人(villain)。\n" + NOR,
            "villain"  : HIY + "他們逃往桃花林裡去了，你能幫我找到他嘛?(yes/no)\n" + NOR,
            "yes"      : (:ask_yes:),
            "no"       : (:ask_no:),
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
            "豆腐"     : (:ask_tofu:),
		]) );

        set("combat_exp", 160000);

        set("chat_chance", 2700);
        set("chat_msg", ({
            (: this_object(), "peach" :),
            "玲玲說道: 父親，我該怎麼辦才好...\n",
            "玲玲說道: 這一切都是我的錯。\n",
            "玲玲說道: 我的愛情不應該有這樣結果的。\n",
            "玲玲說道: 為什麼他(him)要帶壞人進來破壞這村子的寧靜呢？？\n",
        }) );
        setup();
}

void init()
{
	object me=this_player();
	if (me->query("quests/peach") !=1 && me->query_temp("quests/peach/mark") <1) //沒解過
	{
		if (me->query("combat_exp") > 1000000)
		{
			me->set_temp("quests/peach/mark", 1);
		}
		return;
	}
	add_action("ask_him_nod","nod");
	if (me->query_temp("quests/peach/mark") == 5)
	{
		if (me->query_temp("quests/peach/die") == 1)
		{
			me->set_temp("quests/peach/mark",6);
			command("say 大俠，對您的感謝無以言表。");
			command("say 非常謝謝您救了小女子的父親，並將他帶回來。");
			command(":)");
			command("say 大俠，我先帶父親進去休息。");
			command("玲玲轉身攙扶著村長進屋。");
			message_vision("玲玲轉身攙扶著村長進屋。\n\n",me);
			destruct(this_object());
		}
		return;
		
	}
	return;
}
int ask_him_nod (string str)
{
	object me = this_player();
	if (str=="lingling"||str=="Lingling")
	{
	call_out("ask_him",0,me);
	}
	return 0;
}

string ask_him()
{
        object me = this_player();
		if (me->query_temp("quests/peach/mark") > 0)
		{
			if (me->query_temp("quests/peach/mark") == 1)
			{
                me->set_temp("quests/peach/mark",2);
				command("say 這裡本來是個純樸的小村落的，但是自從那一天那個外地人來之後，
我無法自拔地迷戀(like)上那個人了。");
			}
			else
			{
			command("say 大俠，真是太感激您伸出援手了。");
		    }
			command("sob");
			return "";
		}
		else
	    {
			if (me->query("quests/peach") != 1)
			{
				command("sigh");
				command("say 「小」俠，你受限於江湖閱\歷不足，可能沒辦法幫我哦！");
				command("say 待你武學修為到了「技壓群雄」以上的階段才有那能力能幫得上忙。");
			}
			command("say 歡迎來到桃花村。");
			command("smile");
		}
        return "";
}

string ask_no()
{
                command("wuwu");
        return "";
}

string ask_yes()
{
        object me = this_player();
		if (me->query_temp("quests/peach/mark") == 2 )
		{
			command("say 真的嗎？你真的願意幫助我！");
            command("dance");
            me->set_temp("quests/peach/mark",3);
		}
		else
		{
			command("say 請快點追上去，拜託您了。");
		}
		return"";
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

string ask_tofu()
{
        object me = this_player(),ob;
		if(!me->query_temp("quests/bonze/food/start")) return "你在問什麼我怎麼聽不懂。"; //食材任務判斷失敗時
		if (me->query("quests/peach") == 1 && !me->query_temp("quests/bonze/food/tofu")) //需已解過 且 未領豆腐時
		{
			command("say 很高興再次見到您，非常感謝您之前的協助。");
            command("say 您需要桃花源村的特產豆腐是嗎？");
			message_vision("於是玲玲就把美味鮮嫩的豆腐交到$N手上。\n",me);
			ob=new("/open/bonze/food_quest/tofu");
			ob->set_temp("quests/bonze/food",1); //為使道具不可離線=限制玩家無限儲存道具在倉庫(離線角色)的作法
			ob->move(me);
			me->set_temp("quests/bonze/food/tofu",1); //限制玩家此階段只能領取一次
		}
		else
		{
			command("say 很高興再次見到您，請您不要吃小女子的豆腐好嗎。");
			command("blush");
		}
		return"";
}
