inherit ROOM;
void create ()
{
set("short", "休息間");
set("long",@LONG

經過了一番打鬥來到了這個房間，一片空蕩蕩的空房，
完全沒有任何東西的擺設，這裡就是試煉塔塔主火神舞
為了減輕系統所做出來的系統緩衝區。

LONG);
set("exits", ([
"north" : __DIR__"up14",
"down" : __DIR__"up13",
]));
set("no_fight",1);
set("objects",([
__DIR__"checkman":1,
]));
set("no_die_room",1);
set("light_up",1);
set("no_transmit",1);
set("no_auc", 1);
setup();
}

void init()
{
object me=this_player();
me->start_busy(3);
}
