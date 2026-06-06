// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "天池");
	set("long", @LONG
愈靠近湖泊(lake)不知怎地就愈覺得溫暖，在湖的
周圍完全看不到積雪，草木也恢復青翠的綠色，
而湖水也不結冰。用手輕輕一觸竟然還是溫的！
令人想跳下去游泳在這冰天雪地中竟還有如此的
湖泊，令人猜想不透。

LONG
	);
	  set("item_desc", ([ /* sizeof() == 1 */
  "lake" : "一個美麗的山頂之湖，湖水還是溫的令人忍不住想跳下去游泳。",
]));
	set("exits", ([ /* sizeof() == 3 */
	"east" : __DIR__"m4",
	"south" : __DIR__"m6",
]));
	set("outdoors", "1");

	setup();
}

void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{
        object who;
        who = this_player();

        if( !arg || arg!="lake" )
        return notify_fail("跳？跳舞啊??\n");
        tell_object(who,"你閉住呼吸，迅速的跳入湖中，宛若一條游龍。\n");
        who->move("/open/dancer/room/yuaroom");
        tell_room(this_object(),"你看到"+who->query("name")+"以難看的姿勢跳入湖中，並以狗爬式緩緩游去。\n");
        return 1;
}
