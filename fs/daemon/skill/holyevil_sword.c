// 仙劍第三二代技..威力超出一般skill by appo
// 只開放給逍遙子使用..
// 如要複製請先通知....
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void holy1(object me, object victim, object  weapon, int damage);
void holy2(object me, object victim, object  weapon, int damage);
void holy3(object me, object victim, object  weapon, int damage);
void holy4(object me, object victim, object  weapon, int damage);
void holy5(object me, object victim, object  weapon, int damage);
int kar,cps,str,cor,int1,spi;
int sp_value;
string *parry_msg = ({
"\n而$n手中的長劍一橫，一招"HIB"『鐵鎖橫江』"NOR"勢挾千斤往前一推一送，噹的一聲碰出了點點火花反把$N手中的$w險些震飛！\n"NOR,
"\n但$n長劍一轉，順著$N的$w以一招"HIC"『順流而下』"NOR"往$N的手指削去，$N大驚失色下急忙收招回架\n",
"\n$n劍走輕靈，手中長劍忽削忽刺一連串的兵器撞擊聲後$n已將$N的快招全部化解！\n",
"\n$n以快制快，$N快但$n更快，連續刺出了七七四十九劍織成一道劍網將$N的招式盡數盪開！\n"NOR,
"\n$n將手中長劍一縮一放，以一招"HIB"『如影隨形』"NOR"長劍隨$N的$w舞動，卸掉$N的勁力！\n"NOR,
"\n$N以千軍萬馬之勢攻向$n，只見$n不慌不忙以逸待勞"HIC"『排山倒海』"NOR"，將$N的攻勢消解在無形中！\n"NOR,
"\n$n以心制劍，不慌不忙將其武學發揮的淋漓盡致一招"HIR"『日月並行』"NOR"，將$N嚇得急忙收招！\n"NOR,
        });
string *unarmed_parry_msg = ({
"但是被$n格開了。\n",
"結果被$n擋開了。\n",
});
mapping *action = ({
//1
          ([    "action"     :               HIR"$N鼓動身上無比聖魔氣勁，手中配劍隨意所至在半空中幻化出一黑一白的劍芒，反反覆覆射出無數光芒"NOR,
                "parry"      :                -180,
                "dodge"      :                -180,
                "damage"     :                510,
                "force"      :                510,
                "post_action":                (: holy1 :),
                "damage_type":                "割傷",
           ]),
//2
              ([ "action"     :              HIR"$N抖了抖身軀，運起身上無比魔勁，帶動渾身血氣一招魔族奧義\n"NOR"
"+HIM"                      ----血霧刃---\n"NOR"
"+HIW"伴隨陣陣的血霧，$N消失於眾人眼前，只見血霧漸漸散佈四周"NOR,
              "dodge"      :                 -250,
              "parry"      :                 -250,
              "damage"     :                 600,
              "force"      :                 600,
              "post_action":               (: holy2 :),
              "damage_type":               "劍傷",
             ]),
//3
         ([     "action"     :               HIR"$N殺的起勁，身上神聖之氣牽動仙劍絕學╠═ "HIY"昊 陽˙競 月"HIW" ═╣，頓時間日月之氣充斥四週，直撲$n"NOR,
                "parry"      :                -200,
                "dodge"      :                -200,
                "damage"     :                550,
                "force"      :                550,
                "post_action":                (: holy3 :),
                "damage_type":                "割傷",
           ]),
//4
         ([     "action"     :               HIR"$N電擊般格掠向前，千百條絢燦明亮的"+HIY"劍芒"+HIR"，參差不齊的在同一時間，像炸開了一朵"+HIW"光球"+HIR"般"NOR"
"+HIR"朝四週飛射掠舞，頓時眼前炫亮的劍芒頓時消失，取而代之的為無數黑色劍影，帶動無比邪意..直逼$n\n"NOR,
                "parry"      :                -220,
                "dodge"      :                -220,
                "damage"     :                540,
                "force"      :                540,
                "post_action":                (: holy4 :),
                "damage_type":                "割傷",
           ]),
//5
         ([     "action"     :               HIR"$N電擊般格掠向前，千百條絢燦明亮的"+HIY"劍芒"+HIC"，參差不齊的在同一時間，像炸開了一朵"+HIW"光球"+HIC"般朝四週飛射掠舞，$n"+HIC"目光一眩，以身陷其中"NOR"
"+HIR"同時，$N身後邪氣大振，帶動寒冰劍氣配合陣陣火焰形成冰火劍陣，瞬間包圍整個戰場$n"NOR,
                "parry"      :                -250,
                "dodge"      :                -250,
                "damage"     :                540,
                "force"      :                540,
                "post_action":                (: holy5 :),
                "damage_type":                "割傷",
           ]),
//6
(["action":"$N並非劍客...無法使用此劍術。",
  "force":10,
  "damage":10,
  "damage_type":"白癡傷",
]),
});

