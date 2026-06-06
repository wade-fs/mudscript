 // 06/12/93 增加蛇穴 by Firedancer
// Room: /open/main/room/L14.c

inherit ROOM;

void create()
{
        set("short", "台地");
	set( "build", 4 );
        set("long", "這是一塊微微高起的台地，稀稀疏疏的長了起幾叢雜草，
幾塊石塊雜亂分部，更顯得這裡的荒涼.

                [蛇穴]
");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"s24",
  "west" : __DIR__"L13",
  "east" : __DIR__"L15",
]) );
        set("item_desc",([
"蛇穴":"一個被雜草所遮蔽住的洞穴．\n",
]));

  set("outdoors", "/open/main" );

  setup();
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter()
{
        object me = this_player();
        message_vision("$N撥開了雜草走進了洞穴內．．．\n",me);
        me->move("/open/area/snake/s01");
return 1;
}
