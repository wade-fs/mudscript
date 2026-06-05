//pd-staff.c editer.by Chan

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void attack1(object me, object victim, object  weapon, int damage);
void again1(object me, object victim, object  weapon, int damage);
string *array_msg=
    ({
      "[1;33m$N帶領著大家，形化四象，復化八卦使打狗陣法發揮致極點。\n[0m",
      "[1;33m眾人發揮出陣法之奧妙變化，使敵人陷入絕望的深淵。\n[0m",
      "^[[1;33m$N指揮若定，眾人武功\配合的天衣無縫，將招式遞向敵人。\n^[[0m",
      "[1;33m眾人發揮出陣法之無窮奧義，將對敵人的損害發揮出最大的境界\n[0m",
     });
mapping *action = ({
(["action":"$N對準$n的弱點,狂揮而下使出" + HIW + "「力劈華山」" + NOR + ",對準$n的$l部份擊下",
"dodge":-60,
"parry":90,
"force":60,
"damage":50,
"damage_type" : "瘀傷",
]),
(["action":"$N看出$n的罩門使一招" + HIW + "「虎虎生風」" + NOR + ",手中的棒子夾帶強大的氣勁向$n的$l揮出",
"dodge":-60,
"parry":90,
"force":70,
"damage":50,
"damage_type" : "瘀傷",
]),
(["action":"$N將手上的棒子,直直剌向$n的$l正是一招" + HIW + "「直攻而入」" + NOR,
"dodge":-90,
"parry":110,
"force":100,
"damage":60,
"damage_type" : "剌傷",
]),
(["action":"$N躍至半空中,高舉手中的棒子猛揮而下一招" + HIW + "「流星趕月」" + NOR + "﹐如流星般向$n的$l急劈而下",
"dodge":-90,
"parry":110,
"force":100,
"damage":70,
"damage_type" : "割傷",
]),
(["action":"$N將手中的棒子,急劃反轉使出蓮花杖法之奧義" + HIW + "「無盡無悔」" + NOR + "﹐漫天的棒影向$n的$l襲去",
"dodge":-90,
"parry":110,
"force":100,
"damage":80,
"post_action":  (: again1 :),
"damage_type" : "內傷",
]),
(["action":"$N面對$n唱出蓮花落之" + HIW + "「乞討餘羹」" + NOR + "﹐將$n的攻擊一封",
"dodge":-90,
"parry":120,
"force":100,
"damage":90,
"post_action":  (: attack1 :),
"damage_type" : "瘀傷",
]),
(["action":"$N以敵不動,我不動面對$n以一招奧義" + HIC + "「蓮花無影」" + NOR + "使$n被挑至空中並從旁向$l擊出",
"dodge":-100,
"parry":120,
"force":100,
"damage":90,
"damage_type" : "瘀傷",
]),
(["action":"$N逆運真氣,幻化無形蓮花奧義" + HIC + "「狂風怒吼」" + NOR + "﹐棒勁所形成的風勁向$n的$l襲去",
"dodge":-100,
"parry":130,
"force":100,
"damage":90,
"damage_type" : "瘀傷",
]),
});

mapping query_action(object me, object weapon)
{
int skill;
   skill=me->query_skill("follow-staff", 1);
   if( me->query_temp("use_form",1))
     message_vision( array_msg[random(sizeof(array_msg))],me );
   if( skill < 50)
      return action[random(4)];
   else if( skill < 60)
      return action[random(4)+1];
   else if( skill < 70)
      return action[random(4)+2];
   else if( skill < 90)
      return action[random(4)+3];
   else
      return action[random(4)+4];
}
void attack1(object me, object victim, object weapon, int damage)
{
 int busy_value,skill;
 skill=me->query_skill("follow-staff", 1);
 busy_value = skill / 3;
 if((me->query_skill_mapped("force")=="followforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIY + "$N將蓮花杖法結合和蓮法心法發出氣絲封住$n的四肢百骸\n" + NOR,me,victim);
   victim->start_busy( busy_value );
   COMBAT_D->report_status(victim, 1);
  }
}

void again1(object me, object victim, object weapon, int damage)
{
 int i,value,k=0,skill,l=5;
 skill=me->query_skill("follow-staff", 1);
 skill = skill / 10;
 if(skill > 9)
 {
  k = 6;
  l = 3;
 }
 else if (skill > 7)
      {
       k = 5;
       l = 4;
      }else if (skill > 4 )
       {
        k = 4;
        l = 5;
       }
 if(me->query("force")>100&&me->query("force_factor"))
 {
   for (i=0;i<k;i++)
    {

      message_vision(HIW + "$N使出蓮花棒法之「亂擊之技」,無數的杖影向$n狂掃而去。\n" + NOR, me, victim);
      value = random (10);
      if (value >= l)
       {
        message_vision("結果被$N準確的命中要害,$n身上留下深厚的棒痕。\n", me, victim);
        victim->receive_wound("kee",25,me);
        me->add("force",-50);
        COMBAT_D->report_status(victim, 1);
       }
      else
        message_vision("結果$n在漫天的棒影穿了出來。\n", me, victim);
    }
    message_vision(HIW + "一陣狂掃之後，$N內勁損耗過大，無法移動。\n" + NOR,me);
    me->start_busy(1);
    COMBAT_D->report_status(victim, 1);
  }
}

int practice_skill(object me)
{
  if( (int)me->query("kee") < 30 )
      return  notify_fail("你的氣不夠﹐無法練習蓮花杖法。\n");
  if( (int)me->query("force") < 5 )
      return  notify_fail("你的內力不夠﹐不能練習蓮花杖法。\n");
  me->receive_damage("kee", 30);
  me->add("force", -5);
  return 1;
}

string perform_action_file(string action)
{
          return CLASS_D("beggar")+"/follow-staff/"+action;
}
int valid_learn(object me)
    {
        object weapon = me->query_temp("weapon");
        if( me->query("max_force") < 50 ) {
            tell_object(me, "你的內力修為不夠, 最少要有五十點。\n");
            return 0;
        }
        if(!(me->query("class") == "beggar")) {
            tell_object(me, "只有丐幫弟子才能學蓮花杖法。\n");
            return 0;
        }
        if( me->query_str() >= 20 ) {
            tell_object(me, "你的臂力過大無法學蓮花杖法。\n");
            return 0;
        }
        if( !weapon || weapon->query("skill_type") != "staff" ) {
            tell_object(me, "手中無棒怎麼個練法呀?\n");
            return 0;
        }
        return 1;
}
int valid_enable(string usage)
{        return ( usage=="staff" )||(usage=="parry");
}
