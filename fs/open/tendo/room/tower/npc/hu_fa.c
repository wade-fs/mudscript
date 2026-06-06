#include <ansi.h>

inherit NPC;

int special_att ();

void create()
{
        set("title","冥殿殿士");
        set_name("貼身護法",({"hu-fa","fa"}));
        set("max_gin",10000);
        set("gin",10000);
        set("race","野獸");
        set("age",520);
        set("str", 65);
        set("max_kee", 12000);
        set("kee", 12000);
        set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
        set("verbs", ({ "bite"}));
        set("combat_exp",1000000);
        set("attitude","aggressive");
        set_temp("apply/armor",60);
        set_temp("apply/attack", 60);
        set("force_factor",10);
        set("bellicosity",1200);
        set("max_sen",10000);
        set("sen",10000);
        set("max_atman",10000);
        set("atman",10000);
        set("max_mana",10000);
        set("mana",10000);
        set("max_force",10000);
        set("force",10000);
        set("cor", 40);
        set("cps", 25);

        set("chat_chance_combat",28);
        set ("chat_msg_combat", ({(: special_att :)}));

        command("wield all");
        command("wear all");
        set_skill("hell-evil",75);
        map_skill("parry","hell-evil");
        set("unarmed",75);
        map_skill("unarmed","hell-evil");
        set_skill("dodge",75);
        set_skill("fly-steps", 60);
        map_skill("dodge","fly-steps");
        set_skill("parry",75);
	setup();
	add_money("gold",7);
}

int special_att ()
{
	object me = this_object ();
	object *enemy = query_enemy (), victim;
	int i = sizeof (enemy), damage;
	victim = enemy[random(i)];
	message_vision(HIB+
"          －－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  一  式 －－" + NOR + "
                  " + HIB + "～『  " + HIY + "妖 魔 聚 鼎" + HIB + "  』～" + NOR + "
          " + HIW + "貼身護法身形倏而騰飛三丈,凌空劈出一" + NOR + "
    " + HIW + "股掌勁,綿綿掌影,如江河缺堤似,暴瀉而下,掌風如激流" + NOR + "
                  " + HIW + "般地向你隔空劈來!" + NOR,me);
  
	if (random (2) >= 1)
	{
	damage = (victim->query ("max_kee") / 30);

	message_vision(HIR + "$N不幸被掌風劈中 , 頓時全身血如泉湧.\n" + NOR,victim);
	victim->apply_condition ("bleeding", random (i * i));
	victim->receive_damage ("kee", damage, me);
	COMBAT_D->report_status (victim, 0);
	}else{
	message_vision(HIW + "只可惜離$N差了一點, 劈到地上, 轟的一聲巨響, 地皮頓時裂了開來.\n" + NOR,victim);
	}
	return 1;
}



