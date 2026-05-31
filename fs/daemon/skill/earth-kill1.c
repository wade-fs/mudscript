#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void earthkill(object me,object victim,object weapon,int damage);
void killall(object me,object victim,object weapon,int damage);
void heartkill(object me,object victim,object weapon,int damage);
void threekill(object me,object victim,object weapon,int damage);
void skykill(object me,object victim,object weapon,int damage);
void bloodkill(object me,object victim,object weapon,int damage);
void burn(object me,object victim,object weapon,int damage);
void cold(object me,object victim,object weapon,int damage);

mapping *action = ({
(["action":"$N不是忍者所以無法使用。",
"dodge":0,
"parry":0,
"damage":0,
"damage_type":  "刺傷"
]),
(["action":HIW"$N東瀛伊賀流地斬十式第一式短刃技『"HIR"空  蟬"HIW"』, 身型一晃, 手中兵器已經襲向$n弱點。"NOR,
"dodge":                 -40,
"parry":                 -40,
"damage":                100,
"damage_type":  "刺傷"
]),
(["action":HIW"$N東瀛伊賀流地斬十式第二式短刃技『"HIR"山  嵐"HIW"』, 穩健的攻擊逼得$n手忙腳亂。"NOR,
"dodge":                -40,
"parry":                -40,
"damage":               110,
"damage_type":  "割傷"
]),
(["action":HIW"$N東瀛伊賀流地斬十式第三式短刃技『"HIR"冰  舞"HIW"』, 只見$N迅速的繞到$n身後準備給予致命的一擊。"NOR,
"dodge":                -50,
"parry":                -50,
"damage":               120,
"post_action":               (: cold :),
"damage_type":  "凍傷"
]),
(["action":HIW"$N東瀛伊賀流地斬十式第四式短刃技『"HIR"炎  襲"HIW"』, 手中兵器如火焰般撲向$n。"NOR,
"dodge":                -50,
"parry":                -50,
"damage":               130,
"post_action":               (: burn :),
"damage_type":  "燒傷"
]),
(["action":HIW"$N東瀛伊賀流地斬十式第五式短刃技『"HIR"血  殺"HIW"』, $n濺出的鮮血隨風四處飄散。"NOR,
"dodge":                -60,
"parry":                -60,
"damage":               145,
"post_action":               (: bloodkill :),
"damage_type":  "刺傷"
]),
(["action":HIW"$N左右晃動, 步法散中有序, 身影忽然消失在空氣之間, 使出忍者至高武術之『"HIR"滅  天  閃"HIW"』。"NOR,
"dodge":                -60,
"parry":                -60,
"damage":               150,
"post_action":               (: skykill :),
"damage_type":  "刺傷"
]),
(["action":HIW"$N使出東瀛伊賀流地斬十式第七式短刃技『"HIR"三  方  斬"HIW"』, 刀光四起, 四處鮮血飛濺。"NOR,
"dodge":                -60,
"parry":                -60,
"damage":               200,
"post_action":               (: threekill :),
"damage_type":  "刺傷"
]),
(["action":HIW"$N激發全身殺氣, 一招『"HIR"破  心  擊"HIW"』以凌人的霸氣震攝$n。"NOR,
"dodge":                -70,
"parry":                -70,
"damage":               200,
"post_action":               (: heartkill :),
"damage_type":   "刺傷"
]),
(["action":HIW"$N使出地斬奧義『"HIR"撼  地  訣"HIW"』, 在極短的時間內朝著$n週身破綻進行猛攻。"NOR,
"dodge":               -70,
"parry":               -70,
"damage":              200,
"post_action":               (: earthkill :),
"damage_type":               "刺傷"
]),        
(["action":HIW"$N如鬼魅般的迅速移動身型, 只見刀光一閃, 一招『"HIR"瞬  殺  四  方"HIW"』朝著四周猛劈。"NOR,
"parry":             -70,
"dodge":             -70,
"damage":            250,
"post_action":               (: killall :),
"damage_type":   "刺傷"
]),
});
int valid_enable(string usage)
{
return usage=="dagger" || usage=="parry";
}

