inherit ROOM;

void create()
{
 set("short","雨居");
 set("long",@LONG
此房間是雨護法休息的地方，他常在房間練功，為的就是
要保護幫主的安危，這也就是他的房間在幫主的附近。
LONG);
 set("exits",([
 "westdown" : __DIR__"room09.c"
 ]));
 
 setup();
}
