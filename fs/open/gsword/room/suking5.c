// Room: /u/s/smore/room/suking/suking5.c

inherit ROOM;

void create ()
{
  set ("short", "左侍衛房");
  set ("long", @LONG
走到這裡，你發現數名身材高大壯碩的侍衛正忠心耿耿的守
衛著將軍席，雖然將軍本身武功高強，但是昔日在戰場上所樹立
的敵人數目太多，甚至會有敵國派來的殺手，所以將軍府還是有
從軍隊中精心挑選出來的人組成侍衛班，守護著將軍府
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/gsword/room/suking4",
  "east" : "/open/gsword/room/suking6",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/l_guard" : 1,
]));
  set("light_up", 1);

  setup();
}
