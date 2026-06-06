inherit ROOM;

void create()
{
 set("short","西廂房");
 set("long",@LONG
嗚～好臭！！一走進這裡，一股奇臭無比的味道撲鼻而來，
哇！臭死了！你心裡罵道：「乞丐就是乞丐，跟豬一樣，臭
死了！」不過別被他們聽到喔！不然可有得你受的。

LONG);
 set("exits",([
 "south" : __DIR__"room16.c",
 "north" : __DIR__"room01.c"
 ]));
 setup();
}
