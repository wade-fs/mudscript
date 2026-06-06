//絳雪神劍 by bss
#include <ansi.h>
#include <combat.h>

void berserk2(object me, object victim, object  weapon, int damage);
void sp1(object me, object victim, object  weapon, int damage);
void sp2(object me, object victim, object  weapon, int damage);
void sp3(object me, object victim, object  weapon, int damage);
//void sp4(object me, object victim, object  weapon, int damage);
string *parry_msg=({
        "$n手中$w忽然脫手一抖，正是一招"+HIY+"「劍流星」"+NOR+"，頃刻間劍如流星運轉，巧絕無方，將$N的攻勢盡數擋了下來。\n",
        "$n身軀一引, 手中$w將$N的攻勢盡數曳了開去。\n",
        "$n把手中的$w舞成圓環, 將$N的攻勢盡數擋了下來。\n",
        "$n以靜制動, 平舉手中$w, 無招勝有招, 化解了$N的攻勢!\n",
        });

mapping *action = ({
        ([
                "action"     :
"$N施展出浣花劍派絕招" + HIY + "「倒飛劍」" + NOR + "，突然間轉過身來，身形騰起，唰的一劍，
往$n胸前直刺，速度飛快，眼看$n就要中招了。",
                "dodge"      :                -500,
                "damage"     :                750,
                "damage_type":               "刺傷",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
        ]),
        ([
                "action"     :
"$N劍作刀使，忽地一招"+HIY+"「龍嘯九天」"+NOR+", 手中$w由下而上的砍向$n，因砍削空氣所形成得螺漩氣流如狂風般攻向$n。",
                "dodge"      :                -500,
                "damage"     :                145,
                "damage_type":               "砍傷",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp1:),
        ]),
        ([
                "action"     :
"$N忽然將手中$w藏於背後，正是一招"+HIB+"「無劍勢」"+NOR+",正當$n搞不清楚狀況的時後，$w\n忽然由$N的腰旁刺出，刺向$n。",
                "dodge"      :               -500,
                "damage"     :                165,
                "damage_type":               "刺傷",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
        ]),
        ([
                "action"     :

"$N將$w拋向空中，$n見機不可失，迅速的向$N進攻,$N忽然眼放精光，跟著躍至空中接\n劍，順勢下劈，正是一招"+HIC+"「怒斬神州」"+NOR+" ，千萬道劍氣隨著劍勢攻向$n。",
                "dodge"      :                -500,
                "damage"     :                200,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":                (: sp2 :),
                "damage_type":                "砍傷",
         ]),
         ([
                "action"     :
"$N忽然向前大跨一步，一股龐大的殺氣從$N身上湧出，$N大喝一聲"+HIR+"「殺龍求道」"+NOR+"，霍地旋身而起，劍隨身轉，旋風般朝$n猛攻。",
                "dodge"      :                -500,
                "damage"     :                220,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "damage_type":                "割傷",
         ]),
         ([
                "action"     :
"$N將$w斜插於地，身形急轉，大喝一聲"+HIY+"「潛龍升天」"+NOR+"，手中$w帶起了一陣上升氣流，彷彿要將四週的一切全部捲到空中似的",
                "dodge"      :                -500,
                "damage"     :                350,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp3:),
                "damage_type":                "割傷",
         ]),
         ([
                "action"     :
"$N手中$w急抖，$w的劍氣有如鞭子一般捲向$n，劍氣所帶起的氣流牢牢鎖定著$n，正是能使劍有如使鞭的絕技\n"+
"            "+HIY+"   ～～～　劍     流     雲  ～～～ "+NOR+"　　",
                "dodge"      :                -500,
                "damage"     :                550,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
                "damage_type":                "割傷",

         ]),
        ([
                "action"     :
"只聽$N如沉雷暴喝一聲，人已箭步而上，頃刻間劍氣暴放成萬道劍光，渾然在半空中刺出一個斗大的"+HIY+"「劍」"+NOR+"字，鋪天蓋\地的向$n壓去，正是能在虛空留痕的---- \n"+
"            "+HIC+"   ～～～　劍     流     痕  ～～～ "+NOR+"　　",
                "dodge"      :                -500,
                "damage"     :                800,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
                "damage_type":               "刺傷",
        ]),
        ([
                "action"     :
"$N左手持劍，右手捏個劍訣，雙手成環，緩緩抬起，這是玄龍劍法絕式的起手式。",
                "dodge"      :                -500,
                "damage"     :                700,
                "damage_type":               "刺傷",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:berserk2:),
        ]),
        ([
                "action"     :
"$N高舉手中的$w，迅速地在身前虛空劈了一個很大的"+HIC+"八"+NOR+"字，正是聖靈劍法之"+HIR+"「劍八」"+NOR+"，劍氣產生了很大的破空聲，直向$n而去。",
                "dodge"      :                -500,
                "damage"     :                800,
                "damage_type":               "砍傷",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp1:),
        ]),
        ([
                "action"     :
"$N施出「無名劍法」中的極致"+HIR+"「悲痛莫名」"+NOR+"，劍網交織的向$n攻去，使得$n不禁為了$N劍式中那悲傷的劍意所感動。",
                "dodge"      :                -500,
                "damage"     :                700,
                "damage_type":               "刺傷",
               "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
        ]),

});

