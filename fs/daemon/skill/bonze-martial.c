// 少林拳法 by swy
//調整skill 為了整合在seventy-two中 與判斷使用者或被攻擊方是否存在的判斷 by blazakira 2011/10/9

#include <combat.h>
#include <ansi.h>
inherit SKILL;

void movedown1(object me,object target,object weapon,int damage);
void movedown2(object me,object target,object weapon,int damage);
void movedown3(object me,object target,object weapon,int damage);

mapping *action = ({
// 1
  (["action"     : "$N握緊雙拳使出"+HIR+"『鐵臂功\』"+NOR+"，橫著手臂硬是往$n的$l砸去。",
    "damage"     : 30,
    "force"      : 160,
    "damage_type": "瘀傷",
  ]),
// 2
  (["action"     : "$N翻身迴力，把真氣往下盤一送使出"+HIR+"『腿踢功\』"+NOR+"，奮力往$n一踢。",
    "damage"     : 60,
    "force"      : 160,
    "damage_type": "踢傷",
  ]),
// 3
  (["action"     : "$N下紮馬步，背轉身子，一招"+HIY+"『鐵頭功\』"+NOR+"，撞的$n人仰馬翻。",
    "damage"     : 80,
    "force"      : 160,
    "damage_type": "撞傷",
  ]),
// 4
  (["action"     : "$N看出$n破綻使出"+HIY+"『霸王肘』"+NOR+"，$n差點被頂倒在地。",
    "damage"     : 80,
    "force"      : 160,
    "damage_type": "撞傷",
  ]),
// 5
  (["action"     : "$N大喝一聲使出"+HIG+"『金鐘罩』"+NOR+"硬擋攻擊，再趁同一時間雙掌同出打在$n的$l。",
    "damage"     : 100,
    "force"      : 160,
    "damage_type": "瘀傷",
  ]),
// 6
  (["action"     : "$N微一吐勁，雙掌其出使出"+HIG+"『鐵砂掌』"+NOR+"，往$n的上盤和下盤拍去。",
    "damage"     : 100,
    "force"      : 160,
    "damage_type": "掌傷",
  ]),
// 7
  (["action"     : "$N身形一縮，使出"+HIM+"『螳螂爪』"+NOR+"，往$n的弱點抓去。",
    "damage"     : 130,
    "force"      : 160,
    "damage_type": "抓傷",
  ]),
// 8
  (["action"     : "$N氣沉丹田，窩身逼近$n，一招"+HIM+"『鐵膝功\』"+NOR+"，往$n的腹部踢了過去。",
    "damage"     : 130,
    "force"      : 160,
    "damage_type": "撞傷",
  ]),
// 9
  (["action"     : "$N騰空躍起，把掌一伸借助風力使出"+HIB+"『追風掌』"+NOR+"，往$n的$l襲去。",
    "damage"     : 160,
    "force"      : 160,
    "damage_type": "掌傷",
  ]),
// 10
  (["action"     : "$N移步遊蹤，身行莫測，突然一招"+HIC+"『鎖功\指』"+NOR+"，$n被指襲中內息頓失。",
    "damage"     : 160,
    "force"      : 160,
    "damage_type": "指傷",
    "post_action": (: call_other,__FILE__,"movedown1" :),
  ]),
// 11
  (["action"     : "$N運氣吐納，丹田運氣一沉，使出"+HIW+"『千斤閘』"+NOR+"，$n硬是抵擋差點吐出鮮血。",
    "damage"     : 160,
    "force"      : 160,
    "damage_type": "瘀傷",
    "post_action": (: call_other,__FILE__,"movedown2" :),
  ]),
// 12
  (["action"     : "$N暗運柔勁，借彼之力還彼之身，一招"+HIW+"『軟玄功\』"+NOR+"，譁然重創$n。",
    "damage"     : 200,
    "force"      : 200,
    "damage_type": "創傷",
    "post_action": (: call_other,__FILE__,"movedown3" :),
  ]),
});

int valid_learn(object me)
{
  object ob;
  if( (int)me->query("max_force") < 100)
    return notify_fail("你的內力不夠，沒有辦法練少林拳法。\n");
//  if( (string)me->query_skill_mapped("force")!= "bonzeforce")
//    return notify_fail("少林拳法必須配合少林內功\才能練。\n");
  return 1;
}

int valid_enable(string usage)
{
  return usage=="unarmed";// || usage=="parry"; //獨立parry的功能 by blazakira
}

mapping query_action(object me, object weapon)
{
  int skill;
  skill=(int)(me->query_skill("bonze-martial", 1));
  if( !skill ) skill=(int)(me->query_skill("seventy-two", 1));
  if( skill<70 ) {
    return action[random(sizeof(action))];
  } else {
    return action[random(6)+6];
  }
}

void movedown1(object me,object target, object weapon,int damage)
{
  if( !me || !target || me->query("force") < 30 ) return;
  message_vision(HIG + "$N" + HIG + "身形快速，十指其點，頓時把$n" + HIG + "的內息給封閉起來！\n" + NOR,me,target);
  if(70>=random(100)) {
    me->add("force",-30);
    message_vision(GRN + "結果$n" + GRN + "內息走岔，登時不能動彈！\n" + NOR,me,target);
    target->start_busy(1);
  }
  else {
    message_vision(GRN + "結果$n" + GRN + "往後一躍，躲了過去。\n" + NOR,me,target);
  }
}

void movedown2(object me,object target, object weapon, int damage)
{
  if( !me || !target || me->query("force") < 50 ) return;
  message_vision(HIR + "$N" + HIR + "的千斤閘內勁已暴走於$n" + HIR + "體內之中！\n" + NOR,me,target);
  if(70>=random(100)&&me->query("force_factor",1)>=5)
  {
    message_vision(GRN + "結果$n" + GRN + "內勁煩亂，登時狂吐鮮血！\n" + NOR,me,target);
    target->receive_damage("kee",300,me);
    COMBAT_D->report_status(target);
    me->add("force",-50);
  } else
    message_vision(sprintf(GRN + "結果$N的內勁被$n" + GRN + "化解。\n" + NOR),me,target);
}

void movedown3(object me,object target, object weapon, int damage)
{
  int fa;
  if( !me || !target || me->query("force") < 70 ) return;
  fa=target->query("force_factor",1)*20+100;
  message_vision(HIY + "$N軟玄功\的柔勁已借彼之力加上己之力全數打在$n" + HIY + "身上！\n" + NOR,me,target);
  if(70>=random(100)&&me->query("force_factor",1)>=10)
  {
    message_vision(GRN + "結果$n" + GRN + "譁然重創，登時倒地狂吐鮮血！\n" + NOR,me,target);
    target->receive_damage("kee",fa,me);
    COMBAT_D->report_status(target);
    me->add("force",-70);
  } else
    message_vision(sprintf(GRN + "結果$N" + GRN + "的柔勁偏了準頭。\n" + NOR),me,target);
}
//此技能沒有per 所以暫時關閉此段 by blazakira
/*
string perform_action_file(string action)
{
// if(this_player()->query_skill_mapped("unarmed")=="seventy-two") {
  return CLASS_D("bonze")+"/seventy-two/"+action;
// }
}
*/