// love water by ACKY

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name( HIW"愛液"NOR, ({ "love water", "water" }) );
	set( "long", "香香的愛液, 雖然只有一小滴, 卻足以讓男人神魂顛倒!" );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set( "weight", 1 );
		set( "unit", "滴" );
	}
	setup();
}


void init()
{
	if( !present( this_object(), this_player() ) )
		return;
	add_action( "do_drink", "drink" );
}

int do_drink( string arg )
{
	object	me, ob;
	string	str;

	if( !arg || sscanf( arg, "%s", str ) != 1 )
		return 0;
	if( str != "water" )
		return 0;

	me = this_player();
	ob = this_object();
	
	if( me->query("age") < 18 )
		return notify_fail( "未成年不可以飲用唷﹗\n" );

	message_vision( "$N將" + ob->name() + "喝了下去。\n", me );
	if( me->query("gender")=="女性" ) {
		message_vision( HIM"$N「哇!」地一聲, 吐了滿地。\n"NOR, me );
		me->set( "gin", 1 );
		me->set( "kee", 1 );
		me->set( "sen", 1 );
		me->set( "water", 0 );
	}
	else {
		message_vision( HIM"$N「哇!」地一聲, 感覺精神百倍。\n"NOR, me );
		me->set( "water", me->max_water_capacity() );
		if( me->query("eff_gin") < me->query("max_gin") )
			me->add( "eff_gin", 10 + random(11) );
		if( me->query("eff_gin") > me->query("max_gin") )
			me->set( "eff_gin", me->query("max_gin") );
		if( me->query("eff_sen") < me->query("max_sen") )
			me->add( "eff_sen", 10 + random(11) );
		if( me->query("eff_sen") > me->query("max_sen") )
			me->set( "eff_sen", me->query("max_sen") );
	}
	destruct(ob);
	return 1;
}		
