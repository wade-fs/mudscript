// man.c

inherit NPC;
string ask_yes();
string ask_happen();
string ask_home();

void create()
{
        set_name("玲玲的戀人", ({ "stranger" }) );
        set("long",
                "在離開之後才明白自己是思念著玲玲的男人，在與好朋友商量之後，\n決定再回來桃花村追求愛情。孰料...\n");

        set("race", "人類");
        set("gender", "男性");
        set("age", 25);
        set("class","booker");
        set("nickname","性情中人");
        set("limbs", ({ "頭部", "身體", "左手", "右手", "左腳", "右腳" }) );

        set("str", 16);
        set("cor", 22);
        set("int", 19);
        set("cps", 23);
        set("kar", 29);

        set("combat_exp", 150000);

        set("inquiry", ([
            "happen"      : (:ask_happen:),
            "yes"         : (:ask_yes:),
            "no"          : "這樣呀...大俠您就行行好，幫幫忙嘛？(yes/no)\n",
            "pass"        : "被樹叢擋住，大俠您找找(search)通往前方的道路就能過去了。\n",
            "前方"         : "被樹叢擋住，大俠您找找(search)通往前方的道路就能過去了。\n",
            "成全"         : (:ask_home:),
            "桃花源"       : "這裡風景好，空氣好，就連女人也......你不能跟我搶玲玲。\n",
			"規矩"         : "別再跟我說那件事了，我不想忘記玲玲。\n",
			"寶物"         : "(傳說)這裡埋藏了數以千計的金銀珠寶喔！\n",
			"傳說"         : "玲玲她父親應該知道不少吧。\n",
			"玲玲"         : "她的心地好，又有文學素養，臉蛋也不錯，身材玲瓏有緻，真是......\n跟你說我沒在流口水啦。\n",
			"村長"         : "這是我的疏失，沒想到那人竟然欺騙我，綁走了玲玲的父親。\n",
			"桃樹"         : "你餓了嗎？\n",
			"桃子"         : "你餓了嗎？\n",
			"遺忘桃"       : "你該不會想吃吧？\n",

]));

        set("chat_chance", 15);
        set("chat_msg", ({
            (: this_object(), "qeusts" :),
            "玲玲的戀人說道: 怎麼會這樣！\n",
            "玲玲的戀人說道: 我沒想到他竟然是這樣的一個人。\n",
            "玲玲的戀人說道: 可惡！玲玲的父親被綁走了！\n",
            "玲玲的戀人說道: 怎麼辦！玲玲她誤會我了啦！\n",
            "玲玲的戀人說道: 希望玲玲會相信我，我只是回家拿禮物而已。\n",
        }) );

        setup();

}

string ask_happen()
{
	    object me = this_player();
        if (me->query_temp("quests/peach/mark") == 3 )
        {command ("say 玲玲的父親被綁走了，我正急著要去救他，可是我在追的過程中不小
心跌傷了腳，請問您能幫忙我嗎？(yes/no)" );
        }
		else
    	{
			command("hmm");
		}
		return "";
}

string ask_yes()
{
	    object me = this_player();
		if (me->query_temp("quests/peach/mark")== 3 )
		{
			command("say 這真是太好了！他們就在前方(pass)不遠，大俠您就趕快追上去吧。");
			command("say 如果大俠您行有餘力，能否麻煩您帶玲玲的父親(回家)好嗎？");
			command("smile");
			me->set_temp("quests/peach/mark",4);
		}
		else
	    {
		command("hmm");
		}
        return "";
}


string ask_home()
{
	    object me = this_player();
		if (me->query_temp("quests/peach/mark")== 7 )
		{
			me->set_temp("quests/peach/mark",8);
			message_vision("\n你詳細轉訴村長的話語。\n",me);
			command("say 真的嗎？我真是太高興了。");
			command(":)");
			command("say 大俠，雖然我很高興聽到這消息，但是我腳受了傷，能否麻煩您送我
回玲玲的家，謝謝。");
			destruct(this_object());
		}
		else
	    {
		command("真太感謝您救出玲玲的父親，大俠。");
		}
		command("shrug");
        return "";
}
