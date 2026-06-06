//shun.c
#include <ansi.h>
inherit NPC;
void do_special();

mapping *action = ({
([     "action"     :   "$N使快妖刀,一招『春風彩蝶飛』已然使開,刀光閃爍不定,婉如彩蝶四處飛舞
$n一失神全身上下已被砍傷無數處.",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    180,
                "force"      :    200,
                "damage_type":   "割傷",
           ]),
([     "action"     :   "$N雙手持妖刀,刀起刀落,正是四季花舞刀法中的『夏夜星空明』,
$n眼睜睜的看著橫刀砍來卻似乎無法抵抗",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    200,
                "force"      :    200,
                "damage_type":   "砍傷",
           ]),
([    "action"     :   "$N眉頭緊鎖,殺意急升,『秋意愁不斷』之起手式看似完成妖刀在
$n的四周飄盪化為無數楓葉落地,$n一不定神,刀氣已經逼到眼前",
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    250,
                "force"      :    180,
                "damage_type":   "砍傷",
            ]),
([    "action"     :    "$N手中妖刀越使越快,刀風冷冽,『冬雨寒若雪』刀招應聲而出,
$n心中大驚,但為時已晚$n已陷入險境無法閃躲.",
                "dodge"      :  -35,
                "parry"      :  -35,
                "force"      :   200,
                "damage"     :   200,
                "damage_type":   "破體之傷",
            ]),                
   });

void create()
{
        set_name("田中惠子", ({"girl"}));
        set("age",15);
        set("long","她是女影門傳人的師妹,與旁邊的河內美加是鑾生姊妹,兩姊妹分別\
練了『四季花舞刀法』的上半部與下半部,姊姊田中惠子練的是上半部刀法\n");
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
        set_skill("unarmed",70);
        map_skill("dodge","nine-steps");
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
HIW "\n惠子使出四季花舞刀法中最強的祕招,隨著刀法的變換演化出『四時轉不息』的超強特攻\n",target);
                message_vision(
HIY "\n四季刀法不斷變化,$N已被四周春夏秋冬之變化給吸引,不知不覺已身受中傷
\n"NOR,target);
                target->receive_wound("kee",random(50+150));
                COMBAT_D->report_status(target);

  }
