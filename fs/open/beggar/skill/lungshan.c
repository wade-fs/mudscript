// lungshan.c
// Chan 15/5做最後的修正
// Chan 10/22重新改寫
// 1.增加武器特功 2.修正連續技
// Swy QC 87/10/22  未經許可請勿修改
#include <combat.h>
#include <ansi.h>
inherit SKILL;
void berserk(object me,object victim,object weapon,int damage);
void berserk1(object me,object victim,object weapon,int damage);
void berserk2(object me,object victim,object weapon,int damage);
void fire1(object me, object victim, object  weapon, int damage);
void fire2(object me, object victim, object  weapon, int damage);
void fire3(object me, object victim, object  weapon, int damage);
int kar=this_player()->query_kar(1);
int cps=this_player()->query_cps(1);
int str=this_player()->query_str(1);
int cor=this_player()->query_cor(1);
int int1=this_player()->query_int(1);
int spi=this_player()->query_spi(1);
int sp_value;
// 武者 damage and force 上限為 190
mapping *action = ({
// 1
([
     "action"     :"$N使出瀧山絕學的起手式﹐一招「飛瀑入山」﹐對準$n的$l打出難以捉摸的一拳",
     "dodge"      :-25,
     "parry"      :-20,
     "damage"     : 30,
     "force"      : 50,
     "damage_type":"瘀傷"
 ]),
// 2
 ([
     "action"     :"$N低吼一聲!!真氣從雙掌中釋出，使出一招「江河日下」﹐對準$n的$l急拍而出",
     "dodge"      :-25,
     "parry"      :-20,
     "damage"     : 25,
     "force"      : 50,
     "damage_type":"瘀傷"
 ]),
// 3
 ([
     "action"     :"$N猶如流水般隨$n的攻勢﹐使出一招「追瀑溯源」便往$n的$l反擊過去",
     "dodge"      :-50,
     "parry"      :-10,
     "damage"     : 20,
     "force"      : 80,
     "damage_type":"瘀傷"
 ]),
// 4
 ([
     "action"     :"$N大喝一聲﹐雙拳一提﹐一招「五嶽頂天」往$n的五個要害擊出",
     "dodge"      :-10,
     "parry"      :-25,
     "damage"     : 70,
     "force"      : 100,
     "damage_type":"瘀傷"
 ]),
// 5
 ([
     "action"     :"$N步履一沉﹐凝神聚氣﹐雙拳連下使出「千川百嶽」擊向$n$l",
     "dodge"      :-30,
     "parry"      :-5,
     "damage"     : 90,
     "force"      : 190,
     "damage_type":"瘀傷"
 ]),
// 6
 ([
     "action"     :"$N縱身一躍﹐使出瀧山拳奧義「山泉群湧」﹐拳如連珠般一連數十拳擊向$n$l",
     "dodge"      :-30,
     "parry"      :-30,
     "damage"     : 110,
     "force"      : 150,
     "damage_type":"瘀傷"
 ]),
// 7
 ([
     "action"     :"$N雙拳交錯﹐運足真氣﹐使出瀧山拳奧義「山窮水盡」﹐萬鈞之力擊向$n$l﹐難以招架",
     "dodge"      :-20,
     "parry"      :-45,
     "damage"     : 130,
     "force"      : 140,
     "damage_type":"瘀傷"
 ]),
// 8
 ([
     "action"     :"$N雙手如「流水」般柔亦柔、剛亦剛，使出瀧山拳中奧義「川流不息」﹐似有似無般向$n$l擊出",
     "dodge"      :-20,
     "parry"      :-45,
     "damage"     : 135,
     "force"      : 140,
     "post_action":(: berserk1 :),
     "damage_type":"瘀傷"
 ]),
// 9
 ([
     "action"     :"$N一拳至剛、一拳至柔，使出瀧山拳奧義「山川流水」﹐剛柔並濟的一擊向$n$l擊去﹐無法閃躲",
     "dodge"      :-20,
     "parry"      :-45,
     "damage"     : 145,
     "force"      : 160,
     "damage_type":"瘀傷"
 ]),
// 10
 ([
     "action"     :"$N拳散靈氣﹐霎時狂風四起﹐無窮真氣自$N身旁湧出﹐使出瀧山拳秘奧義「山河俱滅」﹐$n$l將受可怕之力所毀滅",
     "dodge"      :-50,
     "parry"      :-50,
     "damage"     : 150,
     "force"      : 150,
     "post_action":(: berserk2 :),
     "damage_type":"瘀傷"
 ]),
// 11
 ([  "action"     :             "$N使出赤焰神掌第一式\n"
                         "--" + HIR + "『赤焰破空』" + NOR + "--\n"
             HIW + "$N將浩日真氣，運至手指上，此時手指發出絲絲的熱氣\n"
                "$N感覺到手上的浩日真氣越來越高，十隻手指發出耀眼的光芒\n"
                "$N低吼一聲數十道炙熱真氣如輻射般狂射$n\n" + NOR,
      "dodge"     :   80,
      "parry"     :   50,
      "damage"    :   160,
      "force"     :   150,
      "post_action":  (: fire1 :),
      "damage_type":  "刺傷",
     ]),
// 12
 ([   "action"     :                 "$N使出赤焰神掌第二式\n"
                         "--" + HIR + "『烈焰漫天』" + NOR + "--\n"
             HIW + "$N逆運浩日真氣，將真氣運至手掌，瞬時雙掌通紅\n"
                "$N體中的浩日真氣如沸水般從手上滾滾而出，不吐不快\n"
                "$N將雙掌向前一推，漫天炙熱真氣如熱浪般襲向$n\n" + NOR,
     "dodge"      :  80,
     "parry"      :  50,
     "damage"     :  170,
     "force"      :  190,
     "post_action":(: fire2 :),
     "damage_type":"瘀傷",

      ]),
// 13
  ([ "action"     :               "$N使出赤焰神掌終極奧義\n"
                         "--" + HIR + "『焚天滅地』" + NOR + "--\n"
             HIW + "$N躍至半空中將浩日真氣發散出來，宛如烈日\n"
                "$N狂吼一聲挾帶炙熱真氣如烈日墜地般狂墜而下\n"
                "數不清的掌影及炙熱真氣形成龍捲風包圍了$n\n" + NOR,

     "dodge"      :  80,
     "parry"      :  50,
     "damage"     :  180,
     "force"      :  180,
     "post_action":(: fire3 :),
     "damage_type":"瘀傷",

     ]),
// 14
 ([
     "action"     :"$N頓悟瀧山拳法之---千山萬水、連綿不斷---，將所學的瀧山拳法連綿不絕般的使用出來!!\n",
     "dodge"      :-50,
     "parry"      :-50,
     "damage"     : 50,
     "force"      : 50,
     "post_action":(: berserk :),
     "damage_type":"瘀傷"
 ]),

});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return   notify_fail("學瀧山絕學必須空手。\n");
        return   1;
}

