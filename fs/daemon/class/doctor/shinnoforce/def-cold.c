#include <ansi.h>

int perform( object me )
{
        int     fun, i;
        object  *enemy = all_inventory(environment(me));
        
        fun = me->query("functions/def-cold/level");
        if( me->query("family/family_name")!="銀針門" )
                return notify_fail( "只有銀針門能用!\n" );
        if( me->query_skill("shinnoforce") < 30 )
                return notify_fail( "你的神農琉璃心法不夠純熟!\n" );
        if( me->query_skill_mapped("force") != "shinnoforce" )
                return notify_fail( "你沒有使用神農琉璃心法!\n" );
        if( me->query("combat_exp")<800000 )
                return notify_fail( "你的江湖歷練不足!\n" );
        if( me->query("max_force") < 1500 )
                return notify_fail( "你的內力不足!\n" );
        if( me->is_fighting() )
                me->start_busy(2);
        if( random(100)+fun < random(150) )
        {
        message_vision( HIW + "$N心有旁騖, 運勁失敗!!\n" + NOR, me );
      if(fun < 100)   me->start_busy(1);
        return 1;
        }
        message_vision( HIW + "$N運起神農琉璃心法中的" + HIC + "「凍氣訣」" + HIW + "!!\n" + NOR, me ); 
        for( i=0; i<sizeof(enemy); i++ )
                if( enemy[i]->is_character() && !enemy[i]->is_corpse() && living(enemy[i]) && enemy[i]->query_temp("def_cold")!=1 ) {
                        message_vision( HIW + "$N的凍氣訣提高了$n對冰雪的防護" + HIW + "!!\n" + NOR, me, enemy[i] );
                        enemy[i]->set_temp( "def_cold", 1 );
                        me->add( "force", -300 );
                        call_out( "remove_effect", 120+fun, enemy[i] );
                        COMBAT_D->report_status( enemy[i], 1 );
                        if( fun < 100 )
                        me->function_improved( "def-cold", random(50) ); 
                        else me->set("functions/def-cold/learned",0);    //  add by obs
                }
        return 1;  
}

void remove_effect( object me )
{
        if(!me) return ;
        me->delete_temp("def_cold");
        tell_object( me, HIC + "你覺得你對冰雪的防護消失了。\n" + NOR );
        return;
}

