// Room: /open/center/room/car.c

inherit ROOM;

void create ()
{
  set ("short", "車馬行");
	set( "build", 301 );
  set ("long", @LONG
這兒的老闆叫張寶，據說是張三丰的第三代堂孫，是雪蒼派的弟
子，早年闖蕩江湖的時候，被十大惡人追殺，後來幸蒙一個走鑣的小
鑣師--趙鼎天--相救，兩人從此成為莫逆之交。後來為了替金刀門的
把總頂罪，差點死在牢裡，靠的還是那位當年的救命恩人。兩度救命
之恩，三十年的老交情，可惜一直沒有報答的機會。最近聽說鑣局缺
少車馬人手，因此跟張老闆也就在此定居了。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road3",
]));

  set("objects", ([ /* sizeof() == 2 */
  "/open/ping/questsfan/npc/lee" : 1,
  "/open/center/npc/brownhorse" : 2,
  "/open/center/npc/blackhorse.c" : 1,
]));

  set("light_up", 1);

  setup();
}
