//shun.c
#include <ansi.h>
inherit NPC;
void do_special();

mapping *action = ({
([     "action"     :   "$N大叫：『星  雲  鎖  鍊』，剎那間鎖鍊已經把$n的全身包住了！！！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    180,
                "force"      :    200,
                "damage_type":   "內傷",
           ]),
([     "action"     :   "$N大叫：『星  雲  鎖』，不知從那冒出來的鎖鍊將$n的全身上下刺成血肉
糢糊的一團。",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    200,
                "force"      :    200,
                "damage_type":   "刺傷",
           ]),
([    "action"     :   "$N將聖衣脫下來，集中了全身的小宇宙，使出了『星  雲  氣  流』，漸漸的
$n的呼吸感到困難，只見一股強大的氣流把$n帶上天空隨著風到處亂撞！！！",
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    250,
                "force"      :    180,
                "damage_type":   "撞傷",
            ]),
   });

void create()
{
        set_name("瞬", ({"shun"}));
        set("age",15);
        set("long","他是屬於青銅級的聖鬥士，在三大聖戰中一直是護衛著雅典娜女神\n"
        "而現在的實力是遠超過黃金聖鬥士，是雅典娜忠心的護衛。\n");
        set("title",HIM"仙女座"NOR+ HIG"聖鬥士"NOR);
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
        set("gin",1000);
        set("kee",2000);
        set("sen",1000);
        set("combat_exp",1370000);
        set("max_force",10000);
        set("force",10000);
        set("max_atman",5000);
        set("max_mana",5000);
        set("atman",5000);
        set("mana",5000);
        set("force_factor",30);
        set_skill("dodge",200);
        set_skill("unarmed",200);
        set("chat_chance_combat",45);
        set("chat_msg_combat",({
        (: do_special :)
        }));
        set_temp("apply/armor",380);
        set_temp("apply/damage",78);
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
HIW "\n瞬把聖衣脫下，燃燒了自己的小宇宙，大喝一聲：看我的『星　雲　風　暴』～～～
\n",target);
                message_vision(
HIY "\n瞬的身邊突然傳來一道道的颶風，剎那間就將$N身影全部給捲進去了！！
\n"NOR,target);
                target->receive_wound("kee",random(200+250));
                COMBAT_D->report_status(target);

  }
