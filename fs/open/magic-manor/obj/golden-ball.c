inherit ITEM;
#include <ansi.h>
string bname;

void create()
{
        set_name("靈氣金珠",({"golden ball","ball"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
	set("long", @LONG
相傳如果要進入五行靈塔，就必需要攜帶的寶物，靈氣金珠所散
發出來的靈氣，足以克制五行之中的木靈之氣，可以減少具有傷害的
靈氣所帶來之傷害。靈氣金珠必需要聚靈之後，才會開啟其作用，若
尚未聚靈的靈氣金珠是無任何作用的。

聚靈方式： gather ball
散靈方式： scatter ball
LONG);

	set("value",100000);
	set("unit","顆");
	set("magic-manor",1);
        }
	setup();
}

void init()
{
        add_action("do_gather","gather");
        add_action("do_scatter","scatter");
}

int do_gather(string arg)
{
object ob,me;

        me = this_player();
        ob = this_object();

	bname = base_name(environment(me));

        if( !arg )
	return 0;

        arg=lower_case(arg);
        if( !ob = present(arg,me) )
	return 0;

	if( ob != this_object() )
	return 0;

	if( bname != "/open/magic-manor/manor53" )
	return notify_fail(""+ob->name(1)+"無法在此聚集靈氣。\n");

        if( me->query_temp("magic-manor/gather-golden") )
	return notify_fail(""+ob->name(1)+"已經聚靈完成。\n");

        ob->set("no_put",1);
        ob->set("no_drop",1);
        ob->set("no_get",1);
        ob->set("no_sell",1);
        ob->set("no_auc",1);
        ob->set("no_give",1);
	ob->set("no_save",1);

        message_vision(HIW + "$N輕輕將$n"+HIW+"放在手掌之中，讓$n"+HIW+"開始吸收聚靈池的靈氣。\n" + NOR,me,ob);
	me->start_busy(1);
	call_out("act1",5,ob);

	return 1;
}

int do_scatter(string arg)
{
	object ob,me;

        me = this_player();
        ob = this_object();

	bname = base_name(environment(me));

        if( !arg )
	return 0;

        arg=lower_case(arg);
        if( !ob = present(arg,me) )
	return 0;

        if( ob != this_object() )
	return 0;

	if( bname != "/open/magic-manor/manor53" )
	return notify_fail(""+ob->name(1)+"無法在此散去靈氣。\n");

        if( !me->query_temp("magic-manor/gather-golden") )
	return notify_fail(""+ob->name(1)+"尚未聚集任何靈氣。\n");

        ob->delete("no_put",1);
        ob->delete("no_drop",1);
        ob->delete("no_get",1);
        ob->delete("no_sell",1);
        ob->delete("no_auc",1);
        ob->delete("no_give",1);
	ob->delete("no_save",1);

        message_vision("$N將$n的靈氣盡數散去，$n回復成一個沒有任何作用的珠子。\n",me,ob);
        ob->set("name","靈氣金珠");
        me->delete_temp("magic-manor/gather-golden",1);
	me->delete_temp("magic-manor/gold-shield",1);
	return 1;
}

int act1(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW + "$N" + HIW + "正緩緩的吸取靈氣中，只見$N" + HIW + "周身泛起陣陣光芒。\n" + NOR,ob);
	me->start_busy(1);
	call_out("act2",5,ob);
	}else{
	message_vision(HIR + "$N" + HIR + "一時失去了靈氣的導引，忽然暴為粉碎!!\n" + NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act2(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW + "$N" + HIW + "正緩緩的吸取靈氣中，只見$N" + HIW + "周身泛起陣陣光芒。\n" + NOR,ob);
	me->start_busy(1);
	call_out("act3",5,ob);
	}else{
	message_vision(HIR + "$N" + HIR + "一時失去了靈氣的導引，忽然暴為粉碎!!\n" + NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act3(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW + "$N" + HIW + "正緩緩的吸取靈氣中，只見$N" + HIW + "周身泛起陣陣光芒。\n" + NOR,ob);
	me->start_busy(1);
	call_out("act4",5,ob);
	}else{
	message_vision(HIR + "$N" + HIR + "一時失去了靈氣的導引，忽然暴為粉碎!!\n" + NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act4(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW + "$N" + HIW + "正緩緩的吸取靈氣中，只見$N" + HIW + "周身泛起陣陣光芒。\n" + NOR,ob);
	me->start_busy(1);
	call_out("act5",5,ob);
	}else{
	message_vision(HIR + "$N" + HIR + "一時失去了靈氣的導引，忽然暴為粉碎!!\n" + NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act5(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW + "$N" + HIW + "正緩緩的吸取靈氣中，只見$N" + HIW + "周身泛起陣陣光芒。\n" + NOR,ob);
	me->start_busy(1);
	call_out("act6",5,ob);
	}else{
	message_vision(HIR + "$N" + HIR + "一時失去了靈氣的導引，忽然暴為粉碎!!\n" + NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act6(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW + "$N" + HIW + "正緩緩的吸取靈氣中，只見$N" + HIW + "周身泛起陣陣光芒。\n" + NOR,ob);
	me->start_busy(1);
	call_out("act7",5,ob);
	}else{
	message_vision(HIR + "$N" + HIR + "一時失去了靈氣的導引，忽然暴為粉碎!!\n" + NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act7(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW + "$N" + HIW + "正緩緩的吸取靈氣中，只見$N" + HIW + "周身泛起陣陣光芒。\n" + NOR,ob);
	me->start_busy(1);
	call_out("act8",5,ob);
	}else{
	message_vision(HIR + "$N" + HIR + "一時失去了靈氣的導引，忽然暴為粉碎!!\n" + NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act8(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW + "$N" + HIW + "正緩緩的吸取靈氣中，只見$N" + HIW + "周身泛起陣陣光芒。\n" + NOR,ob);
	me->start_busy(1);
	call_out("act9",5,ob);
	}else{
	message_vision(HIR + "$N" + HIR + "一時失去了靈氣的導引，忽然暴為粉碎!!\n" + NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act9(object ob,object me)
{
	ob=this_object();
	me=this_player();
	message_vision(HIW + "只見$N" + HIW + "已吸足了靈氣，$N" + HIW + "周身泛起強烈光芒。\n" + NOR,ob);
        ob->set("name",HIW + "(聚靈) "NOR+HIY"靈氣金珠" + NOR);
        me->set_temp("magic-manor/gather-golden",1);
	me->set_temp("magic-manor/gold-shield",1);
	return 1;
}
