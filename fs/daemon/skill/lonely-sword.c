// lonely-sword.c  獨孤九劍
/*
#include <ansi.h>
*/
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void berserk(object me, object victim, object  weapon, int damage);
void sp1(object me, object victim, object  weapon, int damage);
void sp2(object me, object victim, object  weapon, int damage);
void sp3(object me, object victim, object  weapon, int damage);
void sp4(object me, object victim, object  weapon, int damage);
string *parry_msg=({
        "$n身軀一引, 將$N的攻勢盡數曳了開去。\n",
        "$n把手中武器舞成圓環, 將$N的攻勢盡數擋了下來。\n",
        "$n以靜制動, 平舉手中的劍, 無招勝有招, 化解了$N的攻勢!\n",
        });
 string *array_msg=
    ({
      "$N大喝一聲, 腳踏七星, 帶領著眾劍士,展開獨孤破邪劍陣。\n",
      "眾人腳踩八卦, 劍化兩儀, 團團將敵人圍住, 令敵人望之膽怯。\n",
      "$N急吸一口氣, 帶領眾人加速運轉獨孤鎮邪劍陣,打的敵人手足無措。\n",
     }); 
mapping *action = ({
        ([
                "action"     :               "$N左手捏個劍訣, 平推而出,訣指上仰, 右手劍朝天不動, 正是一招『震劍勢』",
                "dodge"      :                -20,
                "damage"     :                200,
                "post_action":                (: berserk :),
                "damage_type":                "割傷",
         ]),
         ([
                "action"     :                "$N面露微笑, 仰視蒼天,使出劍招之極致『閃劍勢』, 但見劍光閃閃",
                "dodge"      :                -10,
                "damage"     :                220,
                "post_action":                (: berserk :),
                "damage_type":                "割傷",
         ]),
         ([
                "action"     :                "$N身形飄忽大喝一聲,$N使出獨孤九劍之必殺絕招\n"+"～～破．落．二劍合一勢～～\n"+
                                              "$N運起內功\心法, 氣沉丹田,以氣御劍, 只見手中$w化作一道銀光, 朝$n急飛而去, 但見銀光一閃,",
                "dodge"      :                10,
                "damage"     :                350,
                "post_action":                (: sp3 :),
                "damage_type":                "刺傷",
         ]),

         ([
                "action"     :                "$N身形飄忽大喝一聲,使出獨孤劍式之必殺絕招\n"+"～～盪．撩．二劍合一勢～～\n"+
                                              "只見$N手中$w急畫一個圓, 越畫越快, $n只覺周身大穴盡皆籠罩在劍芒之下, 驚駭之餘, 一股大力突然湧來,",
                "dodge"      :                10,
                "damage"     :                550,
                "post_action":                (: sp1 :),
                "damage_type":                "砍傷",                                    
         ]),

        ([
                "action"     :               "$N左手持劍, 右手捏個劍訣,雙手成環, 緩緩抬起, 這是獨孤劍式絕式的起手式",
                "dodge"      :                -10,
                "damage"     :                700,
                "post_action":                (: sp2 :),
                "damage_type":               "刺傷",
        ]),

        ([
                "action"     :
"$N施展出獨孤九劍之精妙絕招\n劍招忽變, 飄逸無倫,歪歪斜斜的使出一招『落劍勢』",
                "dodge"      :                -10,
                "damage"     :                800,
                "damage_type":               "刺傷",
        ]),
        ([
                "action"     :
"$N施展出獨孤九劍之精妙絕招\n劍芒吞吐, 電閃星飛,一招『旋劍勢』, 推送而上",
                "dodge"      :                -10,
                "damage"     :                700,
                "damage_type":               "刺傷",
        ]),
        ([
                "action"     :
"$N施展出獨孤九劍之精妙絕招\n$N$w越使越快, 突然間轉過身來,一聲呼喝,唰的一劍, 在$n胸前對穿而過,這一招『離劍勢』,正是絕高的絕技",
                "dodge"      :                -10,
                "damage"     :                750,
                "post_action":                (: sp4 :),
                "damage_type":               "刺傷",
        ]),

});

mapping query_action(object me, object weapon)
{
   int skill_level, limit;
   skill_level = (int)(me->query_skill("lonely-sword", 1));
   limit= (int)( skill_level/ 10);
   if( me->query_temp("use_form", 1))
      message_vision( array_msg[ random( sizeof( array_msg))], me); 
   if( me->query("quest/lonely-sword"))
   {
      if (limit < 1 )
         return action[random(6 )];
      else if (limit < 2 )
         return action[random(7 )];
      else if (limit < 3 )
         return action[random(8 )];
      else if (limit < 4 )
         return action[random(9 )];
      else if (limit < 5 )
         return action[random(9 )+1];
      else if (limit < 6 )
         return action[random(9 )+2];
      else if (limit < 7 )
         return action[random(9 )+3];
      else if (limit < 8 )
         return action[random(9 )+4];
      else if (limit < 9 )
         return action[random(9 )+5];
         return action[random(9 )+6];
   }
   else
   {
      if (limit < 1 )
         return action[random(1)];
      else if (limit < 2 )
         return action[random(2)];
      else if (limit < 3 )
         return action[random(3)];
      else if (limit < 4 )
         return action[random(4)];
      else if (limit < 5 )
         return action[random(4)+1];
      else if (limit < 6 )
         return action[random(4)+2];
      else if (limit < 7 )
         return action[random(4)+3];
      else if (limit < 8 )
         return action[random(4)+4];
      else if (limit < 9 )
         return action[random(4)+5];
         return action[random(4)+6];
   }
}

