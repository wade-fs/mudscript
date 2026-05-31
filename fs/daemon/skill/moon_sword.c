// 月影幻式劍法
//連陽副劍
//由連陽劍修改而來
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void sp_attack0(object me, object victim, object  weapon, int damage);
void sp_attack1(object me, object victim, object  weapon, int damage);
void sp_attack2(object me, object victim, object  weapon, int damage);
void sp_attack3(object me, object victim, object  weapon, int damage);
void sp_attack4(object me, object victim, object  weapon, int damage);
void sp_attack5(object me, object victim, object  weapon, int damage);
void sp_attack6(object me, object victim, object  weapon, int damage);
int kar,cps,str,cor,int1,spi;
int sp_value;
mapping *action = ({
//1
        ([
                "action"     :               BLK"$N收光為暈斂剛成柔，手中的長劍消失於黑暗中，四周劍芒頓時消失，不由自主使出月影幻式『陰月』，瞬間$n完全無法見光，只覺疾風扶向$n$l"NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                330,
                "force"      :                330,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "刺傷"
        ]),
//2
        ([
                "action"     :               BLK"一片昏暗中突見一陣光亮，只見$N身若游光使出月影幻式『新月』，劍氣四竄，一流宏大的劍壓曲地逼近$n"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                340,
                "force"      :                340,
                "post_action":                (: sp_attack1 :),
                "damage_type":               "刺傷"
        ]),
//3
        ([
                "action"     :               BLK"$N飛身高躍倏然使出了月影幻式『滿月』，劍光如圓月照亮黑暗，直指$n眉心"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                350,
                "force"      :                350,
                "post_action":                (: sp_attack2 :),
                "damage_type":               "刺傷"
        ]),
//4
        ([
                "action"     :               BLK"$N撫劍如靜，心靜劍寧，月影幻式『月缺』泛起波波殺意如刃向$n繞流而去"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                370,
                "force"      :                370,
                "post_action":                (: sp_attack3 :),
                "damage_type":               "割傷"
               ]),
//5
        ([
                "action"     :               BLK"如月之上弦$N手裡的長劍畫出一道半圓，月影幻式『上弦』劍影破空而下落$n身上"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                380,
                "force"      :                380,
                "post_action":                (: sp_attack4 :),
                "damage_type":               "割傷"
        ]),
//6
        ([
                "action"     :               BLK"如月之下弦$N將手中長劍峰迴路轉由下而上畫出半圓劍影，月影幻式『下弦』，劍影猶如萬馬奔騰由下而上直奔$n心口"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                390,
                "force"      :                390,
                "post_action":                (: sp_attack5 :),
                "damage_type":               "刺傷"
        ]),
//7
         ([     "action"     :               BLK"$N將佩劍收入鞘中，身影消失於黑暗中，月影幻式『蝕』，無數道無形殺氣質直逼$n"NOR,
                "parry"      :                -100,
                "dodge"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack6 :),
                "damage_type":               "割傷",
]),
//8
 (["action":"$N叛離仙劍無法體會月影幻式奧義。",
  "force":10,
  "damage":10,
  "damage_type":"白癡傷",
]),
});

