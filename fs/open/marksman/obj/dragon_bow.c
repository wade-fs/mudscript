#include <weapon.h>
#include <ansi.h>

inherit BOW;

void create()
{

 set_name(HIR"龍蜒"HIY"神弓"NOR,({"dragon bow","bow"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long","一把由龍蜒所製成的弓。\n");
        set("material","steel");
        set("super_bow",1);
        set("no_hands",1);
        }
init_bow(60);
set("value",1);
setup();
}
void init()
{
        add_action("do_perform","supershoot");
}
int do_perform()
{
        object me,*target,room;
        int i,j,k,l,damage;

        me=this_player();
        if(random(2)) {
        damage=1000; }
        else {
        damage=500;
        }
        room= environment(me);
target = me->query_enemy(room);
i=sizeof(target);
if(me->query("family/family_name")!="射日派")
                 return notify_fail("你無法使出此弓的特級密技!!!\n");
if(!me->is_fighting()) return notify_fail("只有在戰鬥中才能使用\n");
if(80>random(100)) {
        message_vision("

          $N"HIR"狂喝一聲 : "BLINK+HIY"「龍  嘯  九  天」"NOR"

       "HIR" 手中龍蜒神弓化變成一條青龍往敵人飛去，一時天昏地暗

       "HIR"只見到青龍快速的在敵人的身上點了幾下，每個都噴出血來。

       \n\n"NOR,me);
        for(j=0;j<i;j++)
        {
             if(!target[j]) continue;
            if( target[j]->is_character() && !target[j]->is_corpse() && living(target[j]))
            {
            target[j]->add("kee",-damage);
            me->kill_ob(target[j]);
            COMBAT_D->report_status(target[j],1);
            }
        }
} else {
message_vision(HIW"結果敵人只造成一點點傷害很快就恢復了。\n"NOR,me);
}
if(me->query("id")!="master lee") {
            me->start_busy(1);
}
  return 1;
}
