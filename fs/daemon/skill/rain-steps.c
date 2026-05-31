// henma-steps.c
#include <ansi.h>
inherit SKILL;

string *dodge_msg = 
({
      

"$n使出"HIW"『草上飛』"NOR",身形像蜻蜓般的輕巧，避開$N的攻擊。\n",

"$n踩出"HIW"『飛鶴衝天』"NOR",身體化成一隻火鶴直奔天空而去，消失在$N之前。\n",

"$n斜踩"HIW"『氣定形轉』"NOR",不慌不忙的氣息一定，$n身上發出一陣煙霧將自己遮蔽住了，在$N面前消失。\n",

"$n使用"HIW"『迷波幻影』"NOR",形體萬千、充斥天地，將$N逼到角落去!\n",

"$n踏出"HIW"『天地無極』"NOR",身形一轉﹐便無聲無息的出現在$N的身後，準備使出致命一擊。\n",

});

int valid_enable(string usage) 
{
        return (usage=="dodge")||(usage=="move");
}

string query_dodge_msg(string limb)
{
  int dodge_pow;
  object me=this_player();

    if(!me) return "";
        dodge_pow = (int)(me->query_skill("rain-steps", 1)/10);
        if ( dodge_pow <= 6)
              return dodge_msg[random(4)];
        else
              return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
if(me->query("combat_exp")<(me->query_skill("rain-steps",1)*5))
      
   return notify_fail("你的戰鬥經驗不足﹐無法體會霧雨迷蹤其中的精義。\n");
        return 1;
}


int practice_skill(object me)
{
        if((int)me->query("kee")<5)
                return notify_fail("你的氣不夠﹐不能練霧雨迷蹤。\n");
        me->receive_wound("kee",5);
        return 1;
}