int valid_learn(object me)
{
       if(!me->query("quest/moon_sword",1)){
        tell_object(me,"你還不夠資格練月影幻式。\n");
        return 0;
                                               }
       if( !me->query_temp("weapon")){
        tell_object(me,"練月影幻式必需先拿把劍。\n");
        return 0;
                                     }
       if( (me->query("potential") - me->query("learned_points")) < 5 ) {
        tell_object(me, "你的潛能不到五點，無法練此劍法。\n");
        return 0;
                                                           }
        me->add("potential", -5);
        return   1;
}
int valid_enable(string usage)
{
        return ( usage=="sword" || usage=="parry" );
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
 skill_level = (int)(me->query_skill("moon_sword",1));
 limit= skill_level;
if(me->query("family/family_name")!="仙劍派")
return action[7];
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
void sp_attack0(object me, object victim, object  weapon, int damage)
{
  sp_value =5*(str+cor)+cps+kar+spi+int1;
    message_vision(BLK"
劍壓流動，隨著$N的心念越發強烈，月影幻式『陰月無影』壓得$n無從反動，完完全全受到劍壓的控制，瞬間已被黑暗吞沒\n"NOR,me,victim);
   victim->receive_damage("kee",sp_value,me);
 //  COMBAT_D->report_status(victim);
}
void sp_attack1(object me, object victim, object  weapon, int damage)
{
  sp_value =5*(str+cor)+cps+kar+spi+int1;
    message_vision(BLK"
受到劍壓的控制，月影幻式『新月畫眉』激出的劍虹在空中不停地聚合盤旋，剎那間!!天地變色風起雲湧，一輪明月在空氣之間現形而生$n被此情景所震懾，瞬間已被吞沒於黑暗中\n"NOR,me,victim);
   victim->receive_damage("kee",sp_value,me);
// COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}
void sp_attack2(object me, object victim, object  weapon, int damage)
{
  sp_value =5*(spi+int1)+cps+kar+str+cor;
    message_vision(BLK"
就在同時，$N身後出現一輪明月，周圍氣息全部遭明月吸收，$N與明月彷彿結合為一，四周的一切彷彿完全停止，月影幻式『圓月殺招』迅如雷光落向$n\n"NOR,me,victim);
   victim->receive_damage("kee",sp_value,me);
   victim->set_temp("no_power",1);
   victim->apply_condition("no_power",2);
//   COMBAT_D->report_status(victim);
COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}
void sp_attack3(object me, object victim, object  weapon, int damage)
{
  sp_value =4*(cps+kar)+str+cor+spi+int1;
    message_vision(BLK"
$N內勁頓轉使出月影陰寒之招，瞬時間一股寒氣籠罩身旁，只見劍上薄冰漸起幻成冰柱，$N愈使愈快，宛若洶湧巨浪瞬時壓力遽增霎時四周水波雲氣變化萬千，$n瞬間分不清劍在何方, 就在遲疑之際，$N一式『月殞影缺』捲起四周水氣直攻$n心口\n"NOR,me,victim);

    victim->receive_damage("kee",sp_value,me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);}
void sp_attack4(object me, object victim, object  weapon, int damage)
{
  sp_value =4*(cps+kar)+str+cor+spi+int1;
    message_vision(BLK"
眨眼間，劍鋒似水，緩緩月光微微射向$n，$N如化月影全身不經意使出月影幻式之『月牙上弦』，手中長劍在半空中畫出一道道半月形劍芒，劍幻千幻彎刀一瞬間$n已完全半月形劍芒吞噬"NOR,me,victim);
    victim->receive_damage("kee",sp_value+40,me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);}
void sp_attack5(object me, object victim, object  weapon, int damage)
{
  sp_value =5*(cps+kar)+str+cor+spi+int1;
    message_vision(BLK"
$N趁勢翻身飛躍，斜迴劍尖，念轉靈動使出『月牙下弦』，霎時殺意狂奔，欲噬血腥無法自制，劍鼓風旋，連鎖成無數無形風刃，削肉刮骨欲罷不能"NOR,me,victim);
victim->receive_damage("kee",sp_value+80,me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);}
void sp_attack6(object me, object victim, object  weapon, int damage)
{
    int i;
  sp_value =5*(str+cor+cps)+spi+int1+kar;
   if( weapon->query("id")=="moon_sword" || "sun_moon_sword"){
    message_vision(BLK"
瞬間，$N收劍回鞘，心凝一式『月蝕刻痕』，迴身飛旋，消失於一片黑暗中，瞬間長劍已離鞘直劃，隨著『刻痕月蝕』這一式散發出潛藏的靈氣，剎那間劍身似成無比巨大的黑洞將光芒完全吸收，只見$n當場目瞪口呆，一陣暈眩以無法分辨東南西北\n"NOR,me,victim);
    victim->receive_wound("kee",sp_value+130,me);
    victim->start_busy(2);
    victim->set_temp("no_power",1);
victim->apply_condition("no_power",2);
//    COMBAT_D->report_status(victim);
}
   else{
    victim->receive_wound("kee",sp_value,me);
    victim->start_busy(1);
    COMBAT_D->report_status(victim);
       }
       }
string perform_action_file(string action)
{
          return CLASS_D("swordsman")+"/moon_sword/"+action;
}