void sp1(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("lonely-sword", 1);
   message_vision("$N長嘯道:『劍旋離身，劍嘯震山河』, 瞬間劍芒大作,朝$n激射而至\n",me,victim);
   victim->add("kee", -(skill* 2));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}
void sp2(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("lonely-sword", 1);
   message_vision("$N突然悟出『練精化氣, 練氣化神, 練神還虛』之真理, 手中長劍突然消失, 已朝$n飛至\n",me,victim);
   victim->add("kee",-(skill* 2));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}
void sp3(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("lonely-sword", 1);
   message_vision("這起手式一展,跟著劍氣突爆『盪劍．撩劍．過劍．挫劍．離劍．落劍．旋劍．挪劍』,最後雙手同時畫圓, 復成持劍歸原之姿\n",me,victim);
   victim->add("kee",-(skill* 2));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}
void sp4(object me, object victim, object  weapon, int damage)
{
   int i, loop;
   int skill= me->query_skill("lonely-sword", 1);
   loop= random( skill/ 10)+ 3;
   if( !me->query("berserk") && random(me->query("combat_exp")) > random(victim->query("combat_exp")))
   {
      me->set_temp("berserk", 1);
      message_vision("$N了悟了『劍在神先, 綿綿不絕』之真意, 劍尖瞬間爆出無數大大小小, 正反斜直各種各樣的圓圈, 朝$n直撲而來\n",me,victim);
      for( i= 0; i< loop; i++)
      {
         message_vision("$N大聲喝道『劍在神先, 綿綿不絕』, 劍招連綿不絕的朝$n攻去\n", me, victim);
         victim->add("kee", -( random( skill)));
         COMBAT_D->report_status(victim, 1);
      }
      me->delete_temp("berserk");
      message_vision("一陣連擊攻之後, $N微感內息不順,趕緊趁機調息。\n",me);
      me->start_busy(1);
      me->add("force", -skill);
   }
}

void berserk(object me, object victim, object  weapon, int damage)
{ 
   if( random(8) > 3 )
   {
      if( (int)me->query_skill("lonely-sword",1) > random(60)+35 &&me->query("force_factor")>= random(5) && me->query("force")>30)
      {
         if(!me->query_temp("berserk" ))
         {
            me->set_temp("berserk", 1);
            if(me->query("family/family_name") == "獨孤傳人")
            {
               message_vision( sprintf("\n$N突然頓悟了『神與意合, 意與神守』之意境"+
               "使出獨孤九劍至極之劍術『 蕩劍起～撩劍破～旋劍無極』!!!\n"),me ,victim);
               message_vision(sprintf("\n$N剎那間整個人脫胎換骨變得威猛無倫, "+
               "跨開大步, 長劍高舉過頭, 往$n^[[1;34m迫去\n天地震動, 宇宙翻騰, $n被這股氣勢震嚇住, "+
               "只覺眼前劍芒一閃。\n "), me ,victim);
               victim->start_busy(1);
               victim->receive_wound("kee",100+random(100),me);
               me->add("force",-60);
            }
            me->delete_temp("berserk");
         }
      }
   }
}

int valid_learn(object me)
{
   object ob;
   if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") !="sword")
      return   notify_fail("少了把劍練起來怪不順手的, 還是拿把劍再來練吧。\n");
   return   1;
}

int valid_enable(string usage)
{
   return ( usage=="sword") || ( usage=="parry" );
}

int practice_skill(object me)
{
  if( (int)me->query("kee") < 25 )
     return notify_fail("你的體力不夠了﹐休息一下再練吧。\n");
  if( (int)me->query("gin") < 5 )
     return notify_fail("你的精力不夠了﹐休息一下再練吧。\n");
  if( (int)me->query("force") < 1 )
     return notify_fail("你的內力不夠了﹐休息一下再練吧。\n");
  me->receive_damage("kee", 25);
  me->receive_damage("gin", 5);
  me->add("force", -1);
  return 1;
}

string perform_action_file(string action)
{
   return CLASS_D("swordsman")+"/lonely-sword/"+action;
}

string query_parry_msg(string limb)
{
   return parry_msg[ random( sizeof( parry_msg))];
}

void skill_improved(object me)
{
tell_object(me,"由於你潛心學習，你的獨孤九劍更加純熟了！！\n");
}
