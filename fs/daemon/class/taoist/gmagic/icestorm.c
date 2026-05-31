//icestorm
#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int fun,fun1,fun2,funn;
int fk,tk,k,i,j=0,l=0,r;
int conjure (object me, object target)
{
object *enemy;
enemy=me->query_enemy();
i=sizeof(enemy);
fun=(me->query("spells/icestorm/level")/25)+1;
fun1=me->query("spells/icestorm/level");
fun2=(int)(me->query_skill("gmagic", 1));
funn=(fun1*7/10)+(fun2*3/10);
if(me->query("class")!="taoist")
return notify_fail("這法術只有術士能用!!\n");
if(me->query("get_icestorm")==1)
  return notify_fail("你欲施展此招，但卻是從心無力，好像是缺乏了什麼一般...\n");
if(me->query("allow_icestorm")!=1)
  return notify_fail("偷學的不能使用喔\n");    
if( !target ) target = offensive_target(me); 
if(!me->is_fighting(target) )
return notify_fail("這法術只能對戰鬥中的對手使用!!\n");
if(me->query("max_mana") < 2500 )
return notify_fail("你的法力根基不足!!\n");
if(me->query("mana") < 2500 )
return notify_fail("你的法力不足!!\n");
if(me->query_temp("icestorm")==1)
return notify_fail("你施展法術後心思尚未集中!!\n");
message_vision(HIY"
$N高聲吶喊道：天地間的奧妙，大自然的力量豈是凡夫俗子所能抗衡的。

"HIC"○。 ‧  "HIG"★"HIC"   ‧  ☆ ‧   "HIB"●"HIC"  ‧  "HIM"★  ‧"HIC"   ☆   ‧  "HIG"★  ‧"HIC"  ‧   ○
"HIC"○。   ‧  ‧  "HIB"★"HIC"  ‧  ○  ‧  ☆   ‧  "HIB"○"HIC"   ‧  ●    ★    ‧  ○
"HIC"○。 "HIG"‧  ☆"HIC" ●  "HBRED+HIY"  冰  ˙  雪  ˙  風  ˙  暴  "NOR+HIC"  ☆‧"HIG"☆"HIC" ‧  ☆    ○
"HIC"○。 ☆  ‧  ★  ●‧"HIB"○"HIC"  ★ ‧‧  ○ ‧  ☆  ‧  "HIM"● ‧"HIC"   ‧ ★   ○
"HIC"○。 "HIB"‧"HIC"  ★   "HIM"‧  ☆"HIC" ‧   "HIG"●  ‧"HIC"  ★  ‧   "HIB"☆"HIC"   ‧  ★  ‧ "HIM"‧ 。"HIC" ○

"HIG"此時天地彷彿憾動了起來，凝結的空氣如冰雪崩落般的封住$n。
"HIG"$N趁此時機運起紫河星之最高境界 "HIY"『 "HIC"冰"HIY"‧"HIW"雪"HIY"‧"HIR"風"HIY"‧"HIG"暴 "HIY"』\n
"NOR, me,target);
me->add("mana",-(500*fun));
me->set_temp("icestorm",1);
me->start_busy(1);
call_out("act1",10,me);
for ( l=0 ; l < fun ; l ++)
{
r=random(100);
if (r >= 60) 
{
message_vision(HIM"
$N使出"HIY"『"HIC"冰"HIW"雪"HIR"風"HIB"暴"HIY"』"HIM"之"HIR"『"HIW"冰封千里"HIR"』"HIM"，四周的空氣瞬間凝結成冰。
"HIM"如同利刃般壓力迫使$n無法呼吸，嚴重缺氧而呆若木雞。
"HIR"緊接著翩然使出"HIY"『"HIW"如霜似雪"HIY"』"HIR"利用大自然神秘的力量，促使天降霜雪層
"HIR"層覆蓋\著$n，令敵人難以招架如此神秘的強烈攻擊。

"HIG"忽然間四周捲起一陣強風將$n捲入空中，$N冷笑數聲喝道:
"HIR"太極陰陽變"HIG"，道家禁招"HIW"『"HIC"風"HIW"～"HIB"起"HIW"～"HIM"雲"HIW"～"HIY"湧"HIW"』"HIG"頓然而出，只見天空風雲
"HIG"翻滾不停，$N將本身法力藉由"HIM"風的極速力量"HIG"、"HIC"雲的變化無窮"HIG"牽引
"HIG"至極高境界，翻手變出數道極光由手中疾馳而出攻擊$n。\n
"NOR,me,target);
for ( j=0 ; j < i ; j++ )
{
k=funn*7;
//if (enemy[j]->query_temp("def_fire")==1) k=funn*2;
enemy[j]->receive_damage("kee",k);
enemy[j]->receive_damage("sen",k*5);

//enemy[j]->apply_condition("icewind",random(20));
COMBAT_D->report_status(enemy[j]);
}
}
else if (r>=20)

{
  if(target)
message_vision(HIY"
      "HIC"受到冰封的$N被無情的霜雪覆蓋\，緊接著被強烈的颶風捲入空中
        由高空往下急速墜落，碰的一聲被摔的血肉模糊不堪入目。\n
"NOR,target);
for ( j=0 ; j < i ; j++ )
{
  if(!enemy[j]) continue;
k=funn*2;
enemy[j]->receive_wound("kee",k);
enemy[j]->receive_wound("sen",k*2);

enemy[j]->apply_condition("ice",random(10));
enemy[j]->start_busy(1);
COMBAT_D->report_status(enemy[j]);
}
}
else 
{
  if(target)
message_vision(HIG"      $N幸運的躲過了冰風暴的攻擊\n"NOR,target);
for ( j=0 ; j < i ; j++ )
{
COMBAT_D->report_status(enemy[j]);
}
}
}
return 1;
}
int act1(object me)
{
  if(!me) return ;
me->delete_temp("icestorm");
tell_object(me,HIG"霜雪過後大地恢復了原貌!\n"NOR);
if(me->query("spells/icestorm/level")<100) spell_improved("icestorm",random(100));
return 1;
}
