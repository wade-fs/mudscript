// Room: /open/gsword/room/gsword1-4.c
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
一條普通的走廊 ,連往仙劍的武器 ,防具室 .俗話說 :工欲擅其事 ,必先
利其器 ,沒有好的配備怎麼跟別人爭長短呢 ?仙劍雖說是劍派 ,儲藏室內不但
各式各樣的劍齊備 ,就連其它武器也是一應俱全 .

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/g1-6.c",
  "east" : "/open/gsword/room/g1-3.c",
]));

  set("light_up", 1);

  setup();
}
