// /d/snow/npc/waiter.c
#include "/open/open.h"

inherit F_VENDOR;

void create()
{
	set_name("店小二", ({ "waiter" }) );
	set("nickname","天耳通");
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"這位店小二正笑咪咪地招呼客人，還不時被喚去問東問西。\n");
	set("combat_exp",110);
	set("attitude", "friendly");
	set("inquiry", ([
	"thief" : "想問事情就得賞些小費吧..\n\n店小二的大手在你面前晃啊晃的。",
	]));
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
		"/obj/example/wineskin",
		"/obj/example/dumpling",
		"/obj/example/chicken_leg",
        CAPITAL_OBJ"tea",
        COMMON_OBJ"needle",
	}) );
	set("greeting_msg", ({
	"來來來..客倌要點什麼..\n",
	"小弟正是包打聽, 天下事事事都曉..\n",
	"來喔..便宜的特產喔..\n",
	}));
	setup();
}

int accept_object(object who, object ob)
{      
	string *secret=
	({" 呵呵..那個蕭甚麼的大盜，聽說逃到蜀山去了..\n",
	  " 唉..楊老可是清官耶..居然要被砍頭了..\n",
	  " 王老闆最近要嫁女兒了耶..\n",
	  " 舉頭三尺有 Wade..虧心事莫做!\n",
	  " 李大嬸昨兒個被她兒子氣死了..真是不孝子阿..\n",
	  " 聽說干將劍削鐵如泥哩!\n",
	  " 聽說無賴窩裡的那兩隻無賴地痞也懂得不少事耶..\n",
	  " 街口的那個武林豪客每次都在吹噓他差點抓到那京城大盜, 也不知是真是假..\n",
	});
	if( ob->value() > 100 )
        {   
          command("say 嘿嘿.."+RANK_D->query_respect(ob)+"真是上道..\n");
          command("say 讓我天耳通來告訴你天下事..\n");
	  command("whisper "+who->query("id")+secret[random(sizeof(secret))]);
	}												
        else
          command("say 你也太瞧不起我天耳通了。\n");
       	return 1;
}       								
