// Room: /open/gsword/room/g1-8.c
inherit ROOM;

void create()
{
  set ("short", "護具室");
  set ("long", @LONG
這裡是仙劍派的防具室, 學武之人本就不需要啥防具, 因此整間房間只放了一些肩甲, 
護心鏡之類的防具, 突然你的眼光被一件耀眼的衣服所吸引, 定神一看, 原來是掌門人
鄭士欣專用的龍鬚衣, 傳說中具有刀槍不入的強韌度。
LONG);

  set("light_up", 1 );

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"g1-6",
]) );

  set("objects", ([ /* sizeof() == 3 */
  "/open/gsword/npc/boy.c" :1,]));
  
  setup();
}