mapping query_action(object me, object weapon)
{
   int skill_level, limit;
   skill_level = (int)(me->query_skill("bss-sword", 1));
   limit= (int)( skill_level/ 10);
      if (limit < 2 )
         return action[random(4 )];
      else if (limit < 3 )
         return action[random(5 )];
      else if (limit < 4 )
         return action[random(6 )];
      else if (limit < 5 )
         return action[random(7 )];
      else if (limit < 6 )
         return action[random(8 )];
      else if (limit < 7 )
         return action[random(9 )];
      else if (limit < 8 )
         return action[random(10 )];
         return action[random(11)];
}


void sp1(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("bss-sword", 1);
   message_vision("$N受到螺旋劍氣的影響，臉上忽青忽白，看來是受到了內傷了\n",victim);
   victim->add("kee", -(skill* 3));
   victim->apply_condition("hart",random(5)+((int)me->query_skill("dragonsword",1)/5));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}
void sp2(object me, object victim, object  weapon, int damage)
{
   int skill = me->query_skill("bss-sword", 1);
   message_vision("$N的劍氣在$n體內四處亂撞，造成嚴重的內傷\n",weapon,victim);
   victim->add("kee",-(skill* 3));
   victim->apply_condition("hart",random(5)+((int)me->query_skill("dragonsword",1)/5));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}
void sp3(object me, object victim, object  weapon, int damage)
{
   int skill = me->query_skill("bss-sword", 1);
   message_vision("$N被$n所帶起的上升氣流，捲至空中並被撕裂開來\n",victim,weapon);
   victim->add("kee",-(skill* 3));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}


void berserk2(object me, object victim, object  weapon, int damage)
{
 int skill_level=me->query_skill("bss-sword",1),bound;
 bound = victim->query("max_kee");
 bound = (bound/100)*5;
  if( random(170) > 27 && me->query("force",1) > 100 )
  {
    if(!me->query_temp("berserk2"))
    {
    if(weapon->query("id")=="dragon sword")
     {
       message_vision(
         sprintf(HIW + "\n$N忽然眼放精光，大喝一聲「風雲連續劍」，剎那間四週湧起一道黑雲，使$n完全失去$N的蹤影!!\n\n" + NOR),me ,victim);
       message_vision(
         sprintf(HIW + "\n$N以傳音之術對$n說到:「接招吧」，招式如狂風般朝$n襲至!!\n\n" + NOR),me ,victim);
       message_vision(
 sprintf(HIW + "\n風雲連續劍第一式" + HIB + "『行雲流水』" + HIW + "，" + HIY + "神龍劍" + HIW + "有如流水般朝$n攻去，使人目不暇己\n" + NOR),me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續劍第二式" + HIB + "『披星戴月』" + HIW + "，" + HIY + "神龍劍" + HIW + "忽然朝$n直刺過去，刺中了$n身上幾大要穴\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續劍第三式" + HIB + "『翻雲覆雨』" + HIW + "，" + HIY + "神龍劍" + HIW + "如風車般在$N身旁轉了起來，$n被劍招所產生的\n\n螺漩氣流所侵，受了重傷\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續劍第四式" + HIB + "『排山倒海』" + HIW + "，$N將" + HIY + "神龍劍" + HIW + "插入土地，跟著用力拔起，隨" + HIY + "神龍劍" + HIW + "而飛起的土石\n\n擊中了$n\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續劍第五式" + HIB + "『重雲深鎖』" + HIW + "，$N用手中" + HIY + "神龍劍" + HIW + "在$n身上畫了十幾個小圓圈，$n\n\n忽然身體一震，動彈不得\n\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
      message_vision(
 sprintf(HIW + "\n風雲連續劍第六式" + HIB + "『風捲殘樓』" + HIW + "，$N拔身而起，劍隨身轉，如一道龍捲風般朝$n攻去\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續劍第七式" + HIB + "『狂風暴雨』" + HIW + "，劍招連綿不絕的朝$n攻去，使$n身受重創\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續劍第八式" + HIB + "『神風怒嚎』" + HIW + "，" + HIY + "神龍劍" + HIW + "在空間中快速的砍劈，使四週產生了巨大的破空聲\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續劍第九式" + HIB + "『撕天排雲』" + HIW + "，" + HIY + "神龍劍" + HIW + "迅速的向左右各劈了兩下，劍氣快速地攻向$n\n" + NOR), me ,victim,weapon);
 victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續劍第十式" + HIB + "『雲海波濤』" + HIW + "，劍氣如巨浪狂湧而至，$n連閃避的機會也沒有\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續劍第十一式" + HIB + "『殃雲天絳』" + HIW + "，$N躍至空中，手中" + HIY + "神龍劍" + HIW + "朝$n直劈而去，劍氣充斥著這整個空間\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
     message_vision(
 sprintf(HIW + "\n$N使完劍法一十一式後，週圍的黑雲漸漸地消散了。\n\n" + NOR), me ,victim);

}
}
}
}
int valid_learn(object me)
{
   object ob;
//   if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") !="sword")
//      return   notify_fail("少了把劍練起來怪不順手的, 還是拿把劍再來練吧。\n");
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
   return CLASS_D("swordsman")+"/dragonsword/"+action;
}

string query_parry_msg(string limb)
{
   return parry_msg[ random( sizeof( parry_msg))];
}

void skill_improved(object me)
{
tell_object(me,"由於你潛心學習，你的玄龍劍法更加純熟了！！\n");
}




