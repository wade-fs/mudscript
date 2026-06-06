//pd-staff.c editer.by Chan

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void attack1(object me,object victim,object weapon,int damage);
void attack2(object me,object victim,object weapon,int damage);
void attack3(object me,object victim,object weapon,int damage);
void attack4(object me,object victim,object weapon,int damage);
void again1(object me,object victim,object weapon,int damage);
string *array_msg=
    ({
      "$N帶領著大家，形化四象，復化八卦使打狗陣法發揮致極點。\n",
      "眾人發揮出陣法之奧妙變化，使敵人陷入絕望的深淵。\n",
      "^[[1;33m$N指揮若定，眾人武功配合的天衣無縫，將招式遞向敵人。\n^[[0m",
      "眾人發揮出陣法之無窮奧義，將對敵人的損害發揮出最大的境界\n",
     });
mapping *action = ({
(["action":"$N將手中的棒子,急晃數下使出" + HIW + "「棒打雙犬」" + NOR + ",對準$n的$l「倏」一聲~擊下",
"dodge":-60,
"parry":90,
"force":60,
"damage":60,
"damage_type" : "瘀傷",
]),
(["action":"$N使出" + HIW + "「棒打惡犬」" + NOR + ",手中的棒子似有似無般的向$n的$l剌出",
"dodge":-60,
"parry":90,
"force":70,
"damage":70,
"damage_type" : "刺傷",
]),
(["action":"$N將手上的棒子,看拙實巧直直剌向$n的$l正是一招" + HIW + "「若隱若現」" + NOR,
"dodge":-90,
"parry":110,
"force":100,
"damage":70,
"damage_type" : "剌傷",
]),
(["action":"$N躍至半空中,高舉手中的棒子一招" + HIW + "「流星墜地」" + NOR + "﹐如流星般向$n的$l急劈而下",
"dodge":-90,
"parry":110,
"force":100,
"damage":80,
"damage_type" : "割傷",
]),
(["action":"$N將手中的棒子,急劃圈圈一招" + HIW + "「無窮無盡」" + NOR + "﹐棒上的內勁向$n的$l襲去",
"dodge":-90,
"parry":110,
"force":100,
"damage":70,
"damage_type" : "內傷",
]),
(["action":"$N面對$n的攻擊使出" + HIW + "「封狗在外」" + NOR + "﹐將攻擊一封,利用棒子向$n的$l一剌",
"dodge":-90,
"parry":120,
"force":100,
"damage":80,
"damage_type" : "瘀傷",
]),
(["action":"$N將手中的棒子,由下往上挑起一招" + HIC + "「挑狗在天」" + NOR + "使$n被挑至空中並從旁向$l擊出",
"dodge":-100,
"parry":120,
"force":100,
"damage":80,
"damage_type" : "瘀傷",
]),
(["action":"$N將內勁貫注至棒子," + HIC + "「狂風追雪」" + NOR + "﹐棒勁所形成的寒風向$n的$l襲去",
"dodge":-100,
"parry":130,
"force":100,
"damage":85,
"damage_type" : "凍傷",
]),
(["action":"$N鼓盡全身內力,一招" + HIC + "「亂棒狂擊」" + NOR + "﹐手中的棒子向$n的$l亂擊而出",
"dodge":-100,
"parry":120,
"force":100,
"damage":90,
"damage_type" : "擊傷",
]),
(["action":"$N狂吼一聲,內力散發使出絕技" + HIC + "「天下無狗」" + NOR + "﹐漫天的棒勢向$n的$l狂襲而去",
"dodge":-100,
"parry":120,
"force":110,
"damage":95,
"damage_type" : "刺傷",
]),
(["action":"$N領悟打狗棒法四大精義之" + HIC + "「亂」" + NOR + "字訣，手中的棒子其勢無窮無盡般向$n的$l狂掃而去",
"dodge":-100,
"parry":120,
"force":110,
"damage":100,
"post_action":  (: attack1 :),
"damage_type" : "剌傷",
]),
(["action":"$N領悟打狗棒法四大精義之" + HIC + "「封」" + NOR + "字訣，手中的棒子如海天一線般封住$n的攻勢,手肘同時擊去",
"dodge":-100,
"parry":120,
"force":110,
"damage":100,
"post_action":  (: attack2 :),
"damage_type" : "瘀傷",
]),
(["action":"$N領悟打狗棒法四大精義之" + HIC + "「劈」" + NOR + "字訣，手中的棒子如閃電般從上向$n的$l狂劈而下",
"dodge":-100,
"parry":110,
"force":110,
"damage":105,
"post_action":  (: attack3 :),
"damage_type" : "砍傷",
]),
(["action":"$N領悟打狗棒法四大精義之" + HIC + "「引」" + NOR + "字訣，手中的棒子如青蛇出洞般向$n的$l狂剌而出",
"dodge":-100,
"parry":120,
"force":110,
"damage":105,
"post_action":  (: attack4 :),
"damage_type" : "剌傷",
]),
(["action":HIR + "$N將谷盡全身的內力,使出打狗棒法中的『亂擊棒法』無數棒影鋪天蓋\地般向$n襲去" + NOR,
"dodge":-110,
"parry":150,
"force":150,
"damage":70,
"post_action":  (: again1 :),
"damage_type" : "瘀傷",
]),
});

