#include <combat.h>
#include <ansi.h>
inherit SKILL;
void sun1(object me, object victim, object  weapon, int damage);
void sun2(object me, object victim, object  weapon, int damage);
void sun3(object me, object victim, object  weapon, int damage);
void sun4(object me, object victim, object  weapon, int damage);
void sun5(object me, object victim, object  weapon, int damage);
void sun6(object me, object victim, object  weapon, int damage);

mapping *action = ({
//1
  ([ "action": 
HIY + "$N使出" + HBBLU+HIW + "Ψ天山六陽掌Ψ" + NOR+HIY + "之起手式" + HIR + "『陽關三疊』" + HIY + "強勁的掌力以連綿不絕生生不息之力
有如排山倒海之勢朝$n擊去，一掌三式掌勁渾厚無匹。" + NOR,
                "dodge":                -5,
                "parry":                -20,
                "force":                200,
                "damage":               300,
                "post_action":               (:sun1:),
                "damage_type":  "內傷",                
        ]),
//2
  ([ "action": 
HIY + "$N聚起全身的內力化勁成焰，一招" + HIW + "『烈陽普照』" + HIY + "全身上下發出巨大的光芒，刺
眼的光芒使$n無法張眼，$N身上發出強烈的溫度使$n全身灼傷有如陷
入焚爐之中痛苦萬分。" + NOR,
        "dodge":        -10,
        "parry":        -50,
        "force":        300,
        "damage":       350,
        "post_action":               (:sun2:),
        "damage_type":  "灼傷",
        ]),
//3
  ([ "action":
HIY + "$N左手運勁內走奇經八脈化氣成焰，右手逆轉內勁氣走丹田化為霜，使出\n" + HBBLU+HIW + "Ψ天山六陽掌Ψ" + NOR+HIY + "第三式" + HIC + "『陽盛陰衰』" + HIY + "，強大的內勁催使$n左冷右熱兩極
交叉內息大亂受到嚴重的內傷狂吐鮮血。" + NOR,
           "dodge":        -15,
           "parry":        -30,
           "force":        200,
           "damage":       400,
           "post_action":               (:sun3:),
           "damage_type":  "內傷",
      ]),
//4
  ([ "action": 
HIC + "$N身法如鷹府衝而下一式" + HIW + "『陽歌天勾』" + HIC + "以詭異的身法遊走$n的四方，趁其不備雙
手運勾朝$n的腦門撲擊而去。" + NOR,
          "dodge":        -60,
          "parry":        -65,
          "force":        100,
          "damage":       450,
          "post_action":          (:sun4:),
          "damage_type":  "瘀傷",
        ]),
//5
  ([ "action": 
HIM + "$N使出" + HBBLU+HIW + "Ψ天三六陽掌Ψ" + NOR+HIM + "第五式" + HIC + "『春陽白雪』" + HIW + "，$N身形飛舞全身散發寒勁成霜，當場雪
花漫天飛舞，$n完全看不見四周的情形，$N趁機發動攻勢偷襲使其受創。" + NOR,
           "dodge":        -80,
           "parry":        -80,
           "force":        300,
           "damage":       500,
           "post_action":      (:sun5:),
           "damage_type":  "瘀傷",
        ]),
//6
  ([ "action": 
HIR + "$N聚勁雙臂運勁成焰，凝聚強大的熱量使出" + HBBLU+HIW + "Ψ天山六陽掌Ψ" + NOR+HIR + "第六式" + HIY + "『驕陽似火』" + HIR + "，烈焰
掌勁侵入$n全身陣陣如火酷勁有如遭烈焰焚身。" + NOR,
           "dodge":       -70,
           "parry":        -70,
           "force":        350,
           "damage":       600,
           "post_action":      (:sun6:),
           "damage_type":  "焚傷",
        ]),
});



int valid_enable(string usage)
{
                return ( usage=="unarmed" || usage=="parry" );   
}



void sun1(object me, object victim, object weapon, int damage)
{
         if(((me->query("combat_exp")+random(2000000)) > (victim->query("combat_exp")+random(2000000)))
         || random(50)>40)
         {
           message_vision(HIR + "\n陽關三疊之" + HBRED+HIM + "【毀山劈天】\n" + NOR, me, victim);
           victim->receive_damage("kee",500);
           COMBAT_D->report_status(victim);
           message_vision(HIR + "\n陽關三疊之" + HBBLU+HIC + "【形合破滅】\n" + NOR, me, victim);
           victim->receive_wound("kee",500);
           COMBAT_D->report_status(victim);
           message_vision(HIR + "\n陽關三疊之" + HBGRN+HIG + "【虛空無極】\n" + NOR, me, victim);
           if((victim->query("force_factor")-2)<0)
             victim->set("force_factor",0);
           else victim->add("force_factor",-2);
           COMBAT_D->report_status(victim);
         }else message_vision(HIW + "$n順勢閃過了$N的攻擊。\n" + NOR, me, victim);          
        
}

void sun2(object me, object victim, object weapon, int damage)
{
	if(((me->query("move")+random(100)) > (victim->query("move")+random(100)))
         || random(50)>40)
        {
	  message_vision(HIR + "\n$n一個不小心被$N的烈陽餘勁所傷。\n" + NOR, me, victim);
	  victim->receive_damage("kee",200);
	  victim->apply_condition("burn",random(10)+1);
	  COMBAT_D->report_status(victim);
	}
}


void sun3(object me, object victim, object  weapon, int damage)
{
       if(((me->query("force")+random(50000)) > (victim->query("force")+random(50000)))
         || random(50)>30)
       {
         message_vision(HIC + "\n$n受不了忽冷忽熱的煎熬受了嚴重的內傷。\n" + NOR, me, victim);
         victim->receive_damage("kee",200);
         victim->apply_condition("star-stial",random(10)+1);
         COMBAT_D->report_status(victim);
       }
}

void sun4(object me, object victim, object weapon, int damage)
{
       if(((me->query("dodge")+random(100)) > (victim->query("dodge")+random(100)))
         || random(50)>45)
       {
         message_vision(HIY + "\n$n閃躲不擊慘招$N凌厲攻勢所傷。\n" + NOR, me, victim);
         victim->receive_wound("kee",500);
         victim->apply_condition("bleeding",random(10)+1);
         COMBAT_D->report_status(victim);
       }
}

void sun5(object me, object victim, object weapon, int damage)
{
       if(((me->query("parry")+random(100)) > (victim->query("parry")+random(100)))
         || random(50)>40)
       {
         message_vision(HIW + "\n$N使出天山六陽掌之變招『天山折梅手』，$n被此招牽制無法使力。\n" + NOR, me, victim);
         victim->receive_damage("kee",200);
         victim->apply_condition("power-down",random(10)+1);
         COMBAT_D->report_status(victim);
       }
}

void sun6(object me, object victim, object weapon, int damage)
{
       if(((me->query("combat_exp")+random(2000000)) > (victim->query("combat_exp")+random(2000000)))
         || random(50)>45)
       {
         message_vision(HIG + "\n$N驕陽似火一出，$n運勁丹田竟感覺空空蕩蕩毫無內勁。\n" + NOR, me, victim);
         victim->apply_condition("no_power_e",random(10)+1);
         COMBAT_D->report_status(victim);
       }
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}


string perform_action_file(string action)
{
        return CLASS_D("tensan")+"/sunstrike/"+action;
}
