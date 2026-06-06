//shun.c
#include <ansi.h>
inherit NPC;
void do_special();

mapping *action = ({
([     "action"     :   "$N連環出招,一招『梅開隨風飄』左攻右擊,如狂風般的飄流,
$n似乎無法避開這柔剛並進的一擊.",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    180,
                "force"      :    200,
                "damage_type":   "割傷",
           ]),
([     "action"     :   "$N倒舉妖刀,以極美妙的姿勢持刀向前,正是四季花舞刀法中
最柔美的招式『蘭香傳四方』,$n已被這美麗的景像
給吸引而忘了攻擊",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    200,
                "force"      :    200,
                "damage_type":   "砍傷",
           ]),
([    "action"     :   "$N刀起斜放,動作清雅脫俗正是『竹出百花殘』刀訣的主要宗旨
$n看到這刀招一出覺的相行見慚,竟然有自廢武學而拜$N為師的念頭.",
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    250,
                "force"      :    180,
                "damage_type":   "砍傷",
            ]),
([    "action"     :    "$N持刀劃半弧成半圓,欺敵之招『菊語採人心』自然而生,$n
被$N看破心意強得先機,$n已陷入一陣刀網之中..",
                "dodge"      :  -35,
                "parry"      :  -35,
                "force"      :   200,
                "damage"     :   200,
                "damage_type":   "破體之傷",
            ]),                
   });

void create()
{
        set_name("河內美加", ({"girl"}));
        set("age",15);
        set("long","她是女影門傳人的師妹,與旁邊的田中惠子是鑾生姊妹,兩姊妹分別\
練了『四季花舞刀法』的上半部與下半部,妹妹河內美加練的是下半部刀法\n");
        set("title",HIM"女影門究極奧義流第四代弟子"NOR);
        set("gender","女姓");
        set("class","killer");
        set("str",30);
        set("cps",30);
        set("kar",30);
        set("spi",30);
        set("int",30);
        set("cor",30);
        set("attitude","herosim");
        set("max_gin",1000);
        set("max_kee",1000);
        set("max_sen",1000);
        set("gin",1000);
        set("kee",1000);
        set("sen",1000);
        set("combat_exp",500000);
        set("max_force",1000);
        set("force",1000);
        set("max_atman",1000);
        set("max_mana",1000);
        set("atman",1000);
        set("mana",1000);
        set("force_factor",10);
        set_skill("dodge",100);
        set_skill("nine-steps",100);
        map_skill("dodge","nine-steps");
        set_skill("unarmed",70);
        set("chat_chance_combat",15);
        set("chat_msg_combat",({
        (: do_special :)
        }));
        set_temp("apply/armor",100);
        set_temp("apply/damage",78);
        setup();
        carry_object("/open/japan/obj/super-cloth.c")->wear();
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
HIW "\n美加使出四季花舞刀法中最強的祕招,隨著刀法的變換演化出『四花齊飛放』的超強特攻\n",target);
                message_vision(
HIY "\n四季刀法不斷變化,$N已被四周群花奔放之景給吸引,不知不覺已身受中傷
\n"NOR,target);
                target->receive_wound("kee",random(50+150));
                COMBAT_D->report_status(target);

  }
