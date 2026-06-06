// woman.c

inherit NPC;
#include <ansi.h>

string ask_well();
void create()
{
        set_name("六婆", ({ "very old woman","woman" }) );
        set("long",
                "純樸的桃花村中，人際關係非常良好的專家。不過她經常徘徊在村長家\n門口，一直望著那口(水井)。\n");

        set("race", "人類");
        set("gender", "女性");
        set("age", 65);
        set("nickname","串門子");
        set("limbs", ({ "頭部", "身體", "左手", "右手", "左腳", "右腳" }) );

        set("per", 17);
        set("cor", 30);
        set("cps", 18);
        set("int", 20);

        set("combat_exp", 80000);


        set("inquiry", ([
            "桃花源"   : "住在這裡相當快樂喔...你要來住這裡嗎？\n",
            "寶物"     : "寶物？老婆子的寶物是不能給你看的...\n",
			"玲玲"     : "她是村長的女兒，怎...你找她有事？\n",
			"傳說"     : "什麼樣的傳說，你在問六婆我編的那一個故事？\n",
			"村長"     : "他們家代代都住在這，應該了解不少(傳說)，不過沒我六婆多就是...嘻嘻。\n",
			"水井"     : (:ask_well:),
			"桃花"     : (:ask_well:),
			"規矩"     : "記得要離開之前，來老婆子家一趟，老婆子送你幾顆桃子吃。\n",
			"桃樹"     : "我家也有種幾顆桃樹，你要不要來老婆子家裡玩呢。\n",
			"桃子"     : "令人很容易跟遺忘桃搞混呢。\n",
			"遺忘桃"   : "對於村裡的人來說，那是一種毒藥喔。\n",
			"him"     : "他很壞，老婆子我很喜歡呢。\n",
		]) );

        set("chat_chance", 40);
        set("chat_msg", ({
            (: this_object(), "peach" :),
            "六婆說道: 我跟妳說...隔壁老王家的老黃生了一隻黑狗...\n",
            "六婆說道: 我跟妳說...對面小陳家有種大黃瓜...\n",
            "六婆說道: 我跟妳說...那天阿明在小花她面前摔了個大跟斗...\n",
            "六婆說道: 我跟妳說...村長她女兒當初被他(him)騙財騙色呢...\n",
            "六婆說道: 我跟妳說...明天不會下雨啦...\n",
            "六婆說道: 我跟妳說...下大雨該收衣服囉...\n",
            "六婆說道: 我跟妳說...小華他老子做的飾品最漂亮了...\n",
            "六婆說道: 我跟妳說...老婆子頭上這髮簪好看嗎？\n",
        }) );
        setup();

}

string ask_well()
{
	object me = this_player();
	object gift;
	if (me->query_temp("quests/peach/die") == 1 || me->query_temp("quests/peach/get") == 2 || me->query_temp("quests/peach/mark")==11)
	{
		if (me->query_temp("quests/peach/key") != 1)
		{
			command("say 說起來，那天玲玲借了一支髮簪給老婆子裝扮裝扮，你順便幫老婆子歸還給她吧。");
			write("六婆從髮中取出一支髮簪交到你手上。\n");
			command("say 老婆子年紀大了，不適合這種小女生的髮簪...");
			gift = new(__DIR__"hairpin");
			gift->set_amount(1);
			gift->move(me);
			me->set_temp("quests/peach/key", 1);
		}
		else if (me->query_temp("quests/peach/borrow") == 1)
		{
			command("say 謝謝你幫忙老婆子把髮簪還給玲玲。");
			command("say 老婆子特地告訴你一個秘密吧。");
			write(HIY"六婆特地在你耳邊悄悄地對你說。\n"NOR);
			write(HIY"六婆說道: 聽說水井是可以爬下去的。\n"NOR);
			me->set_temp("quests/peach/know",1);
		}
		else
		{
			command("say 要記得還喔。");
		}
		return "";
	}
	else
	{
		command("say 水井裡面應該不會有女人吧。");
		command("say 你問這想做什麼？我最討厭外地人了。");
		command("cower");
	}
	return "";
}
