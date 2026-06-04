// 對其fs的進步幫其 lungshan 做其合技 by swy
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void berserk(object me,object victim,object weapon,int damage);
void berserk1(object me,object victim,object weapon,int damage);
void berserk2(object me,object victim,object weapon,int damage);
void fire1(object me, object victim, object  weapon, int damage);
void fire2(object me, object victim, object  weapon, int damage);
void fire3(object me, object victim, object  weapon, int damage);
int kar,cps,str,cor,int1,spi;
int sp_value;
// 武者 damage and force 上限為 500
mapping *action = ({
// 1
([
     "action"     :"$N使出瀧山絕學的起手式﹐一招[1m「飛瀑入山」[0m﹐對準$n的$l打出難以捉摸的一拳",
     "dodge"      :-25,
     "parry"      :-20,
     "damage"     : 50,
     "force"      : 50,
     "damage_type":"瘀傷"
 ]),
// 2
 ([
     "action"     :"$N低吼一聲!!真氣從雙掌中釋出，使出一招[1m「江河日下」[0m﹐對準$n的$l急拍而出",
     "dodge"      :-25,
     "parry"      :-20,
     "damage"     : 100,
     "force"      : 100,
     "damage_type":"瘀傷"
 ]),
// 3
 ([
     "action"     :"$N猶如流水般隨$n的攻勢﹐使出一招[1m「追瀑溯源」[0m便往$n的$l反擊過去",
     "dodge"      :-50,
     "parry"      :-10,
     "damage"     : 150,
     "force"      : 150,
     "damage_type":"瘀傷"
 ]),
// 4
 ([
     "action"     :"$N大喝一聲﹐雙拳一提﹐一招[1m「五嶽頂天」[0m往$n的五個要害擊出",
     "dodge"      :-10,
     "parry"      :-25,
     "damage"     : 200,
     "force"      : 200,
     "damage_type":"瘀傷"
 ]),
// 5
 ([
     "action"     :"$N步履一沉﹐凝神聚氣﹐雙拳連下使出[1m「千川百嶽」[0m擊向$n$l",
     "dodge"      :-30,
     "parry"      :-5,
     "damage"     : 250,
     "force"      : 250,
     "damage_type":"瘀傷"
 ]),
// 6
 ([
     "action"     :"$N縱身一躍﹐使出瀧山拳奧義[36m「山泉群湧」[0m﹐拳如連珠般一連數十拳擊向$n$l",
     "dodge"      :-30,
     "parry"      :-30,
     "damage"     : 300,
     "force"      : 300,
     "damage_type":"瘀傷"
 ]),
// 7
 ([
     "action"     :"$N雙拳交錯﹐運足真氣﹐使出瀧山拳奧義[1;36m「山窮水盡」[0m﹐萬鈞之力擊向$n$l﹐難以招架",
     "dodge"      :-20,
     "parry"      :-45,
     "damage"     : 350,
     "force"      : 350,
     "damage_type":"瘀傷"
 ]),
// 8
 ([
     "action"     :"$N雙手如「流水」般柔亦柔、剛亦剛，使出瀧山拳中奧義[1;32m「川流不息」[0m﹐似有似無般向$n$l擊出",
     "dodge"      :-20,
     "parry"      :-45,
     "damage"     : 400,
     "force"      : 400,
     "post_action":(: berserk1 :),
     "damage_type":"瘀傷"
 ]),
// 9
 ([
     "action"     :"$N一拳至剛、一拳至柔，使出瀧山拳奧義[1;36m「山川流水」[0m﹐剛柔並濟的一擊向$n$l擊去﹐無法閃躲",
     "dodge"      :-20,
     "parry"      :-45,
     "damage"     : 400,
     "force"      : 400,
     "damage_type":"瘀傷"
 ]),
// 10
 ([
     "action"     :"$N拳散靈氣﹐霎時狂風四起﹐無窮真氣自$N身旁湧出﹐使出瀧山拳秘奧義[1;32m「山河俱滅」[0m﹐$n$l將受可怕之力所毀滅",
     "dodge"      :-50,
     "parry"      :-50,
     "damage"     : 400,
     "force"      : 400,
     "post_action":(: berserk2 :),
     "damage_type":"瘀傷"
 ]),
// 11
 ([  "action"     :             "$N使出赤焰神掌第一式\n"
                         "--" + HIR + "『赤焰破空』" + NOR + "--\n" + HIW + "$N將浩日真氣，運至手指上，此時手指發出絲絲的熱氣\n"
                "$N感覺到手上的浩日真氣越來越高，十隻手指發出耀眼的光芒\n"
                "$N低吼一聲數十道炙熱真氣如輻射般狂射$n\n" + NOR,
      "dodge"     :   80,
      "parry"     :   50,
      "damage"    :   500,
      "force"     :   500,
      "post_action":  (: fire1 :),
      "damage_type":  "刺傷",
     ]),
// 12
 ([   "action"     :                 "$N使出赤焰神掌第二式\n"
                         "--" + HIR + "『烈焰漫天』" + NOR + "--\n" + HIW + "$N逆運浩日真氣，將真氣運至手掌，瞬時雙掌通紅\n"
                "$N體中的浩日真氣如沸水般從手上滾滾而出，不吐不快\n"
                "$N將雙掌向前一推，漫天炙熱真氣如熱浪般襲向$n\n" + NOR,
     "dodge"      :  80,
     "parry"      :  50,
     "damage"     :  500,
     "force"      :  500,
     "post_action":(: fire2 :),
     "damage_type":"瘀傷",

      ]),
// 13
  ([ "action"     :               "$N使出赤焰神掌終極奧義\n"
                         "--" + HIR + "『焚天滅地』" + NOR + "--\n" + HIW + "$N躍至半空中將浩日真氣發散出來，宛如烈日\n"
                "$N狂吼一聲挾帶炙熱真氣如烈日墜地般狂墜而下\n"
                "數不清的掌影及炙熱真氣形成龍捲風包圍了$n\n" + NOR,

     "dodge"      :  80,
     "parry"      :  50,
     "damage"     :  500,
     "force"      :  500,
     "post_action":(: fire3 :),
     "damage_type":"瘀傷",

     ]),
// 14
 ([
     "action"     :"$N頓悟瀧山拳法之---[1;5;36m千山萬水、連綿不斷[0m---，將所學的瀧山拳法連綿不絕般的使用出來!!\n",
     "dodge"      :-50,
     "parry"      :-50,
     "damage"     : 200,
     "force"      : 200,
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
 int skill_level, limit ,f,k,i,j,l,m,a;
 object victim ,*enemy,room,*all;
  kar=me->query_kar();
 cps=me->query_cps();
 str=me->query_str();
 cor=me->query_cor();
 int1=me->query_int();
 spi=me->query_spi();

 enemy = me->query_enemy();
 i=sizeof(enemy);
victim=offensive_target(me);
if(!victim) return action[random(5)];
 room = environment(me);
 all = all_inventory(room);
 m=sizeof(all);
 skill_level = (int)(me->query_skill("lungshan-mob", 1));
 limit= (int)(skill_level/10);
 f = random(10);
 k = random(100);
if(me->query("combat_exp")>1500000) {
if(!me->is_busy() && 20>random(100) && me->query("family/family_name")=="瀧山派") {
for(a=0;a<i;a++) {
if(!enemy[a]) continue;
if(enemy[a]->query("family/family_name")!="雪蒼派") continue;
enemy[a]->set_temp("is_enemy",1);
}
for(j=0;j<m;j++) {
if(!all[j]->is_fighting()) continue;
if(!all[j]->query("is_mob")) continue;
if(all[j]->query_temp("is_enemy")) continue;
if(all[j]->query_temp("use-two-power")) continue;
if(all[j]->query("family/family_name")!="雪蒼派") continue;
for(l=0;l<10;l++) {
message_vision(HIW + "只見"+me->query("name")+"與"+all[j]->query("name")+"連手，把瀧山派與雪蒼派的絕學融合一致，使出『" + HIC + "寒冰" + HIR + "烈火" + HIB + "掌" + HIW + "』向$N狂攻而去。\n" + NOR,victim);
victim->receive_damage("kee",300);
COMBAT_D->report_status(victim);
}
m=0;
all[j]->set_temp("use-two-power",1);
me->start_busy(1);
all[j]->start_busy(1);
victim->start_busy(1);
}}}
if(me->query_temp("weapon"))
{
 weapon=me->query_temp("weapon");  //扣自己force 200
if(me->query("family/family_name")=="瀧山派"&&weapon->query("id")=="crazy dragon")
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
victim->receive_damage("kee",100);
victim->apply_condition("burn",random(10)+1);
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
       if((int)me->query("force") > 3000)
        {
if(f<2)
         return action[12];
return action[random(10)+4];
        }
       if((int)me->query("force") > 2000)
        {
if(f<2)
         return action[11];
return action[random(10)+4];
        }
       if((int)me->query("force") > 1000)
        {
if(f<2)
         return action[10];
return action[random(10)+4];
        }
      }
    }
  }
    if (limit < 5 )
            return action[random(5)];
    if (limit < 6 )
    {
       return action[random(6)];
    }
    if (limit < 7 )
    {
       return action[random(6)+1];
    }
    if (limit < 8 )
    {
       return action[random(6)+2];
    }
    else if (limit < 9)
            {
if(f<2)
                return action[13];
                return action[random(6)+3];
            }
    else
    {
if(f<2)
       return action[13];
       return action[random(6)+4];
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
      victim->receive_damage("kee",(100+2*sp_value));
      me->add("force",-100);
      victim->apply_condition("burn",random(10)+1);
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
    message_vision(HIW + "$N的炙熱真氣在$n旁形成真空旋渦，使$n身心受創\n" + NOR,me,victim);
      victim->receive_damage("kee",(150+2*sp_value));
      me->add("force",-150);
      victim->apply_condition("burn",random(15)+1);
      COMBAT_D->report_status(victim, 1);
}
}

void fire3(object me, object victim, object  weapon, int damage)
 {
     int skill_level;
skill_level = (int)(me->query_skill("haoforce", 1));
if (skill_level >= 100)
{
     sp_value =4*(cor+int1)+3*str+spi+cps+kar;
     message_vision(HIW + "$n被$N的炙熱龍捲真氣，捲至半空中並被撕裂開來\n" + NOR,me,victim);
      victim->receive_damage("kee",(200+2*sp_value));
      me->add("force",-200);
     victim->apply_condition("burn",random(20)+1);
     COMBAT_D->report_status(victim, 1);
}
}

void berserk(object me, object victim, object  weapon, int damage)
{
int bovalue,sklv,ko,bound=50,i;
sklv=(int)me->query_skill("lungshan-mob",1)/10;
if((me->query("id")=="cgy"||me->query("id")=="master jen")||(60>random(100)&&me->query("env/瀧山連擊")&&me->query("family/family_name")=="瀧山派")) {
 for(i=0;i<sklv;i++)
 {
  switch(i) {
case 0:
 message_vision("$N使出瀧山拳法第一招" + HIC + "「飛瀑入山」" + NOR + "，真氣狂吐擊向$n。\n",me,victim);
break;
case 1:
 message_vision("$N使出瀧山拳法第二招" + HIC + "「江河日下」" + NOR + "，真氣狂吐擊向$n。\n ",me,victim);
break;
case 2:
 message_vision("$N使出瀧山拳法第三招" + HIC + "「追瀑溯源」" + NOR + "，真氣狂吐擊向$n。\n ",me,victim);
break;
case 3:
 message_vision("$N使出瀧山拳法第四招" + HIC + "「五嶽頂天」" + NOR + "，真氣狂吐擊向$n。\n ",me,victim);
break;
case 4:
 message_vision("$N使出瀧山拳法第五招" + HIC + "「千川百嶽」" + NOR + "，真氣狂吐擊向$n。\n",me,victim);
break;
case 5:
 message_vision("$N使出瀧山拳法第六招" + HIC + "「山泉群湧」" + NOR + "，真氣狂吐擊向$n。\n ",me,victim);
break;
case 6:
 message_vision("$N使出瀧山拳法第七招" + HIC + "「山窮水盡」" + NOR + "，真氣狂吐擊向$n。\n",me,victim);
break;
case 7:
 message_vision("$N使出瀧山拳法第八招" + HIC + "「川流不息」" + NOR + "，真氣狂吐擊向$n。\n",me,victim);
break;
case 8:
 message_vision("$N使出瀧山拳法第九招" + HIC + "「山川流水」" + NOR + "，真氣狂吐擊向$n。\n",me,victim);
break;
case 9:
 message_vision("$N使出瀧山拳法第十招" + HIC + "「山河俱滅」" + NOR + "，真氣狂吐擊向$n。\n",me,victim);
break;
}
// 修正全命中 By Swy
message_vision(HIY + "$N凌厲異常的瀧山拳法，在$n身上烙下深厚的掌印。\n" + NOR,me,victim);
        victim->receive_damage("kee",bound);
        COMBAT_D->report_status(victim, 1);
        bound=bound+10;
 }
// 取消自身 busy by swy
/*
message_vision(HIR + "$N使出連綿不絕後，全身內力枯\竭，不得不趕緊運氣調息。\n" + NOR,me);
if(me->query("del_delay") != 1) {
    me->start_busy(1);
}
*/
    me->add("force",-bound);
    COMBAT_D->report_status(victim, 1);
}
}

void berserk1(object me, object victim, object  weapon, int damage)
{
// 提高命中率 by swy
if(60>random(100) && me->query("super_fire",1))
{
message_vision(HIC + "$n被瀧山拳法中所蘊涵的山川流水之氣息所侵，使$n吐了一口鮮血。\n" + NOR,me,victim);
      victim->receive_damage("kee",350);
      me->add("force",-50);
      COMBAT_D->report_status(victim, 1);
}
}

void berserk2(object me, object victim, object  weapon, int damage)
{
// 提高命中率 by swy
if(60>random(100) &&
  ((string)me->query_skill_mapped("force") == "haoforce") &&
  (me->query("super_fire",1))&&(me->query("force")>200))
{
message_vision
( HIR + "$N臉色一變,全身散出炙熱無比的真氣,雙手如旋渦般使出瀧山絕學之禁斷技!!!\n\n" + HIY + "      ☆★『" + HIW + "火～海～焚～天  " + HIB + "波～濤～洶～湧" + HIY + "』★☆\n" + HIR + "源源不斷的炙熱氣勁如大海浪般,一層又一層的向$n狂捲而去,$n被包圍在熱浪之中
$n只覺巨大的炙熱氣勁入侵全身經脈無法凝氣,感覺內力不斷地在流失之中\n" + NOR
      ,me,victim);
      victim->receive_damage("kee",500);
      victim->add("force",-200);
victim->apply_condition("burn",random(15)+1);
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
        if( (int)me->query_skill("literate") <= ( (int)(me->query_skill("lungshan-mob", 1)*0.75) ) )
                return notify_fail("你的武學知識不足﹐似乎無法參透絕學中山水之義。");
        me->receive_damage("kee", 40);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("fighter")+"/lungshan/"+action;
}
