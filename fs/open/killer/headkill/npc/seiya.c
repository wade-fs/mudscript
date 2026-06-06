//seiya.c
#include <ansi.h>
inherit NPC;
void do_special();

mapping *action = ({
([     "action"     :   "$N大叫：『天馬流星拳』，剎那間拳影已攏罩$n的全身",
                "dodge"      :   -35,
                "parry"      :   -35,
		"damage"     :190,
                "force"      :    200,
                "damage_type":   "內傷",
           ]),
([    "action"     :   "$N集中全身的小宇宙，對$n使出了『天馬彗星拳』",
                "dodge"      :    40,
                "parry"      :   -50,
		"damage"     :240,
                "force"      :    180,
                "damage_type":   "內傷",
            ]),
   });

void create()
{
        set_name("星矢", ({"seiya"}));
        set("age",15);
        set("long","屬於青銅級的聖鬥士，在三大聖戰中一直是護衛著雅典娜女神\n"
        "而現在的實力是遠超過黃金聖鬥士，是雅典娜忠心的護衛。\n"
        "夢幻的佩加索斯，傳說的天馬，展開他那雪白的羽翼迎向一切挑戰。\n");
	set("title",HIW"天馬座"NOR+ HIG"聖鬥士"NOR);
        set("gender","男性");
        set("str",30);
        set("cps",30);
        set("kar",30);
        set("spe",30);
        set("int",30);
        set("cor",30);
        set("attitude","herosim");
        set("max_gin",1000);
        set("max_kee",3000);
        set("max_sen",1000);
        set("gin",1000);
        set("kee",3000);
        set("sen",1000);
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
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
        (: do_special :)
        }));
        set("inquiry",([
	    "雅典娜" : "她是聖域的守護者。\n",
	    "教皇" : "這可惡的教皇，其實是雙子座黃金聖鬥士。\n",
	    "雙子座" : "十三年前的錯誤，倒制現在的情況。\n",
	    "情況" : "現在女神的性命有危險了，$N是來幫助我們的嗎？\n",
            ]) );
	set_temp("apply/armor",400);
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
	HIY "\n星矢大喝一聲：看我的「天  馬  彗  星  拳」～～～\n"NOR,target);
                message_vision(
HIW"\n星矢的拳影突然一變，由流星融合成彗星了！！$N感到一股大力從彗星中傳來，等$N回過神來時，星矢的身影已經在$N的身後了。\n"NOR,target);
                target->receive_wound("kee",random(200+250));
                COMBAT_D->report_status(target);

  }