int valid_learn(object me)
{
       if( !me->query_temp("weapon"))
                          {
        tell_object(me,"練劍法必需先拿把劍。\n");
        return 0;
                                               }
       if( (me->query("potential") - me->query("learned_points")) < 15 ) {
        tell_object(me, "你的潛能不到十點，無法練此劍法。\n");
        return 0;
                                                                         }
        me->add("potential", -10);
        return   1;
}

int valid_enable(string usage)
{
        return ( usage=="sword" || usage=="parry" );
}
mapping query_action(object me, object *weapon )
{
  int skill_level,limit;
 kar=me->query_kar();
 cps=me->query_cps();
 str=me->query_str();
 cor=me->query_cor();
 int1=me->query_int();
 spi=me->query_spi();
  skill_level = (int)(me->query_skill("holy_sword",1));
  limit= skill_level;
if(me->query("family/family_name")!="仙劍派")
return action[8];
       if (limit < 20)
                return action[random(1)];
        else if (limit < 50)
                return action[random(2)];
        else if (limit < 70)
                return action[random(3)];
        else if (limit < 99)
                return action[random(4)];
       else return action[random(5)];

}
void holy1(object me, object victim, object weapon, int damage)
{
  sp_value =7*(str+cor)+cps+kar+spi+int1;
 message_vision(HIG"$N運起渾身氣勁牽動身上聖魔兩種極端靈氣，一招【"+HIW"神魔兩極"+HIG"】挾帶兩股不同屬性的劍芒，一波一波直取$n。\n"NOR,me,victim);
if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/10 )
    {
    victim->receive_wound("kee",sp_value,me);
    COMBAT_D->report_status(victim, 1);
    }
