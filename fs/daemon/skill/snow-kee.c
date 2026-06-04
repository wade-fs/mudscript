// snow-kee.c
// 雪蒼派的護身氣勁..Chan Design
//
#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
   HIC + "$n雪蒼護身內勁爆發,強大的寒勁硬生生將$N的攻勢震開。\n" + NOR,
   HIW + "$n一手「" + HIY + "盤天式" + HIW + "」一手「" + HIG + "臥地式" + HIW + "」其勢無窮無盡，將身旁守的固若金湯。\n" + NOR,
   WHT + "$n運腳如飛形成龍捲氣勁，在身前織成一道緊密氣網，將$N的猛烈攻勢盡數卸開。\n" + NOR,
   HIC + "$n內力狂轉，雙手急揮使出雪蒼武學之「" + HIM + "深淵勢" + HIC + "」，$N的攻勢如泥牛入海盡被$n氣勁宣洩出去。 \n" + NOR,
   HIW + "$n使出雪蒼護身寒勁之終極絕招【" + HIC + "--冰--風--雪--暴--" + HIW + "】\n" + HIW + "$n如同狂風暴冷般冰寒的氣勁,使溫度降至冰點,讓$N攻勢完全失去了效用\n" + NOR,
            });

int valid_enable(string usage)
{
int family;
object me=this_player();
if ( me->query("family/family_name") == "雪蒼派")
 return (usage=="parry");
else
 return notify_fail("只有雪蒼門人才能用雪蒼護身寒勁!!\n");
}

string query_parry_msg(string limb,object me)
{
  int parry_pow;
  if(!me) return parry_msg[random(sizeof(parry_msg))];
  parry_pow = (int)(me->query_skill("snow-kee", 1)/10);
  if ( parry_pow <= 8)
   return parry_msg[random(4)];
  else
   return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
if(me->query_skill("snowforce",1) < 60 )
   return notify_fail("你的雪蒼內勁不夠純熟!!無法修習雪蒼護身寒勁。\n");
  return 1;
}


int practice_skill(object me)
{
        if((int)me->query("kee")<100)
                return notify_fail("你的氣不夠﹐不能練雪蒼護身寒勁。\n");
        me->receive_wound("kee",10);
        return 1;
}

    string perform_action_file(string action)
{
           return CLASS_D("fighter")+"/snow-kee/"+action;
}
