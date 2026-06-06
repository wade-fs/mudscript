//shuryu.c
#include <ansi.h>
inherit NPC;
void do_special();

mapping *action = ({
([     "action"     :   "$N大叫：『盧  山  龍  飛  翔』，$n感到一條青龍飛過$n的身邊。",
                "dodge"      :   -35,
		"parry"      :   -35,
                "damage"     :    140,
                "force"      :    100,
                "damage_type":   "內傷",
           ]),
([     "action"     :   "$N的身後突然浮現了龍，$N大喝：『盧  山  昇  龍  霸』，$n只看到一條巨
龍從$N的身後帶著一股大力向$n這襲捲而來！！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    300,
                "force"      :    200,
                "damage_type":   "內傷",
           ]),
([    "action"     :   "$N將從山羊座黃金聖鬥士阿修羅那學來的技巧默想了一次，集中全身的小宇
宙，使出了『黃  金  聖  劍』！！！把$n的身影幾乎要砍成兩半了。",
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    270,
                "force"      :    300,
                "damage_type":   "砍傷",
            ]),
   });

void create()
{
        set_name("紫龍", ({"shuryu"}));
        set("age",15);
        set("long","他是屬於青銅級的聖鬥士，在三大聖戰中一直是護衛著雅典娜女神。\n"
        "而現在的實力是遠超過黃金聖鬥士，是雅典娜忠心的護衛。\n");
        set("title",HIG + "青龍座聖鬥士" + NOR);
        set("gender","男性");
        set("class","聖鬥士");
        set("str",30);
        set("cps",30);
        set("kar",30);
        set("spi",30);
        set("int",30);
        set("cor",30);
        set("attitude","herosim");
        set("max_gin",1000);
        set("max_kee",3000);
        set("max_sen",1000);
        set("gin",2000);
        set("kee",3000);
        set("sen",2000);
        set("combat_exp",1450000);
        set("max_force",10000);
        set("force",10000);
        set("max_atman",5000);
        set("max_mana",5000);
        set("atman",5000);
        set("mana",5000);
        set("force_factor",30);
        set_skill("dodge",200);
        set_skill("unarmed",200);
	set("chat_chance_combat",30);
        set("chat_msg_combat",({
        (: do_special :)
        }));
        set_temp("apply/armor",390);
        set_temp("apply/damage",100);
        setup();
        set("default_actions", (: call_other, __FILE__,"query_action" :));
        reset_action();
}

mapping query_action()
{
        return action[random(sizeof(action))];
}
void do_special()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];

                message_vision(
HIG + "\n紫龍想了一會，大喝一聲：看我的『盧  山  亢  龍  霸』～～～\n",target);
                message_vision(
HIR + "\n紫龍的身影突然在$N身後出現，雙手架著$N，直向宇宙飛去！！\n" + NOR,target);
                target->receive_wound("kee",random(300+350));
                COMBAT_D->report_status(target);
  }