int valid_enable(string usage)
{
        return ( usage=="unarmed" );
}

mapping query_action(object me, object  weapon)
{
 int skill_level, limit ,test,f,k,i;
 object victim ,*enemy;
 enemy = me->query_enemy();
 i=sizeof(enemy);
 victim = enemy[random(i)];
 skill_level = (int)(me->query_skill("lungshan", 1));
 limit= (int)(skill_level/10);
 f = random(10);
 k = random(100);             //以下武器特功的部份.出現率為15%,扣敵人kee 210
if(me->query_temp("weapon"))
{
 weapon=me->query_temp("weapon");  //扣自己force 200
if(me->query("family/family_name")=="瀧山派"&&weapon->query("id")=="carzy dragon")
  {
if((k>85)&&(skill_level>90)&&(me->query_skill_mapped("force")=="haoforce"))
{
message_vision(HIW + "$N手上的" + HIY + "狂龍翔天破" + HIW + "被$N的浩日氣勁所引,幻化出一條巨大火龍!!\n" + NOR,me,victim);
message_vision(HIR+@LONG

                             /           /
                            /' .,,,,  ./
                           /';'     ,/
                          / /   ,,//,`'`
                         ( ,, '_,  ,,,' ``
                         |    /@  ,,, ;  `
                        /    .   ,' /' `,``
                       /   .     ./, `,, ` ;
                    ,./  .   ,-,',` ,,/''\,'
                    |   /; ./,,'`,,'' |   |
                    |     /   ','    /    |
                     \___/'   '     |     |
                       `,,'  |      /     `\
                            /      |        ~\
                           '       (
                           :
                          ; .         \--\----

LONG+NOR,me);
 for(i=0;i<3;i++)
 {
message_vision(HIR + "兇猛的火龍對$n噴出了炙熱火焰,瞬時$n被火焰所包圍,全身痛苦不己。\n" + NOR,me,victim);
victim->add("kee",-70);
victim->apply_condition("burn",random(10));
COMBAT_D->report_status(victim, 1);
  }
message_vision(HIW + "$N手上的" + HIY + "狂龍翔天破" + HIW + "發一道白光,火龍消失在白光之中了。\n" + NOR,me);
me->add("force",-200);
}
}
}
 if(me->query("family/family_name")=="瀧山派"&& me->query("fire_strike",1))
  {
    if( (string)me->query_skill_mapped("force") == "haoforce")
    {
    if (limit = 10)
      {
       if((int)me->query("force") > 1000)
        {
         if (f< 1)
         return action[13];
         return action[random(5)+8];
        }
       if((int)me->query("force") > 750)
        {
         if (f< 1)
         return action[13];
         return action[random(5)+7];
        }
       if((int)me->query("force") > 500)
        {
         if (f< 1)
         return action[13];
         return action[random(5)+6];
        }
      }
    }
  }
    if (limit < 5 )
            return action[random(5)];
    if (limit < 6 )
    {
       return action[random(5)+1];
    }
    if (limit < 7 )
    {
       return action[random(5)+2];
    }
    if (limit < 8 )
    {
       return action[random(5)+3];
    }
    else if (limit < 9)
            {
         if (f< 1)
                return action[13];
                return action[random(5)+4];
            }
    else
    {
         if (f< 1)
       return action[13];
       return action[random(5)+5];
    }
}

void fire1(object me, object victim, object  weapon, int damage)
{
int skill_level;
skill_level = (int)(me->query_skill("haoforce", 1));
if (skill_level > 80)
{
      sp_value =4*(cps+kar)+str+cor+spi+int1;
      message_vision(HIW + "數十道炙熱真氣在$n體內亂竄並狂爆開來\n" + NOR,me,victim);
      victim->add("kee",-sp_value/2);
      me->add("force",-80);
      victim->apply_condition("burn",random(10)+((int)me->query_skill("haoforce", 1)/10));
      COMBAT_D->report_status(victim, 1);
}
}

void fire2(object me, object victim, object  weapon, int damage)
{
    int skill_level;
    skill_level = (int)(me->query_skill("haoforce", 1));
if (skill_level > 90)
{
    int i;
    sp_value =4*(str+cor)+cps+2*kar+spi+int1;
message_vision(HIW + "$N的炙熱真氣在$n旁形成真空旋渦，使$n無法動彈\n" + NOR,me,victim);    
      victim->add("kee",-sp_value/2);
      victim->start_busy(1);
      me->add("force",-100);
      victim->apply_condition("burn",random(15)+((int)me->query_skill("haoforce", 1)/10));
      COMBAT_D->report_status(victim, 1);
}
}

void fire3(object me, object victim, object  weapon, int damage)
 {
     int skill_level;
skill_level = (int)(me->query_skill("haoforce", 1));
if (skill_level > 100)
{
     sp_value =4*(cor+int1)+3*str+spi+cps+kar;
message_vision(HIW + "$n被$N的炙熱龍捲真氣，捲至半空中並被撕裂開來\n" + NOR,me,victim);     
        victim->add("kee",-sp_value/2);
        me->add("force",-170);
     victim->apply_condition("burn",random(10)+((int)me->query_skill("haoforce", 1)/10));
     COMBAT_D->report_status(victim, 1);
}
}

void berserk(object me, object victim, object  weapon, int damage)
{ //連續技的部份,分成二個.kee >1500(指mob),kee<1600指player
int bovalue,sklv,ko,bound=10,i,vdodge;//扣的kee約二倍(mob及player比的話)
vdodge=victim->query_skill("dodge",1);
if(vdodge>140)
 vdodge=140;
 sklv=(int)me->query_skill("lungshan",1)/10;
// 修正判定 不然可能會有100% 只要haoforce高就可能 By Swy
 ko=(int)me->query_skill("lungshan",1);
 ko=ko+((int)me->query_skill("unarmed",1)+(int)me->query_skill("fire-kee",1))/2;
//出現率四成,成功率約50% 十下全中扣kee 500,mob的話約1000全中的話
 for(i=0;i<sklv;i++)
 {
  switch(i) {
case 0:
 message_vision("$N使出瀧山絕學的起手式,「飛瀑入山」﹐對準$n的要害打出難以捉摸的一拳\n",me,victim);
break;
case 1:
 message_vision("$N低吼一聲!!真氣從雙掌中釋出，使出一招「江河日下」﹐對準$n穴位急拍而出\n ",me,victim);
break;
case 2:
 message_vision("$N雙手急轉使出瀧山絕學之「追瀑溯源」快速地往$n致命部位擊出\n ",me,victim);
break;
case 3:
 message_vision("$N大喝一聲﹐雙拳一提﹐一招「五嶽頂天」往$n的五個要害擊出\n ",me,victim);
break;
case 4:
 message_vision("$N步履一沉﹐凝神聚氣﹐雙拳連下使出「千川百嶽」擊向$n全身要害\n",me,victim);
break;
case 5:
 message_vision("$N縱身一躍﹐使出瀧山拳奧義「山泉群湧」﹐拳如連珠般一連數十拳擊向$n的要害\n ",me,victim);
break;
case 6:
 message_vision("$N雙拳交錯﹐運足真氣﹐使出瀧山拳奧義「山窮水盡」﹐萬鈞之力擊向$n使$n難以招架\n",me,victim);
break;
case 7:
 message_vision("$N雙手如「流水」般柔亦柔、剛亦剛，使出瀧山拳中奧義「川流不息」﹐雙掌似有似無般向$n擊出 ",me,victim);
break;
case 8:
 message_vision("$N一拳至剛、一拳至柔，使出瀧山拳奧義「山川流水」﹐剛柔並濟的一擊向$n擊去﹐無法閃躲 ",me,victim);
break;
case 9:
 message_vision("$N拳散靈氣﹐霎時狂風四起﹐無窮真氣自$N身旁湧出﹐使出瀧山拳秘奧義「山河俱滅」﹐$n將受可怕之力所毀滅 ",me,victim);
break;}
// 命中約 50% By Swy 
if(random(ko)>vdodge-30){
message_vision(HIY + "$n被$N凌厲異常的瀧山拳法擊中,$n身上被烙下深厚的掌印。\n" + NOR,me,victim);
bovalue=(int)victim->query("kee");
//mob扣二次,player扣一次
if(bovalue>1600) victim->add("kee",-bound);
        victim->add("kee",-bound);
        COMBAT_D->report_status(victim, 1);
        bound=bound+10;
  }
else{
message_vision(HIW + "$n在千均一刻之際看出$N瀧山拳法的破綻,有驚無險地躲了開來。\n" + NOR, me, victim);
        bound=bound+10;
  }
 }
message_vision(HIR + "$N使出連綿不絕後,全身內力枯\竭,使$N不得不趕緊運氣調息。\n" + NOR,me);
    me->start_busy(1);
    me->add("force",-bound);
    COMBAT_D->report_status(victim, 1);
}

void berserk1(object me, object victim, object  weapon, int damage)
{
int skill_level;
skill_level = (int)(me->query_skill("lungshan", 1));
// 命中約 50%
if(((skill_level+random(150)) > 160) && (me->query("super_fire",1)))
{
message_vision(HIC + "$n被瀧山拳法中所蘊涵的山川流水之氣息所侵，使$n迷失在山水之中\n" + NOR,me,victim);
      victim->start_busy(1);
      me->add("force",-40);
      COMBAT_D->report_status(victim, 1);
}
}

void berserk2(object me, object victim, object  weapon, int damage)
{
int skill_level1,skill_level2;
skill_level1 = (int)(me->query_skill("lungshan", 1));
// haoforce 能練 so 設限 By Swy
skill_level2 = (int)(me->query_skill("haoforce", 1));
if(skill_level2 > 100) skill_level2=100;
// 命中 50% By Swy
if(((skill_level1+skill_level2+random(200)) > 285) &&
  ((string)me->query_skill_mapped("force") == "haoforce") &&
  (me->query("super_fire",1))&&(me->query("force")>200))
{
message_vision
( HIR + "$N臉色一變,全身散出炙熱無比的真氣,雙手如旋渦般使出瀧山絕學之禁斷技!!!\n\n" + HIY
     "      ☆★『" + HIW + "火～海～焚～天  " + HIB + "波～濤～洶～湧" + HIY + "』★☆\n" + HIR
"源源不斷的炙熱氣勁如大海浪般,一層又一層的向$n狂捲而去,$n被包圍在熱浪之中
$n只覺巨大的炙熱氣勁入侵全身經脈無法凝氣,感覺內力不斷地在流失之中\n" + NOR
      ,me,victim);
      victim->add("kee",-200);
      victim->add("force",-300);
victim->apply_condition("burn",random(10) +((int)me->query_skill("haoforce",1)/10));
     // delay 的 condition 5 回 By Swy
 victim->apply_condition("hart",random(10)+1);
      me->add("force",-200);
      COMBAT_D->report_status(victim, 1);
}
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("你的體力不夠了﹐休息一下再練吧。\n");
        if( (int)me->query("force") < 3 )
                return notify_fail("你的內力不夠了﹐休息一下再練吧。\n");
        if( (int)me->query_skill("literate") <= ( (int)(me->query_skill("lungshan", 1)*0.75) ) )
                return notify_fail("你的武學知識不足﹐似乎無法參透絕學中山水之義。");
        me->receive_damage("kee", 40);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("fighter")+"/lungshan/"+action;
}
