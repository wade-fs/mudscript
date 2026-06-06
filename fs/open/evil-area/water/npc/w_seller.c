inherit F_VENDOR;
#include <ansi.h>
inherit SSERVER;

void create()
{
	set_name("水羚",({"water seller","seller"}));
	set("long","
火辣的體型，簡直與人間的西施有的比，佼好的臉孔加上甜美的笑容使得
它成為琰揚湖中最有名的販賣者，每個人幾乎都醉倒在她那回濛一笑，就
連你也不例外。\n");
	set("title",HIC + " 賣 盡 天 下 " + NOR);
	set("nickname",HIG + " 琰 揚 商 販 " + NOR);
	set("age",1293);
        set("gender", "女性" );
	set("kar",30);
	set("per",30);
	set("str",10);
	set("cor",10);
	set("combat_exp",100000);
	set("max_gin",10000);
	set("max_kee",10000);
	set("max_sen",10000);
	set("max_force",100000);
        set("force_factor",10);
	set("inquiry",([
		"邪靈界":"邪靈界??...邪靈界不就是這裡嗎??..你怎麼問這麼奇怪的問題??\n",
		"水邪將":"喔～水邪將就是水柔纏啊～聽說她在轉世成邪靈之前，是一個人類ㄋ～\n",
		"水柔纏":"嗯～她是管理我們琰揚湖的邪將，不過...她似乎心地太好..不適合當邪將...\n",
	]));

        set("vendor_goods", ({
		"/open/evil-area/water/npc/obj/cloth",
		"/open/evil-area/water/npc/obj/dagger",
		"/open/evil-area/water/npc/obj/cap",
		"/open/evil-area/npc/obj/enemy_pill",
		"/open/evil-area/npc/obj/damage_pill",
		"/open/evil-area/water/npc/obj/dumpling",
		"/open/evil-area/water/npc/obj/ice",
		"/open/evil-area/water/npc/obj/bag",
        }) );
	set_skill("unarmed",100);
	set_skill("move",100);
	set_skill("dodge",100);
	set_skill("force",100);
	setup();
}

void heart_beat()
{
	object ob,env,target;

	ob = this_object();
	env = environment(ob);
    	target = offensive_target(ob);
		if( env == environment(target) )
		{
                message_vision(HIW + "
\n$N大叫：救命啊～有人要殺我啊～

" + HIR + "$N一大叫，週遭所有的邪靈馬上圍了過來，$N趁機偷咬了$n一下就逃跑了～\n\n" + NOR,ob,target);
                target->receive_wound("kee",100);
                COMBAT_D->report_status(target,1);
                target->start_busy(1);
		destruct(ob);		
		}
set_heart_beat(1);
::heart_beat();
}

void greeting(object ob)
{
int gender,per;

        gender = 0;
        per = ob->query_per();

        if( !ob || environment(ob) != environment() )
		return;

        if( ob->query("gender") == "女性")
        	gender = 1;

	if( per < 18 )
	{
		if( gender )
			command("say 好個妹子啊～妳的長相可跟我有的比ㄋ～");
		else
			command("say 這位邪雄獸～你可長的獸性十足啊～讓小妹子我心動不已ㄋ～");
	}
	else
	{
		if( gender )
			command("say 妹子啊～不是我說妳～妳來這也不該把自己打扮的跟人一樣啊～");
		else
			command("say 那位長的跟人沒兩樣的邪雄獸～你可要小心被這裡的邪獸打死喔～");
	}
	command("grin "+ob->query("id"));
	command("say 來來～我這些可都是外出必備品啊～買了一定不會吃虧～\n");
}
