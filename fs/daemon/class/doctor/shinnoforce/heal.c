#include <ansi.h>
int perform( object me )
{
object *enemy = all_inventory( environment(me) );
int fun,i,j;
fun=me->query("functions/heal/level");
if(me->query("family/family_name")!="銀針門")
return notify_fail ("只有銀針門能用！\n");
if(me->query_temp("cure")==1)
return notify_fail ("治癒術必須休息一陣子才能使用!!\n");
if(me->query_skill("shinnoforce",1)< 60 )
return notify_fail ("你的神農琉璃心法不夠純熟！\n");
if(me->query_skill("godcure",1)< 100 )
return notify_fail ("你的神華佗醫術不夠純熟！\n");
if(me->query_skill("cure",1)< 100 )
return notify_fail ("你的基本醫術不夠純熟！\n");
if(me->query_skill_mapped("force") != "shinnoforce")
return notify_fail("你沒有裝備神農琉璃心法!!\n");
if(me->query("combat_exp")<1000000)
return notify_fail ("你的經驗不足!\n");
if (me->query ("force") < 2000)
return notify_fail ("你的內力不足!\n");
if( me->is_fighting() ) me->start_busy(2);
message_vision (HIW + "$N運起神農琉璃心法中的" + HIY + "「神農治癒術」" + HIW + "!!" + NOR + "\n",me); 
me->add ("force", -2000);
me->set_temp("cure",1);
call_out("out",20,me);
for( i=0; i<sizeof(enemy); i++ )
{
if( enemy[i]->is_character() && !enemy[i]->is_corpse() )
{
j = enemy[i]->query("max_kee");
enemy[i]->receive_curing("kee",fun*j/500);
enemy[i]->receive_heal("kee",fun*j/500);
//更動回氣量 by frequency   練到lv 100最多一次可回 (max_kee)/5
//若ppl max_kee為10000則一次回2000比之前的設定略少
//但對於max_kee少於2000的ppl不會像之前一次heal到滿，較為合理
//否則新手練功隨身帶個doctor就可以有不死身了
COMBAT_D->report_status(enemy[i], 1);
}
}      
return 1;  
}
int out(object me)
{
int fun;
if(!me) return ;
fun=me->query("functions/heal/level");
tell_object(me,"你精神恢復, 可以再度使用治癒術!!\n");
if(fun<100) me->function_improved("heal",100+random(100));
me->delete_temp("cure");
}
