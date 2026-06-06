// enable-archery.c
// by airke
// By Swy 最後修正 QC 98/6/23
#include <combat.h>
#include <ansi.h>
inherit SKILL;

void god_att(object me, object victim, object  weapon, int damage);
void shooting_att(object me,object victim, object weapon,int damage);

// 有箭時的敘述 $w是弓 $c 是箭
//應玩家要求.增加連擊 by poloer
mapping *arrow_action = ({
        ([      "action":
"$N心中一急，迅速將$c搭於$w之上，使出流星箭法第一式" + HIC + "「一洩千里」" + NOR + "，箭勢如洪水狂洩般朝$n$l飛射而去",
                "dodge":        -100,
                "damage":       130,
                "parry":        -100,
                "force":        130,
                "damage_type": "射傷",
        ]),
([        "action":
"$N將手上$c迅速搭於$w分為兩次射出，使出流星箭法第二式" + HIG + "「雙龍出海」" + NOR + "﹐分射出之$c如雙龍狂噬般朝$n而去",
                "dodge":        -100,
                "damage":       130,
                "force" :       130,
                "damage_type": "射傷",
                "parry":        -100,
        ]),
        ([      "action":
"$N霸氣突漲，將手中$c迅速搭於$w三箭齊發，使出流星箭法第三式" + HIB + "「三分鼎足」" + NOR + "﹐射出的$c似含三國鼎立之霸氣分三處向$n急射而去",
                "dodge":        -100,
                "damage":       130,
                "force":         130,
                "parry":        -100,
                "damage_type": "射傷",
        ]),
        ([      "action":
"$N被$n攻勢所驚嚇，將手中$c迅速搭於$w之上分射四箭，使出流星箭法第四式" + HIY + "「四面楚歌」" + NOR + "﹐射出的$c似有靈性般由$n前後左右四面飛射而去",
                "dodge":        -100,
                "damage":       130,
                "force":        130,
                "parry":        -100,
                "damage_type": "射傷",
        ]),
        ([      "action":
"$N心中殺氣突漲，將手中$c迅速搭於$w上五箭齊射，殺氣融合於$c使出流星箭法第五式" + HIW + "「五馬分屍」" + NOR + "﹐$c朝$n頭及雙手雙腳齊射而去",
                "dodge":        -100,
                "damage":       110,
                "force":        130,
                "parry":        -100,
                "damage_type": "射傷",
        ]),
        ([      "action":
"$N將手中$c迅速搭於$w，射出之際融入旋轉氣勁使出流星箭法第六式" + HIG + "「六道輪迴」" + NOR + "﹐$c急速旋轉朝著$n急射而去",
                "dodge":        -100,
                "damage":       115,
                "foece":        130,
                "parry":        -100,
                "damage_type": "射傷",
        ]),
        ([      "action":
"$N將手中$c迅速搭於$w連續射出七箭，使出流星箭法第七式" + HIM + "「七星連線」" + NOR + "，$c七箭一箭接著一箭形成一線朝$n急射而去",
                "dodge":        -100,
                "damage":       130,
                "force":        130,
                "parry":        -100,
                "damage_type": "射傷",
        ]),
        ([      "action":
"$N將手中$c迅速搭於$w緩緩射出，使出流星箭法第八式" + HIC + "「八仙過海」" + NOR + "，$c如同仙人過海般縹緲般令$n不知所措",
                "dodge":        -100,
                "damage":       130,
                "force":        130,
                "parry":        -100,
                "damage_type": "射傷",
                "post_action":  (: god_att :),
        ]),
        ([      "action":
"$N將手中$c迅速搭於$w緩緩射出九箭，使出流星箭法第九式" + HIR + "「九九歸元」" + NOR + "，射出九箭合一，令$n無法招架",
                "dodge":        -100,
                "damage":       130,
                "parry":        -100,
                "force":        130,
                "damage_type": "射傷",
                "post_action":  (: shooting_att :),
        ]),

});

