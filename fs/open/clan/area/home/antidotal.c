// poison book by ACKY

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name( HIM"藥王神篇"NOR, ({ "antidotal book", "book" }) );
	set( "long", HIM"裡面記載著各種解毒的秘方(use box)。"NOR );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set( "weight", 100 );
		set( "unit", "本" );
	}
	setup();
}

void init()
{
	if( !present( this_object(), this_player() ) )
		return;
	add_action( "do_use", "use" );
}

int do_use( string arg )
{
	object	me, ob, sex;
	string	str;
	mapping	en;

	if( !arg || sscanf( arg, "%s", str ) != 1 )
		return 0;
	if( str != "book" )
		return 0;

	me = this_player();
	ob = this_object();
	en = me->query_skill_map();
	
	me->clear_condition();
	me->clear_condition("mogi");
	me->clear_condition("lyssa");
	me->set( "force", 0 );

	message_vision( "$N趕緊拿出" + ob->name() + "翻閱\。\n", me );
	write( YEL"上頭寫著:「吾畢身苦思各種解毒之道, 晚年終於找到一種剋治所有奇毒之法,\n"NOR );
	write( YEL"           其實也什麼特別之處, 只消......」\n"NOR );
	message_vision( HIC"\n$N照著書上的步驟, 趕緊蹲下脫褲子, 運起" +
		( undefinedp(en["force"]) ? "內功\心法" : to_chinese(en["force"]) ) + "...\n\n", me );
	message_vision( HIR"四周煙霧瀰漫, $N全身不斷散發出陣陣惡臭, 汗流浹背。\n\n"NOR, me );
	message_vision( HIM"$N「嗯!」地一聲, 終於大出一坨紫黑色的糞便。\n"NOR, me );


	destruct(ob);

	return 1;
}