mapping query_action(object me, object weapon)
{
int skill;
   skill=me->query_skill("pd-staff", 1);
   if( me->query_temp("use_form",1))
     message_vision( array_msg[random(sizeof(array_msg))],me );
   if( skill < 50)
      return action[random(7)];
   else if( skill < 60)
      return action[random(7)+2];
   else if( skill < 70)
      return action[random(7)+3];
   else if( skill < 80)
      return action[random(7)+5];
   else if( skill < 90)
      return action[random(7)+7];
   else
      return action[random(7)+8];
}
void attack1(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("pd-staff", 1);
 att_value = skill * 12;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIR + "$N將打狗棒法結合洗髓經中的暗勁震傷$n全身血脈\n" + NOR,me,victim);
   victim->receive_damage("kee",att_value);
   COMBAT_D->report_status(victim, 1);
  }
}
void attack2(object me, object victim, object weapon, int damage)
{
 int busy_value,skill;
 skill=me->query_skill("pd-staff", 1);
 busy_value = skill / 2;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIW + "$N將打狗棒法中封字訣和降龍勁配合封住$n的四肢百骸\n" + NOR,me,victim);
   victim->start_busy( busy_value );
   COMBAT_D->report_status(victim, 1);
  }
}
void attack3(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("pd-staff", 1);
 att_value = skill * 14;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIB + "$N將打狗棒法中轉字訣注入降龍勁形成龍捲風襲向$n\n" + NOR,me,victim);
   victim->receive_damage("kee",att_value);
   COMBAT_D->report_status(victim, 1);
  }
}
void attack4(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("pd-staff", 1);
 att_value = skill * 14;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIG + "$N將降龍勁配合打狗棒法的引字訣,其無窮的氣勁剌傷$n\n" + NOR,me,victim);
   victim->receive_damage("kee",att_value);
   COMBAT_D->report_status(victim, 1);
  }
}

void again1(object me, object victim, object weapon, int damage)
{
        int i,time;
        int level=(int)(me->query_skill("pd-staff",1)/10);
        time=level+2;
        if (level > 6)
        {
  if( me->query_temp("pd-staff") == 0 && me->query("class")=="beggar" )
          {
              me->set_temp("pd-staff",1);
              message_vision(HIW + "$N使出打狗棒法之「亂取之技」,無數的棒影向$n狂掃而去。\n" + NOR, me, victim);
              for(i=1;i<=time;i++)
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
              me->delete_temp("pd-staff");
             me->start_busy(1);
          }
        }

}

int practice_skill(object me)
{
  if ((int) me->query("max_force")<10000)
  return notify_fail("你武學知識不足，無法參透打狗棒法的精妙之處\n");
}

string perform_action_file(string action)
{
          return CLASS_D("beggar")+"/pd-staff/"+action;
}
int valid_learn(object me)
    {
        object weapon = me->query_temp("weapon");
        if( me->query("max_force") < 1000 ) {
            tell_object(me, "你的內力修為不夠, 最少要有一千點。\n");
            return 0;
        }
        if(!(me->query("class") == "beggar")) {
            tell_object(me, "只有丐幫弟子才能學打狗棒法。\n");
            return 0;
        }
        if( me->query_str() >= 20 ) {
            tell_object(me, "你的臂力過大無法學打狗棒法。\n");
            return 0;
        }
        if(!(me->query("beggar/quests 10") == 1 )) {
            tell_object(me, "丐幫弟子要完成任務十才能學。\n");
            return 0;
        }
        if( me->query("force") < 500 ) {
            tell_object(me, "你目前的內力不到五百點, 無法練此絕學。\n");
            return 0;
        }
        if( (me->query("potential") - me->query("learned_points")) < 2 ) {
            tell_object(me, "你的潛能不到二點, 無法練此絕學。\n");
            return 0;
        }
        if( !weapon || weapon->query("skill_type") != "staff" ) {
            tell_object(me, "手中無棒怎麼個練法呀?\n");
            return 0;
        }

        tell_object(me, "學此絕學需扣潛能二點。\n");
        me->add("potential", -2);
        return 1;
}
int valid_enable(string usage)
{        return ( usage=="staff" )||(usage=="parry");
}
