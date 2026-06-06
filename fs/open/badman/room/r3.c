// Room: /open/badman/room/r3
inherit ROOM;

void create ()
{
  set ("short", "病房");
  set ("long", @LONG
灰暗的燈光下你看到房間裡有一張白色的病床，旁邊的小架子
上則放了一些醫療用具，平常要是有誰受了傷得躺上十天半個月的
話，就只好乖乖的待在這裡囉。惡人谷中沒有任何一個人敢在這裡
胡來，因為他們每一個人都不知道何時自己也會住進這間小小的屋
子呢。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r2",
]));
  set("light_up", 1);

  setup();
}
