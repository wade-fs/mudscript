
inherit ROOM;
void create()
{
  set ("short", "茅廁");
  set ("long","
    這裡四面暗悶悶的﹐兩旁各有兩條水溝﹐這裡烏七八
黑的空氣中充滿了濃濃的怪味道﹐難道是所有士兵們拉拉
拉拉機的地方﹐真是壯觀啊。

 ");
   set("exits", ([
   "east"   : __DIR__"r3.c",
   
  ]));      
  set("light_up", 1);
  setup();
} 
