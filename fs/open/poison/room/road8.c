// Room: /open/poison/room/road8
inherit ROOM;

void create ()
{
  set ("short", "山間小徑");
  set ("long", @LONG
你走在一條蜿蜒的山路上，地上的碎石子刺痛了你的雙
腳，向前一眼望去，有一大片蓊鬱的樹林，樹林裡傳來各種
動物的鳴叫聲，像是在訴說牠們的逍遙快樂，讓你忘記雙腳
的疼痛，輕鬆自在的行走。
LONG);

  set("outdoors", "/open/poison");

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/open/poison/room/road7",
  "northdown" : "/open/poison/room/road9",
]));

  setup();
}
