inherit ROOM;
#include <ansi.h>

void move();

void create()
{
	set("short",YEL"古代遺跡=亂葬室"NOR);
	set("long",@LONG
    一大堆的骨骸就在你的腳底下，這裡猶如骨骸堆置處一般，所有
的骨骸加起來，少說也有上千人的份量，只不過並非全部都是人類的
骨骸，還有動物與一些不知名生物的骨骸。
    四周都是由黃土石磚堆積而成的一個四方形密閉空間，並沒有任
何其他的通道。
    在骨骸堆中，有一個閃閃發光的銀色骨骸，隱約中，這銀色的骨
骸似乎在晃動！
LONG);
	set("item_desc",([
	"骨骸": (:move:),
	]));
	set("exits",([
		"east":__DIR__"a04",
		"north":__DIR__"a01",
	]));
	set("no_transmit",1);
	setup();
}

void move()
{
	if(!this_object()->query("leave"))
	{
	tell_object(this_player(),"在你正準備仔細檢查銀色骨骸的同時，骨骸突然動了起來！
銀色的骨骸說：想離開這嗎？哈哈～這裡可沒這麼簡單離開！\n");
	this_object()->set("leave",1);
	call_out("msg01",3,this_player());
	}
}

void msg01()
{
	tell_object(this_player(),"
銀色的骨骸稍微頓了一下，接著說：你的運氣算不錯，遇上了我，我可是匯集這裡所有骨骸的精華所成的「骨骸王」！\n");
	call_out("msg02",3,this_player());
}

void msg02()
{
	tell_object(this_player(),"
骨骸王說：如果你想離開這裡，我可以幫你，不過你要付出代價！
骨骸王說：別問我代價是什麼！同不同意隨你，反正你要是離不開這裡，遲早也是會被我吸收掉！
骨骸王說：我給你30秒鐘考慮...\n");
	call_out("msg03",30,this_player());
}

void msg03()
{
	tell_object(this_player(),"
骨骸王說：考慮好了嗎？如果決定好了就告訴我答案吧！
骨骸王說：你決定要離開(leave)還是留在這裡(stay)？給你10秒考慮...\n");
	call_out("msg04",10,this_player());
}

void msg04()
{
	if(this_object()->query("leave"))
	{
		tell_object(this_player(),"
骨骸王說：反正你遲早會變成我的一部份！哈哈～\n");
		this_object()->delete("leave");
	}
}

void msg05()
{
	tell_object(this_player(),"
骨骸王大笑：哈哈～好久沒吸收到這樣的精華了！
骨骸王說：我本想直接就把你吸收掉，讓你直接幻滅！不過，本王是守信用的！
"HIR"骨骸王說：廢物～本王就當同情你！送你一程吧！\n"NOR);
	call_out("msg06",7,this_player());
}

void msg06()
{
	tell_object(this_player(),"

骨骸王對著你喝道﹕「"+this_player()->query("name")+"﹗今日不是你死就是我活﹗」

"HIR"看起來骨骸王想殺死你﹗\n"NOR);
	call_out("msg07",2,this_player());
}

void msg07()
{
	tell_object(this_player(),HIY"

骨骸王大喝一聲使出『金。龍訣』

                    ◥▇◣                        ◥▇◣
                      ◥▇◣========================◥▇◣
========================◥▇◣========================◥▇◣
==========================▇▇==========================▇▇
========================◢▇◤========================◢▇◤
                      ◢▇◤========================◢▇◤
                    ◢▇◤                        ◢▇◤
                    
                    ◥▇◣                        ◥▇◣
                      ◥▇◣========================◥▇◣
========================◥▇◣========================◥▇◣
==========================▇▇==========================▇▇
========================◢▇◤========================◢▇◤
                      ◢▇◤========================◢▇◤
                    ◢▇◤                        ◢▇◤
\n\n"NOR);
	this_player()->start_busy(10);
	tell_object(this_player(),HIR"
你昏倒了...\n"NOR);
	call_out("msg08",2,this_player());
}

void msg08()
{
	tell_object(this_player(),HIR"你死了。\n"NOR);
	this_player()->move(__DIR__"b01");
	tell_object(users(),BLU"
【死亡快報】骨骸王(???)狂笑說:「可憐的"+this_player()->query("name")+", 死在我手上算是你的福氣。」\n"NOR);
}

void init()
{
	add_action("do_leave","leave");
	add_action("do_stay","stay");
}

int do_stay()
{
	if(this_object()->query("leave"))
	{
		call_out("msg04",1,this_player());
		return 1;
	}
return 0;
}

int do_leave()
{
	if(this_object()->query("leave") )
	{
		this_object()->delete("leave");
		this_player()->set("startroom","/open/area/forest/sh01");
		
		if(this_object()->query("/area/underpass/leave"))
			call_out("msg05",3,this_player());
		else
		{
			this_player()->set("/area/underpass/leave",1);
			tell_object(this_player(),"
骨骸王笑道：哈哈～想離開就要付出代價！而這個代價就是你的一切！\n");
			this_player()->set("/area/underpass/combat_exp",this_player()->query("combat_exp"));
			this_player()->set("/area/underpass/max_force",this_player()->query("max_force"));
			this_player()->set("/area/underpass/skill_force",this_player()->query_skill("force"));
			this_player()->set("/area/underpass/eff_gin",this_player()->query("eff_gin"));
			this_player()->set("/area/underpass/eff_kee",this_player()->query("eff_kee"));
			this_player()->set("/area/underpass/eff_sen",this_player()->query("eff_sen"));
			tell_object(this_player(),HIR"
你損失了"+this_player()->query("combat_exp")+"經驗值！
你最大內力為1，基本內功\技能降至1！
你精、氣、神降到1！\n"NOR);
			this_player()->set("combat_exp",1);
			this_player()->set_skill("force",1);
			this_player()->set("max_force",1);
			this_player()->set("eff_gin",1);
			this_player()->set("eff_kee",1);
			this_player()->set("eff_sen",1);
			this_player()->set("max_gin",1);
			this_player()->set("max_kee",1);
			this_player()->set("max_sen",1);
			this_player()->set("gin",1);
			this_player()->set("kee",1);
			this_player()->set("sen",1);
			this_player()->set("force",1);
			call_out("msg05",10,this_player());
		}
		return 1;
	}
return 0;
	
}
