inherit ROOM;

void create()
{
	set("short", "崑崙山頂");
	set( "build", 1 );
	set("long", @LONG
偌大的銀色山谷，終年白雪皚皚，地上積了
一層薄薄的雪，雖是如此還是長了不少平地難得
一見的花草。前方有片奇特的樹林終年雲霧繚繞
你也許可以穿越(pass)看看。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"east" : __DIR__"m1",
]));
	set("outdoors", "1");

	setup();
}

void init()
{
	add_action("do_pass","pass");
}

// modified by babe
int do_pass()
{
	object who = this_player();
	tell_room( this_object(), who->query("name")+ "往樹林走去。\n", who );
	who->move(__DIR__"c1");
	if( who->query("food") > 200 )
		who->add( "food", -10 );
	return 1;
}