else
    {
    message_vision(sprintf(HIR"千鈞一髮之際$n"+HIR"避開了$N"+HIR"的殺招！\n"NOR),me,victim);
    }
}
void holy2(object me, object victim, object  weapon, int damage)
 {
    int i,time;
    damage = 6*(cor+int1+str+spi+cps+kar);
 if (!me->query_temp("strike"))
  {
    time = random(7);
    me->set_temp("strike",1);
    if (random(cor) > random(10))
    victim->start_busy(1);
    for(i=0;i<=time;i++)
   {
     message_vision(sprintf(HBRED"血霧連天 - 魔意無窮 - 陣陣邪氣 - 層層殺勁\n"NOR),me,victim);
     victim->add("kee",-damage);
   COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
   }
   me->delete_temp("strike");
  }
 else
  {
   if( me->query_temp("strike")==1 )
   {
    message_vision(sprintf(HIR"片片血霧...引起無限殺機...\n"NOR),me,victim);
    damage = 10*(cor+int1+str+spi+cps+kar);
   }
   else
   {
    if (random(cor) > random(10))
    victim->start_busy(1);
    for(i=0;i<=time;i++)
     {
       {
     message_vision(sprintf(HBRED"血霧連天 - 魔意無窮 - 陣陣邪氣 - 層層殺勁\n"NOR),me,victim);
        victim->receice_damage("kee",-damage);
   COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
       }
       victim->delete_temp("conti");
     }
   }
  }
}
void holy3(object me, object victim, object weapon, int damage)
{
   int times;
   sp_value =8*(str+cor)+cps+kar+spi+int1;
times=3;
  if(victim)
   if(!victim->query_temp("sword"))
   {
     victim->add_temp("sword",times);
     message_vision(HBRED"$N藉由神聖日月之氣,對$n發動強勁的攻勢\n"NOR,me,victim);
    victim->receive_wound("kee",sp_value);
     COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
     call_out("sunmoon8",1,me,victim,sp_value);

   }
   else
   {
     message_vision(HIR"$N藉由神聖日月之氣,對$n發動強勁的攻勢\n"NOR,me,victim);
    victim->receive_wound("kee",sp_value);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        }
}
int holy8(object me, object victim, int sunmoon)
{
int n,k;
sp_value =8*(str+cor)+cps+kar+spi+int1;
n = victim->query_temp("sword");
sunmoon = sunmoon-random(victim->query("dodge")/5);
if(environment(victim) && victim->query_temp("sword")>=1 &&me->is_fighting())
{
if (sunmoon <= 0)
    {
     victim->delete_temp("sword");
     message_vision(RED"$n耗盡真氣真氣抵擋日月絕學的殺招\n"NOR,me,victim);
       return 1;
    }
   if(victim->query_temp("sword"))
    {
     switch(random(n)+1)
     {
     case 1:
//基本case
message_vision(HIG"日月絕學奧義〒"+HIW"開 天 闢 地 ═ 日 光 月 影"+HIB"〒。\n"NOR,me,victim);
    message_vision(HIY"日月奧義牽動皓月之氣,無影無息..$N已殺至$n身邊！\n"NOR,me,victim);
    victim->receive_wound("kee",sp_value+130,me);
    victim->start_busy(1);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
     call_out("sunmoon8",1,me,victim,sunmoon);
     break;
     break;
     case 2:
//容貌一般 加上no_power
message_vision(sprintf(HIG"日月絕學奧義〒"+HIW"昊 陽 震 宇 ═ 覆 月 無 垠"+HIB"〒。\n"NOR),me,victim);
    message_vision(HIY"日月奧義牽動艷陽昊氣,$N藉由艷陽昊氣對$n發動無情的攻擊！\n"NOR,me,victim);
    victim->receive_wound("kee",sp_value+130,me);
    victim->set_temp("no_power",1);
    victim->apply_condition("no_power",2);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    call_out("sunmoon8",1,me,victim,sunmoon);
     break;
     break;
     case 3:
//解quest 後習得 加上連擊&busy(1)
message_vision(sprintf(HIG"日月絕學奧義〒"+HIW"長 日 高 掛 ═ 月 下 無 敵"+HIB"〒。\n"NOR),me,victim);
     message_vision(HIY"
     $N將天上艷陽皓月兩股至陰至陽之氣吸納入體內,只聽$N大喊
"+HBCYN" 昊    。    陽    。    競    。    月    。    破    。    天    。    轟！\n"NOR,me,victim);
  message_vision(HIY"$N牽動昊日罡\氣,虹月柔勁,瞬間殺出數招！\n"NOR,me,victim);

   victim->receive_wound("kee",sp_value,me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    for(k=0;k<2;k++)
    {
    COMBAT_D->report_status(victim);
    }
     victim->set_temp("no_power",1);
    victim->apply_condition("no_power",2);
    victim->start_busy(1);
     call_out("holy8",1,me,victim,sunmoon);
     break;
     break;
      }
    }
    }
else victim->delete_temp("sword");
}
void holy4(object me, object victim, object  weapon, int damage)
{
  sp_value =10*(str+cor)+cps+kar+spi+int1;
message_vision(HIG"$N使出一招【"+HIW"聖 劍 無 影 ═ 邪 劍 無 極"+HIG"】，劍意無涯，聖邪交集之氣牽動天雷之氣。\n"NOR,me,victim);
if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/10 )
    {
    message_vision(sprintf(HIR"$n閃躲不及，無影幻劍穿體而過...隨後而至的九天真雷亦毫不留情的轟在$n身上！\n"NOR),me,victim);
    victim->receive_damage("kee",sp_value,me);
    victim->apply_condition("tsunami",5);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

    }
else
    {
    message_vision(sprintf(HIR"千鈞一髮之際$n"+HIR"避開了$N"+HIR"的殺招！\n"NOR),me,victim);
    }
}
void holy5(object me, object victim, object  weapon, int damage)
{
  int i,j;
  object ob,room,*target;
  room = environment(me);
  target=me->query_enemy(room);
  i=sizeof(target);
  sp_value =10*(str+cor)+cps+kar+spi+int1;
  message_vision(HIG"$N將身上聖魔之氣運至極限，一招【"+HIW"神 魔 同 體 ═  冰 火 至 極"+HIG"】\n牽動無比狂霸氣勁直擊場中所有敵人。\n"NOR,me,victim);
  for(j=0;j < i;j++)
  {
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/12 )
    {
      if(!target[j]) continue;
      target[j]->receive_damage("kee",sp_value+130,me);
      target[j]->start_busy(1);
      target[j]->receive_wound("kee",sp_value);
      target[j]->set_temp("no_power",1);
      target[j]->apply_condition("no_power",2);
      COMBAT_D->report_status(target[j]);
    }
   else
    {
    message_vision(sprintf(HIR"千鈞一髮之際$n"+HIR"避開了$N"+HIR"的殺招！\n"NOR),me,victim);
    }
  }
 }
string perform_action_file(string action)
{
          return CLASS_D("swordsman")+"/sun_moon_sword/"+action;
}   
