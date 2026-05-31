// lys-skill
//QC..OK..by Chan 8/29/98
#include "/std/sserver.c"
#include "ansi.h"
inherit SKILL;


string *parry_msg=
    ({
      "$n回身抽鞭，使出冥蛇鞭法防禦式，將$N的攻勢一一化去\n",
      "只見$n身形一轉，輕抖手中$l，圈出一個鞭花，往$N的$w捲去\n",
      "$n氣運$l，將$l舞成一個圈圈，護住身周五尺內\n",
      "$n急忙之際，使出一招『圍魏救趙』，進身直攻，逼的$N收勢防守\n",
    });
mapping *action = ({
([ "action":"$N手中$w一揮，使出一招[33m『金蛇出洞』[0m，氣勢驚人，直撲$n而去",
        "dodge": -20,
        "parry": 25,
        "damage": 50,
        "damage_type":  "鞭傷",
]),

([ "action":"$N使出一招[35m『靈蛇八方』[0m，$w似靈蛇般由四面八方打向$n",
        "dodge": -15,
        "parry": 35,
        "damage": 45,
        "damage_type":  "鞭傷",
]),

([ "action":"$N使出一招[1;34m『靈蛇乍現』[0m，$w忽隱忽現，忽東忽西，令$n無法捉摸$N的鞭路",
        "dodge": 10,
        "parry": 40,
        "damage": 40,
        "damage_type":  "鞭傷",
]),

([ "action":"$N蓄勢一揮，使出一招[31m『赤龍翻江』[0m，呼的一聲，手中$w向$n橫掃而去",
        "dodge": -15,
        "parry": 25,
        "damage": 55,
        "damage_type":  "鞭傷",
]),

([ "action":"$N揮動$w，使出一招[1;33m『金蛇萬道』[0m，如有千百條金蛇同時打出，直撲$n各大穴",
        "dodge": -10,
        "parry": 35,
        "damage": 60,
        "damage_type":  "鞭傷",
]),

([ "action":"$N手中$w一抖，圈起一圈圈鞭花，一招[1;32m『金蛇纏身』[0m，向$n捲去",
	"dodge": 35,
        "parry": 50,
    "damage": 70,
        "damage_type":  "鞭傷",
]),

([ "action":"$N身形一斜，使出一招[1;31m『萬蠱蝕心』[0m，頓時滿天鞭影，鞭勢挾帶一股腥風向$n撲至",
        "dodge": 20,
        "parry": 45,
     "damage": 80,
        "damage_type":  "鞭傷",
]),

([ "action":"[1;35m$N$w微揮，使出一招[1;36m『幽冥幻化』[1;35m，
使鞭之快不見鞭影，只聞呼呼聲響，邪風陰煞，圍繞$n四周[0m",
        "dodge": 25,
        "parry": 50,
    "damage":80,
        "damage_type":  "鞭傷",
]),

});

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}
string query_parry_msg(string limb)
{
  int parry_pow;
  object me;
  me=this_player();

  if(!me) return parry_msg[random(sizeof(parry_msg))];

  parry_pow = (int)( me->query_skill("ming-snake", 1)/10);
  if ( parry_pow < 3)
    return parry_msg[random(2)];
  else
    return parry_msg[random(sizeof(parry_msg))];
}
 string *poison_type = ({
                         "snake_poison",
                         "fire_poison",
                         "rose_poison",
                         "dark_poison",
                         "five_poison" ,
                        });

mapping query_action(object me, object weapon)
{
	int skill_level, limit;
	skill_level = (int)(me->query_skill("ming-snake",1));
	limit = (int)(skill_level/10);
	if(limit < 4)
		return action[random(3)];
	if(limit < 8)
		return action[random(limit)];
	else {
    if(me->query("family/family_name")=="冥蠱魔教")
    {
      if(present("bleed whip",me))
      {
        object target = offensive_target(me);
        if((int)(me->query_skill("poison",1)) > random(target->query_skill("dodge",1)) && random(10) < 2) // 20% 攻擊的機會
        {

//          string poison = values(poison_type)[random(sizeof(poison_type))];
          string poison  = poison_type[random(sizeof(poison_type))];
          if(!target->query_condition(poison) && me->query("poison") > 5)
          {
            target->apply_condition(poison,1);
            me->add("poison",-5);
            message_vision(HIB"\n纏繞在"HIR"血龍鞭"HIB"上的毒氣的順著鞭子的纏到$n的身上\n"NOR,me,target);
            
            
          }
          //me->query("env/cure_poison");
        }
      }
    }
    
		return action[random(sizeof(action))];
  }
}
int vaid_learn(object me)
{
	object ob;
	if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type")!="whip")
                return notify_fail("不拿鞭怎麼學呀!你有沒有搞錯。\n");
	return 1;
}
int practice_skill(object me)
{
	object ob;
	if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type")!="whip")
		return notify_fail("不拿鞭如何練習鞭法。\n");
	if( (int)me->query("kee")< 40)
		return notify_fail("不會累嗎? 你的體力不夠了，還是休息一下再練吧。\n");
	if( (int)me->query("force")< 5 )
                return notify_fail("你的內力不夠了，我看你還是休息一下再練吧。\n");
	me->receive_damage("kee", 40);
	me->add("force",-5);
	return 1;
}
	
string perform_action_file(string action)
{
        return CLASS_D("poisoner")+"/ming-snake/"+action;
 }

