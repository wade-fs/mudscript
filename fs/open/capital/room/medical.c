// Room: /open/capital/room/medical
inherit ROOM;

void create ()
{
  set ("short", "仁心藥店");
	set( "build", 12 );
  set ("long", @LONG
藥店兩旁的牆壁均立了兩個大櫃子, 再縱橫分成了數百個小櫃子,
每個小櫃子上都標示了一種草藥名, 仔細的算一算, 這兒有的藥材之豐
富只怕是天下數一數二的了, 藥店的夥計忙碌的走動著, 都忙的不可開
交, 在角落裡一個小學童模樣的小孩手裡正拿著一把大扇子, 拼命的朝
著火盆搧風。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"h06",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/Pwaiter" : 1,
]));
  set("light_up", 1);

  setup();
}
