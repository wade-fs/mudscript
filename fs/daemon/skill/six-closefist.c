
//  six-closefist.c
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void power(object me, object victim, object weapon, int damage);
void burn(object me, object victim, object weapon, int damage);
//void diyk(object me, object victim, object weapon, int damage);//
mapping *action = ({
 (["action":"$N大喝一聲,一招"HIW"『虎 抱 頭』"NOR"$N左腳一跨、身子一起﹐
左手手肘以強烈的衝擊往$n頂過去",
                  "dodge":     -40,
                  "parry":     -30,
                  "force":     130,
                  "damage":    60,
                  "damage_type":     "挫傷",
                 ]),
 (["action":"$N身子一側﹐使出一招"HIY"『烏牛擺\頭』"NOR"$N右腳往右一跨﹐拳勁順勢往$n的左肩一擊",
                  "dodge":     -40,
                  "parry":     -10,
                  "force":     130,
                  "damage":     65,
                  "damage_type":    "瘀傷",
            ]),
 (["action":"$N沉馬一站﹐運起全身勁力使出一招"HIB"『懷抱頑石·鷹捉把』"NOR"$N右手手肘往$n一頂﹐趁$n不防之時使出掌勁將$n一頭按下",
                  "dodge":     -50,
                  "parry":     -30,
                  "force":     130,
                  "damage":     70,
                  "damage_type":     "瘀傷",
                  "post_action":  (: burn :),
                 ]),
 (["action":"$N趁勢使出六合拳之"HIC"『懷抱頑石．雙推把．雙把』"NOR"﹐掌勁渾厚順勢往$n五臟六腑擊出五掌",
                  "dodge":     -50,
                  "parry":     -30,
                  "force":     130,
                  "damage":     80,
                  "damage_type":     "瘀傷",
                 ]),
 (["action":"$N丹田一運、氣功\一調使出一招"HIG"『丹鳳朝陽．虎蹲山』"NOR"$N腳往前一跨﹐拳勁往$n下額一擊伺機在以掌勁往$n頭部一切",
                  "dodge":     -40,
                  "parry":     -30,
                  "force":     140,
                  "damage":     90,
                  "damage_type":     "瘀傷",
                  "post_action":  (: burn :),
                 ]),
 (["action":"$N使出心意六合拳之"HIG"『盤肘．丹鳳朝陽』"NOR"$N雙手一盤﹐往$n右胸頂過去﹐在以反手掌勁往$n下額拍去",
                "dodge":                -30,
                "parry":                -20,
                "force":                180,
                "damage":               100,
                "damage_type": "瘀傷",
                "post_action":  (: power :),
       ]),

 (["action":"$N馬步一沉﹐一招六合拳之"HIM"『雞子栽肩』"NOR"$N右膝往$n的腹部一頂﹐右手拳勁順勢往$n頂門一擊過去",
                  "dodge":     -50,
                  "parry":     -30,
                  "force":     150,
                  "damage":     100,
                  "damage_type":     "瘀傷",
                "post_action":  (: power :),
                 ]),
 (["action":"$N使出六合拳一招"HIB"『雞腿．半旋風』"NOR"$N腳勁凌厲往$n身上連踹兩腳",
                "dodge":                -30,
                "parry":                -10,
                "force":                200,
                "damage":               110,
                "damage_type":  "瘀傷",
                "post_action":  (: power :),
                 ]),
 (["action":"$N使出六合拳之"HIR"『七寸腿．烏牛擺\頭』"NOR"$N右腳微踢﹐在以渾厚拳勁往$n頭部一擊",
                     "dodge":     -40,
                     "parry":     -10,
                     "force":     200,
                     "damage":    120,
                     "damage_type":    "瘀傷",
                     "post_action":  (: burn :),
       ]),
 (["action":"$N使出心意六合拳之精華"HIY"【雲閉日月把】"NOR"$N雙掌將$n雙手按下﹐伺機再以雙掌順勢往$n的下額和胸部擊掌過去",
                     "dodge":     -40,
                     "parry":     -40,
                     "force":     200,
                     "damage_type":    "瘀傷",
                     "damage":    150,
                     "post_action":  (: burn :),
       ]),
 (["action":"$N使出心意六合拳之精隨"HIY"【心 意 把】"NOR"$N將$n手反手按住再用
堅實的肩部頂向$n的胸部",
                     "dodge":     -40,
                     "parry":     -40,
                     "force":     200,
                     "damage":    160,
                     "damage_type":    "瘀傷",
                     "post_action":  (: burn :),
    ]),

});
void power(object me, object victim, object weapon, int damage)

