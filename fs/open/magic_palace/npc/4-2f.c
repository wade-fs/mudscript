#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("影‧巴斯八",({"False King","false king"}));
        set("long",@LONG
巴斯八的幻影。

LONG);
	set("gender","男性");
	set("class","dancer");
	set("nickname",HIG + "萬世魔王" + NOR);
	set("title",HIM + "萬世教主" + NOR);
	set("family/family_name","夜夢小築");
	set("combat_exp",1000000);
	set("attitude","aggressive");
	set("score",20000);
	set("bellicosity",3000);
	set("age",50);
	set("str", 35);
	set("cor", 35);
	set("cps", 35);
	set("int", 35);
	set("spi", 35);
	set("per", 35);
	set("kar", 35);
	set("con", 35);
	set("force",9000);
	set("max_force",9000);
	set("mana",2000);
	set("max_mana",1000);
	set("atman",9999);
	set("max_atman",1000);
	set("force_factor", 10);
	set("max_kee",5000);
	set("max_gin",2000);
	set("max_sen",2000);
	set_skill("unarmed",90);
	set_skill("dreamforce",90);
	set_skill("dreamdance",90);
	set_skill("paull-steps",90);
	set_skill("move",90);
	set_skill("dodge",90);
	set_skill("parry",90);
	set_skill("force",100);
	map_skill("dodge","paull-steps");
	map_skill("force","dreamforce");
	map_skill("move","paull-steps");
	map_skill("unarmed","dreamdance");
	set_temp("armor_vs_force",100);
	set_temp("apply/armor",50);
	set_temp("apply/attack",20);
	set_temp("apply/damage",20);
	setup();
	carry_object("/open/magic-manor/obj/fire-color-ribbon");
}

void unconcious ()
{
        message_vision(HIG + "重掌擊中巴斯八後，卻發現只是打中命運的幻影而已。\n" + NOR,this_player());
        destruct(this_object());
}