// 下面是沒箭時的攻擊敘述

mapping *bow_action = ({
        ([      "action":               "$N舉起$w狠狠地往$n$l砸去",
                "dodge":        -10,
                "damage":       10,
                "parry":        -10,
                "damage_type":  "瘀傷",

        ]),
        ([      "action":               "$N吃力地揮舞$w試著打傷$n",
                "dodge":        -5,
                "damage":       15,
                "parry":        -10,
                "damage_type":    "瘀傷",

        ]),
});

int valid_learn(object me)
{
        object ob;

if(me->query_skill("archery",1)<15)
                return notify_fail("要練流星箭法要先有相當的弓箭基礎。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type")!="archery")
                return notify_fail("你手上要有弓箭才能練流星箭法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="archery" || usage=="parry";
}


mapping query_action(object me, object weapon)
{
  int skill_level, limit;
  object wpn = me->query_temp("weapon");
  int i;
//以下幾行都是必須的..
//-----------------------------------------------------
//
// i = 目前弓上的箭數
  i=wpn->query("arrow/amount");
if ( !userp(me) )
        i ++;

//戰鬥中射完也必須將弓初始化
// 1的時候就可以初始化....因為初始化完還會攻擊一次

 if(i==1) {
        tell_object(me, "\n你的" + wpn->query("arrow/name") + "用完了﹗\n\n");
        wpn->set("arrow/id","none");
        wpn->set("arrow/name","空的");
        wpn->set("weapon_prop/damage",wpn->query("bow/attack"));

  }
  if (i > 0) {
        i--;
        wpn->set("arrow/amount",i);
                // 呼叫有箭時的敘述
        return arrow_action[random(sizeof(arrow_action))];
  }

  if( i <= 0) {
                //呼叫沒箭的攻擊敘述
        return bow_action[random(sizeof(bow_action))];
  }
//----- under by poloer from --------------------------------------------


        skill_level=(int)me->query_skill("god-shooting", 1);
       if (skill_level < 10)
                return arrow_action[random(2)];
        else if (skill_level < 20 )
                return arrow_action[random(3)];
        else if (skill_level < 30 )
               return arrow_action[random(4)];
                else if (skill_level < 50 )
                return arrow_action[random(5)];
               else if (skill_level < 70 )
                       return arrow_action[random(6)];
               else if (skill_level < 80 )
                      return arrow_action[random(6)+1];
        else if(skill_level<90)
return arrow_action[random(6)+2];
        else
return arrow_action[random(6)+3];


}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的內力或氣不夠﹐不能練流星箭法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("marksman")+"/god-shooting/"+action;
}

void god_att(object me, object victim, object  weapon, int damage)
{
if((random(80)<me->query_skill("iceforce",1))&&!me->set_temp("break"))
{
victim->start_busy(1);
message_vision(HIB + "$N暗使冰心訣之陰寒內勁，將$n受內勁所困動彈不得。\n" + NOR, me, victim);

}
}

void shooting_att(object me, object victim, object  weapon, int damage)
{
        int lose, i;
int bellpower = (int)me->query_cps()/3;
        // modify by oda
        // combat_exp 之比較在自身之 exp 加上 random
        // lose = skill/10 + 1 改為 random(skill/10) + 3
        // 增加連擊完畢 busy 一回合
if(random(100)<70)
        {
        if(bellpower > 5) bellpower=5;
        lose=random(10);
                me->set_temp("berserk", 1);
                for(i = 0;i < lose; i++)
                {
       message_vision(HIR + "$N拿起數支箭使勁的往$n連射過去。\n" + NOR, me,victim);
                       }
                victim->add("kee",-50);
                me->delete_temp("berserk");
                message_vision(HIW + "一陣混亂後，$N用勁過度，趕緊趁機調息。\n" + NOR,me);

        }
}
