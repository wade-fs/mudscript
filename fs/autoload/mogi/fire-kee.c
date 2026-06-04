// fire-kee.c
// 瀧山派的護身氣勁..Chan Design
//
#include <combat.h>
#include <ansi.h>

inherit SKILL;

string *parry_msg =
({
   MAG + "面對$N猛烈的攻勢,$n暗運浩日心法,瞬間$N護身真氣暴漲,將猛烈的攻勢化之無形\n" + NOR,
   YEL + "$n將護身的浩日氣勁收縮,氣血逆流.將氣勁運至雙手,以雙臂抵擋$N所使出的必殺招式\n" + NOR,
   HIR + "$n狂吼一聲,轟～～一聲!!!全身氣勁暴散\n,$N被$n的浩日護身氣勁所形成的氣牆所阻,其招勢無法發出勁力\n" + NOR,
   MAG + "$n氣沈丹田,烈日真氣凝結成絲,全身散發出無數的氣塊,轟～～一聲!!\n$N的攻擊被氣塊所阻,無法發出威力\n" + NOR,
   HIW + "$n使出浩日護身氣勁之終極絕招【" + HIY + "--烈--火--無--限--" + HIW + "】\n" + HIR + "$n如同火山暴發般炙熱的氣勁,向四周漫延,讓$N攻勢完全失去了效用\n" + NOR,
});

int valid_enable(string usage)
{
int family;
object me=this_player();
if ( me->query("family/family_name") == "瀧山派")
 return (usage=="parry");
else
 return notify_fail("只有瀧山弟子才能用浩日護身氣勁!!\n");
}

string query_parry_msg(string limb)
{
  int parry_pow;
  object me=this_player();
  parry_pow = (int)(me->query_skill("fire-kee", 1)/10);
  if ( parry_pow <= 8)
   return parry_msg[random(4)];
  else
   return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
  if(me->query ("combat_exp") <= (me->query_skill("fire-kee",1)*6) )
   return notify_fail("你的戰鬥經驗不足﹐無法體會烈日護身氣勁運行之道。\n");
  if(me->query_skill("haoforce") < 60 )
   return notify_fail("你的浩日心法不夠純熟!!無法修習烈日護身氣勁。\n");
  return 1;
}


int practice_skill(object me)
{
        if((int)me->query("kee")<100)
                return notify_fail("你的氣不夠﹐不能練烈日護身氣勁。\n");
        me->receive_wound("kee",10);
        return 1;
}

