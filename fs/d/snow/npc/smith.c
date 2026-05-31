// smith.c

inherit NPC;

void create()
{
	set_name("王鐵匠", ({ "wang", "smith" }) );
	set("gender", "男性" );
	set("age", 33);
	set("long", "王鐵匠正用鐵鉗夾住一塊紅熱的鐵塊放進爐中。\n");
	set("combat_exp", 400);
	set("inquiry", ([
		"name": "小人姓王﹐單名一個恆字﹐可是小人西瓜大的字識不到一擔﹐只有王字會寫。\n",
		"here": "這裡是小人餬口的鋪子﹐小人一家五口都住在後邊的屋子。\n",
		"鋤頭": "鋤頭... 抱歉﹐鋤頭已經賣光了...\n",
		"鏟子": "對不起﹐小人店裡的鏟子都給人訂走了。\n",
		"鐵鎚": "鐵鎚﹖小人做的鐵鎚堅固又耐用﹐一把只要三百文錢。\n"
	]) );
	setup();
	carry_object("/d/snow/obj/hammer")->wield();
}

int buy_object(object who, string what)
{
	if( what=="鐵鎚" ) return 300;
	return 0;
}

void compelete_trade(object who, string what)
{
	object ob;

	ob = new("/d/snow/obj/hammer");
	ob->move(who);
	message_vision("$N交給$n一把沈甸甸的打鐵用鐵鎚。\n", this_object(), who);
}
