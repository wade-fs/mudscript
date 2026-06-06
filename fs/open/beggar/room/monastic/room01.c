inherit ROOM;

void create()
{
 set("short","西廂房");
 set("long",@LONG
  你看到一群乞丐圍在一起，並聽到鏗、鏗的聲音，你走近
  一看，原來是他們正在玩骰子.....你想加入他們嗎？

LONG);
 set("exits",([
 "south" : __DIR__"room07.c"
 ]));
 setup();
}
