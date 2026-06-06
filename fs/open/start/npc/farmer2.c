// any.c by anmy 97/11/17
//修改訊息表述錯誤 by blazakira 2010/12/24

#include <ansi.h>
#include "../start.h"

inherit NPC;

void create()
{
	set_name("農夫", ({"farmer" }) );
	set("gender", "男性");
	set("age", 35);
	set("long","你注意到他的鼻子上長了一顆好大的痣，十分的滑稽。\n");
	set("str", 25);
	set("con", 20);
	set("combat_exp", 134);

        set("chat_chance", 5);
        set("chat_msg", ({
         "農夫抬起頭來擦擦額頭上的汗水，又再彎下腰去努力的耕田。\n",
	}) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "農夫尖叫道：救命啊！有人殺人啊！\n",
                "農夫尖叫道：你要幹什麼？要錢也不用殺我吧！\n",
        }) );

        setup();
        carry_object(S_OBJ"t_shirt")->wear();
}

int accept_fight(object me)
{
	return notify_fail("農夫說：這位"+RANK_D->query_respect(me)+"別開我玩笑了好嗎？\n");
}

int accept_object(object who , object item)
{
	if( item->query("id")=="bento" ) {
		tell_object(who,"喔喔！替我家的黃臉婆送來的呀，太感激你了，謝謝～\n");
		if( !who->query("quests/bento") &&
who->query_temp("bento")==1 )
		{
			who->add("combat_exp",100);
tell_object(who,HIY"你完成了農婦的便當之謎！\n"NOR);
			tell_object(who,HIC"你的經驗增加了 :p\n"NOR);
			who->set("quests/bento", 1);
		}
	}
	if( item->query("id")=="bento box" ) {
		printf("%s看了一看%s，\n",this_object()->short(),item->short());
		printf("%s大喊：好小子！竟敢吃了我的便當！\n",
		this_object()->short());
		tell_object(who, "你覺得實在很不好意思，只好再回去幫農夫拿一個便當。\n");
		who->set_temp("bento", 2);
	}
	return 1;
}
