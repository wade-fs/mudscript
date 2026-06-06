// Room: /open/su/room/suroad9_1.c

inherit ROOM;

void create ()
{
  set ("short", "仙劍派大殿");
  set ("long", @LONG
	
這是仙劍派的大殿,殿中數位劍士恭謹的站在兩側,看看這的成設
,全以紫檀木造成，少了一種壯麗,卻多一分莫名的英氣。唯一令你
不解是大殿掌門人的位置上，卻不見掌門人--李逍遙，坐在其上。
，看來想拜師的話只好問問左右的劍士們了。         

LONG);

  set("light_up",1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/gsword/room/north",
  "out" : "/open/gsword/room/test.c",
]));

  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/mob/swordsman" : 2,
  "/open/gsword/mob/chenfon.c" : 1,
]));

  setup();
}
