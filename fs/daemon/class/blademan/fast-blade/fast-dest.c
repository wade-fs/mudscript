#include <ansi.h>
inherit SSERVER;
inherit F_FUNCTION;
void create() { seteuid(getuid()); }
int again(object me);
int perform( object me, object target )
{
	object weapon, mob, *enemy;
    int i;
        enemy=me->query_enemy();
        i=sizeof(enemy);
	if( me->query_skill( "fast-blade", 1 ) < 90 )
	return notify_fail( "你的幔羅千葉刀法根基不夠, 沒辦法使出無影狂刀斬。\n" );
	if( me->query_skill_mapped("blade") != "fast-blade" )
	return notify_fail( "只有在使幔羅千葉刀法時才能使出無影狂刀斬。\n" );
	if( me->query("family/family_name") != "金刀門" )
	return notify_fail( "只有金刀門徒能用唷。\n" );
	if( !(weapon = me->query_temp("weapon"))||weapon->query("skill_type") != "blade" )
	return notify_fail( "沒有刀是使不出無影狂刀斬的。\n" );
	if( !me->is_fighting() )
	return notify_fail( "你想用無影狂刀斬砍誰?\n" );
	if( me->query("force") < 300 )
	return notify_fail( "你的內力不夠, 使不出無影狂刀斬。\n" );
	if( me->query_temp("fast-dest")==1 )
	return notify_fail( "太累了, 無力使用無影狂刀斬...\n" );
	message_vision( HIW"只見$N手中的刀越舞越快, 身法隨著刀法極速加快,\n"
		           "身影也愈來愈糢糊, $N身旁的人已無法看清楚$N的位置,\n" 
                           "$N忽然大喝一聲,"HIY"「～～無影狂刀斬～～」\n"
                        HIW"接著開始無聲無息地攻擊各個敵人。\n" NOR, me );
        me->add( "force", -300 );
        while(i--) {
        if(enemy[i])
              {
                if(!enemy[i]->is_busy())
                        {
                        enemy[i]->start_busy(2);
                        }else{
                              enemy[i]->start_busy(1);
                             }
              }
        }
	me->set_temp( "fast-dest", 1 );
	me->start_busy(1);
    call_out("again", 2, me); 
	return 1;
}
int again(object me)
{
        object *enemy;
        int i,a,fun,gin,kee,sen;
        if(!me) return 1;
        enemy=me->query_enemy();
        i=sizeof(enemy);
        fun=me->query("functions/fast-dest/level");
        a=(int)(fun/10)+3;
        if(!me->query_temp("a")) {
        me->set_temp("a",a+1); }
        if(me->query_temp("fast-times")==me->query_temp("a")) {
        tell_object(me,sprintf(HIC"你的無影狂刀斬消失了。\n"NOR));
        me->delete_temp("fast-dest");
        me->delete_temp("a");
        me->delete_temp("fast-times");
        if(fun<100) function_improved("fast-dest",random(500));
        return 1; }
        while(i--) {
        if(!me||!enemy[i]) continue;
        message_vision(HIC"$N使出幔羅千葉刀法的精華 --- 無影狂刀斬，偷偷的向$n砍了一刀。\n" NOR, me, enemy[i]);
        if( environment(me) != environment(enemy[i]) )
        tell_object(enemy[i],sprintf(HIC"%s使出幔羅千葉刀法的精華 --- 無影狂刀斬，偷偷的向你砍了過來。\n" NOR,me->name()));
        if( 80 > random(100) ) {
        message_vision(HIR"$n閃躲不及，被$N的無影狂刀斬砍了一個大傷口，血流如注。\n" NOR, me, enemy[i]);
        if( environment(me) != environment(enemy[i]) )
        tell_object(enemy[i], sprintf(HIR"你閃躲不及，被%s的無影狂刀斬砍了一個大傷口，血流如注。\n"NOR, me->name()));
        if(me->is_fighting(enemy[i])) {
        kee = enemy[i]->query("kee")/35;
        if(kee > 150) kee=150;
        enemy[i]->receive_wound("kee",kee,me);
        sen = enemy[i]->query("sen")/20;
        if(sen > 150) sen=150;     // 最大值上限修正 by obs
        enemy[i]->receive_damage("sen",sen,me);
        gin = enemy[i]->query("gin")/20;
        if(gin > 150) gin=150;     // 最大值上限修正 by obs
        enemy[i]->receive_damage("gin",gin,me);
        if(!enemy[i]->is_busy())
         {
         enemy[i]->start_busy(2);
         }else{
               enemy[i]->start_busy(1);
              }
        COMBAT_D->report_status(enemy[i]);
        }
        } else {
        message_vision(HIG "$n巧妙的閃過了$N的無影狂刀斬。\n" NOR, me, enemy[i]);
        if( environment(me) != environment(enemy[i]) )
        tell_object(enemy[i], sprintf(HIG "你巧妙的閃過了%s的無影狂刀斬。\n" NOR, me->name()));
        }
        }
        me->add_temp("fast-times",1);
        call_out("again", 2, me);
        return 1;
}
