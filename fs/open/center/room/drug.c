// Room: /open/center/room/drug.c

inherit ROOM;

void create ()
{
  set ("short", "藥店");
	set( "build", 12 );
  set ("long", @LONG
當你一踏進這個藥店, 一股濃厚的藥材味立即撲鼻而來, 在店裏的右邊
堆放了一堆堆尚未經過處理的藥材, 左邊的店老板與伙計們正忙著招呼客人,
店後則隱約傳來些奇怪的聲音, 可能是學徒們正操作著機器在處理藥材吧!
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/center/room/road2",
]));

  set("light_up", 1);

  setup();
}
