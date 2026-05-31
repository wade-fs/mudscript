#include <ansi.h>
inherit SKILL;
void striback(object me,object victim);

string *parry_msg = ({
 "$n瞧著$N的攻勢﹐腳步一轉﹐嚇然轉出了一式[1;37m『邪嵐轉勢』[0m﹐瞬間變制住了$N的攻勢﹐轉守為攻\n",
 "$n大喝一聲﹐趁$N擊出一擊重擊時﹐使出一招[1;36m『兇兆舞勢落』[0m﹐$N的身子硬是逆著$N的攻勢逼到$N身前\n",
 "$n注視著$N的層層攻勢﹐腳鋒一捷﹐點出了一記[1;35m『殺元跺』[0m﹐便趁著$N的攻勢尚未使盡前架住其鋒﹐硬是把$N元氣退回﹐使得$N元氣頗傷\n",
 "$n注意到$N即將展開攻勢﹐隨即將身法放輕﹐內力凝聚﹐用出了一招[1;34m『厄驚覺』[0m﹐$n看準了$N的攻勢尚未展開便扣住其身﹐虎口正對準了$N那尚未明瞭的臉孔上\n",
 "$n眼看著$N強大攻勢即將落在$n身上﹐忽然心神一震﹐腳步急轉成風﹐使出的正是[1;31m『無心訣』[0m﹐只見得$N的身子忽然凝滯不前﹐$n正在$N頭上攻下\n",
                    });

int valid_enable(string usage)
{
  object me=this_player();
  if ( me->query("class") == "bandit" )
    return (usage=="parry");
 else
    return notify_fail("你又不是個壞東西 ,憑啥用這招 ?\n");
}

string query_parry_msg(string limb)
{
  int sb;
  object me=this_player();
  sb = me->query_skill("evilstriback");
  if ( sb <= 80 )
  {
    call_out("striback",me);
  return parry_msg[random(4)];
  }
  else
  {
    call_out("striback",me);
  return parry_msg[random(sizeof(parry_msg))];
  }
}

int valid_learn(object me)
{
  if(me->query_skill("badstrike",1)<30)
    return notify_fail("拳腳功\夫不紮實還想有番作為 ?\n");
  else if (me->query_skill("badforce",1)<30)
    return notify_fail("先學著運氣吧 ,小子\n");
  else if (me->query_skill("ghost-steps",1)<30)
    return notify_fail("輕功\不高還想要制敵機先 ?\n");
  return 1; 
}

void striback(object me,object victim)
{
  int esb;
  esb = (me->query_skill("evilstriback")/10);
  if ( random(esb) >= 5 )
  {
    victim->start_busy(1);
    message_vision("[1;33m$N成功\的將$n的攻勢反轉過去 ![0m\n", me, victim);
  }
  else
  {
    message_vision("[1;32m$N錯過了反擊良機!![0m\n", me, victim);
  }
}

