// Room: /open/tendo/room/t09.c

inherit ROOM;

void create()
{
	set("short", "煉丹房");
	set( "build", 12 );
	set("long", @LONG
終年熱呼呼的煉丹房，這裡可以讓你煉製保命的丹藥但你必須先
學會煉丹術及備有適合的材料。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"t10",
]));
        set("objects",([
		"open/tendo/npc/chinshi" : 1,
        ]));
	set("light_up",1);
	setup();
}
void init()
{

add_action("do_made","made");
}

int do_made(string arg)
{
  object ob,pi,me=this_player();
		if(me->query("class")!="taoist")
		return 0;
        if( !arg )                      return 0;
		if(arg !="fruit") {
		write("你要煉啥東東?\n");
		return 0;
		}
        arg=lower_case(arg);
		if( !ob = present(arg,me) ) {
		write("你身上沒那東東啦\n");
		return 1;
		}
destruct(ob);

pi = new("/open/tendo/obj/manapill");
pi->add_amount(15);
pi->move(this_player());
write("經過一番努力，終於煉出了丹藥。\n");
return 1;
}
