inherit ROOM;

void create()
{
 set("short","西廂房");
 set("long",@LONG
嗚～好臭！！一走進這裡，一股奇臭無比的味道撲鼻而來
，哇！臭死了！你心裡罵道：「乞丐就是乞丐，跟豬一樣
，臭死了！」不過別被他們聽到喔！不然可有得你受的。

LONG);
 set("exits",([
 "east" : __DIR__"room07.c",
 "north" : __DIR__"room01.c",
 "south" : __DIR__"room11.c"
 ]));
 setup();
}