{

int i;
 if(me->query("combat_exp") >= 600000 )
 if(me->query("force")>100&&me->query("force_factor"))

{
   for(i=1;i<=3;i++)
{
    switch(i)
{
case 1:
message_vision(sprintf(
HIC"$N見敵人的攻勢瓦解決定使出心意六合拳之"HIY"『硬開三皇鎖』"NOR"，"HIC"直取敵人的三處要害。\n"NOR),me);


message_vision(sprintf(
HIG"$N單手將$n的右手抓住，使出左手掌勁往$n手關節處擊去，只聽見$n唉嚎一聲。\n"NOR),me,victim);
break;
case 2:
message_vision(sprintf(
HIW"$N再以雄厚的手肘順勢往$n的胸部要害狠狠的頂過去，只聽見$n慘叫一聲。\n"NOR),me,victim);
break;
case 3:
message_vision(sprintf(
HIM"$N再順是以反手掌勁往$n的面門一拍，霎時$n血噴八步，$n的面門慘不能睹。\n"NOR),me,victim);
break;
}
     if(me->query_skill("six-closefist",1)>random(80))
{
message_vision(sprintf("結果被$N確確實實的命中要害，$n看來快氣絕身亡了。\n"),me,victim);
            victim->receive_wound("kee",80,me);
          COMBAT_D->report_status(victim, 1);
   me->add("force",-80);
}else{

message_vision(sprintf("結果$N的攻擊被$n輕鬆避了開來。\n"),me,victim);
}
}
}
}
void burn(object me, object victim, object  weapon, int damage)
{
message_vision(HIM"$N的勁力使$n的體內血脈筋骨斷裂，使$n受到了嚴重的內傷\n"NOR,me,victim);
         victim->apply_condition("burn",random(30));
         victim->receive_damage("kee",30);
         victim->add("force",-30);
         COMBAT_D->report_status(victim, 1);
 }

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                           return   notify_fail("心意六合拳必需空手。\n");
        if(me->query("max_force")<100)
               return notify_fail("喂! 小子, 內力上限要 100 喔﹐等你長大點再來。\n");
        if(me->query_skill("snowforce",1)<10)
               return notify_fail("你的六合心法火候不夠﹐不能練心意六合拳。\n");
        if(me->query_skill_mapped("dodge")=="six-closefist")
               me->map_skill("dodge","black-steps");
        return 1;

}

int valid_enable(string  usage)  {

        if(this_player()->query_skill("six-closefist",1) >= 50)
         {
            return (usage=="unarmed")||(usage=="parry");
         }
             return usage=="unarmed";
}



mapping query_action(object me, object weapon)

{
   int skill;
   skill=me->query_skill("six-closefist", 1);
   if( skill < 20)
      return action[random(3)];
   else if( skill < 40)
      return action[random(4)];
   else if( skill < 60)
      return action[random(5)];
   else if( skill < 80)
      return action[random(9)];
   else if( skill < 90)
      return action[random(10)];
   else
      return action[random(11)];

}

int practice_skill(object me)

{
        if( (int)me->query("kee") < 30 )
                      return  notify_fail("你的氣不夠﹐無法練習心意六合拳。\n");
        if( (int)me->query("force") < 5 )
                   return  notify_fail("你的內力不夠﹐不能練習心意六合拳。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string action)

{
        return CLASS_D("fighter")+"/six-closefist/"+action;
}


