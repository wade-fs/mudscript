#include <ansi.h>
#include <combat.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit SKILL;

int perform(object me, object target)
{
  int wave_lv;
  object ob,victim = target;
  wave_lv=me->query("functions/wave/level");
  if( !target ) target = offensive_target(me);
  if(me->query_skill("dragonfist",1) < 80 )
   return notify_fail("你的降龍武學不夠純熟，使出奔龍波瀾。\n"); 
  if( me->query("family/family_name") != "丐幫" )
   return notify_fail("奔龍波瀾只有丐幫弟子才能施展。\n"); 
   if(me->query("force")<wave_lv)
     return notify_fail("你的內力不夠。\n");
   if(!me->is_fighting())
    {
     tell_object(me,"奔龍波瀾需由戰鬥中激發。\n");
     return 0;
   }
 
if(target->is_busy())
 return notify_fail("敵人不能動中，快攻擊吧！\n");

    if(!me->query_temp("wave"))
	{
 me->set_temp("wave",1);
     message_vision(HIY"$N雙掌一錯,掌勢由散轉密,猛招前奏如山雨欲來....."NOR,me);
     if(wave_lv<=25){
	message_vision(HIR"$N欲使強招，身形微微一窒。\n"NOR,me);
            me->start_busy(1);
            call_out("do_wave",14,target,me);
     } else if(wave_lv<=50){
	message_vision(HIR"$N欲使強招，身形微微一窒。\n"NOR,me);
            me->start_busy(1);
	call_out("do_wave",10,target,me);
     } else if(wave_lv<=75) {
  	call_out("do_wave",6,target,me);
     } else {
	call_out("do_wave",2,target,me);	
     }     
    function_improved("wave",random(me->query("force")/10));
    message_vision( NOR,me);
    return 1;
  }
}
int do_wave(object victim,object me)
{
     int i; 
     int wave_lv;
     wave_lv=me->query("functions/wave/level");
     if(wave_lv<=25){
	message_vision(HIW"$N如潛龍低嘯，奔龍波瀾出掌快絕如風!\n"NOR,me);
            COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
     } else if(wave_lv<=50){
	message_vision(HIW"$N身似磐龍出谷，奔龍波瀾一掌快比一掌!!\n"NOR,me);
            for(i=0;i<2;i++){
 	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);	
            }
     } else if(wave_lv<=75) {
            message_vision(HIW"$N掌隨風行,奔龍波瀾如狂龍爆發,勢不可擋!!!\n"NOR,me);
	for(i=0;i<3;i++)
	{
           COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            }
     } else {
	message_vision(HIC"降龍秘義---奔---龍---波---瀾---!!!\n"NOR,me);
	for(i=0;i<4;i++){
            COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);	
    	} 
    }     
    me->delete_temp("wave");
    return 1;
}
