#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void sp_attack1(object me, object victim, object  weapon, int damage);
void sp_attack2(object me, object victim, object  weapon, int damage);
void sp_attack3(object me, object victim, object  weapon, int damage);
void sp_attack4(object me, object victim, object  weapon, int damage);
void sp_attack5(object me, object victim, object  weapon, int damage);
void sp_attack6(object me, object victim, object  weapon, int damage);
void sp_attack7(object me, object victim, object  weapon, int damage);
int kar,cps,str,cor,int1,spi;
int sp_value;


mapping *action = ({
//1
        ([
                "action"     :  
"" + HIW + "$N將紫雷氣勁緩緩運入$w" + HIW + "中，快速將$w" + HIW + "往上而下劈落，使出" + HIY + "【" + MAG + "春雷暴殛" + HIY + "】" + HIW + "，$w" + HIW + "四周蘊含雷勁，如春雷般朝$n" + HIW + "狂襲而去。" + NOR + "",
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                120,
                "post_action":  (: sp_attack1 :),
                "force"      :                120,
                "damage_type":               "震傷"
        ]),

//2
        ([
                "action"     :  
"" + HIW + "$N將紫雷氣勁緩緩運入$w" + HIW + "中，並將$w" + HIW + "配合手中螺旋勁，使出" + HIY + "【" + MAG + "天旋雷轉" + HIY + "】" + HIW + "，雷勁隨著螺旋勁在$w" + HIW + "四週圍繞著，急速的朝著$n" + HIW + "擊去。" + NOR + "",
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                150,
                "force"      :                150,
                "damage_type":               "震傷"
        ]),

//3
        ([
                "action"     :  
"" + HIW + "$N將紫雷氣勁緩緩運入$w" + HIW + "中，然後迅速將$w" + HIW + "朝地上擊去，使出" + HIY + "【" + MAG + "沉雷地獄" + HIY + "】" + HIW + "，雷勁由$w" + HIW + "傳至地下，最後雷勁在$n" + HIW + "地下爆發。" + NOR + "",
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                180,
                "force"      :                180,
                "damage_type":               "震傷"
        ]),

//4
        ([
                "action"     :  
"" + HIW + "$N將紫雷氣勁緩緩運入$w" + HIW + "中，並將$w" + HIW + "拋至空中以氣御之，使出" + HIY + "【" + MAG + "冬雷霹靂" + HIY + "】" + HIW + "，$N利用真氣迅速牽引$w" + HIW + "朝$n" + HIW + "劈去。" + NOR + "",
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                210,
                "force"      :                210,
                "damage_type":               "震傷"
        ]),

//5
        ([
                "action"     :  
"" + HIW + "$N將紫雷氣勁緩緩運入$w" + HIW + "中，使出" + HIY + "【" + MAG + "狂雷震九霄" + HIY + "】" + HIW + "，$w" + HIW + "瞬時承受不了如此大的氣勁，將氣勁傳至空氣，瞬時形成一股蘊含雷勁之旋風朝$n" + HIW + "襲去。" + NOR + "",
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                240,
                "force"      :                240,
                "damage_type":               "震傷"
        ]),
//6
        ([
                "action"     :  
"" + HIW + "$N將紫雷氣勁緩緩運入$w" + HIW + "中，並將$w" + HIW + "朝地面狂劈，使出" + HIY + "【" + MAG + "驚雷爆五嶽" + HIY + "】" + HIW + "，地面承受不住如此強大氣勁瞬時地裂，氣勁隨著裂縫朝$n" + HIW + "襲去。" + NOR + "",
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                270,
                "post_action":  (: sp_attack6 :),
                "force"      :                270,
                "damage_type":               "震傷"
        ]),

//7
        ([
                "action"     :  
"" + HIW + "$N將紫雷氣勁發揮到極限，使出" + HIY + "【" + MAG + "怒雷撕天裂地" + HIY + "】" + HIW + "，瞬時風雲變色，只見$N利用雷勁隔空將手中$w" + HIW + "劈向$n" + NOR + "。",
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                300,
                "force"      :                300,
                "damage_type":               "震傷"
        ]),

});

int valid_learn(object me)
{
       if(!me->query("quest/purple_thunder",1)){
        tell_object(me,"你還不夠資格練紫雷七擊。\n");
        return 0;
                                               }
       if( (me->query("potential") - me->query("learned_points")) < 5 ) {
        tell_object(me, "你的潛能不到五點，無法練紫雷七擊。\n");
        return 0;
                                                                         }
        me->add("potential", -5);
        return   1;
}

int valid_enable(string usage)
{
return (usage=="unarmed" || usage=="blade" || usage=="sword" || usage=="stabber" || usage=="dagger" || usage=="whip" || usage=="parry" );
}

mapping query_action(object me, object *weapon)
{

 int skill_level,limit,i;
 kar=me->query_kar();
 cps=me->query_cps();
 str=me->query_str();
 cor=me->query_cor();
 int1=me->query_int();
 spi=me->query_spi();
 skill_level = (int)(me->query_skill("purple_thunder",1));
 limit= skill_level;

        if (limit < 15)
                return action[random(1)];
        else if (limit < 30)
                return action[random(2)];
        else if (limit < 45)
                return action[random(3)];
        else if (limit < 60)
                return action[random(4)];
        else if (limit < 75)
                return action[random(5)];
        else if (limit < 90)
                return action[random(6)];
        else
          return action[random(7)];
}

void sp_attack1(object me, object victim, object weapon, int damage)
{
        if(me->query("max_force") >= 2000)
        {
                me->add("force",-200);
victim->start_busy(2);

message_vision(HIC + "$N暗運雷勁，使得$n因受真氣受雷勁所阻因而動彈不了。\n" + NOR,me,victim);
        }
}

void sp_attack6(object me, object victim, object weapon, int damage)
{
int i,force;
force=me->query("max_force")/400;
if(force < 1) force=1;
if(force > 5) force=5;
if(me->query("max_force") >= 2000)
{
  for(i=1;i<=force;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf("" + HIC + "$N使出驚雷破五嶽之" + HIR + "『破南嶽』" + NOR + "" + HIC + "，雷勁朝$n的左手擊去。\n"),me,victim);
     break;
     case 2:
message_vision(sprintf("" + HIC + "$N使出驚雷破五嶽之" + HIR + "『破北嶽』" + NOR + "" + HIC + "，雷勁朝$n的右手擊去。\n"),me,victim);
     break;
     case 3:
message_vision(sprintf("" + HIC + "$N使出驚雷破五嶽之" + HIR + "『破東嶽』" + NOR + "" + HIC + "，雷勁朝$n的左腳擊去。\n"),me,victim);
     break;
     case 4:
message_vision(sprintf("" + HIC + "$N使出驚雷破五嶽之" + HIR + "『破西嶽』" + NOR + "" + HIC + "，雷勁朝$n的右腳擊去。\n"),me,victim);
     break;
     case 5:
message_vision(sprintf("" + HIC + "$N使出驚雷破五嶽之" + HIR + "『破中嶽』" + NOR + "" + HIC + "，雷勁朝$n的身軀擊去。\n"),me,victim);
     break;
     }
message_vision(sprintf(HIC + "$N確實命中$n各處，$n體內各處雷勁流竄。\n" + NOR),me,victim);
         victim->receive_wound("kee",150,me);
victim->start_busy(1);
          COMBAT_D->report_status(victim, 1);
   }
   me->add("force",-70);
   COMBAT_D->report_status(victim, 1);
} 
else
message_vision(sprintf("結果$N的內勁不夠使不出來。\n"),me,victim);
}


