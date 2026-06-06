inherit NPC;
#include <ansi.h>
#include "log/log.c"

void create()
{
	set_name("極火",({"huo wu cing","cing"}));
	set("long","極火山寨的大寨主，極火功\無人能及，傳說此技巧是焚天魔王直接傳授的。
不過他之所以會在中央驛站的理由，是為了獎賞tomorrow打倒強大的他。
" + HIY + "(請輸入gift領取獎賞)" + NOR + "
\n");
	set("race", "人類");
	set("gender","男性");
	set("title",HIR + "極火山寨 大寨主" + NOR);
	set("nickname",HIC + "極火無敵" + NOR);
        set("age",40);
        set("attitude","aggressive");
        set("combat_exp",1000000);
        set("max_gin",20000);
        set("eff_gin",20000);
        set("gin",20000);
        set("max_kee",40000);
        set("eff_kee",40000);
        set("kee",40000);
        set("max_sen",20000);
        set("eff_sen",20000);
        set("sen",20000);
        set("max_force",300000);
        set("force",300000);
        set("force_factor",60);
        set("str",50);
        set("cor",50);
        set("int",10);
        set("spi",10);
        set("cps",50);
        set("per",10);
        set("con",50);
        set("kar",10);
        set_skill("force",200);
        set_skill("parry",200);
        set_skill("move",200);
        set_skill("dodge",200);
        set_skill("fireforce",200);
        set_skill("mogi-steps",200);
        set_skill("firestrike",200);
        map_skill("unarmed","firestrike");
        map_skill("parry","firestrike");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("force","foreforce");
        set("functions/gold-fire/level",200);
        set("quest/gold-fire",1);
	set("quest/new_gold_fire",1);			
        set_temp("no_die_soon",1);			
        set_temp("apply/armor",200);			
        set_temp("apply/defense",200);			
        set_temp("apply/damage",200);			
        set_temp("apply/attack",200);
        set_temp("no_steal",1);
        set("no_kill",1);
        set("no_fight",1);
	setup();
}

void init()
{
	add_action("do_gift","gift");
}

int accept_fight(object ob)
{
	destruct(this_object());
	return 0;
}

int accept_kill(object ob)
{
	destruct(this_object());
	return 0;
}

int do_gift()
{
	int sk;
	if(this_player()->query("id")!="tomorrow")
		return 0;
	tell_object(users(),HIW + "
	中央驛站發出一道白色強光直射雲霄！
	極火  運行畢生的功\力，將所有內力傳入 "+this_player()->query("name")+" 中！\n\n" + NOR);
	tell_object(this_player(),"極火笑道：哈哈～格老子的，算你行，改天我們再較量較量！\n語畢，極火轉身離開了中央驛站。\n");
	sk=(int)this_player()->query_skill("force",1);
	sk=sk+2;
	this_player()->set_skill("force",sk);
	write_log(this_player(),"拿到add_skill 2 目前force技能為"+sk+" ");				////記錄拿到禮物
	destruct(this_object());
	return 1;
}
