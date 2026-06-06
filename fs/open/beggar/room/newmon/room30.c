inherit ROOM;

void create()
{
 set("short","長老休息室");
 set("long",@LONG
這裡是長老的房間，他們專管幫派弟子生活上的鎖事，包
括傳授武功、清除叛徒及擾亂幫派安寧的傢伙，你想叛幫
嗎？勸你最好三思.....

LONG);
 set("exits",([
 "south" : __DIR__"room15.c"
 ]));
 
 setup();
}
