#include <room.h>
#include <ansi.h>
inherit NPC;

string do_askblue();
string do_askbluecard();
string asktest();
string askcard();

void create()
{
set_name("獨居老人",({"oldman"}) );
set("long","這是一位面無表情的老人，他會是(藍鳳組)的聯絡人嗎？\n"+
       "還是先跟他打聲<招呼再說吧。。。\n");
set("gender","男性");
set("age",55);
set("combat_exp",200000);

set("inquiry",([ 
    "藍鳳組" : (: do_askblue :),
    "藍鳳絕殺令" : (: do_askbluecard :),
    "試煉" : (: asktest :),
    "靈異令牌" : (: askcard :),
]));
setup();
}

void init()
{
	add_action("do_hi","hi");
}


int accept_fight(object me)
{
   return notify_fail("放過我吧！讓我度過餘生吧！\n");
}

int do_hi(string arg)
{
    if ((!arg) || (arg != "oldman" ))
		return notify_fail("你在跟誰打招呼呀！。\n");
	if (this_player()->query_temp("head") < 1)
		return notify_fail("媽的，你怎麼來到這裡的？！。\n");
	if (this_player()->query_temp("head") == 1)
	{
		message_vision("嗯！有什麼事情嗎？能來這裡，看來是問（藍鳳組）的事情吧？\n",this_player());
		this_player()->set_temp("havehi",1);
		return 1;
	}
	message_vision("不用多禮，天靈老人的靈異令牌拿來了嗎？有了就拿給我！\n",this_player());
        return 1;
}

int accept_object( object me , object ob )
{
	object obj;

    if(ob->query("id") != "ghost_card")
	{
		command("say 甚麼東西啊?");
		return 0;
	}
	if( me->query_temp("head") !=5 ) 
	{
		command("say 居然敢叫別人幫你拿令牌！你沒資格出這一個任務了！滾！");
		me->delete_temp("head");
		return 0;
	}
	//表有令牌，而且令牌是自己拿的
	command("nod");
	command("say 果然是靈異令牌，你必須通過藍鳳試煉，才有資格去見到我們組長");
	obj = new("/open/killer/headkill/obj/wind.c");
	obj->move(this_player());
	message_vision("$N給$n一份"+obj->name()+"。\n",this_object(),this_player());
	command("say 你可以利用它，前往各個試煉場，詳細使用法自己看卷軸上有寫");
destruct(ob);
	me->set_temp("head",6);
	me->set_temp("kill_ghost",0);
}

string askcard ()
{
	object me=this_player();

	if (me->query_temp("havehi") != 1)
		return "沒有禮貌的傢伙，滾！";
	if (me->query_temp("askblue") ==3)
	{
		me->set_temp("head",2);
		command("say 想離開這裡的話，打 pass way，就可以離開");
		return "那在靈異掌令手中，自己去找他問靈異令牌，不知道誰是靈異掌令？看看殺手簡介吧！混！";	
	}
    return "你想要問幾次呀！";
}

string asktest ()
{
	object me=this_player();

	if (me->query_temp("havehi") != 1)
		return "沒有禮貌的傢伙，滾！";
	if (me->query_temp("askblue") ==2)
	{
		me->set_temp("askblue",3);
		return "那是一種資格考，想要去試煉先給我(靈異令牌)";	
	}
    return "你想要問幾次呀！";
}

string do_askbluecard ()
{
	object me=this_player();

	if (me->query_temp("havehi") != 1)
		return "沒有禮貌的傢伙，滾！";
	if (me->query_temp("askblue") ==1)
	{
		me->set_temp("askblue",2);
		return "那是可以命令藍鳳組的令牌，想要的話，需先通過(試煉)";	
	}
    return "你想要問幾次呀！";
}

string do_askblue ()
{
	object me=this_player();

	if (me->query_temp("havehi") != 1)
		return "沒有禮貌的傢伙，滾！";
	if (me->query_temp("head") == 1)
	{
		me->set_temp("askblue",1);
		return "想驅動藍鳳組的話，就必須有(藍鳳絕殺令）";	
	}
    return "你想要問幾次呀！";
}
