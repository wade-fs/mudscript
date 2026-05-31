//星夜豔夢刀法 by roger

#include <combat.h>
#include <ansi.h>
void sp_attack(object me,object victim,object weapon,int damage);
inherit SKILL;
mapping *action = ({
(["action":HIG"$N輕舞手中的$w，刀光悠遠，像美麗的女子在情人的詩句下圈下一道眉批；刀色淡淡，如遠山之望眉，夕照之依稀；刀亦未盡，輕盈若詩，優美如夢"NOR,
        "damage":       30,
        "dodge":        200,
        "parry":         5,
        "force":        200,
        "damage_type":  "砍傷",
        ]),
(["action":HIY"$N一動，刀光突至，輕的就像一陣微風，柔得就像一抹月色。$n遇上這麼輕、這麼柔、這麼曼妙的刀法，一時不知如何抵禦。刀光倏沒。"NOR,
           "damage":           200,
           "dodge":            20,
           "parry":            10,
           "force":            200,
           "damage_type":  "割傷"
          ]),
(["action":HIC"$N拔刀，刀聲優美，像美麗女子的一聲清吟，像一串風過時的鈴鐺，蕩人心魄。刀揮動時還帶著一種音韻一般的聲響，掠起微微香氣，一種令人失魂的刀法。"NOR,
           "damage":      200,
           "dodge":       -5,
           "parry":       15,
           "force":       200,
        "damage_type":  "砍傷"
           ]),

(["action":HIW"$N拔出$w，刀光驚豔般的亮起，如流星自長空劃過，彷彿是初燃的燈影、處子的眼波；依稀是情人的美靨，猶似是落花醉樓人。那樣的不可抗拒，猶似身處豔夢中。"NOR,
        "damage":       200,
        "dodge":        -20,
        "parry":        20,
        "force":        200,
        "post_action":          (: sp_attack:),
        "damage_type": "劈傷"
            ]),
(["action":HIG"$N嘆息一聲，隨嘆息而出刀，刀像一首優美的詩，刀像夢。夢，夢裡花落，夢裡花落知多少？『夢裡花落』正是這一刀的名稱"NOR,
        "damage":       200,
        "dodge":        -20,
        "parry":        25,
        "force":        200,
        "damage_type": "劈傷"
        ]),
(["action":HIY"$N一刀揮出，像一道歲月的夢痕，帶著三分驚豔、三分瀟灑、三分惆悵，和一分的不可一世。"NOR,
        "damage":       200,
        "force":        200,
        "parry":        30,
        "dodge":        -10,
        "post_action":          (: sp_attack:),
        "damage_type": "劈傷"
        ]),
(["action":HIG"刀盪刀風，美麗的刀影，如情人的倩影；刀略起時，帶著微微的香氣與呻吟，刀彎處像美人的柔肩，刀落時還帶著些許\美麗的風華。刀清豔。"NOR,
        "damage":       200,
        "parry":        20,
        "dodge":        -10,
        "force":        200,
        "post_action":          (: sp_attack:),
        "damage_type": "砍傷"
        ]),
(["action":HIY"$N出刀，劈出『細雨黃昏』，刀美如夢，彩色繽紛，尤其是血也似的濺紅。刀迴轉，帶出殘酷的現實；刀過處，黑裡濺出厲紅。每一刀揮出，$N的生命悽豔亮烈、優美如夢"NOR,
        "damage":       200,
        "force":        200,
        "parry":        30,
        "dodge":        0,
        "post_action":          (: sp_attack:),
        "damage_type":  "砍傷"
        ]),

});
int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_force") < 50)
        return notify_fail("你的內力不夠，沒有辦法練星夜豔夢刀法。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade")
                return notify_fail("你必須先找一把刀才能練刀法。\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

void sp_attack(object me,object victim, object weapon,int damage)
{
 int i;
 if(random(100) > 50){
message_vision(HIM"\n那麼驚豔的刀法，看來，誰都願意為這一刀而死，為這一刀而生，為這一刀而不顧生死\n"NOR,me);
  me->set_temp("conti",1);
   for(i=0;i<3;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
  me->delete_temp("conti");
                     }
}

