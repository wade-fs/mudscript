// Room: /open/gblade/port/room/p2-4.c
inherit ROOM;

void create()
{
	set("short","寵物店");
  set ("long", @LONG
這裡是全國唯一的一家寵物店 , 買賣各式各樣動物 , 你可
以買去作伴 , 也可以買去好好訓練 , 與你共闖江湖 , 現在這
裡還在缺貨中 , 相信很快就會有貨源運到啦 !


LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"p2-3",
]));
  setup();
}
