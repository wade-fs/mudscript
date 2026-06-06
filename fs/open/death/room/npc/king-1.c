#include <ansi.h>

inherit NPC;
void do_special();
void use_poison(object me, object viction);
 
mapping *action = ({
        ([
                "action"     :  "$N怒吼一聲，用龐大的身軀向$n直撲而來",
                "dodge"      :  -20,
                "parry"      :  -20,
                "damage"     :   25,
               "damage_type":  "骨折"
        ]),
        ([
                "action"     :  "$N抽身一躍，雙手抱膝成球狀撞向$n，威力萬鈞，正是一招『火龍金魔體』",
                "dodge"      :  -30,
                "parry"      :   25,
                "damage"     :   40,
                "damage_type":  "骨折",
        ]),
        ([
                "action"     :   "$N身法忽變，一招『魔風鬼爪』身體隨風而動，飄乎不定，巨爪出手詭異，抓向$n",
                "dodge"      :   -35,
                "parry"      :    15,
                "damage"     :    65,
                "damage_type":   "抓傷",
            "post_action"    :   (: use_poison :)
        ]),
        ([
                "action"     :   "$N高聲長嘯，一招『魔音穿腦』，震得$n七孔滲血", 
                "dodge"      :   -20,
                "parry"      :    25,
                "damage"     :    90,
                "damage_type":   "內傷"
        ]),
        ([
                "action"     :   "$N雙膝微屈，做跪拜投降之勢，卻趁機雙爪猛攻$n下盤，正是一招『鬼魅拜月』",
                "dodge"      :    30,
                "parry"      :   -30,
                "damage"     :    160,
                "force"      :    160,
                "damage_type":   "抓傷",
            "post_action"    :   (: use_poison :)
        ]),
        ([
                "action"     :   "$N身形一轉使出『惡鬼招魂』，霎時風聲鶴唳，爪影重重，忽的一爪成弧狀劃向$n的喉嚨",
                "dodge"      :   -50,
                "parry"      :    15,
                "damage"     :    130,
                "force"      :    60,
                "damage_type":   "割傷",
                "weapon"     :   "毒爪",
            "post_action"    :   (: use_poison :)
        ]),
         ([     "action"     :   "$N狂嘯一聲，使出『滅天絕地暴風掌』，剎那間掌影已攏罩$n的全身",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    230,
                "force"      :    200,
                "damage_type":   "內傷",
           ]),
          ([    "action"     :   "$N臉色一沈，集全靈之力，使出必殺招『魔極之源』",
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    200,
                "force"      :    180,
                "damage_type":   "割傷",
                "weapon"     :   "毒爪",
            "post_action"    :   (: use_poison :)
            ]),
   });
 
void create()
{
        set_name("秦廣明王",({"king chin kuang","king","chin","kuang"}));
        set("race", "妖魔");
	set("age",1000);
        set("long","你看的一個威嚴的老者，正手撚鬍鬚，雙目精光逼視著你，彷彿要看進你內心深處\n");
        set("str",30);
        set("cps",30);
        set("kar",20);
        set("spe",20);
        set("int",20);
        set("cor",30);
        set("limbs", ({"頭部", "胸部", "腿部", "手臂"}) );
        set("verbs", ({ "bite"}));
 
        set("attitude","herosim");
        set("combat_exp",100000);
        set_skill("dodge",260);
        set_skill("unarmed",200);
        set("chat_chance",10);
        set("chat_msg",({

          "有心為善，雖善不賞;無心為惡，雖惡不罰。\n",
          "既然來到地獄，就該有接受酷刑的準備。\n",
        }));

        set("chat_chance_combat",200);
        set("chat_msg_combat",({
        (: do_special :)
        }));
        set_temp("apply/defend",100000);
        set_temp("apply/armor",100000);
        setup();
        set("default_actions", (: call_other, __FILE__,"query_action" :));
	reset_action();
}
 
mapping query_action()
{
        return action[random(sizeof(action))];
}
void use_poison(object me, object viction)
{
// here can write many thing u want
   viction->apply_condition("dark_poison",100+viction->query_condition("dark_poi
son") );
}
void do_special()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];

                message_vision(
        HIY + "\n夜叉大喝一聲，看我的『夜叉獨門絕技』～～～毒  龍  鑽\n",target);
                message_vision(
        HIB + "\n夜叉手上的雙爪突然快速旋轉由意想不到的位置攻擊!!\n" + NOR,target);
                target->receive_wound("kee",random(50+100));
                COMBAT_D->report_status(target);

  }
