inherit ROOM;

void create()
{
 set("short","大廳");
 set("long",@LONG
寺廟外面雖然看起來破破舊舊的，不過裡面的木板卻挺
結實的，絲毫沒有損壞的痕跡，左右兩邊各通往西廂房
與東廂房，前方便是丐幫幫主聚集幫眾的「降龍堂」了。

LONG);
 set("exits",([
 "east" : __DIR__"room19.c",
 "west" : __DIR__"room17.c",
 "north" : __DIR__"room09.c",
 "out" : "/u/l/list/area/room08.c"
 ]));
 setup();
}
