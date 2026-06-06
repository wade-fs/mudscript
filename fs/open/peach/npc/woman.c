// woman.c

inherit NPC;

string ask_well();
string ask_story();
void create()
{
        set_name("三姑", ({ "old woman","woman" }) );
        set("long",
                "悠閒的桃花村中，說故事的專家。據說，她知道一般人所不知道的\n傳說。她的習慣是多喝水，所以經常徘徊在...\n");

        set("race", "人類");
        set("gender", "女性");
        set("age", 55);
        set("nickname","大嗓門");
        set("limbs", ({ "頭部", "身體", "左手", "右手", "左腳", "右腳" }) );

        set("per", 15);
        set("cor", 25);
        set("cps", 23);
        set("int", 16);

        set("inquiry", ([
            "桃花源"   : "我跟你說，這裡本來是一個與世隔絕的世外桃源，自從那天以來，一切都改變了...\n",
            "傳說"     : (:ask_story:),
            "寶物"     : "寶物？你在說哪一個？？老王田裡的莊稼，還是說小陳家裡的那隻鋤頭？\n",
            "水井"     : (:ask_well:),
			"規矩"     : "在你離開前，來老婆子家裡拿桃子回去嚐嚐吧。\n",
			"玲玲"     : "她長的真是標緻對吧。\n",
			"村長"     : "從這往前直走就是他家了。\n",
			"桃樹"     : "這裡除了樹上會產桃子之外，據說在某個地方埋有一個秘密喔。\n",
			"桃子"     : "桃子有分一般味美的鮮桃，與富有特殊風味的遺忘桃兩種。\n",
			"遺忘桃"   : "相傳這種桃子是我家先人栽培的喔。\n",
			"him"     : "他是壞人，專門欺騙女人的感情，早該要他吃下遺忘桃了。\n",
		]) );

		set("combat_exp", 90000);
        set("chat_chance", 50);
        set("chat_msg", ({
            (: this_object(), "peach" :),
            "三姑說道: 嗯嗯...\n",
            "三姑說道: 是嗎？\n",
            "三姑說道: 沒這回事吧...\n",
            "三姑說道: 騙人...\n",
            "三姑說道: 好啦...\n",
            "三姑說道: 哪個他(him)...\n",
            "三姑說道: 不好不好...\n",
        }) );

        setup();

}

string ask_well()
{
	object me = this_player();
	if (me->query_temp("quests/peach/mark") > 10)
	{
		command("say 你在問水井下的寶物呀，傳說中，那是先祖從俗世帶進來的。");
	}
	else
	{
		command("say 水底下有寶物？你在騙老婆子呀...");
	}
	return "";
}

string ask_story()
{
	string str;
	object gift;
	object ob = this_player();
	switch(random(100))
	{
		case 0..19:
			write("\n");
			break;
		
		case 20..39:
			write("\n");
			break;

		case 40..59:
			write("\n");
			break;

		case 60..79:
			write("\n");
			break;

		case 80..99:
			write("\n");
			break;
		default:
        }
//		write(HIR"恭喜獲得"+str+HIR"獎品！\n"NOR);
		return "";
}
