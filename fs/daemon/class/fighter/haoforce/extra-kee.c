#include <ansi.h>
int perform( object me )
{
        int fun,i,mforce;
        mforce = me->query("max_force");
        fun=me->query("functions/extra-kee/level");
        i = mforce * fun / 100 + fun * 15;
        if( me->query("eff_kee")!=me->query("max_kee"))
                return notify_fail( "你的傷勢導致無法使用化勁成氣!!\n" );
		if( me->query("kee")!=me->query("eff_kee"))
                return notify_fail( "你的傷勢導致無法使用化勁成氣!!\n" );
        if( me->query("class")!="fighter" )
                return notify_fail( "非武者無法使用!!\n" );
        if( me->query("max_force") < 4000 )
                return notify_fail( "你的內力不足不足以化勁成氣!!\n" );
        if( me->query_temp("keeup") == 1 )
                return notify_fail( "你已經使用化勁成氣了!!\n" );
        if( me->query("force") < i*3/2 )
                return notify_fail( "你的內力不足!\n" );
        if( me->is_fighting() )
                me->start_busy(1);
        message_vision( HIW"$N憑著高深的內力修為, 將體內部分內勁轉化成氣!!\n"NOR, me ); 
        me->add("force", -(i*3/2) );
        me->add("max_kee",i+200);
		me->add("eff_kee",i+200);
        me->add("kee",i+200);
		me->set_temp("keeup",1);
        call_out( "remove_effect", 70+fun,me);
        return 1;  
}

void remove_effect( object me )
{
				int fun,mforce,i;
				if(!me) return ;
        fun=me->query("functions/extra-kee/level");
        mforce=me->query("max_force");
        i=mforce * fun / 100 + fun * 15;
		if(me->query_temp("keeup"))
		{
        me->add("max_kee",-(i+200));
        me->set("eff_kee",me->query("max_kee"));
        me->delete_temp("keeup");
        tell_object( me, HIR"你體內的氣勁漸漸消失了。\n"NOR );
        if( fun < 100 )
                me->function_improved( "extra-kee", random(300) ); 
        }
		return;
}