mapping query_action(object me, object weapon, object victim, object *enemy,object room)
{
int skill_level, limit, i, j=0,kill_hurt;
skill_level=(int)me->query_skill("earth-kill", 1);
limit=(int)(skill_level/10);
enemy=me->query_enemy();
i=sizeof(enemy);
victim=enemy[random(i)];
kill_hurt=(me->query("PKS"))*5;
if (kill_hurt > 1500) kill_hurt=1500;
if (me->query_skill("earth-kill") > 35 && random(me->query("functions/manakee/level")) > 130
    && me->query_temp("earthkill")!=1)
{message_vision(HIG"
                       ～ ～  "HIR"秘 奧 義  "HIG"～ ～
                  "YEL"『"HIB" 狂 亂 烈 風 之 空 蟬 地 斬 "YEL"』

               "HIM"真 ˙ 伊 賀 流 秘 義"HIW" －－"HIY"『 "HIC"空    蟬 "HIY"』
                        
               "GRN"裏 ˙ 伊 賀 流 奧 義"HIW" －－"HIY"『"YEL" 地    斬 "HIY"』

"HIW"$N雙奧義同時施展, 招式如狂風暴雨般的猛襲$n。\n"NOR,me,victim);
victim->receive_wound("kee",me->query_skill("force"));
victim->start_busy(1);
COMBAT_D->report_status(victim);
}
if (skill_level > 90 && random(100)>1 && me->query("bellicosity") > me->query("force")
    && me->query("bellicosity") > 8000 && me->query_temp("earthkill")!=1
    && me->query("quest/be_pker")==1 && me->query("force") > 1000)
{
me->do_command("hehe");
me->do_command("say 嘿嘿....就讓你見識一下真正的殺人劍招!!");
message_vision(HIW"\n\t殺  人  劍 ～～～ "HIY"『 斬  人 』 "HIW"!!\n"NOR,me);
victim->receive_wound("kee",kill_hurt/4);
COMBAT_D->report_status(victim);
me->add("force",-100);
me->add("bellicosity",-50);
if (me->query("bellicosity") > 13000)
{message_vision(HIW"\n\t殺  人  劍 ～～～ "HIC"『 斬  魂 』 "HIW"!!\n"NOR,me);
victim->receive_wound("kee",kill_hurt/3);
me->add("force",-200);
me->add("bellicosity",-100);
COMBAT_D->report_status(victim);}
if (me->query("bellicosity") > 18000)
{message_vision(HIW"\n\t殺  人  劍 ～～～ "HIG"『 斬  鬼 』 "HIW"!!\n"NOR,me);
victim->receive_wound("kee",kill_hurt/2);
me->add("force",-300);
me->add("bellicosity",-150);
COMBAT_D->report_status(victim);}
if (me->query("bellicosity") > 23000)
{message_vision(HIW"\n\t殺  人  劍 ～～～ "HIR"『 斬  神 』 "HIW"!!\n"NOR,me);
victim->receive_wound("kee",kill_hurt);
me->add("force",-400);
me->add("bellicosity",-200);
COMBAT_D->report_status(victim);
COMBAT_D->report_status(victim);}
message_vision(HIB"\n招式過後, 天空灑下了一片腥紅血雨 !!\n"NOR,me);
me->do_command("haha");
}
if (random(15000)< (me->query_cor()+me->query_cps())+me->query("quest/add_bak")+me->query_temp("add_bak"))
{
message_vision(HIY"\n$N趁著$n短暫的疏忽, 給了$n致命的背刺!!\n\n"NOR,me,victim);
if (victim->query("max_kee")/2 > 100000)
{
room=environment(me);
tell_object(users(),HIW"一陣強烈能量從"+room->query("short")+"傳出!!!!\n"NOR);
}
victim->receive_wound("kee",victim->query("max_kee")/2);
COMBAT_D->report_status(victim);
}
if (me->query("class") != "killer")
return action[0];
if (limit < 2 )
return action[random(2)+1];
if (limit == 2 )
return action[random(3)+1];
if (limit == 3 )
return action[random(4)+1];
if (limit == 4 )
return action[random(5)+1];
if (limit == 5 )
return action[random(6)+1];
if (limit == 6 )
return action[random(7)+1];
if (limit == 7 )
return action[random(8)+1];
if (limit == 8 )
return action[random(7)+2];
if (limit == 9 )
return action[random(7)+3];
if (limit == 10)
return action[random(6)+5];
}
void earthkill(object me, object victim, object  weapon, int damage)
{
int i,cor,j=0;
cor=me->query_cor();
i=me->query_skill("dagger")/16+3;
if (random(me->query("functions/manakee/level")) > 55-cor && me->query_temp("earthkill")!=1 
    && me->query("bellicosity") > 3000)
{
me->set_temp("earthkill",1);
for(j = 0;j < i; j++)
{
COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
COMBAT_D->report_status(victim);
}
me->delete_temp("earthkill");
if (random(100) < 50-cor) 
{
me->start_busy(1);
message_vision(HIR"$N殺意消失, 無心繼續發動攻擊!!\n"NOR,me);
}
}
}
void killall(object me, object victim, object  weapon, int damage)
{
int i,hurt,j=0;
object *enemy;
enemy=me->query_enemy();
i=sizeof(enemy);
hurt=me->query("PKS");
if (hurt > 1000) hurt=1000;
if (random(me->query("functions/manakee/level")) > 40 && me->query_temp("earthkill")!=1)
{
message_vision(HIW"只見$N在刀光中狂舞, 鮮血四處飛濺著!!\n"NOR,me);
for (j=0 ; j < i ; j++)
{
if (random(100) > 25)
{
message_vision(HIR"$N閃躲不及, 被刀光劈中, 鮮血狂噴!!\n"NOR,enemy[j]);
enemy[j]->receive_wound("kee",hurt);
COMBAT_D->report_status(enemy[j]);
}
else
{
message_vision(YEL"$N側身一避, 躲開了這致命的一擊!!\n"NOR,enemy[j]);
}}}}

void heartkill(object me, object victim, object  weapon, int damage)
{
int hurt;
me=this_player();
hurt=me->query("bellicosity")/25;
if (hurt > 500) hurt = 500;
if (random(me->query("functions/manakee/level")) > 80 && me->query_temp("earthkill")!=1 && me->query("force") > 500
    && me->query("bellicosity") > 500 )
{
message_vision(HIC"$N被$n散發出的強大氣息震攝住, 全身無法動彈!!\n"NOR,victim,me);
victim->add("kee",-hurt);
victim->start_busy(1);
me->add("force",-100);
me->add("bellicosity",-40);
}
}

void skykill(object me, object victim,object weapon,object *enemy)
{
int hurt;
me=this_player();
enemy=me->query_enemy();
hurt=me->query("bellicosity")/20;
if (hurt > 800) hurt = 800;
if (random(me->query("functions/manakee/level")) > 40 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600)
{
message_vision(YEL"『"HIB"臨˙兵˙鬥˙者˙皆˙陣˙列˙在˙前"YEL"』"HIW"～～$N口中默唸忍術九字真言!!\n"NOR,me);
message_vision(HIY"$N的兵器忽然灑出無數刀氣朝向$n直攻而去, 只見$n閃避不及, 被$N的刀氣擊中。!!\n"NOR,me,victim);
victim->receive_wound("kee",hurt);
me->add("force",-100);
me->add("bellicosity",-30);
COMBAT_D->report_status(victim);
}}
void threekill(object me, object victim, object  weapon,object *enemy)
{
int i,hurt,k,j=0;
me=this_player();
enemy=me->query_enemy();
i=sizeof(enemy);
hurt=me->query("bellicosity")/25;
if (hurt > 250) hurt = 250;
if (random(me->query("functions/manakee/level")) > 50 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600)
{
for (j=0 ; j < 3; j++)
{
message_vision(HIG"$N無聲無息的繞到$n身候, 冷不防的在$n背後刺了一刀!!\n"NOR,me,victim);
victim->receive_wound("kee",hurt);
me->add("force",-200);
me->add("bellicosity",-50);
COMBAT_D->report_status(victim);
}
}}
void bloodkill(object me, object victim, object  weapon,object *enemy)
{
int str,cor,intt,spi,cps,per,con,kar,hurt;
me=this_player();
str=me->query_str();
cps=me->query_cps();
per=me->query_per();
con=me->query_con();
kar=me->query_kar();
intt=me->query_int();
cor=me->query_cor();
spi=me->query_spi();
hurt=(str+cor+intt+spi+cps+per+con+kar)*3;
if (random(me->query("functions/manakee/level")) > 40 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600)
{
message_vision(HIR"$N吸取風中飄散的鮮血, 將血氣納為己用!!\n"NOR,me);
victim->receive_wound("kee",hurt);
me->receive_curing("kee",hurt);
me->receive_heal("kee",hurt);
me->add("force",-100);
me->add("bellicosity",-50);
COMBAT_D->report_status(victim);
}}
void burn(object me, object victim, object  weapon,object *enemy)
{
int hurt;
me=this_player();
hurt=me->query("functions/manakee/level")*3;
if (random(me->query("functions/manakee/level")) > 50 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600)
{
message_vision(HIR"由$N殺意激發出來的炎勁不斷侵襲$n!!\n"NOR,me,victim);
victim->receive_wound("kee",hurt);
victim->apply_condition("burn",10);
me->add("force",-80);
me->add("bellicosity",-25);
COMBAT_D->report_status(victim);
}}
void cold(object me, object victim, object  weapon,object *enemy)
{
int hurt;
me=this_player();
hurt=me->query("functions/manakee/level")*3;
if (random(me->query("functions/manakee/level")) > 50 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600)
{
message_vision(HIC"由$N殺意激發出來的寒勁不斷侵襲$n!!\n"NOR,me,victim);
victim->receive_wound("kee",hurt);
victim->apply_condition("cold",10);
me->add("force",-80);
me->add("bellicosity",-25);
COMBAT_D->report_status(victim);
}}
string perform_action_file(string action)
{
return CLASS_D("killer")+"/earth-kill/"+action;
}
int valid_learn(object me)
{
tell_object(me,"地斬無法從學習中獲得進展, 必須自己修行方有成果!!\n");
return 0;
}
