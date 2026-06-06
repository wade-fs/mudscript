// firedancer 修改 2002/07/28
// Room: /open/main/room/L12.c

inherit ROOM;

void create()
{
        set("short", "台地");
	set( "build", 24 );
        set("long", "這是一塊微微高起的台地，稀稀疏疏的長了起幾叢雜草，
幾塊石塊雜亂分部，更顯得這裡的荒涼.
附近有一個石屋，石屋上的煙囪不斷冒出陣陣白煙，看來似乎
有人住在裡面。

		<< 石屋 >>
\n");
	set("item_desc",([
"石屋":"石屋似乎沒上鎖，似乎可以直接進去..\n",
]));
	set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"L11",
"north" : __DIR__"m31",
]) );
	set("outdoors", "/open/main" );
setup();
}

void init()
{
add_action("do_enter","enter");
}

int do_enter(string arg)
{
object me = this_player();

	if( !arg )
		return 0;

	if( arg!="石屋" && arg!="horse" )
		return 0;

	message_vision("$N走入了石屋內。\n",me);
	me->move("/open/firedancer/t01.c");
return 1;
}
