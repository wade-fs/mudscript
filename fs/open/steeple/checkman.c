// 原 code 過於龐大, 精簡 by ACKY

inherit NPC;

#include <ansi.h>

string ans1();

void create ()
{
	set_name( "位置管理者", ({ "local master", "master", "local" }) );
	set( "long", "
    他是一個由火神舞所製造而成的位置管理機器人，你可以為他有關於
試煉塔『位置』傳送的問題。\n");
	set( "age", 200 );
	set( "gender", "男性" );
	set( "title", "試煉塔" );
	set( "inquiry", ([
		"位置" : (: ans1 :)
		]) );
	setup();
}

string ans1()
{
	command( "hmm" );
	command( "say 我會依照你試煉塔的資料傳送, 你可以選擇傳送的地方。格式( move [number] )\n" );
	command( "say 但要是你的資料不足以到達你所想要的位置, 那我也沒辦法喔...\n" );
	command( "shrug" );
	return "再跟你多說一點... 裡面的人都很強喔!\n";
}

void init()
{
	add_action( "do_move", "move" );
}

int do_move( string str )
{
	int	move;
	object	me = this_player();
	if( !str || sscanf( str, "%d", move )!=1 || move > 50 || move < 1 ) {
		tell_object( me, HIY"位置管理者說道: 你說什麼? 我聽不懂...\n"NOR );
		return 1;
	}
	if( me->query("quest/start_game") <= move ) {
		tell_object( me, HIY"位置管理者說道: 抱歉囉... 你的等級不足以通往該處。\n"NOR );
		return 1;
	}
	message_vision( HIY"位置管理者說道: 資料符合, 開始傳送挑戰者"HIW + me->query("name") + HIY"。\n"NOR, me );
	me->move( __DIR__"busy_room" + ( move < 10 ? "0" + move : "" + move ) );
	message_vision( HIW"$N緩緩從天而降。\n"NOR, me );
	return 1;
}

